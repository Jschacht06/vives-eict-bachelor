using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BackToTheFuture
{
    public class TimeStamp
    {
        //Attributes
        private int hours;
        private int minutes;
        private int seconds;

        //properties
        public int Hours 
        {
            get { return hours; }
            set { hours = (Math.Max(0, value) % 24); FormatTime(); }
        }
        public int Minutes
        {
            get { return minutes; }
            set { minutes = (Math.Max(0, value) % 60); hours += value / 60; FormatTime(); }


        }
        public int Seconds
        {
            get { return seconds; }
            set { seconds = (Math.Max(0, value) % 60); minutes += value / 60; FormatTime(); }
        }
        //Constructors
        public TimeStamp()
        {
            hours = 0;
            minutes = 0;
            seconds = 0;
        }
        public TimeStamp(int hours, int minutes, int seconds)
        {
            Hours = Math.Max(0, hours);
            Minutes = Math.Max(0, minutes);
            Seconds = Math.Max(0, seconds);
        }
        //Methods

        public void AddSeconds(int seconds)
        {
            Seconds += seconds;
        }
        public void AddMinutes(int minutes)
        {
            Minutes += minutes;
        }
        public void AddHours(int hours)
        {
            Hours += hours;
        }
        public override string ToString()
        {
            return $"{Hours:D2}h:{Minutes:D2}m:{Seconds:D2}s";
        }

        public void FormatTime() 
        {
            if (seconds >= 60)
            {
                minutes += seconds / 60;
                seconds %= 60;
            }

            if (minutes >= 60)
            {
                hours += minutes / 60;
                minutes %= 60;
            }

            hours %= 24;
        }
    }
}
