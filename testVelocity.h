#pragma once
#include "velocity.h"
#define _USE_MATH_DEFINES
#include <math.h>

class TestVelocity
{
public:
	void run()
	{
		defaultConstructor();

		getDirectionUp();
		getDirectionRight();
		getDirectionUpRight();
		getDirectionLeft();
		getDirectionDown();
		
		reverseUpRight();
		reverseRight();

		addVelocityUpRight();
		addVelocityDownRight();
		addVelocityUpLeft();
		addVelocityDownLeft();
	}
	
private:
	void defaultConstructor()
	{
		// Setup
		// Excercise
		Velocity v;
		// Verify
		assert(v.dx == 0.00);
		assert(v.dy == 0.00);
		// Teardown
	}

	void getDirectionUp()
	{
		// Setup
		Velocity v;
		v.setDxDy(0.0, 1.0);
		// Excercise
		//Verify
		assert(v.getDirection().radians == 0);
		// Teardown
	}

	void getDirectionRight()
	{
		// Setup
		Velocity v;
		v.setDxDy(1.0, 0.0);
		// Excercise
		// Verify
		assert(v.getDirection().radians == (M_PI / 2));
		// Teardown
	}

	void getDirectionUpRight()
	{
		// Setup
		Velocity v;
		v.setDxDy(1.0, 1.0);
		// Excercise
		// Verify
		assert(v.getDirection().radians == (M_PI / 4));
		// Teardown
	}

	void getDirectionLeft()
	{
		// Setup
		Velocity v;
		v.setDxDy(-1.0, 0.0);
		// Excercise
		// Verify
		assert(v.getDirection().radians == ((3 * M_PI) / 2));
		// Teardown
	}

	void getDirectionDown()
	{
		// Setup
		Velocity v;
		v.setDxDy(0.0, -1.0);
		// Excercise
		// Verify
		assert(v.getDirection().radians == M_PI);
		// Teardown
	}

	void reverseUpRight()
	{
		// Setup
		Velocity v;
		v.setDxDy(1.0, 1.0);
		// Excercise
		v.reverse();
		// Verify
		assert(v.dx == -1.0 and v.dy == -1.0);
		// Teardown
	}

	void reverseRight()
	{
		// Setup
		Velocity v;
		v.setDxDy(1.0, 0.0);
		// Excercise
		v.reverse();
		// Verify
		assert(v.dx == -1.0 and v.dy == 0.0);
		// Teardown
	}

	void addVelocityUpRight()
	{
		// Setup
		Velocity v;
		v.setDxDy(1.0, 0.0);
		// Exercise
		v.addDY(1.0);
		// Verify
		assert(v.dx == 1.0 and v.dy == 1.0);
		// Teardown
	}

	void addVelocityDownRight()
	{
		// Setup
		Velocity v;
		v.setDxDy(4.0, 0.0);
		// Excercise
		v.addDY(-3.0);
		// Verify
		assert(v.dx == 4.0 and v.dy == -3.0);
		// Teardown
	}

	void addVelocityUpLeft()
	{
		// Setup
		Velocity v;
		v.setDxDy(-1.0, 1.0);
		// Exercise
		v.addDY(1.0);
		// Verify
		assert(v.dx == -1.0 and v.dy == 2.0);
		// Teardown
	}

	void addVelocityDownLeft()
	{
		// Setup
		Velocity v;
		v.setDxDy(-4.0, 0.0);
		// Excercise
		v.addDY(-3.0);
		// Verify
		assert(v.dx == -4.0 and v.dy == -3.0);
		// Teardown
	}
};

