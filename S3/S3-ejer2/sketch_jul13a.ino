void setup()
{
pinMode(7, INPUT);
pinMode(13, OUTPUT);
}
void loop()
{
int val = digitalRead(7); //leer si el interruptor está pulsado o no
digitalWrite(13,!val);
}
