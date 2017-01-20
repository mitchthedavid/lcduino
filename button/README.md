# lcduino with a button
What good is a screen if you can't control anything on it? With this is mind, I wired a button into my lcduino case, and opted to create a 30-second timer.

##Setup
You'll need to connect your lcd screen to your Arduino as shown in the main README. From there, you can connect a button fairly easily. Note that the button needs to connect to the same 5v as the screen, so you may need to get creative if you're not using a breadboard.

###Wiring Diagram
![official Arduino diagram](https://www.arduino.cc/en/uploads/Tutorial/button.png)


From there, you're good to add the 'timer' sketch, which can be found in the 'button' folder, to your Arduino. Once the button is pressed, it counts down from 30, while changing the backlight color from blue to green, displays a message saying that the timer is done, then resets, allowing for the timer to be run again.

In the future, I intend to figure out a way of adding more hardware controls so that different durations can be used.  
