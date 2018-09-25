#include "stdafx.h"
#include "CalculationLibrary.h"

#define LIBFUNC_API(rtype) UNITY_INTERFACE_EXPORT rtype UNITY_INTERFACE_API


#pragma region Utility

/// <summary> Finds and returns the distance between two 3 dimensional points. </summary>
float FindDistanceBetweenVectors(V3 p1, V3 p2)
{
	float vecx = p1.x - p2.x;
	float vecy = p1.y - p2.y;
	float vecz = p1.z - p2.z;
	float sqr = sqrt(vecx * vecx + vecy * vecy + vecz * vecz);
	return sqr;
}

/// <summary> Finds and returns the distance between two 2 dimensional points. </summary>
float FindDistanceBetweenVectors(V2 p1, V2 p2)
{
	float vecx = p1.x - p2.x;
	float vecy = p1.y - p2.y;
	return vecx * vecx + vecy * vecy;
}

/// <summary> Returns a float value randomized between the min and max arguments. Both are inclusive.</summary>
float GetRandomFloatInRange(float min, float max)
{
	// Check whether min is bigger than the max, in such case, switch them. Return min directly if they equal to each other.
	if (min > max)
	{
		float tempMax = max;
		max = min;
		min = tempMax;
	}
	else if (min == max) return min;

	// Make sure that randomization seed is set to change every second properly. Call only once via flag check on a static variable to make sure the seed doesnt stay the same.
	if (sRandFlag == 0)
	{
		sRandFlag = 1;
		srand(time(NULL));
	}

	// Use the rand() and equate with min & max to get a random number through the seed.
	float r = min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
	return r;
}

/// <summary> Returns an int value randomized between the min and max arguments. Both are inclusive.</summary>
int GetRandomIntInRange(int min, int max)
{
	// Check whether min is bigger than the max, in such case, switch them. Return min directly if they equal to each other.
	if (min > max)
	{
		int tempMax = max;
		max = min;
		min = tempMax;
	}
	else if (min == max) return min;

	// Get random & return.
	std::uniform_int_distribution<int> distribution(min, max);
	int random = distribution(generator);
	return random;
}

#pragma endregion


