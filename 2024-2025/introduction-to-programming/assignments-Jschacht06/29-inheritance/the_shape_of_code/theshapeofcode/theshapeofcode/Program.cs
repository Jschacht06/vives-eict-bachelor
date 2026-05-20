namespace theshapeofcode
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var shapes = new List<Shape>
        {
            new Rectangle(10, 5, Color.Red),
            new Square(7, Color.Green),
            new Rectangle(4, 4, Color.Blue),
            new Square(10, Color.Yellow),
            new Rectangle(3, 9, Color.Black)
        };

            Console.WriteLine("Before Sorting:");
            foreach (var shape in shapes)
            {
                Console.WriteLine(shape);
            }

            // Sort by area
            shapes.Sort((a, b) =>
            {
                double areaA = a is Rectangle rectA ? rectA.GetArea() : 0;
                double areaB = b is Rectangle rectB ? rectB.GetArea() : 0;
                return areaA.CompareTo(areaB);
            });

            Console.WriteLine("\nAfter Sorting by Area:");
            foreach (var shape in shapes)
            {
                Console.WriteLine(shape);
            }
        }
    }

}
