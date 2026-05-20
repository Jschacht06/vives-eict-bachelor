using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GeneratorOfNumbers
{
    public interface IGenerator
    {
        int Next();
        void Reset();
    }
}
