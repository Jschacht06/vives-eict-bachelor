using System.Diagnostics;

namespace childs_play
{
    internal class Program
    {
        public static int difficulty()
        {
            Console.Write("Select difficulty level (1 = Easy, 2 = Medium, 3 = Hard): ");
            int difficulty = Convert.ToInt32(Console.ReadLine());
            int maxNumber = 0;
            switch (difficulty)
            {
                case 1: //easy
                    maxNumber = 50; 
                    break;
                case 2: //medium
                    maxNumber = 250;
                    break;
                case 3: //hard
                    maxNumber = 500;
                    break;
            }
            return maxNumber;
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to child's play. Your source for math practice.");
            Console.WriteLine("Try to answer the math problems as quickly as possible");
            int maxNumber = difficulty();

            Console.WriteLine("Press enter when ready ...");
            Console.ReadKey(); 


            Random numberGenerator = new Random();
            Stopwatch stopwatch = new Stopwatch();
            string results = "";
            int correctAnswers = 0;
            int totalQuestions = 3; 

            for (int i = 1; i <= totalQuestions; i++)
            {
                int number1 = numberGenerator.Next(1, maxNumber + 1);
                int number2 = numberGenerator.Next(1, maxNumber + 1);
                int correctAnswer = number1 + number2;

                Console.Write($"{number1} + {number2} = ? ");

                stopwatch.Start();  // start timing
                int userAnswer = Convert.ToInt32(Console.ReadLine());
                stopwatch.Stop(); // stop timing

                // controle
                bool isCorrect = userAnswer == correctAnswer;
                if (isCorrect) correctAnswers++;

                if (isCorrect == true)
                {
                    results += $"{number1} + {number2} = {userAnswer} (correct)\n";
                }
                else
                {
                    results += $"{number1} + {number2} = {userAnswer} (incorrect - correct answer was {correctAnswer})\n";
                }
            }

            Console.WriteLine("\nYour results:");
            Console.WriteLine(results);

            // totale tijd
            double totalSeconds = stopwatch.ElapsedMilliseconds / 1000.0;
            Console.WriteLine($"It took you {totalSeconds:F3}s to solve {totalQuestions} additions.");
            Console.WriteLine($"You got {correctAnswers} out of {totalQuestions} correct.");

            Console.WriteLine("\nThanks for playing.");
        }
    }
}
