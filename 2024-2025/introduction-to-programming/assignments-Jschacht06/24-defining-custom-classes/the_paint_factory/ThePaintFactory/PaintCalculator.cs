using System;
using System.Collections.Generic;
using System.Text;

namespace ThePaintFactory
{
    public class PaintCalculator
    {
        public void AddSquare(double side)
        {
            // TODO - Add square surface area to totalArea
            totalArea += side * side;
        }

        public void AddRectangle(double width, double height)
        {
            // TODO - Add rectangular surface area to totalArea
            totalArea += width * height;
        }

        public double LitersOfPaint(int coats)
        {
            // TODO - Calculate how much paint is required to paint the totalArea surface.
            return Math.Ceiling(1.05 * (totalArea / 12) * coats); ;
        }

        // Attribute for total area to paint
        private double totalArea = 0;

        // Property for totalArea
        public double TotalArea { get { return totalArea; } }
    }
}
