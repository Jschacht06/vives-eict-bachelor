using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Threading;

namespace sensor_history_plot
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        private List<int> sensorData = new List<int>();
        private DispatcherTimer timer;
        private Random datapoint = new Random();
        private int maxAmountOfPoints = 120;

        public MainWindow()
        {
            InitializeComponent();
            timer = new DispatcherTimer();
            timer.Interval = TimeSpan.FromSeconds(1);
            timer.Tick += Timer_Tick;
        }

        private void Start_recording_Click(object sender, RoutedEventArgs e)
        {
            Start_recording.IsEnabled = false;
            sensorData.Clear();
            canvas.Children.Clear();
            DrawAxes();
            timer.Start();
        }

        private void Timer_Tick(object sender, EventArgs e)
        {
            if (sensorData.Count < maxAmountOfPoints)
            {
                int newDatapoint = datapoint.Next(-25, 26);
                sensorData.Add(newDatapoint);

                if (sensorData.Count > 1)
                {
                    PlotDatapoint(sensorData.Count - 2, sensorData[sensorData.Count - 2], sensorData.Count - 1, sensorData[sensorData.Count - 1]);
                }
            }
            else
            {
                timer.Stop();
                Start_recording.IsEnabled = true;
            }
        }

        private void DrawAxes()
        {
            double canvasWidth = canvas.ActualWidth;
            double canvasHeight = canvas.ActualHeight;

            Line xAxis = new Line
            {
                X1 = 20,
                Y1 = canvasHeight / 2,
                X2 = canvasWidth - 20,
                Y2 = canvasHeight / 2,
                Stroke = Brushes.Black
            };

            Line yAxis = new Line
            {
                X1 = 20,
                Y1 = 20,
                X2 = 20,
                Y2 = canvasHeight - 20,
                Stroke = Brushes.Black
            };

            canvas.Children.Add(xAxis);
            canvas.Children.Add(yAxis);

            TextBlock minXLabel = new TextBlock { Text = "0", Margin = new Thickness(20, canvasHeight / 2 + 5, 0, 0) };
            TextBlock maxXLabel = new TextBlock { Text = maxAmountOfPoints.ToString(), Margin = new Thickness(canvasWidth - 40, canvasHeight / 2 + 5, 0, 0) };

            canvas.Children.Add(minXLabel);
            canvas.Children.Add(maxXLabel);

            TextBlock minYLabel = new TextBlock { Text = "-25", Margin = new Thickness(0, canvasHeight - 30, 0, 0) };
            TextBlock maxYLabel = new TextBlock { Text = "25", Margin = new Thickness(0, 10, 0, 0) };

            canvas.Children.Add(minYLabel);
            canvas.Children.Add(maxYLabel);
        }

        private void PlotDatapoint(int index1, int value1, int index2, int value2)
        {
            double width = canvas.ActualWidth;
            double height = canvas.ActualHeight;
            double xSpacing = (width - 40) / (double)maxAmountOfPoints;
            double yScale = (height - 40) / 50.0;

            double x1 = 20 + index1 * xSpacing;
            double y1 = (height / 2) - value1 * yScale;
            double x2 = 20 + index2 * xSpacing;
            double y2 = (height / 2) - value2 * yScale;

            Line line = new Line
            {
                X1 = x1,
                Y1 = y1,
                X2 = x2,
                Y2 = y2,
                Stroke = Brushes.Red
            };
            canvas.Children.Add(line);
        }
    }
}