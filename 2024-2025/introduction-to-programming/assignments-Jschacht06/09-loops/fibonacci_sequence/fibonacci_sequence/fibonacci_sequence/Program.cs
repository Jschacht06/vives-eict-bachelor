namespace fibonacci_sequence
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int number1 = 0, number2 = 1, nextNumber = 0;
            for (int i = 0; i <= 20; i++)
            {
                nextNumber = number1 + number2;
                Console.Write("{0} ", nextNumber);
                number1 = number2;
                number2 = nextNumber;
            }
        }
    }
}






