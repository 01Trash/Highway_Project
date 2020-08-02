#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Turkish");

	double H_proje, asinma, binder, bitumlu_temel, pmt, pmat, Sofset, Sorta, Sbanket, Dever, Fark_ofset;
	double H_ofset_terasman, Ha_ofset_terasman, H_Orta_terasman, Ha_Orta_terasman, H_banket_terasman, Ha_banket_terasman;

		// Bilinenleri isteyelim.
	// H; Proje kotu
	printf("Proje kotu (H) değerini giriniz: ");
	scanf("%lf", &H_proje);
	// Üst yapı kalınlıkları (Pmat, Pmt, Bitümlü temel, Binder ve Aşınma);
	//printf(" === Üst yapı kalınlıkları! === \n");
	printf("Üst yapı kalınlığı AŞINMA değerini giriniz: ");
	scanf("%lf", &asinma);
	printf("Üst yapı kalınlığı BİNDER değerini giriniz: ");
	scanf("%lf", &binder);
	printf("Üst yapı kalınlığı BİTÜMLÜ TEMEL değerini giriniz: ");
	scanf("%lf", &bitumlu_temel);
	printf("Üst yapı kalınlığı PMT değerini giriniz: ");
	scanf("%lf", &pmt);
	printf("Üst yapı kalınlığı PMAT değerini giriniz: ");
	scanf("%lf", &pmat);
	// Refüj mesafesi; Eksen ofset; Sofset
	printf("Refüj mesafesi değerini giriniz: ");
	scanf("%lf", &Sofset);
	// Yol orta mesafesi; Proje orta mesafe; Sorta
	printf("Yol orta mesafesi değerini giriniz: ");
	scanf("%lf", &Sorta);
	// Yol banket mesafesi; Proje banket mesafe; Sbanket
	printf("Yol banket mesafesi değerini giriniz: ");
	scanf("%lf", &Sbanket);
	// Dever; Yolun enine eğimi
	printf("Dever +/- değerini giriniz: ");
	scanf("%lf", &Dever);
	// Fark_Eksen/Orta/Banket; Proje terasman kotlarından Eksen/Orta/Banket olmak üzere, arazide yapılan nivelman sonrası kot değerleri arasındaki fark değerleridir.
	printf("Arazide yapılan nivelman sonrası kot değerleri arasındaki fark değerini giriniz: ");
	scanf("%lf", &Fark_ofset);

		// Bilinmeyenlerin hesaplanması;
	printf("\n\t=== Hesap sonuçları! === \n");
	/* Terasman eksen ofset kotlarının hesaplanması
	H_ofset_terasman = H_proje - (pmat + pmt + bitumlu_temel + binder + asinma); */
	H_ofset_terasman = H_proje - (pmat + pmt + bitumlu_temel + binder + asinma);
	printf("Terasman eksen ofset kotlarının değeri: %f\n", H_ofset_terasman);
	/* Arazi terasman eksen ofset kotlarının hesaplanması
	Ha_ofset_terasman = H_ofset_terasman + Fark_ofset; */
	Ha_ofset_terasman = H_ofset_terasman + Fark_ofset;
	printf("Arazi terasman eksen ofset kotlarının değeri: %f\n", Ha_ofset_terasman);
	/* Terasman orta mesafe kotlarının hesaplanması
	H_Orta_terasman = H_ofset_terasman - (((Dever / 100) * -1) * (Sorta - Sofset)); */
	H_Orta_terasman = H_ofset_terasman - (((Dever / 100) * -1) * (Sorta - Sofset));
	printf("Terasman orta mesafe kotlarının değeri: %f\n", H_Orta_terasman);
	/* Arazi terasman orta mesafe kotlarının hesaplanması
	Ha_Orta_terasman = H_Orta_terasman + Fark_ofset; */
	Ha_Orta_terasman = H_Orta_terasman + Fark_ofset;
	printf("Arazi terasman orta mesafe kotlarının değeri: %f\n", Ha_Orta_terasman);
	/* Terasman banket kotlarının hesaplanması
	H_banket_terasman = H_ofset_terasman - (((Dever / 100) * -1) * (Sbanket - Sofset)); */
	H_banket_terasman = H_ofset_terasman - (((Dever / 100) * -1) * (Sbanket - Sofset));
	printf("Terasman banket kotlarının değeri: %f\n", H_banket_terasman);
	/* Arazi terasman banket kotlarının hesaplanması
	Ha_banket_terasman = H_banket_terasman + Fark_ofset; */
	Ha_banket_terasman = H_banket_terasman + Fark_ofset;
	printf("Arazi terasman banket kotlarının değeri: %f\n", Ha_banket_terasman);

	return 0;
}
