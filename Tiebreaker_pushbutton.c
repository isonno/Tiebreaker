//
// This sketch implements a "Jeopardy" style contestant response tiebreaker.
//
// Each contestant has a pushbutton switch. When they know the answer,
// they push it.  This turns on the corresponding light.
// The light for the first person to push their button blinks.
//
// Pressing the reset switch restarts the game.
//
// J. Peterson, Apr '12
//

// The LEDs, cathodes connected to ground
int Lights[3] = {13, 12, 11};

// The pushbutton switches connect the input to ground when closed.
int Switches[3] = { 10, 9, 8 };

// Connect to ground to reset the game
int Reset = 7;

// Set to -1 when no winner set.
int winner;

boolean SwitchPushed[3] = { false, false, false };

void setup()
{
  int i;
  for (i = 0; i < 3; i++)
  {
    pinMode(Lights[i], OUTPUT);

    pinMode(Switches[i], INPUT);
    digitalWrite(Switches[i], HIGH);  // Enable pullup

    pinMode( Reset, INPUT );
    digitalWrite( Reset, HIGH );    // Enable pullup
  }

  LightsOff();
}

// Reset to the initial state.
void LightsOff()
{
  int i;
  winner = -1;
  for (i = 0; i < 3; i++)
  {
    digitalWrite( Lights[i], LOW);
    SwitchPushed[i] = false;
  }
}

void loop()
{
  int i;

  // If no winner selected, first button selects the winner.
  if (winner == -1)
  {
    for (i = 0; (i < 3) && (winner == -1); i++)
      if (digitalRead( Switches[i] ) == LOW)
        winner = i;
  }
  else
  {
     for (i = 0; i < 3; i++)
     {
       if (i == winner)  // Blink winner's light
       {
         if (((millis() /100) % 10) & 1)
           digitalWrite( Lights[winner], HIGH );
          else
            digitalWrite( Lights[winner], LOW );
       }
       else
       {
         // When switch is pushed, record it.
         if (digitalRead( Switches[i] ) == LOW)
           SwitchPushed[i] = true;

         // Display non-winner lights
         digitalWrite( Lights[i], SwitchPushed[i] ? HIGH : LOW );
       }
     }
  }

  // Reset button
  if (digitalRead( Reset ) == LOW)
    LightsOff();
}
