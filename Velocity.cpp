#include "velocity.h"
#include <math.h>

Velocity::Velocity(double dx, double dy) 
{
	setDX(dx);
	setDY(dy);
}

Velocity::Velocity(double totalSpeed, Direction direction)
{
	setSpeed(totalSpeed);
	setDirection(direction);
}

/*
 * GET DIRECTION
 * 
 * Gets the angle in radians from dx dy and returns 
 * a Direction obj containing it.
 */
Direction Velocity::getDirection()
{
	Direction d; // Direction obj
	double a;	 // Angle
	a = getAngleFromComponents(dx, dy);
	d.setRadians(a);
	return d;
}


/*
 * SET DIRECTION
 *
 * Sets the angle in radians from dx dy and returns nothing.
 */
void Velocity::setDirection(Direction direction)
{
	double angle = direction.getRadians();
	double total = getTotalComponent(dx, dy);
	double newDX = getHorizontalComponent(total, angle);
	double newDY = getVerticalComponent(total, angle);

	dx = newDX;
	dy = newDY;
}

void Velocity::setSpeed(double speed)
{
	double angle;
	double newDX;
	double newDY;
	angle = getAngleFromComponents(dx, dy);
	newDX = getHorizontalComponent(speed, angle);
	newDY = getHorizontalComponent(speed, angle);

	dx = newDX;
	dy = newDY;
}

void Velocity::addDX(double dx)
{
	this->dx += dx;
}

void Velocity::addDY(double dy)
{
	this->dy += dy;
}

void Velocity::reverse()
{
	dx *= -1;
	dy *= -1;
}


// Changed the addV() method to an overload of +=.
Velocity& Velocity::operator+=(Velocity velocity)
{
	this->dx += velocity.dx;
	this->dy += velocity.dy;
	return *this;
}