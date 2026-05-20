using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.AccessControl;
using System.Text;
using System.Threading.Tasks;

namespace ThirdRockFromTheSun
{
    public class Sphere
    {
        // Attributes
        private double radius;
        // Properties
        public double Radius
        {
            get { return radius; }
            set { radius = Math.Abs(value); }
        }
        public double Diameter
        {
            get { return radius*2.0; }
            set { radius = Math.Abs(value / 2.0); }
        }
        public Sphere(double radius)
        {
            Radius = radius; 
        }

        // Methods
        public double Surface()
        {
            return 4 * Math.PI * Math.Pow(radius, 2);
        }

        public double Volume()
        {
            return (4.0 / 3.0) * Math.PI * Math.Pow(radius, 3);
        }

        public double Circumference()
        {
            return 2 * Math.PI * radius;
        }


    }
}
