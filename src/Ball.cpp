#include "Ball.hpp"

bool Ball::checkCollision() {
	int left;
	int top;
	int right;
	int bottom;

	left = pos.x;
	top = pos.y;
	right = pos.x + currentFrame.w;
	bottom = pos.y + currentFrame.h;

	if(
		top < 5 ||
		bottom > HEIGHT
	) return true;
	else if (
		left < 5 ||
		right > WIDTH
	) {
		this->pos.x = WIDTH/2 - 32;
		this->pos.y = HEIGHT/2 - 32;
		if(left <5) {
			angle = 90;
		}
		else {
			angle = 270;
		}
	}
	return false;
}

bool Ball::checkCollision(Player e) {
	int leftA, leftB;
	int topA, topB;
	int rightA, rightB;
	int bottomA, bottomB;

	leftA = pos.x;
	topA = pos.y;
	rightA = pos.x + currentFrame.w;
	bottomA = pos.y + currentFrame.h;

	leftB = e.getPos().x;
	topB = e.getPos().y;
	rightB = e.getPos().x + e.getCurrentFrame().w;
	bottomB = e.getPos().y + e.getCurrentFrame().h;

	if( 
		bottomA <= topB ||
		topA >= bottomB ||
		rightA <= leftB ||
		leftA >= rightB
	) return false;
	return true;
}

void Ball::calcAngle(float q) {
	angle += q;
	if(angle >= 360) {
		angle -= 360;
	}
	if(angle < 0) {
		angle += 360;
	}
}

void Ball::move(std::vector<Player> players) {
	float radians = angle * (M_PI / 180);
	float a_sin = sin(radians);
    float a_cos = cos(radians);
    this->pos.x += (step*a_sin);
    this->pos.y -= (step*a_cos);

	if(checkCollision()) {
		calcAngle(60);
	}
	else if(checkCollision(players[0])) {
		float diffx = fabs(this->pos.x - players[0].getPos().x);
		float q = -(diffx*360) / (players[0].getPos().x + players[0].getCurrentFrame().w);
		q*=1.15;
		calcAngle(q);
	}
	else if(checkCollision(players[1])) {
		float diffx = fabs(this->pos.x - players[1].getPos().x);
		float q = (diffx*360) / (players[1].getPos().x + players[1].getCurrentFrame().w);
		q*=1.15;
		calcAngle(q);
	}
}