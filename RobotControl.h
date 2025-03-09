#ifndef ROBOTCONTROL_H
#define ROBOTCONTROL_H

#include <iostream>
#include "Pose.h"
#include "NaoRobotAPI.h"

using namespace std;

/**
 * @brief Robotun hareketlerini kontrol eden sınıf.
 */
class RobotControl {
private:
	Pose* position; /**< Robotun konumunu saklayan Pose sınıfı pointer'ı. */
	NaoRobotAPI* robotAPI; /**< Robot API'sini kullanmak için NaoRobotAPI sınıfı pointer'ı. */
	int state; /**< Robotun durumunu belirten durum değişkeni. */

public:
	/**
	 * @brief Varsayılan yapıcı metod.
	 */
	RobotControl();

	/**
	 * @brief Parametre alan yapıcı metod.
	 * @param position Robotun başlangıç konumu.
	 * @param robotAPI Robot API'sini kullanmak için NaoRobotAPI sınıfı pointer'ı.
	 * @param state Robotun başlangıç durumu.
	 */
	RobotControl(Pose* position, NaoRobotAPI* robotAPI, int state);

	/**
	 * @brief Yıkıcı metod.
	 */
	~RobotControl();

	/**
	 * @brief Robotu sola döndüren metod.
	 * @param angle Dönüş açısı.
	 */
	void turnLeft(int angle);

	/**
	 * @brief Robotu sağa döndüren metod.
	 * @param angle Dönüş açısı.
	 */
	void turnRight(int angle);

	/**
	 * @brief Robotu ileri doğru hareket ettiren metod.
	 * @param distance Hareket mesafesi.
	 */
	void forward(int distance);

	/**
	 * @brief Robotu geriye doğru hareket ettiren metod.
	 * @param distance Hareket mesafesi.
	 */
	void backward(int distance);

	/**
	 * @brief Robotun konumunu ekrana yazdıran metod.
	 */
	void print() const;

	/**
	 * @brief Robotun yönünü ekrana yazdıran metod.
	 */
	void printDirection() const;

	/**
	 * @brief Robotun mevcut konumunu döndüren metod.
	 * @return Robotun mevcut konumu.
	 */
	Pose getPose() const;

	/**
	 * @brief Robotun konumunu ayarlayan metod.
	 */
	void setPose();

	/**
	 * @brief Robot API'sini döndüren metod.
	 * @return NaoRobotAPI sınıfı pointer'ı.
	 */
	NaoRobotAPI* getNaoRobotAPI() const;

	/**
	 * @brief Robotu sola kaydıran metod.
	 * @param distance Kayma mesafesi.
	 */
	void moveLeft(int distance);

	/**
	 * @brief Robotu sağa kaydıran metod.
	 * @param distance Kayma mesafesi.
	 */
	void moveRight(int distance);

	/**
	 * @brief Robotu durduran metod.
	 * @param time Durdurma süresi.
	 */
	void stop(int time);

	/**
	 * @brief Robot API'sine bağlanan metod.
	 * @param robotAPI NaoRobotAPI sınıfı pointer'ı.
	 */
	void connectRobot(NaoRobotAPI* robotAPI);

	/**
	 * @brief Robot API'sinden ayrılan metod.
	 */
	void disconnectRobot();
};

#endif // ROBOTCONTROL
