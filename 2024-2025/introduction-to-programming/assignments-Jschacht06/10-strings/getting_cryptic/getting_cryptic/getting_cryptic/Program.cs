namespace getting_cryptic
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string word = GetInput();
            string encryptedWord = EncryptWord(word);
            Console.WriteLine(encryptedWord);
        }

        static string GetInput()
        {
            Console.Write("Enter a word: ");
            return Console.ReadLine();
        }

        static string EncryptWord(string word)
        {
            string result = "";
            foreach (char letter in word)
            {
                int ascii = (int)letter;
                string asciiStr = ascii.ToString();
                int firstDigit = int.Parse(asciiStr[0].ToString());
                int lastDigit = int.Parse(asciiStr[asciiStr.Length - 1].ToString());

                char startChar = (char)(ascii + lastDigit);
                char endChar = (char)(ascii - firstDigit);

                result += startChar + firstDigit.ToString() + lastDigit.ToString() + endChar;
            }
            return result;
        }
    }
}
 
