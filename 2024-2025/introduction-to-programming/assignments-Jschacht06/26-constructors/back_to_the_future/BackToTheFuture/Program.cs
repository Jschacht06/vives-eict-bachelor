using System;

namespace BackToTheFuture
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to Back to the Future.");
            Console.WriteLine("Here we are demonstrating a TimeStamp class.");
            TimeStamp defaultConstructor = new TimeStamp();
            Console.WriteLine($"Default construction: {defaultConstructor}");
            TimeStamp time = new TimeStamp(13, 12, 11);
            Console.WriteLine($"With timing info: {time}");
            time.AddHours(12);
            defaultConstructor.AddHours(12);
            Console.WriteLine($"Let's set the hours 12h ahead {defaultConstructor}" + " or for the second " + $"{ time}");
            defaultConstructor.AddMinutes(66);
            time.AddMinutes(66);
            Console.WriteLine($"Let's set the hours 66m ahead {defaultConstructor}" + " or for the second " + $"{time}");
            defaultConstructor.AddSeconds(138);
            time.AddSeconds(138);
            Console.WriteLine($"Let's set the hours 66m ahead {defaultConstructor}" + " or for the second " + $"{time}");
        }
    }
}
