 #pragma once
#include <vector>
#include <string>
#include "velocity.h"
#include "uiDraw.h"
using namespace std;

class Projectile
{
	public:

		Projectile();
		
		void reset();
		void fire(Position pos, double time, Direction angle, Velocity vel);
		void advance(double time);
		void draw(ogstream& gout);
		void groundProjectile();
		bool flying();
		double getAltitude();
		Position getPosition();
		double getFlightTime();
		double getFlightDistance();
		double getSpeed();
		double getCurrentTime();
		string getStatus() { return status; }
		void setMass(double mass) { this->mass = mass; };
		void setRadius(double radius) { this->radius = radius; };

	private:
		
		struct pvt {
			Position p;
			Velocity v;
			double t;
		};

		double mass;
		double radius;
		string status;
		vector<pvt> flightPath;
		
};

