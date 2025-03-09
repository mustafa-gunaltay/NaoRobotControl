#pragma once
#include<string>
#include<iostream>
#include "Encryption.h"

using namespace std;

/**
 * @brief Robot operatörünü temsil eden sınıf.
 * @details Encryption sınıfından genişletilmiştir.
 */
class RobotOperator : public Encryption { // RobotOperator class publicly inherits from the Encryption class
private:
	string name; /**< İsim bilgisini saklayan string değişkeni. */
	string surname; /**< Soyisim bilgisini saklayan string değişkeni. */
	unsigned int accessCode; /**< Şifrelenmiş erişim kodunu tutan unsigned int değişkeni. */
	bool accessState; /**< Erişim durumunu tutan bool değişkeni. */

	/**
	 * @brief Kodu şifreleyen özel metot.
	 * @param code Şifrelenecek kod.
	 * @return Şifrelenmiş kodu döndürür.
	 */
	int encryptCode(int code);

	/**
	 * @brief Şifrelenmiş kodu çözen özel metot.
	 * @param code Çözülecek kod.
	 * @return Çözülmüş kodu döndürür.
	 */
	int decryptCode(int code);

public:
	/**
	 * @brief Varsayılan yapıcı metod.
	 */
	RobotOperator();

	/**
	 * @brief Parametre alan yapıcı metod.
	 * @param name İsim bilgisi.
	 * @param surname Soyisim bilgisi.
	 * @param accessCode Erişim kodu.
	 * @param accessState Erişim durumu.
	 */
	RobotOperator(string name, string surname, unsigned int accessCode, bool accessState);

	/**
	 * @brief Erişim kodunu kontrol eden metod.
	 * @param code Kontrol edilecek kod.
	 * @return Girilen kodun şifreli accessCode ile aynı olup olmadığını döndürür.
	 */
	bool checkAccessCode(int code);

	/**
	 * @brief Operatörün adını, soyadını ve erişim durumunu ekrana yazdıran metod.
	 */
	void print();
};
