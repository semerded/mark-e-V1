# dear traveler

We are the VEX V5 team from Mosa-RT, Belgium

This is our code for our vex robot named "mark-e"

## who are we?

We are the first team from Belgium that went to the finals in America in 2023
We love building robots and we have a passion for technology

## who wrote the code?

I'm Sem Van Broekhoven, a 17 year old programmer.
I follow IICT at Mosa-RT and I love writing codes.

## structure of the code

The code is written in <b>C++</b>.
The main.cpp file contains the construction of the classes, general variables for the robot and the mapping of functions to the corresponding buttons.<br>
The drivetrain.cpp contains the logic of the robots drivetrain. I rebuild the drivetrain to work with 6 wheels. It also has the ability to switch between slow driving and fast driving (we are using 600RPM motors for the drivetrain).<br>
The pneumatic code has all the essentials to work with the 2 arms (the code is really basic)<br>
autonomous.cpp is the bridge between the bare code and the autoCode. It contains 3 classes to fully control the drivetrain, pneumatics and the shooter for the autonomous code.<br>
autoCode.cpp contains the autonomous code. It contains a struct with 1 function containing the autonomous code. <br>

## testing
the bare code has a testing code. This is to easily check if the basic functionality functions!. The only real way to test the code is to plug it in and test it on the robot.

## ports used

port 1-6: drivetrain
    1. left front
    2. left mid
    3. left rear
    4. right front
    5. right mid
    6. right rear

port 7 and 8: shooting

port A: left arm
port B: right arm

## known bugs with code

<b>most bugs are caused by the vex library</b><br>
- button.pressed can't handle a methode from a class, only a function
- button.pressed doesn't work with both arms, thats why I've used a more difficult solution using button.pressing
- autocode import only works with a class/struct not a function


# have a nice day!