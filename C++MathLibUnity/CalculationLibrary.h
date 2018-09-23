#pragma once

#include <IUnityInterface.h>

#define LIBFUNC_API(rtype) UNITY_INTERFACE_EXPORT rtype UNITY_INTERFACE_API
//double FindDistanceBetweenVector3s(V3*, V3*);

double Randomizedoubles(double, double);
int RandomizeInts(int, int);
struct V2 { float x, y; };
struct V3 { double x, y, z; };

extern "C"
{

#pragma region VectorRandomization

	/*LIBFUNC_API void RandomizeVector3double(V3*, double, double);
	LIBFUNC_API void RandomizeVector3doubleRange(V3* v, double, double, double, double, double, double);

	LIBFUNC_API void RandomizeVector3Int(V3*, int, int);
	LIBFUNC_API void RandomizeVector3IntRange(V3*, int, int, int, int, int, int);

	LIBFUNC_API void RandomizeVector2double(V2*, double, double);
	LIBFUNC_API void RandomizeVector2doubleRange(V2*, double, double, double, double);								   
	LIBFUNC_API void RandomizeVector2Int(V2*, int, int);
	LIBFUNC_API void RandomizeVector2IntRange(V2*, int, int, int, int);

	LIBFUNC_API V3* FindClosest(V3*, V3*, int);*/

	//LIBFUNC_API(V3 *) FindClosest(int);

#pragma endregion

}