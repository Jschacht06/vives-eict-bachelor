using System;
using System.Collections.Generic;
using System.Text;

namespace RectangleArea
{
    public class Rectangle
    {
        public double CalculateArea(double width, double height)
        {
            // TODO Calculate area if both width and height are positive, else set area to 0
            double area = -1;
            if (width > 0 && height > 0)
            {
                area = width * height;
            }
            else
            {
                area = 0;
            }

            // Please dont change the code below (automatic unit tests)
            return area;
        }
    }
}
