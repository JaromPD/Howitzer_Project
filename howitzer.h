#pragma once
#include "uiDraw.h"
#include "velocity.h"

class Howitzer
{
	public:

		Howitzer();

		void draw(ogstream &gout, double flightTime);
		Position& getPosition();
		void generatePosition(int size);
		Velocity getMuzzleVelocity();
		void setMuzzleVelocity(Velocity velocity);
		void rotate(double radians);
		void raise(double radians);

	private:

		Position position;
		double muzzleVelocity;
		Direction elevation;
};

