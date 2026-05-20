using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using The_Company_Relationship;

namespace The_Company_Relationship
{
    using System;

    namespace The_Company_Relationship
    {
        public class Manager
        {
            //attributes
            private int id;
            private string name;
            private SwipeCard assignedSwipeCard;
            private List<Worker> workers;
            private Project project;
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
            public SwipeCard AssignedSwipeCard
            {
                get { return assignedSwipeCard; }
                set { assignedSwipeCard = value; }
            }
            public List<Worker> Workers
            {
                get { return workers; }
                set { workers = value; }
            }
            public Project Project
            {
                get { return project; }
                set { project = value; }
            }
            //constructor
            public Manager(int id, string name, SwipeCard assignedSwipeCard, Project project)
            {
                Id = id;
                Name = name;
                AssignedSwipeCard = assignedSwipeCard;
                Workers = new List<Worker>();
                Project = project;
            }

        }
    }
}