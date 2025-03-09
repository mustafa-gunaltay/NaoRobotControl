/**
 * Bu sınıf Metehan Güven ve Mustafa Günaltay tarafından yazıldı.
 * Tarih : 25/12/2023
 */
#include "SonarSensor.h"

SonarSensor::SonarSensor(double leftSensor, double rightSensor, NaoRobotAPI* robotAPI) {
	ranges[0] = leftSensor;
	ranges[1] = rightSensor;
	this->robotAPI = robotAPI;
}

double SonarSensor::getRange(int i) {
	if (i != 0 && i != 1) {
		cout << "Wrong Index" << endl;
		exit(1);
	}

	return ranges[i];
}

double SonarSensor::getMax(int& i) {
	int targetIndex;

	if (ranges[0] > ranges[1]) {
		targetIndex = 0;
		i = targetIndex;
		return ranges[0];
	}
	else {
		targetIndex = 1;
		i = targetIndex;
		return ranges[1];
	}
}

double SonarSensor::getMin(int& i) {
	int targetIndex;

	if (ranges[0] < ranges[1]) {
		targetIndex = 0;
		i = targetIndex;
		return ranges[0];
	}
	else {
		targetIndex = 1;
		i = targetIndex;
		return ranges[1];
	}
}


void SonarSensor::updateSensor() {
	double left, right;
	robotAPI->getSonarRange(left, right);

	ranges[0] = left;
	ranges[1] = right;
}

double SonarSensor::operator[](int i) {
	return ranges[i];
}

void SonarSensor::printSonarInfo() const {
	cout << "SONAR RANGES : (LEFT) " << ranges[0] << " meters, (RIGHT) " << ranges[1] << " meters" << endl;
}
