#include <cfloat>
#include <cmath>

#define PI 3.141592654;

//FLT_EPSILON
namespace andMath {
__declspec(align(32)) struct vec2 {
		union {
			float v[2];
			struct { float x, y; };
		};
		static vec2 fromAngle(float angle);// shoot a vector for a determined angle
		//unary operations
		float mag()		const;
		float angle()	const;
		vec2 perp()		const;
		vec2 normal()	const;
		void normalize();
		vec2 operator-()const;
	};
	//binary operations 
	float dot(const vec2 &lhs, const vec2 &rhs);

	vec2 lerp(const vec2 &lhs, const vec2 &rhs, float t);
	vec2 reflect(const vec2 &lhs, const vec2 &norm);
	vec2 project(const vec2 &a, const vec2 &b);

	vec2 operator+  (const vec2 &lhs, const vec2 &rhs);
	vec2 operator+= (vec2 &lhs, const vec2 &rhs);
	vec2 operator-  (const vec2 &lhs, const vec2 &rhs);
	vec2 operator-= (vec2 &lhs, const vec2 &rhs);

	vec2 operator*  (const vec2 &lhs, float rhs);
	vec2 operator*  (float rhs, const vec2 &lhs);
	vec2 operator*= (vec2 &lhs, float rhs);
	vec2 operator*= (float rhs, vec2 &lhs);

	vec2 operator/  (const vec2 &lhs, float rhs);
	vec2 operator/  (float rhs, const vec2 &lhs);
	vec2 operator/= (vec2 &lhs, float rhs);
	vec2 operator/= (float rhs, vec2 &lhs);

	bool operator== (const vec2 &lhs, const vec2 &rhs);
	bool operator!= (const vec2 &lhs, const vec2 &rhs);

	bool operator<  (const vec2 &lhs, const vec2 &rhs);
	bool operator<= (const vec2 &lhs, const vec2 &rhs);

	bool operator>  (const vec2 &lhs, const vec2 &rhs);
	bool operator>= (const vec2 &lhs, const vec2 &rhs);
}

