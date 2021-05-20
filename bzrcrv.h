#pragma once

#include <vector>
#include "gmath.h"
#include ".\usr\include\GL\freeglut.h"

/*!
*	\brief 베지에 곡선을 표현하는 클래스
*/
class GBzrCrv
{
public:
	/*! \brief 곡선의 정의역 [a, b]*/
	GVec2	m_Domain;

	/*! \brief 제어점 배열 (곡선의 차수 = 제어점 수 - 1) */
	std::vector<GVec3>	m_Points;

public:
	// 생성자 및 소멸자
	GBzrCrv() 
	{ 
		m_Domain = GVec2(0.0, 1.0); 
	}
	GBzrCrv(GVec2 Domain, std::vector<GVec3> Points) 
	{ 
		m_Domain = Domain;
		m_Points = Points; 
	}
	~GBzrCrv() {};

public:
	/*!
	*	\brief 곡선 위의 점 C(u)와 접선 벡터 C'(u)를 계산한다.
	*
	*	\param	u[in]	계산 파라미터 (a <= u <= b)
	*	\param	p[out]	곡선 위의 점 C(u)가 저장된다.
	*	\param	v[out]	접선 벡터 C'(u)가 저장된다.
	*/
	void Eval(double u, GVec3 &p, GVec3 &v)
	{
		std::vector<GVec3> Points = m_Points;
		double t = (u - m_Domain[0]) / (m_Domain[1] - m_Domain[0]);
				
		// de_Casteljau 알고리즘을 수행한다.
		int NumPts = (int)Points.size();
		for (int i = 1; i < NumPts; ++i) // i = 1, ... (NumPt - 1)
		{
			for (int j = 0; j < NumPts - i; ++j)
				Points[j] = (1.0 - t) * Points[j] + t * Points[j + 1];

			if (i == NumPts - 2) // 마지막 전단계라면... 일차 미분을 구한다.
				v = (NumPts - 1) * (Points[1] - Points[0]) / (m_Domain[1] - m_Domain[0]);
		}
		p = Points[0];
	}

	/*!
	*	\brief 곡선을 렌더링 한다.
	*
	*	\param	NumOfPts[in]	곡선 위의 점의 수
	*/
	void Render(int NumOfPts)
	{
		int NumPts = (int)m_Points.size();

		// 제어점을 렌더링 한다.
		glColor3d(1.0, 0.0, 0.0);
		glPointSize(5.0f);
		glBegin(GL_POINTS);
		{
			for (int i = 0; i < NumPts; ++i)
				glVertex3d(m_Points[i][0], m_Points[i][1], m_Points[i][2]);
		}
		glEnd();

		// 제어다각형을 렌더링 한다.
		glColor3d(0.0, 1.0, 0.0);
		glLineWidth(2.0);
		glBegin(GL_LINE_STRIP);
		{
			for (int i = 0; i < NumPts; ++i)
				glVertex3d(m_Points[i][0], m_Points[i][1], m_Points[i][2]);
		}
		glEnd();

		// 곡선을 렌더링 한다.
		glColor3f(0.0, 0.0, 1.0);
		glLineWidth(3.0);
		glBegin(GL_LINE_STRIP);
		{
			GVec3 p, v;
			for (int i = 0; i < NumOfPts; ++i)  // i = 0, ... NumOfPts - 1
			{
				double u = m_Domain[0] + (m_Domain[1] - m_Domain[0]) * (double)i / (NumOfPts - 1); // a <= u <= b
				Eval(u, p, v);
				glVertex3d(p[0], p[1], p[2]);
			}
		}
		glEnd();
		glLineWidth(1.0);
		glPointSize(1.0);
	}
};

