using System;

namespace RectangleArea
{
    class Program
    {
        public static double askHeight()
        {
            Console.Write("Whats the height of the rectangle in meters?: ");
            return Convert.ToDouble(Console.ReadLine());

        }
        public static double askWidth()
        {
            Console.Write("Whats the width of the rectangle in meters?: ");
            return Convert.ToDouble(Console.ReadLine());

        }
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to the rectangle calculator");

            // TODO Request the width of the rectangle from the user
            double width = askWidth();

            // TODO Request the height of the rectangle from the user
            double height = askHeight();

            // Calculate area
            Rectangle rectangle = new Rectangle();
            double area = rectangle.CalculateArea(width, height);

            // TODO Generate message to the user stating the area (show appropriate message if width or height was < 0)
            if (width < 0 || height < 0)
            {
                Console.WriteLine("Sorry, you provided negative value(s).Cannot determine area.");
            }
            else
            {
                Console.WriteLine($"The area of this rectangle ({width} by {height}) {area} square meters");
            }
        }
    }
}
