#define _USE_MATH_DEFINES

#include "physics.h"
#include <vector>
#include <math.h>
using namespace std;

double getArea(double r)
{
	double a;
	return a = M_PI * pow(r, 2);
}

double getTotalComponent(double x, double y)
{
	double total;
	return total = sqrt(pow(x, 2) + pow(y, 2));
};

double getVerticalComponent(double total, double angleRadians)
{
	double vertical;
	return vertical = total * cos(angleRadians);
}

double getHorizontalComponent(double total, double angleRadians)
{
	double vertical;
	return vertical = total * sin(angleRadians);
}

double getAngleFromComponents(double x, double y)
{
	double angle;
	return angle = atan2(x, y);
}

double linearInterpolation(vector<vector<double>> requiredMap, double d)
{
	bool isFound = false;
	int i = 0;
	while (not isFound)
	{
		if (i > requiredMap.size())
		{
			isFound = false;
		}
		else
		{
			vector<double> currData = requiredMap[i];
			double val1 = currData[0];
			double val2 = currData[1];
			if (i == 0 && d <= val1)
				return val2;
			else if (val1 == d)
			{
				return val2;
			}
			else if (val1 > d)
			{
				int largerIndex = i;
				int smallerIndex = i - 1;
				double d0 = requiredMap[smallerIndex][0];
				double r0 = requiredMap[smallerIndex][1];
				double d1 = requiredMap[largerIndex][0];
				double r1 = requiredMap[largerIndex][1];
				double r = (((r1 - r0) * (d - d0)) / (d1 - d0)) + r0;
				return r;
			}
			i++;
		}
	}
	return 0;
}

double speedOfSoundFromAltitude(double altitude)
{
	vector<vector<double>> soundData
	{
		{    0, 340},
		{ 1000, 336},
		{ 2000, 332},
		{ 3000, 328},
		{ 4000, 324},
		{ 5000, 320},
		{ 6000, 316},
		{ 7000, 312},
		{ 8000, 308},
		{ 9000, 303},
		{10000, 299},
		{15000, 295},
		{20000, 295},
		{25000, 295},
		{30000, 305},
		{40000, 324}
	};

	double vs = linearInterpolation(soundData, altitude);
	return vs;
}

double machFromSpeed(double speed, double altitude)
{
	double vs = speedOfSoundFromAltitude(altitude);
	double vm = speed / vs;
	return vm;
}

double densityFromAltitude(double altitude)
{
	vector<vector<double>> densityData
	{
		{    0, 1.2250000},
		{ 1000, 1.1120000},
		{ 2000, 1.0070000},
		{ 3000, 0.9093000},
		{ 4000, 0.8194000},
		{ 5000, 0.7364000},
		{ 6000, 0.6601000},
		{ 7000, 0.5900000},
		{ 8000, 0.5258000},
		{ 9000, 0.4671000},
		{10000, 0.4135000},
		{15000, 0.1948000},
		{20000, 0.0889100},
		{25000, 0.0400800},
		{30000, 0.0184100},
		{40000, 0.0039960},
		{50000, 0.0010270},
		{60000, 0.0003097},
		{70000, 0.0000828},
		{80000, 0.0000185}
	};

	double density = linearInterpolation(densityData, altitude);
	return density;
}

double dragFromSpeed(double speed, double altitude)
{
	vector<vector<double>> dragData
	{
		{0.300, 0.1629},
		{0.500, 0.1659},
		{0.700, 0.2031},
		{0.890, 0.2597},
		{0.920, 0.3010},
		{0.960, 0.3287},
		{0.980, 0.4002},
		{1.000, 0.4258},
		{1.020, 0.4335},
		{1.060, 0.4483},
		{1.240, 0.4064},
		{1.530, 0.3663},
		{1.990, 0.2897},
		{2.870, 0.2297},
		{2.890, 0.2306},
		{5.000, 0.2656}
	};

	double speedMach = machFromSpeed(speed, altitude);
	double drag = linearInterpolation(dragData, speedMach);
	return drag;
}

double forceFromDrag(double p, double c, double a, double v)
{
	double d = (0.5) * c * p * pow(v, 2) * a;
	return d;
}

double accelerationFromForce(double force, double mass)
{
	double a = force / mass;
	return a;
}

double velocityFromAcceleration(double acceleration, double interval)
{
	double v = acceleration * interval;
	return v;
}

double gravityFromAltitude(double altitude)
{
	vector<vector<double>> gravityData
	{
		{    0, 9.807},
		{ 1000, 9.804},
		{ 2000, 9.801},
		{ 3000, 9.797},
		{ 4000, 9.794},
		{ 5000, 9.791},
		{ 6000, 9.788},
		{ 7000, 9.785},
		{ 8000, 9.782},
		{ 9000, 9.779},
		{10000, 9.776},
		{15000, 9.761},
		{20000, 9.745},
		{25000, 9.730},
	};

	double gravity = linearInterpolation(gravityData, altitude);
	return gravity;
}