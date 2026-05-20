using static sortyourtasks.baseclass;

namespace sortyourtasks
{
    internal class Program : baseclass
    {
        static void Main(string[] args)
        {
            // Create individual tasks
            Task stopUsingChatGPT = new Task(DateTime.Today.AddDays(7), "Stop using ChatGPT");

            RecurringTask makeSummary = new RecurringTask(DateTime.Today.AddDays(2), "Make summary of this course", Recurrence.Week);
            RecurringTask payTheRent = new RecurringTask(DateTime.Today.AddDays(5), "Pay the rent", Recurrence.Month);

            Task goToNerdland = new Task(DateTime.Today.AddDays(45), "Go to Nerdland");
            goToNerdland.TaskPriority = Priority.High;

            // List to hold all tasks
            List<Task> allTasks = new List<Task>
        {
            stopUsingChatGPT,
            goToNerdland
        };

            // Add recurring tasks and expand them until the end of the year
            allTasks.AddRange(ExpandRecurringTask(makeSummary));
            allTasks.AddRange(ExpandRecurringTask(payTheRent));

            // Sort by due date
            var sortedTasks = allTasks.OrderBy(t => t.DueDate).ToList();

            // Output
            Console.WriteLine("=== TASK LIST ===");
            foreach (var task in sortedTasks)
            {
                Console.WriteLine(task);
            }
        }

        static List<Task> ExpandRecurringTask(RecurringTask recurringTask)
        {
            List<Task> occurrences = new List<Task>();
            DateTime date = recurringTask.DueDate;
            Recurrence recurrence = recurringTask.TaskRecurrence;

            while (date.Year == DateTime.Today.Year)
            {
                // Create new instance with same recurrence & description
                RecurringTask newTask = new RecurringTask(date, recurringTask.Description, recurrence)
                {
                    TaskPriority = recurringTask.TaskPriority
                };
                occurrences.Add(newTask);

                date = recurrence switch
                {
                    Recurrence.Day => date.AddDays(1),
                    Recurrence.Week => date.AddDays(7),
                    Recurrence.Month => date.AddMonths(1),
                    Recurrence.Year => date.AddYears(1),
                    _ => date.AddDays(1)
                };
            }

            return occurrences;
        }
    }
}