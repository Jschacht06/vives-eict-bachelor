using System;
using System.Collections.Generic;
using System.Text;

namespace ParallelArrays
{
    public class ArrayHelper
    {
        public static int CountDifferentFrom(int[] elements, int value)
        {
            int counter = 0;
            // TODO - Count how many elements differ from 'value'
            foreach (int element in elements)
            {
                if (value != element)
                {
                   counter++;
                }
            }

            return counter;
        }

        public static int[] SumByElements(int[] first, int[] second)
        {
            // TODO - Return new array that contains the sum of the elements in
            // 'first' and 'second'.
            int[] sum = new int[first.Length]; //zelfde lengte als 1e en dus ook 2e array
            for (int i = 0; i < first.Length; i++)
            {
                sum[i] = first[i] + second[i];
            }


            return sum;
        }

        public static int[] DoubleInSize(int[] numbers)
        {
            // TODO - Return an array twice the size of numbers with
            // the data of 'numbers' stored in front. Initialize the other
            // elements to '0'
            int[] longer = new int[numbers.Length*2];


            for (int i = 0; i < numbers.Length; i++)
            {
                longer[i] = numbers[i];
            }


            return longer;
        }
    }
}
