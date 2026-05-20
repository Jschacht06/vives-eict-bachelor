namespace baby_roulette
{
    internal class Program
    {
        public static int userNumber()
        {
            Console.Write($"Please enter a number between 1 and 10: ");
            return Convert.ToInt32( Console.ReadLine() );
        }
        public static int pc()
        {
            Random pc = new Random();
            return pc.Next(1,11);
        }
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to Baby Roulette. A game with high stakes.");
            int user = userNumber();
            int smartPC = pc();
            int difference = Math.Abs(user - smartPC);
            Console.WriteLine("Spinning the wheel ... Please wait");
            System.Threading.Thread.Sleep(5000);
            if (smartPC == user)
            {
                Console.WriteLine("Congratulations you guessed the correct number");
            }
            else
            {
                Console.WriteLine($"WRONGGG!!. You missed it by {difference} . The ball landed on {smartPC}.");
            }
        }
    }
}
