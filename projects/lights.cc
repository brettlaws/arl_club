const int sensorPin = A5;
const int ledPin = 13;

int sensorCalibration = 0;
int roomLightThreshold = 440; // Unknown
int sensorValue = 0;

void calibrateSensor() {
  sensorCalibration = (analogRead(sensorPin) * -1) + 20;
}

int readSensor() {
  int sensorValue =   analogRead(sensorPin) + sensorCalibration;
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  return sensorValue;
}

bool isRoomLight(int sensorValue) {
  if (sensorValue < roomLightThreshold)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void ledOff() {
  digitalWrite(ledPin, LOW);
}

void ledOn() {
  digitalWrite(ledPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
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