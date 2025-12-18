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