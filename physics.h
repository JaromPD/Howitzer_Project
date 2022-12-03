#include <vector>
using namespace std;

double getArea(double r);

double getTotalComponent(double x, double y);
double getVerticalComponent(double total, double angleRadians);
double getHorizontalComponent(double total, double angleRadians);
double getAngleFromComponents(double x, double y);

double linearInterpolation(vector<vector<double>> requiredMap, double d);
double machFromSpeed(double speed, double altitude);

double speedOfSoundFromAltitude(double altitdue);
double densityFromAltitude(double altitude);
double dragFromSpeed(double speed, double altitude);
double forceFromDrag(double density, double dragCoefficient, double radius, double speed);
double accelerationFromForce(double force, double mass);
double velocityFromAcceleration(double acceleration, double interval);
double gravityFromAltitude(double altitude);
