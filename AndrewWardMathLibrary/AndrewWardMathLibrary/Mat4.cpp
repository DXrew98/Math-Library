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
	float n = (a.m[1] * (a.m[5] * a.m[9] - a.m[6] * a.m[8]))
			- (a.m[2] * (a.m[4] * a.m[9] - a.m[6] * a.m[7]))
			+ (a.m[3] * (a.m[4] * a.m[8] - a.m[5] * a.m[7]));
	return n;
}

andMath::mat4 andMath::rotate(const vec3 &a, float b)
{
	mat4 n;
	n.c[0] = { cosf(b), sinf(b), 0 };
	n.c[1] = { -sinf(b), cosf(b), 0 };
	return n;
}
andMath::mat4 andMath::translate(const vec3 &a)
{
	mat4 n = n.identity;
	n.mm[2][0] = a.x;
	n.mm[2][1] = a.y;
	return n;
}
andMath::mat4 andMath::scale(const vec3 a)
{
	mat4 n = n.identity;
	n.mm[0][0][0] = a;
	n.mm[1][1][1] = a;
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

