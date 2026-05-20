using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static sortyourtasks.baseclass;

namespace sortyourtasks
{
    public class RecurringTask : baseclass.Task
    {
        // Constructor
        public RecurringTask(DateTime dueDate, string description, Recurrence recurrence)
            : base(dueDate, description)
        {
        }
    }
}
