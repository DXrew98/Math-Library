#include "vmmath.h"

		andMath::vec2 andMath::vec2::fromAngle(float angle) {
			vec2 c;
			c.x = cosf(angle);
			c.y = sinf(angle);
			return c;
		}// shoot a vector for a determined angle
		float andMath::vec2::mag()		const { return sqrtf(x * x + y * y); }
		float andMath::vec2::angle()	const { return atan2(y, x) * 180 / PI; }
		andMath::vec2 andMath::vec2::perp()		const {
			vec2 p;
			p.x = y;
			p.y = x * -1;
			return p;
		}
		andMath::vec2 andMath::vec2::normal()	const {
			vec2 c;
			float m = mag();
			c.x = x / m;
			c.y = y / m;
			return c;
		}
		void andMath::vec2::normalize() {
			float m = mag();
			x /= m;
			y /= m;
		}
		andMath::vec2 andMath::vec2::operator-()const {
			vec2 c;
			c.x = x * -1;
			c.y = y * -1;
			return  c;
		}

	float andMath::dot(const vec2 &lhs, const vec2 &rhs) { return (lhs.x * rhs.x) + (lhs.y * rhs.y); }

	andMath::vec2 andMath::lerp(const vec2 &lhs, const vec2 &rhs, float t) { return lhs * t + rhs * (1 - t); }// add clamp betwwen 0-1
	andMath::vec2 andMath::reflect(const vec2 &lhs, const vec2 &norm) { return 2 * (dot(lhs, norm)) * norm - lhs; }
	andMath::vec2 andMath::project(const vec2 & a, const vec2 & b) { return dot(a, b) * b.normal(); }

	andMath::vec2 andMath::min(const vec2 & a, const vec2 & b)
	{
		if (a < b) { return a; }
		else       { return b; }
	}

	andMath::vec2 andMath::max(const vec2 & a, const vec2 & b)
	{
		if (a > b) { return a; }
		else       { return b; }
	}

	andMath::vec2 andMath::clamp(const vec2 & a, const vec2 & min, const vec2 & max)
	{
		if (a > max) { return max; }
		if (a < min) { return min; }
	}

	andMath::vec2 andMath::operator+  (const vec2 &lhs, const vec2 &rhs) {
		vec2 c;
		c.x = lhs.x + rhs.x;
		c.y = lhs.y + rhs.y;
		return  c;
	}
	andMath::vec2 andMath::operator+= (vec2 &lhs, const vec2 &rhs)
	{
		return lhs = lhs + rhs;
	}
	andMath::vec2 andMath::operator-  (const vec2 &lhs, const vec2 &rhs) {
		vec2 c;
		c.x = lhs.x - rhs.x;
		c.y = lhs.y - rhs.y;
		return  c;
	}
	andMath::vec2 andMath::operator-= (vec2 &lhs, const vec2 &rhs) {
		return lhs = lhs - rhs;
	}

	andMath::vec2 andMath::operator*  (const vec2 &lhs, const vec2 &rhs) {
		vec2 c;
		c.x = lhs.x * rhs.x;
		c.y = lhs.y * rhs.y;
		return  c;
	}
	andMath::vec2 andMath::operator*  (const vec2 &lhs, float rhs) {
		vec2 c;
		c.x = lhs.x * rhs;
		c.y = lhs.y * rhs;
		return  c;
	}
	andMath::vec2 andMath::operator*  (float rhs, const vec2 &lhs) {
		vec2 c;
		c.x = lhs.x * rhs;
		c.y = lhs.y * rhs;
		return  c;
	}
	andMath::vec2 andMath::operator*= (vec2 &lhs, float rhs) {
		return lhs = lhs * rhs;
	}
	andMath::vec2 andMath::operator*= (float rhs, vec2 &lhs) {
		return lhs = lhs * rhs;
	}

	andMath::vec2 andMath::operator/  (const vec2 &lhs, float rhs) {
		vec2 c;
		c.x = lhs.x / rhs;
		c.y = lhs.y / rhs;
		return  c;
	}
	andMath::vec2 andMath::operator/  (float rhs, const vec2 &lhs) {
		vec2 c;
		c.x = lhs.x / rhs;
		c.y = lhs.y / rhs;
		return  c;
	}
	andMath::vec2 andMath::operator/= (vec2 &lhs, float rhs) {
		return lhs = lhs / rhs;
	}
	andMath::vec2 andMath::operator/= (float rhs, vec2 &lhs) {
		return lhs = lhs / rhs;
	}

	bool andMath::operator== (const vec2 &lhs, const vec2 &rhs) { return (fabs(lhs.x - rhs.x) < FLT_EPSILON && fabs(lhs.y - rhs.y) < FLT_EPSILON); }
	bool andMath::operator!= (const vec2 &lhs, const vec2 &rhs) { return !(fabs(lhs.x - rhs.x) < FLT_EPSILON && !(fabs(lhs.y - rhs.y)) < FLT_EPSILON); }

	bool andMath::operator<  (const vec2 &lhs, const vec2 &rhs) { return lhs.mag() < rhs.mag(); }
	bool andMath::operator<= (const vec2 &lhs, const vec2 &rhs) { return lhs.mag() < rhs.mag() || fabs(lhs.mag() - rhs.mag()) < FLT_EPSILON; }

	bool andMath::operator>  (const vec2 &lhs, const vec2 &rhs) { return lhs.mag() > rhs.mag(); }
	bool andMath::operator>= (const vec2 &lhs, const vec2 &rhs) { return lhs.mag() > rhs.mag() || fabs(lhs.mag() - rhs.mag()) < FLT_EPSILON; }
