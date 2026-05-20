using System;
using System.Collections.Generic;
using System.Text;

namespace TimeMachine
{
    public class Clock
    {
        int hours = DateTime.Now.Hour;
        int minutes = DateTime.Now.Minute;

        public void AddHours(int delta)
        {
            hours = (hours + delta) % 24;
            hours = (hours + 24) % 24;
        }

        public void AddMinutes(int delta)
        {
            int inputMinutes = minutes + delta;
            minutes = (inputMinutes % 60) % 24;
            hours = (hours + inputMinutes / 60) % 24;
            hours = (hours + 24) % 24;
        }

        public void PrintToTerminal()
        {
            Console.WriteLine($"Time: {hours.ToString("D2")}:{minutes.ToString("D2")}");
        }

        public int Hours { get { return hours; } set { hours = value; } }
        public int Minutes { get { return minutes; } set { minutes = value; } }
    }
}