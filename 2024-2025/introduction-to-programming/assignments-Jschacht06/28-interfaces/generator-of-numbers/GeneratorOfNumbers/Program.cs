using GeneratorOfNumbers;
using System;

namespace GeneratorOfNumbers
{

    public class NaturalGenerator : IGenerator
    {
        private int current = 0;

        public int Next()
        {
            return ++current;
        }

        public void Reset()
        {
            current = 0;
        }
    }

    public class PowersOfTwoGenerator : IGenerator
    {
        private int current = 1;

        public int Next()
        {
            int result = current;
            current *= 2;
            return result;
        }

        public void Reset()
        {
            current = 1;
        }
    }

    public class FibonacciGenerator : IGenerator
    {
        private int previous = 0;
        private int current = 1;

        public int Next()
        {
            int next = previous + current;
            previous = current;
            current = next;
            return previous;
        }

        public void Reset()
        {
            previous = 0;
            current = 1;
        }
    }

    public class RandomGenerator : IGenerator
    {
        private Random random = new Random();

        public int Next()
        {
            return random.Next(1, 101); 
        }

        public void Reset()
        {
            random = new Random();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to Generator of Numbers.");
            Console.WriteLine();
            
             Console.WriteLine("Series of natural numbers:");
             IGenerator natural = new NaturalGenerator();
             for(int i = 0; i < 20; i++) {
              Console.Write(natural.Next() + " ");
             }

             Console.WriteLine();
             Console.WriteLine();
             Console.WriteLine("Powers of two:");
             IGenerator powersOfTwo = new PowersOfTwoGenerator();
             for(int i = 0; i < 20; i++) {
               Console.Write(powersOfTwo.Next() + " ");
             }

             Console.WriteLine();
             Console.WriteLine();
             Console.WriteLine("Fibonacci Sequence:");
             IGenerator fibonacci = new FibonacciGenerator();
             for(int i = 0; i < 20; i++) {
               Console.Write(fibonacci.Next() + " ");
             }

             Console.WriteLine();
             Console.WriteLine();
             Console.WriteLine("Random series of numbers:");
             IGenerator random = new RandomGenerator();
             for(int i = 0; i < 20; i++) {
            
             }
             random.Reset();
             Console.WriteLine();
             for(int i = 0; i < 20; i++) {
               Console.Write(random.Next() + " ");
             }
        }
    }
}
