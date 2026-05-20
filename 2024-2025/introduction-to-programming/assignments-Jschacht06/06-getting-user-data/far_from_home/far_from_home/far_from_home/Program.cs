using Microsoft.VisualBasic;
using System.Diagnostics;
using static System.Net.Mime.MediaTypeNames;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace far_from_home
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello and welcome to drive \"Far From Home\". This small application can determine how\r\nfuel you need to take a trip from source to destination. It will also determine how\r\nmuch the trip will cost you and how many times you will need to fill up the car.");
            Console.WriteLine("Before all this can be calculated we do require some information from you:");
            // Input
            Console.Write("Please supply the length of the trip[km]:");
            double distance = Convert.ToDouble(Console.ReadLine());
            Console.Write("What is the fuel usage of the car you will be driving [l/100km]:");
            double fuelUsage = Convert.ToDouble(Console.ReadLine());
            Console.Write("What is the current average fuel price per liter [eur/l]:");
            double fuelPrice = Convert.ToDouble(Console.ReadLine());
            Console.Write("How much liters can your gas tank hold[l]");
            double tankCapacity = Convert.ToDouble(Console.ReadLine());

            //berekeningen
            double tripFuelConsumption = (distance / 100) * fuelUsage;
            double tripFuelPrice = tripFuelConsumption * fuelPrice;
            double distancePerTank = (tankCapacity / fuelUsage) * 100;
            int stops = Convert.ToInt32(distance / distancePerTank);

            Console.WriteLine($"{distance } EN {fuelUsage} EN{fuelPrice} EN {distancePerTank} testline");
            Console.WriteLine("Calculating ...");
            Console.WriteLine("Here is the outcome");
            Console.WriteLine($"For a trip of {distance} you will need {tripFuelConsumption} liters of fuel.");
            Console.WriteLine($"That means this trip will cost you {tripFuelPrice}eur at a gas price of {fuelPrice}eur / l.");
            Console.WriteLine($"You will need to stop {stops} times if you start with a full gas tank otherwise you might have to stop {stops+1} times");







        }
    }
}
