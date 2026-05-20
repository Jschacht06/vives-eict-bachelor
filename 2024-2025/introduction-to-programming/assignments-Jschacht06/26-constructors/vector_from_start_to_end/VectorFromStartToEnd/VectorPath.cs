using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VectorFromStartToEnd
{
    public class VectorPath
    {
        //Attributes
        private List<Vector> vectors;
        //Constructors
        public VectorPath()
        {
            vectors = new List<Vector>();
        }
        //Methods
        public void Add(Vector vector)
        {
            vectors.Add(vector);
        }
        public Vector ResultingVector()
        {
            double x = 0;
            double y = 0;
            foreach (Vector vector in vectors)
            {
                x += vector.X();
                y += vector.Y();
            }
            return new Vector(x, y);
        }
        public override string ToString()
        {
            string result = "";
            foreach (Vector vector in vectors)
            {
                result += vector + "\n";
            }
            return result;
        }
    }
}
