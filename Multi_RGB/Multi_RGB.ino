// Initializing values as integers
int currentRed = 0, currentGreen = 0, currentBlue = 0;
int previousRed, previousGreen, previousBlue;

// Sets pinMode OUTPUT so the colors are able to display properly
void setup() 
{
  pinMode(9, OUTPUT);           // Set as blue value to output
  pinMode(10, OUTPUT);          // Set as green value to output
  pinMode(11, OUTPUT);          // Set as red value to output
}

// Loop that controls random hex values for our 3 main colors
void loop() 
{
  // Decrements the values when the current values are bigger than the previous
  if (currentRed  > previousRed)
  {
    currentRed --;
  }

  // Increments the values when the previous values and bigger than the current
  else if (currentRed  < previousRed)
  {
    currentRed ++;
  }

  // Set New Values if the values are equal
  else
  {
    previousRed = random(0, 255);
  }

  // Decrements the values when the current values are bigger than the previous
  if (currentGreen > previousGreen)
  {
    currentGreen--;
  }

  // Increments the values when the previous values and bigger than the current
  else if (currentGreen < previousGreen)
  {
    currentGreen++;
  }

  // Set New Values if the values are equal
  else
  {
    previousGreen = random(0, 255);
  }

  // Decrements the values when the current values are bigger than the previous
  if (currentBlue > previousBlue)
  {
    currentBlue--;
  }

  // Increments the values when the previous values and bigger than the current
  else if (currentBlue < previousBlue)
  {
    currentBlue++;
  }

  // Set New Values if the values are equal
  else
  {
    previousBlue = random(0, 255);
  }
 
  // Using Pulse Width Modulation to write an analog value to a pin
  // PWM reduces the average power from an electrical signal
  // Writes the values as a int between 0 - 255
  analogWrite(11, currentRed);
  analogWrite(10, currentGreen);
  analogWrite(9, currentBlue);
  
  // Controls the speed of the light, changing will make it faster/slower
  delay(5);
}
