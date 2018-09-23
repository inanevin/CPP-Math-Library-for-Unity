#include "stdafx.h"
#include <stdlib.h>     /* srand, rand */
#include "CalculationLibrary.h"

#pragma region Utility

float RandomizeFloats(float min, float max)
{
	float random = ((float)rand()) / (float)max;
	float diff = max - min;
	float r = random * diff;
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

	// Vector3 randomization methods & overloads for float and integer, as well as per property randomization & all around randomization.
	void RandomizeVector3(V3* v, float min, float max)
	{
		v->x = RandomizeFloats(min, max);
		v->y = RandomizeFloats(min, max);
		v->z = RandomizeFloats(min, max);
	}
	void RandomizeVector3(V3* v, float minX, float maxX, float minY, float maxY, float minZ, float maxZ)
	{
		v->x = RandomizeFloats(minX, maxX);
		v->y = RandomizeFloats(minY, maxY);
		v->z = RandomizeFloats(minZ, maxZ);
	}
	void RandomizeVector3(V3* v, int min, int max)
	{
		v->x = RandomizeInts(min, max);
		v->y = RandomizeInts(min, max);
		v->z = RandomizeInts(min, max);
	}
	void RandomizeVector3(V3* v, int minX, int maxX, int minY, int maxY, int minZ, int maxZ)
	{
		v->x = RandomizeInts(minX, maxX);
		v->y = RandomizeInts(minY, maxY);
		v->z = RandomizeInts(minZ, maxZ);
	}

	// Vector2 randomization methods & overloads for float and integer, as well as per property randomization & all around randomization.
	void RandomizeVector2(V2* v, float min, float max)
	{
		v->x = RandomizeFloats(min, max);
		v->y = RandomizeFloats(min, max);
	}
	void RandomizeVector2(V2* v, float minX, float maxX, float minY, float maxY)
	{
		v->x = RandomizeFloats(minX, maxX);
		v->y = RandomizeFloats(minY, maxY);
	}
	void RandomizeVector2(V2* v, int min, int max)
	{
		v->x = RandomizeInts(min, max);
		v->y = RandomizeInts(min, max);
	}
	void RandomizeVector2(V2* v, int minX, int maxX, int minY, int maxY)
	{
		v->x = RandomizeInts(minX, maxX);
		v->y = RandomizeInts(minY, maxY);
	}

#pragma endregion

}