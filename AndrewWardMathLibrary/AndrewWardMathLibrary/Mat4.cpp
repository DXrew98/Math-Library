#include "Mat4.h"

constexpr andMath::mat4 andMath::mat4::identity()
{
	mat4 n;
	n.c[0] = { 1, 0, 0, 0 };
	n.c[1] = { 0, 1, 0, 0 };
	n.c[2] = { 0, 0, 1, 0 };
	n.c[3] = { 0, 0, 0, 1 };
	return n;
}

andMath::mat4 andMath::transpose(const mat4 & a)
{
	mat4 n;
	n.c[0] = { a.mm[0][0], a.mm[1][0], a.mm[2][0], a.mm[3][0] };
	n.c[1] = { a.mm[0][1], a.mm[1][1], a.mm[2][1], a.mm[3][1] };
	n.c[2] = { a.mm[0][2], a.mm[1][2], a.mm[2][2], a.mm[3][2] };
	n.c[3] = { a.mm[0][3], a.mm[1][3], a.mm[2][3], a.mm[3][3] };
	return n;
}
andMath::mat4 andMath::inverse(const mat4 & a)
{
	mat4 n;
	mat4 mC = { 1, -1, 1, -1, 1, -1, 1, -1, 1 };

	n.c[0] = { a.m[5] * a.m[9] - a.m[6] * a.m[8], a.m[4] * a.m[9] - a.m[6] * a.m[7], a.m[4] * a.m[8] - a.m[5] * a.m[7] };
	n.c[1] = { a.m[2] * a.m[9] - a.m[3] * a.m[8], a.m[1] * a.m[9] - a.m[3] * a.m[7], a.m[1] * a.m[8] - a.m[2] * a.m[7] };
	n.c[2] = { a.m[2] * a.m[6] - a.m[3] * a.m[5], a.m[1] * a.m[6] - a.m[3] * a.m[4], a.m[1] * a.m[5] - a.m[2] * a.m[4] };

	n *= mC;

	return (transpose(n) * (1 / determinant(n)));
}

float andMath::determinant(const mat4 & a)
{
	mat3 one = { a.m[6], a.m[7], a.m[8], a.m[10], a.m[11], a.m[12], a.m[14], a.m[15], a.m[16] };
	mat3 two = { a.m[5], a.m[7], a.m[8], a.m[9], a.m[11], a.m[13], a.m[14], a.m[15], a.m[16]  };
	mat3 thr = { a.m[5], a.m[6], a.m[8], a.m[9], a.m[10], a.m[12], a.m[13], a.m[14], a.m[16]  };
	mat3 fou = { a.m[5], a.m[6], a.m[7], a.m[9], a.m[10], a.m[11], a.m[13], a.m[14], a.m[15]  };

	float n = a.m[1] * determinant(one) - a.m[2] * determinant(two)
			+ a.m[3] * determinant(thr) - a.m[4] * determinant(fou);
	return n;
}

andMath::mat4 andMath::rotate(const vec3 &normalizedVec3, float angle)
{
	vec3 m = normalizedVec3;
	float cos = cosf(angle);
	float cosp = 1.0f - cos;
	float sin = sinf(angle);
	
	mat4 n = { cos + m.x * m.x * cosp, m.y * m.x * cosp + m.z * sin, m.z * m.x * cosp - m.y * sin, 0, //first col

			   m.x * m.y * cosp - m.z * sin, cos + m.y * m.y * cosp, m.z * m.y * cosp + m.x * sin, 0, //second col

			   m.x * m.z * cosp + m.y * sin, m.y * m.z * cosp - m.x * sin, cos + m.z * m.z * cosp, 0, //third col

			   0, 0, 0, 1 };																		  //fourth col
	return n;
}
andMath::mat4 andMath::translate(const vec3 &translation)
{
	mat4 n = n.identity;
	n.mm[3][0] = translation.x;
	n.mm[3][1] = translation.y;
	n.mm[3][2] = translation.z;
	return n;
}
andMath::mat4 andMath::scale(const vec3 scale)
{
	mat4 n = n.identity;
	n.mm[0][0] = scale.x;
	n.mm[1][1] = scale.y;
	n.mm[2][2] = scale.z;
	return mat4();
}

andMath::mat4 andMath::operator+(const mat4 & lhs, const mat4 & rhs)
{
	mat4 n;
	n.c[0] = lhs.c[0] + rhs.c[0];
	n.c[1] = lhs.c[1] + rhs.c[1];
	n.c[2] = lhs.c[2] + rhs.c[2];
	n.c[3] = lhs.c[3] + rhs.c[3];
	return n;
}
andMath::mat4 andMath::operator+=(mat4 & lhs, const mat4 & rhs)
{
	lhs.c[0] += rhs.c[0];
	lhs.c[1] += rhs.c[1];
	lhs.c[2] += rhs.c[2];
	lhs.c[3] += rhs.c[3];
	return lhs;
}
andMath::mat4 andMath::operator-(const mat4 & lhs, const mat4 & rhs)
{
	mat4 n;
	n.c[0] = lhs.c[0] - rhs.c[0];
	n.c[1] = lhs.c[1] - rhs.c[1];
	n.c[2] = lhs.c[2] - rhs.c[2];
	n.c[3] = lhs.c[3] - rhs.c[3];
	return n;
}
andMath::mat4 andMath::operator-=(mat4 & lhs, const mat4 & rhs)
{
	lhs.c[0] -= rhs.c[0];
	lhs.c[1] -= rhs.c[1];
	lhs.c[2] -= rhs.c[2];
	lhs.c[3] -= rhs.c[3];
	return lhs;
}

