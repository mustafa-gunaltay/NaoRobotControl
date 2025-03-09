/**
 * Bu sınıf Metehan Güven ve Mustafa Günaltay tarafından yazıldı.
 * Tarih : 25/12/2023
 */
#include<iostream>
#include<math.h>
#include <cmath>
#include"Pose.h"

#define PI 3.14159265358979323846

using namespace std;

Pose::Pose() :x(0), y(0), th(0) {}
Pose::Pose(double x, double y, double th) :x(x), y(y), th(th) {}
double Pose::getX() const {
	return x;
}
void Pose::setX(double x) {
	this->x = x;
}
double Pose::getY() const {
	return y;
}
void Pose::setY(double y) {
	this->y = y;
}
double Pose::getTh() const {
	return th;
}
void Pose::setTh(double th) {
	this->th = th;
}
bool Pose::operator==(const Pose& pose) {
	return (this->x == pose.x && this->y == pose.y && this->th == pose.th);
}
Pose Pose::operator+(const Pose& pose) {
	Pose result;
	if (this->getTh() == pose.getTh()) {
		result.setX(this->x + pose.getX());
		result.setY(this->y + pose.getY());
		result.setTh(this->getTh() + pose.getTh());
	}
	else {
		result.setX(pose.getX());
		result.setY(pose.getY());
		result.setTh(pose.getTh());
	}
	
	return result;
}
Pose Pose::operator-(const Pose& pose) {
	Pose result;
	if (this->getTh() == pose.getTh()) {
		result.setX(this->x - pose.getX());
		result.setY(this->y - pose.getY());
		result.setTh(this->getTh() - pose.getTh());
	}
	else {
		result.setX(pose.getX());
		result.setY(pose.getY());
		result.setTh(pose.getTh());
	}
	return result;
}
Pose& Pose::operator+=(const Pose& pose) {
	if (this->getTh() == pose.getTh()) {
		this->x += pose.getX();
		this->y += pose.getY();
		this->th += pose.getTh();
	}
	return (*this);
}
Pose& Pose::operator-=(const Pose& pose) {
	if (this->getTh() == pose.getTh()) {
		this->x -= pose.getX();
		this->y -= pose.getY();
		this->th -= pose.getTh();
	}
	return (*this);
}
bool Pose::operator<(const Pose& pose) {
	return (this->x < pose.getX()) && (this->y < pose.getY());
}
void Pose::getPose(double& x, double& y, double& th) const {
	x = this->x;
	y = this->y;
	th = this->th;
}
void Pose::setPose(double x, double y, double th) {
	this->x = x;
	this->y = y;
	this->th = th;
}
double Pose::findDistanceTo(Pose x) {
	double result;
	double side1 = x.getY() - this->y;
	double side2 = x.getX() - this->x;
	
	result = sqrt(pow(side1, 2) + pow(side2, 2));
	return result;
}

double Pose::findAngleTo(Pose p) {

	double radian, degree;

	radian = atan(this->findSlope(p));
	degree = radian * (180.0 / PI);

	return degree;
}



double Pose::absoluteDifferenceX(Pose p) {
	if (this->x - p.getX() > 0) {
		return (this->x - p.getX());
	}
	else {
		return (p.getX() - this->x);
	}
}

double Pose::absoluteDifferenceY(Pose p) {
	if (this->y - p.getY() > 0) {
		return (this->y - p.getY());
	}
	else {
		return (p.getY() - this->y);
	}
}

double Pose::findSlope(Pose p) {
	return ((this->y - p.getY()) / (this->x - p.getX()));
}

void Pose::printPoseInfo() {
	cout << "x = " << this->x << endl;
	cout << "y = " << this->y << endl;
	cout << "th = " << this->th << endl;
}


// + , - , += , -= operatorulerinin mantiklarini kontrol et

/*
double absoluteDifferenceX(Pose);
double absoluteDifferenceY(Pose p);
double findSlope(Pose);
void printPoseInfo();

	fonksiyonlarina doxygen comment ekle
*/