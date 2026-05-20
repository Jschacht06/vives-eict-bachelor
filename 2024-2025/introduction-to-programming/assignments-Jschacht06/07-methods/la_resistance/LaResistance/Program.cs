using System;
using System.Security.Cryptography;

namespace LaResistance
{
    class Program
    {
        // TODO - Step 1 - Create SolveSeries method that calculates
        // the equivalent resistor of two series resistors
        static double SolveSeries(double resistor1 , double resistor2)
        {
            return (resistor1 + resistor2);
        }



        // TODO - Step 3 - Create SolveParallel method that calculates
        // the equivalent resistor of two parallel resistors
        static double SolveParallel(double resistor1, double resistor2)
        {
            return (resistor1 * resistor2) / (resistor1 + resistor2);
        }



        static void Main(string[] args)
        {
            double resistor1 = 120;
            double resistor2 = 200;

            // TODO - Step 2 - Uncomment the code below to test the SolveSeries method
            double twoSeriesResistors = SolveSeries(resistor1, resistor2);
            Console.WriteLine("The series equivalent of " + resistor1 + " and "
                + resistor2 + " is " + twoSeriesResistors);



            // TODO - Step 4 - Uncomment the code below to test the SolveParallel method
            double twoParallelResistors = SolveParallel(resistor1, resistor2);
            Console.WriteLine("The parallel equivalent of " + resistor1 + " and "
                + resistor2 + " is " + twoParallelResistors);



            // TODO - Step 5 - Solving a basic resistor network
            double totalResistance = SolveParallel(80, 320);
            totalResistance = SolveSeries(60, totalResistance);
            totalResistance = SolveSeries(totalResistance, 440);

            Console.WriteLine("The resulting equivalent resistance for the basic network is "
                + totalResistance);



            // TODO - Step 6 - Solving an advanced resistor network
            double totalResistance2 = SolveSeries(470, 120);
            totalResistance2 = SolveSeries(80, totalResistance2);
            totalResistance2 = SolveParallel(180, totalResistance2);
            totalResistance2 = SolveSeries(680, totalResistance2);
            totalResistance2 = SolveSeries(540, totalResistance2);
            totalResistance2 = totalResistance2 + SolveParallel(150, 150);
            totalResistance2 = SolveParallel(totalResistance2, 380);
            Console.WriteLine("The resulting equivalent resistance for the basic network is "
    + totalResistance2);


        }
    }
}
