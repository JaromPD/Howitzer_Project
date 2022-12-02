#pragma once
#include "direction.h"
#include "physics.h"

class Velocity
{
public:
	Velocity() : dx(0), dy(0) {}
	Velocity(double dx, double dy);
	Velocity(double totalSpeed, Direction direction);

	// Getters
	double getDX() { return dx; }
	double getDY() { return dy; }
	double getSpeed() { return getTotalComponent(dx, dy); }
	Direction getDirection();

	// Setters
	void setDX(double dx) { this->dx = dx; }
	void setDY(double dy) { this->dy = dy; }
	void setDxDy(double dx, double dy) { this->dx = dx; this->dy = dy; }
	void setDirection(Direction direction);
	void setSpeed(double speed);

	void addDX(double dx);
	void addDY(double dy);
	void addV(Velocity velocity);
	void reverse();
	Velocity& operator+=(Velocity velocity);

private:

	double dx;
	double dy;

	friend class TestVelocity;
};

