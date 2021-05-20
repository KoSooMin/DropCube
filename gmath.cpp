#include "gmath.h"

// 정적 데이터 멤버의 초기화
double GQuater::Precision = 1.0e-7;
double GLine::Precision = 1.0e-7;
double GMatrix::Precision = 1.0e-7;
double GPlane::Precision = 1.0e-7;
double GPos3::Precision = 1.0e-7;
double GVec::Precision = 1.0e-7;
double GVec2::Precision = 1.0e-7;
double GVec3::Precision = 1.0e-7;
double GVec4::Precision = 1.0e-7;

/*!
*	\brief 디폴트 생성자
*
*	\param x x-좌표
*	\param y y-좌표
*/
GVec2::GVec2(double x, double y)
{
	V[0] = x;
	V[1] = y;
}

/*!
*	\brief	복사생성자
*
*	\param cpy 복사될 객체
*/
GVec2::GVec2(const GVec2 &cpy)
{
	V[0] = cpy.V[0];
	V[1] = cpy.V[1];
}

/*!
*	\brief 소멸자
*/
GVec2::~GVec2()
{
}

/*!
*	\brief 대입연산자
*
*	\param rhs 오른쪽 피연산자
*
*	\return 대입된 자신
*/
GVec2 &GVec2::operator =(const GVec2 &rhs)
{
	V[0] = rhs.V[0];
	V[1] = rhs.V[1];
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param rhs 오른쪽 피연산자
*
*	\return 연산후 대입된 자신
*/
GVec2 &GVec2::operator +=(const GVec2 &rhs)
{
	V[0] += rhs.V[0];
	V[1] += rhs.V[1];
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param rhs 오른쪽 피연산자
*
*	\return 연산후 대입된 자신
*/
GVec2 &GVec2::operator -=(const GVec2 &rhs)
{
	V[0] -= rhs.V[0];
	V[1] -= rhs.V[1];
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param s 곱할 상수
*
*	\return 연산후 대입된 자신
*/
GVec2 &GVec2::operator *=(const double &s)
{
	V[0] *= s;
	V[1] *= s;
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param s 나눌 상수
*
*	\return 연산후 대입된 자신
*/
GVec2 &GVec2::operator /=(const double &s)
{
	V[0] /= s;
	V[1] /= s;
	return *this;
}

/*!
*	\brief 단항연산자
*
*	\return 반대부호를 갖는 객체
*/
GVec2 GVec2::operator +() const
{
	return *this;
}

/*!
*	\brief 단항연산자
*
*	\return 반대부호를 갖는 객체
*/
GVec2 GVec2::operator -() const
{
	return *this * -1;
}

/*!
*	\brief 산술연산자(+)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec2 operator +(const GVec2 &lhs, const GVec2 &rhs)
{
	return GVec2(lhs.V[0] + rhs.V[0], lhs.V[1] + rhs.V[1]);
}

/*!
*	\brief 산술연산자(-)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec2 operator -(const GVec2 &lhs, const GVec2 &rhs)
{
	return GVec2(lhs.V[0] - rhs.V[0], lhs.V[1] - rhs.V[1]);
}

/*!
*	\brief 내적연산자(*)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 내적의 결과를 반환
*/
double operator *(const GVec2 &lhs, const GVec2 &rhs)
{
	return lhs.V[0] * rhs.V[0] + lhs.V[1] * rhs.V[1];
}

/*!
*	\brief 산술연산자(/)
*
*	\param s 나룰 상수
*	\return 연산의 결과를 반환
*/
GVec2 operator /(const GVec2 &lhs, const double &s)
{
	return GVec2(lhs.V[0] / s, lhs.V[1] / s);
}

/*!
*	\brief 등호연산자
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교 결과를 반환
*/
bool operator ==(const GVec2 &lhs, const GVec2 &rhs)
{
	double error = GVec2::Precision;
	return (EQ(lhs.V[0], rhs.V[0], error) && EQ(lhs.V[1], rhs.V[1], error));
}

/*!
*	\brief 부등호연산자
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교 결과를 반환
*/
bool operator !=(const GVec2 &lhs, const GVec2 &rhs)
{
	double error = GVec2::Precision;
	return (!EQ(lhs.V[0], rhs.V[0], error) || !EQ(lhs.V[1], rhs.V[1], error));
}

/*!
*	\brief 첨자연산자([])
*
*	\param idx 첨자
*	\param 벡터의 \a idx번째 원소를 반환
*/
double &GVec2::operator [](const int &idx)
{
	assert(idx >= 0 && idx < 2);
	return V[idx];
}

/*!
*	\brief 상수객체에 대한 첨자연산자([])
*
*	\param idx 첨자
*	\param 벡터의 \a idx번째 원소를 반환
*/
const double &GVec2::operator [](const int &idx) const
{
	assert(idx >= 0 && idx < 2);
	return V[idx];
}

/*!
*	\brief 벡터의 좌표를 설정
*
*	\param x x-좌표
*	\param y y-좌표
*/
GVec2 &GVec2::Set(const double &x, const double &y)
{
	V[0] = x;
	V[1] = y;
	return *this;
}

/*!
*	\brief 벡터를 정규하여 단위벡터로 변환
*
*	\return 변환된 자신을 반환
*/
GVec2 &GVec2::Normalize()
{
	double len = norm(*this);
	if (EQ_ZERO(len, Precision))
		return *this;
	V[0] /= len;
	V[1] /= len;
	return *this;
}

/*!
*	\brief 등호 및 부등호 연산자의 오차의 한계 설정
*
*	\param error 오차의 한계
*/
void GVec2::SetPrecision(double error)
{
	Precision = error;
}

/*!
*	\brief 설정된 오차의 한계를 반환
*
*	\return 설정된 오차의 한계
*/
double GVec2::GetPrecision()
{
	return Precision;
}

/*!
*	\brief 산술연산자(*)
*
*	\param lhs 왼쪽 피연산자
*	\param s 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec2 operator *(const GVec2 &lhs, const double &s)
{
	GVec2 ret(lhs);
	ret *= s;
	return ret;
}

/*!
*	\brief 산술연산자(*)
*
*	\param s 왼쪽 피연산자
*	\param lhs 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec2 operator *(const double &s, const GVec2 &rhs)
{
	GVec2 ret(rhs);
	ret *= s;
	return ret;
}

/*!
*	\brief 출력연산자(<<)
*
*	\param os 출력스트림
*	\param v 출력할 벡터
*
*	\return \a v가 출력된 스트림을 반환
*/
std::ostream &operator <<(std::ostream &os, const GVec2 &v)
{
	os << "(" << std::setw(10) << v.V[0] << ", " << std::setw(10) << v.V[1] << ")";
	return os;
}

/*!
*	\brief 입력연산자(>>)
*
*	\param is 입력스트림
*	\param v 입력값이 저장될 벡터
*
*	\return 입력값이 제거된 입력스트림
*/
std::istream &operator >>(std::istream &is, GVec2 &v)
{
	is >> v.V[0] >> v.V[1];
	return is;
}

/*!
*	\brief 벡터 v를 벡터 w에 사영시킨 벡터를 구한다.
*
*	\param v 벡터.
*	\param w 벡터.
*
*	\return 벡터 v를 벡터 w에 사영시킨 벡터를 반환한다.
*/
GVec2 proj(const GVec2 &v, const GVec2 &w)
{
	return (v * w / (w.V[0] * w.V[0] + w.V[1] * w.V[1])) * w;
}

/*!
*	\brief 벡터 v, w의 차이벡터의 길이를 구한다.
*
*	\param v 벡터.
*	\param w 벡터.
*
*	\return  벡터 \a v, \a w의 차이벡터의 길이
*/
double dist(const GVec2 &v, const GVec2 &w)
{
	return norm(v - w);
}

/*!
*	\brief 벡터 v의 크기를 구한다.
*
*	\param v 벡터
*
*	\return 벡터 \a v의 크기
*/
double norm(const GVec2 &v)
{
	return SQRT(SQR(v.V[0]) + SQR(v.V[1]));
}

/*!
*	\brief 두 벡터 사이의 사이각을 구한다.
*	\warning 0 <= 사이각 <= 180
*
*	\param v 시작 벡터
*	\param w 끝 벡터
*	\param radian 각도의 형태(true: radian, false: degree)
*
*	\return 벡터 \a v에서 벡터 \a w까지의 사이각
*/
double angle(const GVec2 &v, const GVec2 &w, bool radian)
{
	GVec3 p, q;
	double cs, sn, theta;

	p.Set(v[0], v[1], 0.0);
	q.Set(w[0], w[1], 0.0);

	p.Normalize();
	q.Normalize();

	cs = p * q;
	sn = norm(p ^ q);

	theta = radian ? atan2(sn, cs) : RAD2DEG(atan2(sn, cs));
	return theta;
}

////////////////////////////////////////////////////////////

/*!
*	\brief 디폴트 생성자
*
*	\param x x-좌표
*	\param y y-좌표
*	\param z z-좌표
*/
GVec3::GVec3(double x, double y, double z)
{
	V[0] = x;
	V[1] = y;
	V[2] = z;
}

/*!
*	\brief	복사생성자
*
*	\param cpy 복사될 객체
*/
GVec3::GVec3(const GVec3 &cpy)
{
	V[0] = cpy.V[0];
	V[1] = cpy.V[1];
	V[2] = cpy.V[2];
}

/*!
*	\brief 소멸자
*/
GVec3::~GVec3()
{
}

/*!
*	\brief 대입연산자
*
*	\param rhs 오른쪽 피연산자
*
*	\return 대입된 자신
*/
GVec3 &GVec3::operator =(const GVec3 &rhs)
{
	V[0] = rhs.V[0];
	V[1] = rhs.V[1];
	V[2] = rhs.V[2];
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param rhs 오른쪽 피연산자
*
*	\return 연산후 대입된 자신
*/
GVec3 &GVec3::operator +=(const GVec3 &rhs)
{
	V[0] += rhs.V[0];
	V[1] += rhs.V[1];
	V[2] += rhs.V[2];
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param rhs 오른쪽 피연산자
*
*	\return 연산후 대입된 자신
*/
GVec3 &GVec3::operator -=(const GVec3 &rhs)
{
	V[0] -= rhs.V[0];
	V[1] -= rhs.V[1];
	V[2] -= rhs.V[2];
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param s 곱할 상수
*
*	\return 연산후 대입된 자신
*/
GVec3 &GVec3::operator *=(const double &s)
{
	V[0] *= s;
	V[1] *= s;
	V[2] *= s;
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param s 나눌 상수
*
*	\return 연산후 대입된 자신
*/
GVec3 &GVec3::operator /=(const double &s)
{
	V[0] /= s;
	V[1] /= s;
	V[2] /= s;
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param rhs 외적의 오른쪽 피연산자
*
*	\return 연산후 대입된 자신
*/
GVec3 &GVec3::operator ^=(const GVec3 &rhs)
{
	double x = V[0], y = V[1], z = V[2];
	V[0] = y * rhs.V[2] - z * rhs.V[1];
	V[1] = z * rhs.V[0] - x * rhs.V[2];
	V[2] = x * rhs.V[1] - y * rhs.V[0];
	return *this;
}

/*!
*	\brief 단항연산자
*
*	\return 반대부호를 갖는 객체
*/
GVec3 GVec3::operator +() const
{
	return *this;
}

/*!
*	\brief 단항연산자
*
*	\return 반대부호를 갖는 객체
*/
GVec3 GVec3::operator -() const
{
	return *this * -1;
}

/*!
*	\brief 산술연산자(+)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec3 operator +(const GVec3 &lhs, const GVec3 &rhs)
{
	return GVec3(lhs.V[0] + rhs.V[0], lhs.V[1] + rhs.V[1], lhs.V[2] + rhs.V[2]);
}

/*!
*	\brief 산술연산자(-)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec3 operator -(const GVec3 &lhs, const GVec3 &rhs)
{
	return GVec3(lhs.V[0] - rhs.V[0], lhs.V[1] - rhs.V[1], lhs.V[2] - rhs.V[2]);
}

/*!
*	\brief 내적연산자(*)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 내적의 결과를 반환
*/
double operator *(const GVec3 &lhs, const GVec3 &rhs)
{
	return lhs.V[0] * rhs.V[0] + lhs.V[1] * rhs.V[1] + lhs.V[2] * rhs.V[2];
}

/*!
*	\brief 산술연산자(/)
*
*	\param s 나룰 상수
*	\return 연산의 결과를 반환
*/
GVec3 operator /(const GVec3 &lhs, const double &s)
{
	return GVec3(lhs.V[0] / s, lhs.V[1] / s, lhs.V[2] / s);
}

/*!
*	\brief 외적연산자(^)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 외적의 결과를 반환
*/
GVec3 operator ^(const GVec3 &lhs, const GVec3 &rhs)
{
	return GVec3(lhs.V[1] * rhs.V[2] - lhs.V[2] * rhs.V[1], lhs.V[2] * rhs.V[0] - lhs.V[0] * rhs.V[2], lhs.V[0] * rhs.V[1] - lhs.V[1] * rhs.V[0]);
}

/*!
*	\brief 등호연산자
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교 결과를 반환
*/
bool operator ==(const GVec3 &lhs, const GVec3 &rhs)
{
	double error = GVec3::Precision;
	return (EQ(lhs.V[0], rhs.V[0], error) && EQ(lhs.V[1], rhs.V[1], error) && EQ(lhs.V[2], rhs.V[2], error));
}

/*!
*	\brief 부등호연산자
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교 결과를 반환
*/
bool operator !=(const GVec3 &lhs, const GVec3 &rhs)
{
	double error = GVec3::Precision;
	return (!EQ(lhs.V[0], rhs.V[0], error) || !EQ(lhs.V[1], rhs.V[1], error) || !EQ(lhs.V[2], rhs.V[2], error));
}

/*!
*	\brief 첨자연산자([])
*
*	\param idx 첨자
*	\param 벡터의 \a idx번째 원소를 반환
*/
double &GVec3::operator [](const int &idx)
{
	assert(idx >= 0 && idx < 3);
	return V[idx];
}

/*!
*	\brief 상수객체에 대한 첨자연산자([])
*
*	\param idx 첨자
*	\param 벡터의 \a idx번째 원소를 반환
*/
const double &GVec3::operator [](const int &idx) const
{
	assert(idx >= 0 && idx < 3);
	return V[idx];
}

/*!
*	\brief 벡터의 좌표를 설정
*
*	\param x x-좌표
*	\param y y-좌표
*	\param z z-좌표
*/
GVec3 &GVec3::Set(const double &x, const double &y, const double &z)
{
	V[0] = x;
	V[1] = y;
	V[2] = z;
	return *this;
}

/*!
*	\brief 벡터를 정규하여 단위벡터로 변환
*
*	\return 변환된 자신을 반환
*/
GVec3 &GVec3::Normalize()
{
	double len = norm(*this);
	if (EQ_ZERO(len, Precision))
		return *this;
	V[0] /= len;
	V[1] /= len;
	V[2] /= len;
	return *this;
}

/*!
*	\brief 등호 및 부등호 연산자의 오차의 한계 설정
*
*	\param error 오차의 한계
*/
void GVec3::SetPrecision(double error)
{
	Precision = error;
}

/*!
*	\brief 설정된 오차의 한계를 반환
*
*	\return 설정된 오차의 한계
*/
double GVec3::GetPrecision()
{
	return Precision;
}

/*!
*	\brief 산술연산자(*)
*
*	\param lhs 왼쪽 피연산자
*	\param s 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec3 operator *(const GVec3 &lhs, const double &s)
{
	GVec3 ret(lhs);
	ret *= s;
	return ret;
}

/*!
*	\brief 산술연산자(*)
*
*	\param s 왼쪽 피연산자
*	\param lhs 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec3 operator *(const double &s, const GVec3 &rhs)
{
	GVec3 ret(rhs);
	ret *= s;
	return ret;
}

/*!
*	\brief 출력연산자(<<)
*
*	\param os 출력스트림
*	\param v 출력할 벡터
*
*	\return \a v가 출력된 스트림을 반환
*/
std::ostream &operator <<(std::ostream &os, const GVec3 &v)
{
	os << "(" << std::setw(10) << v.V[0] << ", " << std::setw(10) << v.V[1] << ", " << std::setw(10) << v.V[2] << ")";
	return os;
}

/*!
*	\brief 입력연산자(>>)
*
*	\param is 입력스트림
*	\param v 입력값이 저장될 벡터
*
*	\return 입력값이 제거된 입력스트림
*/
std::istream &operator >>(std::istream &is, GVec3 &v)
{
	is >> v.V[0] >> v.V[1] >> v.V[2];
	return is;
}

/*!
*	\brief 벡터 v를 벡터 w에 사영시킨 벡터를 구한다.
*
*	\param v 벡터.
*	\param w 벡터.
*
*	\return 벡터 v를 벡터 w에 사영시킨 벡터를 반환한다.
*/
GVec3 proj(const GVec3 &v, const GVec3 &w)
{
	return (v * w / (w.V[0] * w.V[0] + w.V[1] * w.V[1] + w.V[2] * w.V[2])) * w;
}

/*!
*	\brief 벡터 v에 수직한 벡터를 구한다.
*
*	\param v 벡터
*
*	\return 벡터 v를 수직한 벡터를 구하여 반환한다.
*/
GVec3 ortho(const GVec3 &v)
{
	GVec3 ret;

	double min_val = MIN(MIN(v[0], v[1]), v[2]);
	if (min_val == v[0])
		ret.Set(0.0, -v[2], v[1]);

	if (min_val == v[1])
		ret.Set(v[2], 0.0, -v[0]);

	if (min_val == v[2])
		ret.Set(-v[1], v[0], 0.0);

	return ret;
}

/*!
*	\brief 벡터 v, w의 차이벡터의 길이를 구한다.
*
*	\param v 벡터.
*	\param w 벡터.
*
*	\return  벡터 \a v, \a w의 차이벡터의 길이
*/
double dist(const GVec3 &v, const GVec3 &w)
{
	return norm(v - w);
}

/*!
*	\brief 벡터 u, v, w의 행렬식을 계산한다.
*
*	\param u 벡터.
*	\param v 벡터.
*	\param w 벡터.
*
*	\return  벡터 u, v, w의 행렬식의 값을 반환한다.
*/
double det(const GVec3 &u, const GVec3 &v, const GVec3 &w)
{
	return (u[0] * v[1] * w[2] + u[1] * v[2] * w[0] + u[2] * v[0] * w[1]) - (w[0] * v[1] * u[2] + v[0] * u[1] * w[2] + u[0] * w[1] * v[2]);
}

/*!
*	\brief 벡터 v의 크기를 구한다.
*
*	\param v 벡터
*
*	\return 벡터 \a v의 크기
*/
double norm(const GVec3 &v)
{
	return SQRT(SQR(v.V[0]) + SQR(v.V[1]) + SQR(v.V[2]));
}

/*!
*	\brief 두 벡터 사이의 사이각을 구한다.
*	\warning 0 <= 사이각 <= 180
*
*	\param v 시작 벡터
*	\param w 끝 벡터
*	\param radian 각도의 형태(true: radian, false: degree)
*
*	\return 벡터 \a v에서 벡터 \a w까지의 사이각(예각, 방향 상관없음)
*/
double angle(const GVec3 &v, const GVec3 &w, bool radian)
{
	GVec3 p(v);
	GVec3 q(w);
	double cs, sn, theta;

	p.Normalize();
	q.Normalize();

	cs = p * q;
	sn = norm(p ^ q);

	theta = radian ? atan2(sn, cs) : RAD2DEG(atan2(sn, cs));
	return theta;
}

/*!
*	\brief 두 벡터 사이의 사이각을 구한다.
*	\warning 0 <= 사이각 <= 360
*
*	\param v 시작 벡터
*	\param w 끝 벡터
*	\param up 기준 벡터
*	\param radian 각도의 형태(true: radian, false: degree)
*
*	\return 벡터 \a v에서 벡터 \a w까지의 사이각(기준 벡터를 기준으로한 반 시계방향)
*/
double angle(const GVec3 &v, const GVec3 &w, const GVec3 &up, bool radian)
{
	GVec3 p(v);
	GVec3 q(w);
	double cs, sn, theta;

	p.Normalize();
	q.Normalize();
	GVec3 r = p ^ q;

	cs = p * q;
	sn = norm(r);

	theta = atan2(sn, cs);
	if (r * up < 0.0)
		theta = 2 * M_PI - theta;

	theta = radian ? theta : RAD2DEG(theta);
	return theta;
}

/////////////////////////////////////////////////////////////////

/*!
*	\brief 디폴트 생성자
*
*	\param x x-좌표
*	\param y y-좌표
*	\param z z-좌표
*/
GVec4::GVec4(double x, double y, double z, double w)
{
	V[0] = x;
	V[1] = y;
	V[2] = z;
	V[3] = w;
}

/*!
*	\brief	복사생성자
*
*	\param cpy 복사될 객체
*/
GVec4::GVec4(const GVec4 &cpy)
{
	V[0] = cpy.V[0];
	V[1] = cpy.V[1];
	V[2] = cpy.V[2];
	V[3] = cpy.V[3];
}

/*!
*	\brief 소멸자
*/
GVec4::~GVec4()
{
}

/*!
*	\brief 대입연산자
*
*	\param rhs 오른쪽 피연산자
*
*	\return 대입된 자신
*/
GVec4 &GVec4::operator =(const GVec4 &rhs)
{
	V[0] = rhs.V[0];
	V[1] = rhs.V[1];
	V[2] = rhs.V[2];
	V[3] = rhs.V[3];
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param rhs 오른쪽 피연산자
*
*	\return 연산후 대입된 자신
*/
GVec4 &GVec4::operator +=(const GVec4 &rhs)
{
	V[0] += rhs.V[0];
	V[1] += rhs.V[1];
	V[2] += rhs.V[2];
	V[3] += rhs.V[3];
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param rhs 오른쪽 피연산자
*
*	\return 연산후 대입된 자신
*/
GVec4 &GVec4::operator -=(const GVec4 &rhs)
{
	V[0] -= rhs.V[0];
	V[1] -= rhs.V[1];
	V[2] -= rhs.V[2];
	V[3] -= rhs.V[3];
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param s 곱할 상수
*
*	\return 연산후 대입된 자신
*/
GVec4 &GVec4::operator *=(const double &s)
{
	V[0] *= s;
	V[1] *= s;
	V[2] *= s;
	V[3] *= s;
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param s 나눌 상수
*
*	\return 연산후 대입된 자신
*/
GVec4 &GVec4::operator /=(const double &s)
{
	V[0] /= s;
	V[1] /= s;
	V[2] /= s;
	V[3] /= s;
	return *this;
}

/*!
*	\brief 단항연산자
*
*	\return 반대부호를 갖는 객체
*/
GVec4 GVec4::operator +() const
{
	return *this;
}

/*!
*	\brief 단항연산자
*
*	\return 반대부호를 갖는 객체
*/
GVec4 GVec4::operator -() const
{
	return *this * -1;
}

/*!
*	\brief 산술연산자(+)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec4 operator +(const GVec4 &lhs, const GVec4 &rhs)
{
	return GVec4(lhs.V[0] + rhs.V[0], lhs.V[1] + rhs.V[1], lhs.V[2] + rhs.V[2], lhs.V[3] + rhs.V[3]);
}

/*!
*	\brief 산술연산자(-)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec4 operator -(const GVec4 &lhs, const GVec4 &rhs)
{
	return GVec4(lhs.V[0] - rhs.V[0], lhs.V[1] - rhs.V[1], lhs.V[2] - rhs.V[2], lhs.V[3] - rhs.V[3]);
}

/*!
*	\brief 내적연산자(*)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 내적의 결과를 반환
*/
double operator *(const GVec4 &lhs, const GVec4 &rhs)
{
	return lhs.V[0] * rhs.V[0] + lhs.V[1] * rhs.V[1] + lhs.V[2] * rhs.V[2] + lhs.V[3] * rhs.V[3];
}

/*!
*	\brief 산술연산자(/)
*
*	\param s 나룰 상수
*	\return 연산의 결과를 반환
*/
GVec4 operator /(const GVec4 &lhs, const double &s)
{
	return GVec4(lhs.V[0] / s, lhs.V[1] / s, lhs.V[2] / s, lhs.V[3] / s);
}

/*!
*	\brief 등호연산자
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교 결과를 반환
*/
bool operator ==(const GVec4 &lhs, const GVec4 &rhs)
{
	double error = GVec4::Precision;
	return (EQ(lhs.V[0], rhs.V[0], error) && EQ(lhs.V[1], rhs.V[1], error) &&
		EQ(lhs.V[2], rhs.V[2], error) && EQ(lhs.V[3], rhs.V[3], error));
}

/*!
*	\brief 부등호연산자
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교 결과를 반환
*/
bool operator !=(const GVec4 &lhs, const GVec4 &rhs)
{
	double error = GVec4::Precision;
	return (!EQ(lhs.V[0], rhs.V[0], error) || !EQ(lhs.V[1], rhs.V[1], error) ||
		!EQ(lhs.V[2], rhs.V[2], error) || !EQ(lhs.V[3], rhs.V[3], error));
}

/*!
*	\brief 첨자연산자([])
*
*	\param idx 첨자
*	\param 벡터의 \a idx번째 원소를 반환
*/
double &GVec4::operator [](const int &idx)
{
	assert(idx >= 0 && idx < 4);
	return V[idx];
}

/*!
*	\brief 상수객체에 대한 첨자연산자([])
*
*	\param idx 첨자
*	\param 벡터의 \a idx번째 원소를 반환
*/
const double &GVec4::operator [](const int &idx) const
{
	assert(idx >= 0 && idx < 4);
	return V[idx];
}

/*!
*	\brief 벡터의 좌표를 설정
*
*	\param x x-좌표
*	\param y y-좌표
*	\param z z-좌표
*	\param w w-좌표
*/
GVec4 &GVec4::Set(double x, double y, double z, double w)
{
	V[0] = x;
	V[1] = y;
	V[2] = z;
	V[3] = w;
	return *this;
}

/*!
*	\brief 벡터를 정규하여 단위벡터로 변환
*
*	\return 변환된 자신을 반환
*/
GVec4 &GVec4::Normalize()
{
	double len = norm(*this);
	if (EQ_ZERO(len, Precision))
		return *this;
	V[0] /= len;
	V[1] /= len;
	V[2] /= len;
	V[3] /= len;
	return *this;
}

/*!
*	\brief 등호 및 부등호 연산자의 오차의 한계 설정
*
*	\param error 오차의 한계
*/
void GVec4::SetPrecision(double error)
{
	Precision = error;
}

/*!
*	\brief 설정된 오차의 한계를 반환
*
*	\return 설정된 오차의 한계
*/
double GVec4::GetPrecision()
{
	return Precision;
}

/*!
*	\brief 산술연산자(*)
*
*	\param lhs 왼쪽 피연산자
*	\param s 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec4 operator *(const GVec4 &lhs, const double &s)
{
	GVec4 ret(lhs);
	ret *= s;
	return ret;
}

/*!
*	\brief 산술연산자(*)
*
*	\param s 왼쪽 피연산자
*	\param lhs 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec4 operator *(const double &s, const GVec4 &rhs)
{
	GVec4 ret(rhs);
	ret *= s;
	return ret;
}

/*!
*	\brief 출력연산자(<<)
*
*	\param os 출력스트림
*	\param v 출력할 벡터
*
*	\return \a v가 출력된 스트림을 반환
*/
std::ostream &operator <<(std::ostream &os, const GVec4 &v)
{
	os << "(" << std::setw(7) << v.V[0] << ", " << std::setw(7) << v.V[1] << ", "
		<< std::setw(7) << v.V[2] << "," << std::setw(7) << v.V[3] << ")";
	return os;
}

/*!
*	\brief 입력연산자(>>)
*
*	\param is 입력스트림
*	\param v 입력값이 저장될 벡터
*
*	\return 입력값이 제거된 입력스트림
*/
std::istream &operator >>(std::istream &is, GVec4 &v)
{
	is >> v.V[0] >> v.V[1] >> v.V[2] >> v.V[3];
	return is;
}

/*!
*	\brief 벡터 v의 크기를 구한다.
*
*	\param v 벡터
*
*	\return 벡터 \a v의 크기
*/
double norm(const GVec4 &v)
{
	return SQRT(SQR(v.V[0]) + SQR(v.V[1]) + SQR(v.V[2]) + SQR(v.V[3]));
}

/*!
*	\brief 두 벡터의 차이벡터의 크기를 구한다.
*
*	\param v 벡터
*	\param w 벡터
*
*	\return 두 벡터의 차이벡터의 크기
*/
double dist(const GVec4 &v, const GVec4 &w)
{
	return norm(v - w);
}

//////////////////////////////////////////////////////////////////

/*!
*	\brief n 차원 벡터를 생성하는 생성자
*	\note 모든 원소는 0으로 초기화 된다.
*
*	\param dim 벡터의 차원
*/
GVec::GVec(int dim)
{
	this->N = dim;
	V = new double[N];
	ARR_ZERO(V, N);
}

/*!
*	\brief n 차원 벡터를 생성하는 생성자
*
*	\param dim 벡터의 차원
*	\param x 벡터의 첫번재 원소 (가변인자로 계속 반복됨)
*/
GVec::GVec(int dim, double x, ...)
{
	this->N = dim;
	V = new double[N];
	va_list ap;
	va_start(ap, dim);
	for (int i = 0; i < N; i++)
		V[i] = va_arg(ap, double);
	va_end(ap);
}

/*!
*	\brief n 차원 벡터를 생성하는 생성자
*
*	\param dim 벡터의 차원
*	\param x 벡터의 첫번재 원소 (가변인자로 계속 반복됨)
*/
GVec::GVec(int dim, int x, ...)
{
	this->N = dim;
	V = new double[N];
	va_list ap;
	va_start(ap, dim);
	for (int i = 0; i < N; i++)
		V[i] = (double)va_arg(ap, int);
	va_end(ap);
}

/*!
*	\brief 복사생성자
*
*	\param copy 복사될 객체
*/
GVec::GVec(const GVec &cpy)
{
	N = cpy.N;
	V = new double[N];
	memcpy(V, cpy.V, N * sizeof(double));
}

/*!
*	\brief 소멸자
*/
GVec::~GVec()
{
	if (V)
		delete[] V;
	V = NULL;
}

/*!
*	\brief 대입연산자 중복
*
*	\param rhs 대입연산자의 오른쪽 피연산자
*
*	\return 대입된 자신을 반환한다
*/
GVec &GVec::operator =(const GVec &rhs)
{
	if (V)
		delete[] V;
	N = rhs.N;
	V = new double[N];
	memcpy(V, rhs.V, N * sizeof(double));
	return *this;
}

/*!
*	\brief 복합대입연산자 중복
*
*	\param rhs 오른쪽 피연산자
*
*	\return 대입된 자신을 반환한다
*/
GVec &GVec::operator +=(const GVec &rhs)
{
	assert(N == rhs.N);
	for (int i = 0; i != N; ++i)
		V[i] += rhs.V[i];
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param rhs 오른쪽 피연산자
*
*	\return 대입된 자신을 반환한다
*/
GVec &GVec::operator -=(const GVec &rhs)
{
	assert(N == rhs.N);
	for (int i = 0; i != N; ++i)
		V[i] -= rhs.V[i];
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param s 오른쪽 피연산자 (스케일 값)
*
*	\return 대입된 자신을 반환한다
*/
GVec &GVec::operator *=(const double &s)
{
	for (int i = 0; i != N; ++i)
		V[i] *= s;
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param s 오른쪽 피연산자 (division factor)
*
*	\return 대입된 자신을 반환한다
*/
GVec &GVec::operator /=(const double &s)
{
	assert(s != 0);
	for (int i = 0; i != N; ++i)
		V[i] /= s;
	return *this;
}

/*!
*	\brief 단항연산자중복 (+)
*
*	\return 새로운 객체를 반환한다
*/
GVec GVec::operator +() const
{
	return *this;
}

/*!
*	\brief 단항연산자중복 (-)
*
*	\return 새로운 객체를 반환한다
*/
GVec GVec::operator -() const
{
	return *this * -1;
}

/*!
*	\brief 산술연산자(+)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec operator +(const GVec &lhs, const GVec &rhs)
{
	assert(lhs.N == rhs.N);
	GVec ret(lhs.N);
	for (int i = 0; i != lhs.N; ++i)
		ret.V[i] = lhs.V[i] + rhs.V[i];
	return ret;
}

/*!
*	\brief 산술연산자(-)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec operator -(const GVec &lhs, const GVec &rhs)
{
	assert(lhs.N == rhs.N);
	GVec ret(lhs.N);
	for (int i = 0; i != lhs.N; ++i)
		ret.V[i] = lhs.V[i] - rhs.V[i];
	return ret;
}

/*!
*	\brief 내적연산자
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 내적의 결과를 반환
*/
double operator *(const GVec &lhs, const GVec &rhs)
{
	assert(lhs.N == rhs.N);
	double ret = 0;
	for (int i = 0; i != lhs.N; ++i)
		ret += lhs.V[i] * rhs.V[i];
	return ret;
}

/*!
*	\brief 산술연산자(/)
*
*	\param lhs 왼쪽 피연산자
*	\param s 나눌 값
*
*	\return 연산의 결과를 반환
*/
GVec operator /(const GVec &lhs, const double &s)
{
	GVec ret(lhs.N);
	for (int i = 0; i != lhs.N; ++i)
		ret.V[i] = lhs.V[i] / s;
	return ret;
}

/*!
*	\brief 부등호연산자 (>)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교의 결과를 반환
*/
bool operator >(const GVec &lhs, const GVec &rhs)
{
	if (norm(lhs) > norm(rhs))
		return true;
	else
		return false;
}

/*!
*	\brief 부등호연산자 (>=)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교의 결과를 반환
*/
bool operator >=(const GVec &lhs, const GVec &rhs)
{
	if (norm(lhs) >= norm(rhs))
		return true;
	else
		return false;
}

/*!
*	\brief 부등호연산자 (<)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교의 결과를 반환
*/
bool operator <(const GVec &lhs, const GVec &rhs)
{
	if (norm(lhs) < norm(rhs))
		return true;
	else
		return false;
}

/*!
*	\brief 부등호연산자 (<=)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교의 결과를 반환
*/
bool operator <=(const GVec &lhs, const GVec &rhs)
{
	if (norm(lhs) <= norm(rhs))
		return true;
	else
		return false;
}

/*!
*	\brief 등호연산자(==)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교의 결과를 반환
*/
bool operator ==(const GVec &lhs, const GVec &rhs)
{
	assert(lhs.N == rhs.N);
	double error = GVec::Precision;
	for (int i = 0; i != lhs.N; ++i)
		if (!EQ(lhs.V[i], rhs.V[i], error))
			return false;
	return true;
}

/*!
*	\brief 부등호연산자(!=)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교의 결과를 반환
*/
bool operator !=(const GVec &lhs, const GVec &rhs)
{
	assert(lhs.N == rhs.N);
	double error = GVec::Precision;
	for (int i = 0; i != lhs.N; ++i)
		if (!EQ(lhs.V[i], rhs.V[i], error))
			return true;
	return false;
}

/*!
*	\brief 첨자연산자([])
*
*	\param idx 첨자
*
*	\return 벡터의 \a idx 번째 원소를 반환
*/
double &GVec::operator [](const int &idx)
{
	assert(idx >= 0 && idx < N);
	return V[idx];
}

/*!
*	\brief 상수객체의 첨자연산자([])
*
*	\param idx 첨자
*
*	\return 벡터의 \a idx 번째 원소를 반환
*/
const double &GVec::operator [](const int &idx) const
{
	assert(idx >= 0 && idx < N);
	return V[idx];
}

/*!
*	\brief 벡터의 원소를 설정한다.
*	\warning 매개변수는 실수형으로 주어야 한다. 예) 1: 불가능, 1.0: 가능.
*
*	\param x 좌표
*
*	\return 설정된 자신을 반환한다.
*/
GVec &GVec::Set(double x, ...)
{
	V[0] = x;
	va_list ap;
	va_start(ap, x);
	for (int i = 1; i != N; ++i)
		V[i] = va_arg(ap, double);
	va_end(ap);
	return *this;
}

/*!
*	\brief 벡터의 원소를 설정한다.
*	\warning 매개변수는 정수형으로 주어야 한다. 예) 1: 가능, 1.0: 불가능.
*
*	\param x 좌표
*
*	\return 설정된 자신을 반환한다.
*/
GVec &GVec::Set(int x, ...)
{
	V[0] = (double)x;
	va_list ap;
	va_start(ap, x);
	for (int i = 1; i != N; ++i)
		V[i] = (double)va_arg(ap, int);
	va_end(ap);
	return *this;
}

/*!
*	\brief 벡터의 원소를 설정한다.
*
*	\param pVal 설정될 원소를 저장한 N차원 실수 배열
*
*	\return 설정된 자신을 반환한다.
*/
GVec &GVec::Set(double *pVal)
{
	memcpy(V, pVal, sizeof(double) * N);
	return *this;
}

/*!
*	\brief 벡터를 정규화한다.
*
*	\return 정규화된 자신을 반환한다.
*/
GVec &GVec::Normalize()
{
	double len = norm(*this);
	for (int i = 0; i != N; ++i)
		V[i] /= len;
	return *this;
}

/*!
*	\brief 영벡터로 설정한다.
*
*	\return 자신을 반환한다.
*/
GVec &GVec::SetZeros()
{
	for (int i = 0; i != N; ++i)
		V[i] = 0.0;
	return *this;
}

/*!
*	\brief 벡터의 차원을 반환한다.
*
*	\return 벡터의 차원값
*/
int GVec::GetDim() const
{
	return N;
}

/*!
*	\brief 비교를 위한 오차의 한계를 설정한다.
*
*	\param error 오차의 한계
*/
void GVec::SetPrecision(double error)
{
	Precision = error;
}

/*!
*	\breief 비교를 위한 오차의 한계값을 반환한다.
*
*	\return 비교를 위한 오차의 한계값
*/
double GVec::GetPrecision()
{
	return Precision;
}

/*!
*	\brief 산술연산자(*)
*
*	\param lhs 왼쪽 피연산자
*	\param s 상수
*	\return 연산의 결과를 반환
*/
GVec operator *(const GVec &lhs, const double &s)
{
	GVec ret(lhs.N);
	for (int i = 0; i != lhs.N; ++i)
		ret.V[i] = lhs.V[i] * s;
	return ret;
}

/*!
*	\brief 산술연산자(*)
*
*	\param s 상수
*	\param rhs 왼쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GVec operator *(const double &s, const GVec &rhs)
{
	GVec ret(rhs.N);
	for (int i = 0; i != rhs.N; ++i)
		ret.V[i] = rhs.V[i] * s;
	return ret;
}

/*!
*	\brief 출력연산자(<<)
*
*	\param os 출력스트림
*	\param v 출력할 벡터
*
*	\return \a v가 출력된 스트림을 반환
*/
std::ostream &operator <<(std::ostream &os, const GVec &v)
{
	for (int i = 0; i != v.N; ++i)
		if (i != v.N - 1)
			os << "| " << std::setw(10) << v.V[i] << " |" << std::endl;
		else
			os << "| " << std::setw(10) << v.V[i] << " |";
	return os;
}

/*!
*	\brief 입력연산자(>>)
*
*	\param is 입력스트림
*	\param v 입력값이 저장될 벡터
*
*	\return 입력값이 제거된 입력스트림
*/
std::istream &operator >>(std::istream &is, GVec &v)
{
	for (int i = 0; i != v.N; ++i)
		is >> v.V[i];
	return is;
}

/*!
*	\brief 벡터 v의 크기를 구한다.
*
*	\param v 벡터
*
*	\return 벡터 v의 크기
*/
double norm(const GVec &v)
{
	double len = 0;
	for (int i = 0; i != v.N; ++i)
		len += SQR(v.V[i]);
	len = SQRT(len);
	return len;
}

/*!
*	\brief 두 벡터의 차이벡터의 크기를 구한다.
*
*	\param v 벡터
*	\param w 벡터
*
*	\return 두 벡터의 차이벡터의 크기
*/
double dist(const GVec &v, const GVec &w)
{
	return norm(v - w);
}

/////////////////////////////////////////////////////////////////////

/*!
*	\brief 디폴트 생성자
*
*	\param x x-좌표
*	\param y y-좌표
*	\param z z-좌표
*/
GPos3::GPos3(double x, double y, double z)
{
	V[0] = x;
	V[1] = y;
	V[2] = z;
}

/*!
*	\brief 복사생성자
*
*	\param cpy 복사될 객체
*
*	\return 복사된 자신을 반환
*/
GPos3::GPos3(const GPos3 &cpy)
{
	V[0] = cpy.V[0];
	V[1] = cpy.V[1];
	V[2] = cpy.V[2];
}

/*!
*	\brief  소멸자
*/
GPos3::~GPos3()
{
}

/*!
*	\brief 대입연산자
*
*	\param rhs 오른쪽 피연산자
*
*	\return 대입된 자신을 반환
*/
GPos3 &GPos3::operator =(const GPos3 &rhs)
{
	V[0] = rhs.V[0];
	V[1] = rhs.V[1];
	V[2] = rhs.V[2];
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param rhs 오른쪽 피연산자
*
*	\return 연산후 대입된 자신
*/
GPos3 &GPos3::operator +=(const GVec3 &rhs)
{
	V[0] += rhs.V[0];
	V[1] += rhs.V[1];
	V[2] += rhs.V[2];
	return *this;
}

/*!
*	\brief 산술연산자(-)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 연산의 결과(벡터)를 반환
*/
GVec3 operator -(const GPos3 &lhs, const GPos3 &rhs)
{
	return GVec3(lhs.V[0] - rhs.V[0], lhs.V[1] - rhs.V[1], lhs.V[2] - rhs.V[2]);
}

/*!
*	\brief 산술연산자(-)
*
*	\param lhs 왼쪽 피연산자(포인트)
*	\param rhs 오른쪽 피연산자(벡터)
*
*	\return 연산의 결과(포인트)를 반환
*/
GPos3 operator -(const GPos3 &lhs, const GVec3 &rhs)
{
	return GPos3(lhs.V[0] - rhs[0], lhs.V[1] - rhs[1], lhs.V[2] - rhs[2]);
}

/*!
*	\brief 산술연산자(+)
*
*	\param lhs 왼쪽 피연산자(포인트)
*	\param rhs 오른쪽 피연산자(벡터)
*
*	\return 연산의 결과(포인트)를 반환
*/
GPos3 operator +(const GPos3 &lhs, const GVec3 &rhs)
{
	return GPos3(lhs.V[0] + rhs[0], lhs.V[1] + rhs[1], lhs.V[2] + rhs[2]);
}

/*!
*	\brief 산술연산자(+)
*
*	\param lhs 왼쪽 피연산자(벡터)
*	\param rhs 오른쪽 피연산자(포인트)

*
*	\return 연산의 결과(포인트)를 반환
*/
GPos3 operator +(const GVec3 &lhs, const GPos3 &rhs)
{
	return GPos3(lhs.V[0] + rhs[0], lhs.V[1] + rhs[1], lhs.V[2] + rhs[2]);
}

/*!
*	\brief 등호연산자
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교결과를 반환
*/
bool operator ==(const GPos3 &lhs, const GPos3 &rhs)
{
	double error = GPos3::Precision;
	return (EQ(lhs.V[0], rhs.V[0], error) && EQ(lhs.V[1], rhs.V[1], error) && EQ(lhs.V[2], rhs.V[2], error));
}

/*!
*	\brief 부등호연산자
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교결과를 반환
*/
bool operator !=(const GPos3 &lhs, const GPos3 &rhs)
{
	double error = GPos3::Precision;
	return (!EQ(lhs.V[0], rhs.V[0], error) || !EQ(lhs.V[1], rhs.V[1], error) || !EQ(lhs.V[2], rhs.V[2], error));
}

/*!
*	\brief 첨자연산자([])
*
*	\param idx 첨자
*
*	\return \a idx 번째 원소를 반환
*/
double &GPos3::operator [](const int &idx)
{
	assert(idx >= 0 && idx < 3);
	return V[idx];
}

/*!
*	\brief 상수객체의 첨자연산자([])
*
*	\param idx 첨자
*
*	\return \a idx 번째 원소를 반환
*/
const double &GPos3::operator [](const int &idx) const
{
	assert(idx >= 0 && idx < 3);
	return V[idx];
}

/*!
*	\brief 포인트의 좌표를 설정한다.
*
*	\param x x-좌표
*	\param y y-좌표
*	\param z z-좌표
*
*	\return 설정된 자신을 반환
*/
GPos3 &GPos3::Set(const double &x, const double &y, const double &z)
{
	V[0] = x;
	V[1] = y;
	V[2] = z;
	return *this;
}

/*!
*	\brief 등호 및 부등호 연산자의 오차의 한계 설정
*
*	\param error 오차의 한계
*/
void GPos3::SetPrecision(double error)
{
	Precision = error;
}

/*!
*	\brief 설정된 오차의 한계를 반환
*
*	\return 설정된 오차의 한계
*/
double GPos3::GetPrecision()
{
	return Precision;
}

/*!
*	\brief 출력연산자(<<)
*
*	\param os 출력스트림
*	\param p 출력할 객체
*
*	\return 출력된 스트림 객체를 반환
*/
std::ostream &operator <<(std::ostream &os, const GPos3 &p)
{
	os << "(" << std::setw(5) << p.V[0] << ", " << std::setw(5) << p.V[1] << ", " << std::setw(5) << p.V[2] << ")";
	return os;
}

/*!
*	\brief 입력연산자(>>)
*
*	\param is 입력스트림
*	\param v 입력값이 저장될 벡터
*
*	\return 입력값이 제거된 입력스트림
*/
std::istream &operator >>(std::istream &is, GPos3 &p)
{
	is >> p.V[0] >> p.V[1] >> p.V[2];
	return is;
}

/*!
*	\brief 점 \a p의 길이를 구한다.
*
*	\param p 점
*
*	\return 점 \a p의 길이.
*/
double norm(const GPos3 &p)
{
	return SQRT(SQR(p.V[0]) + SQR(p.V[1]) + SQR(p.V[2]));
}

/*!
*	\brief 점 \a p에서 점 \a q까지의 거리를 구한다.
*
*	\param p 점
*	\param q 점
*
*	\return 점 \a p에서 점 \a q까지의 거리
*/
double dist(const GPos3 &p, const GPos3 &q)
{
	return SQRT(SQR(p.V[0] - q.V[0]) + SQR(p.V[1] - q.V[1]) + SQR(p.V[2] - q.V[2]));
}

/*!
*	\brief 점 \a p에서 점 \a q까지의 거리의 제곱을 구한다.
*
*	\param p 점
*	\param q 점
*
*	\return 점 \a p에서 점 \a q까지의 거리
*/
double dist_sq(const GPos3 &p, const GPos3 &q)
{
	return (SQR(p.V[0] - q.V[0]) + SQR(p.V[1] - q.V[1]) + SQR(p.V[2] - q.V[2]));
}

/*!
*	\brief 점 pt의 좌표를 벡터형태로 반환한다.
*
*	\param pt 3차원 공간의 점
*
*	\return pt의 3차원 벡터 표현
*/
GVec3 cast_vec3(const GPos3 &pt)
{
	return GVec3(pt[0], pt[1], pt[2]);
}

/*!
*	\brief 점 pt의 좌표를 4차원 벡터형태로 반환한다.
*
*	\param pt 3차원 공간의 점
*	\param w 4번째 좌표값
*
*	\return pt의 4차원 벡터 표현
*/
GVec4 cast_vec4(const GPos3 &pt, double w)
{
	return GVec4(pt[0], pt[1], pt[2], w);
}

/*!
*	\brief 점 pt의 좌표를 벡터형태로 반환
*
*	\param pt 3차원 공간의 점
*
*	\return pt의 벡터 표현
*/
GVec cast_vec(const GPos3 &pt)
{
	return GVec(3, pt[0], pt[1], pt[2]);
}

/*!
*	\brief 점 p의 좌표를 주어진 자리수까지(반올림하여) 나타냄
*
*	\param p 3차원 공간의 점
*
*	\return 반올림된 점의 표현
*/
GPos3 round_off(const GPos3 &p, int place)
{
	double a = pow(10.0, -place);
	double x = ((int)(p[0] * a + 0.5)) / a;
	double y = ((int)(p[1] * a + 0.5)) / a;
	double z = ((int)(p[2] * a + 0.5)) / a;

	return GPos3(x, y, z);
}

/*!
*	\brief 2차원 벡터표현을 3차원 벡터로 변환한다.
*
*	\param v 2차원 벡터
*
*	\return v의 3차원 벡터표현
*/
GVec3 cast_vec3(const GVec2 &v)
{
	return GVec3(v[0], v[1], 0.0);
}

/*!
*	\brief 2차원 벡터 v의 좌표를 일반적인 벡터 형태로 반환
*
*	\param v 2차원 벡터
*
*	\return 3차원 벡터 v의 좌표를 일반적인 벡터 형태로 반환
*/
GVec cast_vec(const GVec2 &v)
{
	return GVec(2, v[0], v[1]);
}

/*!
*	\brief 벡터 v의 좌표를 포인트 형태로 반환
*
*	\param v 3차원 공간의 벡터
*
*	\return v의 좌표를 포인트 형태로 반환
*/
GPos3 cast_pt3(const GVec3 &v)
{
	return GPos3(v[0], v[1], v[2]);
}

/*!
*	\brief 3차원 벡터 v의 좌표를 일반적인 벡터 형태로 반환
*
*	\param v 3차원 공간의 벡터
*
*	\return 3차원 벡터 v의 좌표를 일반적인 벡터 형태로 반환
*/
GVec cast_vec(const GVec3 &v)
{
	return GVec(3, v[0], v[1], v[2]);
}

/*!
*	\brief 3차원 벡터를 4차원 벡터형태로 반환한다.
*
*	\param v 3차원 벡터
*	\param w 4번째 좌표값
*
*	\return v의 확장된 4차원 벡터 표현
*/
GVec4 cast_vec4(const GVec3 &v, double w)
{
	return GVec4(v[0], v[1], v[2], w);
}

/*!
*	\brief 4차원 벡터 v의 좌표를 일반적인 벡터 형태로 반환
*
*	\param v 4차원 공간의 벡터
*
*	\return 4차원 벡터 v의 좌표를 일반적인 벡터 형태로 반환
*/
GVec cast_vec(const GVec4 &v)
{
	return GVec(4, v[0], v[1], v[2], v[3]);
}

/*!
*	\brief 4차원 벡터 v의 좌표를 3차원 벡터 형태로 반환
*
*	\param v 4차원 공간의 벡터
*
*	\return 4차원 벡터 v의 좌표를 3차원 벡터 형태로 반환
*/
GVec3 cast_vec3(const GVec4 &v)
{
	return GVec3(v[0], v[1], v[2]);
}

/*!
*	\brief 4차원 벡터 v의 좌표를 3차원 포인트 형태로 반환
*
*	\param v 4차원 공간의 벡터
*
*	\return 4차원 벡터 v의 좌표를 3차원 포인트 형태로 반환
*/
GPos3 cast_pt3(const GVec4 &v)
{
	return GPos3(v[0], v[1], v[2]);
}

/*!
*	\brief v=(x, y, z, w) -> v'=(wx, wy, wz, w)
*
*	\param v 4차원 공간의 벡터
*
*	\return  v'=(wx, wy, wz, w)를 반환
*/
GVec4 homogenize(const GVec4 &v)
{
	return GVec4(v[0] * v[3], v[1] * v[3], v[2] * v[3], v[3]);
}


/*!
*	\brief v=(wx, wy, wz, w) -> v'=(x, y, z, w)
*
*	\param v 4차원 공간의 벡터
*
*	\return  v'=(x, y, z, w)를 반환
*/
GVec4 rationalize(const GVec4 &v)
{
	return GVec4(v[0] / v[3], v[1] / v[3], v[2] / v[3], v[3]);
}

/*!
*	\brief v=(wx, wy, wz, w) -> v'=(x, y, z, 1)
*
*	\param v 4차원 공간의 벡터
*
*	\return v'=(x, y, z, 1)를 반환
*/
GVec4 cartesianize(const GVec4 &v)
{
	return GVec4(v[0] / v[3], v[1] / v[3], v[2] / v[3], 1.0);
}

/*!
*	\brief 점들의 affine combination을 구한다
*
*	\param N 점의 개수
*	\param alpha0 상수
*	\param p0 첫 번째 점
*	\param alpha1 상수
*	\param p1 첫 번째 점
*
*	\return 점들의 affine combination의 결과 (alpha0 * p0 + alpha1 * p1 + ... + alpha_n-1 * p_n-1)
*/
GPos3 affine_sum(int N, ...)
{
	GPos3 ret;

	va_list ap;
	va_start(ap, N);
	for (int i = 0; i < N; ++i)
	{
		double alpha = va_arg(ap, double);
		GPos3 p = va_arg(ap, GPos3);

		ret[0] = ret[0] + alpha * p[0];
		ret[1] = ret[1] + alpha * p[1];
		ret[2] = ret[2] + alpha * p[2];
	}
	va_end(ap);

	return ret;
}

/*!
*	\brief 점들의 affine combination을 구한다
*
*	\param Points 점의 배열에 대한 포인터
*	\param Weights combination의 상수값
*	\param Size 점의 개수 (Points, Weights 배열의 크기)
*
*	\return 점들의 affine combination의 결과 (= Point[0] * Weight[0] + Points[1] * Weight[1] + ... + Points[Size-1] * Weight[Size-1])
*/
GPos3 affine_sum(GPos3 *Points, double *Weights, const int Size)
{
	GPos3 ret;
	for (int i = 0; i < Size; i++)
	{
		ret.V[0] += Points[i][0] * Weights[i];
		ret.V[1] += Points[i][1] * Weights[i];
		ret.V[2] += Points[i][2] * Weights[i];
	}
	return ret;
}

//////////////////////////////////////////////////////////////////

/*!
*	\brief 생성자
*
*	\param row 행벡터의 차원
*	\param col 열벡터의 차원
*	\param elem 행렬의 원소
*/
GMatrix::GMatrix(int row, int col, double *elem)
{
	r = row;
	c = col;
	M = new double[r * c];
	if (elem)
		memcpy(M, elem, sizeof(double) * r * c);
	else
		memset(M, 0, sizeof(double) * r * c);
}

/*!
*	\brief 복사생성자
*
*	\param 복사될 객체
*/
GMatrix::GMatrix(const GMatrix &cpy)
{
	r = cpy.r;
	c = cpy.c;
	M = new double[r * c];
	memcpy(M, cpy.M, sizeof(double) * r * c);
}

/*!
*	\brief 소멸자
*/
GMatrix::~GMatrix()
{
	if (M)
		delete[] M;
	M = NULL;
}

/*!
*	\brief 대입연산자
*
*	\param rhs 대입될 오른쪽 피연산자
*
*	\return 대입된 자신을 반환
*/
GMatrix &GMatrix::operator =(const GMatrix &rhs)
{
	if (M)
		delete[] M;

	r = rhs.r;
	c = rhs.c;
	M = new double[r * c];

	memcpy(M, rhs.M, sizeof(double) * r * c);
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param rhs 오른쪽 피연산자
*
*	\return 연산후 대입된 자신
*/
GMatrix &GMatrix::operator +=(const GMatrix &rhs)
{
	assert(r == rhs.r && c == rhs.c);
	for (int i = 0; i < r * c; ++i)
		M[i] += rhs.M[i];
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param rhs 오른쪽 피연산자
*
*	\return 연산후 대입된 자신
*/
GMatrix &GMatrix::operator -=(const GMatrix &rhs)
{
	assert(r == rhs.r && c == rhs.c);
	for (int i = 0; i < r * c; ++i)
		M[i] -= rhs.M[i];
	return *this;
}

/*!
*	\brief 복합대입연산자
*	\note 버그발견 (M[i * c + k] --> M[i * rhs.r + k]) 2010. 6. 15.
*
*	\param rhs 오른쪽 피연산자
*
*	\return 연산후 대입된 자신
*/
GMatrix &GMatrix::operator *=(const GMatrix &rhs)
{
	assert(c == rhs.r);

	c = rhs.c;
	double *newM = new double[r * c];
	memset(newM, 0, sizeof(double) * r * c);

	for (int i = 0; i != r; ++i)
		for (int j = 0; j != c; ++j)
			for (int k = 0; k != rhs.r; ++k)
				newM[i * c + j] += M[i * rhs.r + k] * rhs.M[k * rhs.c + j];

	delete[] M;
	M = newM;

	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param s 오른쪽 피연산자(상수)
*
*	\return 연산후 대입된 자신
*/
GMatrix &GMatrix::operator *=(const double &s)
{
	for (int i = 0; i < r * c; i++)
		M[i] *= s;
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param s 오른쪽 피연산자(상수)
*
*	\return 연산후 대입된 자신
*/
GMatrix &GMatrix::operator /=(const double &s)
{
	for (int i = 0; i < r * c; i++)
		M[i] /= s;
	return *this;
}

/*!
*	\brief 다항연산자 (+)
*
*	\return 같은 부호 및 같은 값을 갖는 객체를 반환
*/
GMatrix GMatrix::operator +() const
{
	return *this;
}

/*!
*	\brief 단항연산자 (-)
*
*	\return 반대부호의 같은 값을 갖는 객체를 반환
*/
GMatrix GMatrix::operator -() const
{
	return *this * -1;
}

/*!
*	\brief 산술연산자(+)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GMatrix operator +(const GMatrix &lhs, const GMatrix &rhs)
{
	assert(lhs.r == rhs.r && lhs.c == rhs.c);
	GMatrix ret(lhs.r, lhs.c);
	ret += rhs;
	return ret;
}

/*!
*	\brief 산술연산자(-)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GMatrix operator -(const GMatrix &lhs, const GMatrix &rhs)
{
	assert(lhs.r == rhs.r && lhs.c == rhs.c);
	GMatrix ret(lhs);
	ret -= rhs;
	return ret;
}

/*!
*	\brief 산술연산자(*)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 연산의 결과를 반환
*/
GMatrix operator *(const GMatrix &lhs, const GMatrix &rhs)
{
	assert(lhs.c == rhs.r);
	GMatrix ret(lhs);
	ret *= rhs;
	return ret;
}

/*!
*	\brief 산술연산자(/)
*
*	\param lhs 왼쪽 피연산자
*	\param s 상수
*
*	\return 연산의 결과를 반환
*/
GMatrix operator /(const GMatrix &lhs, const double &s)
{
	GMatrix ret(lhs);
	ret /= s;
	return ret;
}

/*!
*	\brief 등호연산자(==)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교의 결과를 반환
*/
bool operator ==(const GMatrix &lhs, const GMatrix &rhs)
{
	assert(lhs.r == rhs.r && lhs.c == rhs.c);
	double error = GMatrix::Precision;
	for (int i = 0; i != lhs.r * lhs.c; ++i)
		if (!EQ(lhs.M[i], rhs.M[i], error))
			return false;
	return true;
}

/*!
*	\brief 부등호연산자(!=)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return 비교의 결과를 반환
*/
bool operator !=(const GMatrix &lhs, const GMatrix &rhs)
{
	assert(lhs.r == rhs.r && lhs.c == rhs.c);
	double error = GMatrix::Precision;
	for (int i = 0; i != lhs.r * lhs.c; ++i)
		if (EQ(lhs.M[i], rhs.M[i], error))
			return true;
	return false;
}

/*!
*	\brief 첨자연산자([])
*
*	\param idx 행의 첨자
*
*	\return \a idx 행의 배열을 반환
*/
double *GMatrix::operator [](const int idx)
{
	assert(idx >= 0 && idx < r);
	return &M[idx * c];
}

/*!
*	\brief 상수객체의 첨자연산자([])
*
*	\param idx 행의 첨자
*
*	\return \a idx 행의 배열을 반환
*/
const double *GMatrix::operator [](const int idx) const
{
	assert(idx >= 0 && idx < r);
	return &M[idx * c];
}

/*!
*	\brief 행렬을 전치행렬로 변환한다.
*
*	\return 변환된 자신을 반환
*/
GMatrix &GMatrix::SetTranspose()
{
	int i, j;
	if (r == c)	// Square matrix
	{
		for (i = 0; i != r; ++i)
			for (j = i + 1; j != c; ++j)
				SWAP(double, M[i * c + j], M[j * c + i]);
	}
	else		// Rectangular matrix
	{
		double *buffer = new double[r * c];
		memcpy(buffer, M, sizeof(double) * r * c);
		SWAP(int, r, c);
		for (i = 0; i != r; ++i)
			for (j = 0; j != c; ++j)
				M[i * c + j] = buffer[j * r + i];
		delete[] buffer;
	}
	return *this;
}

/*!
*	\brief 단위행렬로 변환한다.
*
*	\return 변환된 자신을 리턴한다.
*/
GMatrix &GMatrix::SetIdentity()
{
	memset(M, 0, sizeof(double) * r * c);
	int min = MIN(r, c);
	for (int i = 0; i < min; i++)
		M[i * c + i] = 1.0;
	return *this;
}

/*!
*	\brief 영행렬로 변환한다.
*
*	\return 변환된 자신을 리턴한다.
*/
GMatrix &GMatrix::SetZeros()
{
	memset(M, 0, sizeof(double) * r * c);
	return *this;
}

/*!
*	\brief idx 번째의 행벡터를 v로 설정한다.
*
*	\param idx 행벡터의 인덱스
*	\param v 설정할 벡터
*
*	\return 변환된 자신을 리턴한다.
*/
GMatrix &GMatrix::SetRowVec(const int idx, const GVec &v)
{
	assert(idx < r);
	assert(v.N == c);
	for (int i = 0; i < c; i++)
		M[idx * c + i] = v.V[i];
	return *this;
}

/*!
*	\brief idx 번째의 열벡터를 v로 설정한다.
*
*	\param idx 열벡터의 인덱스
*	\param v 설정할 벡터
*
*	\return 변환된 자신을 리턴한다.
*/
GMatrix &GMatrix::SetColVec(const int idx, const GVec &v)
{
	assert(idx < c);
	assert(v.N == r);
	for (int i = 0; i < r; i++)
		M[i * c + idx] = v.V[i];
	return *this;
}

/*!
*	\brief idx0번째 행벡터와 idx1번째 행벡터를 교환한다.
*
*	\param idx0 행벡터의 인덱스
*	\param idx1 행벡터의 인덱스
*
*	\return 변환된 자신을 리턴한다.
*/
GMatrix &GMatrix::ExchangeRows(const int idx0, const int idx1)
{
	GVec tmp(c);
	tmp = GetRowVec(idx0);
	SetRowVec(idx0, GetRowVec(idx1));
	SetRowVec(idx1, tmp);
	return *this;
}
/*!
*	\brief idx0번째 열벡터와 idx1번째 열벡터를 교환한다.
*
*	\param idx0 열벡터의 인덱스
*	\param idx1 열벡터의 인덱스
*
*	\return 변환된 자신을 리턴한다.
*/
GMatrix &GMatrix::ExchangeCols(const int idx0, const int idx1)
{
	GVec tmp(r);
	tmp = GetColVec(idx0);
	SetColVec(idx0, GetColVec(idx1));
	SetColVec(idx1, tmp);
	return *this;
}

/*!
*	\brief 행의 수를 리턴한다.
*
*	\return 행의 수
*/
int GMatrix::GetRowNum() const
{
	return r;
}

/*!
*	\brief 열의 수를 리턴한다.
*
*	\return 열의 수
*/
int GMatrix::GetColNum() const
{
	return c;
}

/*!
*	\brief 행벡터를 반환한다.
*
*	\param idx 행벡터의 인덱스
*
*	\return idx 번째 행벡터를 반환한다.
*/
GVec GMatrix::GetRowVec(const int idx) const
{
	assert(idx < r);
	GVec ret(c);
	for (int i = 0; i < c; i++)
		ret.V[i] = M[idx * c + i];
	return ret;
}

/*!
*	\brief 열벡터를 반환한다.
*
*	\param idx 열벡터의 인덱스
*
*	\return idx 번째 열벡터를 반환한다.
*/
GVec GMatrix::GetColVec(const int idx) const
{
	assert(idx < c);
	GVec ret(r);
	for (int i = 0; i < r; i++)
		ret.V[i] = M[i * c + idx];
	return ret;
}

/*!
*	\brief 정방행렬 (square matrix)인지를 조사한다.
*
*	\return 정방행렬의 경우 true, 직사각행렬의 경우 false.
*/
bool GMatrix::IsSquare() const
{
	return (r == c) ? true : false;
}

/*!
*	\brief Set 등호 및 부등호연산자의 정확도를 설정한다.
*
*	\param error 오차의 한계
*/
void GMatrix::SetPrecision(double error)
{
	Precision = error;
}

/*!
*	\brief 설정된 오차의 한계를 반환한다.
*
*	\return 오차의 한계
*/
double GMatrix::GetPrecision()
{
	return Precision;
}

/*!
*	\brief 산술연산자 (*)
*
*	\param lhs 왼쪽 피연산자 (행렬)
*	\param rhs 오른쪽 피연산자 (벡터)
*
*	\return 계산의 결과를 반환
*/
GVec operator *(const GMatrix &lhs, const GVec &rhs)
{
	assert(lhs.c == rhs.N);
	GVec ret(lhs.r);
	for (int i = 0; i != lhs.r; ++i)		// for each row.
		for (int j = 0; j != lhs.c; ++j)	// for each col.
			ret.V[i] += lhs.M[i * lhs.c + j] * rhs.V[j];
	return ret;
}

/*!
*	\brief 산술연산자 (*)
*
*	\param lhs 왼쪽 피연산자 (벡터)
*	\param rhs 오른쪽 피연산자 (행렬)
*
*	\return 계산의 결과를 반환
*/
GMatrix operator *(const GVec &lhs, const GMatrix &rhs)
{
	assert(rhs.r == 1);
	GMatrix ret(lhs.N, rhs.c);
	for (int i = 0; i != lhs.N; ++i)		// for each row.
		for (int j = 0; j != rhs.c; ++j)	// for each col.
			ret.M[i * rhs.c + j] = lhs.V[i] * rhs.M[j];
	return ret;
}

/*!
*	\brief 산술연산자 (*)
*
*	\param lhs 왼쪽 피연산자 (행렬)
*	\param rhs 오른쪽 피연산자 (상수)
*
*	\return 계산의 결과를 반환
*/
GMatrix operator *(const GMatrix &lhs, const double &s)
{
	GMatrix ret(lhs);
	ret *= s;
	return ret;
}

/*!
*	\brief 산술연산자 (*)
*
*	\param lhs 왼쪽 피연산자 (상수)
*	\param rhs 오른쪽 피연산자 (행렬)
*
*	\return 계산의 결과를 반환
*/
GMatrix operator *(const double &s, const GMatrix &rhs)
{
	GMatrix ret(rhs);
	ret *= s;
	return ret;
}

/*!
*	\brief 출력연산자(<<)
*
*	\param os 출력스트림
*	\param m 출력할 객체
*
*	\return 출력된 스트림 객체를 반환
*/
std::ostream &operator <<(std::ostream &os, const GMatrix &m)
{
	for (int i = 0; i != m.r; i++)
	{
		os << "|";
		for (int j = 0; j != m.c; j++)
		{
			double val = m.M[i * m.c + j];
			if (EQ(val, 0.0, 1.0e-6))
				val = 0.0;

			os << std::setw(5) << val << " ";
		}
		os << "|" << std::endl;
	}
	return os;
}

/*!
*	\brief 전치행렬을 반환한다.
*
*	\param m 행렬
*
*	\return 행렬 \a m의 전치행렬
*/ GMatrix tr(const GMatrix &m)
{
	GMatrix ret(m);
	ret.SetTranspose();
	return ret;
}

/*!
*	\brief 행렬의 row-echelon 폼을 반환한다.
*
*	\param m 행렬
*
*	\return row-echelon 폼을 반환한다.
*/ GMatrix ref(const GMatrix &m)
{
	int i, j, k; // 반복제어 변수
	int r = m.GetRowNum();
	int c = m.GetColNum();
	int n = MIN(r, c);
	GMatrix T(m);

	int shift = 0;
	for (i = 0; i < n; i++)
	{
		// pivoting.
		double maxi = ABS(T[i][i + shift]);
		int pivot_idx = i;
		for (j = i + 1; j < r; j++)
		{
			if (maxi < ABS(T[j][i + shift]))
			{
				maxi = ABS(T[j][i + shift]);
				pivot_idx = j;
			}
		}

		if (EQ_ZERO(maxi, GMatrix::Precision))
		{
			shift++;
			i--;
			continue;
		}

		if (i != pivot_idx)
			T.ExchangeRows(i, pivot_idx);

		double s = T[i][i + shift];
		for (j = i + shift; j < c; j++)
			T[i][j] = T[i][j] / s;

		for (j = i + 1; j < r; j++)
		{
			s = T[j][i + shift];
			for (k = i + shift; k < c; k++)
			{
				T[j][k] = T[j][k] - s * T[i][k];
			}
		}
	}

	return T;
}

/*!
*	\brief 행렬의 reduced row-echelon 폼을 반환한다.
*
*	\param m 행렬
*
*	\return reduced row-echelon 폼을 반환한다.
*/ GMatrix rref(const GMatrix &m)
{
	int i, j, k; // 반복제어 변수
	int r = m.GetRowNum();
	int c = m.GetColNum();
	int n = MIN(r, c);
	GMatrix T(m);

	int shift = 0;
	for (i = 0; i < n; i++)
	{
		// pivoting.
		double maxi = ABS(T[i][i + shift]);
		int pivot_idx = i;
		for (j = i + 1; j < r; j++)
		{
			if (maxi < ABS(T[j][i + shift]))
			{
				maxi = ABS(T[j][i + shift]);
				pivot_idx = j;
			}
		}

		if (EQ_ZERO(maxi, GMatrix::Precision))
		{
			shift++;
			i--;
			continue;
		}

		if (i != pivot_idx)
			T.ExchangeRows(i, pivot_idx);

		double s = T[i][i + shift];
		for (j = i + shift; j < c; j++)
			T[i][j] = T[i][j] / s;

		for (j = 0; j < r; j++)
		{
			if (i == j)
				continue;

			s = T[j][i + shift];
			for (k = i + shift; k < c; k++)
			{
				T[j][k] = T[j][k] - s * T[i][k];
			}
		}
	}

	return T;
}

/*!
*	\brief 행렬 \a m의 Null 공간의 기저를 열 벡터로 갖는 행렬을 반환한다.
*
*	\param m 행렬
*
*	\return 행렬 \a m의 Null 공간의 기저를 열 벡터로 갖는 행렬을 반환한다.
*/
GMatrix basis_null(const GMatrix &m)
{
	// 행렬 m의 reduced row-echelon form을 구한다.
	GMatrix R = rref(m);

	// 행렬 R의 행의 수와 열의 수를 구한다.
	int r = R.GetRowNum();
	int c = R.GetColNum();

	// 행렬 R의 free 변수와 pivot 변수의 인데스를 구한다.
	std::vector<int> FreeIdx;
	std::vector<int> PivotIdx;
	int tmp = 0;
	for (int i = 0; i < c; ++i)
	{
		GVec x = R.GetColVec(i);
		if (EQ(x[tmp], 1.0, 1.0e-6))
		{
			tmp++;
			PivotIdx.push_back(i);
		}
		else
		{
			FreeIdx.push_back(i);
		}
	}

	// Free 열 벡터를 저장할 행렬 B를 정의한다.
	int NumFree = (int)FreeIdx.size();
	GMatrix B(r, NumFree);
	for (int i = 0; i < NumFree; ++i)
	{
		GVec x = R.GetColVec(FreeIdx[i]);
		B.SetColVec(i, -x);
	}

	// Null 공간의 기저를 저장할 행렬 N을 정의한다.
	GMatrix N(c, NumFree);
	GMatrix I(NumFree, NumFree);
	I.SetIdentity();
	for (int i = 0; i < NumFree; ++i)
	{
		GVec x = I.GetRowVec(i);
		N.SetRowVec(FreeIdx[i], x);
	}

	// Free 변수의 열 벡터의 음수 값으로 행렬 N의 Pivot 행을 채운다.
	int NumPivot = (int)PivotIdx.size();
	for (int i = 0; i < NumPivot; ++i)
	{
		GVec x = B.GetRowVec(i);
		N.SetRowVec(PivotIdx[i], x);
	}

	// 구해진 기저를 반환한다.
	return N;
}

/*!
*	\brief 행렬의 원소를 담은 실수배열을 반환
*
*	\param m 행렬
*
*	\return 행렬의 원소를 저장한 실수 배열
*/
double *cast_arr(const GMatrix &m)
{
	return m.M;
}

/*!
*	\brief 행렬의 rank (독립한 열벡터 혹은 행벡터의 수)를 계산
*
*	\param m 행렬
*
*	\return 구해진 행렬의 rank
*/
int rank(const GMatrix &m)
{
	int i, r, rank = 0;
	r = m.GetRowNum();

	GMatrix T = ref(m);
	for (i = 0; i < r; i++)
	{
		GVec rVec = T.GetRowVec(i);
		if (!EQ_ZERO(norm(rVec), rVec.GetPrecision()))
			rank++;
	}

	return rank;
}

/*!
*	\brief 행렬의 nullity 를 계산
*
*	\param m 행렬
*
*	\return 구해진 행렬의 nullity
*/
int nullity(const GMatrix &m)
{
	int rnk = rank(m);
	int c = m.GetColNum();
	return (c - rnk);
}

/*!
*	\brief	행렬 A를 하삼각행렬(lower triangle matrix) L과 상삼각행렬 (upper triangle matrix) U로 분해 \n
*			분해과정에서 부분피봇팅 및 행교환을 수행하지 않음
*
*	\param A 분해하고자 하는 정방행렬
*	\param L 분해후 하삼각행렬이 저장됨
*	\param U 분해후 상삼각행렬이 저장됨
*
*	\return 성공: true, 실패: false
*/
int dcmp_lu(const GMatrix &A, GMatrix &L, GMatrix &U)
{
	assert(A.r == A.c);
	assert(L.r == A.r);
	assert(L.c == A.c);
	assert(U.r == A.r);
	assert(U.c == A.c);
	int i, j, k, n;
	double big, dum, sum;
	n = A.r;

	GVec vv(n);  // vv stores the implicit scaling of each row
	GMatrix AA(A);
	L.SetIdentity();
	U.SetZeros();

	for (i = 0; i < n; i++)
	{
		big = 0.0;
		for (j = 0; j < n; j++)
			if (ABS(AA[i][j]) > big)
				big = ABS(AA[i][j]);
		if (big == 0.0)
		{
			printf("Singular matrix in dcmp_lu()...\n");
			return false;
		}
	}

	for (j = 0; j < n; j++)			// loop over columns of Crout's method
	{
		for (i = 0; i < j; i++)		// equation (2.3.12) except i=j
		{
			sum = AA[i][j];
			for (k = 0; k < i; k++)
				sum -= AA[i][k] * AA[k][j];
			AA[i][j] = sum;
		}
		for (i = j; i < n; i++) 	// i=j of equation (2.3.12) and i= j+1 .. N
		{							// of equation (2.3.13)
			sum = AA[i][j];
			for (k = 0; k < j; k++)
				sum -= AA[i][k] * AA[k][j];
			AA[i][j] = sum;
		}
		if (AA[j][j] == 0.0)
			AA[j][j] = 1.0e-15;
		/*
		if the pivot element is zero the matrix is singular (at least the
		precision of the algorithm). For some applications on singular
		matrices, it is desirable to substitute TINY for zero
		*/
		if (j != n - 1)				// now finally, divide by the pivot element
		{
			dum = 1.0 / AA[j][j];
			for (i = j + 1; i < n; i++)
				AA[i][j] *= dum;
		}
	}		// go back for the next column in the reduction

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j >= i)
				U[i][j] = AA[i][j];
			else
				L[i][j] = AA[i][j];
		}
	}
	return true;
}

/*!
*	\brief	행렬 A를 하삼각행렬(lower triangle matrix) L과 상삼각행렬 (upper triangle matrix) U로 변환\n
*			분해과정에서 부분피봇팅 (행교환)을 수행. 따라서, Idx = (0, 1, 2, ...)와 같지 않으면, L*U 는 A와 같지 않다.\n
*			분해 후, lin_sys_lu(A, x, b, Idx)를 호출하여 선형시스템 Ax = b 를 만족하는 벡터 x를 구함
*
*	\param A n행 n열의 행렬으로 함수호출 후, LU 형태로 변환
*	\param Idx 행 벡터의 교환정보가 저장
*	\param d 행 벡터의 교환정보가 짝수이면 1, 홀수이면 -1 이 저장
*
*	\return 성공: true, 실패: false
*/
int dcmp_lu(GMatrix &A, GVec &Idx, double &d)
{
	assert(A.r == A.c);
	assert(Idx.N == A.r);
	int i, imax, j, k, n;
	double big, dum, sum, temp;
	n = A.r;
	GVec vv(n);  // vv stores the implicit scaling of each row

	d = 1.0;
	for (i = 0; i < n; i++)
	{
		big = 0.0;
		for (j = 0; j < n; j++)
			if ((temp = ABS(A[i][j])) > big)
				big = temp;
		if (big == 0.0)
		{
			printf("Singular matrix in dcmp_lu()...\n");
			return false;
		}
		// No nonzero largest element
		vv[i] = 1.0 / big;		// save the scaling
	}

	for (j = 0; j < n; j++)			// loop over columns of Crout's method
	{
		for (i = 0; i < j; i++)		// equation (2.3.12) except i=j
		{
			sum = A[i][j];
			for (k = 0; k < i; k++)
				sum -= A[i][k] * A[k][j];
			A[i][j] = sum;
		}
		big = 0.0;					// initialize for the search for largest pivot element
		for (i = j; i < n; i++) 	// i=j of equation (2.3.12) and i= j+1 .. N
		{							// of equation (2.3.13)
			sum = A[i][j];
			for (k = 0; k < j; k++)
				sum -= A[i][k] * A[k][j];
			A[i][j] = sum;
			if ((dum = vv[i] * ABS(sum)) >= big)
			{
				// is the figure of merit for the pivot better than the best so far
				big = dum;
				imax = i;
			}
		}
		if (j != imax) 			// Do we need to interchange rows?
		{
			A.ExchangeRows(j, imax);
			d = -d;			// and change the parity of d
			vv[imax] = vv[j];	// also interchange the scale factor
		}

		Idx[j] = imax;
		if (A[j][j] == 0.0)
			A[j][j] = 1e-15;
		/*
		if the pivot element is zero the matrix is singular (at least the
		precision of the algorithm). For some applications on singular
		matrices , it is desirable to substitute TINY for zero
		*/
		if (j != n - 1)				// now finally, divide by the pivot element
		{
			dum = 1.0 / (A[j][j]);
			for (i = j + 1; i < n; i++)
				A[i][j] *= dum;
		}
	}		// go back for the next column in the reduction
	return true;
}

/*!
*	\brief	선형방정식 Ax = b 를 만족하는 x를 구한다.\n
*			- 행렬 A는 dcmp_lu(A, Idx, d)로 LU로 분해된 결과이다.\n
*			- 벡터 Idx는 dcmp_lu(A, Idx, d)로 행교환벡터 결과이다.\n
*
*	\param A LU로 분해된 행열
*	\param x 해가 저장될 벡터
*	\param b 상수 벡터
*	\param Idx 행 벡터의 교환정보를 저장한 벡터
*/
void lin_sys_lu(const GMatrix &A, GVec &x, const GVec &b, const GVec &Idx)
{
	assert(A.r == A.c);
	assert(A.r == x.N);
	assert(x.N == b.N);
	assert(Idx.N == x.N);
	x = b;

	int i, ii = -1, ip, j, n;
	double sum;
	n = A.r;

	for (i = 0; i < n; i++)			// when ii is set to a positive value, it
	{								// will become the index of the first non-
		ip = (int)Idx[i];			// vanishing element of b. We now do the
		sum = x[ip];				// forward substitution, equation (2.3.6).
		x[ip] = x[i];				// The only new wrinkle is to unscalable 
		if (ii >= 0)				// the permutation as we go
			for (j = ii; j < i; j++)
				sum -= A[i][j] * x[j];
		else if (sum)				// A nonzero element was encountered, so 
			ii = i;					// from now on we will have to do the sums
		x[i] = sum;					// in the loop above
	}

	for (i = n - 1; i >= 0; i--) // Now we do the back-substitution equation
	{							 // (2.3.7)
		sum = x[i];
		for (j = i + 1; j < n; j++)
			sum -= A[i][j] * x[j];
		x[i] = sum / A[i][i];		// Store a component of the solution std::vector X
	}
}

/*!
*	\brief	행렬 A를 Householder 행렬을 사용하여 Q * R로 분해
*
*	\param A m x n 행렬
*	\param Q m x m orthogonal 행렬
*	\param R m x n 상삼각행렬
*
*	\return 실패: -1, 성공: householder 행렬을 적용한 회수
*/
int dcmp_qr(const GMatrix &A, GMatrix &Q, GMatrix &R)
{
	if (Q.r != A.r || Q.c != A.r)
		return -1;
	if (R.r != A.r || R.c != A.c)
		return -1;

	int i, j, k;
	double alpha, beta;
	Q.SetIdentity();
	R = A;
	GVec u(A.r);			// Target column std::vector 	
	GMatrix H(A.r, A.r);	// HouseHolder Matrix.

	for (k = 0; k < A.c; k++) // for each column
	{
		alpha = 0.0;
		for (i = k; i < A.r; i++)
		{
			alpha = alpha + SQR(R[i][k]);
			u[i] = R[i][k];
		}
		alpha = SQRT(alpha);
		if (EQ_ZERO(alpha, GMatrix::Precision))
			break;
		beta = 1.0 / (alpha * alpha + SIGN1(alpha, u[k]) * u[k]);
		u[k] = u[k] + SIGN1(alpha, u[k]);

		H.SetIdentity();
		for (i = k; i < A.r; i++)
		{
			for (j = k; j < A.r; j++)
			{
				H[i][j] -= beta * u[i] * u[j]; // Construct HouseHolder Matrix. -> Beautiful Computation.
			}
		}

		Q = Q * H;
		R = H * R;
	}
	return k;
}

/*!
*	\brief	행렬 A를 singular value decomposition을 수행\n
*			- A = U * W * tr(V) 로 분해\n
*
*	\param A m x n 행렬 (m >= n)
*	\param U m x n 행렬로서 열벡터는 A의 열공간의 단위기저가 저장
*	\param S 특이값이 저장될 n 차원벡터. W는 S의 원소로 생성되는 대각선 행렬
*	\param V n x n 행렬로서 열벡터는 A의 행공간 및 널공간의 단위기저가 저장
*/
void dcmp_sv(const GMatrix &A, GMatrix &U, GVec &S, GMatrix &V)
{
	int flag, i, its, j, jj, k, l, nm;
	double c, f, h, s, x, y, z;
	double anorm = 0.0, g = 0.0, scale = 0.0;
	int m = A.r;
	int n = A.c;
	assert(m >= n);
	assert(m == U.r && n == U.c);
	GVec rv1(n);
	U = A;
	for (i = 0; i < n; i++)
	{
		l = i + 1;
		rv1[i] = scale * g;
		g = s = scale = 0.0;
		if (i < m)
		{
			for (k = i; k < m; k++)
				scale += fabs(U[k][i]);
			if (scale)
			{
				for (k = i; k < m; k++)
				{
					U[k][i] /= scale;
					s += U[k][i] * U[k][i];
				}
				f = U[i][i];
				g = -SIGN2(SQRT(s), f);
				h = f * g - s;
				U[i][i] = f - g;
				if (i != n - 1)
				{
					for (j = l; j < n; j++)
					{
						for (s = 0.0, k = i; k < m; k++)
							s += U[k][i] * U[k][j];
						f = s / h;
						for (k = i; k < m; k++)
							U[k][j] += f * U[k][i];
					}
				}
				for (k = i; k < m; k++)
					U[k][i] *= scale;
			}
		}
		S[i] = scale * g;
		g = s = scale = 0.0;
		if (i <= m - 1 && i != n - 1)
		{
			for (k = l; k < n; k++)
				scale += fabs(U[i][k]);
			if (scale)
			{
				for (k = l; k < n; k++)
				{
					U[i][k] /= scale;
					s += U[i][k] * U[i][k];
				}
				f = U[i][l];
				g = -SIGN2(SQRT(s), f);
				h = f * g - s;
				U[i][l] = f - g;
				for (k = l; k < n; k++)
					rv1[k] = U[i][k] / h;
				if (i != m - 1)
				{
					for (j = l; j < m; j++)
					{
						for (s = 0.0, k = l; k < n; k++)
							s += U[j][k] * U[i][k];
						for (k = l; k < n; k++)
							U[j][k] += s * rv1[k];
					}
				}
				for (k = l; k < n; k++)
					U[i][k] *= scale;
			}
		}
		s = fabs(S[i]) + fabs(rv1[i]);
		anorm = MAX(anorm, s);
	}
	for (i = n - 1; i >= 0; i--)
	{
		if (i < n - 1)
		{
			if (g)
			{
				for (j = l; j < n; j++)
					V[j][i] = (U[i][j] / U[i][l]) / g;
				for (j = l; j < n; j++)
				{
					for (s = 0.0, k = l; k < n; k++)
						s += U[i][k] * V[k][j];
					for (k = l; k < n; k++)
						V[k][j] += s * V[k][i];
				}
			}
			for (j = l; j < n; j++)
				V[i][j] = V[j][i] = 0.0;
		}
		V[i][i] = 1.0;
		g = rv1[i];
		l = i;
	}
	for (i = n - 1; i >= 0; i--)
	{
		l = i + 1;
		g = S[i];
		if (i < n - 1)
			for (j = l; j < n; j++)
				U[i][j] = 0.0;
		if (g)
		{
			g = 1.0 / g;
			if (i != n - 1)
			{
				for (j = l; j < n; j++)
				{
					for (s = 0.0, k = l; k < m; k++)
						s += U[k][i] * U[k][j];
					f = (s / U[i][i]) * g;
					for (k = i; k < m; k++)
						U[k][j] += f * U[k][i];
				}
			}
			for (j = i; j < m; j++)
				U[j][i] *= g;
		}
		else
		{
			for (j = i; j < m; j++)
				U[j][i] = 0.0;
		}
		++U[i][i];
	}
	for (k = n - 1; k >= 0; k--)
	{
		for (its = 1; its <= 30; its++)
		{
			flag = 1;
			for (l = k; l >= 0; l--)
			{
				nm = l - 1;
				if (fabs(rv1[l]) + anorm == anorm)
				{
					flag = 0;
					break;
				}
				if (fabs(S[nm]) + anorm == anorm)
					break;
			}
			if (flag)
			{
				c = 0.0;
				s = 1.0;
				for (i = l; i <= k; i++)
				{
					f = s * rv1[i];
					if (fabs(f) + anorm != anorm)
					{
						g = S[i];
						h = PYTHAG(f, g);
						S[i] = h;
						h = 1.0 / h;
						c = g * h;
						s = (-f * h);
						for (j = 0; j < m; j++)
						{
							y = U[j][nm];
							z = U[j][i];
							U[j][nm] = y * c + z * s;
							U[j][i] = z * c - y * s;
						}
					}
				}
			}
			z = S[k];
			if (l == k)
			{
				if (z < 0.0)
				{
					S[k] = -z;
					for (j = 0; j < n; j++)
						V[j][k] = (-V[j][k]);
				}
				break;
			}
			//if (its == 30)
			//	cerr << "No convergence in 30 SVDCMP iterations";
			x = S[l];
			nm = k - 1;
			y = S[nm];
			g = rv1[nm];
			h = rv1[k];
			f = ((y - z) * (y + z) + (g - h) * (g + h)) / (2.0 * h * y);
			g = PYTHAG(f, 1.0);
			f = ((x - z) * (x + z) + h * ((y / (f + SIGN2(g, f))) - h)) / x;
			c = s = 1.0;
			for (j = l; j <= nm; j++)
			{
				i = j + 1;
				g = rv1[i];
				y = S[i];
				h = s * g;
				g = c * g;
				z = PYTHAG(f, h);
				rv1[j] = z;
				c = f / z;
				s = h / z;
				f = x * c + g * s;
				g = g * c - x * s;
				h = y * s;
				y = y * c;
				for (jj = 0; jj < n; jj++)
				{
					x = V[jj][j];
					z = V[jj][i];
					V[jj][j] = x * c + z * s;
					V[jj][i] = z * c - x * s;
				}
				z = PYTHAG(f, h);
				S[j] = z;
				if (z)
				{
					z = 1.0 / z;
					c = f * z;
					s = h * z;
				}
				f = (c * g) + (s * y);
				x = (c * y) - (s * g);
				for (jj = 0; jj < m; jj++)
				{
					y = U[jj][j];
					z = U[jj][i];
					U[jj][j] = y * c + z * s;
					U[jj][i] = z * c - y * s;
				}
			}
			rv1[l] = 0.0;
			rv1[k] = f;
			S[k] = x;
		}
	}
}

/*!
*	\brief	선형방정식 Ax = b 를 만족하는 minimum length least square 해 x를 구함
*
*	\param A m x n 행렬 (m >= n)
*	\param x 해가 저장될 n 차원 벡터
*	\param b m 차원 상수벡터
*
*	\return condition number
*/
double lin_sys_sv(const GMatrix &A, GVec &x, const GVec &b)
{
	int i, j;
	int m = A.r;
	int n = A.c;
	double min, max, cnum;

	GMatrix U(m, n);
	GVec S(n);
	GMatrix V(n, n);
	dcmp_sv(A, U, S, V);
	min = max = S[0];

	for (i = 0; i < n; i++)
	{
		min = MIN(min, S[i]);
		max = MAX(max, S[i]);
		cnum = min / max;
	}

	GVec tmp(n);
	for (j = 0; j < n; j++)
	{
		double s = 0.0;
		if (!EQ_ZERO(S[j], GMatrix::Precision))
		{
			for (i = 0; i < m; i++)
				s += U[i][j] * b[i];
			s /= S[j];
		}
		tmp[j] = s;
	}
	for (j = 0; j < n; j++)
	{
		double s = 0.0;
		for (i = 0; i < n; i++)
			s += V[j][i] * tmp[i];
		x[j] = s;
	}
	return cnum;
}

/*!
*	\brief	선형방정식 Ax = b 를 만족하는 minimum length least square 해 x를 구한다.\n
*			- 이 함수를 호출하기 전에, dcmp_sv(A, U, S, V)를 호출하여 행렬 A의 분해된 결과를 사용한다.
*			- 한번 분해된 행렬 A는 상수벡터 b만 바꾸면서 해를 구하게 된다.
*
*	\param U m x n 행렬로 dcmp_sv(A, U, S, V)의 결과
*	\param S n 차원 벡터로 dcmp_sv(A, U, S, V)의 결과
*	\param V n x n 행렬로 dcmp_sv(A, U, S, V)의 결과
*	\param x 해가 저장될 n 차원 벡터
*	\param b m 차원 상수벡터
*
*	\return 조건수 (condition number)
*/
double lin_sys_sv(const GMatrix &U, const GVec &S, const GMatrix &V, GVec &x, const GVec &b)
{
	int i, j;
	int m = U.r;
	int n = U.c;
	double min, max, cnum;
	min = max = S[0];

	for (i = 0; i < n; i++)
	{
		min = MIN(min, S[i]);
		max = MAX(max, S[i]);
		cnum = min / max;
	}
	GVec tmp(n);
	for (j = 0; j < n; j++)
	{
		double s = 0.0;
		if (!EQ_ZERO(S[j], GMatrix::Precision))
		{
			for (i = 0; i < m; i++)
				s += U[i][j] * b[i];
			s /= S[j];
		}
		tmp[j] = s;
	}
	for (j = 0; j < n; j++)
	{
		double s = 0.0;
		for (i = 0; i < n; i++)
			s += V[j][i] * tmp[i];
		x[j] = s;
	}
	return cnum;
}

/*!
*	\brief	LU 분해를 통해, 행렬 A의 행렬식을 구한다.
*
*	\param A n x n 행렬.
*
*	\return 행렬식의 값.
*/
double det(const GMatrix &A)
{
	assert(A.IsSquare());
	int i, n = A.r;
	double d;
	GMatrix LU(A);
	GVec Idx(n);

	dcmp_lu(LU, Idx, d);

	for (i = 0; i < n; i++)
		d *= LU[i][i];

	return d;
}

/*!
*	\brief	LU 분해를 통해, 행렬 A의 역행렬을 구한다.
*
*	\param A n x n 행렬.
*
*	\return 행렬 A의 역행렬.
*/
GMatrix inv(const GMatrix &A)
{
	assert(A.IsSquare());
	int n = A.r;
	GMatrix ret(n, n);

	if (n == 3)	// 3 x 3 matrix
	{
		double det = (A[0][0] * A[1][1] * A[2][2] + A[1][0] * A[2][1] * A[0][2] + A[0][1] * A[1][2] * A[2][0])
			- (A[0][2] * A[1][1] * A[2][0] + A[0][1] * A[1][0] * A[2][2] + A[1][2] * A[2][1] * A[0][0]);

		ret[0][0] = (A[1][1] * A[2][2] - A[1][2] * A[2][1]) / det;
		ret[0][1] = -(A[0][1] * A[2][2] - A[0][2] * A[2][1]) / det;
		ret[0][2] = (A[0][1] * A[1][2] - A[0][2] * A[1][1]) / det;
		ret[1][0] = -(A[1][0] * A[2][2] - A[1][2] * A[2][0]) / det;
		ret[1][1] = (A[0][0] * A[2][2] - A[0][2] * A[2][0]) / det;
		ret[1][2] = -(A[0][0] * A[1][2] - A[0][2] * A[1][0]) / det;
		ret[2][0] = (A[1][0] * A[2][1] - A[1][1] * A[2][0]) / det;
		ret[2][1] = -(A[0][0] * A[2][1] - A[0][1] * A[2][0]) / det;
		ret[2][2] = (A[0][0] * A[1][1] - A[0][1] * A[1][0]) / det;
	}
	else		// general matrix (n x n, n = 4, 5, 6, ....)
	{
		double d;
		GVec Idx(n);
		GMatrix LU(A);

		// for fast inverse computation remove determinant check.
		d = det(LU);
		assert(!EQ_ZERO(d, GMatrix::Precision));

		dcmp_lu(LU, Idx, d);
		for (int j = 0; j < n; j++)
		{
			GVec x(n);
			GVec b(n);
			b[j] = 1.0;
			lin_sys_lu(LU, x, b, Idx);
			ret.SetColVec(j, x);
		}
	}

	return ret;
}

/*!
*	\brief	Conjugate gradient 방법을 사용하여 선형방정식 Ax = b 를 푼다.\n
*			- 행렬 A는 대칭행렬이어야 한다.
*			- sparse 선형시스템을 풀기위한 효과적인 방법이다.
*
*	\param A n x n 대칭행렬.
*	\param x n 차원 초기 해 벡터.
*	\param b n 차원 상수 벡터.
*	\param iter 반복회수, 만약 반복회수가 n이면 정확한 해를 구한다.
*
*	\return 실제 반복회수.
*/
int lin_sys_cg(const GMatrix &A, GVec &x, const GVec &b, int iter)
{
	int n = A.r;
	assert(A.IsSquare());
	assert(n == x.N);
	assert(n == b.N);
	if (iter < 0 || iter > n)
		iter = n;

	GVec tmp0(n);
	double alpha, beta, tmp1;
	GVec r(b);	// initial residual.
	GVec d(b);	// initial conjugate direction.

	// Conjugate Gradient Iteration
	// Such a simple algorithm... 
	// but great theorem....(Expanding Subspace Theorem)
	int i;
	for (i = 0; i < iter; ++i)
	{
		tmp0 = A * d;
		tmp1 = r * r;

		alpha = tmp1 / (d * tmp0);
		x = x + alpha * d;
		r = r - alpha * tmp0;
		beta = (r * r) / tmp1;
		d = r + beta * d;
	}

	return i;
}

/*!
*	\brief	QR 분해법을 이용하여 선형방정식 Ax = b의 least square 해를 찾는다.
*
*	\param A m x n 행렬.
*	\param x n 차원 해 벡터.
*	\param b n 차원 상수 벡터.
*
*	\return 1: 성공, 0: 실패.
*/
int lin_sys_qr(const GMatrix &A, GVec &x, const GVec &b)
{
	int m, n, i, j, scs;
	m = A.r;
	n = A.c;

	GMatrix Q(m, m);
	GMatrix R(m, n);
	GVec c(m);

	scs = dcmp_qr(A, Q, R);

	if (scs != A.c)
		return false;

	Q.SetTranspose();
	c = Q * b;

	for (i = n - 1; i >= 0; i--)
	{
		double sum = 0.0;
		for (j = i + 1; j < n; j++)
			sum += (R[i][j] * x[j]);
		x[i] = (c[i] - sum) / R[i][i];
	}
	return true;
}

#define ROTATE(a, i, j, k, l)\
{ \
	g = a[i][j]; \
	h = a[k][l]; \
	a[i][j] = g - s * (h + g * tau); \
	a[k][l] = h + s * (g - h * tau); \
}
/*!
*	\brief	상사변환 (similarity transformation)을 사용하여 실수대칭행렬의 모든 eigenvector와 eigenvalue를 구한다.
*
*	\param A n x n 대칭행렬.
*	\param D n개의 eigenvalue를 저장한 벡터.
*	\param V n개의 eigenvector (열벡터)를 저장한 행렬.
*
*	\return 상사변환의 회수.
*/
int eigen_sys(const GMatrix &A, GVec &D, GMatrix &V)
{
	int n = A.r;
	assert(A.c == n);
	assert(D.N == n);
	assert(V.r == n);
	assert(V.c == n);
	int j, iq, ip, i, nrot;
	double tresh, theta, tau, t, sm, s, h, g, c, *b, *z;

	b = new double[n];
	z = new double[n];

	GMatrix B(A);
	V.SetIdentity();

	for (ip = 0; ip < n; ip++)
	{
		b[ip] = D[ip] = B[ip][ip];
		z[ip] = 0.0;
	}

	nrot = 0;

	for (i = 1; i <= 50; i++)
	{
		sm = 0.0;
		for (ip = 0; ip < n - 1; ip++)
		{
			for (iq = ip + 1; iq < n; iq++)
				sm += ABS(B[ip][iq]);
		}
		if (sm == 0.0)
		{
			delete[] b;
			delete[] z;
			return nrot;
		}
		if (i < 4)
			tresh = 0.2 * sm / (n * n);
		else
			tresh = 0.0;
		for (ip = 0; ip < n - 1; ip++)
			for (iq = ip + 1; iq < n; iq++)
			{
				g = 100.0 * ABS(B[ip][iq]);
				if (i > 4 && ABS((D[ip]) + g) == ABS(D[ip]) && (ABS(D[iq]) + g) == ABS(D[iq]))
					B[ip][iq] = 0.0;
				else if (ABS(B[ip][iq]) > tresh)
				{
					h = D[iq] - D[ip];
					if ((ABS(h) + g) == ABS(h))
						t = (B[ip][iq]) / h;
					else
					{
						theta = 0.5 * h / B[ip][iq];
						t = 1.0 / (ABS(theta) + SQRT((1.0 + SQR(theta))));
						if (theta < 0.0)
							t = -t;
					}
					c = 1.0 / SQRT(1 + SQR(t));
					s = t * c;
					tau = s / (1.0 + c);
					h = t * B[ip][iq];
					z[ip] -= h;
					z[iq] += h;
					D[ip] -= h;
					D[iq] += h;
					B[ip][iq] = 0.0;
					for (j = 0; j < ip; j++)
						ROTATE(B, j, ip, j, iq)
						for (j = ip + 1; j < iq; j++)
							ROTATE(B, ip, j, j, iq)
							for (j = iq + 1; j < n; j++)
								ROTATE(B, ip, j, iq, j)
								for (j = 0; j < n; j++)
									ROTATE(V, j, ip, j, iq)
									++nrot;
				}
			}
		for (ip = 0; ip < n; ip++)
		{
			b[ip] += z[ip];
			D[ip] = b[ip];
			z[ip] = 0.0;
		}
	}
	return nrot;
}

/*!
*	\brief dcmp_sv 를 사용하여 주성분 (principle component)를 찾는다.
*	\note 함수호출 후, Data 값들은 평균이 원점에 위치하도록 이동된다.
*
*	\param Data m x n 데이터 행렬 (m: 데이터의 개수, n: 데이터의 차원)
*	\param PC 열벡터로 표현된 주성분.
*	\param SigVal 주성분벡터의 특이값을 저장한 n 차원 벡터.
*	\param Mean 평균벡터.
*/
void pca(GMatrix &Data, GMatrix &PC, GVec &SigVal, GVec &Mean)
{
	int i;
	int num = Data.r;
	int dim = Data.c;
	assert(PC.r == dim);
	assert(PC.c == dim);
	assert(SigVal.N == dim);

	// 1. Get mean std::vector
	GVec data(dim);
	for (i = 0; i < num; i++)
	{
		data = Data.GetRowVec(i);
		Mean += data;
	}
	Mean = Mean / (double)num;
	// for debug.
	// cerr << "mean std::vector:" << std::endl << Mean;

	// 2. Translate to mean std::vector.
	for (i = 0; i < num; i++)
	{
		data = Data.GetRowVec(i);
		data -= Mean;
		Data.SetRowVec(i, data);
	}
	Data /= SQRT((double)num);
	// for debug.
	//printf( "translate matrix:\n" );
	//Data.Print();

	// 3. Do singular Value Decomposition.
	GMatrix U(num, dim), V(dim, dim);
	GVec W(dim);
	dcmp_sv(Data, U, W, V);

	// 4. Sorting by its singular value size.
	for (i = 0; i < dim - 1; i++)
	{
		if (W[i] < W[i + 1])
		{
			// swap eigenvalue.
			SWAP(double, W[i], W[i + 1]);
			// swap eigenvector.
			V.ExchangeCols(i, i + 1);
			U.ExchangeCols(i, i + 1);
		}
	}

	PC = V;
	SigVal = W;
}

/*!
*	\brief 벡터의 원소를 담은 실수배열을 구한다.
*
*	\param v 벡터
*
*	\return 벡터의 원소를 저장한 실수 배열
*/
double *cast_arr(const GVec &v)
{
	return v.V;
}

/*!
*	\brief 일반적인 벡터표현을 3차원 벡터로 변환한다.
*
*	\param v 벡터
*
*	\return v의 3차원 벡터표현
*/
GVec3 cast_vec3(const GVec &v)
{
	return GVec3(v[0], v[1], v[2]);
}

/*!
*	\brief 일반적인 벡터표현을 3차원 포인트의 형태로 변환한다.
*
*	\param v 벡터
*
*	\return v의 3차원 포인트 표현
*/
GPos3 cast_pt3(const GVec &v)
{
	return GPos3(v[0], v[1], v[2]);
}

//////////////////////////////////////////////////////////////////

/*!
*	\brief 쿼터니온 q = w + xi + yj + zk 을 생성하는 생성자
*
*	\param w 실수부
*	\param x i의 허수부
*	\param y j의 허수부
*	\param z k의 허수부
*/
GQuater::GQuater(double w, double x, double y, double z)
{
	this->W = w;
	this->X = x;
	this->Y = y;
	this->Z = z;
}

/*!
*	\brief 복사생성자 (copy constructor)
*
*	\param cpy 복사될 쿼터니온 객체
*/
GQuater::GQuater(const GQuater &cpy)
{
	this->W = cpy.W;
	this->X = cpy.X;
	this->Y = cpy.Y;
	this->Z = cpy.Z;
}

/*!
*	\brief 생성자 (constructor)
*
*	\param q 생성될 쿼터니온의 원소를 저장한 배열
*	\param invOrder 원소의 저장순서.
*          true: W = q[1], X = q[2], Y = q[3], W = q[0].
*		   false: W = q[0], X = q[1], Y = q[2], W = q[3].
*/
GQuater::GQuater(const double *q, const bool invOrder)
{
	if (invOrder)
	{
		this->W = q[1];
		this->X = q[2];
		this->Y = q[3];
		this->Z = q[0];
	}
	else
	{
		this->W = q[0];
		this->X = q[1];
		this->Y = q[2];
		this->Z = q[3];
	}
}

/*!
*	\brief 회전축 axis를 중심으로 theta만큼 회전하는 단위쿼터니온을 생성한다.
*
*	\param axis 회전의 중심축.
*	\param theta 회전각도
*	\param radian true: theta는 래디안, false: theta는 degree.
*/
GQuater::GQuater(GVec3 axis, double theta, bool radian /* = false */)
{
	double rad, sn, cs;
	axis.Normalize();
	if (!radian)
		rad = theta * M_PI / 360.0;
	else
		rad = theta * 0.5;

	sn = sin(rad);
	cs = cos(rad);

	sn = (abs(sn) < Precision) ? 0.0 : sn;
	cs = (abs(cs) < Precision) ? 0.0 : cs;

	W = cs;
	X = sn * axis[0];
	Y = sn * axis[1];
	Z = sn * axis[2];
}

/*!
*	\brief 오일러각 (degree) 이용하여 쿼터니온을 생성한다.
*
*	\param theta1 첫번째축에 대한 회전각도 (degree).
*	\param theta2 두번째축에 대한 회전각도 (degree).
*	\param theta3 세번째축에 대한 회전각도 (degree).
*	\param eulerType 오일러축 (XYZ = RxRyRz, ZYX = RzRyRx, ...)
*/
GQuater::GQuater(double theta1, double theta2, double theta3, TypeEuler eulerType)
{
	double c1, c2, c3;
	double s1, s2, s3;
	theta1 = DEG2RAD(theta1);
	theta2 = DEG2RAD(theta2);
	theta3 = DEG2RAD(theta3);
	c1 = cos(theta1);
	c2 = cos(theta2);
	c3 = cos(theta3);
	s1 = sin(theta1);
	s2 = sin(theta2);
	s3 = sin(theta3);

	double m[16];
	switch (eulerType)
	{
	case EULER_XYZ:
		m[0] = c2 * c3;
		m[1] = -c2 * s3;
		m[2] = s2;
		m[3] = 0.0;

		m[4] = s1 * s2 * c3 + c1 * s3;
		m[5] = -s1 * s2 * s3 + c1 * c3;
		m[6] = -s1 * c2;
		m[7] = 0.0;

		m[8] = -c1 * s2 * c3 + s1 * s3;
		m[9] = c1 * s2 * s3 + s1 * c3;
		m[10] = c1 * c2;
		m[11] = 0.0;

		m[12] = 0.0;
		m[13] = 0.0;
		m[14] = 0.0;
		m[15] = 1.0;
		break;

	case EULER_ZYX:
		m[0] = c3 * c2;
		m[1] = -s3 * c1 + c3 * s2 * s1;
		m[2] = s3 * s1 + c3 * s2 * c1;
		m[3] = 0.0;

		m[4] = s3 * c2;
		m[5] = c3 * c1 + s3 * s2 * s1;
		m[6] = -c3 * s1 + s3 * s2 * c1;
		m[7] = 0.0;

		m[8] = -s2;
		m[9] = c2 * s1;
		m[10] = c2 * c1;
		m[11] = 0.0;

		m[12] = 0.0;
		m[13] = 0.0;
		m[14] = 0.0;
		m[15] = 1.0;
		break;
	}
	SetFromMatrix(m, false);
}

/*!
*	\brief 생성자
*
*	\param x_axis x축 벡터
*	\param y_axis y축 벡터
*/
GQuater::GQuater(GVec3 x_axis, GVec3 y_axis)
{
	SetFromFrameXY(x_axis, y_axis);
}

/*!
*	\brief 소멸자 (destructor)
*/
GQuater::~GQuater()
{
}

/*!
*	\brief 대입연산자
*
*	\param rhs 대입연산자의 오른쪽 피연산자
*
*	\return 대입된 자신을 반환
*/
GQuater &GQuater::operator =(const GQuater &rhs)
{
	W = rhs.W;
	X = rhs.X;
	Y = rhs.Y;
	Z = rhs.Z;
	return *this;
}

/*!
*	복합대입연산자
*
*	\param rhs 복합대입연산자의 오른편 피연산자.
*
*	\return 연산후 대입된 자신을 반환
*/
GQuater &GQuater::operator +=(const GQuater &rhs)
{
	W += rhs.W;
	X += rhs.X;
	Y += rhs.Y;
	Z += rhs.Z;
	return *this;
}

/*!
*	복합대입연산자
*
*	\param rhs 복합대입연산자의 오른편 피연산자.
*
*	\return 연산후 대입된 자신을 반환
*/
GQuater &GQuater::operator -=(const GQuater &rhs)
{
	W -= rhs.W;
	X -= rhs.X;
	Y -= rhs.Y;
	Z -= rhs.Z;
	return *this;
}

/*!
*	\brief 복합대입연산자
*	\warning 단위 쿼터니온의 경우라도, 곱셈을 연속적으로 적용하다 보면 비단위쿼터니온이 될 수 있음.
*
*	\param rhs 복합대입연산자의 오른쪽 피연산자.
*
*	\return 연산후 대입된 자신을 반환
*/
GQuater &GQuater::operator *=(const GQuater &rhs)
{
	double w = W, x = X, y = Y, z = Z;
	this->W = w * rhs.W - x * rhs.X - y * rhs.Y - z * rhs.Z;
	this->X = w * rhs.X + rhs.W * x + y * rhs.Z - z * rhs.Y;
	this->Y = w * rhs.Y + rhs.W * y + z * rhs.X - x * rhs.Z;
	this->Z = w * rhs.Z + rhs.W * z + x * rhs.Y - y * rhs.X;
	return *this;
}

/*!
*	\brief 복합대입연산자
*	\usage q1 /= q2;	// q2에서 q1로의 상대적인 회전을 구한다
*
*	\param rhs 복합대입연산자의 오른편에 피연산자.
*
*	\return 연산후 대입된 자신을 반환
*/
GQuater &GQuater::operator /=(const GQuater &rhs)
{
	(*this) = inv(rhs) * (*this);
	Normalize();
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param s 복합대입연산자의 오른편에 피연산자 (실수).
*
*	\return 연산후 대입된 자신을 반환
*/
GQuater &GQuater::operator *=(const double s)
{
	W *= s;
	X *= s;
	Y *= s;
	Z *= s;
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param s 복합대입연산자의 오른편에 피연산자 (실수).
*
*	\return 연산후 대입된 자신을 반환
*/
GQuater &GQuater::operator /=(const double s)
{
	W /= s;
	X /= s;
	Y /= s;
	Z /= s;
	return *this;
}

/*!
*	\brief 단항연산자
*/
GQuater GQuater::operator -() const
{
	return *this * -1;
}

/*!
*	\brief 단항연산자
*/
GQuater GQuater::operator +() const
{
	return *this;
}

/*!
*	\brief 산술연산자(+)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른편 피연산자
*
*	\return 연산의 결과를 반환
*/
GQuater operator +(const GQuater &lhs, const GQuater &rhs)
{
	GQuater ret(lhs);
	ret += rhs;
	return ret;
}

/*!
*	\brief 산술연산자(-)
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른편 피연산자
*
*	\return 연산의 결과를 반환
*/
GQuater operator -(const GQuater &lhs, const GQuater &rhs)
{
	GQuater ret(lhs);
	ret -= rhs;
	return ret;
}

/*!
*	\brief 이항연산자 (*) 중복
*	\warning 단위 쿼터니온의 경우라도, 곱셈을 연속적으로 적용하다 보면 비단위쿼터니온이 될 수 있음.
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른편 피연산자
*
*	\return 두 쿼터니온의 곱을 반환한다.
*/
GQuater operator *(const GQuater &lhs, const GQuater &rhs)
{
	GQuater ret(lhs);
	ret *= rhs;
	return ret;
}

/*!
*	\brief (/) 연산자 중복
*	\note q1 / q2;	// q2에서 q1로의 상대적인 회전을 구한다
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른편 피연산자
*
*	\return 연산의 결과를 반환
*/
GQuater operator /(const GQuater &lhs, const GQuater &rhs)
{
	GQuater ret(lhs);
	ret /= rhs;
	return ret;
}

/*!
*	\brief 이항연산자 (*) 중복
*
*	\param lhs 왼쪽 피연산자
*	\param s 오른편 피연산자 (실수)
*
*	\return 쿼터니온의 실수배 (1/s)를 반환한다.
*/
GQuater operator /(const GQuater &lhs, const double s)
{
	GQuater ret(lhs);
	ret /= s;
	return ret;
}

/*!
*	\brief 이항연산자 (*) 중복
*		    (*) 주의: 현재 쿼터니온은 단위쿼터니온 이어야 한다.
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른편 피연산자 (벡터)
*
*	\return 벡터 rhs를 쿼터니온으로 회전한 벡터를 계산하여 리턴한다.
*/
GVec3 operator *(const GQuater &lhs, const GVec3 &rhs)
{
	assert(lhs.IsUnitQuater());
	GVec3 ret;
	GQuater v(0.0, rhs[0], rhs[1], rhs[2]);
	GQuater rq = lhs * v * inv(lhs);
	ret.Set(rq.X, rq.Y, rq.Z);
	return ret;
}

/*!
*	\brief 이항연산자 (*) 중복
*		    (*) 주의: 현재 쿼터니온은 단위쿼터니온 이어야 한다.
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른편 피연산자 (점)
*
*	\return 점 rhs를 쿼터니온으로 회전한 점을 계산하여 리턴한다.
*/
GPos3 operator *(const GQuater &lhs, const GPos3 &rhs)
{
	assert(lhs.IsUnitQuater());
	GPos3 ret;
	GQuater v(0.0, rhs[0], rhs[1], rhs[2]);
	GQuater rq = lhs * v * inv(lhs);
	ret.Set(rq.X, rq.Y, rq.Z);
	return ret;
}

/*!
*	\brief 수치오차의 범위를 설정하는 정적멤버함수
*
*	\param error 수치오차의 범위
*/
void GQuater::SetPrecision(double error)
{
	Precision = error;
}

/*!
*	\brief 수치오차의 범위를 얻음
*
*	\return 설정된 수치오차의 범위
*/
double GQuater::GetPrecision()
{
	return Precision;
}

/*!
*	\brief 등호연산자 (==) 중복
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 등호의 오른편 피연산자
*
*	\return 두 쿼터니온이 오차범위에서 같으면 true, 다르면 false 반환
*/
bool operator ==(const GQuater &lhs, const GQuater &rhs)
{
	double error = GQuater::Precision;
	return (EQ(lhs.W, rhs.W, error) && EQ(lhs.X, rhs.X, error) && EQ(lhs.Y, rhs.Y, error) && EQ(lhs.Z, rhs.Z, error));
}

/*!
*	\brief 등호연산자 (!=) 중복
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 등호의 오른편 피연산자
*
*	\return 두 쿼터니온이 오차범위에서 다르면 true, 같으면 false 반환
*/
bool operator !=(const GQuater &lhs, const GQuater &rhs)
{
	double error = GQuater::Precision;
	return (!EQ(lhs.W, rhs.W, error) || !EQ(lhs.X, rhs.X, error) || !EQ(lhs.Y, rhs.Y, error) || !EQ(lhs.Z, rhs.Z, error));
}

/*!
*	\brief Set 멤버함수
*
*	\param w 쿼터니온의 실수부
*	\param x 쿼터니온의 i 허수부
*	\param y 쿼터니온의 j 허수부
*	\param z 쿼터니온의 k 허수부
*/
GQuater &GQuater::Set(const double w, const double x, const double y, const double z)
{
	this->W = w;
	this->X = x;
	this->Y = y;
	this->Z = z;
	return *this;
}

/*!
*	\brief Set 멤버함수
*
*	\param q 생성될 쿼터니온의 원소를 저장한 배열
*	\param invOrder 원소의 저장순서.
*          true: W = q[3], X = q[0], Y = q[1], W = q[2].
*		   false: W = q[0], X = q[1], Y = q[2], W = q[3].
*/
GQuater &GQuater::Set(double *q, bool invOrder)
{
	if (invOrder)
	{
		this->W = q[3];
		this->X = q[0];
		this->Y = q[1];
		this->Z = q[2];
	}
	else
	{
		this->W = q[0];
		this->X = q[1];
		this->Y = q[2];
		this->Z = q[3];
	}

	return *this;
}

/*!
*	\brief axis 축을 중심으로 theta 만큼 회전하는 쿼터니온을 생성한다.
*
*	\param theta 회전할 각도를 나타낸다.
*	\param axis 회전의 중심축을 나타낸다.
*	\param radian theta가 래디안이면 true, 각도이면 false.
*
*	\return 생성된 자신을 리턴한다.
*/
GQuater &GQuater::SetFromAngleAxis(const double theta, GVec3 axis, bool radian)
{
	double rad, sn, cs;
	axis.Normalize();
	if (!radian)
		rad = theta * M_PI / 360.0;
	else
		rad = theta / 2.0;

	sn = sin(rad);
	cs = cos(rad);

	sn = (abs(sn) < Precision) ? 0.0 : sn;
	cs = (abs(cs) < Precision) ? 0.0 : cs;

	W = cs;
	X = sn * axis[0];
	Y = sn * axis[1];
	Z = sn * axis[2];

	return *this;
}

/*!
*	\brief 아크볼위의 점 p를 점 q로 회전하는 쿼터니온을 생성한다.
*
*	\param p 아크볼위의 점.
*	\param q 아크볼위의 점.
*	\param arcType 아크볼의 타입.
*
*	\return 생성된 자신을 리턴한다.
*/
GQuater &GQuater::SetFromArcBall(GVec3 p, GVec3 q, TypeArcBall arcType)
{
	double ang, nm;
	GVec3 axis;

	p.Normalize();
	q.Normalize();

	double dot = p * q;
	if (EQ(dot, -1.0, Precision))	// p = -q 인경우
	{
		int idx = 0;
		if (p[idx] >= p[1])
			idx = 1;

		if (p[idx] >= p[2])
			idx = 2;

		switch (idx)
		{
		case 0:
			W = 0.0;
			X = 0.0;
			Y = p[2];
			Z = -p[1];
			break;
		case 1:
			W = 0.0;
			X = p[2];
			Y = 0.0;
			Z = -p[0];
			break;
		case 2:
			W = 0.0;
			X = p[1];
			Y = -p[0];
			Z = 0.0;
			break;
		}

		return *this;
	}

	axis = p ^ q;
	nm = norm(axis);

	if (EQ_ZERO(nm, Precision))	// p == q 인경우
	{
		SetIdentity();
		return *this;
	}

	switch (arcType)
	{
	case ARCBALL_X:
		if (axis[0] < 0.0)
			axis.Set(-1.0, 0.0, 0.0);
		else
			axis.Set(1.0, 0.0, 0.0);
		break;
	case ARCBALL_Y:
		if (axis[1] < 0.0)
			axis.Set(0.0, -1.0, 0.0);
		else
			axis.Set(0.0, 1.0, 0.0);
		break;
	case ARCBALL_Z:
		if (axis[2] < 0.0)
			axis.Set(0.0, 0.0, -1.0);
		else
			axis.Set(0.0, 0.0, 1.0);
		break;
	}

	ang = angle(p, q, false);
	SetFromAngleAxis(ang, axis);
	return *this;
}

/*!
*	\brief 오일러각 (degree) 이용하여 쿼터니온을 생성한다.
*
*	\param theta1 첫번째축에 대한 회전각도 (degree).
*	\param theta2 두번째축에 대한 회전각도 (degree).
*	\param theta3 세번째축에 대한 회전각도 (degree).
*	\param eulerType 오일러축 (XYZ, ZYX, ...)
*
*	\return 생성된 자신을 리턴한다.
*/
GQuater &GQuater::SetFromEulerAngle(double theta1, double theta2, double theta3, TypeEuler eulerType)
{
	double c1, c2, c3;
	double s1, s2, s3;
	theta1 = DEG2RAD(theta1);
	theta2 = DEG2RAD(theta2);
	theta3 = DEG2RAD(theta3);
	c1 = cos(theta1);
	c2 = cos(theta2);
	c3 = cos(theta3);
	s1 = sin(theta1);
	s2 = sin(theta2);
	s3 = sin(theta3);

	double m[16];
	switch (eulerType)
	{
	case EULER_XYZ:
		m[0] = c2 * c3;
		m[1] = -c2 * s3;
		m[2] = s2;
		m[3] = 0.0;

		m[4] = s1 * s2 * c3 + c1 * s3;
		m[5] = -s1 * s2 * s3 + c1 * c3;
		m[6] = -s1 * c2;
		m[7] = 0.0;

		m[8] = -c1 * s2 * c3 + s1 * s3;
		m[9] = c1 * s2 * s3 + s1 * c3;
		m[10] = c1 * c2;
		m[11] = 0.0;

		m[12] = 0.0;
		m[13] = 0.0;
		m[14] = 0.0;
		m[15] = 1.0;
		break;

	case EULER_ZYX:
		m[0] = c3 * c2;
		m[1] = -s3 * c1 + c3 * s2 * s1;
		m[2] = s3 * s1 + c3 * s2 * c1;
		m[3] = 0.0;

		m[4] = s3 * c2;
		m[5] = c3 * c1 + s3 * s2 * s1;
		m[6] = -c3 * s1 + s3 * s2 * c1;
		m[7] = 0.0;

		m[8] = -s2;
		m[9] = c2 * s1;
		m[10] = c2 * c1;
		m[11] = 0.0;

		m[12] = 0.0;
		m[13] = 0.0;
		m[14] = 0.0;
		m[15] = 1.0;
		break;
	}
	return SetFromMatrix(m, false);
}

/*!
*	\brief 두 축의 방향으로 회전하는 쿼터니온을 생성한다.
*
*	\param x_axis x 축을 나타낸다.
*	\param y_axis y 축을 나타낸다.
*
*	\return 생성된 자신을 리턴한다.
*/
GQuater &GQuater::SetFromFrameXY(const GVec3 &x_axis, const GVec3 &y_axis)
{
	GVec3 X(x_axis), Y(y_axis), Z;
	Z = X ^ Y;
	X.Normalize();
	Y.Normalize();
	Z.Normalize();

	double m[16];
	m[0] = X[0];
	m[4] = X[1];
	m[8] = X[2];
	m[12] = 0.0;

	m[1] = Y[0];
	m[5] = Y[1];
	m[9] = Y[2];
	m[13] = 0.0;

	m[2] = Z[0];
	m[6] = Z[1];
	m[10] = Z[2];
	m[14] = 0.0;

	m[3] = 0.0;
	m[7] = 0.0;
	m[11] = 0.0;
	m[15] = 1.0;

	return SetFromMatrix(m, false);
}

/*!
*	\brief 두 축의 방향으로 회전하는 쿼터니온을 생성한다.
*
*	\param y_axis y 축을 나타낸다.
*	\param z_axis z 축을 나타낸다.
*
*	\return 생성된 자신을 리턴한다.
*/
GQuater &GQuater::SetFromFrameYZ(const GVec3 &y_axis, const GVec3 &z_axis)
{
	GVec3 X, Y(y_axis), Z(z_axis);
	X = Y ^ Z;
	X.Normalize();
	Y.Normalize();
	Z.Normalize();

	double m[16];
	m[0] = X[0];
	m[4] = X[1];
	m[8] = X[2];
	m[12] = 0.0;

	m[1] = Y[0];
	m[5] = Y[1];
	m[9] = Y[2];
	m[13] = 0.0;

	m[2] = Z[0];
	m[6] = Z[1];
	m[10] = Z[2];
	m[14] = 0.0;

	m[3] = 0.0;
	m[7] = 0.0;
	m[11] = 0.0;
	m[15] = 1.0;

	return SetFromMatrix(m, false);
}

/*!
*	\brief 두 축의 방향으로 회전하는 쿼터니온을 생성한다.
*
*	\param z_axis z 축을 나타낸다.
*	\param x_axis x 축을 나타낸다.
*
*	\return 생성된 자신을 리턴한다.
*/
GQuater &GQuater::SetFromFrameZX(const GVec3 &z_axis, const GVec3 &x_axis)
{
	GVec3 X(x_axis), Y, Z(z_axis);
	Y = Z ^ X;
	X.Normalize();
	Y.Normalize();
	Z.Normalize();

	double m[16];
	m[0] = X[0];
	m[4] = X[1];
	m[8] = X[2];
	m[12] = 0.0;

	m[1] = Y[0];
	m[5] = Y[1];
	m[9] = Y[2];
	m[13] = 0.0;

	m[2] = Z[0];
	m[6] = Z[1];
	m[10] = Z[2];
	m[14] = 0.0;

	m[3] = 0.0;
	m[7] = 0.0;
	m[11] = 0.0;
	m[15] = 1.0;

	return SetFromMatrix(m, false);
}

/*!
*	\brief 회전행렬로부터 쿼터니온을 설정한다.
*
*	\param mat 변환행렬(4 X 4)
*	\parma isGL (true: OpenGL의 변환행렬)
*
*	\return 생성된 자신을 리턴한다.
*/
GQuater &GQuater::SetFromMatrix(double *mat, bool isGL)
{
	double q[4];
	double tr, s;
	int i, j, k;
	int nxt[3] = { 1, 2, 0 };

	if (isGL)
	{
		tr = mat[0] + mat[5] + mat[10];

		if (tr > 0.0)
		{
			s = SQRT(tr + 1.0);
			W = s * 0.5;
			s = 0.5 / s;
			X = (mat[6] - mat[9]) * s;
			Y = (mat[8] - mat[2]) * s;
			Z = (mat[1] - mat[4]) * s;
		}
		else
		{
			i = 0;
			if (mat[5] > mat[0])
				i = 1;
			if (mat[10] > mat[i * 4 + i])
				i = 2;
			j = nxt[i];
			k = nxt[j];
			s = SQRT((mat[i + 4 * i] - (mat[j + 4 * j] + mat[k + 4 * k])) + 1.0);
			q[i] = s * 0.5;
			s = 0.5 / s;
			W = (mat[k + 4 * j] - mat[j + 4 * k]) * s;
			q[j] = (mat[j + 4 * i] + mat[i + 4 * j]) * s;
			q[k] = (mat[k + 4 * i] + mat[i + 4 * k]) * s;
			X = q[0];
			Y = q[1];
			Z = q[2];
		}
	}
	else
	{
		tr = mat[0] + mat[5] + mat[10];

		if (tr > 0.0)
		{
			s = SQRT(tr + 1.0);
			W = s * 0.5;
			s = 0.5 / s;
			X = (mat[9] - mat[6]) * s;
			Y = (mat[2] - mat[8]) * s;
			Z = (mat[4] - mat[1]) * s;
		}
		else
		{
			i = 0;
			if (mat[5] > mat[0])
				i = 1;
			if (mat[10] > mat[i * 4 + i])
				i = 2;
			j = nxt[i];
			k = nxt[j];
			s = SQRT((mat[i * 4 + i] - (mat[j * 4 + j] + mat[k * 4 + k])) + 1.0);
			q[i] = s * 0.5;
			s = 0.5 / s;
			W = (mat[k * 4 + j] - mat[j * 4 + k]) * s;
			q[j] = (mat[j * 4 + i] + mat[i * 4 + j]) * s;
			q[k] = (mat[k * 4 + i] + mat[i * 4 + k]) * s;
			X = q[0];
			Y = q[1];
			Z = q[2];
		}
	}

	Normalize();
	return *this;
}

/*!
*	\brief 쿼터니온을 항등원으로 변환한다.
*
*	\return 항등원으로 변환된 자신을 리턴한다.
*/
GQuater &GQuater::SetIdentity()
{
	this->W = 1.0;
	this->X = 0.0;
	this->Y = 0.0;
	this->Z = 0.0;
	return *this;
}

/*!
*	\brief 쿼터니온을 역원으로 변환한다.
*
*	\return 역원으로 변환된 자신을 리턴한다.
*/
GQuater &GQuater::SetInverse()
{
	if (!IsUnitQuater())
	{
		double norm_sqr = SQR(W) + SQR(X) + SQR(Y) + SQR(Z);
		*this /= norm_sqr;
	}
	SetConjugate();
	return *this;
}

/*!
*	\brief 쿼터니온을 conjugate 한다.
*
*	\return conjugate한 자신을 리턴한다.
*/
GQuater &GQuater::SetConjugate()
{
	this->X *= -1.0;
	this->Y *= -1.0;
	this->Z *= -1.0;
	return *this;
}

/*!
*	\brief 쿼터니온을 negate 한다.
*
*	\return negate한 자신을 리턴한다.
*/
GQuater &GQuater::SetNegate()
{
	this->W *= -1.0;
	this->X *= -1.0;
	this->Y *= -1.0;
	this->Z *= -1.0;
	return *this;
}

/*!
*	\brief 쿼터니온을 단위쿼터니온으로 변환한다.
*
*	\return 단위쿼터니온으로 변환된 자신을 리턴한다.
*/
GQuater &GQuater::Normalize()
{
	double len = norm(*this);
	this->W /= len;
	this->X /= len;
	this->Y /= len;
	this->Z /= len;
	return *this;
}

/*!
*	\brief 쿼터니온으로 표현되는 회전의 단위회전축과 각도를 구한다.
*
*	\param axis 회전축이 저장된다.
*	\param angle 각도가 저장된다.
*	\param radian \a angle에 저장된 각도가 래디안이면 true, 아니면 false.
*/
void GQuater::GetAngleAxis(GVec3 &axis, double &angle, bool radian) const
{
	if (IsIdentity() || !IsUnitQuater())
	{
		angle = 0.0;
		axis.Set(1.0, 0.0, 0.0);
		return;
	}

	double cs, sn;
	cs = W;
	sn = SQRT(SQR(X) + SQR(Y) + SQR(Z));
	angle = atan2(sn, cs);
	axis.Set(X / sn, Y / sn, Z / sn);
	if (radian)
		angle = angle * 2.0;
	else
		angle = angle * 360.0 / M_PI;
}

/*!
*	\brief 쿼터니온으로 표현되는 회전의 오일러 표현을 구한다.
*
*	\param theta1 첫번째 각도
*	\param theta2 두번째 각도
*	\param theta3 세번째 각도
*	\param radian true: 라디안, false: 각도
*	\param eulerType EULER_XYZ or EULER_ZYX
*/
void GQuater::GetEulerAngle(double &theta1, double &theta2, double &theta3, bool radian, TypeEuler eulerType)
{
	GMatrix mat = cast_mat(*this, false);
	switch (eulerType)
	{
	case EULER_XYZ:
		theta1 = atan2(-mat[1][2], mat[2][2]);
		theta2 = asin(mat[0][2]);
		theta3 = atan2(-mat[0][1], mat[0][0]);
		break;
	case EULER_ZYX:
		theta1 = atan2(mat[2][1], mat[2][2]);
		theta2 = asin(-mat[2][0]);
		theta3 = atan2(mat[1][0], mat[0][0]);
		break;
	}
	if (!radian)
	{
		theta1 = RAD2DEG(theta1);
		theta2 = RAD2DEG(theta2);
		theta3 = RAD2DEG(theta3);
	}
}

/*!
*	\brief 쿼터니온의 W 성분을 반환한다.
*
*	\return  쿼터니온의 W 성분
*/
double GQuater::GetW() const
{
	return W;
}

/*!
*	\brief 쿼터니온의 X 성분을 반환한다.
*
*	\return  쿼터니온의 X 성분
*/
double GQuater::GetX() const
{
	return X;
}

/*!
*	\brief 쿼터니온의 Y 성분을 반환한다.
*
*	\return  쿼터니온의 Y 성분
*/
double GQuater::GetY() const
{
	return Y;
}

/*!
*	\brief 쿼터니온의 Z 성분을 반환한다.
*
*	\return  쿼터니온의 Z 성분
*/
double GQuater::GetZ() const
{
	return Z;
}

/*!
*	\brief 단위쿼터니온 여부를 판정한다.
*
*	\return true: 단위쿼터니온, false: 단위쿼터니온이 아닌경우
*/
bool GQuater::IsUnitQuater() const
{
	double norm = SQR(W) + SQR(X) + SQR(Y) + SQR(Z);
	return EQ(norm, 1.0, Precision) ? true : false;
}

/*!
*	\brief 현재 쿼터니온이 항등원인지 여부를 판정한다.
*
*	\return true: 항등원인 경우, false: 항등원이 아닌경우
*/
bool GQuater::IsIdentity() const
{
	return (EQ(W, 1.0, 1.0e-5) && EQ(X, 0.0, 1.0e-5) &&
		EQ(Y, 0.0, 1.0e-5) && EQ(Z, 0.0, 1.0e-5));
}

/*!
*	\brief 연산자 (*) 중복
*
*	\param lhs 왼쪽 피연산자
*	\param s 오른쪽 피연산자 (실수)
*
*	\return \a s배 곱해진 쿼터니온을 리턴한다.
*/
GQuater operator *(const GQuater &lhs, const double &s)
{
	GQuater ret(lhs);
	ret *= s;
	return ret;
}

/*!
*	\brief 연산자 (*) 중복
*
*	\param s 왼쪽 피연산자 (실수)
*	\param rhs 오른쪽 피연산자 (쿼터니온)
*
*	\return \a s 배 곱해진 쿼터니온
*/
GQuater operator *(const double &s, const GQuater &rhs)
{
	GQuater ret(rhs);
	ret *= s;
	return ret;
}

/*!
*	\brief 쿼터니온의 크기를 구한다.
*
*	\param q 크기를 구할 쿼터니온
*
*	\return 쿼터니온 \a q의 크기
*/
double norm(const GQuater &q)
{
	return SQRT(SQR(q.W) + SQR(q.X) + SQR(q.Y) + SQR(q.Z));
}

/*!
*	\brief 쿼터니온의 역원을 구하는 함수.
*
*	\param q 역원을 구할 쿼터니온.
*
*	\return 쿼터니온 \a q의 역원.
*/
GQuater inv(const GQuater &q)
{
	GQuater ret(q);
	if (!ret.IsUnitQuater())
	{
		double norm_sqr = SQR(ret.W) + SQR(ret.X) + SQR(ret.Y) + SQR(ret.Z);
		ret /= norm_sqr;
	}
	ret.SetConjugate();
	return ret;
}

/*!
*	\brief 주어진 벡터 (pure imaginary 쿼터니온)의 exponential mapping을 구한다.
*
*	\param v pure imaginary 쿼터니온 q = (0, v).
*
*	\return 단위회전축 v/||v|| 를 중심으로 2 * ||v|| 의 회전각을 갖는 쿼터니온.
*/
GQuater exp(const GVec3 &v)
{
	double nm, s;
	GQuater rq;

	nm = norm(v);
	if (EQ(nm, 0.0, GQuater::Precision))
	{
		rq.SetIdentity();
		return rq;
	}

	rq.W = cos(nm);
	s = sin(nm) / nm;
	rq.X = s * v[0];
	rq.Y = s * v[1];
	rq.Z = s * v[2];

	return rq;
}

/*!
*	\brief 쿼터니온 q의 로그함수값을 구한다.
*
*	\param q 쿼터니온
*
*	\return 순허수 쿼터니온의 허수부분 Log(q) = (0, x, y, z).
*/
GVec3 log(const GQuater &q)
{
	GVec3 rv;
	if (q.IsIdentity())
	{
		rv.Set(0.0, 0.0, 0.0);
		return rv;
	}
	double theta, s;
	theta = acos(q.W);
	s = theta / sin(theta);
	rv.Set(s * q.X, s * q.Y, s * q.Z);
	return rv;
}

/*!
*	\brief 쿼터니온 q1, q2을 내적 한다.
*
*	\param q1 쿼터니온
*	\param q2 쿼터니온
*
*	\return 내적한 값
*/
double quat_dot(const GQuater &q1, const GQuater &q2)
{
	return q1.W * q2.W + q1.X * q2.X + q1.Y * q2.Y + q1.Z * q2.Z;
}

/*!
*	\brief 쿼터니온 q1, q2를 Spherical linear interpolation 한다.
*
*	\param q1 쿼터니온
*	\param q2 쿼터니온
*	\param t 보간될 시간
*
*	\return 보간된 쿼터니온
*/
GQuater slerp(GQuater q1, GQuater q2, double t)
{
	if (quat_dot(q1, q2) < 0.0)
		q2.SetNegate();

	GQuater q;
	double c = q1.W * q2.W + q1.X * q2.X + q1.Y * q2.Y + q1.Z * q2.Z;

	if (1.0 + c > 1.0e-5)
	{
		if (1.0 - c > 1.0e-5)
		{
			double theta = acos(c);
			q = (q1 * sin((1.0 - t) * theta) + q2 * sin(t * theta)) / sin(theta);
		}
		else
			q = q1 * (1.0 - t) + q2 * t;
	}
	else
		q = q1 * sin((0.5 - t) * M_PI) + q2 * sin(t * M_PI);

	q.Normalize();
	return q;
}

/*!
*	\brief 쿼터니온으로 표현되는 회전을 4행 4열의 동차좌표변환행렬로 변환한다.
*
*	\param q 대상쿼터니온
*	\param isGL 만약 true 이면 행렬에 OpenGL 형태로 저장한다.
*
*	\return 회전을 표현하는 행렬
*/
GMatrix cast_mat(const GQuater &q, bool isGL)
{
	GMatrix ret(4, 4);

	double s = 2.0 / (q.W * q.W + q.X * q.X + q.Y * q.Y + q.Z * q.Z);
	double xs = q.X * s, ys = q.Y * s, zs = q.Z * s;
	double wx = q.W * xs, wy = q.W * ys, wz = q.W * zs;
	double xx = q.X * xs, xy = q.X * ys, xz = q.X * zs;
	double yy = q.Y * ys, yz = q.Y * zs, zz = q.Z * zs;

	ret[0][0] = 1.0 - (yy + zz);
	ret[1][0] = xy + wz;
	ret[2][0] = xz - wy;

	ret[0][1] = xy - wz;
	ret[1][1] = 1.0 - (xx + zz);
	ret[2][1] = yz + wx;

	ret[0][2] = xz + wy;
	ret[1][2] = yz - wx;
	ret[2][2] = 1.0 - (xx + yy);

	ret[0][3] = ret[1][3] = ret[2][3] = 0.0;
	ret[3][0] = ret[3][1] = ret[3][2] = 0.0;
	ret[3][3] = 1.0;

	if (isGL)
		ret.SetTranspose();

	return ret;
}

/*!
*	\brief 쿼터니온을 4차원 벡터로 변환한다.
*
*	\param q 쿼터니온
*
*	\return 4차원 벡터
*/
GVec cast_vec(const GQuater &q)
{
	return GVec(4, q.W, q.X, q.Y, q.Z);
}

/*!
*	\brief 쿼터니온을 4차원 벡터로 변환한다.
*
*	\param q 쿼터니온
*
*	\return 4차원 벡터
*/
GVec4 cast_vec4(const GQuater &q)
{
	return GVec4(q.W, q.X, q.Y, q.Z);
}

/*!
*	\brief 4차원 벡터를 쿼터니온으로 변환한다.
*
*	\param v 4차원 벡터
*
*	\return 변환된 쿼터니온 (w, x, y, z) = (v[0], v[1], v[2], v[3])을 반환한다.
*/
GQuater cast_qt(const GVec4 &v)
{
	return GQuater(v[0], v[1], v[2], v[3]);
}

/*!
*	\brief 출력연산자 중복
*
*	\param os 출력스트림
*	\param q 출력할 쿼터니온
*
*	\return 출력된 스트림
*/
std::ostream &operator <<(std::ostream &os, const GQuater &q)
{
	os << "(" << q.W << ") + " << "(" << q.X << ")i + " << "(" << q.Y << ")j + " << "(" << q.Z << ")k" << std::endl;
	return os;
}

/*!
*	\brief 입력연산자 중복
*
*	\param is 입력스트림
*	\param q 입력받을 쿼터니온
*
*	\return 입력된 스트림
*/
std::istream &operator >>(std::istream &is, GQuater &q)
{
	is >> q.W >> q.X >> q.Y >> q.Z;
	return is;
}

/*!
*	\brief 4차원 벡터를 쿼터니온의 형태로 변환한다.
*
*	\param v 4차원 벡터
*
*	\return 변환된 쿼터니온표현
*/
GQuater cast_quat(const GVec &v)
{
	return GQuater(v[0], v[1], v[2], v[3]);
}

///////////////////////////////////////////////////////////
/*!
*	\brief 직선위의 한 점과 방향으로 직선을 생성하는 생성자.
*
*	\param _p 직선위의 한 점
*	\param _v 직선의 방향 벡터.
*/
GLine::GLine(const GPos3 &_p, const GVec3 &_v)
	: p(_p), v(_v)
{
}

/*!
*	\brief 3차원 공간상의 두 점을 지나는 직선을 생성하는 생성자.
*
*	\param _p 직선위의 점, l(0) = p.
*	\param _q 직선위의 점, l(1) = q.
*/
GLine::GLine(const GPos3 &_p, const GPos3 &_q)
{
	p = _p;
	v = _q - _p;
}

/*!
*	\brief 복사생성자.
*
*	\param copy 복사될 직선의 객체.
*/
GLine::GLine(const GLine &copy)
	: p(copy.p), v(copy.v)
{
}

/*!
*	\brief 소멸자.
*/
GLine::~GLine()
{
}

/*!
*	\brief	대입연산자 중복
*
*	\param rhs 오른쪽 피연산자.
*
*	\return 대입된 자신을 반환한다.
*/
GLine &GLine::operator =(const GLine &rhs)
{
	this->p = rhs.p;
	this->v = rhs.v;
	return *this;
}

/*!
*	\brief	함수호출연산자 중복
*			- 직선위의 매개변수 t에서의 점 l(t)를 구한다.
*
*	\param t 매개변수.
*
*	\return 직선위의 점 l(t)를 반환한다.
*/
GPos3 GLine::Eval(const double t) const
{
	return p + t * v;
}

/*!
*	\brief	등호입연산자 중복.
*
*	\param rhs 오른쪽 피연산자.
*
*	\return true: 같으면, false: 다르면.
*/
bool operator ==(const GLine &lhs, const GLine &rhs)
{
	if (lhs.IsOnLine(rhs.p) && EQ_ZERO(norm(lhs.v ^ rhs.v), GLine::Precision))
		return true;
	else
		return false;
}

/*!
*	\brief	부등호입연산자 중복.
*
*	\param rhs 오른쪽 피연산자.
*
*	\return true: 다르면, false: 같으면.
*/
bool operator !=(const GLine &lhs, const GLine &rhs)
{
	return !(lhs == rhs);
}

/*!
*	\brief 점 q가 직선위의 점인지 조사한다.
*
*	\param q 조사할 점.
*
*	\return true: q가 직선위의 점 일경우, false: 아닐경우.
*/
bool GLine::IsOnLine(const GPos3 &q) const
{
	GVec3 w = q - p;
	double s = norm(v ^ w);
	if (EQ_ZERO(s, Precision))
		return true;
	else
		return false;
}

/*!
*	\brief 출력연산자 중복.
*
*	\param os 출력스트림
*	\param l 출력할 라인객체
*
*	\return 출력된 스트림
*/
std::ostream &operator <<(std::ostream &os, const GLine &l)
{
	os << "("
		<< l.p[0] << " + (" << l.v[0] << ") * t, "
		<< l.p[1] << " + (" << l.v[1] << ") * t, "
		<< l.p[2] << " + (" << l.v[2] << ") * t)";
	return os;
}

/*!
*	\brief 한 점에서 직선까지의 거리를 구한다.
*
*	\param l 직선
*	\param q 한 점
*
*	\return 점 \a q에서 직선 \a l까지의 수직거리
*/
double dist(const GLine &l, const GPos3 &q)
{
	return norm(proj(q - l.p, l.v) - (q - l.p));
}

/*!
*	\brief 두 직선 l1(t)와 l2(t)사이의 최단 거리를 구한다.
*
*	\param l1 첫 번째 직선
*	\param l2 두 번째 직선
*	\param t1 최단 거리가 생기는 l1의 파리미터 값이 저장됨
*	\param t2 최단 거리가 생기는 l2의 파리미터 값이 저장됨
*
*	\return 두 직선 사이의 최단거리를 계산하여 반환한다 (두 직선이 만나는 경우 -1.0을 반환한다).
*/
double dist(const GLine &l1, const GLine &l2, double &t1, double &t2)
{
	GPos3 p1 = l1.p;
	GPos3 p2 = l2.p;
	GVec3 v1 = l1.v;
	GVec3 v2 = l2.v;

	double a11 = v1 * v1;
	double a12 = -v2 * v1;
	double a21 = v1 * v2;
	double a22 = -v2 * v2;
	double b1 = (p1 - p2) * v1;
	double b2 = (p1 - p2) * v2;
	double D = a11 * a22 - a12 * a21;

	double ret = 0.0;
	if (EQ_ZERO(D, 0.00001))
	{
		t1 = 0.0;
		t2 = 0.0;
		ret = -1.0;
	}
	else
	{
		t1 = (a22 * b1 - a12 * b2) / D;
		t2 = (-a21 * b1 + a11 * b2) / D;

		GPos3 q1 = l1.Eval(t1);
		GPos3 q2 = l2.Eval(t2);

		ret = dist(q1, q2);
	}

	return ret;
}

/*!
*	\brief 새로운 점을 지나도록 직선의 방정식을 변경한다 (방향은 변경없음).
*
*	\param _p 새로운 점
*
*	\return 변경된 자신을 반환한다.
*/
GLine &GLine::SetPt(const GPos3 &_p)
{
	p = _p;
	return *this;
}

/*!
*	\brief 직선의 방향을 변경한다.
*
*	\param _v 새로운 방향.
*
*	\return 변경된 자신을 반환한다.
*/
GLine &GLine::SetDir(const GVec3 &_v)
{
	v = _v;
	return *this;
}

/*!
*	\brief 직선의 시작점을 리턴한다.
*
*	\return 직선의 시작점.
*/
GPos3 GLine::GetPt() const
{
	return p;
}

/*!
*	\brief 직선의 방향을 리턴한다.
*
*	\return 직선의 방향.
*/
GVec3 GLine::GetDir() const
{
	return v;
}

/*!
*	\brief 수치오류의 한계치를 설정한다.
*/
void GLine::SetPrecision(double err)
{
	Precision = err;
}

/*!
*	\brief 수치오류의 한계치를 리턴한다.
*
*	\return 한계치.
*/
double GLine::GetPrecision()
{
	return Precision;
}

///////////////////////////////////////////////////////////

/*!
*	\brief 평면의 생성자.
*
*	\param _n 생성되는 평면의 법선벡터
*	\param _p 생성되는 평면위의 임의의 한점
*/
GPlane::GPlane(const GVec3 &_n, const GPos3 &_p)
{
	n = _n;
	d = -(n[0] * _p[0] + n[1] * _p[1] + n[2] * _p[2]);
}

/*!
*	\brief 세 점 p1, p2, p3 를 지나는 평면의 생성자
*
*	\param p1 평면상의 점.
*	\param p2 평면상의 점.
*	\param p3 평면상의 점.
*/
GPlane::GPlane(const GPos3 &p1, const GPos3 &p2, const GPos3 &p3)
{
	n = (p2 - p1) ^ (p3 - p1);
	d = -(n[0] * p1[0] + n[1] * p1[1] + n[2] * p1[2]);
}

/*!
*	\brief 평면의 복사생성자
*
*	\param copy 복사될 평면의 객체에 대한 레퍼런스
*/
GPlane::GPlane(const GPlane &cpy)
	: n(cpy.n), d(cpy.d)
{
}

/*!
*	\brief 평면의 생성자.
*
*	\param _n 법선벡터.
*	\param _d 상수 d = - n * p (p: 평면위의 임의의 점).
*/
GPlane::GPlane(const GVec3 &_n, const double &_d)
	: n(_n), d(_d)
{
}

/*!
*	\brief 평면의 생성자.
*
*	\param a, b, c, d 평면 방정식 ax + by + cz +d = 0 의 계수
*/
GPlane::GPlane(const double &a, const double &b, const double &c, const double &d)
{
	this->n = GVec3(a, b, c);
	this->d = d;
}

/*!
*	\brief 평면의 소멸자.
*/
GPlane::~GPlane()
{
}

/*!
*	\brief 대입연산자 중복
*
*	\param rhs 오른쪽 피연산자
*
*	\return 대입된 자신을 반환한다.
*/
GPlane &GPlane::operator =(const GPlane &rhs)
{
	this->n = rhs.n;
	this->d = rhs.d;
	return *this;
}

/*!
*	\brief 등호입연산자 중복.
*
*	\param lhs 왼쪽 피연산자.
*	\param rhs 오른쪽 피연산자.
*
*	\return true: 같으면, false: 다르면.
*/
bool operator ==(const GPlane &lhs, const GPlane &rhs)
{
	GVec pi1(4), pi2(4);
	pi1.Set(lhs.n[0], lhs.n[1], lhs.n[2], lhs.d);
	pi2.Set(rhs.n[0], rhs.n[1], rhs.n[2], rhs.d);
	double s1 = norm(pi1) * norm(pi2);
	double s2 = pi1 * pi2;

	if (EQ(s1, s2, GPlane::Precision))
		return true;
	else
		return false;
}

/*!
*	\brief 부등호입연산자 중복
*
*	\param lhs 왼쪽 피연산자
*	\param rhs 오른쪽 피연산자
*
*	\return true: 다르면, false: 같으면.
*/
bool operator !=(const GPlane &lhs, const GPlane &rhs)
{
	return !(lhs == rhs);
}

/*!
*	\brief 법선벡터를 반환한다.
*
*	\return 법선벡터.
*/
GVec3 GPlane::GetNormal() const
{
	return n;
}

/*!
*	\brief 점 p가 평면상의 점 인지를 조사.
*
*	\param p 조사할 점
*
*	\return true: 점 p가 평면상의 점 일경우, false: 그렇지 않을경우.
*/
bool GPlane::IsOnPlane(const GPos3 &p) const
{
	double s;
	s = -(n[0] * p[0] + n[1] * p[1] + n[2] * p[2]);
	if (EQ(s, d, GPlane::Precision))
		return true;
	else
		return false;
}

/*!
*	\brief 점 p가 평면의 위쪽 점인지를 조사.
*
*	\param p 조사할 점
*
*	\return true: 점 p가 평면의 위쪽 점 일경우, false: 그렇지 않을경우.
*/
bool GPlane::IsAbovePlane(const GPos3 &p) const
{
	double s;
	s = n[0] * p[0] + n[1] * p[1] + n[2] * p[2] + d;
	if (s > 0.0)
		return true;
	else
		return false;
}

/*!
*	\brief 점 p가 평면의 아래쪽 점인지를 조사.
*
*	\param p 조사할 점
*
*	\return true: 점 p가 평면의 아래쪽 점 일경우, false: 그렇지 않을경우.
*/
bool GPlane::IsBelowPlane(const GPos3 &p) const
{
	double s;
	s = n[0] * p[0] + n[1] * p[1] + n[2] * p[2] + d;
	if (s < 0.0)
		return true;
	else
		return false;
}

/*!
*	\brief 수치오류의 한계치를 설정한다.
*/
void GPlane::SetPrecision(const double err)
{
	Precision = err;
}

/*!
*	\brief 수치오류의 한계치를 리턴한다.
*
*	\return 한계치.
*/
double GPlane::GetPrecision()
{
	return Precision;
}

/*!
*	\brief 출력연산자 중복.
*
*	\param os 출력스트림.
*	\param pi 출력할 평면객체.
*
*	\return 출력스트림
*/
std::ostream &operator <<(std::ostream &os, const GPlane &pi)
{
	os << "(" << pi.n[0] << ") * x + ("
		<< pi.n[1] << ") * y + ("
		<< pi.n[2] << ") * z + ("
		<< pi.d << ") = 0";
	return os;
}

/*!
*	\brief	평면 pi에서 점 p까지의 부호있는 거리를 계산한다.
*
*	\param pi 평면의 객체.
*	\param p 평면 밖의 한점.
*
*	\return 평면 \a pi에서 점 \a p까지의 부호있는 거리
*/
double dist(const GPlane &pi, const GPos3 &p)
{
	double D;
	D = (p[0] * pi.n[0] + p[1] * pi.n[1] + p[2] * pi.n[2] + pi.d) / norm(pi.n);
	return D;
}

/*!
*	\brief	점 p를 평면 pi에 사영시킨 점을 구한다.
*
*	\param p 평면 밖의 점.
*	\param pi 평면객체.
*/
GPos3 proj(const GPos3 &p, const GPlane &pi)
{
	double s = -dist(pi, p) / norm(pi.n);
	return p + s * pi.n;
}

/*!
*	\brief	직선과 직선의 교차점을 계산한다.
*
*	\param p 교차점이 저장될 변수
*	\param l0 첫번째 직선의 방정식 (ruling line)
*	\param l1 두번째 직선의 방정식 (boundary line)
*	\param t0 첫번째 직선위 교차점의 파라미터 값이 저장됨
*	\param t1 두번째 직선위 교차점의 파라미터 값이 저장됨
*
*	\return true: 성공, false: 직선이 꼬인 위치에 있거나, (0 ~ 1)사이를 벗어날 경우
*/
bool intersect_line_line(GPos3 &p, const GLine &l0, const GLine &l1, double &t0, double &t1)
{
	double a = l0.v[0];
	double b = -l1.v[0];
	double c = l0.v[1];
	double d = -l1.v[1];
	double e = l1.p[0] - l0.p[0];
	double f = l1.p[1] - l0.p[1];

	double det = a * d - b * c;
	if (EQ(det, 0.0, 1.0e-6))
		return false;

	t0 = (d * e - b * f) / det;
	t1 = (a * f - c * e) / det;

	if (EQ(t0, 0.0, 1.0e-6))
		t0 = 0.0;

	if (EQ(t0, 1.0, 1.0e-6))
		t0 = 1.0;

	if (EQ(t1, 0.0, 1.0e-6))
		t1 = 0.0;

	if (EQ(t1, 1.0, 1.0e-6))
		t1 = 1.0;

	if (t0 < 0.0 || t0 > 1.0)
		return false;

	if (t1 < 0.0 || t1 > 1.0)
		return false;

	// p = l0.Eval(t0);
	p = l1.Eval(t1);

	return true;
}

/*!
*	\brief	직선과 직선의 교차점을 계산한다.
*
*	\param p 교차점이 저장될 변수
*	\param l0 첫번째 직선의 방정식 (ruling line)
*	\param l1 두번째 직선의 방정식 (boundary line)
*
*	\return true: 성공, false: 직선이 꼬인 위치에 있는 경우
*/
bool intersect_line_line2(GPos3 &p, GLine &l0, GLine &l1)
{
	double a = l0.v[0];
	double b = -l1.v[0];
	double c = l0.v[1];
	double d = -l1.v[1];
	double e = l1.p[0] - l0.p[0];
	double f = l1.p[1] - l0.p[1];

	double det = a * d - b * c;
	if (EQ(det, 0.0, 0.00001))
		return false;

	double t0, t1;
	t0 = (d * e - b * f) / det;
	t1 = (a * f - c * e) / det;

	// p = l0.Eval(t0);
	p = l1.Eval(t1);

	return true;
}

/*!
*	\brief	직선과 평면의 교차점을 계산한다.
*
*	\param p 교차점이 저장될 변수.
*	\param l 직선 객체.
*	\param pi 평면 객체.
*
*	\return true: 성공, false: 직선이 평면과 평행하거나, 평면이 직선을 포함하는 경우.
*/
bool intersect_line_plane(GPos3 &p, const GLine &l, const GPlane &pi)
{
	if (EQ_ZERO(l.v * pi.n, GPlane::Precision))
	{
		std::cout << "line is parallel to plane !" << std::endl;
		return false;
	}

	double t = -(l.p[0] * pi.n[0] + l.p[1] * pi.n[1] + l.p[2] * pi.n[2] + pi.d) / (l.v * pi.n);
	p = l.Eval(t);
	return true;
}

/*!
*	\brief	직선과 삼각형 (p1p2p3)의 교차점을 계산한다.
*
*	\param p1 삼각형의 정점
*	\param p2 삼각형의 정점
*	\param p3 삼각형의 정점
*	\param l 직선의 방정식
*	\param t q = l(t)를 만족하는 직선의 파라미터
*	\param q 교차점이 저장됨
*	\param alpha barycentric 좌표가 저장됨
*	\param beta barycentric 좌표가 저장됨
*	\param gamma barycentric 좌표가 저장됨
*	\param bCullBackFace 직선이 삼각형의 뒷면과 만나는 경우를 제외하려면. (디폴트: true).
*	\note q = alpha * p1 + beta * p2 + gamma * p3, (alpha + beta + gamma = 1)
*
*	\return true: 성공, false: 직선이 삼각형이 평행하거나 교차점이 삼각형의 외부에 존재하는 경우.
*/
bool intersect_line_triangle(const GPos3 &p1, const GPos3 &p2, const GPos3 &p3, const GLine &l, double &t, GPos3 &q, double &alpha, double &beta, double &gamma, const bool bCullBackFace)
{
	GVec3 e1, e2, u, v, w;
	double det;
	e1 = p1 - p3;
	e2 = p2 - p3;
	u = l.v ^ e2;
	det = e1 * u;

	if (bCullBackFace)	// 직선이 삼각형의 뒷면과 만나는 경우는 제외.
	{
		if (det < GLine::Precision)
			return false;

		w = l.p - p3;
		alpha = w * u;
		if (alpha < 0.0 || alpha > det)
			return false;

		v = w ^ e1;
		beta = l.v * v;
		if (beta < 0.0 || alpha + beta > det)
			return false;

		t = e2 * v;

		alpha /= det;
		beta /= det;
		t /= det;
	}
	else
	{
		if (det > -GLine::Precision && det < GLine::Precision)
			return false;

		w = l.p - p3;
		alpha = w * u / det;
		if (alpha < 0.0 || alpha > 1.0)
			return false;

		v = w ^ e1;
		beta = l.v * v / det;
		if (beta < 0.0 || alpha + beta > 1.0)
			return false;

		t = e2 * v / det;
	}

	gamma = 1.0 - alpha - beta;
	q = l.Eval(t);
	return true;
}

/*!
*	\brief	직선과 삼각형 (p1p2p3)의 교차점을 계산한다.
*
*	\param p1 삼각형의 정점
*	\param p2 삼각형의 정점
*	\param p3 삼각형의 정점
*	\param l 직선의 방정식
*	\param ispt 교차점이 저장됨
*	\param bCullBackFace 직선이 삼각형의 뒷면과 만나는 경우를 제외하려면. (디폴트: true).
*
*	\return true: 성공, false: 직선이 삼각형이 평행하거나 교차점이 삼각형의 외부에 존재하는 경우.
*/
bool intersect_line_triangle(const GPos3 &p1, const GPos3 &p2, const GPos3 &p3, const GLine &l, GPos3 &ispt, const bool bCullBackFace)
{
	GVec3 e1, e2, u, v, w;
	double det;
	e1 = p1 - p3;
	e2 = p2 - p3;
	u = l.v ^ e2;
	det = e1 * u;

	double t;
	if (bCullBackFace)	// 직선이 삼각형의 뒷면과 만나는 경우는 제외.
	{
		if (det < GLine::Precision)
			return false;

		w = l.p - p3;
		double alpha = w * u;
		if (alpha < 0.0 || alpha > det)
			return false;

		v = w ^ e1;
		double beta = l.v * v;
		if (beta < 0.0 || alpha + beta > det)
			return false;

		t = e2 * v;
		t /= det;
	}
	else
	{
		if (det > -GLine::Precision && det < GLine::Precision)
			return false;

		w = l.p - p3;
		double alpha = w * u / det;
		if (alpha < 0.0 || alpha > 1.0)
			return false;

		v = w ^ e1;
		double beta = l.v * v / det;
		if (beta < 0.0 || alpha + beta > 1.0)
			return false;

		t = e2 * v / det;
	}

	ispt = l.Eval(t);
	return true;
}

/*!
*	\brief	두 평면의 교차직선을 계산한다.
*
*	\param l 교차직선이 저장될 직선객체.
*	\param pi1 평면1.
*	\param pi2 평면2.
*
*	\return true: 성공, false: 두 평면이 평행한 경우.
*/
bool intersect_planes(GLine &l, const GPlane &pi1, const GPlane &pi2)
{
	double s = norm(pi1.n ^ pi2.n);
	if (EQ_ZERO(s, GPlane::Precision))
	{
		std::cout << "two planes are parallel !" << std::endl;
		return false;
	}

	l.v = pi1.n ^ pi2.n;

	GPos3 p(0, 0, 0);
	GPlane pi3(l.v, p);
	intersect_planes(p, pi1, pi2, pi3);

	l.p = p;
	return true;
}

/*!
*	\brief	세 평면의 교차점을 계산한다.
*
*	\param p 교차점이 저장될 점 객체.
*	\param pi1 평면1.
*	\param pi2 평면2.
*	\param pi3 평면3.
*
*	\return true: 성공, false: 세 평면 중 적어도 두 평면이 일치하거나 평행하는 경우.
*/
bool intersect_planes(GPos3 &p, const GPlane &pi1, const GPlane &pi2, const GPlane &pi3)
{
	GMatrix A(3, 3);
	GVec x(3), b(3), Idx(3);
	double tmp;

	A.SetRowVec(0, cast_vec(pi1.n));
	A.SetRowVec(1, cast_vec(pi2.n));
	A.SetRowVec(2, cast_vec(pi3.n));

	if (rank(A) != 3)
	{
		std::cout << "at least two planes are parallel !" << std::endl;
		return false;
	}

	b.Set(-pi1.d, -pi2.d, -pi3.d);
	dcmp_lu(A, Idx, tmp);

	lin_sys_lu(A, x, b, Idx);
	p[0] = x[0];
	p[1] = x[1];
	p[2] = x[2];
	return true;
}

/////////////////////////////////////////////////////////////////

/*!
*	\brief 디폴트 생성자.
*
*	\param _t 이동벡터.
*	\param _q 회전을 나타내는 쿼터니온.
*/
GTransf::GTransf(const GVec3 &_t, const GQuater &_q)
	: t(_t), q(_q)
{
}

/*!
*	\brief 생성자
*
*	\param mat 변환행렬(4 X 4)
*/
GTransf::GTransf(double *mat, bool isGL)
{
	if (isGL)
	{
		t.Set(mat[12], mat[13], mat[14]);
		q.SetFromMatrix(mat, isGL);
	}
	else
	{
		t.Set(mat[3], mat[7], mat[11]);
		q.SetFromMatrix(mat, isGL);
	}
}

/*!
*	\brief 복사 생성자.
*
*	\param copy 복사될 객체.
*/
GTransf::GTransf(const GTransf &cpy)
	: t(cpy.t), q(cpy.q)
{
}

/*!
*	\brief 소멸자.
*/
GTransf::~GTransf()
{
}

/*!
*	\brief 대입연산자 중복.
*
*	\param rhs 대입될 피연산자.
*
*	\return 변경된 자신을 반환한다.
*/
GTransf &GTransf::operator =(const GTransf &rhs)
{
	this->t = rhs.t;
	this->q = rhs.q;
	return *this;
}

/*!
*	\brief 복합대입연산자
*
*	\param rhs 오른쪽 피연산자.
*
*	\return 대입된 자신을 반환.
*/
GTransf &GTransf::operator *=(const GTransf &rhs)
{
	t += q * rhs.t;
	q *= rhs.q;
	q.Normalize();
	return *this;
}

/*!
*	\brief 복합 대입연산자
*
*	\param s 상수 값
*
*	\return 대입된 자신을 반환
*/
GTransf &GTransf::operator *=(const double &s)
{
	t *= s;
	q *= s;
	return *this;
}

/*!
*	\brief 산술연산자
*
*	\param lhs 왼쪽 피연산자.
*	\param rhs 오른쪽 피연산자.
*
*	\return 연결된 강체변환을 반환
*/
GTransf operator *(const GTransf &lhs, const GTransf &rhs)
{
	GTransf X(lhs);
	X *= rhs;
	return X;
}


/*!
*	\brief 등호연산자 중복.
*
*	\param lhs 왼쪽피연산자
*	\param rhs 오른쪽피연산자
*
*	\return true: 같으면, false: 다르면.
*/
bool operator ==(const GTransf &lhs, const GTransf &rhs)
{
	if (lhs.t == rhs.t && lhs.q == rhs.q)
		return true;
	else
		return false;
}

/*!
*	\brief 부등호연산자 중복.
*
*	\param lhs 왼쪽피연산자
*	\param rhs 오른쪽피연산자
*
*	\return true: 다르면, false: 같으면.
*/
bool operator !=(const GTransf &lhs, const GTransf &rhs)
{
	return !(lhs == rhs);
}

/*!
*	\brief 회전을 negate한다.
*/
void GTransf::SetNegate()
{
	q.SetNegate();
}

/*!
*	\brief 이동변환을 설정한다.
*
*	\param _t 설정될 이동변환
*/
void GTransf::SetTrans(const GVec3 &_t)
{
	t = _t;
}

/*!
*	\brief 회전변환을 설정한다.
*
*	\param _q 설정될 회전변환
*/
void GTransf::SetRot(const GQuater &_q)
{
	q = _q;
}

/*!
*	\brief 출력연산자 중복.
*
*	\param os 출력스트림.
*	\param X 출력할 강체변환.
*
*	\return 출력된 스트림
*/
std::ostream &operator <<(std::ostream &os, const GTransf &X)
{
	os << cast_mat(X, false);
	return os;
}

/*!
*	\brief 산술연산자
*
*	\param lhs 왼쪽 피연산자
*	\param s 상수
*
*	\return \a s만큼 스케일 된 변환
*/
GTransf operator *(const GTransf &lhs, const double &s)
{
	GTransf ret(lhs);
	ret *= s;
	return ret;
}

/*!
*	\brief * 연산자 중복
*
*	\param s 상수
*	\param rhs 왼쪽 피연산자
*	\return \a s만큼 스케일 된 변환
*/
GTransf operator *(const double &s, const GTransf &rhs)
{
	GTransf ret(rhs);
	ret *= s;
	return ret;
}

/*!
*	\brief 곱셈연산자 중복.
*
*	\param X 강체변환 객체.
*	\param p 지역좌표계상의 한 점.
*
*	\return 고정 (이전) 좌표계에서 점 p의 좌표.
*/
GPos3 operator *(const GTransf &X, const GPos3 &p)
{
	return X.q * p + X.t;
}

/*!
*	\brief 곱셈연산자 중복.
*
*	\param X 강체변환 객체.
*	\param v 지역좌표계상의 한 벡터.
*
*	\return 고정 (이전) 좌표계에서 벡터 v의 성분.
*	\warning 벡터의 경우, 이동정보가 영향을 주지 않는다.
*/
GVec3 operator *(const GTransf &X, const GVec3 &v)
{
	return X.q * v;
}

/*!
*	\brief 곱셈연산자 중복.
*
*	\param X 강체변환 객체.
*	\param l 지역좌표계상에서 표현되 직선 객체.
*
*	\return 고정 (이전) 좌표계에서 표현된 직선 l.
*/
GLine operator *(const GTransf &X, const GLine &l)
{
	GPos3 p = X * l.p;
	GVec3 v = X * l.v;
	return GLine(p, v);
}

/*!
*	\brief 곱셈연산자 중복.
*
*	\param X 강체변환 객체.
*	\param pi 지역좌표계상 표현된 평면의 객체.
*
*	\return 고정 (이전) 좌표계에서 표현된 평면 pi.
*/
GPlane operator *(const GTransf &X, const GPlane &pi)
{
	GVec3 n = X * pi.n;
	double d = pi.d - pi.n * (inv(X.q) * X.t);
	return GPlane(n, d);
}

/*!
*	\brief 강체변환의 역변환을 구한다.
*
*	\param X 강체변환 객체.
*
*	\return 강체변환 X의 역변환.
*/
GTransf inv(const GTransf &X)
{
	GQuater q = inv(X.q);
	GVec3 t = -(q * X.t);
	return GTransf(t, q);
}

/*!
*	\brief 강체변환의 이동성분을 구한다.
*
*	\param X 강체변환 객체.
*
*	\return 강체변환 X의 이동성분
*/
GVec3 part_trans(const GTransf &X)
{
	return X.t;
}

/*!
*	\brief 강체변환의 회전성분을 구한다.
*
*	\param X 강체변환 객체.
*
*	\return 강체변환 X의 회전성분
*/
GQuater part_rot(const GTransf &X)
{
	return X.q;
}

/*!
*	\brief 강체변환 X에 해당하는 4행 4열의 동차좌표변환행렬로 변환한다.
*	\param X 강체변환
*	\param isGL 만약 true 이면 행렬에 OpenGL 형태로 저장한다.
*
*	\return 강체변환을 표현하는 행렬
*/
GMatrix cast_mat(const GTransf &X, bool isGL)
{
	GMatrix R;
	R = cast_mat(X.q, isGL);
	if (isGL)
	{
		R[3][0] = X.t[0];
		R[3][1] = X.t[1];
		R[3][2] = X.t[2];
	}
	else
	{
		R[0][3] = X.t[0];
		R[1][3] = X.t[1];
		R[2][3] = X.t[2];
	}
	return R;
}

/*!
*	\brief 변환 X의 크기를 구한다.
*
*	\param X 강체변환
*
*	\return 변환 X의 크기
*/
double norm(const GTransf &X)
{
	return norm(X.t) + norm(log(X.q));
}

/*!
*	\brief 두 GTransf 간의 거리를 구한다
*
*	\param X1 첫번째 GTransf
*	\param X2 두번째 GTransf
*
*	\return \a X1 에서 \a X2 변환으로의 거리
*/
double dist(const GTransf &X1, const GTransf &X2)
{
	return norm(inv(X1) * X2);
}

/*!
*	\brief 변환간을 시간에 따라서 선형보간한다.
*
*	\param X1 첫번째 변환
*	\param X2 두번째 변환
*	\param t 시간 (0 <= t <= 1)
*
*	\return 보간된 변환이 반환된다.
*/
GTransf lerp(GTransf X1, GTransf X2, const double t)
{
	GTransf ret;

	if (quat_dot(X1.q, X2.q) < 0.0)
		X2.q.SetNegate();

	ret.t = (1.0 - t) * X1.t + t * X2.t;
	ret.q = slerp(X1.q, X2.q, t);

	return ret;
}

/*!
*	\brief \a X 좌표계에서 표현된 변환 \a dX를 \a Y 좌표계에서 표현된 변환으로 계산한다.
*
*	\param X 기준좌표계
*	\param dX 기준좌표계 \a X에서 표현된 변환
*	\param Y 대상좌표계
*
*	\return 기준좌표계 \a X에서 표현된 변환 \a dX를 대상좌표계 \a Y에서 표현으로 변환
*/
GTransf ad(const GTransf &X, const GTransf &dX, const GTransf &Y)
{
	GTransf YX = inv(Y) * X;
	GVec3 p = part_trans(YX * dX) - part_trans(YX);

	GVec3 axis;
	double angle;
	part_rot(dX).GetAngleAxis(axis, angle, true);

	GQuater q;
	q.SetFromAngleAxis(angle, YX * axis, true);

	return GTransf(p, q);
}
