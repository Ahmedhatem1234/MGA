# MGA
We started by moving the first finger base to the right position, Then started making more finger bases at the statues where we identified the point of the rotation of the finger base, Each new base had transformation relative to  its correct place, Then popped the statues back to determine the new point of rotation and we pushed it to the stack, we did the second part of the finger and added more parts each time transforming them to the correct place.
When we decided to add the thump we did not want to use the status which made it rotate on the same axes. So we popped the stack once more and begun determining the points that we want it to rotate around in and changed the axes at the last point to rotate around the x-axis.
Our last modification was at the switch case
We didn't like the fact that the joints could rotate at 360 degrees, So we added condition that would limit the movement to only 180 degrees  if the angle exceeded it then it would break without increasing it
