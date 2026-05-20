using System;
using System.Collections.Generic;
using System.Text;
using static System.Net.Mime.MediaTypeNames;

namespace Palindrome
{
    public class PalindromeChecker
    {
        public bool IsPalindrome(string word)
        {
            bool isPalindrome = false;

            // TODO Determine if word is a palindrome
            word = word.ToLower().Trim();
            Console.Write(word);
            string reversed = "";
            for (int i = word.Length - 1; i >= 0; i--) // -1 want start bij 0 en niet 1
            {
                char character = word[i];
                reversed += character;
            }
            if (reversed == word)
            {
                isPalindrome = true;
            }

            // Please dont change the code below (automatic unit tests)
            return isPalindrome;
        }
    }
}
