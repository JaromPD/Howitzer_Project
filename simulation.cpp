#include <iostream>
#include "simulation.h"
using namespace std;

Simulation::Simulation(Position ptUpperRight) :
	ptUpperRight(ptUpperRight),
	ground(ptUpperRight),
	simTime(0.0),
	stageCount(0)
{
	ground.reset(howitzer.getPosition());
}

void Simulation::advance()
{
	cout << "[" << projectile.getPosition().getPixelsX() << " | " << projectile.getPosition().getPixelsY() << "]" << endl;
	cout << "ELEVATION: " << ground.getElevationMeters(projectile.getPosition()) << endl;
	simTime += interval;
	if (projectile.flying())
	{
		projectile.advance(interval);
		if (hitTarget())
		{
			reset();
		}
		else if (projectile.getPosition().getMetersY() <= ground.getElevationMeters(projectile.getPosition()))
		{
			projectile.groundProjectile();
		}
	}
}

void Simulation::reset()
{
	projectile.groundProjectile();
	ground.reset(howitzer.getPosition());
	stageCount++;
}

void Simulation::fire()
{
	cout << "***" << howitzer.getMuzzleVelocity().getSpeed() << "***" << endl;;
	if (projectile.getStatus() == "grounded")
	{
		projectile.reset();
		projectile.fire(howitzer.getPosition(), simTime, howitzer.getMuzzleVelocity().getDirection(), howitzer.getMuzzleVelocity());
	}
}

void Simulation::display()
{
	ogstream gout(Position(10.0, ptUpperRight.getPixelsY() - 20.0));

	howitzer.draw(gout, simTime);
	ground.draw(gout);
	if (projectile.flying())
	{
		projectile.draw(gout);
	}

	gout.setPosition(Position(3000, 18000));
	gout.setf(ios::fixed | ios::showpoint);
	gout.precision(1);

	// Display Howitzer status
	gout << "Howitzer Status: ";
	if (projectile.getStatus() == "flying")
		gout << "Reloading...";
	else
		gout << "Ready to Fire";
	gout << endl;

	// Display altitude.
	if (projectile.getStatus() == "flying")
	{
		gout << "Alt: ";
		gout << projectile.getPosition().getMetersY() - ground.getElevationMeters(projectile.getPosition()) << endl;
	}

	// Display Speed
	if (projectile.getStatus() == "flying")
	{
		gout << "Speed: ";
		gout << projectile.getSpeed() << endl;
	}

	// Display Distance
	if (projectile.getStatus() == "flying")
	{
		gout << "Distance: ";
		gout << projectile.getPosition().getMetersX() - howitzer.getPosition().getMetersX() << endl;
	}

	// DisplayHangtime
	if (projectile.getStatus() == "flying")
	{
		gout << "Hangtime: ";
		gout << simTime << endl;
	}

	if (projectile.getStatus() == "grounded")
	{
		gout << "Angle: ";
		gout << howitzer.getElevation().getDegrees() << endl;
	}

	gout << "Stage: " << stageCount << "\n";
}

void Simulation::input(const Interface* pUI)
{
	// move a large amount
	if (pUI->isRight())
		howitzer.rotate(0.05);//->angle += 0.05;
	if (pUI->isLeft())
		howitzer.rotate(-0.05);

	if (pUI->isUp())
		howitzer.rotate(0.003);
	if (pUI->isDown())
		howitzer.rotate(-0.003);

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
	if ((ground.getTarget().getPixelsX() -10 <= projectile.getPosition().getPixelsX() 
		and 
		projectile.getPosition().getPixelsX() <= ground.getTarget().getPixelsX() + 10)
		and
		(ground.getTarget().getPixelsY() -10 <= projectile.getPosition().getPixelsY() 
		and 
		projectile.getPosition().getPixelsY() <= ground.getTarget().getPixelsY() + 10))
	{
		return true;
	}
	else
		return false;
}

double Simulation::getHeightMeters()
{
	return 0.00; // Placeholder
}