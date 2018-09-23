#include "stdafx.h"
#include <stdlib.h>     /* srand, rand */
#include <math.h>
#include <IUnityInterface.h>
#include <Windows.h>
#include "CalculationLibrary.h"

#define LIBFUNC_API(rtype) UNITY_INTERFACE_EXPORT rtype UNITY_INTERFACE_API


#pragma region Utility

/*double FindDistanceBetweenVector3s(V3* p1, V3* p2)
{
	// Store the differences.
	double xDiff = p1->x - p2->x;
	double yDiff = p1->y - p2->y;
	double zDiff = p1->z - p2->z;

	// Store the powers of the differences to the 2.
	double powX = pow(xDiff, 2);
	double powY = pow(yDiff, 2);
	double powZ = pow(zDiff, 2);

	// Apply the distance formula.
	return sqrt(powX + powY + powZ);
}*/

double FindDistanceBetweenVector2s(V3* p1, V3* p2)
{
	// Store the differences.
	double xDiff = p1->x - p2->x;
	double yDiff = p1->y - p2->y;

	// Store the powers of the differences to the 2.
	double powX = pow(xDiff, 2);
	double powY = pow(yDiff, 2);

	// Apply the distance formula.
	return sqrt(powX + powY);
}

double Randomizedoubles(double min, double max)
{
	double random = ((double)rand()) / (double)max;
	double diff = max - min;
	double r = random * diff;
	return min + r;
}

int RandomizeInts(int min, int max)
{
	return rand() % min + max;
}

#pragma endregion



extern "C"
{

#pragma region VectorRandomization

	/* Randomization functions for vectors. */

	// Vector3 randomization methods & overloads for double and integer, as well as per property randomization & all around randomization.
/*	void RandomizeVector3double(V3* v, double min, double max)
	{
		v->x = Randomizedoubles(min, max);
		v->y = Randomizedoubles(min, max);
		v->z = Randomizedoubles(min, max);
	}
	void RandomizeVector3doubleRange(V3* v, double minX, double maxX, double minY, double maxY, double minZ, double maxZ)
	{
		v->x = Randomizedoubles(minX, maxX);
		v->y = Randomizedoubles(minY, maxY);
		v->z = Randomizedoubles(minZ, maxZ);
	}
	void RandomizeVector3Int(V3* v, int min, int max)
	{
		v->x = RandomizeInts(min, max);
		v->y = RandomizeInts(min, max);
		v->z = RandomizeInts(min, max);
	}
	void RandomizeVector3IntRange(V3* v, int minX, int maxX, int minY, int maxY, int minZ, int maxZ)
	{
		v->x = RandomizeInts(minX, maxX);
		v->y = RandomizeInts(minY, maxY);
		v->z = RandomizeInts(minZ, maxZ);
	}

	// Vector2 randomization methods & overloads for double and integer, as well as per property randomization & all around randomization.
	void RandomizeVector2double(V2* v, double min, double max)
	{
		v->x = Randomizedoubles(min, max);
		v->y = Randomizedoubles(min, max);
	}
	void RandomizeVector2doubleRange(V2* v, double minX, double maxX, double minY, double maxY)
	{
		v->x = Randomizedoubles(minX, maxX);
		v->y = Randomizedoubles(minY, maxY);
	}
	void RandomizeVector2Int(V2* v, int min, int max)
	{
		v->x = RandomizeInts(min, max);
		v->y = RandomizeInts(min, max);
	}
	void RandomizeVector2IntRange(V2* v, int minX, int maxX, int minY, int maxY)
	{
		v->x = RandomizeInts(minX, maxX);
		v->y = RandomizeInts(minY, maxY);
	}
	*/
#pragma endregion

	LIBFUNC_API(V3) FindClosest(V3* first, int size)
	{
		
		V3* closestPoint = (V3*)malloc(sizeof(V3*));
		closestPoint->x = 12;
		//closestPoint = first + size;
		return *(closestPoint);
		
	}

}