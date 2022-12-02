#include "howitzer.h"

Howitzer::Howitzer()
{
	/* Position sets a random X coordinate as X.*/
	generatePosition(500);
	elevation.setDegrees(0); // Defaults to 0.
	
}

void Howitzer::draw(ogstream &gout, double flightTime)
{
	gout.drawHowitzer(position, elevation.getRadians(), flightTime);
}

Position& Howitzer::getPosition()
{
	return position; // Placeholder
}

void Howitzer::generatePosition(int size)
{
	position.setPixelsX(random(20, (size - 20)));
}

Velocity Howitzer::getMuzzleVelocity()
{
	Velocity v; // Placeholder
	return v;   // Placeholder
}

void Howitzer::setMuzzleVelocity(Velocity velocity)
{

}

void Howitzer::rotate(double radians)
{
	elevation.setRadians(elevation.getRadians() + radians);
}

void Howitzer::raise(double radians)
{

}