// Externalized methods to be called from Unity.
extern "C"
{

#pragma region Vector Randomization

	/* Randomization functions for vectors. Mins and maxes are inclusive. */
	void RandomizeVector3F(V3* v, float min, float max)
	{
		v->x = GetRandomFloatInRange(min, max);
		v->y = GetRandomFloatInRange(min, max);
		v->z = GetRandomFloatInRange(min, max);
	}
	void RandomizeVector3FRange(V3* v, double minX, double maxX, double minY, double maxY, double minZ, double maxZ)
	{
		v->x = GetRandomFloatInRange(minX, maxX);
		v->y = GetRandomFloatInRange(minY, maxY);
		v->z = GetRandomFloatInRange(minZ, maxZ);
	}
	void RandomizeVector3Int(V3* v, int min, int max)
	{
		v->x = GetRandomIntInRange(min, max);
		v->y = GetRandomIntInRange(min, max);
		v->z = GetRandomIntInRange(min, max);
	}
	void RandomizeVector3IntRange(V3* v, int minX, int maxX, int minY, int maxY, int minZ, int maxZ)
	{
		v->x = GetRandomIntInRange(minX, maxX);
		v->y = GetRandomIntInRange(minY, maxY);
		v->z = GetRandomIntInRange(minZ, maxZ);
	}
	void RandomizeVector2F(V2* v, double min, double max)
	{
		v->x = GetRandomFloatInRange(min, max);
		v->y = GetRandomFloatInRange(min, max);
	}
	void RandomizeVector2FRange(V2* v, double minX, double maxX, double minY, double maxY)
	{
		v->x = GetRandomFloatInRange(minX, maxX);
		v->y = GetRandomFloatInRange(minY, maxY);
	}
	void RandomizeVector2Int(V2* v, int min, int max)
	{
		v->x = GetRandomIntInRange(min, max);
		v->y = GetRandomIntInRange(min, max);
	}
	void RandomizeVector2IntRange(V2* v, int minX, int maxX, int minY, int maxY)
	{
		v->x = GetRandomIntInRange(minX, maxX);
		v->y = GetRandomIntInRange(minY, maxY);
	}

#pragma endregion

#pragma region Vector Distance Calculations

	/// <summary> Iterates through an array of points and finds the closest one to a given one. Returns the index of the closest one.
	/// Maximum Distance it can calculate is : 999.999</summary>
	int FindClosestV3(V3* vectorArray, V3 comparisonVector, int size)
	{
		int closestIndex = 0;
		float closestDistance = MAX_VECTORCALDISTANCE;
		float currentDistance = 0;

		// Iterate through distances and check & record the closest.
		for (int i = 0; i < size; i++)
		{
			currentDistance = FindDistanceBetweenVectors(vectorArray[i], comparisonVector);

			if (currentDistance < closestDistance)
			{
				closestIndex = i;
				closestDistance = currentDistance;
			}
		}

		return closestIndex;
	}

	/// <summary> Iterates through an array of points and finds the closest one to a given one. Returns the index of the closest one.
	/// Maximum Distance it can calculate is : 999.999</summary>
	int FindClosestV2(V2* vectorArray, V2 comparisonVector, int size)
	{
		int closestIndex = 0;
		float closestDistance = MAX_VECTORCALDISTANCE;
		float currentDistance = 0;

		// Iterate through distances and check & record the closest.
		for (int i = 0; i < size; i++)
		{
			currentDistance = FindDistanceBetweenVectors(vectorArray[i], comparisonVector);

			if (currentDistance < closestDistance)
			{
				closestIndex = i;
				closestDistance = currentDistance;
			}
		}

		return closestIndex;
	}

#pragma endregion

#pragma region Vector Array Calculations

	/// <summary> Returns a pointer pointing to the first element of dynamically allocated array which contains given amount of points between the start & end points.</summary>
	V3* GetPointsBetweenVectorsV3(V3 start, V3 end, int& size)
	{
		// Return a null pointer if the size is 0 or neg.
		if (size < 1)
			return nullptr;

		// Allocate mem for array.
		V3* pointArray = (V3*)CoTaskMemAlloc(sizeof(V3) * size);
		
		// Calculate intervals for incrementation.
		float intervalX = (end.x - start.x) / (size + 1);
		float intervalY = (end.y - start.y) / (size + 1);
		float intervalZ = (end.z - start.z) / (size + 1);

		// Iterate & fill the array with incrementations by intervals.
		for (int i = 0; i <= size; i++)
		{
			pointArray[i] = { start.x + intervalX * (i+1), start.y + intervalY * (i+1), start.z + intervalZ * (i+1) };
		}

		return pointArray;

	}

	/// <summary> Returns a pointer pointing to the first element of dynamically allocated array which contains given amount of points between the start & end points.</summary>
	V2* GetPointsBetweenVectorsV2(V2 start, V2 end, int& size)
	{
		// Return a null pointer if the size is 0 or neg.
		if (size < 1)
			return nullptr;

		// Allocate mem for array.
		V2* pointArray = (V2*)CoTaskMemAlloc(sizeof(V2) * size);

		// Calculate intervals for incrementation.
		float intervalX = (end.x - start.x) / (size + 1);
		float intervalY = (end.y - start.y) / (size + 1);

		// Iterate & fill the array with incrementations by intervals.
		for (int i = 0; i <= size; i++)
		{
			pointArray[i] = { start.x + intervalX * (i + 1), start.y + intervalY * (i + 1) };
		}

		return pointArray;

	}

#pragma endregion


#pragma region Vector Circle Calculations

	void GetRandomPointBetweenTwoConcentricCircles(V2* inVector, V2 offset, int& rad1, int& rad2) 
	{
		// Ensure that rad2 will be the bigger radius.
		if (rad1 > rad2)
		{
			int tempRad1 = rad1;
			rad1 = rad2;
			rad2 = tempRad1;
		}

		// Get a random point in a 1 radius circle.
		V2 randomUnitPoint = V2(GetRandomFloatInRange(0.0f, 1.0f), GetRandomFloatInRange(0.0f, 1.0f));

		// Normalize the point, making it's length 1, scaling its components.
		randomUnitPoint.Normalize();

		// Assign the in vector with random point over the are between the circles and add offset.
		inVector->x = offset.x + (rad1 * randomUnitPoint.x + GetRandomFloatInRange(0.0f, 1.0f) * ((randomUnitPoint.x * rad2) - (randomUnitPoint.x * rad1)));
		inVector->y = offset.y + (rad1 * randomUnitPoint.y + GetRandomFloatInRange(0.0f, 1.0f) * ((randomUnitPoint.y * rad2) - (randomUnitPoint.y * rad1)));

	}

#pragma endregion
}