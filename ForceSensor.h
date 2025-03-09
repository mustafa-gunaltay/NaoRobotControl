#ifndef FORCESENSOR_H
#define FORCESENSOR_H

#include <iostream>
#include "NaoRobotAPI.h"
using namespace std;

/**
 * @brief Robot için bir Kuvvet Sensörünü temsil eden sınıf.
 */
class ForceSensor {
private:
    double force; /**< Kuvvet değeri */
    NaoRobotAPI* robotAPI; /**< NaoRobotAPI nesnesine işaretçi */

public:
    /**
     * @brief ForceSensor sınıfı için yapıcı metod.
     * @param force Başlangıçtaki kuvvet değeri.
     * @param robotAPI NaoRobotAPI nesnesine işaretçi.
     */
    ForceSensor(double force, NaoRobotAPI* robotAPI);

    /**
     * @brief Sensörü günceller, gerçek robot ayağının kuvvet değerini alarak.
     */
    void updateSensor();

    /**
     * @brief Kuvvet değerini getirir.
     * @return Kuvvet değeri.
     */
    double getForce() const;

    /**
     * @brief Düşme durumunu kontrol eder.
     * @return Eğer kuvvet 1'den küçükse true, aksi halde false.
     */
    bool checkFall();

    /**
     * @brief Ayağın kuvvet bilgisini ekrana yazdırır.
     */
    void printFootForce() const;
};

#endif
