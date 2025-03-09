#ifndef POSE_H
#define POSE_H

#include<iostream>

using namespace std;

/**
 * @brief Konum bilgisini temsil eden sınıf.
 */
class Pose {
private:
	double x; /**< x koordinatı */
	double y; /**< y koordinatı */
	double th; /**< açı (radyan cinsinden) */
public:
	/**
	 * @brief Varsayılan yapıcı metod.
	 */
	Pose();

	/**
	 * @brief Belirtilen değerlerle yapıcı metod.
	 * @param x x koordinatı
	 * @param y y koordinatı
	 * @param th açı (radyan cinsinden)
	 */
	Pose(double x, double y, double th);

	/**
	 * @brief x koordinatını döndürür.
	 * @return x koordinatı.
	 */
	~Pose() {}

	/**
	 * @brief x koordinatını döndürür.
	 * @return x koordinatı.
	 */
	double getX() const;

	/**
	 * @brief x koordinatını ayarlar.
	 * @param x x koordinatı.
	 */
	void setX(double);

	/**
	 * @brief y koordinatını döndürür.
	 * @return y koordinatı.
	 */
	double getY() const;

	/**
	 * @brief y koordinatını ayarlar.
	 * @param y y koordinatı.
	 */
	void setY(double);

	/**
	 * @brief Açıyı döndürür.
	 * @return Açı (radyan cinsinden).
	 */
	double getTh() const;

	/**
	 * @brief Açıyı ayarlar.
	 * @param th Açı (radyan cinsinden).
	 */
	void setTh(double);

	/**
	 * @brief İki konumun eşit olup olmadığını kontrol eder.
	 * @param pose Karşılaştırılacak konum.
	 * @return Eşitse true, değilse false.
	 */
	bool operator==(const Pose&);

	/**
	 * @brief İki konumu toplar.
	 * @param pose Toplanacak konum.
	 * @return Toplam konumu.
	 */
	Pose operator+(const Pose&);

	/**
	 * @brief İki konumu çıkarır.
	 * @param pose Çıkarılacak konum.
	 * @return Fark konumu.
	 */
	Pose operator-(const Pose&);

	/**
	 * @brief İki konumu toplar ve mevcut konumu günceller.
	 * @param pose Toplanacak konum.
	 * @return Güncellenmiş konum.
	 */
	Pose& operator+=(const Pose&);

	/**
	 * @brief İki konumu çıkarır ve mevcut konumu günceller.
	 * @param pose Çıkarılacak konum.
	 * @return Güncellenmiş konum.
	 */
	Pose& operator-=(const Pose&);

	/**
	 * @brief Bu konumun, parametre olarak girilen konumdan küçük olup olmadığını kontrol eder.
	 * @param pose Karşılaştırılacak konum.
	 * @return Bu konum küçükse true, değilse false.
	 */
	bool operator<(const Pose&);

	/**
	 * @brief x, y ve th değerlerini döndürür.
	 * @param x x koordinatı (referans ile)
	 * @param y y koordinatı (referans ile)
	 * @param th açı (radyan cinsinden) (referans ile)
	 */
	void getPose(double&, double&, double&) const;

	/**
	 * @brief x, y ve th değerlerini ayarlar.
	 * @param x x koordinatı
	 * @param y y koordinatı
	 * @param th açı (radyan cinsinden)
	 */
	void setPose(double, double, double);

	/**
	 * @brief Bu konumdan parametre olarak girilen konuma olan uzaklığı hesaplar.
	 * @param x Hesaplanacak uzaklık için diğer konum.
	 * @return Uzaklık değeri.
	 */
	double findDistanceTo(Pose);

	/**
	 * @brief Bu konumdan parametre olarak girilen konuma olan açıyı hesaplar.
	 * @param p Hesaplanacak açı için diğer konum.
	 * @return Açı değeri.
	 */
	double findAngleTo(Pose);

	/**
	 * @brief Bu konumun x koordinatının parametre olarak girilen konumun x koordinatına olan mutlak farkını hesaplar.
	 * @param p Hesaplanacak fark için diğer konum.
	 * @return Mutlak fark değeri.
	 */
	double absoluteDifferenceX(Pose);

	/**
	 * @brief Bu konumun y koordinatının parametre olarak girilen konumun y koordinatına olan mutlak farkını hesaplar.
	 * @param p Hesaplanacak fark için diğer konum.
	 * @return Mutlak fark değeri.
	 */
	double absoluteDifferenceY(Pose p);

	/**
	 * @brief Bu konumdan parametre olarak girilen konuma doğru eğimi hesaplar.
	 * @param p Eğimi hesaplanacak diğer konum.
	 * @return Eğim değeri.
	 */
	double findSlope(Pose);

	/**
	 * @brief Konum bilgilerini ekrana yazdırır.
	 */
	void printPoseInfo();
};

#endif
