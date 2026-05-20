using System;

namespace time_for_change
{
    internal class Program
    {
        public static string calculateChange(double change)
        {
            double[] coinValues = { 2 , 1 , 0.50, 0.20, 0.10, 0.05, 0.02, 0.01 };
            string[] coinNames = { "2eur", "1eur", "50cent", "20cent", "10cent", "5cent", "2cent", "1cent" };

            string changeOutput = "";
            for (int i = 0; i < coinValues.Length; i++)
            {
                int coinCount = (int)(change / coinValues[i]);
                if (coinCount > 0)
                {
                    changeOutput += $"{coinCount}x {coinNames[i]} ";
                    change -= coinCount * coinValues[i];
                    change = Math.Round(change, 2);      
                }
            }
            return changeOutput; 
        }
        static void Main(string[] args)
        {
            string[] productNames = { "Cola", "Fanta", "Water", "Red Bull" };
            double[] productPrices = { 2.2, 2.2, 1.0, 2.7 };
            Console.WriteLine("Please select a product:");
            for (int i = 0 ; i < productNames.Length; i++)
            {
                Console.WriteLine($"{i+1}. {productNames[i]} [{productPrices[i]}eur]");
            }

            Console.Write("Choice: ");
            int choice = Convert.ToInt32( Console.ReadLine());
            double price = 0;
            for (int i = 0 ;i < productPrices.Length;i++)
            {
                if (i+1 == choice)
                {
                    price = productPrices[i];
                    Console.WriteLine($"Please insert at least {price}eur.");
                }
            }
            Console.Write("Insert:");
            double insertedMoney = Convert.ToDouble( Console.ReadLine());
            double change = insertedMoney - price;
            int productIndex = choice - 1;
            string productName = productNames[productIndex];

            if (change > 0)
            {
                Console.WriteLine($"\nYour change: {calculateChange(change)}");
            }
            else
            {
                Console.WriteLine("\nNo change to return.");
            }

            Console.WriteLine($"\nThank you and enjoy your {productName}!");
        }
    }
}
