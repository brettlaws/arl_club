const int sensorPin = 0;
const int ledPin = 9;

int sensorCalibration = 0;
int roomLightThreshold = 0; // Unknown
int sensorValue = 0;

void calibrateSensor()
{
    sensorCalibration = analogRead(sensorPin) * -1;
}

int readSensor()
{
    int sensorValue = analogRead(sensorPin) + sensorCalibration;
    Serial.print("Sensor Value: ");
    Serial.println(sensorValue);
    return sensorValue;
}

bool isRoomLight(int sensorValue)
{
    if (sensorValue < roomLightThreshold)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void ledOff()
{
    digitalWrite(ledPin, LOW);
}

void ledOn()
{
    digitalWrite(ledPin, HIGH);
}

void setup()
{
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);

    calibrateSensor();
}

void loop()
{
    sensorValue = readSensor();

    if (isRoomLight(sensorValue) == true)
    {
        ledOff();
    }
    else
    {
        ledOn();
    }
}
