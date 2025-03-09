/**
 * Bu sınıf Oğuzhan Sarıgöl tarafından yazıldı.
 * Tarih : 27/12/2023
 */
#include "RobotOperator.h"
#include "Encryption.h"
#include<iostream>

using namespace std;

RobotOperator::RobotOperator() {
	this->name = this->surname = "";
	this->accessCode = 0;
	this->accessState = false;
}

RobotOperator::RobotOperator(string name, string surname, unsigned int accessCode, bool accessState) {
	this->name = name;
	this->surname = surname;
	this->accessCode = accessCode;
	this->accessState = accessState;
}

int RobotOperator::encryptCode(int code) {
	Encryption enc;
	return enc.encrypt(code);
}


int RobotOperator::decryptCode(int code) {
	Encryption enc;
	return enc.decrypt(code);
}


bool RobotOperator::checkAccessCode(int code) {
	int decryptedCode = decrypt(code);
	return (accessCode == decryptedCode);
}


void RobotOperator::print() {
	cout << "*********************** Robot Operator Info ***********************" << endl;
	cout << "Name = " << name << endl;
	cout << "Surname = " << surname << endl;
	cout << "Access Code = " << accessCode << endl;
	cout << "Access State = " << accessState << endl;
}
