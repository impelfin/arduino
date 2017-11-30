const int NB_DIGITS     = 4;  // 4-digit display
const int FIRST_ANODE   = 2;  // anodes a..g on pins 2..8
const int FIRST_CATHODE = 9;  // cathodes, right to left, on pins 9..12

// Digits to display, from right to left.
uint8_t digits[NB_DIGITS];

// Set all the used pins as outputs.
void init_display()
{
    for (int i = 0; i < 7; i++)
        pinMode(FIRST_ANODE + i, OUTPUT);
    for (int i = 0; i < NB_DIGITS; i++)
        pinMode(FIRST_CATHODE + i, OUTPUT);
}

// This should be called periodically.
void refresh_display()
{
    // Our 7-segment "font".
    static const uint8_t font[10] = {
        //abcdefg
        0b1111110, // 0
        0b0110000, // 1
        0b1101101, // 2
        0b1111001, // 3
        0b0110011, // 4
        0b1011011, // 5
        0b1011111, // 6
        0b1110000, // 7
        0b1111111, // 8
        0b1111011  // 9
    };

    // Wait for 2.5 ms before switching digits.
    static uint32_t last_switch;
    uint32_t now = micros();
    if (now - last_switch < 2500) return;
    last_switch = now;

    // Switch off the current digit.
    static uint8_t pos;
    digitalWrite(FIRST_CATHODE + pos, LOW);

    // Set the anodes for the next digit.
    pos = (pos + 1) % NB_DIGITS;
    uint8_t glyph = font[digits[pos]];
    for (int i = 0; i < 7; i++)
        digitalWrite(FIRST_ANODE + i, glyph & 1 << (6-i));

    // Switch digit on.
    digitalWrite(FIRST_CATHODE + pos, HIGH);
}

/***********************************************************************
 * Example usage.
 */

void setup()
{
    init_display();
}

void loop()
{
    uint32_t now = millis();

    // Change the number displayed every second.
    static uint32_t last_change;
    if (now - last_change >= 1000) {
        digits[3] = digits[2];
        digits[2] = digits[1];
        digits[1] = digits[0];
        digits[0] = (digits[0] + 1) % 10;
        last_change = now;
    }

    refresh_display();
}
