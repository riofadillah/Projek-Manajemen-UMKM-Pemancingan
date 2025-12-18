#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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
    