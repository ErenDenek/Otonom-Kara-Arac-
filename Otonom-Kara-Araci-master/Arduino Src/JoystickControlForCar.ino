int rM, lM;
int in1 = 6, in2 = 9, in3 = 10, in4 = 11;
int speedCar = 10, wheelCar = 10, recordData = 1;
unsigned long calX, calY;
String sendData;
char sends[50];
void setup() {

  Serial.begin(9600);


  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  digitalWrite(2, 1);
  for (int i = 0; i < 5000; i++)
  {
    calX = calX + analogRead(A0);
    calY = calY + analogRead(A1);
  }
  calX = calX / 5000;
  calY = calY / 5000;

}

void loop() {
  motor();
}
void motor()
{
  speedCar = (analogRead(A0) - calX) / 4;
  wheelCar = (analogRead(A1) - calY) / 4;

  if (wheelCar <= 0)
  {
    lM = speedCar;
    rM = speedCar  - wheelCar;
  }
  else if (wheelCar > 0)
  {
    rM = speedCar;
    lM = speedCar  + wheelCar;
  }

  if (rM < speedCar)rM = speedCar;
  else if (rM > 255) rM = 255;
  if (lM < speedCar)lM = speedCar;
  else if (lM > 255) lM = 255;


  sendRaspi();
  analogWrite(6, lM);
  analogWrite(9, 0);
  analogWrite(10, rM);
  analogWrite(11, 0);

  /*  Serial.print("X :");Serial.print(analogRead(A0));
    Serial.print("Y :");Serial.print(analogRead(A1));
    Serial.print("Right : "); Serial.print(rM);
    Serial.print(" Left : "); Serial.println(lM);*/

}

void sendRaspi()
{
  sendData = "#"+ String(557) + "|" + String(1) + "|" + ",";
  sendData.toCharArray(sends,50);
  Serial.println(sends);
  /*Serial.print(60);
    Serial.print('|');
    Serial.println(recordData);*/

}
