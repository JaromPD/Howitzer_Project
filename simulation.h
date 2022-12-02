#pragma once
#include "uiInteract.h"
#include "velocity.h"
#include "howitzer.h"
#include "projectile.h"
#include "ground.h"

class Simulation
{
	public:

		Simulation(Position ptUpperRight);

		void reset();
		void fire();
		void display();
		void advance() { simTime += interval; };
		void input(const Interface* pUI);
		void setInterval(double interval) { this->interval = interval; }
		void setMuzzleVelocity(Velocity velocity); // velocity may be type double instead.
		void setDiameter(double diameter);

	private:

		// Attributes

		double interval;
		Howitzer howitzer;
		Projectile projectile;
		//Statue status; 
		//Unsure what type "Statue" as shown in example class diagram means.
		double simTime;
		Ground ground;
		Position ptUpperRight; // May not be neccesary. 

		// Private Methods

		bool hitTarget(); // Might not be bool type.
		double getHeightMeters();
};

