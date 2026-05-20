using System;
using System.Collections.Generic;
using System.Text;

namespace CoordinatePlane
{
    public class Point
    {
        double x = 0;
        double y = 0;

        public string Quadrant()
        {
            // TODO Determine the quadrant of the coordinates
            // first, second, third, fourth or origin (if both 0)
            string quadrant = "";
            if ( x == 0 && y == 0)
            {
                quadrant = "The origin";
            }
            else if ( x > 0  && y > 0 )
            {
                quadrant = "The first quadrant";
            }
            else if (x < 0 && y > 0)
            {
                quadrant = "The second quadrant";
            }
            else if (x < 0 && y < 0)
            {
                quadrant = "The third quadrant";
            }
            else if (x > 0 && y > 0)
            {
                quadrant = "The fourth quadrant";
            }
            else if(x == 0 && y > 0)
            {
                quadrant = "Between the first and second quadrant";
            }
            else if (x == 0 && y < 0)
            {
                quadrant = "Between the third and fourth quadrant";
            }
            else if (x > 0 && y == 0)
            {
                quadrant = "Between the first and fourth quadrant";
            }
            else if (x < 0 && y < 0)
            {
                quadrant = "Between the second and third quadrant";
            }




            // Please dont change the code below (automatic unit tests)
            return quadrant;
        }

        // Properties - Dont change code below
        public double X { get { return x; } set { x = value; } }
        public double Y { get { return y; } set { y = value; } }
    }
}
