int g1 = 13;
int y1 = 12;
int r1 = 11;
int g2 = 10;
int y2 = 9;
int r2 = 8;
int g3 = 7;
int y3 = 6;
int r3 = 5;
int g4 = 4;
int y4 = 3;
int r4 = 1;
int count = 0;
char input[12];
boolean flag = 0;
int ty = 1000;
int tg = 3000;
void setup() {
Serial.begin(9600);
pinMode (r1, OUTPUT);
pinMode (y1, OUTPUT);
pinMode (g1, OUTPUT);
pinMode (r2, OUTPUT);
pinMode (y2, OUTPUT);
pinMode (g2, OUTPUT);
pinMode (r3, OUTPUT);
pinMode (y3, OUTPUT);
pinMode (g3, OUTPUT);
pinMode (r4, OUTPUT);
pinMode (y4, OUTPUT);
pinMode (g4, OUTPUT);
attachInterrupt(0, rfid, HIGH);
}
void loop()
{
lane1();
lane2();
lane3();
lane4();
}
void lane1()
{
digitalWrite(g1, LOW);
digitalWrite(g2, LOW);
digitalWrite(g3, LOW);
digitalWrite(g4, LOW);
digitalWrite(r1, HIGH);
digitalWrite(r2, HIGH);
digitalWrite(r3, HIGH);
digitalWrite(r4, HIGH);
digitalWrite(y1, HIGH);
digitalWrite(y2, HIGH);
digitalWrite(y3, LOW);
digitalWrite(y4, LOW);
delay(ty);
digitalWrite(g1, HIGH);
digitalWrite(g2, LOW);
digitalWrite(g3, LOW);
digitalWrite(g4, LOW);
digitalWrite(r1, LOW);
digitalWrite(r2, HIGH);
digitalWrite(r3, HIGH);
digitalWrite(r4, HIGH);
digitalWrite(y1, LOW);
digitalWrite(y2, LOW);
digitalWrite(y3, LOW);
digitalWrite(y4, LOW);
delay(tg);
}
void lane2()
{
digitalWrite(g1, LOW);
digitalWrite(g2, LOW);
digitalWrite(g3, LOW);
digitalWrite(g4, LOW);
digitalWrite(r1, HIGH);
digitalWrite(r2, HIGH);
digitalWrite(r3, HIGH);
digitalWrite(r4, HIGH);
digitalWrite(y1, LOW);
digitalWrite(y2, HIGH);
digitalWrite(y3, HIGH);
digitalWrite(y4, LOW);
delay(ty);
10
digitalWrite(g1, LOW);
digitalWrite(g2, HIGH);
digitalWrite(g3, LOW);
digitalWrite(g4, LOW);
digitalWrite(r1, HIGH);
digitalWrite(r2, LOW);
digitalWrite(r3, HIGH);
digitalWrite(r4, HIGH);
digitalWrite(y1, LOW);
digitalWrite(y2, LOW);
digitalWrite(y3, LOW);
digitalWrite(y4, LOW);
delay(tg);
}
void lane3()
{
digitalWrite(g1, LOW);
digitalWrite(g2, LOW);
digitalWrite(g3, LOW);
digitalWrite(g4, LOW);
digitalWrite(r1, HIGH);
digitalWrite(r2, HIGH);
digitalWrite(r3, HIGH);
digitalWrite(r4, HIGH);
digitalWrite(y1, LOW);
digitalWrite(y2, LOW);
digitalWrite(y3, HIGH);
digitalWrite(y4, HIGH);
delay(ty);
digitalWrite(g1, LOW);
digitalWrite(g2, LOW);
digitalWrite(g3, HIGH);
digitalWrite(g4, LOW);
digitalWrite(r1, HIGH);
digitalWrite(r2, HIGH);
digitalWrite(r3, LOW);
digitalWrite(r4, HIGH);
digitalWrite(y1, LOW);
digitalWrite(y2, LOW);
digitalWrite(y3, LOW);
digitalWrite(y4, LOW);
delay(tg);
}
void lane4()
{
digitalWrite(g1, LOW);
digitalWrite(g2, LOW);
digitalWrite(g3, LOW);
digitalWrite(g4, LOW);
digitalWrite(r1, HIGH);
digitalWrite(r2, HIGH);
digitalWrite(r3, HIGH);
digitalWrite(r4, HIGH);
digitalWrite(y1, HIGH);
digitalWrite(y2, LOW);
digitalWrite(y3, LOW);
digitalWrite(y4, HIGH);
delay(ty);
digitalWrite(g1, LOW);
digitalWrite(g2, LOW);
digitalWrite(g3, LOW);
digitalWrite(g4, HIGH);
digitalWrite(r1, HIGH);
digitalWrite(r2, HIGH);
digitalWrite(r3, HIGH);
digitalWrite(r4, LOW);
digitalWrite(y1, LOW);
digitalWrite(y2, LOW);
digitalWrite(y3, LOW);
digitalWrite(y4, LOW);
delay(tg);
}
void rfid()
{
if (Serial.available())
{
count = 0;
while (Serial.available() && count < 12)
{
input[count] = Serial.read();
count++;
delay(5);
}
Serial.print(input);
Serial.println("ambulance ");
lane1();