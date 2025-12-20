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

//daris-Tambah Peserta
void tambahPeserta(){
    char lagi;
    char konfirmasi;

    do{
        system("cls");
        printf("=== Input Peserta ===\n");
        printf("Nama : ");
        scanf(" %[^\n]", data[jumlahPeserta].nama);
        printf("No HP: ");
        scanf(" %[^\n]", data[jumlahPeserta].nohp);

        data[jumlahPeserta].sudahBayar = 0;
        data[jumlahPeserta].lapak = 0;
        data[jumlahPeserta].beliKopi = 0;
        data[jumlahPeserta].beliMie = 0;
        data[jumlahPeserta].jumlahIkan = 0;
        data[jumlahPeserta].beratIkan = 0;
        jumlahPeserta++;

        printf("Input lagi? (y/n): ");
        getchar();
        lagi = getchar();   
        getchar();

        //Minimal Peserta tujuh
        if((lagi == 'n' || lagi == 'N') && jumlahPeserta < 7) {
            system ("cls");
            printf("Peserta Minimal 7 orang!\n");
            printf("Jumlah Peserta Saat ini: %d\n\n", jumlahPeserta);
            printf("1. Tambah Peserta lagi\n");
            printf("2. Batalkan sesi pemancingan\n");
            printf("Pilih (1/2): ");
            konfirmasi = getchar();
            getchar();

            if (konfirmasi == '1') {
                lagi = 'y'; // kembali ke input peserta
            } else {
                    system("cls");
                    printf("\nSesi pemancingan dibatalkan\n");
                    printf("\nProgram dihentikan.\n");
                    exit(0);
            }


        }

    }while(lagi=='y' || lagi=='Y');
}



//daris-MENU LIHAT PESERTA
void menuLihatPeserta() {
    int pilih;
    do {
        system("cls");
        printf("======= LIHAT PESERTA =======\n");
        printf("Total peserta: %d\n\n", jumlahPeserta);
        printf("1. Tampilkan daftar asli\n");
        printf("2. Urutkan berdasarkan nama (A-Z)\n");
        printf("3. Urutkan berdasarkan nomor lapak\n");
        printf("4. Cari peserta\n");
        printf("5. Kembali\n");
        printf("Pilih: ");
        scanf("%d",&pilih);
        getchar(); // buang newline

        struct peserta temp[30]; // array sementara untuk sorting
        memcpy(temp, data, sizeof(data));

        switch(pilih) {
            case 1:
                lihatPeserta();break;
            case 2: // sort nama A-Z
                 sortDataNama();break;
            case 3: // sort lapak
               sortDataLapak();break;
            case 4:
                cariPeserta();break;;
            case 5:
                printf("Kembali ke menu utama...\n");break;
            default:
                printf("Pilihan tidak valid!\n");
                continue; // kembali ke menu pilihan
        }
        
    } while(pilih != 5);
}



//FITUR ACAK LAPAK fiks dari ais
void acakLapak() {
    
    // Cek dulu ada peserta atau tidak
    if (jumlahPeserta == 0) {
        printf("Belum ada peserta!\n");
        printf("Tekan ENTER untuk kembali...");
        getchar();
        return;
    }

    // ===== PENGACAKAN LAPAK =====
    int totalLapak = 28;
    int step = round((float) totalLapak / jumlahPeserta);
    int posisi = 1;
    // ============================================

    system("cls");
    printf("=== HASIL ACAK LAPAK ===\n\n");
    printf("%-20s %-10s %-10s\n", "NAMA", "LAPAK", "POSISI");
    printf("------------------------------------------\n");

    for(int i = 0; i < jumlahPeserta; i++) {

        
        // SIMPAN HASIL LAPAK
        data[i].lapak = posisi;

        // TENTUKAN SISI
        if (posisi <= 14) {
            printf("%-20s %-10d %-10s\n", data[i].nama, posisi, "Kanan");
        } else {
            printf("%-20s %-10d %-10s\n", data[i].nama, posisi, "Kiri");
        }

        // PINDAH KE LAPAK BERIKUTNYA
        posisi += step;
        if (posisi > totalLapak) {
            posisi = ((posisi - 1) % totalLapak) + 1;
        }
    }

    printf("\nSukses! Lapak sudah disimpan.\n");
    printf("Tekan ENTER untuk kembali...");
    getchar();

}



