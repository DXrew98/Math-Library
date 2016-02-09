#include "CollisionTests.h"
#include <cmath>

float andMath::pointPlaneDistance(const Circle &circle, const Plane & plane)
{
	return (dot(plane.normal, (circle.pos - plane.pos)));
}
float andMath::rayPlaneDistance(const Ray & ray, const Plane & plane)
{
	return (0 <= (dot(plane.normal, (ray.pos - plane.pos)) / -dot(plane.normal, ray.dir)) <= 12);
}

andMath::CollisionData andMath::iTest(const AABB & rectA, const AABB & rectB)
{
	CollisionData cd = { false, INFINITY };
	if (rectA.max.x >= rectB.min.x && rectB.max.x >= rectA.min.x &&
		rectA.max.y >= rectB.min.y && rectB.max.y >= rectA.min.x) {
		return cd = { true }; }
	return cd;
}
andMath::CollisionData andMath::iTest(const AABB & rect, const Circle & circle)
{
	CollisionData cd = { false };
	vec2 cP = clamp(circle.pos, rect.min, rect.max);
	if (circle.pos - cP) * (circle.pos - cP) <= (circle.radius * circle.radius)) {cd = { true }; }
	return cd;
}
andMath::CollisionData andMath::iTest(const AABB & rect, const Ray & ray)
{
	return CollisionData();
}
andMath::CollisionData andMath::iTest(const AABB & rect, const Plane & plane)
{
	return CollisionData();
}

andMath::CollisionData andMath::iTest(const Circle & circleA, const Circle & circleB)
{
	CollisionData cd = { false };
	float dist = pow(circleA.pos.x - circleB.pos.x, 2) + pow(circleA.pos.y - circleB.pos.y, 2);
	float radius = pow(circleA.radius + circleB.radius, 2) * pow(circleA.radius + circleB.radius, 2);
	if (dist < radius) { cd = { true }; }
	return cd;
}
andMath::CollisionData andMath::iTest(const Circle & circle, const Ray & ray)
{
	return CollisionData();
}
andMath::CollisionData andMath::iTest(const Circle & circle, const Plane & plane)
{
	CollisionData cd = { false };
	float lhs = dot(plane.normal, (circle.pos - plane.pos));
	float rhs = circle.radius;

	if (lhs <= rhs) { cd = { true, lhs }; }
	return cd;
}

andMath::CollisionData andMath::iTest(const Ray & ray, const Plane & plane)
{
	return CollisionData();
}

andMath::CollisionData andMath::iTest(const ConvexHull & chullA, const ConvexHull & chullB)
{
	return CollisionData();
}
andMath::CollisionData andMath::iTest(const ConvexHull & chull, const Circle & circle)
{
	return CollisionData();
}
andMath::CollisionData andMath::iTest(const ConvexHull & chull, const Ray & ray)
{
	return CollisionData();
}
andMath::CollisionData andMath::iTest(const ConvexHull & chull, const Plane & plane)
{
	return CollisionData();
}
andMath::CollisionData andMath::iTest(const ConvexHull & chull, const AABB & rect)
{
	return CollisionData();
}
