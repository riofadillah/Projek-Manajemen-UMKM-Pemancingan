#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "fungsi.h"

struct peserta{
    char nama[30];
    char nohp[20];
    int sudahBayar;      
    int lapak;           
    int beliKopi;   
    int beliMie;
    int jumlahIkan;      
    int beratIkan;       
};
struct peserta data[30];
int noPeserta = 0;

//TAMBAH PESERTA
void tambahPeserta(){
    char lagi;
    do{
        system("cls");
        printf("=== Input Peserta ===\n");
        printf("Nama : ");
        scanf(" %[^\n]", data[noPeserta].nama);
        printf("No HP: ");
        scanf(" %[^\n]", data[noPeserta].nohp);

        data[noPeserta].sudahBayar = 0;
        data[noPeserta].lapak = 0;
        data[noPeserta].beliKantin = 0;
        data[noPeserta].jumlahIkan = 0;
        data[noPeserta].beratIkan = 0;
        noPeserta++;

        printf("Input lagi? (y/n): ");
        getchar();
        lagi = getchar();   
        getchar();

    }while(lagi=='y' || lagi=='Y');
    }

//AKHIRI PROGRAM
void akhiriProgram (){

time_t waktu = time (NULL);
struct tm tm = *localtime(&waktu);

char namaFile [100];
sprintf (namaFile, "Laporan_%04d-%02d-%02d_%02d-%02d.txt", tm.tm_year + 1900, tm.tm + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);

FILE * f = fopen (namaFile, "W");


}
