using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace ArudinoInferface
{
    public partial class Form1 : Form
    {
        string sensorval;
        private bool comOpen; 

        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //Get all Portnames 
            string[] Portnames = System.IO.Ports.SerialPort.GetPortNames();

            //Display an error message if no ports are detected
            if (Portnames == null)
            {
                tbRX.Text = "There are no Com Ports detected!";
                this.Close();
            }

            //Add the Portnames in the "ComboBox"
            comboBox1.Items.AddRange(Portnames);
            comboBox1.Text = Portnames[0];
        }

        private void LedOn_Click(object sender, EventArgs e)
        {
            if (!comOpen)
                tbRX.Text = "Not connected"; //If SerialPort is not connected display an error message
            else
            {
                serialPort1.Write("1");
                LedOn.Enabled = false;
                LedOff.Enabled = true;
            }
        }

        private void LedOff_Click(object sender, EventArgs e)
        {
            if (!comOpen)
                tbRX.Text = "Not connected"; //If SerialPort is not connected display an error message
            else
            {
                serialPort1.Write("0");
                LedOn.Enabled = true;
                LedOff.Enabled = false;
            }
        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            sensorval = serialPort1.ReadLine();
            this.Invoke(new EventHandler(DisplayText));
        }

        private void DisplayText(object sender, EventArgs e)
        {
            richTextBox1.AppendText(sensorval);
            richTextBox1.ScrollToCaret();
        }

        private void connect_Click(object sender, EventArgs e)
        {
            // Device parameters
            var _with1 = serialPort1;
            _with1.PortName = comboBox1.Text;
            _with1.BaudRate = 9600;
            _with1.Parity = System.IO.Ports.Parity.None;
            _with1.DataBits = 8;
            _with1.StopBits = System.IO.Ports.StopBits.One;
            _with1.Handshake = System.IO.Ports.Handshake.None;
            _with1.WriteTimeout = 10000;
            _with1.ReadTimeout = 10000;
            _with1.DiscardNull = true;
            
            // check whether device is avaiable: 
            try
            {   //Opens SerialPort Communication
                serialPort1.DiscardNull = true;
                serialPort1.Open();
                comOpen = serialPort1.IsOpen;
                tbRX.Clear();
                tbRX.Text = "Connected";
            }
            catch (Exception arg)
            {
                comOpen = false;
                tbRX.Text = "Error Open: ";
            }

            if (comOpen)
            {
                comboBox1.Enabled = false;
                connect.Enabled = false;
                serialPort1.DataReceived += serialPort1_DataReceived;
            }
        }

        private void disconnect_Click(object sender, EventArgs e)
        {
            if (comOpen)
            {
                serialPort1.DiscardInBuffer(); //Discards data from the Voltmeter
                serialPort1.Close(); //Closes the serial port communication
                tbRX.Clear();  //Clears any text in the textbox
                tbRX.Text = "Disconnected";
            }
            comOpen = false;            //SeriaPort is closed
            comboBox1.Enabled = true;  //"Comboxbox" is enabled
            connect.Enabled = true; //"Connect" button is enabled
        }

        private void Exit_Click(object sender, EventArgs e)
        {
            Application.Exit(); //Function to exit the Application
        }
    }
}
