namespace AvgTemp
{
    internal class Program
    {
        static void Main(string[] args)
        {
            List<int> recordedTemperaturesInDegreesCelcius = new List<int>();
            string filePath = Path.Combine(Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments), "temperatures.txt");

            try
            {
                // Read all lines from the file
                string[] lines = File.ReadAllLines(filePath);

                foreach (string line in lines)
                {
                    try
                    {
                        int temperature = int.Parse(line);
                        recordedTemperaturesInDegreesCelcius.Add(temperature);
                    }
                    catch (FormatException)
                    {
                        Console.WriteLine($"The value '{line}' is not a valid integer.");
                    }
                }

                // Calculate and print the average temperature
                int averageTemperature = SimpleMath.CalculateAverage(recordedTemperaturesInDegreesCelcius);
                Console.WriteLine("The average temperature is " + averageTemperature);
            }
            catch (FileNotFoundException)
            {
                Console.WriteLine($"The file '{filePath}' was not found.");
            }
            catch (UnauthorizedAccessException)
            {
                Console.WriteLine($"Access to the file '{filePath}' is denied.");
            }
            catch (IOException ex)
            {
                Console.WriteLine($"An I/O error occurred: {ex.Message}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"An unexpected error occurred: {ex.Message}");
            }
            finally
            {
                Console.WriteLine("Program execution completed.");
            }
        }
    }
}