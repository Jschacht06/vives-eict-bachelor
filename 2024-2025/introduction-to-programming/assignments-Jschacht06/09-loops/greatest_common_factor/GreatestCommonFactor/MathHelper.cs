using System;
using System.Collections.Generic;
using System.Text;

namespace GreatestCommonFactor
{
    public class MathHelper
    {
        public int DetermineGreatestCommonFactor(int first, int second)
        {
            // TODO Determine the Greatest Common Factor
            int gcf = 0;
            first = Math.Abs(first);
            second = Math.Abs(second);

            if (first == 0) return second;
            if (second == 0) return first;

            while (second != 0)
            {
                int remainder = first % second;
                first = second;
                second = remainder;
                gcf = first;
            }

            // Please dont change the code below (automatic unit tests)
            return gcf;
        }
    }
}
