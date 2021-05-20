#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "gmath.h"
#include "bzrcrv.h"
#include ".\usr\include\GL\freeglut.h"

using namespace std;
int Width = 800, Height = 800;
int ManipulateMode = 0;

// 관측변환을 위한 변수
int StartPt[2];
float Angle = 0.0;
GVec3 Axis;
float Zoom = -50.0;
float Pan[3] = { 0.0, 0.0, 0.0 };
float RotMat[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
double Time = 0.0;

// Callback 함수
void Reshape(int w, int h);
void Keyboard(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void MouseMove(int x, int y);
void MouseWheel(int button, int dir, int x, int y);
void Timer(int id);

// 사용자 정의함수
void InitGL();
void GetSphereCoord(int x, int y, GVec3 &p);
void Render();
void RenderFloor();
void SetupViewVolume();
void SetupViewTransform();
void get_interp_crv_hermite(std::vector<GVec3> &Key, std::vector<GBzrCrv> &CrvList);

GVec3 P;
GQuater Q0, Q1, Q2, Q3, Q4, Q5, Q;
std::vector<GVec3> Key;

std::vector<GBzrCrv> gCrvList;


int main(int argc, char **argv)
{
	// GLUT 초기화
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// 윈도우 초기화 및 생성
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyframe Example");
	InitGL();
	
	// 2개의 키프레임 설정
	Key.push_back(GVec3(-15.0, 7.0, 0.0));
	Key.push_back(GVec3(-10.0, 0.0, 0.0));
	Key.push_back(GVec3(-1.0, 3.0, 0.0));
	Key.push_back(GVec3(5.0, 0.0, 0.0));
	Key.push_back(GVec3(12.0, 2.0, 0.0));

	Q0.SetIdentity();	
	Q1.SetFromAngleAxis(189.0, GVec3(0.0, 0.0, 1.0));   
	Q2.SetFromAngleAxis(150.0, GVec3(0.0, 1.0, 0.0));
	Q3.SetFromAngleAxis(100.0, GVec3(0.0, 0.0, 1.0));
	Q4.SetFromAngleAxis(120.0, GVec3(0.0, 1.0, 0.0));
	Q5.SetFromAngleAxis(120.0, GVec3(0.0, 0.0, 1.0));
	
	get_interp_crv_hermite(Key, gCrvList);

	// Callback 함수 등록
	glutDisplayFunc(Render);
	glutReshapeFunc(Reshape);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMove);
	glutMouseWheelFunc(MouseWheel);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(30, Timer, 0);

	// 메시지 루푸 진입
	glutMainLoop();
	return 0;
}

void InitGL()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}

void Render()
{
	// 칼라 버퍼와 깊이 버퍼를 초기화 한다.
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 관측 공간을 설정하고, 뷰잉 변환을 수행한다.
	SetupViewVolume();
	SetupViewTransform();

	// 모델 리스트를 렌더링한다.
	glMatrixMode(GL_MODELVIEW);
	RenderFloor();

	//보기위해 추가한곳
	glColor3f(1.0, 0.0, 0.0); 
	glPointSize(5.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < Key.size(); ++i)
		glVertex3d(Key[i][0], Key[i][1], Key[i][2]);
	glEnd();
	glPointSize(1.0);

	for (int i = 0; i < gCrvList.size(); ++i)
		gCrvList[i].Render(50);

	glPushMatrix();
	{
		// 이동 변환을 적용한다.
		glTranslated(P[0], P[1], P[2]);

		// 회전 변환을 적용한다.
		GVec3 Axis;
		double angle;
		Q.GetAngleAxis(Axis, angle); // 쿼터니온Q 를 이용해 현재 축이 얼마이고 얼마나 회전됐는지 받아옴
		glRotated(angle, Axis[0], Axis[1], Axis[2]);

		// 객체를 렌더링 한다.
		glutSolidCube(1.0);
	}

	glPopMatrix();

	// 칼라 버퍼를 교환한다.
	glutSwapBuffers();
}

