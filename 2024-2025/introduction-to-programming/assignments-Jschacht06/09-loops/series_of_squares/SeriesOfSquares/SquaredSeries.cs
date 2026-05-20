using System;
using System.Collections.Generic;
using System.Text;

namespace SeriesOfSquares
{
    public class SquaredSeries
    {
        public static int SeriesSum(int n)
        {
            int sum = 0;
            // TODO - Determine the sum of a squared series using a simple loop
            for (int i = 1; i <= n; i++)
            {
                sum += Convert.ToInt32(Math.Pow(i,2));
            }
            return sum;
        }

        public static int CalculateSumSeries(int n)
        {
            // TODO - Determine the sum using the formula for a squared series
            int sum =(n * (n + 1) * (2 * n + 1) / 6);
            return sum;
        }
    }
}
