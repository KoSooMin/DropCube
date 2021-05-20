#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "gmath.h"
#include "bzrcrv.h"
#include ".\usr\include\GL\freeglut.h"

using namespace std;
int Width = 800, Height = 800;
int ManipulateMode = 0;

// ������ȯ�� ���� ����
int StartPt[2];
float Angle = 0.0;
GVec3 Axis;
float Zoom = -50.0;
float Pan[3] = { 0.0, 0.0, 0.0 };
float RotMat[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
double Time = 0.0;

// Callback �Լ�
void Reshape(int w, int h);
void Keyboard(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void MouseMove(int x, int y);
void MouseWheel(int button, int dir, int x, int y);
void Timer(int id);

// ����� �����Լ�
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
	// GLUT �ʱ�ȭ
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// ������ �ʱ�ȭ �� ����
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyframe Example");
	InitGL();
	
	// 2���� Ű������ ����
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

	// Callback �Լ� ���
	glutDisplayFunc(Render);
	glutReshapeFunc(Reshape);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMove);
	glutMouseWheelFunc(MouseWheel);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(30, Timer, 0);

	// �޽��� ��Ǫ ����
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
	// Į�� ���ۿ� ���� ���۸� �ʱ�ȭ �Ѵ�.
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// ���� ������ �����ϰ�, ���� ��ȯ�� �����Ѵ�.
	SetupViewVolume();
	SetupViewTransform();

	// �� ����Ʈ�� �������Ѵ�.
	glMatrixMode(GL_MODELVIEW);
	RenderFloor();

	//�������� �߰��Ѱ�
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
		// �̵� ��ȯ�� �����Ѵ�.
		glTranslated(P[0], P[1], P[2]);

		// ȸ�� ��ȯ�� �����Ѵ�.
		GVec3 Axis;
		double angle;
		Q.GetAngleAxis(Axis, angle); // ���ʹϿ�Q �� �̿��� ���� ���� ���̰� �󸶳� ȸ���ƴ��� �޾ƿ�
		glRotated(angle, Axis[0], Axis[1], Axis[2]);

		// ��ü�� ������ �Ѵ�.
		glutSolidCube(1.0);
	}

	glPopMatrix();

	// Į�� ���۸� ��ȯ�Ѵ�.
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
	{	// Linear interpolation ��ġ �������� 
		//P = (1.0 - Time) * P0 + Time * P1;	
		double u = (gCrvList[0].m_Domain[1] - gCrvList[0].m_Domain[0])* Time + gCrvList[0].m_Domain[0];
		gCrvList[0].Eval(u,p,v);
		P = p;
		// Spherical linear interpolation ȸ�� ��������
		Q = slerp(Q0, Q1, Time);
	}
	//���� �ۼ�
	else if (Time >= 1.0 && Time < 2.0)
	{
		double u = (gCrvList[1].m_Domain[1] - gCrvList[1].m_Domain[0])* (Time-1) + gCrvList[1].m_Domain[0];
		gCrvList[1].Eval(u, p, v);
		P = p;
		// Spherical linear interpolation ȸ�� ��������
		Q = slerp(Q1, Q2, Time);
	}

	else if (Time >= 2.0 && Time < 3.0)
	{	// Linear interpolation ��ġ �������� 
		double u = (gCrvList[2].m_Domain[1] - gCrvList[2].m_Domain[0]) * (Time-2) + gCrvList[2].m_Domain[0];
		gCrvList[2].Eval(u, p, v);
		P = p;
		// Spherical linear interpolation ȸ�� ��������
		Q = slerp(Q2, Q3, Time);
	}

	else if(Time >= 3.0&& Time < 4.0)
	{	// Linear interpolation ��ġ �������� 
		double u = (gCrvList[3].m_Domain[1] - gCrvList[3].m_Domain[0]) * (Time-3) + gCrvList[3].m_Domain[0];
		gCrvList[3].Eval(u, p, v);
		P = p;
		// Spherical linear interpolation ȸ�� ��������
		Q = slerp(Q3, Q4, Time);
	}

	glutPostRedisplay();
	glutTimerFunc(30, Timer, 0);
}



