
int dir1 = 10;
int steps1 = 6;
int dir2 = 9;
int steps2 = 5;


void setup() {
  // put your setup code here, to run once:
  pinMode(dir1, OUTPUT);
  pinMode(steps1, OUTPUT);
  pinMode(dir2, OUTPUT);
  pinMode(steps2, OUTPUT);
  digitalWrite(dir1, HIGH);
  digitalWrite(dir2, LOW);
  for (int i = 0; i < 100; i++) {
    digitalWrite(steps1, HIGH);
    digitalWrite(steps2, HIGH);
    delay(10);
    digitalWrite(steps1, LOW);
    digitalWrite(steps2, LOW);
    delay(10);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dir1, HIGH - digitalRead(dir1));
  digitalWrite(dir2, HIGH - digitalRead(dir2));
  for (int i = 0; i < 200; i++) {
    digitalWrite(steps1, HIGH);
    digitalWrite(steps2, HIGH);
    delay(10);
    digitalWrite(steps1, LOW);
    digitalWrite(steps2, LOW);
    delay(10);
  }

}
