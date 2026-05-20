using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AvgTemp
{
    internal class SimpleMath
    {
        public static int CalculateAverage(List<int> listOfIntegers)
        {
            int average = 0;

            foreach (int value in listOfIntegers)
            {
                average += value;
            }
            average /= listOfIntegers.Count;

            return average;
        }
    }
}
