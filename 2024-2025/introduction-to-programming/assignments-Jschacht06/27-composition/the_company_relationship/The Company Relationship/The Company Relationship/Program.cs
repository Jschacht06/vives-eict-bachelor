using The_Company_Relationship.The_Company_Relationship;

namespace The_Company_Relationship
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Manager manager = new Manager(1, "John Doe", new SwipeCard(1, "123456", null), new Project(1, "Project A"));
            manager.AssignedSwipeCard.AssignedManager = manager;
            manager.Workers.Add(new Worker(1, "Jane Smith"));
            manager.Workers.Add(new Worker(2, "Bob Johnson"));

            Console.WriteLine($"Manager: {manager.Name}");
            Console.WriteLine($"Assigned Swipe Card: {manager.AssignedSwipeCard.CardNumber}");
            Console.WriteLine($"Project: {manager.Project.ProjectName}");
            Console.WriteLine("Workers:");
            foreach (var worker in manager.Workers)
            {
                Console.WriteLine($"- {worker.Name}");
            }
            Console.WriteLine($"Project Status: {manager.Project.ProjectStatus}");
            Console.WriteLine($"Project ID: {manager.Project.ProjectId}");
            Console.WriteLine($"Project Name: {manager.Project.ProjectName}");
            Console.WriteLine($"Swipe Card ID: {manager.AssignedSwipeCard.CardId}");
            Console.WriteLine($"Swipe Card Number: {manager.AssignedSwipeCard.CardNumber}");
            Console.WriteLine($"Assigned Manager ID: {manager.AssignedSwipeCard.AssignedManager.Id}");
            Console.WriteLine($"Assigned Manager Name: {manager.AssignedSwipeCard.AssignedManager.Name}");

        }
    
    }
}