inline andMath::mat4 andMath::operator*(const mat4 & lhs, const mat4 & rhs)
{
	mat4 n, t = transpose(lhs);
	n.c[0] = { dot(t.c[0], rhs.c[0]), dot(t.c[1], rhs.c[0]), dot(t.c[2], rhs.c[0]),  dot(t.c[3], rhs.c[0]) };
	n.c[1] = { dot(t.c[0], rhs.c[1]), dot(t.c[1], rhs.c[1]), dot(t.c[2], rhs.c[1]),  dot(t.c[3], rhs.c[1]) };
	n.c[2] = { dot(t.c[0], rhs.c[2]), dot(t.c[1], rhs.c[2]), dot(t.c[2], rhs.c[2]),  dot(t.c[3], rhs.c[2]) };
	n.c[3] = { dot(t.c[0], rhs.c[3]), dot(t.c[1], rhs.c[3]), dot(t.c[2], rhs.c[3]),  dot(t.c[3], rhs.c[3]) };
	return n;
}
inline andMath::vec4 andMath::operator*(const mat4 & lhs, const vec4 & rhs)
{
	mat4 t = transpose(lhs);
	vec4 n;

	n.x = dot(t.c[0], rhs);
	n.y = dot(t.c[1], rhs);
	n.z = dot(t.c[2], rhs);
	n.z = dot(t.c[3], rhs);

	return n;
}
inline andMath::mat4 andMath::operator*(const mat4 & lhs, float rhs)
{
	mat4 n;
	n.c[0] = lhs.c[0] * rhs;
	n.c[1] = lhs.c[1] * rhs;
	n.c[2] = lhs.c[2] * rhs;
	n.c[3] = lhs.c[3] * rhs;
	return n;
}

andMath::mat4 andMath::operator*=(mat4 & lhs, const mat4 & rhs)
{
	mat4 t = transpose(lhs);
	t.c[0] = { dot(t.c[0], rhs.c[0]), dot(t.c[1], rhs.c[0]), dot(t.c[2], rhs.c[0]),  dot(t.c[3], rhs.c[0]) };
	t.c[1] = { dot(t.c[0], rhs.c[1]), dot(t.c[1], rhs.c[1]), dot(t.c[2], rhs.c[1]),  dot(t.c[3], rhs.c[1]) };
	t.c[2] = { dot(t.c[0], rhs.c[2]), dot(t.c[1], rhs.c[2]), dot(t.c[2], rhs.c[2]),  dot(t.c[3], rhs.c[2]) };
	t.c[2] = { dot(t.c[0], rhs.c[3]), dot(t.c[1], rhs.c[3]), dot(t.c[2], rhs.c[3]),  dot(t.c[3], rhs.c[3]) };
	return t;
}
andMath::mat4 andMath::operator*=(mat4 & lhs, float rhs)
{
	lhs.c[0] *= rhs;
	lhs.c[1] *= rhs;
	lhs.c[2] *= rhs;
	lhs.c[3] *= rhs;
	return lhs;
}

bool andMath::operator==(const mat4 & a, const mat4 & b)
{
	return (a.c[0] == a.c[0] && a.c[1] == a.c[1] && a.c[2] == a.c[2] && a.c[3] == a.c[3]) ? true : false;
}
bool andMath::operator!=(const mat4 & a, const mat4 & b)
{
	return (a.c[0] != a.c[0] && a.c[1] != a.c[1] && a.c[2] != a.c[2] && a.c[3] != a.c[3]) ? true : false;
}

andMath::mat4 andMath::ortho(float left, float right, float bottom, float top, float near, float far)
{
	//based of off work done in glmatrix library
	//http://glmatrix.net/docs/2.2.0/symbols/src/gl-matrix_src_gl-matrix_mat4.js.html

	mat4 nM = mat4::identity();

	float l = left, r = right, b = bottom, t = top, n = near, f = far;
	float lr = 1 / (l - r),
		  bt = 1 / (b - t),
		  nf = 1 / (n - f);

	//anything not listed here is 0
	nM.m[0]  = -2 * lr;
	nM.m[5]  = -2 * bt;
	nM.m[10] =  2 * nf;
	nM.m[12] = (l + r) * lr;
	nM.m[13] = (t + b) * bt;
	nM.m[14] = (n + f) * nf;

	return nM);
}

andMath::mat4 andMath::frustum(float left, float right, float bottom, float top, float near, float far)
{
	//based of off work done in glmatrix library
	//http://glmatrix.net/docs/2.2.0/symbols/src/gl-matrix_src_gl-matrix_mat4.js.html

	mat4 nM = mat4::identity();

	float l = left, r = right, b = bottom, t = top, n = near, f = far;
	float rl = 1 / (r - l),
		  tb = 1 / (t - b),
		  nf = 1 / (n - f);

	//anything not listed here is 0
	nM.m[0]  = (n * 2) * rl;
	nM.m[5]  = (n * 2) * tb;
	nM.m[8]  = (r + l) * rl;
	nM.m[9]  = (t + b) * tb;
	nM.m[10] = (f + n) * nf;
	nM.m[11] = -1;
	nM.m[14] = (f * n * 2) * nf;

	return nM;
}

andMath::mat4 andMath::perspective(float fov, float aspect, float near, float far)
{
	//based of off work done in glmatrix library
	//http://glmatrix.net/docs/2.2.0/symbols/src/gl-matrix_src_gl-matrix_mat4.js.html

	mat4 nM = mat4::identity();

	float fo = fov, a = aspect, n = near, fa = far;
	float f = 1 / tanf(fo / 2);
	float nf = 1 / (n - fa);

	//anything not listed here is 0
	nM.m[0]  = f / a;
	nM.m[5]  = f;
	nM.m[10] = (fa + n) * nf;
	nM.m[11] = -1;
	nM.m[14] = (2 * fa * n) * nf;

	return nM;
}



