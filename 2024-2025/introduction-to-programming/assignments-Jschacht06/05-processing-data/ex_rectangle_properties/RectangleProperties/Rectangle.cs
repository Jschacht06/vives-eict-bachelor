using System;
using System.Collections.Generic;
using System.Text;

namespace RectangleProperties
{
    public class Rectangle
    {
        double width = 3;
        double height = 8;

        public double CalculateArea()
        {
            // TODO: Calculate the area of a rectangle
            double area = width*height ;

            // Please dont change the code below (automatic unit tests)
            return area;
        }

        public double CalculateCircumference()
        {
            // TODO: Calculate the circumference of a rectangle
            double circumference = 2*width + 2*height ;

            // Please dont change the code below (automatic unit tests)
            return circumference;
        }

        public void PrintToTerminal()
        {
            // Print some info to the terminal
            Console.WriteLine("Rectangle: " + width + "cm by " + height + "cm");

            Console.WriteLine("The rectangle has an area of " + CalculateArea()
                + "sq centimeters.");

            Console.WriteLine("The rectangle has an circumference of " + CalculateCircumference()
                + " centimeters.");
        }
    }
}
