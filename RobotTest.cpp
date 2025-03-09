/**
 * Bu sınıf Mustafa Günaltay tarafından yazıldı.
 * Tarih : 29/12/2023
 */
#include <iostream>
#include "NaoRobotAPI.h"
#include <Windows.h>
#include "Pose.h"
#include "RobotControl.h"
#include "SonarSensor.h"
#include "BumperSensor.h"
#include "ForceSensor.h"
#include "Encryption.h"
#include "RobotOperator.h"


using namespace std;

void PoseTest();
void RobotControlTest();
void SonarSensorTest();
void BumperSensorTest();
void ForceSensorTest();
void EncryptionTest();
void RobotOperatorTest();

NaoRobotAPI* nao;

int main() {

	//PoseTest();
	//RobotControlTest();
	//SonarSensorTest();
	//BumperSensorTest();
	//ForceSensorTest();
	//EncryptionTest();
	//RobotOperatorTest();


	return 0;
}

void PoseTest() {
	Pose p1(3, 5, 60);
	Pose p2(6, 9, 30);

	bool b = p1 == p2;
	cout << "Is p1 and p2 equal = " << b << endl << endl;;

	Pose p3 = p1 + p2;
	cout << "p1 + p2 : " << endl;
	p3.printPoseInfo();
	cout << endl;

	p3 = p1 - p2;
	cout << "p1 - p2 : " << endl;
	p3.printPoseInfo();
	cout << endl;

	Pose tempP1 = p1;
	Pose tempP2 = p2;
	tempP1 += tempP2;
	cout << "p1 += p2 :" << endl;
	tempP1.printPoseInfo();
	cout << endl;

	tempP1 = p1;
	tempP2 = p2;
	tempP1 -= tempP2;
	cout << "p1 -= p2 :" << endl;
	tempP1.printPoseInfo();
	cout << endl;

	b = p1 < p2;
	cout << "p1 < p2  = " << b << endl << endl;

	cout << "p1.findDistanceTo(p2) = " << p1.findDistanceTo(p2) << endl;
	cout << "p2.findDistanceTo(p1) = " << p2.findDistanceTo(p1) << endl << endl;

	cout << "p1.absoluteDifferenceX(p2) = " << p1.absoluteDifferenceX(p2) << endl;
	cout << "p2.absoluteDifferenceX(p1) = " << p2.absoluteDifferenceX(p1) << endl;
	cout << "p1.absoluteDifferenceY(p2) = " << p1.absoluteDifferenceY(p2) << endl;
	cout << "p2.absoluteDifferenceY(p1) = " << p2.absoluteDifferenceY(p1) << endl << endl;

	cout << "p1.findSlope(p2) = " << p1.findSlope(p2) << endl;
	cout << "p2.findSlope(p1) = " << p2.findSlope(p1) << endl << endl;

	cout << "p1.findAngleTo(p2) = " << p1.findAngleTo(p2) << endl;
	cout << "p2.findAngleTo(p1) = " << p2.findAngleTo(p1) << endl;

}

