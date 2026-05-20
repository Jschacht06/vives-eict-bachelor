using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace theshapeofcode
{
    public class Rectangle : Shape, IComparable<Rectangle>, IEquatable<Rectangle>
    {
        private double width;
        private double height;
        //properties
        public double Width
        {
            get { return width; }
            set { width = value; }
        }
        public double Height
        {
            get { return height; }
            set { height = value; }
        }
        //constructor
        public Rectangle(double width, double height, Color color)
        {
            this.width = width;
            this.height = height;
            _color = color;
        }
        //methods
        public double GetArea()
        {
            return width * height;
        }
        public override string GetInfo()
        {
            return $"Rectangle: Width = {width}, Height = {height}, Color = {Color}";
        }
        public int CompareTo(Rectangle? other)
        {
            if (other == null) return 1;
            return GetArea().CompareTo(other.GetArea());
        }
        public bool Equals(Rectangle? other)
        {
            if (other == null) return false;
            return width == other.width && height == other.height;
        }

    }
}
