#include <iostream>
#include "simulation.h"
using namespace std;

Simulation::Simulation(Position ptUpperRight) :
	ptUpperRight(ptUpperRight),
	ground(ptUpperRight),
	simTime(0.0)
{
	ground.reset(howitzer.getPosition());
}

void Simulation::advance()
{
	simTime += interval;
	if (projectile.flying())
	{
		projectile.advance(interval);
	}
}

void Simulation::reset()
{

}

void Simulation::fire()
{
	cout << "***" << howitzer.getMuzzleVelocity().getSpeed() << "***";
	projectile.fire(howitzer.getPosition(), simTime, howitzer.getMuzzleVelocity().getDirection(), howitzer.getMuzzleVelocity());
}

void Simulation::display()
{
	ogstream gout(Position(10.0, ptUpperRight.getPixelsY() - 20.0));

	ground.draw(gout);
	howitzer.draw(gout, simTime);
	
	if (projectile.flying())
	{
		projectile.draw(gout);
	}

	gout.setf(ios::fixed | ios::showpoint);
	gout.precision(1);
	gout << "Time since the bullet was fired: "
		<< simTime << "s\n";
}

void Simulation::input(const Interface* pUI)
{
	// move a large amount
	if (pUI->isRight())
		howitzer.rotate(0.05);//->angle += 0.05;
	if (pUI->isLeft())
		howitzer.rotate(-0.05);

	/*
	// move by a little
	if (pUI->isUp() a)
		pDemo->angle += (pDemo->angle >= 0 ? -0.003 : 0.003);
	if (pUI->isDown())
		pDemo->angle += (pDemo->angle >= 0 ? 0.003 : -0.003);
	*/

	// fire that gun
	if (pUI->isSpace())
	{
		simTime = 0.0;
		fire();
	}
}

void Simulation::setMuzzleVelocity(Velocity velocity)
{

}

void Simulation::setDiameter(double diameter)
{

}

bool Simulation::hitTarget()
{
	return true; // Placeholder
}

double Simulation::getHeightMeters()
{
	return 0.00; // Placeholder
}