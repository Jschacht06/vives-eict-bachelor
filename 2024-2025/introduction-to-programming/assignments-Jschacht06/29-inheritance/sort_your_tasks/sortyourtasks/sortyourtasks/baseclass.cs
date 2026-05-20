using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace sortyourtasks
{
    public class baseclass
    {
        public enum Priority
        {
            Low,
            Medium,
            High
        }

        public enum Recurrence
        {
            Once,
            Day,
            Week,
            Month,
            Year
        }

        public class Task
        {
            // Attributes
            private DateTime dueDate;
            private string description;
            private Priority priority;
            private Recurrence recurrence;
            //properties
            public DateTime DueDate
            {
                get { return dueDate; }
                set { dueDate = value; }
            }
            public string Description
            {
                get { return description; }
                set { description = value; }
            }
            public Priority TaskPriority
            {
                get { return priority; }
                set { priority = value; }
            }
            public Recurrence TaskRecurrence
            {
                get { return recurrence; }
                set { recurrence = value; }
            }
            // Constructor
            public Task(DateTime dueDate, string description)
            {
                this.dueDate = DueDate;
                this.description = Description;
            }
            // Methods
            public void UpdateDescriptionWithPriority()
            {
                if (priority == Priority.Low)
                {
                    description = "LOW PRIORITY: " + description;
                }
                else if (priority == Priority.High)
                {
                    description = "HIGH PRIORITY: " + description;
                }

            }
            public override string ToString()
            {
                return $"Task - Due: {dueDate.ToShortDateString()}, Description: {description}, Priority: {priority}, Recurrence: {recurrence}";
            }



        }
    }
}
