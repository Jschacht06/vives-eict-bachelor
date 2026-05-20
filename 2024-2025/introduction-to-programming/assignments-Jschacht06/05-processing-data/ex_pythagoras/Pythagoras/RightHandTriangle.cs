using System;
using System.Collections.Generic;
using System.Text;

namespace Pythagoras
{
    public class RightHandTriangle
    {
        public double DetermineA(double b, double c)
        {
            // TODO: Calculate the a-side from the b- and c-side
            double a = Math.Sqrt(Math.Pow(c, 2) - Math.Pow(b,2));

            // Please dont change the code below (automatic unit tests)
            return a;
        }
        public double DetermineB(double a, double c)
        {
            // TODO: Calculate the b-side from the a- and c-side
            double b = Math.Sqrt(Math.Pow(c, 2) - Math.Pow(a, 2)); ;

            // Please dont change the code below (automatic unit tests)
            return b;
        }
        public double DetermineC(double a, double b)
        {
            // TODO: Calculate the c-side from the a- and b-side
            double c = Math.Sqrt(Math.Pow(a, 2) + Math.Pow(b, 2)); ;

            // Please dont change the code below (automatic unit tests)
            return c;
        }
    }
}
