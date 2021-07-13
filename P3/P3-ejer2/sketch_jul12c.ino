void setup()
{
  pinMode(7, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
   
}


void loop()
{
  
  int val = digitalRead(7);

  digitalWrite(13, val);
  digitalWrite(12, !val);
  digitalWrite(11, !val);
   
}
