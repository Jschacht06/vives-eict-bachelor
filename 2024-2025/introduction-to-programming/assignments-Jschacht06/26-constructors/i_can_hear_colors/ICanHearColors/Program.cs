using System;

namespace ICanHearColors
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("This application show how to use the color class");

            Console.Write("Start by creating a new instance of Color: ");
            Color myFavoriteColor = new Color();
            Console.WriteLine(myFavoriteColor + "\n");

            Console.WriteLine("To change the color components we need to call the setters.");

            myFavoriteColor.Green = 85;
            Console.WriteLine("For example a nice green: " + myFavoriteColor);

            myFavoriteColor.Red = 128;
            myFavoriteColor.Green = 0;
            myFavoriteColor.Blue = 128;
            Console.WriteLine("Or a very cute pink color " + myFavoriteColor);
        }
    }
}
