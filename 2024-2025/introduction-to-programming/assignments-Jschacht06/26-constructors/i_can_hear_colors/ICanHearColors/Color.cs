using System;
using System.Collections.Generic;
using System.Text;

namespace ICanHearColors
{
    public class Color
    {
        //Constructors
        public Color()
        {
            Red = 0;
            Green = 0;
            Blue = 0;
        }
        public Color(int red, int green, int blue)
        {
            Red = red;
            Green = green;
            Blue = blue;
        }
        public int Red
        {
            get { return red; }
            set { red = Math.Clamp(value, 0, 255); }
        }

        public int Blue
        {
            get { return blue; }
            set { blue = Math.Clamp(value, 0, 255); }
        }
        public int Green
        {
            get { return green; }
            set { green = Math.Clamp(value, 0, 255); }
        }
        public override string ToString()
        {
            return $"Red: {Red} | Green: {Green} | Blue: {Blue}";
        }

        private int red = 0;
        private int green = 0;
        private int blue = 0;
    }
}
