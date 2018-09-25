#pragma once

#pragma region Preprocessors

#include <random>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <math.h>
#include <Windows.h>
#include <IUnityInterface.h>
#include <combaseapi.h>
#define LIBFUNC_API(rtype) UNITY_INTERFACE_EXPORT rtype UNITY_INTERFACE_API
#define MAX_VECTORCALDISTANCE 999999
using namespace std;

#pragma endregion

#pragma region UtilityPrototypes

struct V2 
{ 
	float x, y; 

	V2(float a, float b) : x(a), y(b) {}

	float Magnitude()
	{
		return sqrt(x * x + y * y);
	}

	void Normalize()
	{
		float mag = Magnitude();
		x/= mag;
		y/= mag;
	}
};

struct V3 { 

	float x, y, z;

	V3(float a, float b, float c) : x(a), y(b), z(c) {}


	float Magnitude(V3 v)
	{
		sqrt(x * x + y * y + z * z);
	}

	V3 Normalize(V3 &v)
	{
		float mag = Magnitude(v);
		v.x /= mag;
		v.y /= mag;
		v.z /= mag;
	}
};

float FindDistanceBetweenVectors(V3, V3);
float FindDistanceBetweenVectors(V2, V2);
float GetRandomFloatInRange(float, float);
int GetRandomIntInRange(int, int);
static int sRandFlag = 0;
static std::default_random_engine generator;

#pragma endregion

extern "C"
{

#pragma region Vector Randomization

	LIBFUNC_API(void) RandomizeVector3F(V3*, float, float);
	LIBFUNC_API(void) RandomizeVector3FRange(V3* v, double, double, double, double, double, double);
	LIBFUNC_API(void) RandomizeVector3Int(V3*, int, int);
	LIBFUNC_API(void) RandomizeVector3IntRange(V3*, int, int, int, int, int, int);
	LIBFUNC_API(void) RandomizeVector2F(V2*, double, double);
	LIBFUNC_API(void) RandomizeVector2FRange(V2*, double, double, double, double);								   
	LIBFUNC_API(void) RandomizeVector2Int(V2*, int, int);
	LIBFUNC_API(void) RandomizeVector2IntRange(V2*, int, int, int, int);

#pragma endregion

#pragma region Vector Distance Calculations

	LIBFUNC_API(int) FindClosestV3(V3*, V3, int);
	LIBFUNC_API(int) FindClosestV2(V2*, V2, int);

#pragma endregion

#pragma region Vector Array Calculations

	LIBFUNC_API(V3*) GetPointsBetweenVectorsV3(V3, V3, int&);
	LIBFUNC_API(V2*) GetPointsBetweenVectorsV2(V2, V2, int&);

#pragma endregion

#pragma region Vector Circle Calculations

	LIBFUNC_API(V2) GetRandomPointBetweenTwoConcentricCircles(V2*, V2, int&, int&);

#pragma endregion

}