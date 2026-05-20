using System;
using System.Collections.Generic;
using System.Text;

namespace StringsToNumbers
{
    public class StringArrayConverter
    {
        public int[] ConvertToIntegers(string[] stringValues)
        {

            // TODO Create an array of integers with the same size as the stringValues array
            int[] numbers = new int[stringValues.Length];

            // TODO Convert each string in stringValues to an integer and store the result in numbers
            for (int i = 0; i < stringValues.Length; i++)
            {
                numbers[i] = Convert.ToInt32(stringValues[i]);
            }
  

            // Please don't change the code below (automatic unit tests)
            return numbers;
        }
    }
}
