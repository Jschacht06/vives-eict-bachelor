# Sensor history plot

In this challenge you will be making a WPF application that captures sensor data and plots it's history to a graph on the canvas.

The main goal of this challenge is WPF and graphical visualizations on a canvas.

`Step 1` - Build the Graphical User Interface

Start a new WPF App and start building the GUI on the `MainWindow`.
It should contain:
* A title
* A button to start recording data
* A canvas to plot the graph on

`Step 2` - Start button

If the user clicks the `start button` then:
* The canvas is cleared and the x-axis and y-axis is drawn.
* Every second a new datapoint is captured. You can use [DispatcherTimer](https://learn.microsoft.com/en-us/dotnet/api/system.windows.threading.dispatchertimer) and [Random](https://learn.microsoft.com/en-us/dotnet/api/system.random) to achieve this and store it with the `Data` class.
* data points have a possible range of [-25,+25].
* Once there are 2 or more data points a line is drawn between the new datapoint and the previous with a methode `PlotDataPoint`. 
* Once the max data points of 120 is reached, the program stops getting new data points.
* Once the `start button` is clicked it is disabled until the max data points is reached.* 




