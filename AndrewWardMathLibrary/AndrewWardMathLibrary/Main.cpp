#include <cassert>
#include <iostream>
#include "Vec2.h"
#include "Vec3.h"
#include "Vec4.h"


void vec2Tests() {
	//new vectors to test with
	andMath::vec2 a{ 5, 1 };
	andMath::vec2 b{ 2, 12 };
	andMath::vec2 c;
	float d = 2; //used for multi and div tests and float tests
	float d2;

	//vectors for bool tests
	andMath::vec2 e{ 1, 1 };
	andMath::vec2 f{ 1, 1 };
	andMath::vec2 h{ 10, 0 };
	andMath::vec2 i{ 0, 0 };

	//vector for mag test 
	andMath::vec2 g{ 2, 2};

	assert(fabs(sqrt(2) - e.mag()) < FLT_EPSILON);

	//perpendicular test
	//reseting c
	c = { 0,0 };
	andMath::vec2 perResult = { 1, -5 };
	c = a.perp();
	assert(c == perResult);

	//normal tests
	//reseting c
	c = { 0,0 };
	andMath::vec2 norm1Result = { (2 / sqrtf(8)), (2 / sqrtf(8)) };
	c = g.normal();
	assert(c == norm1Result);

	//normalizing a vector
	andMath::vec2 norm2Result = { (2 / sqrtf(8)), (2 / sqrtf(8)) };
	g.normalize();
	assert(g == norm2Result);

	//sign flip
	c = { 0,0 };
	andMath::vec2 flipResult = { -5, -1 };
	c = a.operator-();
	assert(c == flipResult);

	//dot product
	d2 = 0;
	float dotResult = 22;
	d2 = dot(a, b);
	assert(d2 == dotResult);

	//lerp
	float t = .5;
	c = { 0,0 };
	andMath::vec2 lerpResult = { 5, 0 };
	c = lerp(i, h, t);
	assert(c == lerpResult);

	//projection
	c = { 0,0 };
	andMath::vec2 proResult = { sqrtf(2), sqrtf(2) };
	c = project(e, f);
 	assert(c == proResult);

	//Operators
	//+
	andMath::vec2 pResult = { 7, 13 };
    c = a + b;
	assert(c == pResult);

	//+=
	andMath::vec2 pEResult = { 9, 25 };
	c += b;
	assert(c == pEResult);
	
	//reseting c
	c = { 0,0 };
	//-
	andMath::vec2 miResult = { 3, -11 };
	c = a - b;
	assert(c == miResult);

	//-=
	andMath::vec2 miEResult = { 1, -23 };
	c -= b;
	assert(c == miEResult);

	//reseting c
	c = { 0,0 };
	//*
	andMath::vec2 tResult = { 10, 2 };
	c = a * d;
	assert(c == tResult);

	//*=
	andMath::vec2 tEResult = { 20, 4 };
	c *= d;
	assert(c == tEResult);

	//reseting c
	c = { 0,0 };
	//*
	andMath::vec2 dResult = { 2.5, .5 };
	c = a / d;
	assert(c == dResult);

	//*=
	andMath::vec2 dEResult = { 1.25, .25 };
	c /= d;
	assert(c == dEResult);

	//bool tests
	assert(e == f);
	assert(e != a);
	assert(e < b);
	assert(e <= a);
	assert(b > a);
	assert(a >= e);


}

void vec3Tests() {
	//new vectors to test with
	andMath::vec3 a{ 5, 1, 3 };
	andMath::vec3 b{ 2, 12, 3 };
	andMath::vec3 c;
	float d = 2; //used for multi and div tests and float tests
	float d2;

	//vectors for bool tests
	andMath::vec3 e{ 1, 1, 1 };
	andMath::vec3 f{ 1, 1, 1 };
	andMath::vec3 h{ 10, 0, 2 };
	andMath::vec3 i{ 0, 0, 1 };

	//vector for mag test 
	andMath::vec3 g{ 2, 2, 2 };

	//assert(fabs(sqrt(2) - e.mag()) < FLT_EPSILON);


	//normal tests
	//reseting c
	c = { 0, 0, 0 };
	andMath::vec3 norm1Result = { (2 / sqrtf(12)), (2 / sqrtf(12)), (2 / sqrtf(12)) };
	c = g.normal();
	assert(c == norm1Result);

	//normalizing a vector
	andMath::vec3 norm2Result = { (2 / sqrtf(12)), (2 / sqrtf(12)), (2 / sqrtf(12)) };
	g.normalize();
	assert(g == norm2Result);

	//sign flip
	c = { 0, 0, 0 };
	andMath::vec3 flipResult = { -5, -1, -3 };
	c = a.operator-();
	assert(c == flipResult);

	//dot product
	d2 = 0;
	float dotResult = 31;
	d2 = dot(a, b);
	assert(d2 == dotResult);

	//lerp
	float t = .5;
	c = { 0, 0, 0 };
	andMath::vec3 lerpResult = { 5, 0, 1.5 };
	c = lerp(i, h, t);
	assert(c == lerpResult);

	//Operators
	//+
	andMath::vec3 pResult = { 7, 13, 6 };
	c = a + b;
	assert(c == pResult);

	//+=
	andMath::vec3 pEResult = { 9, 25, 9 };
	c += b;
	assert(c == pEResult);

	//reseting c
	c = { 0, 0, 0 };
	//-
	andMath::vec3 miResult = { 3, -11, 0 };
	c = a - b;
	assert(c == miResult);

	//-=
	andMath::vec3 miEResult = { 1, -23, -3 };
	c -= b;
	assert(c == miEResult);

	//reseting c
	c = { 0, 0, 0 };
	//*
	andMath::vec3 tResult = { 10, 2, 6 };
	c = a * d;
	assert(c == tResult);

	//*=
	andMath::vec3 tEResult = { 20, 4, 12 };
	c *= d;
	assert(c == tEResult);

	//reseting c
	c = { 0, 0, 0 };
	//*
	andMath::vec3 dResult = { 2.5, .5, 1.5 };
	c = a / d;
	assert(c == dResult);

	//*=
	andMath::vec3 dEResult = { 1.25, .25, .75 };
	c /= d;
	assert(c == dEResult);

	//bool tests
	assert(e == f);
	assert(h != a);
	assert(e < b);
	assert(e <= a);
	assert(b > a);
	assert(a >= e);

}

void vec4Tests() {

}

int main() {
	vec2Tests();
	vec3Tests();

	system("pause");
	return 0;
}