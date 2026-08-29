// Fire Fighting Robot
// ESP32 + L298N + 2 DC Motors + 3 Flame Sensors + Water Pump

// -------- Flame Sensors --------
#define FLAME_LEFT    34
#define FLAME_CENTER  35
#define FLAME_RIGHT   32

// -------- L298N Motor Driver --------
#define IN1 25
#define IN2 26
#define IN3 27
#define IN4 14

// -------- Water Pump / Relay --------
#define PUMP 13

// Flame sensor threshold
// Adjust this value according to your sensor
#define FIRE_THRESHOLD 500

void setup()
{
  Serial.begin(115200);

  // Flame sensors
  pinMode(FLAME_LEFT, INPUT);
  pinMode(FLAME_CENTER, INPUT);
  pinMode(FLAME_RIGHT, INPUT);

  // Motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Pump
  pinMode(PUMP, OUTPUT);

  stopCar();
  digitalWrite(PUMP, LOW);

  Serial.println("Fire Fighting Robot Started");
}

void loop()
{
  int leftValue   = analogRead(FLAME_LEFT);
  int centerValue = analogRead(FLAME_CENTER);
  int rightValue  = analogRead(FLAME_RIGHT);

  Serial.print("Left: ");
  Serial.print(leftValue);

  Serial.print(" | Center: ");
  Serial.print(centerValue);

  Serial.print(" | Right: ");
  Serial.println(rightValue);

  // ------------------------------------------------
  // FIRE DETECTION
  // ------------------------------------------------

  if (centerValue < FIRE_THRESHOLD &&
      centerValue < leftValue &&
      centerValue < rightValue)
  {
    // Fire is in front
    Serial.println("🔥 FIRE IN FRONT");

    moveForward();
    delay(300);

    stopCar();

    // Move close to fire
    if (centerValue < 250)
    {
      Serial.println("🔥 Fire is CLOSE - Pump ON");

      digitalWrite(PUMP, HIGH);
      delay(3000);

      digitalWrite(PUMP, LOW);

      stopCar();
      delay(1000);
    }
  }

  else if (leftValue < FIRE_THRESHOLD &&
           leftValue < rightValue)
  {
    // Fire is on left
    Serial.println("🔥 FIRE ON LEFT");

    turnLeft();
    delay(300);
    stopCar();
  }

  else if (rightValue < FIRE_THRESHOLD &&
           rightValue < leftValue)
  {
    // Fire is on right
    Serial.println("🔥 FIRE ON RIGHT");

    turnRight();
    delay(300);
    stopCar();
  }

  else
  {
    // No fire detected
    Serial.println("No Fire");

    stopCar();
    digitalWrite(PUMP, LOW);
  }

  delay(100);
}

// =================================================
// MOTOR FUNCTIONS
// =================================================

// Move Forward
void moveForward()
{
  // Left motor
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Move Backward
void moveBackward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// Turn Left
void turnLeft()
{
  // Left motor STOP
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  // Right motor FORWARD
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// Turn Right
void turnRight()
{
  // Left motor FORWARD
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Right motor STOP
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Stop both motors
void stopCar()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
