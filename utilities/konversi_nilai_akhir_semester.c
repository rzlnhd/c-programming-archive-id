/*
  NIM     : I0714031
  Nama    : Rizal Nurhidayat
  Website : http://clever-society.blogspot.com/
  Program : Pengolah Nilai Akhir Semester (NAS) (Success) FIX
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char dataNAME[34][8] = {
        "Abid", "Adit", "Aji F", "Andry", "Rico", "Ardan", "Bima", "Bina", "Boni", "Dwiyan", "Edi N",
        "Fadilah", "Fasda", "Febry", "Ferdy", "Rian", "Igor", "Irfan", "Luthfy", "Hakim", "Iqbal", "Zacky",
        "Nadya", "Panji", " ", "Renaldy", "Rey", "Reza", "Rio Y", "Rizal A", "Rizal N", "Hanur", "Hendra", "Dion"},
         datnt[8], datnr[8];
    int nim, jumdat, nilai, urutan, rataan, datat, datar, datt, datr, total = 0, tinggi = 0, rendah = 100, A = 0, B = 0, C = 0, D = 0, E = 0, ggl = 0, dataNAS[34], dataNIM[34];

    printf("===============================================================================\n");
    printf("|                 Program Pengolah Nilai Akhir Semester (NAS)                 |\n");
    printf("|                  Dibuat Oleh : Rizal Nurhidayat | I0714031                  |\n");
    printf("|                Website : http://clever-society.blogspot.com/                |");
    printf("\n===============================================================================\n");
    printf("\n-------------------------------------------------------------------------------\n");
    printf("|            Masukkan Nilai dan No. Absen Mahasiswa Teknik Elektro            |\n");
    printf("|                      Mata Kuliah : Teknik Pemprograman                      |\n");
    printf("|              Masukkan Nilai=999 Untuk Berhenti Menginput Data.              |\n");
    printf("-------------------------------------------------------------------------------\n");
    for (urutan = 1; nilai != 999; urutan++)
    {
        if (urutan <= 33)
        {
        ulang:
            printf("\n\tData Mahasiswa ke-%d", urutan);
            printf("\n\t\tNilai  %18s", ": ");
            scanf("%d", &nilai);
            if (nilai > 100 & nilai != 999)
            {
                printf("\n-------------------------------------------------------------------------------\n");
                printf("|                   Error!! Nilai Tidak Boleh Melebihi 100!                   |\n");
                printf("|                     Mohon Masukkan Data Nilai Kembali!                      |\n");
                printf("-------------------------------------------------------------------------------\n");
                goto ulang;
            }
            dataNAS[urutan] = nilai;
            if (nilai != 999)
            {
                printf("\t\tNo. Absen %15s", ": ");
                scanf("%d", &nim);
                if (nim > 33)
                {
                    printf("\n-------------------------------------------------------------------------------\n");
                    printf("|               Error!! Data No. Absen Tidak Boleh Melebihi 33!               |\n");
                    printf("|                   Mohon Masukkan Data No. Absen Kembali!                    |\n");
                    printf("-------------------------------------------------------------------------------\n");
                    goto ulang;
                }
                dataNIM[urutan] = nim;
            }
            else if (nilai = 999)
            {
                nilai = 0;
                nim = 0;
                jumdat = urutan;
                goto endloop;
            }
        }
        else if (urutan > 33)
        {
            nilai = 0;
            nim = 0;
            jumdat = urutan;
            goto endloop;
        }
    }
endloop:
    printf("\n===============================================================================\n");
    printf("%3s%8s%9s%41s%9s%9s", "No.", "NIM", "NAMA", "NAS", "ANGKA", "HURUF\n");
    printf("-------------------------------------------------------------------------------\n");
    for (urutan = 1; urutan <= (jumdat - 1); urutan++)
    {
        printf("%2d.", urutan);
        if (dataNIM[urutan] < 10)
        {
            printf("%9s%d", "I071400", dataNIM[urutan]);
            printf("\t%s", dataNAME[dataNIM[urutan] - 1]);
        }
        else if (dataNIM[urutan] < 25)
        {
            printf("%8s%2d", "I07140", dataNIM[urutan]);
            printf("\t%s", dataNAME[dataNIM[urutan] - 1]);
        }
        else if (dataNIM[urutan] >= 25)
        {
            printf("%8s%2d", "I07140", dataNIM[urutan] + 1);
            printf("\t%s", dataNAME[dataNIM[urutan]]);
        }
        printf("\t\t\t\t\t  %d", dataNAS[urutan]);

        if (dataNAS[urutan] >= 80)
        {
            printf("\t%4s\t%5s", "4", "A\n");
            A = A + 1;
        }
        else if (dataNAS[urutan] >= 70)
        {
            printf("\t%4s\t%5s", "3", "B\n");
            B = B + 1;
        }
        else if (dataNAS[urutan] >= 60)
        {
            printf("\t%4s\t%5s", "2", "C\n");
            C = C + 1;
        }
        else if (dataNAS[urutan] > 40)
        {
            printf("\t%4s\t%5s", "1", "D\n");
            D = D + 1;
            ggl = ggl + 1;
        }
        else
        {
            printf("\t%4s\t%5s", "0", "E\n");
            E = E + 1;
            ggl = ggl + 1;
        }

        if (tinggi < dataNAS[urutan])
        {
            tinggi = dataNAS[urutan];
            datt = urutan;
            datat = dataNIM[datt];
        }
        if (rendah > dataNAS[urutan])
        {
            rendah = dataNAS[urutan];
            datr = urutan;
            datar = dataNIM[datr];
        }
        total = total + dataNAS[urutan];
        rataan = total / (jumdat - 1);
    }

    printf("===============================================================================\n\n");
    printf("---------------------------------Analisis Data---------------------------------\n\n");
    printf("    Jumlah Nili Seluruh Adalah \t%s%3d\n", ": ", total);
    printf("    Rata-rata NAS adalah \t%s%3d\n", ": ", rataan);
    printf("    Total Nilai A \t\t%s%3d\n", ": ", A);
    printf("    Total Nilai B \t\t%s%3d\n", ": ", B);
    printf("    Total Nilai C \t\t%s%3d\n", ": ", C);
    printf("    Total Nilai D \t\t%s%3d\n", ": ", D);
    printf("    Total Nilai D \t\t%s%3d\n", ": ", E);
    printf("    Total yang Gagal \t\t%s%3d\n", ": ", ggl);
    printf("    Nilai Maksimum \t\t%s%3d", ": ", tinggi);
    if (datat < 25)
    {
        printf("%12s%2d, Atas Nama : %s\n", "data ke-", datt, dataNAME[datat - 1]);
    }
    else if (datat >= 25)
    {
        printf("%12s%2d, Atas Nama : %s\n", "data ke-", datt, dataNAME[datat]);
    }
    printf("    Nilai Minimum  \t\t%s%3d", ": ", rendah);
    if (datar < 25)
    {
        printf("%12s%2d, Atas Nama : %s\n", "data ke-", datr, dataNAME[datar - 1]);
    }
    else if (datar >= 25)
    {
        printf("%12s%2d, Atas Nama : %s\n", "data ke-", datr, dataNAME[datar]);
    }
    printf("\n-------------------------------------------------------------------------------\n");
    system("pause");
    return (0);
}
