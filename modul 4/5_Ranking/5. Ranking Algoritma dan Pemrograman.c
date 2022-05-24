#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <math.h>

int validInt(double *nilai);
void reVldInt(double *nilai, char *kalimat);
void rangeVldInt(double *nilai, double batas_bawah, double batas_atas, char *kalimat);
void input_data_file_asistenin();
void membaca_mengurutkan_data_file_asistenin();
void transfer_nilai_ranking();
void stop();

void dis_headerbox();

//fungsi yang berguna untuk mengatur tata letak dari krusor
COORD coord = {0, 0};
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;																//koordinat x																			
	coord.Y = y;																//koordinat y	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);			//mengeset letak krusor
}

//fungsi interface
void dis_headerbox(){
	int i;
	gotoxy(1,0);
	printf("%c",201);
	for(i=1;i<79;i++){
		gotoxy(1+i,0);
		printf("%c",205);
	}

	gotoxy(80,0);
	printf("%c",187);
	gotoxy(1,6);
	for(i=1;i<5;i++){
		gotoxy(1,0+i);
		printf("%c",186);
	}
	
	gotoxy(1,5);
	printf("%c",200);
	for(i=1;i<79;i++){
		gotoxy(1+i,5);
		printf("%c",205);
	}
	
	gotoxy(80,5);
	printf("%c",188);
	gotoxy(80,6);
	for(i=1;i<5;i++){
		gotoxy(80,0+i);
		printf("%c",186);
	}
}

struct Mahasiswa { 
    char nama[100];
    double nilai; 
} mahasiswa[100];

int posisi = 0;

int main() {
    double banyak_mahasiswa; 
    int i=0;
    
    system("cls");
	dis_headerbox();
	gotoxy(23,2);
	printf("PROGRAM INPUT DATA NILAI DAN RANKING");
	gotoxy(25,3);
	printf("KELOMPOK 9 ALGORITMA PEMOGRAMAN");
	
	gotoxy(0,7);
    printf("\n\tKetik 0 jika untuk melihat ranking nilai");
    printf("\n\tBanyak Mahasiswa Yang Ingin Dituliskan ");
    reVldInt(&banyak_mahasiswa, "=> ");

    for (i = 0 ; i < (int)banyak_mahasiswa; i++) {
        input_data_file_asistenin();
    }

    membaca_mengurutkan_data_file_asistenin();
    transfer_nilai_ranking();
    printf("==========================================");
    getch();
    stop();
    return 0; 
}

int validInt(double *var) {
    char buff[100];
    char cek;
    fflush(stdin);
    if(fgets(buff, sizeof(buff), stdin) != NULL) {
        if(sscanf(buff, "%lf %c", var, &cek) == 1) {
            return 1;
        }
    }

    return 0;
}

void reVldInt(double *var, char *prompt) {
    while(1) {
        printf("%s", prompt);
        if(validInt(var))
            break;
        printf("\n\t### Dimohon untuk mengetik angka\n");
    }
}

void rangeVldInt(double *var, double range1, double range2, char *prompt) {
    while(1) {
        reVldInt(var, prompt);
        if(*var >= range1  && *var <= range2)
            break;
        printf("\n\tInput salah! harus diatara %lf hingga %lf\n", range1, range2);
    }
}

void input_data_file_asistenin() { 
    FILE *ptr_asistenin = fopen("asistenin.txt", "a");
    char nama_mahasiswa[100];
    double nilai_mahasiswa;
    int i = 0;
    
    printf("\n\tNama : ");
    // input nama 
    scanf("%[^\n]", nama_mahasiswa);
    while(i ==0) {  
        if(strlen(nama_mahasiswa) < 1  && strlen(nama_mahasiswa) > 100) {
            printf("\n\tPenulisan nama tidak boleh lebih dari 100 karakter\n");
            continue;
        } else { 
            i++;
        }
    }
    fprintf(ptr_asistenin, "%s\n", nama_mahasiswa); 
    // input nilai
    rangeVldInt(&nilai_mahasiswa, 0, 100, "\n\tNilai : ");
    fprintf(ptr_asistenin, "%.2lf\n", nilai_mahasiswa); 
    fclose(ptr_asistenin);
}

void membaca_mengurutkan_data_file_asistenin() {
    FILE *ptr_asistenin = fopen("asistenin.txt", "r");
    int i = 0;
    int j = 0;
    struct Mahasiswa temp;
    double *ptr_nilai;

    while(!feof(ptr_asistenin)) {
        ptr_nilai = &mahasiswa[posisi].nilai;
        fscanf(ptr_asistenin, "%s %lf", mahasiswa[i].nama, &mahasiswa[i].nilai);
        i++;
        posisi++;
    }

    for(i = 0; i < posisi - 1; i++) {
        for(j = 0; j < posisi - i - 1; j++) { 
            if(mahasiswa[j].nilai < mahasiswa[j + 1].nilai) {
                temp.nilai = mahasiswa[j].nilai;
                strcpy(temp.nama, mahasiswa[j].nama);
                mahasiswa[j].nilai = mahasiswa[j + 1].nilai; 
                strcpy(mahasiswa[j].nama, mahasiswa[j + 1].nama);
                mahasiswa[j + 1].nilai = temp.nilai;
                strcpy(mahasiswa[j + 1].nama, temp.nama);
            }
        }
    }

    fclose(ptr_asistenin);
}

void transfer_nilai_ranking() {
	
	int i=0;
	
    FILE *ptr_asistenout_write = fopen("asistenout.txt", "w");
    FILE *ptr_asistenout_append = fopen("asistenout.txt", "a+");

    if(ptr_asistenout_append == NULL && ptr_asistenout_write == NULL)   
        printf("\n\tTidak terdapat file asistenout.txt");

    // menuliskan judul pada file
    fprintf(ptr_asistenout_write, "%s\n\n", "\n\tNilai Mata Kuliah Algoritma dan Pemrograman ");
    // menuliskan judul pada terminal
    printf("\n\tNilai Mata Kuliah Algoritma Pemrograman : \n");
    for(i = 0; i < posisi - 1; i++) {
        printf("\n\tRanking ke - [%d] %s %.2lf\n", i, mahasiswa[i].nama, mahasiswa[i].nilai);
        // menuliskan data kepada file
        fprintf(ptr_asistenout_append, "\n\tRanking ke - [%d] %s %.2lf\n", i, mahasiswa[i].nama, mahasiswa[i].nilai);
    }

    fclose(ptr_asistenout_write);
    fclose(ptr_asistenout_append);
}

void stop() {
    system("cls");
	int i;
	for(i=1;i<79;i++){
		gotoxy(0+i,1);
		printf("%c",205);
	}
	gotoxy(20,2);
	printf("Terima Kasih Sudah Menggunakan Program Ini");
	gotoxy(16,3);
	printf("Silahkan Mengulang Program Ini Untuk Melihat Lagi");
	for(i=1;i<79;i++){
		gotoxy(0+i,4);
		printf("%c",205);
	}
}  

