using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;
using System.Runtime.InteropServices;

public static class IE_MathLibraryWrapper
{

    #region Variables And Structs

    public const string s_LibName = "a5";

    [StructLayout(LayoutKind.Sequential)]
    public struct Vector3Struct
    {
        public float x, y, z;
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct Vector2Struct
    {
        public float x, y;
    }

    #endregion

    #region Vector Randomizations

    [DllImport(s_LibName)]
    private static extern void RandomizeVector3F(out Vector3Struct vs, float min, float max);
    [DllImport(s_LibName)]
    private static extern void RandomizeVector3FRange(out Vector3Struct vs, double minX, double maxX, double minY, double maxY, double minZ, double maxZ);
    [DllImport(s_LibName)]
    private static extern void RandomizeVector3Int(out Vector3Struct vs, int min, int max);
    [DllImport(s_LibName)]
    private static extern void RandomizeVector3IntRange(out Vector3Struct vs, int minX, int maxX, int minY, int maxY, int minZ, int maxZ);
    [DllImport(s_LibName)]
    private static extern void RandomizeVector2F(out Vector2Struct vs, double min, double max);
    [DllImport(s_LibName)]
    private static extern void RandomizeVector2FRange(out Vector2Struct vs, double minX, double maxX, double minY, double maxY);
    [DllImport(s_LibName)]
    private static extern void RandomizeVector2Int(out Vector2Struct vs, int min, int max);
    [DllImport(s_LibName)]
    private static extern void RandomizeVector2IntRange(out Vector2Struct vs, int minX, int maxX, int minY, int maxY);

    /// <summary>
    /// Returns a randomized Vector3, each property is randomized seperately between min and max.
    /// </summary>
    /// <param name="min">Lower limit for randomization.(Inclusive)</param>
    /// <param name="max">Upper limit for randomization.(Inclusive)</param>
    public static Vector3 GetRandomizedVector3(float min, float max)
    {
        Vector3Struct vs = new Vector3Struct();
        RandomizeVector3F(out vs, min, max);
        return ToVector(vs);
    }

    /// <summary>
    /// Returns a randomized Vector3, each property is randomized seperately between their respective passed arguments. All limits are inclusive.
    /// </summary>
    public static Vector3 GetRandomizedVector3(float minX, float maxX, float minY, float maxY, float minZ, float maxZ)
    {
        Vector3Struct vs = new Vector3Struct();
        RandomizeVector3FRange(out vs, minX, maxX, minY, maxY, minZ, maxZ);
        return ToVector(vs);
    }

    /// <summary>
    /// Returns a randomized Vector3, each property is randomized seperately between min and max.
    /// </summary>
    /// <param name="min">Lower limit for randomization.(Inclusive)</param>
    /// <param name="max">Upper limit for randomization.(Inclusive)</param>
    public static Vector3 GetRandomizedVector3(int min, int max)
    {
        Vector3Struct vs = new Vector3Struct();
        RandomizeVector3Int(out vs, min, max);
        return ToVector(vs);
    }

    /// <summary>
    /// Returns a randomized Vector3, each property is randomized seperately between their respective passed arguments. All limits are inclusive.
    /// </summary>
    public static Vector3 GetRandomizedVector3(int minX, int maxX, int minY, int maxY, int minZ, int maxZ)
    {
        Vector3Struct vs = new Vector3Struct();
        RandomizeVector3IntRange(out vs, minX, maxX, minY, maxY, minZ, maxZ);
        return ToVector(vs);
    }

    /// <summary>
    /// Returns a randomized Vector2, each property is randomized seperately between min and max.
    /// </summary>
    /// <param name="min">Lower limit for randomization.(Inclusive)</param>
    /// <param name="max">Upper limit for randomization.(Inclusive)</param>
    public static Vector2 GetRandomizedVector2(float min, float max)
    {
        Vector2Struct vs = new Vector2Struct();
        RandomizeVector2F(out vs, min, max);
        return ToVector(vs);
    }

    /// <summary>
    /// Returns a randomized Vector2, each property is randomized seperately between their respective passed arguments. All limits are inclusive.
    /// </summary>
    public static Vector2 GetRandomizedVector2(float minX, float maxX, float minY, float maxY)
    {
        Vector2Struct vs = new Vector2Struct();
        RandomizeVector2FRange(out vs, minX, maxX, minY, maxY);
        return ToVector(vs);
    }

