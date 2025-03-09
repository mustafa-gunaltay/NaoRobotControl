/**
 * Bu sınıf Oğuzhan Sarıgöl ve Mustafa Günaltay tarafından yazıldı.
 * Tarih : 24/12/2023
 */
#include "ForceSensor.h"

ForceSensor::ForceSensor(double force, NaoRobotAPI* robotAPI) {
	this->force = force;
	this->robotAPI = robotAPI;
}

void ForceSensor::updateSensor() {
	force = robotAPI->getFootForce();
}

double ForceSensor::getForce() const {
	return force;
}

bool ForceSensor::checkFall() {
	return (force < 1);
}

void ForceSensor::printFootForce() const {
	cout << "Foot Force : " << force << " kg.f" << endl;
}