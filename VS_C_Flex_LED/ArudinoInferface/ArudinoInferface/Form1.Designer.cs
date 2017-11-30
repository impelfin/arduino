namespace ArudinoInferface
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다.
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마십시오.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.serialPort1 = new System.IO.Ports.SerialPort(this.components);
            this.LedOn = new System.Windows.Forms.Button();
            this.LedOff = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.tbRX = new System.Windows.Forms.TextBox();
            this.connect = new System.Windows.Forms.Button();
            this.disconnect = new System.Windows.Forms.Button();
            this.Exit = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // LedOn
            // 
            this.LedOn.BackColor = System.Drawing.Color.Blue;
            this.LedOn.Font = new System.Drawing.Font("굴림", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.LedOn.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.LedOn.Location = new System.Drawing.Point(15, 28);
            this.LedOn.Name = "LedOn";
            this.LedOn.Size = new System.Drawing.Size(102, 39);
            this.LedOn.TabIndex = 0;
            this.LedOn.Text = "LED ON";
            this.LedOn.UseVisualStyleBackColor = false;
            this.LedOn.Click += new System.EventHandler(this.LedOn_Click);
            // 
            // LedOff
            // 
            this.LedOff.BackColor = System.Drawing.Color.Red;
            this.LedOff.Font = new System.Drawing.Font("굴림", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.LedOff.ForeColor = System.Drawing.SystemColors.ButtonFace;
            this.LedOff.Location = new System.Drawing.Point(123, 28);
            this.LedOff.Name = "LedOff";
            this.LedOff.Size = new System.Drawing.Size(102, 39);
            this.LedOff.TabIndex = 1;
            this.LedOff.Text = "LED OFF";
            this.LedOff.UseVisualStyleBackColor = false;
            this.LedOff.Click += new System.EventHandler(this.LedOff_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("굴림", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.label1.Location = new System.Drawing.Point(12, 80);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(104, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "Sensor Value";
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(12, 96);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(210, 202);
            this.richTextBox1.TabIndex = 3;
            this.richTextBox1.Text = "";
            // 
            // comboBox1
            // 
            this.comboBox1.Font = new System.Drawing.Font("굴림", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Location = new System.Drawing.Point(250, 98);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(121, 21);
            this.comboBox1.TabIndex = 4;
            this.comboBox1.Text = "COM1";
            // 
            // tbRX
            // 
            this.tbRX.BackColor = System.Drawing.Color.Azure;
            this.tbRX.Font = new System.Drawing.Font("굴림", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tbRX.Location = new System.Drawing.Point(-2, 314);
            this.tbRX.Name = "tbRX";
            this.tbRX.Size = new System.Drawing.Size(391, 22);
            this.tbRX.TabIndex = 5;
            // 
            // connect
            // 
            this.connect.BackColor = System.Drawing.Color.SpringGreen;
            this.connect.Font = new System.Drawing.Font("굴림", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.connect.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.connect.Location = new System.Drawing.Point(250, 139);
            this.connect.Name = "connect";
            this.connect.Size = new System.Drawing.Size(121, 39);
            this.connect.TabIndex = 6;
            this.connect.Text = "Connect";
            this.connect.UseVisualStyleBackColor = false;
            this.connect.Click += new System.EventHandler(this.connect_Click);
            // 
            // disconnect
            // 
            this.disconnect.BackColor = System.Drawing.Color.DarkGoldenrod;
            this.disconnect.Font = new System.Drawing.Font("굴림", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.disconnect.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.disconnect.Location = new System.Drawing.Point(250, 199);
            this.disconnect.Name = "disconnect";
            this.disconnect.Size = new System.Drawing.Size(121, 39);
            this.disconnect.TabIndex = 7;
            this.disconnect.Text = "Disconnect";
            this.disconnect.UseVisualStyleBackColor = false;
            this.disconnect.Click += new System.EventHandler(this.disconnect_Click);
            // 
            // Exit
            // 
            this.Exit.BackColor = System.Drawing.Color.Firebrick;
            this.Exit.Font = new System.Drawing.Font("굴림", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.Exit.ForeColor = System.Drawing.SystemColors.ButtonHighlight;
            this.Exit.Location = new System.Drawing.Point(250, 260);
            this.Exit.Name = "Exit";
            this.Exit.Size = new System.Drawing.Size(121, 38);
            this.Exit.TabIndex = 10;
            this.Exit.Text = "Exit";
            this.Exit.UseVisualStyleBackColor = false;
            this.Exit.Click += new System.EventHandler(this.Exit_Click);
            // 
            // Form1
            // 
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.None;
            this.ClientSize = new System.Drawing.Size(388, 335);
            this.Controls.Add(this.Exit);
            this.Controls.Add(this.disconnect);
            this.Controls.Add(this.connect);
            this.Controls.Add(this.tbRX);
            this.Controls.Add(this.comboBox1);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.LedOff);
            this.Controls.Add(this.LedOn);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedToolWindow;
            this.Name = "Form1";
            this.Text = "Arduino Interface";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.IO.Ports.SerialPort serialPort1;
        private System.Windows.Forms.Button LedOn;
        private System.Windows.Forms.Button LedOff;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.TextBox tbRX;
        private System.Windows.Forms.Button connect;
        private System.Windows.Forms.Button disconnect;
        private System.Windows.Forms.Button Exit;
    }
}

