using System;

namespace CoordinatePlane
{
    class Program
    {
        public static double xCoordinate()
        {
            Console.Write("Please enter the X coordinate: ");
            return Convert.ToDouble(Console.ReadLine());
        }
        public static double yCoordinate()
        {
            Console.Write("Please enter the Y coordinate: ");
            return Convert.ToDouble(Console.ReadLine());
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to the Coordinate Plane App");

            // TODO Request point coordinates from user

            // Create point
            Point point = new Point();
            point.X = xCoordinate();        // Set user value
            point.Y = yCoordinate();        // Set user value

            // TODO Output in which quadrant the point lies
            // Warning! Output different message if it lies in the origin
            string quadrant = point.Quadrant();

            Console.WriteLine($"The coordinate ({point.X},{point.Y}) lies in {quadrant}");

        }
    }
}