/*! ���� �߰��� �κ�
*	\brief	������ �����ϴ� 3�� ������ ��� ����Ʈ�� �����Ѵ�.
*
*	\param	Points[in]		������ ������ ����
*	\param	CrvList[out]	������ ������ ��� ����ȴ�.
*/
void get_interp_crv_hermite(std::vector<GVec3> &Key, std::vector<GBzrCrv> &CrvList)
{
	// 1. ���� �Ķ���͸� �����Ѵ�.
	int Numpts = (int)Key.size();
	std::vector <double> Params(Numpts, 0.0);	
	for (int i = 1; i < Numpts; ++i)
	{
		Params[i] = Params[i - 1] + dist(Key[i], Key[i - 1]);
	}

	// 2. �����͸� �����Ѵ�.
	std::vector<GVec3> Tangential;  
	Tangential.push_back(GVec3(0, 0, 0));

	for (int i = 1; i < Numpts - 1; ++i)
	{
		Tangential.push_back((Key[i + 1] - Key[i - 1]) / (Params[i + 1] - Params[i - 1]));
	}
	Tangential.push_back(GVec3(0, 0, 0));


	// 3. �� ������ ������ ��� �����Ͽ� ����Ʈ�� �߰��Ѵ�.
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
	// ����Ʈ ��ȯ�� �����Ѵ�.
	glViewport(0, 0, w, h);
	Width = w;
	Height = h;
}

void Keyboard(unsigned char key, int x, int y)
{
	// ESC Ű�� ������ �޽� ����Ʈ�� �޸𸮿��� �����ϰ� �����Ѵ�.
	if (key == 27)
		exit(0);
}

void SetupViewTransform()
{
	// �𵨺� ��� ����
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// �̵�-ȸ�� ��ȯ ����
	glTranslatef(0.0, 0.0, Zoom);
	glRotatef(Angle, Axis[0], Axis[1], Axis[2]);

	// ������ ����� ȸ�� ��ȯ ��, �̵� ��ȯ ����
	glMultMatrixf(RotMat);
	glTranslatef(Pan[0], Pan[1], Pan[2]);

	// ȸ�� ��ȯ�� ����� ����
	glGetFloatv(GL_MODELVIEW_MATRIX, RotMat);
	RotMat[12] = RotMat[13] = RotMat[14] = 0.0;
}

void SetupViewVolume()
{
	// ���� ��� ���� �� ���� ���� ����
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(30.0, (double)Width / (double)Height, 0.01, 10000.0);
}

void RenderFloor()
{
	// �ٴ� ����� �������Ѵ�.
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
	// ���콺 ��ư�� ���� ���,
	if (state == GLUT_DOWN)
	{
		StartPt[0] = x;
		StartPt[1] = y;

		if (button == GLUT_LEFT_BUTTON)
			ManipulateMode = 1;		// ȸ��
		else if (button == GLUT_MIDDLE_BUTTON)
			ManipulateMode = 2;		// �̵�
	}

	// ���콺 ��ư�� �� ���,
	if (state == GLUT_UP)
	{
		// �� �ʱ�ȭ
		ManipulateMode = 0;
		StartPt[0] = StartPt[1] = 0;
		Angle = 0.0;
	}
}

void MouseMove(int x, int y)
{
	// ȸ�� �����,
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
	else  if (ManipulateMode == 2) // �̵� ���
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
	//x,y �� ���콺 Ŭ���� ��ġ
	p[0] = (2.0 * x - Width) / Width;
	p[1] = (-2.0 * y + Height) / Height;
	p[2] = 0.0;

	double r = p * p;
	if (r >= 1.0)
		p.Normalize();
	else
		p[2] = sqrt(1.0 - r);
}

