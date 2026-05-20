using System;

namespace TeachTheTeacher
{
    class Program
    {
        static void Main(string[] args)
        {
            Teacher teacher = new Teacher();
            teacher.SetFirstname("Juha");
            teacher.SetLastname("Schacht");
            Console.WriteLine(teacher.Fullname());
            Console.WriteLine(teacher.Email());
            Console.WriteLine(teacher.ToString());

        }
    }
}
