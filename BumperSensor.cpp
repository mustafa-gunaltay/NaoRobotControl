/**
 * Bu sınıf Asrınalp Şahin ve Mustafa Günaltay tarafından yazıldı.
 * Tarih : 21/12/2023
 */
#include "BumperSensor.h"

/**
 * @brief BumperSensor sınıfı için yapıcı metod.
 * @param leftLeft Sol sol Bumper'ın durumu.
 * @param leftRight Sol sağ Bumper'ın durumu.
 * @param rightLeft Sağ sol Bumper'ın durumu.
 * @param rightRight Sağ sağ Bumper'ın durumu.
 * @param robotAPI NaoRobotAPI nesnesine işaretçi.
 */
BumperSensor::BumperSensor(bool leftLeft, bool leftRight, bool rightLeft, bool rightRight, NaoRobotAPI* robotAPI) {
    states[0] = leftLeft;
    states[1] = leftRight;
    states[2] = rightLeft;
    states[3] = rightRight;
    this->robotAPI = robotAPI;
}

/**
 * @brief Belirli bir bumper'ın durumunu alır.
 * @param i Bumper'ın indeksi (0 solLeft, 1 solRight, 2 sağSol, 3 sağSağ).
 * @return Belirtilen bumper'ın durumu.
 */
bool BumperSensor::getState(int i) {
    return states[i];
}

/**
 * @brief Gerçek robot ayak bumper'larına dayanarak sensör durumlarını günceller.
 */
void BumperSensor::updateSensor() {
    bool leftLeft, leftRight, rightLeft, rightRight;
    robotAPI->getFootBumpers(leftLeft, leftRight, rightLeft, rightRight);

    states[0] = leftLeft;
    states[1] = leftRight;
    states[2] = rightLeft;
    states[3] = rightRight;
}

/**
 * @brief Herhangi bir bumper'ın dokunup dokunmadığını kontrol eder.
 * @return Herhangi bir bumper dokunulmuşsa true, aksi halde false.
 */
bool BumperSensor::checkTouch() {
    for (int i = 0; i < 4; i++) {
        if (states[i] == true)
            return true;
    }

    return false;
}

/**
 * @brief Bumper sensörü hakkında bilgi yazdırır.
 */
void BumperSensor::printBumperSensorInfo() {
    if (checkTouch()) {
        cout << "Robot touches somewhere" << endl;
    } else {
        cout << "Robot touches nowhere" << endl;
    }
}
