namespace higher_lower
{
    internal class Program
    {
        public static int userInput()
        {
            Console.Write("Please enter a number: ");
            return Convert.ToInt32(Console.ReadLine());
        }
        public static void progressBar(int attempts , int currentAttempt, int attemptsLeft)
        {
            int progressBarLength = 10;
            Console.Write("|");
            for (int i = 0; i < progressBarLength; i++)
            {
                if (i < currentAttempt)
                {
                    Console.Write("X");
                }
                else 
                { 
                    Console.Write(".");
                }
            }
            Console.WriteLine($"| ({attemptsLeft} guesses left)");
        }

        static void Main(string[] args)
        {
            Random pcNumber = new Random();
            int pc = pcNumber.Next(0, 1001);
            int attempts = 10;
            int attemptsLeft = attempts;


            Console.WriteLine("Welcome to higher/lower. The most addictive guessing game.");
            Console.WriteLine();
            Console.WriteLine("Generating a very secret number between 0 and 1000 ...");
            Console.WriteLine($"OK Done. You can start your guessing work. You have {attemptsLeft} attempts");
            while (attemptsLeft > 0)
            {
                int user = userInput();
                if (user < pc)
                {
                    Console.WriteLine($"Ow, too low. Guess again.");
                }
                else if (user > pc)
                {
                    Console.WriteLine($"Ow, too high. Guess again.");
                }
                else
                {

                    Console.WriteLine($"Congratulations! You guessed the secret number {pc} in {attempts - attemptsLeft + 1} attempt(s)."); // +1 Want nadat je 3x mis bent moet je nog 1x raden voor je de juiste hebt dus 4x
                    return;
                }
                attemptsLeft--;
                progressBar(attempts, attempts - attemptsLeft, attemptsLeft); // staat hier anders klopt attemptsleft niet
            }
            Console.WriteLine($"Sorry, you've used all your guesses. The secret number was {pc}. Better luck next time!");
        }
    }
}
