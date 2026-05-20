using System;
using System.Collections.Generic;
using System.Text;

namespace ReplacePerformance
{
    public class StringHelper
    {
        public string ReplaceUsingLibrary(string text, string word, string replacement)
        {
            string alteredText = "";

            // TODO Use the string Replace method to replace all the occurences of word
            // with replacement inside of the string text;
            alteredText = text.Replace(word, replacement);

            return alteredText;
        }
        
        public string ReplaceUsingOwnImplementation(string text, string word, string replacement)
        {
            string alteredText = "";
            string remaingText = text;
            bool stringsRemaining = true;

            while(stringsRemaining)
            {
                int indexOfWord = remaingText.IndexOf(word);
                if (indexOfWord >= 0)
                {
                    alteredText += remaingText.Substring(0, indexOfWord) + replacement; // neemt de hele tekst tot aan indexOfWord en voegt replacement toe
                    remaingText = remaingText.Substring(indexOfWord + word.Length); // zet alle text erbij na indexofword woord zelf dus niet
                }
                else
                {
                    stringsRemaining = false;
                }
            }
            alteredText += remaingText;

            // TODO Do the same as the other method but don't use the Replace method.
            // Build your own implementation.
            return alteredText;
        }
    }
}
