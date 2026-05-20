using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Quadratic
{
    public class QuadraticEquation
    {
        //attributes
        private double a;
        private double b;
        private double c;
        //Constructor
        public QuadraticEquation(double a, double b, double c)
        {
            this.a = a;
            this.b = b;
            this.c = c;
        }
        //Methods
        public QuadraticSolution Solve()
        {
            double discriminant = b * b - 4 * a * c;

            if (discriminant < 0)
            {
                return new QuadraticSolution(0.0,0.0);
            }
            double x1 = (-b + Math.Sqrt(discriminant)) / (2 * a);
            double x2 = (-b - Math.Sqrt(discriminant)) / (2 * a);

            return new QuadraticSolution(x1, x2);
        }

        public override string ToString()
        {
            return $"{a}x^2 + {b}x + {c} = 0";
        }
    }


}
