using System;

namespace SuperStringTheory
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Welcome to Super String Theory\n");

            // Append
            Console.WriteLine("Lets append the word \" World\" to \"Hello\"");
            SuperString hello = new SuperString("Hello");
            Console.WriteLine(" > Before: " + hello.Text);

            hello.Append(" World");
            Console.WriteLine(" > After: " + hello.Text);

            // IsValidNumber
            Console.WriteLine("\nLet's check some numbers ...");
            SuperString number = new SuperString();

            number.Text = "1234";
            Console.WriteLine($"Is {number.Text} a valid number? " + number.IsValidNumber());

            number.Text = "SDFNBDSF";
            Console.WriteLine($"Is {number.Text} a valid number? " + number.IsValidNumber());

            number.Text = "#88";
            Console.WriteLine($"Is {number.Text} a valid number? " + number.IsValidNumber());

            // Trim
            Console.WriteLine("\nOK, now for some trimming ...");
            SuperString text = new SuperString();

            text.Text = "  Hello There!";
            Console.Write($"If we trim at the beginning \"{text.Text}\"");
            text.TrimStart();
            Console.WriteLine($", then we get \"{text.Text}\"");

            text.Text = "There is no place like home!    ";
            Console.Write($"If we trim at the end \"{text.Text}\"");
            text.TrimEnd();
            Console.WriteLine($", then we get \"{text.Text}\"");
        }
    }
}
