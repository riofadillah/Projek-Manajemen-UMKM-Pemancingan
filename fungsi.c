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
struct peserta data[28];
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
                 sortNamaPeserta();break;
            case 3: // sort lapak
               sortLapak();break;
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

    // Penanda lapak terpakai (angka 1–28)
    int lapakTerpakai[29] = {0};
    // ============================================

    system("cls");
    printf("=== HASIL ACAK LAPAK ===\n\n");
    printf("%-20s %-10s %-10s\n", "NAMA", "LAPAK", "POSISI");
    printf("------------------------------------------\n");

    for(int i = 0; i < jumlahPeserta; i++) {

        // Cari lapak kosong (antisipasi jika ada tabrakan posisi)
        while (lapakTerpakai[posisi] == 1) {
            posisi++;
            if (posisi > totalLapak) {
                posisi = 1;
            }
        }

        // Simpan hasil lapak
        data[i].lapak = posisi;
        lapakTerpakai[posisi] = 1;

        // Tentukan sisi lapak
        if (posisi <= 14) {
            printf("%-20s %-10d %-10s\n", data[i].nama, posisi, "Kanan");
        } else {
            printf("%-20s %-10d %-10s\n", data[i].nama, posisi, "Kiri");
        }

        // Pindah ke posisi berikutnya berdasarkan step
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

//Kakang juga
void sortLapak() {
    struct peserta temp; 

    
      for (int i = 0; i < jumlahPeserta - 1; i++) {
        for (int j = 0; j < jumlahPeserta - i - 1; j++) {
            
            // Bandingkan: Kalau lapak sekarang lebih besar dari lapak depannya
            // Contoh: Lapak 5 ada di depan Lapak 2 -> TUKAR!
            if (data[j].lapak > data[j + 1].lapak) {
                
                // Proses tukar posisi (Swap)
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    printf("\nData berhasil diurutkan berdasarkan Nomor Lapak (Terkecil -> Terbesar)!\n");
    // Langsung tampilkan hasilnya
    lihatPeserta(); 
}


// Hasil ikan punya ais
void hasilIkan() {
    int nomor, ekor, berat;
    char lanjut;

    do {
        system("cls");
        printf("=== INPUT HASIL PANCINGAN ===\n");
        printf("Masukkan data hasil tangkapan peserta.\n\n");

        if (jumlahPeserta == 0) {
            printf("Belum ada peserta.\n");
            printf("Tekan ENTER untuk kembali...");
            getchar();
            return;
        }

        // Tampilkan tabel biar admin gampang lihat data yang sudah masuk
        printf("%-3s %-20s %-10s %-15s\n", "No", "Nama", "Jml Ekor", "Berat Induk(gr)");
        printf("----------------------------------------------------\n");
        for (int i = 0; i < jumlahPeserta; i++) {
            printf("%-3d %-20s %-10d %-15d\n", 
                i + 1, 
                data[i].nama, 
                data[i].jumlahIkan, 
                data[i].beratIkan);
        }
        printf("----------------------------------------------------\n");

        printf("\nPilih Nomor Peserta (0 untuk kembali): ");
        scanf("%d", &nomor);
        getchar();

        if (nomor == 0) break;

        // Validasi nomor
        if (nomor > 0 && nomor <= jumlahPeserta) {
            int idx = nomor - 1;

            printf("\n--- Input Data untuk %s ---\n", data[idx].nama);
            
            printf("Jumlah Ikan (ekor)       : ");
            scanf("%d", &ekor);
            
            printf("Berat Ikan Terberat (gram): "); // Input berat ikan yang paling besar saja
            scanf("%d", &berat);
    
            getchar();

            // Simpan ke database
            data[idx].jumlahIkan = ekor;
            data[idx].beratIkan  = berat;

            printf("\nData berhasil disimpan!\n");

        } else {
            printf("Nomor peserta tidak valid!\n");
        }

        printf("\nInput data peserta lain? (y/n): ");
        lanjut = getchar();
        getchar();

    } while (lanjut == 'y' || lanjut == 'Y');
}


//dilla - HASIL PEMENANG
void pemenang(){
    if (jumlahPeserta == 0){
        printf("Belum ada peserta.\n");
        printf("Tekan ENTER untuk kembali...");
        getchar();
        return;
    }
    // 1. Menghitung uang hadiah -rumus: (harga tiket 70.000 - harga ikan perkilo 38.000) = 32.000 sisa untuk hadiah
    int sisaUang = jumlahPeserta * 32000;

    long hadiahBerat = sisaUang * 0.25; // 25%
    long hadiahJ1    = sisaUang * 0.35; // 35%
    long hadiahJ2    = sisaUang * 0.25; // 25%
    long hadiahJ3    = sisaUang * 0.15; // 15%

    //2. Mencari juara trberat (Master Koja - 1 orang)
    int indexBerat= -1;
    int maxBerat =-1;
    for (int i = 0; i < jumlahPeserta; i++){
        if (data[i].beratIkan >maxBerat){
            maxBerat = data[i].beratIkan;
            indexBerat = i;
        }
    }

    //3.Mencari juara terbanyak (3 orang)
    struct peserta temp[28];
    memcpy(temp, data, sizeof(data));
     for(int i = 0; i < jumlahPeserta - 1; i++) {
        for(int j = 0; j < jumlahPeserta - i - 1; j++) {
            if(temp[j].jumlahIkan < temp[j+1].jumlahIkan) { // Tanda < biar urut dari besar
                struct peserta t = temp[j];
                temp[j] = temp[j+1];
                temp[j+1]=t;
            }
        }
    }
     system("cls");
    printf("=== PENGUMUMAN JUARA PEMANCINGAN ===\n");
    printf("Total Peserta: %d orang\n", jumlahPeserta);
    printf("Total Dana Hadiah: Rp %ld\n\n", sisaUang);

    printf("--- KATEGORI IKAN TERBERAT (MASTER KOJA) ---\n");
    if (maxBerat > 0 && indexBerat != -1) {
        printf("PEMENANG : %s\n", data[indexBerat].nama);
        printf("Berat    : %d gram\n", data[indexBerat].beratIkan);
        printf("Hadiah   : Rp %ld\n", hadiahBerat);
    } else {
        printf("Belum ada data berat ikan.\n");
    }

    printf("\n--- KATEGORI IKAN TERBANYAK (JUMLAH EKOR) ---\n");
    printf("JUARA 1  : %s (%d ekor)\n", temp[0].nama, temp[0].jumlahIkan);
    printf("Hadiah   : Rp %ld\n", hadiahJ1);
    if (jumlahPeserta >= 2) {
        printf("JUARA 2  : %s (%d ekor)\n", temp[1].nama, temp[1].jumlahIkan);
        printf("Hadiah   : Rp %ld\n", hadiahJ2);
    }
    if (jumlahPeserta >= 3) {
        printf("JUARA 3  : %s (%d ekor)\n", temp[2].nama, temp[2].jumlahIkan);
        printf("Hadiah   : Rp %ld\n", hadiahJ3);
    }

    printf("\n============================================\n");
    printf("Mancing mantap! Selamat kepada para pemenang ^-^\n");
    printf("Tekan ENTER untuk kembali...");
    getchar();
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

//punyaarinn-CARI peserta
void cariPeserta (){
int pilih;
do{
    system ("cls");
    printf ("=======SEARCH PESERTA=======\n");
    printf ("1. Cari berdasarkan nama\n");
    printf ("2. Cari berdasarkan lapak\n");
    printf ("3. Kembali\n");
    printf ("pilih: ");
    scanf ("%d", &pilih);
    getchar ();
    
    if (pilih==1){
        char kataKunci[30];
        printf ("Masukkan nama yang ingin dicari: ");
        scanf ("%[^\n]", kataKunci);
        getchar ();
        
        printf("\n--- Hasil pencarian Nama '%s' ---\n", kataKunci);
        printf("%-3s %-20s %-15s %-10s %-5s\n", "No", "Nama", "No HP", "Bayar", "Lapak");
        printf("-------------------------------------------------------------\n");


        int found = 0;
        for (int i = 0; i < jumlahPeserta; i++){
            if (strstr (data[i].nama, kataKunci) != NULL){
                printf("%-3d %-20s %-15s %-10s %-5d\n",
                        i + 1,
                        data[i].nama,
                        data[i].nohp,
                        data[i].sudahBayar ? "Lunas" : "Belum",
                        data[i].lapak
                    );
                    found++;
            }
        }
    if (found == 0){
        printf ("Peserta tidak ditemukan.\n");
     }    
    }
    else if (pilih == 2){
        int lap;
        printf ("Masukkan nomor lapak yang dicari: ");
        scanf ("%d", &lap);
        getchar();
        
        printf("\n--- Hasil pencarian Lapak %d ---\n", lap);
            printf("%-3s %-20s %-15s %-10s %-5s\n", "No", "Nama", "No HP", "Bayar", "Lapak");
            printf("-------------------------------------------------------------\n");
            
        int found = 0;
        for (int i = 0; i < jumlahPeserta; i++){
            if (data[i].lapak == lap){
                printf ("%-3d %-20s %-15s %-10s %-5d\n",
                i + 1,
                data[i].nama,
                data[i].nohp,
                data[i].sudahBayar ? "Lunas" : "Belum",
                data [i]. lapak
                );
                found++;
            }
        }
        if (found == 0){
            printf ("Peserta di lapak %d tidak ditemukan.\n",lap);
        }
    }
    else if (pilih == 3){
        printf ("Kembali ke menu utama..\n");
    }
    else {
        printf ("Pilihan tidak valid!\n");
    }
    if ( pilih >= 1 && pilih <=2){
        printf ("\nTekan ENTER untuk kembali ke menu search...");
        while (getchar() != '\n');
        getchar ();
    }
    }while (pilih !=3);
}

//punyyaarin-AKHIRI PROGRAM
void akhiriProgram (){

//1. bikin perhitungan keuangan
float totalTiket  = jumlahPeserta * 70000;
float modalIkan   = jumlahPeserta * 38000;
float danaHadiah  = jumlahPeserta * 32000;
float totalKopi   = jumlahPeserta * 5000;
float totalMie   = jumlahPeserta * 10000;
float omsetKantin = 0;

//omsetkantin
for (int i = 0; i<jumlahPeserta; i++){
    omsetKantin += (data[i].beliKopi * 5000 + data[i].beliMie * 10000);
}


//2. bikin nama file
time_t waktu = time (NULL);
struct tm tm = *localtime(&waktu);

char namaFile [100];
sprintf (namaFile, "Laporan_%04d-%02d-%02d_%02d-%02d.txt", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min);

FILE * f = fopen (namaFile, "w");
if (f == NULL){
    printf ("Gagal memuat file laporan!\n");
    return;
}
printf ("Sedang menyimpan laporan ke-'%s'\n",namaFile);

//3. bikin laporan di file

fprintf(f, "=== LAPORAN SESI PEMANCINGAN ===\n");
    fprintf(f, "Waktu Cetak : %02d-%02d-%04d Pukul %02d:%02d\n", 
            tm.tm_mday, tm.tm_mon+1, tm.tm_year+1900, tm.tm_hour, tm.tm_min);
    fprintf(f, "Total Peserta: %d Orang\n\n", noPeserta);

    fprintf(f, "--- RINGKASAN KEUANGAN ---\n");
    fprintf(f, "1. Total Uang Tiket Masuk : Rp %ld\n", totalTiket);
    fprintf(f, "2. Modal Belanja Ikan     : Rp %ld (Disisihkan)\n", modalIkan);
    fprintf(f, "3. Total Dana Hadiah      : Rp %ld (Dibagikan)\n", danaHadiah);
    fprintf(f, "4. Total Pendapatan Kantin: Rp %ld\n", omsetKantin);
    fprintf(f, "--------------------------------------------\n");
    fprintf(f, "TOTAL UANG KAS (Kantin)   : Rp %ld\n", omsetKantin); 
    fprintf(f, "--------------------------------------------\n\n");

 fprintf(f, "--- DATA PESERTA ---\n");
    fprintf(f,
        "%-4s %-20s %-8s %-10s %-6s %-6s %-6s %-10s\n",
        "No", "Nama", "Lapak", "Status",
        "Kopi", "Mie", "Ekor", "Berat");
    fprintf(f,
        "--------------------------------------------------------------------------\n");

    for (int i = 0; i < jumlahPeserta; i++) {
        fprintf(f,
            "%-4d %-20s %-8d %-10s %-6d %-6d %-6d %-10d\n",
            i + 1,
            data[i].nama,
            data[i].lapak,
            data[i].sudahBayar ? "Lunas" : "Belum",
            data[i].beliKopi,
            data[i].beliMie,
            data[i].jumlahIkan,
            data[i].beratIkan);
    }

    fprintf(f,
        "--------------------------------------------------------------------------\n");
    fclose(f);

    // Reset data
    jumlahPeserta = 0;

    printf("\nSUKSES! Laporan berhasil disimpan.\n");
    printf("Data direset, siap untuk sesi baru.\n");
    printf("Tekan ENTER untuk kembali...");
    getchar();
}

// Naufal- Pembayaran
void pembayaran() {
    int pilih, uangBayar, totalTagihan, kembalian;
    char lanjut;

    do {
        system("cls");
        printf("=== KASIR PEMBAYARAN ===\n");
        printf("Harga Tiket: Rp 70.000/orang\n");
        printf("Harga Kopi : Rp  5.000/gelas\n");
        printf("Harga Mie  : Rp  10.000/porsi\n\n");

        // Header tabel
        printf("%-3s %-20s %-15s %-15s %-12s\n",
               "No", "Nama", "Total Kopi", "Total Mie", "Status");
        printf("-----------------------------------------------------------------\n");

        // Isi tabel (SUDAH BENAR)
        for (int i = 0; i < jumlahPeserta; i++) {
            printf("%-3d %-20s %-15d %-15d %-12s\n", 
                i + 1,
                data[i].nama,
                data[i].beliKopi,
                data[i].beliMie,
                data[i].sudahBayar ? "LUNAS" : "BELUM BAYAR"
            );
        }
        printf("-----------------------------------------------------------------\n");

        printf("\nPilih Nomor Peserta (0 untuk kembali): ");
        scanf("%d", &pilih);
        getchar();

        if (pilih == 0) break;

        int idx = pilih - 1;

        if (idx >= 0 && idx < jumlahPeserta) {

            if (data[idx].sudahBayar == 1) {
                printf("\nPeserta atas nama %s SUDAH LUNAS.\n", data[idx].nama);
            } 
            else {
                int biayaTiket = 70000;
                int biayaKopi  = data[idx].beliKopi * 5000;
                int biayaMie   = data[idx].beliMie * 10000;
                totalTagihan   = biayaTiket + biayaKopi + biayaMie;

                printf("\n--- Rincian Tagihan %s ---\n", data[idx].nama);
                printf("Tiket Mancing      : Rp 70.000\n");
                printf("Kopi (%d gelas)     : Rp %d\n", data[idx].beliKopi, biayaKopi);
                printf("Mie  (%d porsi)     : Rp %d\n", data[idx].beliMie, biayaMie);
                printf("------------------------------ +\n");
                printf("TOTAL HARUS DIBAYAR : Rp %d\n", totalTagihan);

                printf("\nMasukkan Uang Pembayaran: Rp ");
                scanf("%d", &uangBayar);
                getchar();

                if (uangBayar < totalTagihan) {
                    printf("\nUang tidak cukup! Transaksi dibatalkan.\n");
                } 
                else {
                    kembalian = uangBayar - totalTagihan;
                    printf("Kembalian           : Rp %d\n", kembalian);
                    printf("Status berubah menjadi LUNAS.\n");

                    data[idx].sudahBayar = 1;
                }
            }

        } else {
            printf("Nomor peserta tidak valid!\n");
        }

        printf("\nProses pembayaran lain? (y/n): ");
        lanjut = getchar();
        getchar();

    } while (lanjut == 'y' || lanjut == 'Y');
}
