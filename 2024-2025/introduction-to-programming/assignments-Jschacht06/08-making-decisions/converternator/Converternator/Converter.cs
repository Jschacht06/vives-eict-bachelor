using System;
using System.Collections.Generic;
using System.Text;

namespace Converternator
{
    public class Converter
    {
        public double PoundToKilogram(double pounds)
        {
            // TODO Convert pounds to kilograms
            double kilograms = (pounds * 0.45359237);

            // Please dont change the code below (automatic unit tests)
            return kilograms;
        }

        public double KilogramToPound(double kilograms)
        {
            // TODO Convert kilograms to pounds
            double pounds = (kilograms / 0.45359237);

            // Please dont change the code below (automatic unit tests)
            return pounds;
        }

        public double MileToKilometer(double miles)
        {
            // TODO Convert miles to kilometers
            double kilometers = (miles * 1.609344);


            // Please dont change the code below (automatic unit tests)
            return kilometers;
        }

        public double KilometerToMile(double kilometers)
        {
            // TODO Convert kilometers to miles
            double miles = (kilometers / 1.609344);

            // Please dont change the code below (automatic unit tests)
            return miles;
        }
    }
}
