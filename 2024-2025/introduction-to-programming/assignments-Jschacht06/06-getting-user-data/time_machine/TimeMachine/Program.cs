using System;

namespace TimeMachine
{
    class Program
    {
        static void Main(string[] args)
        {
            Clock clock = new Clock();

            Console.WriteLine("Welcome to your personal time machine.\n");

            Console.WriteLine("The current time is");
            clock.PrintToTerminal();

            Console.Write("How many minutes would you like to add? ");
            int minutes = Convert.ToInt32(Console.ReadLine());
            clock.AddMinutes(minutes);

            Console.Write("How many hours would you like to add? ");
            int hours = Convert.ToInt32(Console.ReadLine());
            clock.AddHours(hours);


            // TODO: Add the actual values to the current clock time
            // Call the AddMinutes() method
            // Call the AddHours() method

            Console.WriteLine("\nCongratz. You jumped forward in time to");
            clock.PrintToTerminal();
        }
    }
}
