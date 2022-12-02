#pragma once
#include "Direction.h"
#include <assert.h>
#define _USE_MATH_DEFINES
#include <math.h>

class TestDirection
{
public:
	void run()
	{
		defaultConstructor();

		setRadiansZero();
		setRadiansPi();
		setRadians2Pi();
		setRadians3Pi();
		setRadiansNegPi();

		setDegreesZero();
		setDegrees180();
		setDegrees360();
		setDegrees540();
		setDegreesNeg180();

		reverseZero();
		reversePi();
		reversePiHalf();
		reverse3Pi();
		reverseNegPiHalf();

		getDegreesZero();
		getDegreesPi();
		getDegrees2Pi();
		getDegrees3Pi();
		getDegreesNegPi();

		getRadiansZeroPi();
		getRadiansPi();
		getRadians2Pi();
		getRadians3Pi();
		getRadiansNegPi();

		setDown();
		setUp();
		setLeft();
		setRight();

	}
private:

	void defaultConstructor()
	{
		// Setup
		// Excercise
		Direction d;
		// Verify
		assert(d.radians == 0.00);
		// Teardown
	}

	void setRadiansZero()
	{
		// Setup
		Direction d;
		// Excercise
		d.setRadians(0);
		// Verify
		assert(d.radians == 0);
		// Teardown
	}

	void setRadiansPi()
	{
		// Setup
		Direction d;
		// Excercise
		d.setRadians(M_PI);
		// Verify
		assert(d.radians == M_PI);
		// Teardown
	}

	void setRadians2Pi()
	{
		// Setup
		Direction d;
		// Excercise
		d.setRadians(2 * M_PI);
		// Verify
		assert(d.radians == 0);
		// Teardown
	}

	void setRadians3Pi()
	{
		// Setup
		Direction d;
		// Excercise
		d.setRadians(3 * M_PI);
		// Verify
		assert(d.radians == M_PI);
		// Teardown
	}

	void setRadiansNegPi()
	{
		// Setup
		Direction d;
		// Excercise
		d.setRadians(-M_PI);
		// Verify
		assert(d.radians == M_PI);
		// Teardown
	}

	void setDegreesZero()
	{
		// Setup
		Direction d;
		// Excercise
		d.setDegrees(0);
		// Verify
		assert(d.radians == 0);
		// Teardown
	}

	void setDegrees180()
	{
		// Setup
		Direction d;
		// Excercise
		d.setDegrees(180);
		// Verify
		assert(d.radians == M_PI);
		// Teardown
	}

	void setDegrees360()
	{
		// Setup
		Direction d;
		// Excercise
		d.setDegrees(360);
		// Verify
		assert(d.radians == 0);
		// Teardown
	}

	void setDegrees540()
	{
		// Setup
		Direction d;
		// Excercise
		d.setDegrees(540);
		// Verify
		assert(d.radians == M_PI);
		// Teardown
	}

	void setDegreesNeg180()
	{
		// Setup
		Direction d;
		// Excercise
		d.setDegrees(-180);
		// Verify
		assert(d.radians == M_PI);
		// Teardown
	}

	void reverseZero()
	{
		// Setup
		Direction d;
		d.radians = 0;
		// Excercise
		d.reverse();
		// Verify
		assert(d.radians == M_PI);
		// Teardown
	}

	void reversePi()
	{
		// Setup
		Direction d;
		d.radians = M_PI;
		// Excercise
		d.reverse();
		// Verify
		assert(d.radians == 0);
		// Teardown
	}

	void reversePiHalf()
	{
		// Setup
		Direction d;
		d.radians = M_PI / 2;
		// Excercise
		d.reverse();
		// Verify
		assert(d.radians == (3 * M_PI) / 2);
		// Teardown
	}

	void reverse3Pi()
	{
		// Setup
		Direction d;
		d.radians = 3 * M_PI;
		// Excercise
		d.reverse();
		// Verify
		assert(d.radians == 2 * M_PI);
		// Teardown
	}

	void reverseNegPiHalf()
	{
		// Setup
		Direction d;
		d.radians = -1 * (M_PI / 2);
		// Excercise
		d.reverse();
		// Verify
		assert(d.radians == (M_PI / 2));
		// Teardown
	}

	void getDegreesZero()
	{
		// Setup
		Direction d;
		d.radians = 0;
		// Excercise
		// Verify
		assert(d.getDegrees() == 0);
		// Teardown
	}

	//void getDegreesZero()
	//{
		// Setup
		//Direction d;
		//d.radians = 0;
		// Excercise
		// Verify
		//assert(d.getDegrees() == 0);
		// Teardown
	//}

	void getDegreesPi()
	{
		// Setup
		Direction d;
		d.radians = M_PI;
		// Excercise
		// Verify
		assert(d.getDegrees() == 180);
		// Teardown
	}

	void getDegrees2Pi()
	{
		// Setup
		Direction d;
		d.radians = 2 * M_PI;
		// Excercise
		// Verify
		assert(d.getDegrees() == 0);
		// Teardown
	}

	void getDegrees3Pi()
	{
		// Setup
		Direction d;
		d.radians = 3 * M_PI;
		// Excercise
		// Verify
		assert(d.getDegrees() == 180);
		// Teardown
	}

	void getDegreesNegPi()
	{
		// Setup
		Direction d;
		d.radians = -M_PI;
		// Excercise
		// Verify
		assert(d.getDegrees() == 180);
		// Teardown
	}

	void getRadiansZeroPi()
	{
		// Setup
		Direction d;
		d.radians = 0;
		// Excercise
		// Verify
		assert(d.getRadians() == 0);
		// Teardown
	}

	void getRadiansPi()
	{
		// Setup
		Direction d;
		d.radians = M_PI;
		// Excercise
		// Verify
		assert(d.getRadians() == M_PI);
		// Teardown
	}

	void getRadians2Pi()
	{
		// Setup
		Direction d;
		d.radians = 2 * M_PI;
		// Excercise
		// Verify
		assert(d.getRadians() == 2 * M_PI);
		// Teardown
	}

	void getRadians3Pi()
	{
		// Setup
		Direction d;
		d.radians = 3 * M_PI;
		// Excercise
		// Verify
		assert(d.getRadians() == 3 * M_PI);
		// Teardown
	}

	void getRadiansNegPi()
	{
		// Setup
		Direction d;
		d.radians = -1 * M_PI;
		// Excercise
		// Verify
		assert(d.getRadians() == -1 * M_PI);
		// Teardown
	}

	void setDown()
	{
		// Setup
		Direction d;
		d.radians = 1;
		// Excercise
		d.setDown();
		// Verify
		assert(d.getRadians() == M_PI);
		// Teardown
	}

	void setUp()
	{
		// Setup
		Direction d;
		d.radians = 1;
		// Excercise
		d.setUp();
		// Verify
		assert(d.getRadians() == 0);
		// Teardown
	}

	void setLeft()
	{
		// Setup
		Direction d;
		d.radians = 1;
		// Excercise
		d.setLeft();
		// Verify
		assert(d.getRadians() == 3 * (M_PI /2));
		// Teardown
	}

	void setRight()
	{
		// Setup
		Direction d;
		d.radians = 1;
		// Excercise
		d.setRight();
		// Verify
		assert(d.getRadians() == M_PI / 2);
		// Teardown
	}

	friend class main;

};

