namespace its_all_about_timing
{
    internal class Program
    {
        static void Welcome()
        {
            Console.WriteLine("Welcome to Its All About Timing");
            Console.WriteLine("Please enter a total number of seconds and the App will convert it to a timestamp.");
        }
        static int requestInput()
        {
            Console.Write("Please enter the total time in seconds: ");
            return Convert.ToInt32(Console.ReadLine());
        }
        static string calculateTimestamp(int totalseconds)
        {
            int days = totalseconds / 86400;
            int remainingseconds = totalseconds % 86400;

            int hours = remainingseconds / 3600;
            remainingseconds %= 3600;

            int minutes = remainingseconds / 60;
            int  seconds = remainingseconds % 60;
            string timestamp = $"{days:00}d {hours:00}:{minutes:00}:{seconds:00}";
            return timestamp;
        }
        static void Main(string[] args)
        {
            int totalseconds = requestInput();
            Console.WriteLine(calculateTimestamp(totalseconds)); 

        }
    }
}