    /// <summary>
    /// Returns a randomized Vector2, each property is randomized seperately between min and max.
    /// </summary>
    /// <param name="min">Lower limit for randomization.(Inclusive)</param>
    /// <param name="max">Upper limit for randomization.(Inclusive)</param>
    public static Vector2 GetRandomizedVector2(int min, int max)
    {
        Vector2Struct vs = new Vector2Struct();
        RandomizeVector2Int(out vs, min, max);
        return ToVector(vs);
    }

    /// <summary>
    /// Returns a randomized Vector2, each property is randomized seperately between their respective passed arguments. All limits are inclusive.
    /// </summary>
    public static Vector3 GetRandomizedVector2(int minX, int maxX, int minY, int maxY)
    {
        Vector2Struct vs = new Vector2Struct();
        RandomizeVector2IntRange(out vs, minX, maxX, minY, maxY);
        return ToVector(vs);
    }

    #endregion

    #region Vector Distance Calculations

    [DllImport(s_LibName)]
    private static extern int FindClosestV3([In, Out] Vector3[] array, ref Vector3Struct comparison, int size);
    [DllImport(s_LibName)]
    private static extern int FindClosestV2([In, Out] Vector2[] array, ref Vector2Struct comparison, int size);

    /// <summary>
    /// Finds and returns the closest vector3 in an array to the given vector.
    /// </summary>
    /// <param name="arr"></param>
    /// <param name="comparison"></param>
    /// <returns></returns>
    public static Vector3 FindClosestVector(Vector3[] arr, Vector3 comparison)
    {
        Vector3Struct s = ToStruct(comparison);
        int index = FindClosestV3(arr, ref s, arr.Length);
        return arr[index];
    }

    /// <summary>
    /// Finds and returns the closest vector3 in an array to the given vector.
    /// </summary>
    /// <param name="arr"></param>
    /// <param name="comparison"></param>
    /// <returns></returns>
    public static Vector3 FindClosestVector(List<Vector3> arr, Vector3 comparison)
    {
        Vector3Struct s = ToStruct(comparison);
        int index = FindClosestV3(arr.ToArray(), ref s, arr.Count);
        return arr[index];
    }

    /// <summary>
    /// Finds and returns the closest vector2 in an array to the given vector.
    /// </summary>
    /// <param name="arr"></param>
    /// <param name="comparison"></param>
    /// <returns></returns>
    public static Vector2 FindClosestVector(Vector2[] arr, Vector2 comparison)
    {
        Vector2Struct s = ToStruct(comparison);
        int index = FindClosestV2(arr, ref s, arr.Length);
        return arr[index];
    }

    /// <summary>
    /// Finds and returns the closest vector2 in an array to the given vector.
    /// </summary>
    /// <param name="arr"></param>
    /// <param name="comparison"></param>
    /// <returns></returns>
    public static Vector2 FindClosestVector(List<Vector2> arr, Vector2 comparison)
    {
        Vector2Struct s = ToStruct(comparison);
        int index = FindClosestV2(arr.ToArray(), ref s, arr.Count);
        return arr[index];
    }

    #endregion,

    #region Vector Array Calculations

    [DllImport(s_LibName)]
    private static extern IntPtr GetPointsBetweenVectorsV3(ref Vector3Struct start, ref Vector3Struct end, ref int size);

    [DllImport(s_LibName)]
    private static extern IntPtr GetPointsBetweenVectorsV2(ref Vector2Struct start, ref Vector2Struct end, ref int size);

