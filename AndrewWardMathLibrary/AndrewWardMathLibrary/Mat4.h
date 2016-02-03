#pragma once
#include "vec4.h"
#include "mat3.h"

namespace andMath {
	__declspec(align(32)) struct mat4 {
		union {
			vec4 c[4];
			struct { float m[16]; };
			struct { float mm[4][4]; };
			struct {
				union { vec4 c1; vec3 rht; };
				union { vec4 c2; vec3 up; };
				union { vec4 c3; vec3 pos; };
			};
		};
		static constexpr mat4 identity();
	};

	mat4 transpose(const mat4 &a);
	mat4 inverse(const mat4 &a);

	float determinant(const mat4 &a);

	mat4 rotate(const vec3 &a, float b);
	mat4 translate(const vec3 &a);
	mat4 scale(const vec3 a);

	mat4 operator+	(const mat4 &lhs, const mat4 &rhs);
	mat4 operator+=	(mat4 &lhs, const mat4 &rhs);
	mat4 operator-	(const mat4 &lhs, const mat4 &rhs);
	mat4 operator-=	(mat4 &lhs, const mat4 &rhs);

	mat4 operator*	(const mat4 &lhs, const mat4 &rhs); //mat
	vec4 operator*	(const mat4 &lhs, const vec4 &rhs); //vec
	mat4 operator*	(const mat4 &lhs, float rhs);		//scalar

	mat4 operator*=	(mat4 &lhs, const mat4 &rhs);
	mat4 operator*=	(mat4 &lhs, float rhs);

	bool operator == (const mat4 &a, const mat4 &b);
	bool operator != (const mat4 &a, const mat4 &b);
}