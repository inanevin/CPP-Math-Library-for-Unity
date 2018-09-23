#pragma once

#define LIBFUNC_API __declspec (dllexport)

float RandomizeFloats(float,float);
int RandomizeInts(int, int);
struct V2 { float x, y; };
struct V3 { float x, y, z; };

extern "C"
{

#pragma region VectorRandomization

	LIBFUNC_API void RandomizeVector3(V3* v, float, float);
	LIBFUNC_API void RandomizeVector3(V3* v, float, float, float, float, float, float);

	LIBFUNC_API void RandomizeVector3(V3* v, int, int);
	LIBFUNC_API void RandomizeVector3(V3* v, int, int, int, int, int, int);

	LIBFUNC_API void RandomizeVector2(V2* v, float, float);
	LIBFUNC_API void RandomizeVector2(V2* v, float, float, float, float);								   
	LIBFUNC_API void RandomizeVector2(V2* v, int, int);
	LIBFUNC_API void RandomizeVector2(V2* v, int, int, int, int);

#pragma endregion

}