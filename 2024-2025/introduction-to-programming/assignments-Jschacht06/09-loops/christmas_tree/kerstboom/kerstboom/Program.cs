namespace kerstboom
{
    internal class Program
    {
        public static void stap1()
        {
            for (int i = 1; i <= 7; i++) // hoeveelheid rijen
            {
                for (int j = 1; j <= i; j++) // hoeveelheid charcters per rij
                {
                    Console.Write("x");
                }
                Console.WriteLine();
            }
        }
        public static void stap2()
        {
            int height = 6;

            for (int i = 1; i <= height; i++) // volgende rij...
            {
                // spaties
                for (int j = 1; j <= height - i; j++)
                {
                    Console.Write(" ");
                }

                // x
                for (int j = 1; j <= (2 * i - 1); j++) // -1 want je moet altijd een oneven getal hebben anders geen mooie kerstboom ( punt moet starten met 1 charcter)
                {
                    Console.Write("x");
                }
                Console.WriteLine();
            }
        }
        public static void stap3()
        {
            int height = 6; 

            for (int i = 1; i <= height; i++) 
            {
                
                for (int j = 1; j <= height - i; j++)
                {
                    Console.Write(" ");
                }

                
                for (int j = 1; j <= (2 * i - 1); j++)
                {
                    // even # oneven x
                    if (j % 2 == 1)
                    {
                        Console.Write("x");
                    }
                    else
                    {
                        Console.Write("#");
                    }
                }
                Console.WriteLine();
            }
        }
        static void Main(string[] args)
        {
            stap1();
            Console.WriteLine();
            stap2();
            Console.WriteLine();
            stap3(); 

        }
    }
}