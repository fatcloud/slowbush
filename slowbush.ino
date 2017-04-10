#define LED_PIN 2
#define FREQ_IN_PIN 2



void setup()
{
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
}

void loop()
{
    int freq = analogRead(FREQ_IN_PIN);
    freq = freq / 6.0 + 16.0;
    long latency = 1000000 / freq;
    digitalWrite(LED_PIN, HIGH);
    delayMicroseconds(latency * 0.1);
    digitalWrite(LED_PIN, LOW);
    delayMicroseconds(latency * 0.9);

    Serial.println(String(latency) + "  "+String(freq));
}

