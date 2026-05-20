using System;

namespace SumAndDifference
{
    public class Program
    {
        static int RequestNumber()
        {
            Console.Write("Please enter a number: ");
            string userInput = Console.ReadLine();
            int number = Convert.ToInt32(userInput);
            return number;
        }

        static int Add(int first, int second)
        {
            return (first + second);
        }

        static int substract(int first, int second) 
        {
            return (second - first);
        }



        static void Main(string[] args)
        {
            // TODO Request two numbers from the user:
            int number1 = RequestNumber();
            int number2 = RequestNumber();



            // Show user the inputted numbers
            Console.WriteLine("You entered " + number1 + " and " + number2 + ".");

            // TODO Call the Add method and store the result in the variable sum.
            int sum = Add(number1, number2);
            // Make sure to pass the two numbers as arguments to the method.



            // Result of sum
            Console.WriteLine("\nTheir sum: " + sum);

            // TODO Call the Subtract method and store the result in the variable difference.
            // Make sure to pass the two numbers as arguments to the method.
            int difference = substract(number1,number2);



            // Result of sum
            Console.WriteLine("\nTheir difference: " + difference);
        }
    }
}
