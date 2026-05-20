using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text;

namespace BiggestOfThemAll
{
    public class ArrayAnalyzer
    {
        public int BiggestValue(int[] values)
        {
            int biggest = 0;

            // TODO Determine the biggest value in the array and place the result in biggest
            // Return 0 if the array is empty (Length == 0)
            foreach (int value in values)
            {
                if (value > biggest)
                {
                    biggest = value;
                }
            }


            // Please don't change the code below (automatic unit tests)
            return biggest;
        }

        public int BiggestIndex(int[] values)
        {
            int indexBiggest = 0;

            // TODO Determine the index of the biggest value in the array
            // Place the resulting index in indexBiggest
            // Return -1 if the array is empty (Length == 0)
            // If multiple values exist, keep the first
            int biggest = -1;
            for (int i = 0; i < values.Length; i++)
            {
                if (values[i] > biggest)
                {
                    biggest = values[i];
                    indexBiggest = i;
                }
            }
            if (values.Length == 0)
            {
                indexBiggest = -1;
            }


            // Please don't change the code below (automatic unit tests)
            return indexBiggest;
        }
    }
}
