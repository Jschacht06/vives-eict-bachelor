using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace The_Company_Relationship
{
    public class Project
    {
        // attributes
        private int projectId;
        private string projectName;
        private string projectStatus;

        // properties
        public int ProjectId
        {
            get { return projectId; }
            set { projectId = value; }
        }

        public string ProjectName
        {
            get { return projectName; }
            set { projectName = value; }
        }

        public string ProjectStatus
        {
            get { return projectStatus; }
            set { projectStatus = value; }
        }

        // constructor
        public Project(int projectId, string projectName)
        {
            ProjectId = projectId;
            ProjectName = projectName;
            ProjectStatus = "In Progress"; 
        }
    }
}
