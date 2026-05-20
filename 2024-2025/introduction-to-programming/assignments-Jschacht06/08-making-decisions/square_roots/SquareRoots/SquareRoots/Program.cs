using System.Diagnostics.Metrics;

namespace SquareRoots
{
    internal class Program
    {
        public static int requestValue()
        {
            Console.Write("Enter an integral value to get the roots: ");
            return Convert.ToInt32(Console.ReadLine());
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to my square root application!");
            int root = requestValue();
            if (root > 0)
            {
                double resultRoot = Math.Sqrt(root);
               Console.WriteLine($"The square roots of {root} are {resultRoot} and -{resultRoot}");

            }
            else
            {
                double resultRoot = Math.Sqrt(Math.Abs(root));
                Console.WriteLine($"The square roots of {root} are {resultRoot}i and -{resultRoot}i");
            }
            Console.WriteLine("Thanks for using my app. Goodbye.");
        }
    }
}
