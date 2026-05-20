using System;

namespace ThirdRockFromTheSun
{
    class Program
    {
        static void Main(string[] args)
        {
            Sphere earth = new Sphere(6371); // Aarde met een radius van 6371 km

            Console.WriteLine("Third Rock from the Sun\n");
            Console.WriteLine($"The Earth has a radius of {earth.Radius} km.");
            Console.WriteLine($"That means its diameter is about {earth.Diameter} km.");
            Console.WriteLine($"It has a surface area of about {Math.Round(earth.Surface())} squared kilometers.");
            Console.WriteLine($"It's volume approximates {earth.Volume():E2} cubic kilometers.");
        }

    }
}

