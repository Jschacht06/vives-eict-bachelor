namespace PlanetLibrary
{
    public class Planet
    {
        private string name;
        private double radius;
        private double distanceFromSun;
        private double temperature;
        private double dayTime;
        private double gravity;
        private double mass;
        private double airPressure;
        //properties
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        public double Radius
        {
            get { return radius; }
            set { radius = value; }
        }
        public double DistanceFromSun
        {
            get { return distanceFromSun; }
            set { distanceFromSun = value; }
        }
        public double Temperature
        {
            get { return temperature; }
            set { temperature = value; }
        }
        public double DayTime
        {
            get { return dayTime; }
            set { dayTime = value; }
        }
        public double Gravity
        {
            get { return gravity; }
            set { gravity = value; }
        }
        public double Mass
        {
            get { return mass; }
            set { mass = value; }
        }
        public double AirPressure
        {
            get { return airPressure; }
            set { airPressure = value; }
        }
        //constructor
        public Planet(string name, double radius, double distanceFromSun, double temperature, double dayTime, double gravity, double mass, double airPressure)
        {
            Name = name;
            Radius = radius;
            DistanceFromSun = distanceFromSun;
            Temperature = temperature;
            DayTime = dayTime;
            Gravity = gravity;
            Mass = mass;
            AirPressure = airPressure;
        }
        //methods
        public override string ToString()
        {
            int days = (int)(dayTime / 24);
            int hours = (int)(dayTime % 24);
            int minutes = (int)((dayTime - (days * 24 + hours)) * 60);

            return $"Name: {name}\n" +
                   $"Radius: {radius} km\n" +
                   $"Distance from Sun: {distanceFromSun} km\n" +
                   $"Temperature: {temperature} °C\n" +
                   $"Day Time: {days} days {hours} hours {minutes} minutes\n" +
                   $"Gravity: {gravity} m/s²\n" +
                   $"Mass: {mass} kg\n" +
                   $"Air Pressure: {airPressure} atm";
        }

        public double CalculateArea()
        {
            return 4 * Math.PI * Math.Pow(radius, 2);
        }
    }
}
