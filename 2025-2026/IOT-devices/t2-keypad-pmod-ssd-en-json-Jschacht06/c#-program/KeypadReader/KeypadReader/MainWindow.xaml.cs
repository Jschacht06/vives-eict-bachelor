using System;
using System.IO.Ports;
using System.Windows;
using System.Text;

namespace KeypadReader
{
    public partial class MainWindow : Window
    {
        private SerialPort serialPort;
        private StringBuilder dataBuffer = new StringBuilder();

        public MainWindow()
        {
            InitializeComponent();
            LoadComPorts();
        }

        private void LoadComPorts()
        {
            cmbComPorts.Items.Clear();
            string[] ports = SerialPort.GetPortNames();
            foreach (string port in ports)
            {
                cmbComPorts.Items.Add(port);
            }
            if (cmbComPorts.Items.Count > 0)
                cmbComPorts.SelectedIndex = 0;
        }

        private void BtnConnect_Click(object sender, RoutedEventArgs e)
        {
            if (cmbComPorts.SelectedItem == null)
            {
                MessageBox.Show("Please select a COM port");
                return;
            }

            try
            {
                serialPort = new SerialPort();
                serialPort.PortName = cmbComPorts.SelectedItem.ToString();
                serialPort.BaudRate = 9600;
                serialPort.DataBits = 8;
                serialPort.Parity = Parity.None;
                serialPort.StopBits = StopBits.One;
                serialPort.Handshake = Handshake.None;
                serialPort.DataReceived += DataReceived;
                serialPort.Open();

                btnConnect.IsEnabled = false;
                btnDisconnect.IsEnabled = true;
                tbKey.Text = "Connected - Press keys";
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message);
            }
        }

        private void ProcessJson(string json)
        {
            Dispatcher.BeginInvoke(new Action(() =>
            {
                try
                {

                    if (json.Contains("\"keystate\":"))
                    {
                        int start = json.IndexOf("\"keystate\":") + 10;
                        int end = json.IndexOf('}', start);

                        if (end > start)
                        {
                            string valueStr = json.Substring(start, end - start).Trim();
                            if (int.TryParse(valueStr, out int keyValue))
                            {
                                DisplayKey(keyValue);
                                return;
                            }
                        }
                    }

                    tbKey.Text = "Invalid data";
                }
                catch (Exception ex)
                {
                    tbKey.Text = "Parse error";
                }
            }));
        }

        private void DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            try
            {
                string data = serialPort.ReadExisting();
                dataBuffer.Append(data);

                string bufferContent = dataBuffer.ToString();

                
                if (bufferContent.Contains("\r\n"))
                {
                    string[] lines = bufferContent.Split(new[] { "\r\n" }, StringSplitOptions.RemoveEmptyEntries);

                    foreach (string line in lines)
                    {
                        if (line.Contains("{"))
                        {
                            ProcessJson(line);
                        }
                    }

                    
                    dataBuffer.Clear();
                }
            }
            catch (Exception ex)
            {
                Dispatcher.BeginInvoke(new Action(() =>
                {
                    tbKey.Text = "Error: " + ex.Message;
                }));
            }
        }

        private void DisplayKey(int keyValue)
        {
            switch (keyValue)
            {
                case -1:
                    tbKey.Text = "*";
                    break;
                case -2:
                    tbKey.Text = "#";
                    break;
                case 0:
                    tbKey.Text = "No key";
                    break;
                default:
                    if (keyValue >= 1 && keyValue <= 9)
                    {
                        tbKey.Text = keyValue.ToString();
                    }
                    else
                    {
                        tbKey.Text = "?" + keyValue;
                    }
                    break;
            }
        }

        private void BtnDisconnect_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                if (serialPort != null && serialPort.IsOpen)
                {
                    serialPort.Close();
                }
            }
            catch { }

            btnConnect.IsEnabled = true;
            btnDisconnect.IsEnabled = false;
            tbKey.Text = "Disconnected";
            dataBuffer.Clear();
        }

        protected override void OnClosed(EventArgs e)
        {
            if (serialPort != null && serialPort.IsOpen)
            {
                serialPort.Close();
            }
            base.OnClosed(e);
        }
    }
}