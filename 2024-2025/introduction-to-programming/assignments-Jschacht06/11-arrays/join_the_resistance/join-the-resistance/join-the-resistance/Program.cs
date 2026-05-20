using System.ComponentModel;
using System;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace join_the_resistance
{
    internal class Program
    {
        public static double GetTolerancePercentage(string toleranceBand)
        {
            switch (toleranceBand)
            {
                case "silver":
                    return 10;
                case "gold":
                    return 5;
                case "brown":
                    return 1;
                case "red":
                    return 2;
                case "green":
                    return 0.5;
                case "blue":
                    return 0.25;
                case "violet":
                    return 0.1;
                case "grey":
                    return 0.05;
                default:
                    return 0; 
            }
        }

        static void Main(string[] args)
        {
            string[] valueColors = { "black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white" }; //index value komt overeen met werkelijke value
            string[] toleranceColors = { "silver", "gold", "brown", "red", "green", "blue", "violet", "grey" };

            Console.WriteLine("Welcome to the Next-Gen Resistor Calculator\n");

            Console.WriteLine("Possible colors are: [black, brown, red, orange, yellow, green, blue, violet, grey, white]");

            // eerste digit
            Console.Write("Band 1: ");
            string band1 = Console.ReadLine().ToLower();

            // 2e digit
            Console.Write("Band 2: ");
            string band2 = Console.ReadLine().ToLower();

            // multiplier
            Console.Write("Band 3: ");
            string band3 = Console.ReadLine().ToLower();

            Console.Write("Tolerance band: ");
            string toleranceBand = Console.ReadLine().ToLower();

            int firstDigit = Array.IndexOf(valueColors, band1); //dit kan enkel als index value overeen komt met werkelijke value
            int secondDigit = Array.IndexOf(valueColors, band2);
            int multiplier = (int)Math.Pow(10, Array.IndexOf(valueColors, band3));

            int resistanceValue = (firstDigit * 10 + secondDigit) * multiplier; // first digit *10 anders klopt seconddigit niet

            double tolerancePercentage = GetTolerancePercentage(toleranceBand);

            Console.WriteLine($"\nThe resistor has a value of {resistanceValue} ohms ± {tolerancePercentage}%");
            Console.WriteLine("\nThank you for using our app.");
        }

    }
}
