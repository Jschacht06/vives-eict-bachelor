using System;
using System.Collections.Generic;
using System.Text;

namespace TurnTheTables
{
    public class ArrayMultiplier
    {
        public int[] Multiply(int[] left, int[] right)
        {
            // TODO Create an array of int
            int[] multiplications = new int[10];

            // For its size take either the length of left or right (both should be the same size)
            int[] result = new int[left.Length];

            // TODO Multiply the elements in left with the elements in right.
            // Place the result in the result array.
            for (int i = 0; i < result.Length; i++)
            {
                result[i] = left[i] * right[i];
            }
            // Please don't change the code below (automatic unit tests)
            return result;
        }
    }
}
