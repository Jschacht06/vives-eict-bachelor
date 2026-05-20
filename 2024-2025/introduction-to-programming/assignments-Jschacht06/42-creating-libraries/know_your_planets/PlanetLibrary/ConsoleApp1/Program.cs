using System.Numerics;
using MenuLibrary;
using PlanetLibrary;

namespace ConsoleApp1
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<Planet> planetObjects = new List<Planet>
            {
                new Planet("Mercury", 2439.5, 57900000, 167, 1407.6, 3.7, 3.3e23, 0.0),
                new Planet("Venus", 6052, 108200000, 464, 5832.5, 8.9, 4.87e24, 92),
                new Planet("Earth", 6378, 149600000, 15, 24, 9.8, 5.97e24, 1),
                new Planet("Mars", 3396, 227900000, -65, 24.6, 3.7, 6.42e23, 0.006),
                new Planet("Jupiter", 71492, 778500000, -110, 9.9, 24.8, 1.90e27, 1),
                new Planet("Saturn", 60268, 1433000000, -140, 10.7, 10.4, 5.68e26, 1.4),
                new Planet("Uranus", 25559, 2871000000, -195, 17.2, 8.7, 8.68e25, 1.2),
                new Planet("Neptune", 24764, 4495000000, -200, 16.1, 11.0, 1.02e26, 1.5),
            };

            List<string> menuItems = new List<string>();
            foreach (Planet planet in planetObjects)
            {
                menuItems.Add(planet.Name);
            }
            menuItems.Add("Exit");

            Menu menu = new Menu(menuItems);

            while (true)
            {
                Console.Clear();
                Console.WriteLine("Select a planet to view info (or Exit):\n");
                Console.WriteLine(menu.ToString());

                ConsoleKeyInfo key = Console.ReadKey(true);

                if (key.Key == ConsoleKey.UpArrow)
                {
                    menu.MoveUp();
                }
                else if (key.Key == ConsoleKey.DownArrow)
                {
                    menu.MoveDown();
                }
                else if (key.Key == ConsoleKey.Enter)
                {
                    string choice = menu.GetSelectedMenuChoice();

                    if (choice == "Exit")
                    {
                        Console.WriteLine("\nExiting program...");
                        break;
                    }

                    Planet selectedPlanet = planetObjects.Find(p => p.Name == choice);
                    if (selectedPlanet != null)
                    {
                        Console.Clear();
                        Console.WriteLine("Planet Information:");
                        Console.WriteLine(selectedPlanet);
                        Console.WriteLine($"\nCalculated Surface Area: {selectedPlanet.CalculateArea():N2} km²");

                        Console.WriteLine("\nPress any key to return to the menu...");
                        Console.ReadKey(true);
                    }
                }
            }
        }
    }
}
