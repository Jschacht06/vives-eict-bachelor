using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_Company_Relationship
{
    public class Worker
    {
        //attributes
        private int id;
        private string name;
        //properties
        public int Id
        {
            get { return id; }
            set { id = value; }
        }
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        //constructor
        public Worker(int id, string name)
        {
            Id = id;
            Name = name;
        }
        //methods

    }

}
