using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace theshapeofcode

{
    public enum Color
    {
        Red,
        Green,
        Blue,
        Yellow,
        Black,
        White
    }
    public abstract class Shape
    {
        protected Color _color;

        public Color Color => _color;

        public void SetColor(Color color)
        {
            _color = color;
        }

        public abstract string GetInfo();

        public override string ToString()
        {
            return GetInfo();
        }
    }
}
