namespace personal_info
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string name = "Schacht";
            string firstName = "Juha";
            int age = 18;
            string gender = "Male";
            int currentYear = DateTime.Now.Year;
            int birthYear = currentYear - age;


            //Write to Console

            Console.WriteLine("This is my personal information \n");
            Console.WriteLine("Name " + name);
            Console.WriteLine("Firstname " + firstName);
            Console.WriteLine("Age " + age);
            Console.WriteLine("Birth Year " + birthYear);
            Console.WriteLine("Gender " + gender);

        }
    }
}
