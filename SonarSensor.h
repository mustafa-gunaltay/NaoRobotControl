#ifndef SONARSENSOR_H
#define SONARSENSOR_H

#include <iostream>
#include "NaoRobotAPI.h"
using namespace std;

/**
 * @brief Sonar sensörünü temsil eden sınıf.
 */
class SonarSensor {
private:
	double ranges[2]; /**< Sonar sensöründen alınan mesafe değerlerini saklayan dizi. */
	NaoRobotAPI* robotAPI; /**< Sonar sensörü verilerini okumak için NaoRobotAPI sınıfı pointer'ı. */

public:
	/**
	 * @brief Parametre alan yapıcı metod.
	 * @param range1 İlk mesafe değeri.
	 * @param range2 İkinci mesafe değeri.
	 * @param robotAPI Sonar sensörü verilerini okumak için NaoRobotAPI sınıfı pointer'ı.
	 */
	SonarSensor(double range1, double range2, NaoRobotAPI* robotAPI);

	/**
	 * @brief Belirtilen indeksteki mesafe değerini döndüren metod.
	 * @param index Döndürülecek mesafe değerinin indeksi.
	 * @return Belirtilen indeksteki mesafe değeri.
	 */
	double getRange(int index);

	/**
	 * @brief Belirtilen indeksteki mesafe değerini döndüren metod.
	 * @param index Döndürülecek mesafe değerinin indeksi.
	 * @return Belirtilen indeksteki mesafe değeri.
	 */
	double operator[](int index);

	/**
	 * @brief Maksimum mesafe değerini ve indeksini döndüren metod.
	 * @param maxIndex Maksimum mesafe değerinin indeksini saklayan referans.
	 * @return Maksimum mesafe değeri.
	 */
	double getMax(int& maxIndex);

	/**
	 * @brief Minimum mesafe değerini ve indeksini döndüren metod.
	 * @param minIndex Minimum mesafe değerinin indeksini saklayan referans.
	 * @return Minimum mesafe değeri.
	 */
	double getMin(int& minIndex);

	/**
	 * @brief Sonar sensöründen yeni verileri okuyan metod.
	 */
	void updateSensor();

	/**
	 * @brief Sonar sensörünün bilgilerini ekrana yazdıran metod.
	 */
	void printSonarInfo() const;
};

#endif // SONARSENSOR_H
