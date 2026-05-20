using System;

namespace Converternator
{
    class Program
    {
        public static int userChoice()
        {
            Console.WriteLine("Welcome to the next gen ConverterNator. Please select an option:");
            Console.WriteLine("1. Miles to kilometers");
            Console.WriteLine("2. Kilometers to miles");
            Console.WriteLine("3. Pounds to kilograms");
            Console.WriteLine("4. Kilograms to pounds");
            Console.WriteLine("5. Exit");
            Console.Write("Your choice: ");
            return Convert.ToInt32(Console.ReadLine()); 
        }
        static void Main(string[] args)
        {
            // TODO Build an application that allows the user to convert units.
            // Request action from the user by showing him/her the following options
            // 1. Miles to kilometers
            // 2. Kilometers to miles
            // 3. Pounds to kilograms
            // 4. Kilograms to pounds
            // 5. Exit

            // Converter object
            Converter converter = new Converter();
            int userchoice = userChoice();

            switch(userchoice)
            {
                case 1:
                    Console.WriteLine("Ready to convert miles to kilometers.");
                    Console.Write("Please enter the value to convert: ");
                    double miles = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine($"{miles} miles equals {converter.MileToKilometer(miles)} kilometers");
                    Console.WriteLine("Thank you for using our ConverterNator App.");
                    break;
                case 2:
                    Console.WriteLine("Ready to convert kilometers to miles.");
                    Console.Write("Please enter the value to convert: ");
                    double kilometers = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine($"{kilometers} kilometers equals {converter.KilometerToMile(kilometers)} miles");
                    Console.WriteLine("Thank you for using our ConverterNator App.");
                    break;
                case 3:
                    Console.WriteLine("Ready to convert pounds to kilogram.");
                    Console.Write("Please enter the value to convert: ");
                    double pounds = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine($"{pounds} pounds equals {converter.PoundToKilogram(pounds)} kilograms");
                    Console.WriteLine("Thank you for using our ConverterNator App.");
                    break;
                case 4:
                    Console.WriteLine("Ready to convert kilograms to pounds.");
                    Console.Write("Please enter the value to convert: ");
                    double kilograms = Convert.ToDouble(Console.ReadLine());
                    Console.WriteLine($"{kilograms} equals {converter.KilogramToPound(kilograms)} pounds");
                    Console.WriteLine("Thank you for using our ConverterNator App.");
                    break;
                case 5:
                    Console.WriteLine("Thank you for using our ConverterNator App.");
                    break;
            }

            // Example useage:
            // double miles = converter.KilometerToMile(34);
        }
    }
}
