#include <cfloat>
#include <cmath>

#define PI 3.141592654;

//FLT_EPSILON
namespace andMath {
	struct vec2 {
		union {
			struct { float x, y; };
			float v[2];
		};
		static vec2 fromAngle(float angle) {
			vec2 c;
			c.x = cosf(angle);
			c.y = sinf(angle);
			return c;
		}// shoot a vector for a determined angle
		//unary operations
		float mag()		const { return sqrtf(x * x + y * y); }
		float angle()	const { return atan2(y, x) * 180 / PI; }
		vec2 normal()	const { 
			vec2 c;
			c.x = x / mag();
			c.y = y / mag();
			return c; }
		vec2 perp()		const {
			vec2 p;
			p.x = y;
			p.y = x * -1;
			return p;
		}
		void normalize() {
			x /= mag();
			y /= mag();
		}
		vec2 operator-()const {
			vec2 c;
			c.x = x * -1;
			c.y = y * -1;
			return  c;
		}
	};
	//binary operations 
	float dot(const vec2 &lhs, const vec2 &rhs) { return (lhs.x * rhs.x) + (lhs.y * rhs.y); }
	vec2 lerp(const vec2 &lhs, const vec2 &rhs, float t) { return lhs * t + rhs * (1 - t); }
	vec2 reflex();

	vec2 operator+  (const vec2 &lhs, const vec2 &rhs){
		vec2 c;
		c.x = lhs.x + rhs.x;
		c.y = lhs.y + rhs.y;
		return  c;
	}
	vec2 operator+= (vec2 &lhs, const vec2 &rhs)
	{
		lhs = lhs + rhs;		
	}
	vec2 operator-  (const vec2 &lhs, const vec2 &rhs){
		vec2 c;
		c.x = lhs.x - rhs.x;
		c.y = lhs.y - rhs.y;
		return  c;
	}
	vec2 operator-= (vec2 &lhs, const vec2 &rhs){
		lhs = lhs + rhs;
	}

	vec2 operator*  (const vec2 &lhs, float rhs) {
		vec2 c;
		c.x = lhs.x * rhs;
		c.y = lhs.y * rhs;
		return  c;
	}
	vec2 operator/  (const vec2 &lhs, float rhs) {
		vec2 c;
		c.x = lhs.x / rhs;
		c.y = lhs.y / rhs;
		return  c;
	}
	vec2 operator*= (vec2 &lhs, float rhs) {
		lhs = lhs * rhs;
	}
	vec2 operator/= (vec2 &lhs, float rhs) {
		lhs = lhs / rhs;
	}

	bool operator== (const vec2 &lhs, const vec2 &rhs) { return (fabs(lhs.x - rhs.x) < FLT_EPSILON && fabs(lhs.y - rhs.y) < FLT_EPSILON); }
	bool operator!= (const vec2 &lhs, const vec2 &rhs) { return !(fabs(lhs.x - rhs.x) < FLT_EPSILON && fabs(lhs.y - rhs.y) < FLT_EPSILON); }
	bool operator<  (const vec2 &lhs, const vec2 &rhs) { return lhs.mag() < rhs.mag(); }
	bool operator<= (const vec2 &lhs, const vec2 &rhs) { return lhs.mag() < rhs.mag() || fabs(lhs.mag() - rhs.mag()) < FLT_EPSILON; }
	bool operator>  (const vec2 &lhs, const vec2 &rhs) { return lhs.mag() > rhs.mag(); }
	bool operator>= (const vec2 &lhs, const vec2 &rhs) { return lhs.mag() > rhs.mag() || fabs(lhs.mag() - rhs.mag()) < FLT_EPSILON; }
}