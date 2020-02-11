int timer = 1000;                                   // The higher the number, the slower the timing.     
                                                    // Defined the For Loops from 8 - 2 for the first loop so it can run infinitely 

void setup()                                        // Sets up our first loop iteration
{
  for (int light = 2; light < 8; light++)           // Initialize each light within our loop
  {
    pinMode(light, OUTPUT);                         // pinMode configures the light to behave as an input or output
  }
}

void loop()                                         // Loop Function that allows the lights to scroll
{
  for (int light = 2; light < 8; light++)           // Loops the lowest to highest pin
  {                                                 // DigitalWrite sets the voltage of the light as either high or low
    digitalWrite(light, HIGH);                      // Light On
    delay(timer);                                   // Delay pauses the program for a set amount of milliseconds
    digitalWrite(light, LOW);                       // Light Off
  }
  
  for (int light = 7; light >= 2; light--)          // Loops the highest to lowest pin
  {                                                 // DigitalWrite sets the voltage of the light as either high or low
    digitalWrite(light, HIGH);                      // Light On
    delay(timer);                                   // Delay pauses the program for a set amount of milliseconds
    digitalWrite(light, LOW);                       // Light Off
  }
}
