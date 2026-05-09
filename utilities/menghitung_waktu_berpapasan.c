/*
  NIM     : I0714031
  Nama    : Rizal Nurhidayat
  Program : Program Kereta Berpapasan
*/
#include <stdio.h>
#include <conio.h>

int main()
{
    double kka, kkb, jka, jkb, mka, mkb, ska, skb, stas, sbp;
    double jbka, jbkb, jsk;
    double jtka, jtkb, dd, jj, mm, ss;
    int d, j, m, s, bd, bj, bm, bs, bdd, bjj, bmm, bss, hd, hj, hm, lg;

    printf("===============================================================================\n");
    printf("|                      Program Peramal Kereta Berpapasan                      |\n");
    printf("|                  Dibuat Oleh : Rizal Nurhidayat | I0714031                  |\n");
    printf("===============================================================================\n\n");

lagi:
    printf("Masukan Kecepatan Kereta A (km)\t\t\t : ");
    scanf("%lf", &kka);
    printf("Masukan Jam Berangkat Kereta A (hh mm ss)\t : ");
    scanf("%lf : %lf : %lf", &jka, &mka, &ska);
    printf("Masukan Kecepatan Kereta B (km)\t\t\t : ");
    scanf("%lf", &kkb);
    printf("Masukan Jam Berangkat Kereta B (hh mm ss)\t : ");
    scanf("%lf %lf %lf", &jkb, &mkb, &skb);
    printf("Masukan Jarak Stasiun A dan Stasiun B (km)\t : ");
    scanf("%lf", &stas);

    // Return Value Jam Berangkat Kereta
    jbka = jka + (mka / 60) + (ska / 3600);
    jbkb = jkb + (mkb / 60) + (skb / 3600);

    // Jarak yang digunakan
    if (jbka < jbkb)
    {
        sbp = stas - (kka * (jbkb - jbka));
    }
    else if (jbka > jbkb)
    {
        sbp = stas - (kkb * (jbka - jbkb));
    }
    else if (jbka = jbkb)
    {
        sbp = stas;
    }

    // Hitung Waktu Berpapasan
    jsk = sbp / (kka + kkb);

    // Hitung Jarak Tempuh Masing-Masing Kereta Saat Berpapasan
    if (jbka < jbkb)
    {
        jtka = kka * jsk + (kka * (jbkb - jbka));
        jtkb = kkb * jsk;
    }
    else if (jbka > jbkb)
    {
        jtka = kka * jsk;
        jtkb = kkb * jsk + (kkb * (jbka - jbkb));
    }
    else if (jbka = jbkb)
    {
        jtka = kka * jsk;
        jtkb = kkb * jsk;
    }

    // Return Value Waktu Tempuh Menjadi Hari, Jam, Menit, Detik
    ss = (jsk - (int)jsk) * 3600;
    if (ss < 60)
    {
        s = ss;
    }
    else if (ss >= 60)
    {
        mm = ss / 60;
        m = (int)mm;
        s = ss - (m * 60);
    }

    if (m < 60)
    {
        jj = (int)jsk;
    }
    else if (m >= 60)
    {
        jj = (int)jsk + (int)(m / 60);
    }
    if (j < 24)
    {
        j = jj;
    }
    else if (j >= 24)
    {
        dd = jj / 24;
        d = (int)dd;
        j = jj - (d * 24);
    }
    if (jbka <= jbkb)
    {
        bss = s + skb;
        if (bss < 60)
        {
            bs = bss;
        }
        else if (bss >= 60)
        {
            hm = bss / 60;
            bs = bss - (hm * 60);
        }
        bmm = m + hm + mkb;
        if (bmm < 60)
        {
            bm = bmm;
        }
        else if (bmm >= 60)
        {
            hj = bmm / 60;
            bm = bmm - (hj * 60);
        }
        bjj = j + hj + jkb;
        if (bjj < 24)
        {
            bj = bjj;
        }
        else if (bjj >= 24)
        {
            hd = bjj / 24;
            bj = bjj - (hd * 24);
        }
    }
    else if (jbka > jbkb)
    {
        bss = s + ska;
        if (bss < 60)
        {
            bs = bss;
        }
        else if (bss >= 60)
        {
            hm = bss / 60;
            bs = bss - (hm * 60);
        }
        bmm = m + hm + mka;
        if (bmm < 60)
        {
            bm = bmm;
        }
        else if (bmm >= 60)
        {
            hj = bmm / 60;
            bm = bmm - (hj * 60);
        }
        bjj = j + hj + jka;
        if (bjj < 24)
        {
            bj = bjj;
        }
        else if (bjj >= 24)
        {
            hd = bjj / 24;
            bj = bjj - (hd * 24);
        }
    }

    printf("\n\n===============================================================================\n");
    printf("\n\tJam Berangkat Kereta A dalam Desimal \t : %lf\tJam", jbka);
    printf("\n\tJam Berangkat Kereta B dalam Desimal \t : %lf\tJam", jbkb);
    printf("\n\tJarak Tempuh Kereta A Saat Berpapasan \t : %lf\tKm", jtka);
    printf("\n\tJarak Tempuh Kereta B Saat Berpapasan \t : %lf\tKm", jtkb);
    printf("\n\tWaktu yang Dibutuhkan Untuk Berpapasan \t : %d Jam %d Menit %d Detik", j, m, s);
    if (hd >= 1)
    {
        printf("\n\tKereta Akan Berpapasan Pada Pukul \t : %d:%d:%d %d, Hari Berikutnya\n", bj, bm, bs, hd);
    }
    else if (hd < 1)
    {
        printf("\n\tKereta Akan Berpapasan Pada Pukul \t : %d:%d:%d\n", bj, bm, bs);
    }
    printf("\n===============================================================================\n");

    printf("\nMau mengulang program ini? (Y/N)   : ");
    while ((lg = getchar()) != "N")
    {
        switch (lg)
        {
        case 'Y':
        case 'y':
            goto lagi;
            break;

        case 'N':
        case 'n':
            return (0);
            break;

        case '\n':
        case '\t':
        case ' ':
            break;

        default:
            printf("Huruf yang dimasukkan salah.\n");
            printf("Masukkan opsi huruf baru! (Y/N) %5s", ": ");
            break;
        }
    }
}
