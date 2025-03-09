#ifndef BUMPERSENSOR_H
#define BUMPERSENSOR_H

#include <iostream>
#include "NaoRobotAPI.h"

using namespace std;

/**
 * @brief Robot için bir Bumper Sensörünü temsil eden sınıf.
 */
class BumperSensor {
private:
    bool states[4]; /**< Bumper'ların durumları: 0 -> leftLeft, 1 -> leftRight, 2 -> rightLeft, 3 -> rightRight */
    NaoRobotAPI* robotAPI; /**< NaoRobotAPI nesnesine işaretçi */

public:
    /**
     * @brief BumperSensor sınıfı için yapıcı metod.
     * @param leftLeft Sol sol Bumper'ın durumu.
     * @param leftRight Sol sağ Bumper'ın durumu.
     * @param rightLeft Sağ sol Bumper'ın durumu.
     * @param rightRight Sağ sağ Bumper'ın durumu.
     * @param robotAPI NaoRobotAPI nesnesine işaretçi.
     */
    BumperSensor(bool leftLeft, bool leftRight, bool rightLeft, bool rightRight, NaoRobotAPI* robotAPI);

    /**
     * @brief Belirli bir bumper'ın durumunu alır.
     * @param i Bumper'ın indeksi (0 solLeft, 1 solRight, 2 sağSol, 3 sağSağ).
     * @return Belirtilen bumper'ın durumu.
     */
    bool getState(int i);

    /**
     * @brief Gerçek robot ayak bumper'larına dayanarak sensör durumlarını günceller.
     */
    void updateSensor();

    /**
     * @brief Herhangi bir bumper'ın dokunup dokunmadığını kontrol eder.
     * @return Herhangi bir bumper dokunulmuşsa true, aksi halde false.
     */
    bool checkTouch();

    /**
     * @brief Bumper sensörü hakkında bilgi yazdırır.
     */
    void printBumperSensorInfo();
};

#endif
