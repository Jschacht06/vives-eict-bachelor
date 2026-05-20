using System.Drawing;

namespace pattern_builder
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to pattern builder this app will build a rectangle for you");
            Console.WriteLine("In order to create the rectangle i need the width and height");
            Console.Write("Please enter the width: ");
            int width = Convert.ToInt32(Console.ReadLine());
            Console.Write("Please enter the height: ");
            int height = Convert.ToInt32(Console.ReadLine());
            string rectangleWidth = "";
            for (int i = 0; i < width; i++)
            {
                rectangleWidth += '*';
            }
            for (int j = 0; j < height; j++)
            {
                Console.WriteLine($"{rectangleWidth}");
            }

        }
    }
}
