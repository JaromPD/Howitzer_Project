#include "projectile.h"
#include "position.h"
#include "velocity.h"
#include "ground.h"
#include <iostream>
using namespace std;

Projectile::Projectile() :
	mass(46.7), // Default mass of a M795 155mm shell.
	radius(.15489 / 2), // Default radius of a M795 155mm shell.
	status("live")
{
	// Default constructor
	// Make the list of 20 pvts.

	for (int i = 0; i < 1; i++)
	{
		pvt pvt;
		pvt.p.setPixelsX((double)i * 2.0);
		pvt.p.setPixelsY(700 / 1.5);
		flightPath.push_back(pvt);
	}

}

void Projectile::reset()
{

}

void Projectile::fire(Position pos, double time, Direction angle, Velocity vel)
{
	status = "flying";

	// Initial conditions are set.

	for (int i = 0; i < 1; i++)
	{
		flightPath[i].p.setPixelsX(pos.getPixelsX());
		flightPath[i].p.setPixelsY(pos.getPixelsY());
		flightPath[i].v.setDirection(angle);
		flightPath[i].v.setDxDy(vel.getDX(), vel.getDY());
		cout << vel.getDX() << " | " << vel.getDY() << endl;
	}

}

void Projectile::advance(double interval)
{

	// All of the pvts are updated with physics.
	// (This makes them move pos)
	/*
	for (int i = 0; i < 1; i++)
	{
		Velocity currVel = flightPath[i].v;
		Position currPos = flightPath[i].p;
		double currTime = flightPath[i].t;

		double y = currPos.getPixelsY();
		y += currVel.getDY() / interval;

		double x = currPos.getPixelsX();
		x += currVel.getDX() / interval;
		flightPath[i].p.setPixelsY(y);
		flightPath[i].p.setPixelsX(x);
	}
	*/
	/*******************
	 * WORK IN PROGRESS	
	 *******************/
	
	
	pvt pvt = flightPath.back();
	
	cout << "Pos: (" << pvt.p.getPixelsX() << ", " << pvt.p.getPixelsY() << ") " << " Vel: " << pvt.v.getDX() << " | " << pvt.v.getDY() << endl;
	
	double speed = pvt.v.getSpeed();
	double altitude = pvt.p.getMetersY();

	// MODIFY VELOCITY TO HANDLE WIND RESISTANCE
	double density = densityFromAltitude(altitude);
	double dragCoefficient = dragFromSpeed(speed, altitude);
	double surfaceArea = getArea(radius);
	
	cout << "Speed: " << speed << endl;
	cout << "Density" << density << endl;
	cout << "dragCoefficient: " << dragCoefficient << endl;
	cout << "SurfaceArea: " << surfaceArea << endl;
	
	double windResistance = forceFromDrag(density, dragCoefficient, surfaceArea, speed);
	double accelerationDrag = accelerationFromForce(windResistance, mass);
	Velocity velocityWind(velocityFromAcceleration(accelerationDrag, interval), pvt.v.getDirection());
	
	velocityWind.reverse(); // Needs reversed since wind is resisting the projectile.
	pvt.v += velocityWind;
	
	cout << "Wind Resistance" << windResistance << endl;
	cout << "Wind Velo: " << velocityWind.getDX() << " | " << velocityWind.getDY() << endl;

	// MODIFY VELOCITY TO HANDLE GRAVITY
	double accelerationGravity = gravityFromAltitude(altitude);
	Direction directionGravity;
	directionGravity.setDown();
	Velocity velocityGravity(velocityFromAcceleration(accelerationGravity, interval), directionGravity);
	pvt.v += velocityGravity;
	
	cout << "Gravity Velo: " << velocityGravity.getDX() << " | " << velocityGravity.getDY() << endl;
	
	// INERTIA
	pvt.p.addMetersX(velocityFromAcceleration(pvt.v.getDX(), interval));
	pvt.p.addMetersY(velocityFromAcceleration(pvt.v.getDY(), interval));

	// ADD IT TO THE BACK OF THE FLIGHT PATH
	flightPath.push_back(pvt);
	
	cout << "Advanced" << endl << endl;
}

void Projectile::draw(ogstream& gout)
{
	// All pvts are displayed.

	for (int i = 0; i < 1; i++)
	{
		gout.drawProjectile(flightPath[i].p, 0.5 * (double)i);
	}
}

bool Projectile::flying()
{	
	if (status == "flying")
		return true;
	else
		return false;
}

double Projectile::getAltitude()
{
	return 0.00; // Placeholder
}

Position Projectile::getPosition()
{
	Position pt;  // Placeholder
	return pt; // Placeholder
}

double Projectile::getFlightTime()
{
	return 0.00; // Placeholder
}

double Projectile::getFlightDistance()
{
	return 0.00; // Placeholder
}

double Projectile::getSpeed()
{
	return 0.00; // Placeholder
}

double Projectile::getCurrentTime()
{
	return 0.00; // Placeholder
}

