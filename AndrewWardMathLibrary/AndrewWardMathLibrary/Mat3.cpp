#include "Mat3.h"

constexpr andMath::mat3 andMath::mat3::identity()
{
	mat3 n;
	n.c[0] = { 1, 0, 0 };
	n.c[1] = { 0, 1, 0 };
	n.c[2] = { 0, 0, 1 };
	return n;
}

andMath::mat3 andMath::transpose(const mat3 & a)
{
	mat3 n;
	n.c[0] = { a.mm[0][0], a.mm[1][0], a.mm[2][0] };
	n.c[1] = { a.mm[0][1], a.mm[1][1], a.mm[2][1] };
	n.c[2] = { a.mm[0][2], a.mm[1][2], a.mm[2][2] };
	return mat3();
}
andMath::mat3 andMath::inverse(const mat3 & a)
{
	return mat3();
}

andMath::mat3 andMath::determinate(const mat3 & a)
{
	return mat3();
}

andMath::mat3 andMath::rotate(float a)
{
	mat3 n;
	n.c[0] = { cosf(a), sinf(a), 0 };
	n.c[1] = { -sinf(a), cosf(a), 0 };
	return n;
}
andMath::mat3 andMath::translate(const vec2 & a)
{
	return mat3();
}
andMath::mat3 andMath::scale(const vec2 & a)
{
	return mat3();
}

andMath::mat3 andMath::operator+(const mat3 & lhs, const mat3 & rhs)
{
	return mat3();
}
andMath::mat3 andMath::operator+=(const mat3 & lhs, const mat3 & rhs)
{
	return mat3();
}
andMath::mat3 andMath::operator-(const mat3 & lhs, const mat3 & rhs)
{
	return mat3();
}
andMath::mat3 andMath::operator-=(const mat3 & lhs, const mat3 & rhs)
{
	return mat3();
}

andMath::mat3 andMath::operator*(const mat3 & lhs, const mat3 & rhs)
{
	return mat3();
}
andMath::mat3 andMath::operator*(const mat3 & lhs, const vec3 & rhs)
{
	return mat3();
}
andMath::mat3 andMath::operator*(const mat3 & lhs, float rhs)
{
	return mat3();
}

andMath::mat3 andMath::operator*=(const mat3 & lhs, const mat3 & rhs)
{
	return mat3();
}
andMath::mat3 andMath::operator*=(const mat3 & lhs, float rhs)
{
	return mat3();
}
