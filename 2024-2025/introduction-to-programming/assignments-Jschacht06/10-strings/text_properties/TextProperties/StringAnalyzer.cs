using System;
using System.Collections.Generic;
using System.Text;

namespace TextProperties
{
    public class StringAnalyzer
    {
        public int NumberOfVowels(string text)
        {
            int numberOfVowels = 0;

            string lowerText = text.ToLower();
            for (int i = 0; i < lowerText.Length; i++)
            {
                char c = lowerText[i];
                switch (c)
                {
                    case 'a': numberOfVowels++; break;
                    case 'e': numberOfVowels++; break;
                    case 'i': numberOfVowels++; break;
                    case 'o': numberOfVowels++; break;
                    case 'u': numberOfVowels++; break;
                        default: break;
                }
            }


                return numberOfVowels;
        }

        public int NumberOfConsonants(string text)
        {
            int numberOfConsonants = 0;

            // TODO Count the number of consonants inside of text
            string lowerText = text.ToLower();
            for (int i = 0; i < lowerText.Length; i++)
            {
                char c = lowerText[i];
                switch (c)
                {
                    case 'a': ; break;
                    case 'e': ; break;
                    case 'i': ; break;
                    case 'o': ; break;
                    case 'u': ; break;
                        default: numberOfConsonants++;  break;
                        
                }
            }

            return numberOfConsonants;
        }

        public int NumberOfDigits(string text)
        {
            int numberOfDigits = 0;
            for (int i = 1; i <= text.Length; i++)
            {
                numberOfDigits++;
            }
                return numberOfDigits;
        }

        public int NumberOfUppercaseLetters(string text)
        {
            int numberOfUppercaseLetters = 0;

            // TODO Count the number of upper case letters inside of text
            string lowerText = text.ToLower();
            for (int i = 0; i < lowerText.Length; i++)
                if (lowerText[i] != text[i])
                    numberOfUppercaseLetters++;

                return numberOfUppercaseLetters;
        }

        public int NumberOfLowercaseLetters(string text)
        {
            int numberOfLowercaseLetters = 0;

            // TODO Count the number of lower case letters inside of text
            string lowerText = text.ToLower();
            for (int i = 0; i < lowerText.Length; i++)
                if (lowerText[i] == text[i])
                    numberOfLowercaseLetters++;

                    return numberOfLowercaseLetters;
        }

        public int NumberOfWhitespaceCharacters(string text)
        {
            int numberOfWhitespaceCharacters = 0;

            // TODO Count the number of whitespace characters inside of text
            for (int i = 0; i < text.Length; i++)
                if (text[i] == ' ') 
                    numberOfWhitespaceCharacters++;

                    return numberOfWhitespaceCharacters;
        }
    }
}
