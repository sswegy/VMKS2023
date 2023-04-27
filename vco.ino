#define PITCH A0
#define SPEAKER 3
#define SWITCH 2

void setup() 
{
  pinMode(PITCH, INPUT);
  pinMode(SPEAKER, OUTPUT);
  pinMode(SWITCH, INPUT);
}

float analogToHerz(int analog) 
{
  if (analog < 17)
    return 0;
  return 65.4 * pow(1.059463094359, analog / 17.05);
}

void arpeggiate(int analog) 
{
  float note1, note2, note3;
  note1 = analogToHerz(analog);
  note2 = note1 * pow(1.059463094359, 7);
  note3 = note2 * pow(1.059463094359, 13);

  tone(SPEAKER, note1, 100);
  delay(100);
  tone(SPEAKER, note2, 100);
  delay(100);
  tone(SPEAKER, note3, 100);
  delay(100);
  tone(SPEAKER, note2, 100);
  delay(100);
}

void loop() 
{
  int p = analogToHerz(analogRead(PITCH));

  if (digitalRead(SWITCH))
    arpeggiate(analogRead(PITCH));
  else
    tone(SPEAKER, p);
}