void RobotControlTest() {

	NaoRobotAPI* nao = nullptr;
	Pose* p = new Pose(3, 5, 60);

	RobotControl* rc = new RobotControl(p, nao, FORWARD);
	SonarSensor* ss = new SonarSensor(0, 0, rc->getNaoRobotAPI());
	BumperSensor* bs = new BumperSensor(false, false, false, false, rc->getNaoRobotAPI());
	ForceSensor* fc = new ForceSensor(0, rc->getNaoRobotAPI());

	rc->forward(10000);
	rc->print();
	cout << endl;
	ss->updateSensor();
	ss->printSonarInfo();
	cout << endl;
	bs->updateSensor();
	bs->printBumperSensorInfo();
	cout << endl;
	fc->updateSensor();
	cout << "Robot's fall status = " << fc->checkFall() << endl;
	fc->printFootForce();
	cout << endl;
	cout << endl;

	rc->turnRight(10000);
	rc->print();
	cout << endl;
	ss->updateSensor();
	ss->printSonarInfo();
	cout << endl;
	bs->updateSensor();
	bs->printBumperSensorInfo();
	cout << endl;
	fc->updateSensor();
	cout << "Robot's fall status = " << fc->checkFall() << endl;
	fc->printFootForce();
	cout << endl;
	cout << endl;

	rc->backward(10000);
	rc->print();
	cout << endl;
	ss->updateSensor();
	ss->printSonarInfo();
	cout << endl;
	bs->updateSensor();
	bs->printBumperSensorInfo();
	cout << endl;
	fc->updateSensor();
	cout << "Robot's fall status = " << fc->checkFall() << endl;
	fc->printFootForce();
	cout << endl;
	cout << endl;

	rc->moveRight(10000);
	rc->print();
	cout << endl;
	ss->updateSensor();
	ss->printSonarInfo();
	cout << endl;
	bs->updateSensor();
	bs->printBumperSensorInfo();
	cout << endl;
	fc->updateSensor();
	cout << "Robot's fall status = " << fc->checkFall() << endl;
	fc->printFootForce();
	cout << endl;
	cout << endl;

	rc->moveLeft(10000);
	rc->print();
	cout << endl;
	ss->updateSensor();
	ss->printSonarInfo();
	cout << endl;
	bs->updateSensor();
	bs->printBumperSensorInfo();
	cout << endl;
	fc->updateSensor();
	cout << "Robot's fall status = " << fc->checkFall() << endl;
	fc->printFootForce();
	cout << endl;
	cout << endl;

	rc->turnLeft(10000);
	rc->print();
	cout << endl;
	ss->updateSensor();
	ss->printSonarInfo();
	cout << endl;
	bs->updateSensor();
	bs->printBumperSensorInfo();
	cout << endl;
	fc->updateSensor();
	cout << "Robot's fall status = " << fc->checkFall() << endl;
	fc->printFootForce();
	cout << endl;
	cout << endl;

	rc->stop(10000);
	rc->print();
	cout << endl;
	ss->updateSensor();
	ss->printSonarInfo();
	cout << endl;
	bs->updateSensor();
	bs->printBumperSensorInfo();
	cout << endl;
	fc->updateSensor();
	cout << "Robot's fall status = " << fc->checkFall() << endl;
	fc->printFootForce();
	cout << endl;
	cout << endl;

	rc->forward(10000);
	rc->print();
	cout << endl;
	ss->updateSensor();
	ss->printSonarInfo();
	cout << endl;
	bs->updateSensor();
	bs->printBumperSensorInfo();
	cout << endl;
	fc->updateSensor();
	cout << "Robot's fall status = " << fc->checkFall() << endl;
	fc->printFootForce();
	cout << endl;
	cout << endl;

}

void SonarSensorTest() {

	NaoRobotAPI* nao = nullptr;

	Pose* p = new Pose(0, 0, 0);
	RobotControl* rc = new RobotControl(p, nao, FORWARD);
	SonarSensor* ss = new SonarSensor(0, 0, rc->getNaoRobotAPI());

	int maxValueIndex;
	int minValueIndex;

	rc->forward(10000);
	ss->updateSensor();
	rc->print();
	ss->printSonarInfo();
	cout << "Max Sonar Value = " << ss->getMax(maxValueIndex) << endl;
	cout << "Min Sonar Value = " << ss->getMax(minValueIndex) << endl;
	cout << "Min Sonar Value with operator[] = " << (*ss)[minValueIndex] << endl;
	cout << "Min Sonar Value with getRange() = " << ss->getRange(minValueIndex) << endl;
	cout << endl;

	rc->turnRight(10000);
	ss->updateSensor();
	rc->print();
	ss->printSonarInfo();
	cout << "Max Sonar Value = " << ss->getMax(maxValueIndex) << endl;
	cout << "Min Sonar Value = " << ss->getMax(minValueIndex) << endl;
	cout << "Max Sonar Value with operator[] = " << (*ss)[maxValueIndex] << endl;
	cout << "Max Sonar Value with getRange() = " << ss->getRange(maxValueIndex) << endl;
	cout << endl;

	rc->forward(10000);
	ss->updateSensor();
	ss->printSonarInfo();
	cout << endl;

	rc->moveLeft(10000);
	ss->updateSensor();
	ss->printSonarInfo();
	cout << endl;
}


