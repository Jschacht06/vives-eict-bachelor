namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            double radius = 2.15;
            double diameter = radius * 2;
            double circumference = radius * radius * Math.PI;
            double area = 2 * radius * Math.PI;
            Console.WriteLine("Hello and welcome to the Circle Properties App");
            Console.WriteLine();
            Console.WriteLine("Properties of the circle");
            Console.WriteLine($"- radius: {radius} meters");
            Console.WriteLine($"- diameter: {diameter} meters");
            Console.WriteLine($"- circumference: {circumference} meters");
            Console.WriteLine($"- area: {area}sq meters");
            Console.WriteLine();
            Console.WriteLine("Thank you for using the app");
        }
    }
}
