using System.Reflection.PortableExecutable;

namespace number_properties
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to my number properties app.");
            Console.WriteLine("Input two integral numbers and I will tell you some important characteristics about them.");
            Console.WriteLine("You can even input negative numbers.");
            Console.WriteLine();
            Console.Write("Please input the first number: ");
            int first = Convert.ToInt32(Console.ReadLine());
            Console.Write("Please input the second number: ");
            int second = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine();
            Console.WriteLine("Thank you. Here is some info about these numbers:");
            Console.WriteLine($"- ({first}) + ({second}) = {first + second}");
            Console.WriteLine($"- ({first}) - ({second}) = {first - second}");
            if (first > second)
            {
                Console.WriteLine($"- The first number ({first}) is the biggest");
            }
            else Console.WriteLine($"- The second number ({second}) is the biggest");






            Console.WriteLine($"- The first number ({first}) is:");
            if (first % 2 == 0)
            {
                Console.WriteLine("     - even");
            }
            else Console.WriteLine("     - uneven");

            if (first > 0)
            {
                Console.WriteLine("     - positive");
            }
            else Console.WriteLine("     - negative");
            Console.WriteLine($"     - square is {Math.Pow(first, 2)}");




            Console.WriteLine($"- The second number ({second}) is:");
            if (second % 2 == 0)
            {
                Console.WriteLine("     - even");
            }
            else Console.WriteLine("     - uneven");

            if (second > 0)
            {
                Console.WriteLine("     - positive");
            }
            else Console.WriteLine("     - negative");
            Console.WriteLine($"     - square is {Math.Pow(second, 2)}");

            Console.WriteLine("Thank you for using my number properties application.");


        }
    }
}
