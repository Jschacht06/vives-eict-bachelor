using System;
using System.Collections.Generic;
using System.Text;

namespace MultiplesOfThree
{
    public class MultipleGenerator
    {
        public int[] generate()
        {
            // TODO - Create an array of 10 integers (remove the null assignment)
            int[] multiples = new int[10];

            // TODO - Fill the array with the first 10 multiples of 3. Start with 3 itself
            // So: 3 6 9 ...
            for (int i = 0; i<10 ; i++)
            {
                multiples[i] = (i + 1)*3;
            }

            // Please don't change the code below (automatic unit tests)
            return multiples;
        }
    }
}