void Timer(int id)
{
	Time += 0.01;
	if (Time > 4.0)
		Time = 0.0;

	GVec3 p;
	GVec3 v;

	if (Time < 1.0)
	{	// Linear interpolation 위치 선형보간 
		//P = (1.0 - Time) * P0 + Time * P1;	
		double u = (gCrvList[0].m_Domain[1] - gCrvList[0].m_Domain[0])* Time + gCrvList[0].m_Domain[0];
		gCrvList[0].Eval(u,p,v);
		P = p;
		// Spherical linear interpolation 회전 선형보간
		Q = slerp(Q0, Q1, Time);
	}
	//새로 작성
	else if (Time >= 1.0 && Time < 2.0)
	{
		double u = (gCrvList[1].m_Domain[1] - gCrvList[1].m_Domain[0])* (Time-1) + gCrvList[1].m_Domain[0];
		gCrvList[1].Eval(u, p, v);
		P = p;
		// Spherical linear interpolation 회전 선형보간
		Q = slerp(Q1, Q2, Time);
	}

	else if (Time >= 2.0 && Time < 3.0)
	{	// Linear interpolation 위치 선형보간 
		double u = (gCrvList[2].m_Domain[1] - gCrvList[2].m_Domain[0]) * (Time-2) + gCrvList[2].m_Domain[0];
		gCrvList[2].Eval(u, p, v);
		P = p;
		// Spherical linear interpolation 회전 선형보간
		Q = slerp(Q2, Q3, Time);
	}

	else if(Time >= 3.0&& Time < 4.0)
	{	// Linear interpolation 위치 선형보간 
		double u = (gCrvList[3].m_Domain[1] - gCrvList[3].m_Domain[0]) * (Time-3) + gCrvList[3].m_Domain[0];
		gCrvList[3].Eval(u, p, v);
		P = p;
		// Spherical linear interpolation 회전 선형보간
		Q = slerp(Q3, Q4, Time);
	}

	glutPostRedisplay();
	glutTimerFunc(30, Timer, 0);
}



/*! 새로 추가한 부분
*	\brief	정점을 보간하는 3차 베지에 곡선의 리스트를 생성한다.
*
*	\param	Points[in]		보간될 데이터 정점
*	\param	CrvList[out]	생성된 베지에 곡선이 저장된다.
*/
void get_interp_crv_hermite(std::vector<GVec3> &Key, std::vector<GBzrCrv> &CrvList)
{
	// 1. 보간 파라미터를 결정한다.
	int Numpts = (int)Key.size();
	std::vector <double> Params(Numpts, 0.0);	
	for (int i = 1; i < Numpts; ++i)
	{
		Params[i] = Params[i - 1] + dist(Key[i], Key[i - 1]);
	}

	// 2. 접벡터를 결정한다.
	std::vector<GVec3> Tangential;  
	Tangential.push_back(GVec3(0, 0, 0));

	for (int i = 1; i < Numpts - 1; ++i)
	{
		Tangential.push_back((Key[i + 1] - Key[i - 1]) / (Params[i + 1] - Params[i - 1]));
	}
	Tangential.push_back(GVec3(0, 0, 0));


	// 3. 각 구간의 베지에 곡선을 생성하여 리스트에 추가한다.
	std::vector <GVec3> Control(4, GVec3(0, 0, 0));
	GVec2 domain;
	for (int i = 0; i < Numpts - 1; ++i)			
	{
		Control[0] = Key[i];
		Control[3] = Key[i + 1];
		Control[1] = Key[i] + (Params[i + 1] - Params[i]) / 3 * Tangential[i];
		Control[2] = Key[i + 1] - (Params[i + 1] - Params[i]) / 3 * Tangential[i + 1];

		domain = GVec2(Params[i], Params[i + 1]);
		
		GBzrCrv GBzr(domain, Control);
		CrvList.push_back(GBzr);
	}

}

void Reshape(int w, int h)
{
	// 뷰포트 변환을 수행한다.
	glViewport(0, 0, w, h);
	Width = w;
	Height = h;
}

void Keyboard(unsigned char key, int x, int y)
{
	// ESC 키를 누르면 메쉬 리스트를 메모리에서 삭제하고 종료한다.
	if (key == 27)
		exit(0);
}