//PUNYA KHAI UHUY
void lihatPeserta() {
    system("cls");

    if(jumlahPeserta == 0){
        printf("Belum ada peserta...\n");
    }
    else{
        printf("====================== DATA PESERTA ======================\n");
        printf("Total peserta: %d\n\n", jumlahPeserta);

        printf("%-3s %-20s %-15s %-10s %-5s\n", "No", "Nama", "No HP", "Bayar", "Lapak");
        printf("------------------------------------------------------------\n");
        
        for(int i = 0; i < jumlahPeserta; i++){
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
        for (int i = 0; i < jumlahPeserta; i++) {
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

        if (nomor == 0) break;
        if (nomor < 1 || nomor > jumlahPeserta) {
            printf("Nomor tidak valid!\n");
            getchar();
            continue;
        }

        int idx = nomor - 1;

        // 3. Menu kantin
        printf("\n--- Menu Kantin untuk %s ---\n", data[idx].nama);
        printf("1. Kopi (Rp 5.000)\n");
        printf("2. Mie  (Rp10.000)\n");
        printf("3. Batal\n");
        printf("Pilih menu: ");
        scanf("%d", &menu);
        getchar();

        if (menu == 3) continue;
        printf("Jumlah beli: ");
        scanf("%d", &jumlah);
        getchar();

        if (menu == 1) {
            data[idx].beliKopi += jumlah;
            printf("Berhasil! %s membeli %d kopi.\n", data[idx].nama, jumlah);
        } 
        else if (menu == 2) {
            data[idx].beliMie += jumlah;
            printf("Berhasil! %s membeli %d mie.\n", data[idx].nama, jumlah);
        } 
        else {
            printf("Menu tidak valid!\n");
        }

        printf("\nTransaksi lain? (y/n): ");
        lagi = getchar();
        getchar();

    } while (lagi == 'y' || lagi == 'Y');
}



//dilla - HASIL PEMENANG
void pemenang(){
    if (jumlahPeserta == 0){
        printf("Belum ada peserta.\n");
        printf("Tekan ENTER untuk kembali...");
        getchar();
        return;
    }
    //Menghitung uang untuk hadiah
    // rumus: (harga tiket 70.000 - harga ikan perkilo 38.000) = 32.000 sisa untuk hadiah
    float sisaUang = jumlahPeserta * 32000;
}



//punya dilla - TAMBAH SORTING DATA PESERTA
void sortNamaPeserta(){
    struct peserta temp;
    for (int i = 0; i < jumlahPeserta - 1; i++){
        for (int j = 0; j < jumlahPeserta - i - 1; j++){
            if (strcmp(data[j].nama, data[j + 1].nama) > 0){
                temp = data[j];
                data[j] = data[j+1];
                data[j + 1] = temp;
            }
        }
    }
    printf("\nData peserta berhasil diurutkan berdasarkan Nama peserta(A-Z)\n");
    lihatPeserta();
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
sprintf (namaFile, "Laporan_%04d-%02d-%02d_%02d-%02d.txt", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);

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
    fprintf (f, "%-4s %-20s %-10s %-10s %-10s %-10s %-10s %-10s\n",
    i+1,
    data [i].nama,
    data [i].lapak,
    data [i].sudahBayar ? "Lunas" : "Belum",
    data [i].beliKopi,
    data [i].beliMie,
    data [i].jumlahIkan,
    data [i].beratIkan
    );
}

fprintf (f, "------------------------------------------------------------------------------\n");
fclose (f);

//reset data
jumlahPeserta = 0;

printf("\nSukses! Laporan Data telah disimpan di file .txt\n");
printf("Data telah direset. siap untuk sesi baru!\n");
printf("Tekan ENTER untuk kembali ke menu utama");
getchar();
}