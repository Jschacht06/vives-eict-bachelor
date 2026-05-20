namespace up_and_down
{
    internal class Program
    {
        static void Main(string[] args)
        {
            // [0, 10[
            Console.Write("Looping [0, 10[: ");
            for (int i = 0; i < 10; i++)
            {
                Console.Write($"{i} ");
            }
            Console.WriteLine();

            // [1, 10]
            Console.Write("Looping [1, 10]: ");
            for (int i = 1; i <= 10; i++)
            {
                Console.Write($"{i} ");
            }
            Console.WriteLine();

            // [10, 0[
            Console.Write("Looping [10, 0[: ");
            for (int i = 10; i >= 0; i--)
            {
                Console.Write($"{i} ");
            }
            Console.WriteLine();

            // [0, 10]
            Console.Write("Looping [0, 10] (even numbers): ");
            for (int i = 0; i <= 10; i += 2)
            {
                Console.Write($"{i} ");
            }
            Console.WriteLine();

            // [0, 100]
            Console.Write("Looping [0, 100] (multiples of 11): ");
            for (int i = 11; i < 100; i += 11)
            {
                Console.Write($"{i} ");
            }
            Console.WriteLine();

            // [1, 10000]
            Console.Write("Looping [1, 10000] (i times 5): ");
            for (int i = 1; i <= 10000; i *= 5)
            {
                Console.Write($"{i} ");
            }
            Console.WriteLine();

            // [4096, 0[
            Console.Write("Looping [4096, 0[ (divided by 2): ");
            for (int i = 4096; i > 0; i /= 2)
            {
                Console.Write($"{i} ");
            }
            Console.WriteLine();
        }
    }
}