using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace WpfApp1
{
    /// <summary>
    /// Interaction logic for PlayWindow.xaml
    /// </summary>
    public partial class PlayWindow : Window
    {
        public PlayWindow()
        {
            InitializeComponent();
        }

        private void SolveButton_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string userInput = AnswerTextBox.Text;
                int parsedAnswer = int.Parse(userInput); 
            }
            catch (FormatException)
            {
                MessageBox.Show("Invalid input: Please enter a valid whole number.");
            }
            catch (OverflowException)
            {
                MessageBox.Show("The number is too large or too small.");
            }
        }
    }
}
