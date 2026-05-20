namespace AvgTemp
{
    internal class Program
    {
        static void Main(string[] args)
        {

            List<int> recordedTemperaturesInDegreesCelcius = new List<int>();
            int temperature = 0;
            // fill the list from values provided as command-line arguments
            foreach (string stringRepresentationOfTemperature in args)
            {
                try
                {
                    temperature = int.Parse(stringRepresentationOfTemperature);
                    recordedTemperaturesInDegreesCelcius.Add(temperature);

                }
                catch(FormatException)
                {
                    Console.WriteLine("The value " + stringRepresentationOfTemperature + " is not a valid integer.");
                    return;
                }
            }

            // Calculate and print the average temperature
            try
            {
                int averageTemperature = SimpleMath.CalculateAverage(recordedTemperaturesInDegreesCelcius);
                Console.WriteLine("The average temperature is " + averageTemperature);
            }        
            catch(DivideByZeroException)
            {
                Console.WriteLine("Gelieve minstens 1 waarde in te voeren");
            }
        }
    }
}