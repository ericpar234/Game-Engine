#ifndef EJF_MATH
#define EJF_MATH


#include "Vector3.h"
#include <vector>


#define PI 3.14159


namespace Math
{
	double ConvertToRadians(double degrees);
	double ConvertToDegrees(double radians);
	Vector3 RotatePoint(Vector3 point, Vector3 pivot, float rot);
	float Max(std::vector<float> v);
	float Min(std::vector<float> v);
	float Abs(float x);

	float RandInRange(int max, int min);

}

#endif