void SetupViewTransform()
{
	// 모델뷰 행렬 선택
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// 이동-회전 변환 수행
	glTranslatef(0.0, 0.0, Zoom);
	glRotatef(Angle, Axis[0], Axis[1], Axis[2]);

	// 이전에 적용된 회전 변환 후, 이동 변환 수행
	glMultMatrixf(RotMat);
	glTranslatef(Pan[0], Pan[1], Pan[2]);

	// 회전 변환의 결과를 저장
	glGetFloatv(GL_MODELVIEW_MATRIX, RotMat);
	RotMat[12] = RotMat[13] = RotMat[14] = 0.0;
}

void SetupViewVolume()
{
	// 투영 행렬 선택 및 관측 공간 지정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (double)Width / (double)Height, 0.01, 10000.0);
}

void RenderFloor()
{
	// 바닥 평면을 렌더링한다.
	glDisable(GL_LIGHTING);
	glColor3d(0.7, 0.7, 0.7);
	for (int i = -20; i <= 20; ++i)
	{
		if (i == 0)
			glLineWidth(2.0);
		else
			glLineWidth(1.0);
		glBegin(GL_LINES);
		glVertex3i(i, -20, -0.001);
		glVertex3f(i, 20, -0.001);
		glVertex3i(-20, i, -0.001);
		glVertex3i(20, i, -0.001);
		glEnd();
	}
	glEnable(GL_LIGHTING);
}

void Mouse(int button, int state, int x, int y)
{
	// 마우스 버튼을 누른 경우,
	if (state == GLUT_DOWN)
	{
		StartPt[0] = x;
		StartPt[1] = y;

		if (button == GLUT_LEFT_BUTTON)
			ManipulateMode = 1;		// 회전
		else if (button == GLUT_MIDDLE_BUTTON)
			ManipulateMode = 2;		// 이동
	}

	// 마우스 버튼을 땐 경우,
	if (state == GLUT_UP)
	{
		// 재 초기화
		ManipulateMode = 0;
		StartPt[0] = StartPt[1] = 0;
		Angle = 0.0;
	}
}

void MouseMove(int x, int y)
{
	// 회전 모드라면,
	if (ManipulateMode == 1)
	{
		GVec3 p, q;
		GetSphereCoord(StartPt[0], StartPt[1], p);
		GetSphereCoord(x, y, q);

		Axis = p ^ q;
		if (norm(Axis) < 1.0e-6)
		{
			Axis.Set(0.0, 0.0, 0.0);
			Angle = 0.0;
		}
		else
		{
			Axis.Normalize();
			Angle = p * q;
			Angle = acos(Angle) * 180.0f / 3.141592f;
		}
	}
	else  if (ManipulateMode == 2) // 이동 모드
	{
		float dx = (x - StartPt[0]) * 0.1;
		float dy = (StartPt[1] - y) * 0.1;
		Pan[0] += RotMat[0] * dx + RotMat[1] * dy;
		Pan[1] += RotMat[4] * dx + RotMat[5] * dy;
		Pan[2] += RotMat[8] * dx + RotMat[9] * dy;
	}

	StartPt[0] = x;
	StartPt[1] = y;
	glutPostRedisplay();
}

void MouseWheel(int button, int dir, int x, int y)
{
	if (dir > 0)
	{
		Zoom -= (StartPt[1] - y) * 0.05;
		if (Zoom > -0.001)
			Zoom = -0.001;	
	}
	else
	{
		Zoom += (StartPt[1] - y) * 0.05;
		if (Zoom > -0.001)
			Zoom = -0.001;
	}
	glutPostRedisplay();
}

void GetSphereCoord(int x, int y, GVec3 &p)
{	
	//x,y 는 마우스 클릭한 위치
	p[0] = (2.0 * x - Width) / Width;
	p[1] = (-2.0 * y + Height) / Height;
	p[2] = 0.0;

	double r = p * p;
	if (r >= 1.0)
		p.Normalize();
	else
		p[2] = sqrt(1.0 - r);
}

