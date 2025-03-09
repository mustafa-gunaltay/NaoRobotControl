/**
 * Bu sınıf Kübra Nur Durak ve Mustafa Günaltay tarafından yazıldı.
 * Tarih : 26/12/2023
 */
#include <iostream>
#include "RobotControl.h"

using namespace std;

RobotControl::RobotControl(Pose* position, NaoRobotAPI* robotAPI, int state) {
	this->position = position;
	this->robotAPI = robotAPI;
	this->state = state;

	robotAPI->connect();
}

RobotControl::RobotControl(){}

RobotControl::~RobotControl() {
	robotAPI->disconnect();
	delete position;
	delete robotAPI;

}

void RobotControl::turnLeft(int ms) {
	state = LEFT;
	printDirection();
	robotAPI->turnRobot(LEFT);
	Sleep(ms);
	setPose();	
}

void RobotControl::turnRight(int ms) {
	state = RIGHT;
	printDirection();
	robotAPI->turnRobot(RIGHT);
	Sleep(ms);
	setPose();
}

void RobotControl::forward(int ms) {
	state = FORWARD;
	printDirection();
	robotAPI->moveRobot(FORWARD);
	Sleep(ms);
	setPose();
}

void RobotControl::backward(int ms) {
	state = BACKWARD;
	printDirection();
	robotAPI->moveRobot(BACKWARD);
	Sleep(ms);
	setPose();
}

void RobotControl::moveLeft(int ms) {
	state = LEFT;
	printDirection();
	robotAPI->moveRobot(LEFT);
	Sleep(ms);
	setPose();
}

void RobotControl::moveRight(int ms) {
	state = RIGHT;
	printDirection();
	robotAPI->moveRobot(RIGHT);
	Sleep(ms);
	setPose();
}

void RobotControl::stop(int ms) {
	robotAPI->stopRobot();
	Sleep(ms);
	setPose();
}


void RobotControl::print() const {
	cout << "Robot's Pose information : " << endl;
	position->printPoseInfo();
}

void RobotControl::printDirection() const {
	string direction;
	switch (state) {
	case RIGHT:
		direction = "right";
		break;

	case LEFT:
		direction = "left";
		break;

	case FORWARD:
		direction = "forward";
		break;

	case BACKWARD:
		direction = "backward";
		break;
	}

	cout << "Robot's direction = " << direction << endl;
}


Pose RobotControl::getPose() const{
	return (*position);
}

void RobotControl::setPose() {
	position->setX(robotAPI->getX());
	position->setY(robotAPI->getY());
	position->setTh(robotAPI->getTh());
}

NaoRobotAPI* RobotControl::getNaoRobotAPI() const {
	return robotAPI;
}

void RobotControl::connectRobot(NaoRobotAPI* robotAPI) {
	this->robotAPI->connect();
}

void RobotControl::disconnectRobot() {
	robotAPI->disconnect();
}

