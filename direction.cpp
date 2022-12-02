#define _USE_MATH_DEFINES

#include "direction.h"
#include "velocity.h"
#include <math.h>
#include <cmath>




void Direction::assign(Direction rhs)
{

}

void Direction::setRadians(double radians)
{
	int difference = floor(radians / (2 * M_PI));
	radians -= ((2 * M_PI) * difference);
	this->radians = radians;
}

void Direction::setDegrees(double rhs)
{
	int difference = floor(rhs / 360);
	double newRadians = (rhs / 360) * (2 * M_PI) - ((2 * M_PI) * difference);
	setRadians(newRadians);
}

void Direction::setDxDy(double dx, double dy)
{
	//setting angle in radians based off of dx/dy
	setRadians(atan2(dy, dx));

}

void Direction::setDown()
{
	setRadians(M_PI);
}

void Direction::setUp()
{
	setRadians(0);
}

void Direction::setRight()
{
	setRadians((M_PI / 2));
}

void Direction::setLeft()
{
	setRadians(3 * (M_PI / 2));
}


void Direction::reverse()
{
	if (this->radians < M_PI) {
		this->radians += M_PI;
	}
	else {
		this->radians -= M_PI;
	}
}

double Direction::getDegrees()
{
	int difference = floor(radians / (2 * M_PI));
	double degrees = ((radians/(2 * M_PI)) * 360) - (360 * difference);
	return degrees;
}

double Direction::getDX()
{
	// v SIN theta = x
	//double velocityTotal = getSpeed();

	return 0; //velocityTotal* sin(getRadians());
}

double Direction::getDY()
{
	// v COS theta = y
	//double velocityTotal = getSpeed();

	return 0;//velocityTotal * cos(getRadians());
}