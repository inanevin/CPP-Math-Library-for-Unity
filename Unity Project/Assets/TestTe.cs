using System.Collections;
using System;
using System.Collections.Generic;
using UnityEngine;
using System.Runtime.InteropServices;
public class TestTe : MonoBehaviour
{




    //   [DllImport("sa")]
    //  private static extern void RandomizeVector3double(System.IntPtr p, double min, double max);

    // Use this for initialization
    void Start()
    {

        /* Vector3 vv = Vector3.zero;
         RandomizeVector3(vv);

         GCHandle handle = GCHandle.Alloc(vv, GCHandleType.Pinned);
         System.IntPtr addr = handle.AddrOfPinnedObject();
         RandomizeVector3(addr);
         handle.Free();

         Debug.Log(vv.y);


         UnityEngine.Profiling.Profiler.BeginSample("My Sample");
         Debug.Log("This code is being profiled");
         UnityEngine.Profiling.Profiler.EndSample();*/

        /*  Vector3 v = Vector3.zero;
          RandomizeVector3double(out v, 5.0d, 15.0d);
          Debug.Log(v);*/

        Vector3 start = new Vector3(2, 2, 2);
        Vector3 end = new Vector3(10, 10, 10);
        int size = 5;
        Vector3[] arr = IE_MathLibraryWrapper.GetPointsBetweenVectors(start, end, size);

        for(int i = 0; i < arr.Length; i++)
        {
            Debug.Log(arr[i]);
        }
    }

    private void Update()
    {
     
    }


}
