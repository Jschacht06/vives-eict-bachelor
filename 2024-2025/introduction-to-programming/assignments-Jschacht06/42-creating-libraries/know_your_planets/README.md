# Know your planets

## Planets

Create a library `PlanetLibrary` with a class `Planet` that holds the following information:
* Name of the planet
* Diameter of the planet
* Distance of the planet to the sun
* Temperature of the planet
* Length of one day in earthly time
* Gravity
* Mass
* Airpressure

Provide a ToString override that gives all information in a visual good manner
Provide a methode to calculate the surface area.

## Menu

Create a library `MenuLibrary` with a class `Menu` that holds the following information:
* A list of strings
* A index of the selected menu option

Provide a ToString override that return a menu of the list items and indicates the current selected one.
Provide a methode to get the selected menu choice.
Provide a methode to move the selected menu choice up or down 
Provide a methdoe to add a new menu item

## Console Program

Start by creating four planets, you get the info of the following two planets, add two more yourself.

**VENUS**

radius = 6051,8 km
distance to the sun = 108200000 km
length of one day = 243 d 0 u 0 m
gravity = 8,87 m/s2
mass = 4,867E24 kg
temperature = 735 K
airpressure = 92 bar

**MARS**

radius = 3389.5 km
distance to the sun = 227900000 km
length of one day = 1d 0u 37m
gravity = 3,71 m/s2
mass = 6,418E23 kg
temperature = 210 K
airpressure = 6,36 hPa

Now based on the planets add there names as menu items and end with exit.

When the user pushes the up or down arrow the selected menu item moves accordingly.
When the user pushes enter the information of that planet is displayed, if it's exit the program is terminated.


