using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VectorFromStartToEnd
{
    public class Vector
    {
        //Attributes
        private double x;
        private double y;
        //Constructors
        public Vector() 
        {
            x = 0;
            y = 0;
        }
        public Vector(double x, double y)
        {
            this.x = x;
            this.y = y;
        }
        //Methods
        public double X()
        {
            return x;
        }
        public double Y() 
        {
            return y;
        }
        public double Magnitude()
        {
            return Math.Sqrt(x * x + y * y);
        }
        public override string ToString()
        {
            return $"[{x};{y}] with magnitude {Magnitude()}";
        }
    }
}
