#include "Collision.h"


 bool Collision::Collisions(  Ball *ball, Ball *ball2) {

	Vec3 centre1 = ball->GetPos();
	Vec3 centre2 = ball2->GetPos();
	float dist = VMath::distance(centre1, centre2);
	if (dist < (ball->r + ball2->r)) {
		std::cout << "YAY";
		return true;
	}
	return false;
}

 void Collision::ResponseCollision(Ball *ball, Ball *ball2) {
	


	



		float e = 1.0f;//1
		Vec3 lineOfAction = ball->GetPos() - ball2->GetPos();
		Vec3 normalizedLineOfAction = VMath::normalize(lineOfAction);
		float v1p = VMath::dot(normalizedLineOfAction, ball->vel);
		float v2p = VMath::dot(normalizedLineOfAction, ball2->vel);

		float v1pnew = ((ball->mass - e * ball2->mass)*v1p) + ((1.0f + e)*ball2->mass*v2p) / (ball->mass + ball2->mass);
		float v2pnew = ((ball2->mass - e * ball->mass)*v2p) + ((1.0f + e)*ball->mass*v1p) / (ball->mass + ball2->mass);

		ball->vel += (v1pnew - v1p)*normalizedLineOfAction;
		ball2->vel += (v2pnew - v2p)*normalizedLineOfAction;
		
}