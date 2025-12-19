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


// FITUR ACAK LAPAK


int main() {
    int totalLapak = 28;
    int peserta = 7;

    int step = round((float) totalLapak / peserta);
    int posisi = 1;

    for (int i = 0; i < peserta; i++) {
        if (posisi <= 14)
            printf("Peserta %d: Lapak %d (Kanan)\n", i + 1, posisi);
        else
            printf("Peserta %d: Lapak %d (Kiri)\n", i + 1, posisi);

        posisi += step;
        if (posisi > totalLapak)
            posisi = ((posisi - 1) % totalLapak) + 1;
    }

    return 0;
}


//punya dilla - TAMBAH SORTING DATA PESERTA
void sortNamaPeserta(){
    struct peserta temp;
    for (int i = 0; i < noPeserta - 1; i++){
        for (int j=0; j < noPeserta - i - 1; j++){
        }
    }
}

//PUNYA KHAI UHUY
//LIHAT PESERTA
void lihatPeserta() {
    system("cls");

    if(noPeserta == 0){
        printf("Belum ada peserta...\n");
    }
    else{
        printf("====================== DATA PESERTA ======================\n");
        printf("Total peserta: %d\n\n", noPeserta);

        printf("%-3s %-20s %-15s %-10s %-5s\n", "No", "Nama", "No HP", "Bayar", "Lapak");
        printf("------------------------------------------------------------\n");
//JANGAN DI SINII, BELUM SELESAIII
