const int a = 8;                // For displaying Top Line
const int b = 9;                // For displaying Top Right Line
const int c = 4;                // For displaying Bottom Right Line
const int d = 5;                // For displaying Bottom Line
const int e = 6;                // For displaying Bottom Left Line
const int f = 2;                // For displaying Top Left Line
const int g = 3;                // For displaying Middle Line
bool buttonPress = false;            // Defaulted to false so numbers dont change on their own
const int IncbuttonPin = 10;         // Specific for the config of the button
const int DecbuttonPin = 11;         // Specific for the config of the button

// Variables will change:
int Pushes = 0;                 // Button Press Counter
int currentIncButtonState = 0;         // current state of the button
int currentDecButtonState = 0;         // current state of the button
int previousIncButtonState = 0;     // previous state of the button
int previousDecButtonState = 0;     // previous state of the button

void setup() 
{
  pinMode(a, OUTPUT);           // Top Line
  pinMode(b, OUTPUT);           // Top Right Line
  pinMode(c, OUTPUT);           // Bottom Right Line
  pinMode(d, OUTPUT);           // Bottom Line
  pinMode(e, OUTPUT);           // Bottom Left Line
  pinMode(f, OUTPUT);           // Top Left Line
  pinMode(g, OUTPUT);           // Middle Line
  pinMode( IncbuttonPin , INPUT_PULLUP ); //Connect a button with external pull down resistor
  pinMode( DecbuttonPin , INPUT_PULLUP ); //Connect a button with external pull down resistor
  Serial.begin(9600);           // Sets the data rate in bits per second
  displayNumbers(Pushes);  // Displays the number onto Arduino
}

void loop() 
{  
  currentIncButtonState = digitalRead(IncbuttonPin);     // Confirms the Arduino pin number we're reading
  currentDecButtonState = digitalRead(DecbuttonPin);     // Confirms the Arduino pin number we're reading
  checkIncButtonPress();                          // Function that allows numbers to increment up to 9 and no higher
  checkDecButtonPress();                          // Function that brings the numbers back to 0
  if( buttonPress )
  {
    buttonPress = false;              
    turnOff();                      
    displayNumbers(Pushes);
  }
}

void checkIncButtonPress()
{
   // compare the IncbuttonState to its previous state
  if (currentIncButtonState != previousIncButtonState) 
  {
    // if the state has changed, increment the counter
    if (currentIncButtonState == LOW) 
    {
      // if the current state is HIGH then the button went from off to on:
      buttonPress = true;
      Pushes++;
      if( Pushes > 9) Pushes =0 ;
      Serial.println("on");       // print as a String
    } 
    else 
    {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");      // prints as a String
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  previousIncButtonState = currentIncButtonState;
}

void checkDecButtonPress()
{
   // compare the IncbuttonState to its previous state
  if (currentDecButtonState != previousDecButtonState) 
  {
    // if the state has changed, increment the counter
    if (currentDecButtonState == LOW) 
    {
      // if the current state is HIGH then the button went from off to on:
      buttonPress = true;
      Pushes--;
      if( Pushes < 0) Pushes =9 ;
      Serial.println("on");      
    } 
    else 
    {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  previousDecButtonState = currentDecButtonState;
}  

void displayNumbers(int numbers)
{
 //Conditions for displaying Top Line
 if(numbers!=1 && numbers != 4)
 digitalWrite(a,HIGH);
 
 //Conditions for displaying Top Right Line
 if(numbers != 5 && numbers != 6)
 digitalWrite(b,HIGH);
 
 //Conditions for displaying Bottom Right Line
 if(numbers !=2)
 digitalWrite(c,HIGH);
 
 //Conditions for displaying Bottom Line
 if(numbers != 1 && numbers !=4 && numbers !=7)
 digitalWrite(d,HIGH);
 
 //Conditions for displaying Bottom Left Line 
 if(numbers == 2 || numbers ==6 || numbers == 8 || numbers==0)
 digitalWrite(e,HIGH);
 
 //Conditions for displaying Top Left Line
 if(numbers != 1 && numbers !=2 && numbers!=3 && numbers !=7)
 digitalWrite(f,HIGH);
 
 //Conditions for displaying Middle Line
 if (numbers!=0 && numbers!=1 && numbers !=7)
 digitalWrite(g,HIGH);
}
void turnOff()
{
  // Function that turns off all of the lights
  digitalWrite(a,LOW);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
}
