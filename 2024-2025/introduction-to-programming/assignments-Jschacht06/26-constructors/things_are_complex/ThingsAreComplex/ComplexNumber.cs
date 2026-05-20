using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ThingsAreComplex
{
    public class ComplexNumber
    {
        //Attributes
        private double real;
        private double imaginary;
        //Constructors
        public ComplexNumber()
        {
            real = 0;
            imaginary = 0;
        }
        public ComplexNumber(double real, double imaginary)
        {
            this.real = real;
            this.imaginary = imaginary;
        }
        //Methods
        
        public double Real()
        {
            return real;
        }

        public double Imaginary()
        {
            return imaginary;
        }

        public double Magnitude()
        {
            return Math.Sqrt(real * real + imaginary * imaginary);
        }

        public ComplexNumber Add(ComplexNumber value)
        {
            return new ComplexNumber(this.real + value.real, this.imaginary + value.imaginary);
        }
        public ComplexNumber Subtract(ComplexNumber value)
        {
            return new ComplexNumber(this.real - value.real, this.imaginary - value.imaginary);
        }
        public ComplexNumber Multiply(ComplexNumber value)
        {
            return new ComplexNumber(this.real * value.real - this.imaginary * value.imaginary, this.real * value.imaginary + this.imaginary * value.real);
        }
        public ComplexNumber Divide(ComplexNumber value)
        {
            double denominator = value.real * value.real + value.imaginary * value.imaginary;
            return new ComplexNumber((this.real * value.real + this.imaginary * value.imaginary) / denominator, (this.imaginary * value.real - this.real * value.imaginary) / denominator);
        }
        public override string ToString()
        {
            return $"({this.real} {(this.imaginary >= 0 ? "+" : "")}{(this.imaginary <= 0 ? "-" : "")} {Math.Abs(this.imaginary)}i)";
        }

    }
}
