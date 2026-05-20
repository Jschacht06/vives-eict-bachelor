namespace visual_rectangle
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to the Rectangle Visualizer.\n");

            // Menu
            Console.WriteLine("Please choose your next action:");
            Console.WriteLine("- filled: Draw a filled rectangle");
            Console.WriteLine("- outline: Draw a non-filled rectangle\n");

            Console.Write("Please make a choice: ");
            string choice = Console.ReadLine().ToLower();

            // Get dimensions
            Console.Write("How many characters would you like to use for the width: ");
            int width = Convert.ToInt32(Console.ReadLine());

            Console.Write("How many characters would you like to use for the height: ");
            int height = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("\nProcessing ...\n");
            DrawRectangle(choice, width, height);
        }

        static void DrawRectangle(string choice, int width, int height)
        {
            if (choice == "filled")
            {
                for (int i = 1; i <= height; i++) // beginnen met 1 en niet met 0 anders moet je extra stap doen bij outline
                {
                    Console.WriteLine(new string('*', width));
                }
            }
            else if (choice == "outline")
            {
                for (int i = 1; i <= height; i++)
                {
                    if (i == 1 || i == height)
                    {
                        // Volle lijnen
                        Console.WriteLine(new string('*', width));
                    }
                    else
                    {
                        // middelste lijnen
                        Console.WriteLine("*" + new string(' ', width - 2) + "*"); // -2 zodat de * op de juiste plek staat
                    }
                }
            }
        }
    }
}