namespace TotalSurface
{
    class AreaListing
    {
        private List<IShape> shapes = new List<IShape>();

        public void Add(IShape shape)
        {
            shapes.Add(shape);
        }

        public double GetTotalArea()
        {
            double total = 0;
            foreach (var shape in shapes)
            {
                total += shape.GetArea();
            }
            return total;
        }

        public override string ToString()
        {
            string output = "";
            foreach (var shape in shapes)
            {
                output += shape + "\n";
            }

            output += "------------------------------\n";
            output += $"Total Area: {GetTotalArea()} sq. meters";

            return output;
        }
    }
}