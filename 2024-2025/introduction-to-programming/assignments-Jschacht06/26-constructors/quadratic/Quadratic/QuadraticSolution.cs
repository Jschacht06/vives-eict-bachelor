using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Quadratic
{
    public class QuadraticSolution
    {
        //attributes
        private double x1;
        private double x2;
        //Constructor
        public QuadraticSolution(double x1, double x2)
        {
            this.x1 = x1;
            this.x2 = x2;
        }
        //Methods

        public double GetX1()
        {
            return x1;
        }
        public double GetX2()
        {
            return x2;
        }

        public override string ToString()
        {
            return $"x1 = {x1}, x2 = {x2}";
        }


    }
}
