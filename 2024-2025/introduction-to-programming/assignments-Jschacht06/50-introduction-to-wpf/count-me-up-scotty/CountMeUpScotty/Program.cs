using System;
using System.Numerics;
using ClassLibrary1;
namespace CountMeUpScotty
{
    class Program
    {
        static void Welcome()
        {
            Console.WriteLine("Welcome to Count Me Up Scotty");
            Console.WriteLine("This game challenges kids to learn how to do basic Math");
        }

        static Player CreatePlayer()
        {
            Console.Write("Please enter your name: ");
            string name = Console.ReadLine();
            return new Player(name);
        }

        static void Main(string[] args)
        {
            Welcome();
            Player player = CreatePlayer();
            Game game = new Game(player);

            // Solve challenges
            // SumChallenge challenge = null;
            // do {
            //   challenge = game.NextChallenge();
            //   Console.WriteLine(challenge);
            // } while(challenge != null);

            while (!game.IsFinished())
            {
                SumChallenge challenge = game.NextChallenge();
                Console.WriteLine(challenge);


                int playerAttempt = Convert.ToInt32(Console.ReadLine());
                challenge.Solve(playerAttempt);
            }

            Console.Write(game.Overview());

            // Single
            // Console.WriteLine("Here is a challenge:");
            // SumChallenge challenge = new SumChallenge();
            // Console.Write(challenge);
            // int playerAttempt = Convert.ToInt32(Console.ReadLine());
            // challenge.Solve(playerAttempt);

            // Console.WriteLine("Results:");
            // Console.Write(challenge);


        }
    }
}