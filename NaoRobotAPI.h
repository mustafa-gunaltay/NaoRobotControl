#ifndef NAOROBOTAPI_H
#define NAOROBOTAPI_H



#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <process.h>
#include <windows.h>

enum DIRECTION {
	FORWARD = 0,
	BACKWARD,
	LEFT,
	RIGHT
};

using namespace std;

class NaoRobotAPI {
public:
	// Constructor
	NaoRobotAPI();

	// Connects to the simulated robot and makes initializations
	void connect();

	// Close the connection to the simulated robot
	void disconnect();

	//The robot moves a few steps  
	//Move directions can be {FORWARD, BACKWARD, LEFT, RIGHT}
	void moveRobot(DIRECTION);

	// The robot turns 
	// Move directions can be {LEFT, RIGHT}
	void turnRobot(DIRECTION);

	// The robot stops
	void stopRobot();

	// Returns the sonar range values which are located on the chest of the robot
	// in meters
	void getSonarRange(double& left, double& right);

	// Returns the position of the robot on x-axis in meters
	double getX();

	// Returns the position of the robot on y-axis int meters
	double getY();

	// Returns the orientation of the robot about z-axis in degrees
	double getTh();

	// On the front of the foot of the robots, there are four bumper sensors
	// False if no touch, true if foot touch to an obstacle. 
	void getFootBumpers(bool& leftFoot_left, bool& leftFoot_right,
		bool& rightFoot_left, bool& rightFoot_right);

	//Returns the total force at the bottom of the foot in Kgf.
	double getFootForce();

};

#endif // !NAOROBOTAPI_H