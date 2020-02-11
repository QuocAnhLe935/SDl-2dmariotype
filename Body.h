#ifndef BODY_H
#define BODY_H
#include "Vector.h"

#include "VMath.h"
using namespace MATH;
class Body {
	friend class Collision;

protected:
	Vec3 pos;
	Vec3 vel;
	Vec3 accel;
	float mass;

	

public:
	Body();
	Body(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_);
	~Body();
	void Update(const float deltaTime);
	void ApplyForce(Vec3 force);
	Vec3 GetPos() const;
	float r;
};

#endif

