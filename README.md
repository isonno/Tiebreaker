# Tiebreaker
Tiebreaker game for the Aurduino. This was originally posted to the [Adafruit forum](https://forums.adafruit.com/viewtopic.php?f=25&t=20729&p=140028) years ago.

It implements a "Tie breaker" used in games like Jeopardy. The light for the first person to flip their switch or push their button comes on, all the others stay off.  The implementation is for the [Aurduino UNO](https://store.arduino.cc/usa/arduino-uno-rev3). No schematics, just follow the hookup instructions in the opening comments.

The original `Tiebreaker.c` uses toggle switches for the contestents. The `Tiebreaker_pushbutton.c` version uses pushbuttons, along with a separate Reset button to restart the game.

There's no schematic necessary, just follow the hook-up instructions in the comments.
