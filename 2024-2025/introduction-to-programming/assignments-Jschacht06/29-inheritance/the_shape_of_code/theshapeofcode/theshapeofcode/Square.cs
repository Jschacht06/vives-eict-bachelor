using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace theshapeofcode
{
    public sealed class Square : Rectangle, IComparable<Square>, IEquatable<Square>
    {
        //constructor
        public Square(double side, Color color) : base(side, side, color)
        {
            Width = side;
            Height = side;
        }
        //methods
        public override string GetInfo()
        {
            return $"Square: Side = {Width}, Color = {Color}";
        }
        public int CompareTo(Square? other)
        {
            if (other == null) return 1;
            return Width.CompareTo(other.Width);
        }
        public bool Equals(Square? other)
        {
            if (other == null) return false;
            return Width == other.Width;
        }
    }
}
