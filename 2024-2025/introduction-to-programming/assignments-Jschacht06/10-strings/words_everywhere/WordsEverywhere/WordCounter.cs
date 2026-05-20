using System;
using System.Collections.Generic;
using System.Text;

namespace WordsEverywhere
{
    public class WordCounter
    {
        public int CountWords(string text)
        {
            int numberOfWords = 0;
            bool word = false;
            text = text.Trim();

            // TODO Count the number of words in the text
            for (int i = 0; i < text.Length; i++)
            {
                if (text[i] != ' ' && text[i] != '\n' && text[i] != '\r') // enkels als text geen spatie of newline etc is
                {
                    
                    if (!word) // enkel als we nog niet in een woord zitten mag numberOfWords++ gebeuren en word dan ook true worden
                    {
                        numberOfWords++;  
                        word = true; 
                    }
                }
                else // einde woord dus false
                {
                    
                    word = false;
                }
            }

            // Please dont change the code below (automatic unit tests)
            return numberOfWords;
        }
    }
}