    /// <summary> 
    /// Returns a pointer pointing to the first element of dynamically allocated array which contains given amount of points between the start & end points.
    /// </summary>
    public static Vector3[] GetPointsBetweenVectors(Vector3 start, Vector3 end, int size)
    {
        // Return if size is 0 or neg.
        if(size < 1)
        {
            Debug.LogError("Size of the required array can not be smaller than 1.");
            return null;
        }

        // Init structs.
        Vector3Struct vS = ToStruct(start);
        Vector3Struct vE = ToStruct(end);

        // The method will return the pointer pointing to the beginning address of the allocated & calculated array.
        IntPtr arrayPointer = GetPointsBetweenVectorsV3(ref vS, ref vE, ref size);

        // Init point vectors to copy the data.
        Vector3[] points = new Vector3[size];

        // Offset is going to be used to increment the pointer by the size of pointSize.
        int offset = 0;

        // Size of a Vector3Struct type variable in the memory. Which is blittable with the V3 struct in C++ library.
        int pointSize = Marshal.SizeOf(typeof(Vector3Struct));

        // Increment the whole array.
        for (int i = 0; i < size; i++)
        {
            // Convert to structure from the pointer, which will be incremented by the size of V3 struct. Then convert the structure to Vector and assign.
            points[i] = ToVector((Vector3Struct)Marshal.PtrToStructure(new IntPtr(arrayPointer.ToInt32() + offset), typeof(Vector3Struct)));
            // Increment offset to shift the memory address forward.
            offset += pointSize;
        }

        // Free the memory which was allocated by C++ method.
        Marshal.FreeCoTaskMem(arrayPointer);

        return points;
    }

    /// <summary> 
    /// Returns a pointer pointing to the first element of dynamically allocated array which contains given amount of points between the start & end points.
    /// </summary>
    public static Vector2[] GetPointsBetweenVectors(Vector2 start, Vector2 end, int size)
    {
        // Return if size is 0 or neg.
        if (size < 1)
        {
            Debug.LogError("Size of the required array can not be smaller than 1.");
            return null;
        }

        // Init structs.
        Vector2Struct vS = ToStruct(start);
        Vector2Struct vE = ToStruct(end);

        // The method will return the pointer pointing to the beginning address of the allocated & calculated array.
        IntPtr arrayPointer = GetPointsBetweenVectorsV2(ref vS, ref vE, ref size);

        // Init point vectors to copy the data.
        Vector2[] points = new Vector2[size];

        // Offset is going to be used to increment the pointer by the size of pointSize.
        int offset = 0;

        // Size of a Vector3Struct type variable in the memory. Which is blittable with the V3 struct in C++ library.
        int pointSize = Marshal.SizeOf(typeof(Vector2Struct));

        // Increment the whole array.
        for (int i = 0; i < size; i++)
        {
            // Convert to structure from the pointer, which will be incremented by the size of V3 struct. Then convert the structure to Vector and assign.
            points[i] = ToVector((Vector2Struct)Marshal.PtrToStructure(new IntPtr(arrayPointer.ToInt32() + offset), typeof(Vector2Struct)));
            // Increment offset to shift the memory address forward.
            offset += pointSize;
        }

        // Free the memory which was allocated by C++ method.
        Marshal.FreeCoTaskMem(arrayPointer);
        
        return points;
    }

    #endregion

    #region Vector Circle Calculations

    #endregion

    #region Utility

    /// <summary>
    /// Returns a Vector3 out of a Vector3Struct type value.
    /// </summary>
    /// <param name="s"></param>
    /// <returns></returns>
    private static Vector3 ToVector(Vector3Struct s)
    {
        Vector3 v = new Vector3();
        v.x = (float)s.x;
        v.y = (float)s.y;
        v.z = (float)s.z;
        return v;
    }

    /// <summary>
    /// Returns a Vector2 out of a Vector2Struct type value.
    /// </summary>
    /// <param name="s"></param>
    /// <returns></returns>
    private static Vector2 ToVector(Vector2Struct s)
    {
        Vector2 v = new Vector2();
        v.x = (float)s.x;
        v.y = (float)s.y;
        return v;
    }

    /// <summary>
    /// Returns a Vector3Struct out of a Vector3 type value.
    /// </summary>
    /// <param name="s"></param>
    /// <returns></returns>
    private static Vector3Struct ToStruct(Vector3 v)
    {
        Vector3Struct vs = new Vector3Struct();
        vs.x = v.x;
        vs.y = v.y;
        vs.z = v.z;
        return vs;
    }

    /// <summary>
    /// Returns a Vector2Struct out of a Vector2 type value.
    /// </summary>
    /// <param name="s"></param>
    /// <returns></returns>
    private static Vector2Struct ToStruct(Vector2 v)
    {
        Vector2Struct vs = new Vector2Struct();
        vs.x = v.x;
        vs.y = v.y;
        return vs;
    }

    #endregion
}
