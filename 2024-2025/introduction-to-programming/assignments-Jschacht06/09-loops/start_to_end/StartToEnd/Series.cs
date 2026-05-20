using System;
using System.Collections.Generic;
using System.Text;

namespace StartToEnd
{
    public class Series
    {
        public int Sum(int start, int end)
        {
            // TODO Determine sum of values between start (included) and end (excluded)
            int sum = 0;

            for (int i = start; i < end; i++)
            {
                sum += i;
            }
            // Please dont change the code below (automatic unit tests)
            return sum;
        }

        public int Sum(int start, int step, int end)
        {
            // TODO Determine sum of values between start (included) and end (excluded)
            // Increment from start to end with a value of step
            
                if (step == 0)
                {
                    Console.Write("Please enter a value thats not 0.");
                }

                int sum = 0;

                // Handles cases where start >= end for positive and negative step
                if (step > 0)
                {
                    for (int i = start; i < end; i += step)
                    {
                        sum += i;
                    }
                }
                else
                {
                    for (int i = start; i > end; i += step)
                    {
                        sum += i;
                    }
                }
            // Please dont change the code below (automatic unit tests)
            return sum;
        }
    }
}
