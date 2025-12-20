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
int jumlahPeserta = 0;

//belum selesai 
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
        data[noPeserta].beliKopi = 0;
        data[noPeserta].beliMie = 0;
        data[noPeserta].jumlahIkan = 0;
        data[noPeserta].beratIkan = 0;
        noPeserta++;

        printf("Input lagi? (y/n): ");
        getchar();
        lagi = getchar();   
        getchar();

        //Minimal Peserta
        if((lagi == 'n' || lagi == 'N')) && noPeserta < 7 {
            system ("cls");
            printf("Peserta Minimal 7 orang!\n");
            printf("Jumlah Peserta Saat ini: %d\n\n", noPeserta);
            printf("1. Tambah Peserta lagi\n")
            printf("")


        }

    }while(lagi=='y' || lagi=='Y');
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
    for (int i = 0; i < jmlhPeserta - 1; i++){
        for (int j=0; j < jmlhPeserta - i - 1; j++){
            if (strcmp(data[j].nama, data [j + 1].nama) > 0){
                temp = data[j];
                data[j] = data [j+1];
                data[j + 1] =;
            }
        }
    }
}

//PUNYA KHAI UHUY
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
        
        for(int i = 0; i < noPeserta; i++){
        printf("%-3d %-20s %-15s %-10s %-5d\n",
                           i+1,
                data[i].nama,
                data[i].nohp,
                data[i].sudahBayar ? "Lunas" : "Belum",
                data[i].lapak
            );
        }

        printf("=============================================================\n");
    
    }
    printf("\nTekan ENTER untuk kembali ke menu...");
    getchar();
}
//JANGAN DI SINII, BELUM SELESAIII



//Bagian kakang
void kantin() {
    int menu, nomor, jumlah;
    char lagi;

    do {
       system("cls");
        printf("=== WARUNG KANTIN ===\n\n");

        // 1. Tampilkan peserta
        printf("%-3s %-20s %-5s %-5s\n", "No", "Nama", "Kopi", "Mie");
        printf("-----------------------------------\n");
        for (int i = 0; i < noPeserta; i++) {
            printf("%-3d %-20s %-5d %-5d\n",
                i + 1,
                data[i].nama,
                data[i].beliKopi,
                data[i].beliMie
            );
        }

        printf("\nPilih Nomor Peserta (0 untuk kembali): ");
        scanf("%d", &nomor);
        getchar();
    }
}

//punyyaarin-AKHIRI PROGRAM
void akhiriProgram (){

//1. bikin perhitungan keuangan
float totalTiket  = jumlahPeserta * 70000;
float modalIkan   = jumlahPeserta * 38000;
float danaHadiah  = jumlahPeserta * 32000;
float totalKopi   = jumlahPeserta * 5000;
float totaliMie   = jumlahPeserta * 10000;
float omsetKantin = 0;

//omsetkantin
for (int i = 0; i<jumlahPeserta; i++){
    omsetKantin += (data[i].beliKopi * 5000 + data[i].beliMie * 7000);
}

//2. bikin nama file
time_t waktu = time (NULL);
struct tm tm = *localtime(&waktu);

char namaFile [100];
sprintf (namaFile, "Laporan_%04d-%02d-%02d_%02d-%02d.txt", tm.tm_year + 1900, tm.tm + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);

FILE * f = fopen (namaFile, "W");
if (f == NULL){
    printf ("Gagal memuat file laporan!\n");
    return;
}
printf ("Sedang menyimpan laporan ke-'%s'\n");

//3. bikin laporan di file
fprintf (f, "===LAPORAN SESI PEMANCINGAN===\n");
fprintf (f, "Waktu cetak: %02d-%02d-%04d Pukul %02d:%02d\n", tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min);
fprintf (f, "Total peserta: %d orang\n\n", jumlahPeserta);

fprintf (f, "---RINGKASAN KEUANGAN---\n");
fprintf (f, "Total uang tiket masuk : Rp %1d\n", totalTiket);
fprintf (f, "Modal Belanja ikan     : Rp %1d (disisihkan)\n", modalIkan);
fprintf (f, "Dana hadiah            : Rp %1d (dibagikan)\n", danaHadiah);
fprintf (f, "Total pendapatan kantin: Rp %1d\n", omsetKantin);

//data peserta
fprintf (f, "---DATA PESERTA---\n");
fprintf (f, "%-4s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n", "No", "Nama", "Lapak", "Status", "Kopi", "Mie", "Ekor", "Berat(gr)");
fprintf (f, "------------------------------------------------------------------------------\n");

for (int i = 0; i<jumlahPeserta; i++){
    fprintf (f, "%-4s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n"
    i+1,
    data [i].nama,
    data [i].lapak,
    data [i].sudahBayar ? "Lunas" : "Belum",
    data [i].beliKopi,
    data [i].beliMie,
    data [i].jumlahIkan,
    data [i].beratIkan,
    );
}

fprintf (f, "------------------------------------------------------------------------------\n");
fclose (f);

//reset data
jumlahPeserta = 0;

printf("\nSukses! Data telah disimpan di file .txt\n");
printf("Data telah direset. siap untuk sesi baru!\n");
printf("Tekan ENTER untuk kembali ke menu utama");
getchar();
}