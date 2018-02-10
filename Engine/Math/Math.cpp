#include "Math.h"
#include <math.h>
#include <vector>

namespace Math
{
	double ConvertToRadians (double degrees)
	{
		return (degrees * PI) / 100;
	}
	
	double ConvertToDegrees(double radians)
	{
		return (radians * 180) / PI;
	}

	Vector3 RotatePoint(Vector3 point, Vector3 pivot, float rot)
	{
		double radRot = ConvertToRadians(rot);
		double s = sin(radRot);
		double c = cos(radRot);

		point = point - pivot;

		float newX = (float)(point.x * c - point.y * s);
		float newY = (float)(point.x * s + point.y * c);

		point.x = newX + pivot.x;
		point.y = newY + pivot.y;

		return point;
	}

	float Max(std::vector<float> v)
	{
		float retVal = v[0];

		for (int i = 1; i < v.size(); i++)
		{
			if (v[i] > retVal)
			{
				retVal = v[i];
			}
		}
		return retVal;

	}

	float Min(std::vector<float> v)
	{
		float retVal = v[0];

		for (unsigned int i = 1; i < v.size(); i++)
		{
			if (v[i] < retVal)
			{
				retVal = v[i];
			}
		}
		return retVal;
	}

	float Abs(float x)
	{
		if (x > 0)
			return x;
		else
			return -x;
	}

	float RandInRange(int max, int min)
	{
		return rand() % (max - min) + min;
	}



}