#pragma once
#include <cfloat>
#include <cmath>

#define PI 3.141592654;

//FLT_EPSILON
namespace andMath {
__declspec(align(32))struct vec3 {
		union {
			float v[3];
			struct { float x, y, z; };
			struct { float r, g, b; };
		};
		float mag()		const;
		vec3 normal()	const;
		void normalize();
		vec3 operator-()const;
	};
	//binary operations 
	float dot(const vec3 &lhs, const vec3 &rhs);
	vec3 cross(const vec3 &lhs, const vec3 &rhs);

	vec3 lerp(const vec3 &lhs, const vec3 &rhs, float t);
	vec3 reflect(const vec3 &lhs, const vec3 &norm);

	vec3 operator+  (const vec3 &lhs, const vec3 &rhs);
	vec3 operator+= (vec3 &lhs, const vec3 &rhs);
	vec3 operator-  (const vec3 &lhs, const vec3 &rhs);
	vec3 operator-= (vec3 &lhs, const vec3 &rhs);

	vec3 operator*  (const vec3 &lhs, float rhs);
	vec3 operator*  (float rhs, const vec3 &lhs);
	vec3 operator*= (vec3 &lhs, float rhs);
	vec3 operator*= (float rhs, vec3 &lhs);

	vec3 operator/  (const vec3 &lhs, float rhs);
	vec3 operator/  (float rhs, const vec3 &lhs);
	vec3 operator/= (vec3 &lhs, float rhs);
	vec3 operator/= (float rhs, vec3 &lhs);

	bool operator== (const vec3 &lhs, const vec3 &rhs);
	bool operator!= (const vec3 &lhs, const vec3 &rhs);

	bool operator<  (const vec3 &lhs, const vec3 &rhs);
	bool operator<= (const vec3 &lhs, const vec3 &rhs);

	bool operator>  (const vec3 &lhs, const vec3 &rhs);
	bool operator>= (const vec3 &lhs, const vec3 &rhs);
}