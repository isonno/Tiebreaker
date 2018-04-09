//
// This sketch implements a "Jeopardy" style contestant response tiebreaker.
//
// Each contestant has a toggle switch. When they know the answer, 
// they flip it on.  This turns on the corresponding light.   
// The light for the first person to flip their switch on blinks.
//
// Turning all of the switches off resets it.
//
// J. Peterson, Apr '11
//


// The LEDs, cathodes connected to ground
int Lights[3] = {13, 12, 11};

// The toggle switches connect the input to ground when closed.
int Switches[3] = { 10, 9, 8 };

// Set to -1 when no winner set.
int winner;

void setup()
{
  int i;
  for (i = 0; i < 3; i++)
  {
    pinMode(Lights[i], OUTPUT);
    
    pinMode(Switches[i], INPUT);
    digitalWrite(Switches[i], HIGH);  // Enable pullup
  }
  winner = -1;
  LightsOff();
}

void LightsOff()
{
  int i;
  for (i = 0; i < 3; i++)
    digitalWrite( Lights[i], LOW);
}

int invert( int value )
{
  return value == HIGH ? LOW : HIGH;
}

void loop()
{
  int i;
  if (winner == -1)
  {
    // Scan the switches looking for a winner
    for (i = 0; (i < 3) && (winner == -1); i++)
      if (digitalRead( Switches[i] ) == LOW)
        winner = i;
  }
  else
  {

     for (i = 0; i < 3; i++)
     {
       if (i == winner)
       {
         // Blink the winner's light every 100ms
         if (((millis() /100) % 10) & 1)
           digitalWrite( Lights[winner], HIGH );
         else
           digitalWrite( Lights[winner], LOW );
       }
       else   // Turn loser's lights on if switches are on
         digitalWrite( Lights[i], invert( digitalRead( Switches[i] )));
     }
  }

  // Check to see if all the switches are off,
  // and reset the winner & lights if so.
  if ((digitalRead( Switches[0] ) == HIGH)
     && (digitalRead( Switches[1] ) == HIGH)
     && (digitalRead( Switches[2] ) == HIGH))
   {
     winner = -1;
     LightsOff();
   }
}
