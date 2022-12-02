#pragma once
class Direction
{
	public:
		
		Direction() : radians(0.00) {};

		void assign(Direction rhs);
		void setRadians(double radians); // double rhs is paramter in given diagram.
		void setDegrees(double degrees); // double rhs is paramter in given diagram.
		void setDxDy(double dx, double dy);
		void setDown();
		void setUp();
		void setRight();
		void setLeft();
		void reverse();
		double getRadians() { return radians; };
		double getDegrees();
		double getDX();
		double getDY();

	private:

		double radians;

		friend class TestVelocity;
		friend class TestDirection;
};

