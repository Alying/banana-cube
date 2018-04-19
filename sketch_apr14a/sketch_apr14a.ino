void turnOn(int x, int y, int z) {
  digitalWrite(23 + (x + 4*y)*2, LOW);
  digitalWrite(2 + z, HIGH);
}

void turnOff(int x, int y, int z) {
  digitalWrite(23 + (x + 4*y)*2, HIGH);
  digitalWrite(2 + z, LOW);
}

void toggle(int x, int y, int z, int t) {
  turnOn(x,y,z);
  delay(t);
  turnOff(x,y,z);
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  for (int i = 23; i <= 53; i += 2) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }

  for (int i = 2; i <= 5; ++i) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int k = 0; k < 4; ++k) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      toggle(i,j,k,10);
    }
  }
  }

  for (int k = 0; k < 4; ++k) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      turnOn(i,j,k);
    }
  }
  delay(500);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      turnOff(i,j,k);
    }
  }
  }

  
  for (int j = 0; j < 4; ++j) {
  for (int i = 0; i < 4; ++i) {
    for (int k = 0; k < 4; ++k) {
      turnOn(i,j,k);
    }
  }
  delay(500);
  for (int i = 0; i < 4; ++i) {
    for (int k = 0; k < 4; ++k) {
      turnOff(i,j,k);
    }
  }
  }

  for (int i = 0; i < 4; ++i) {
  for (int j = 0; j < 4; ++j) {
    for (int k = 0; k < 4; ++k) {
      turnOn(i,j,k);
    }
  }
  delay(500);
  for (int j = 0; j < 4; ++j) {
    for (int k = 0; k < 4; ++k) {
      turnOff(i,j,k);
    }
  }
  }

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      for (int k = 0; k < 4; ++k) {
        turnOn(i,j,k);
      }
      delay(200);
      for (int k = 0; k < 4; ++k) {
        turnOff(i,j,k);
      }
    }
  }
}
