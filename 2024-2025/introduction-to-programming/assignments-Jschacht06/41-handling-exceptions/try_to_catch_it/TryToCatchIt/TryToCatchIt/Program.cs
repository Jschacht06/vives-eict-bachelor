namespace TryToCatchIt
{
    internal class Program
    {
        static int GetInteger(String prompt)
        {
            int result = 0;
            bool ok;
            do
            {
                try
                {
                    Console.Write(prompt);
                    result = int.Parse(Console.ReadLine());
                    ok = true;
                }
                catch (FormatException)
                {
                    Console.WriteLine("Invalid input. Please enter a valid integer.");
                    ok = false;
                }
            }
            while (!ok);
            return result;
        }

        static void Main(string[] args)
        {
            int num1 = GetInteger("Enter a number: ");
            int num2 = GetInteger("Enter another number: ");

            try
            {
                Console.WriteLine("{0} / {1} = {2}", num1, num2, num1 / num2);
            }
            catch (DivideByZeroException)
            {
                Console.WriteLine("Delen door nul is flauwekul.");
            }
        }
    }
}