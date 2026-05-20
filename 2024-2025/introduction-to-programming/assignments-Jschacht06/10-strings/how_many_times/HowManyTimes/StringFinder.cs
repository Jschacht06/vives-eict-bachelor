using System;
using System.Collections.Generic;
using System.Text;

namespace HowManyTimes
{
    public class StringFinder
    {
        public int SearchAndCount(string text, string word)
        {
            int numberOfOccurrences = 0;
            string tempWord = "";
            text = text.ToLower();
            word = word.ToLower();

            // TODO Count the number of times the word occurs in the text
            for (int i = 0; i < text.Length; i++)
            {
                char character = text[i];
                if (text[i] != ' ' && text[i] != '\n' && text[i] != '\r')
                {
                    tempWord += character;
                    if (tempWord == word)
                    {
                        numberOfOccurrences++;
                    }
                }
                else
                {
                    tempWord = "";
                }
            }


                    // Please dont change the code below (automatic unit tests)
                    return numberOfOccurrences;
        }
    }
}