void BumperSensorTest() {

	NaoRobotAPI* nao = nullptr;

	Pose* p = new Pose(0, 0, 0);
	RobotControl* rc = new RobotControl(p, nao, FORWARD);
	BumperSensor* bs = new BumperSensor(false, false, false, false, rc->getNaoRobotAPI());

	rc->forward(10000);
	rc->print();
	bs->updateSensor();
	bs->printBumperSensorInfo();
	cout << "LeftFoot left touch state = " << bs->getState(0) << endl;
	cout << endl;

	rc->turnLeft(10000);
	rc->print();
	bs->updateSensor();
	bs->printBumperSensorInfo();
	cout << "LeftFoot right touch state = " << bs->getState(1) << endl;
	cout << endl;

	rc->forward(10000);
	rc->print();
	bs->updateSensor();
	bs->printBumperSensorInfo();
	cout << "RightFoot left touch state = " << bs->getState(2) << endl;
	cout << endl;

	rc->moveRight(10000);
	rc->print();
	bs->updateSensor();
	bs->printBumperSensorInfo();
	cout << "RightFoot right touch state = " << bs->getState(3) << endl;
	cout << endl;
}

void ForceSensorTest() {

	NaoRobotAPI* nao = nullptr;

	Pose* p = new Pose(0, 0, 0);
	RobotControl* rc = new RobotControl(p, nao, FORWARD);
	ForceSensor* fc = new ForceSensor(0, rc->getNaoRobotAPI());

	rc->forward(10000);
	rc->print();
	fc->updateSensor();
	cout << "Robot's fall status = " << fc->checkFall() << endl;
	fc->printFootForce();
	cout << endl;

	rc->turnLeft(10000);
	rc->print();
	fc->updateSensor();
	cout << "Robot's fall status = " << fc->checkFall() << endl;
	fc->printFootForce();
	cout << endl;


	rc->forward(10000);
	rc->print();
	fc->updateSensor();
	cout << "Robot's fall status = " << fc->checkFall() << endl;
	fc->printFootForce();
	cout << endl;

	rc->moveRight(10000);
	rc->print();
	fc->updateSensor();
	cout << "Robot's fall status = " << fc->checkFall() << endl;
	fc->printFootForce();
	cout << endl;
}


void EncryptionTest() {

	Encryption* e = new Encryption();

	int originalNum = 3749;
	int encryptedNum = e->encrypt(originalNum);
	int decryptedNum = e->decrypt(encryptedNum);

	cout << "Original Num = " << originalNum << endl;
	cout << "Encrypted Num = " << encryptedNum << endl;
	cout << "Decrypted Num = " << decryptedNum << endl;

	if (originalNum == decryptedNum) {
		cout << "Encryption and Decryption is successful" << endl;
	}
	else {
		cout << "Encryption and Decryption is unsuccessful" << endl;
	}


}



void RobotOperatorTest() {
	Encryption* e = new Encryption();
	int originalNum = 3749;
	int encryptedNum = e->encrypt(originalNum);
	int decryptedNum = e->decrypt(encryptedNum);

	RobotOperator* ro = new RobotOperator("Ahmet", "Arslan", decryptedNum, true);

	if (ro->checkAccessCode(encryptedNum)) {
		cout << "Access Code is same" << endl;
	}
	else {
		cout << "Access Code is not same" << endl;
	}
	cout << endl;

	ro->print();

	getchar();
}
