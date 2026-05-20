namespace roll_em_all
{
    internal class Program
    {
        public static void SimulateThrows(int throws , int eyes)
        {
            Random rolls = new Random();

            for (int i = 1; i <= throws; i++)
            {
                int roll = rolls.Next(1, eyes + 1); 
                Console.WriteLine($"Throw {i}: {roll}");
            }

        }
        static void Main(string[] args)
        {
            Console.WriteLine("This is a dice throwing simulator. Select the number of throws you wish to simulate and the eyes of the dice to use.");

            Console.Write("Number of throws to simulate? ");
            int throws = Convert.ToInt32(Console.ReadLine());

            Console.Write("Number of eyes of the dice to use? ");
            int eyes = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine();
            SimulateThrows(throws, eyes);
        }
    }
}
