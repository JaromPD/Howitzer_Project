#include "projectile.h"
#include "position.h"
#include "velocity.h"
#include "ground.h"

Projectile::Projectile() :
	mass(46.7), // Default mass of a M795 155mm shell.
	radius(154.89 / 2) // Default radius of a M795 155mm shell.
{
	// Default constructor
}

void Projectile::reset()
{

}

void Projectile::fire(double pos, double time, double angle, double vel)
{
	
}

void Projectile::advance(double interval)
{
	/*******************
	 * WORK IN PROGRESS	
	 *******************/
	
	
	pvt pvt = flightPath.back();
	double speed = pvt.v.getSpeed();
	double altitude = pvt.p.getMetersY();

	// MODIFY VELOCITY TO HANDLE WIND RESISTANCE
	double density = densityFromAltitude(altitude);
	double dragCoefficient = dragFromSpeed(speed, altitude);
	double windResistance = forceFromDrag(density, dragCoefficient, radius, speed);
	double accelerationDrag = accelerationFromForce(windResistance, mass);
	Velocity velocityWind(velocityFromAcceleration(accelerationDrag, interval), pvt.v.getDirection());
	
	velocityWind.reverse(); // Needs reversed since wind is resisting the projectile.
	pvt.v += velocityWind;
	
	// MODIFY VELOCITY TO HANDLE GRAVITY
	double accelerationGravity = gravityFromAltitude(altitude);
	Direction directionGravity;
	directionGravity.setDown();
	Velocity velocityGravity(velocityFromAcceleration(accelerationGravity, interval), directionGravity);
	pvt.v += velocityGravity;
	
	// INERTIA
	pvt.p.addMetersX(velocityFromAcceleration(pvt.v.getDX(), interval));
	pvt.p.addMetersY(velocityFromAcceleration(pvt.v.getDY(), interval));

	// ADD IT TO THE BACK OF THE FLIGHT PATH
	flightPath.push_back(pvt);

}

void Projectile::draw(ogstream& gout)
{
	for (int i = 0; i < 20; i++)
	{
		gout.drawProjectile(flightPath[i].p, 0.5 * (double)i);
	}
}

bool Projectile::flying()
{
	
	if (getAltitude() <= 0) {
		return false;
	}
	else {
		return true;
	}

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

