/*  Modul 1 Praktikum Algoritna Pemograman                  									*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>															
#include <windows.h>

#define PHI 3.14

void pilihan_keluar(int ulang,int kembali);
void menu_tabung();
void volume_tabung();
void luas_permukaan_tabung();
void menu_bola();
void volume_bola();
void luas_permukaan_bola();
void menu_limas_segiempat();
void volume_limas_segiempat(); 
void luas_permukaan_limas_segiempat();
void menu_prisma_segitiga();
void volume_prisma_segitiga();
void luas_permukaan_prisma_segitiga();
void menu_kerucut();
void volume_kerucut();
void luas_permukaan_kerucut();
void menu_utama();
void keluar();

void dis_mainbox();
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

void dis_mainbox(){
	int i;
	gotoxy(1,6);
	printf("%c",201);
	for(i=1;i<79;i++){
		gotoxy(1+i,6);
		printf("%c",205);
	}

	gotoxy(80,6);
	printf("%c",187);
	gotoxy(1,6);
	for(i=5;i<35;i++){
		gotoxy(1,2+i);
		printf("%c",186);
	}
	
	gotoxy(1,37);
	printf("%c",200);
	for(i=1;i<79;i++){
		gotoxy(1+i,37);
		printf("%c",205);
	}
	
	gotoxy(80,37);
	printf("%c",188);
	gotoxy(80,6);
	for(i=5;i<35;i++){
		gotoxy(80,2+i);
		printf("%c",186);
	}
	
	printf("\n\n");
}

int validInt(int *var) {
    char buff[100];
    char cek;
    fflush(stdin);
    if(fgets(buff, sizeof(buff), stdin) != NULL){
        if(sscanf(buff, "%d %c", var, &cek) == 1) {
            return 1;
        }
    }
    return 0;
}

void reVldInt(int *var, char *prompt){
    while(1){
        printf("%s", prompt);
        if(validInt(var))
            break;
        printf("\n\t MASUKAN DENGAN BENAR PILIHAN DIATAS !!!!");
    }
}

void rangeVldInt(int *var, int range1, int range2, char *prompt){
    while(1) {
        reVldInt(var, prompt);
        if(*var >= range1  && *var <= range2)
            break;
        printf("\n\t Input salah! Silahkan coba lagi");
    }
}

float validFlt(float *var){
    char buff[1024];
    char cek;
    fflush(stdin);
    if(fgets(buff, sizeof(buff), stdin) != NULL){
        if(sscanf(buff, "%f %c", var, &cek) == 1) {
            return 1;
        }
    }
    return 0;
}

void reVldFlt(float *var, char *prompt){
    while(1){
        printf("%s", prompt);
        fflush(stdin);
        if(validFlt(var))
            break;
        printf("\n\t Input salah! Silahkan coba lagi");
    }
} 

void rangeVldFloat(float *var, int range1, char *prompt){
    while(1){
        reVldFlt(var, prompt);
        fflush(stdin);
        if(*var >= range1 )
            break;
        printf("\n\t Input salah! Tidak Boleh Bilangan Negatif Silahkan coba lagi!!!!");
    }
}


void pilihan_keluar(int ulang,int kembali){
    char mengulang;

    printf("\n\tLakukan lagi? Ya/Tidak/Keluar (Y/T/K) : ");
    fflush(stdin);
    scanf("%c", &mengulang);
    if(mengulang != 'y' && mengulang != 't' && mengulang != 'k' && mengulang != 'Y' && mengulang != 'T' && mengulang != 'K'){
        printf("\tMasukan anda salah!");
        getch();
        pilihan_keluar(ulang,kembali);
    }else if(mengulang == 't' || mengulang == 'T'){
        system("cls");
        switch(kembali){
            case 1:
                menu_tabung();
                break;
            case 2:
                menu_bola();
                break;
            case 3:
                menu_limas_segiempat();
                break;
            case 4:
                menu_prisma_segitiga();
                break;
            case 5:
                menu_kerucut();
                break;
        }
    }else if(mengulang == 'y' || mengulang == 'Y'){
        system("cls");
        switch(ulang){
            case 1:
                luas_permukaan_tabung();
                break;
            case 2:
                volume_tabung();
                break;
            case 3:
                luas_permukaan_bola();
                break;
            case 4:
                volume_bola();
                break;
            case 5:
                luas_permukaan_limas_segiempat();
                break;
            case 6:
                volume_limas_segiempat();
                break;
            case 7:
                luas_permukaan_prisma_segitiga();
                break;
            case 8:
                volume_prisma_segitiga();
                break;
            case 9:
                luas_permukaan_kerucut();
                break;
            case 10:
                volume_kerucut();
                break;
        }
    }else{
        keluar();
    }
}

void menu_tabung(){
	int pilihan;
    
    system("cls");
	dis_headerbox();
	gotoxy(14,2);
	printf("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN RUANG");
	gotoxy(36,3);
	printf("TABUNG");
	dis_mainbox();
	
	gotoxy(18,11);
	printf("MENU :");
	gotoxy(18,14);
	printf("1.	Hitung Luas Permukaan");
	gotoxy(18,17);
	printf("2.	Hitung Volume");
	gotoxy(18,20);
	printf("3.	Kembali");
	gotoxy(18,23);
	printf("4.	Keluar");
	gotoxy(18,30);
	printf("Masukan Pilihan Anda :");
    scanf("%d", &pilihan);
    fflush(stdin);
    system("cls");
    
    if (pilihan==1){
        luas_permukaan_tabung();
	}else if (pilihan==2){
        volume_tabung();
	}else if (pilihan==3){
        menu_utama();
	}else if (pilihan==4){
		keluar();
	}else{
		int i;
		
		gotoxy(20,2);
		printf("Input Yang Anda Masukan Salah");
		gotoxy(17,3);
		printf("Masukan Sesuai Input Yang Disediakan");
		
		for(i=1;i<79;i++){
			gotoxy(0+i,1);
			printf("%c",205);
		}

		for(i=1;i<79;i++){
			gotoxy(0+i,4);
			printf("%c",205);
		}
		getch();
		menu_tabung();
	}
    
}


void luas_permukaan_tabung(){
    system("cls");

    float r,t,hasil;
    
    dis_headerbox();
	gotoxy(25,2);
	printf("MENGHITUNG LUAS PERMUKAAN TABUNG");

	gotoxy(0,7);
    printf("\n\tRumus : (PHI*r*r)*2+(2*PHI*r)*t");
    printf("\n\tTolong Masukkan Nilai Yang Dibutuhkan");
    rangeVldFloat(&r, 0, "\n\t Masukan Nilai Jari-Jari : ");
    fflush(stdin);
    rangeVldFloat(&t, 0,"\n\t Masukan Nilai Tinggi : ");
    fflush(stdin);
    hasil= (PHI*r*r)*2+(2*PHI*r)*t;
    
    printf("\n\t Luas Permukaan Tabung Adalah %.2f  cm \n", hasil);

	pilihan_keluar(1,1);
}

void volume_tabung(){
    system("cls");

    float r,t,hasil;
    char mengulang;
    
	dis_headerbox();
	gotoxy(25,2);
	printf("MENGHITUNG KELILING SEGITIGA SEMBARANG");

	gotoxy(0,7);
    printf("\n\tRumus : PHI*r*r*t");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    
    rangeVldFloat(&r, 0, "\n\t Masukan Nilai Jari-Jari : ");
    fflush(stdin);
    rangeVldFloat(&t, 0,"\n\t Masukan Nilai Tinggi : ");
    fflush(stdin);
    hasil= PHI*r*r*t;
    printf("\n\t Luas Permukaan Tabung Adalah %.2f  cm \n", hasil);
    
	pilihan_keluar(2,1);
}

void menu_bola(){
    int pilihan;
    
    system("cls");
	dis_headerbox();
	gotoxy(14,2);
	printf("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN RUANG");
	gotoxy(36,3);
	printf("BOLA");
	dis_mainbox();
	
	gotoxy(18,11);
	printf("MENU :");
	gotoxy(18,14);
	printf("1.	Hitung Luas Permukaan");
	gotoxy(18,17);
	printf("2.	Hitung Volume");
	gotoxy(18,20);
	printf("3.	Kembali");
	gotoxy(18,23);
	printf("4.	Keluar");
	gotoxy(18,30);
	printf("Masukan Pilihan Anda :");
    scanf("%d", &pilihan);
    fflush(stdin);
    system("cls");
    
    if (pilihan==1){
        luas_permukaan_bola();
	}else if (pilihan==2){
        volume_bola();
	}else if (pilihan==3){
        menu_utama();
	}else if (pilihan==4){
		keluar();
	}else{
		int i;
		
		gotoxy(20,2);
		printf("Input Yang Anda Masukan Salah");
		gotoxy(17,3);
		printf("Masukan Sesuai Input Yang Disediakan");
		
		for(i=1;i<79;i++){
			gotoxy(0+i,1);
			printf("%c",205);
		}

		for(i=1;i<79;i++){
			gotoxy(0+i,4);
			printf("%c",205);
		}
		getch();
		menu_bola();
	}
    
}
  
void luas_permukaan_bola(){
    system("cls");
    float r, hasil;
    char mengulang;

	dis_headerbox();
	gotoxy(25,2);
	printf("MENGHITUNG LUAS PERMUKAAN BOLA");
	
	gotoxy(0,7);
    printf("\n\tRumus : 4*PHI*r*r");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    
    rangeVldFloat(&r, 0,"\n\t Masukkan nilai jari-jari : ");
    fflush(stdin);
    hasil= 4*PHI*r*r;
    printf("\n\tLuas Permukaan Bola adalah %.2f cm\nm", hasil);

    pilihan_keluar(3,2);
}

void volume_bola(){
	system("cls");
    float r, hasil;
    char mengulang;

	dis_headerbox();
	gotoxy(30,2);
	printf("MENGHITUNG VOLUME BOLA");
	
	gotoxy(0,7);
    printf("\n\tRumus : (4*PHI*r*r*r)/3");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    
    rangeVldFloat(&r, 0,"\n\t Masukkan nilai jari-jari : ");
    fflush(stdin);
    hasil= (4*PHI*r*r*r)/3;
    printf("\n\tVolume Bola adalah %.2f cm\nm", hasil);
    pilihan_keluar(4,2);
}

void menu_limas_segiempat(){
	int pilihan;
    
    system("cls");
	dis_headerbox();
	gotoxy(14,2);
	printf("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN RUANG");
	gotoxy(36,3);
	printf("LIMAS SEGI EMPAT");
	dis_mainbox();
	
	gotoxy(18,11);
	printf("MENU :");
	gotoxy(18,14);
	printf("1.	Hitung Luas Permukaan");
	gotoxy(18,17);
	printf("2.	Hitung Volume");
	gotoxy(18,20);
	printf("3.	Kembali");
	gotoxy(18,23);
	printf("4.	Keluar");
	gotoxy(18,30);
	printf("Masukan Pilihan Anda :");
    scanf("%d", &pilihan);
    fflush(stdin);
    system("cls");
    
    if (pilihan==1){
        luas_permukaan_limas_segiempat();
	}else if (pilihan==2){
        volume_limas_segiempat();
	}else if (pilihan==3){
        menu_utama();
	}else if (pilihan==4){
		keluar();
	}else{
		int i;
		
		gotoxy(20,2);
		printf("Input Yang Anda Masukan Salah");
		gotoxy(17,3);
		printf("Masukan Sesuai Input Yang Disediakan");
		
		for(i=1;i<79;i++){
			gotoxy(0+i,1);
			printf("%c",205);
		}

		for(i=1;i<79;i++){
			gotoxy(0+i,4);
			printf("%c",205);
		}
		getch();
		menu_limas_segiempat();
	}
    
}

void luas_permukaan_limas_segiempat(){
    system("cls");
    float sisi1,sisi2,t,t_selimut,hasil;
    char mengulang;

	dis_headerbox();
	gotoxy(20,2);
	printf("MENGHITUNG LUAS PERMUKAAN LIMAS SEGIEMPAT");

	gotoxy(0,7);
    printf("\n\tRumus : (sisi1*sisi2) + (2*sisi1*t_selimut/2) + (2*sisi2*t_selimut/2)");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    
    rangeVldFloat(&sisi1, 0,"\n\t Masukkan sisi alas 1: ");
    fflush(stdin);
    rangeVldFloat(&sisi2, 0,"\n\t Masukkan sisi alas 2: ");
    fflush(stdin);
    rangeVldFloat(&t, 0,"\n\t Masukkan tinggi selimut limas: ");
    fflush(stdin);
    hasil= (sisi1*sisi2) + (2*sisi1*t_selimut/2) + (2*sisi2*t_selimut/2);
    printf("\n\t Luas Permukaan Limas Segiempat adalah %.2f cm\n", hasil);
    
    pilihan_keluar(5,3);
}

void volume_limas_segiempat(){
    system("cls");
    float sisi1,sisi2,t,t_selimut,hasil;
    char mengulang;

	dis_headerbox();
	gotoxy(25,2);
	printf("MENGHITUNG VOLUME LIMAS SEGIEMPAT");
	
	gotoxy(0,7);
    printf("\n\tRumus : sisi1*sisi2*t/3");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    
    rangeVldFloat(&sisi1, 0, "\n\t Masukkan sisi alas 1: ");
    fflush(stdin);
    rangeVldFloat(&sisi2, 0, "\n\t Masukkan sisi alas 2: ");
    fflush(stdin);
    rangeVldFloat(&t, 0,"\n\t Masukkan tinggi limas: ");
    fflush(stdin);
    hasil= sisi1*sisi2*t/3;
    printf("\n\t Volume Limas Segiempat adalah %.2f cm\n", hasil);

    pilihan_keluar(6,3);
}



void menu_prisma_segitiga(){
   	int pilihan;
    
    system("cls");
	dis_headerbox();
	gotoxy(14,2);
	printf("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN RUANG");
	gotoxy(36,3);
	printf("PRISMA SEGITIGA");
	dis_mainbox();
	
	gotoxy(18,11);
	printf("MENU :");
	gotoxy(18,14);
	printf("1.	Hitung Luas Permukaan");
	gotoxy(18,17);
	printf("2.	Hitung Volume");
	gotoxy(18,20);
	printf("3.	Kembali");
	gotoxy(18,23);
	printf("4.	Keluar");
	gotoxy(18,30);
	printf("Masukan Pilihan Anda :");
    scanf("%d", &pilihan);
    fflush(stdin);
    system("cls");
    
    if (pilihan==1){
        luas_permukaan_prisma_segitiga();
	}else if (pilihan==2){
        volume_prisma_segitiga();
	}else if (pilihan==3){
        menu_utama();
	}else if (pilihan==4){
		keluar();
	}else{
		int i;
		
		gotoxy(20,2);
		printf("Input Yang Anda Masukan Salah");
		gotoxy(17,3);
		printf("Masukan Sesuai Input Yang Disediakan");
		
		for(i=1;i<79;i++){
			gotoxy(0+i,1);
			printf("%c",205);
		}

		for(i=1;i<79;i++){
			gotoxy(0+i,4);
			printf("%c",205);
		}
		getch();
		menu_prisma_segitiga();
	}
    
}

void luas_permukaan_prisma_segitiga(){
    system("cls");
    float sisialas3,sisialas1, sisialas2,  t_alas, t_prisma, hasil, alas;
    char mengulang;
    
    dis_headerbox();
	gotoxy(18,2);
	printf("MENGHITUNG LUAS PERMUKAAN PRISMA SEGITIGA");

	gotoxy(0,7);
    printf("\n\tRumus : t_prisma*(sisialas3+sisialas1+sisialas2)+(2*(sisialas3*t_alas/2))");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    
    rangeVldFloat(&alas, 0,"\n\t Masukkan sisi alas prisma 1: ");
    fflush(stdin);
    rangeVldFloat(&sisialas1, 0,"\n\t Masukkan sisi alas prisma 2: ");
    fflush(stdin);
    rangeVldFloat(&sisialas2, 0,"\n\t Masukkan sisi alas prisma 3: ");
    fflush(stdin);
    rangeVldFloat(&t_alas, 0,"\n\t Masukkan tinggi alas prisma: ");
    fflush(stdin);
    rangeVldFloat(&t_prisma, 0,"\n\t Masukkan tinggi prisma: ");
    scanf("%f", &t_prisma);
    hasil= t_prisma*(alas+sisialas1+sisialas2)+(2*(alas*t_alas/2));
    printf("\n\t Luas permukaan: %.2f\n", hasil);
    fflush(stdin);    
    
    pilihan_keluar(7,4);
}

void volume_prisma_segitiga(){
    system("cls");
    float sisialas3,sisialas1, sisialas2,  t_alas, t_prisma, hasil, alas;
    char mengulang;

	dis_headerbox();
	gotoxy(23,2);
	printf("MENGHITUNG VOLUME PRISMA SEGITIGA");

	gotoxy(0,7);
    printf("\n\tRumus : (sisialas3*t_alas/2)*t_prisma");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    
    rangeVldFloat(&alas, 0,"\n\t  Masukkan sisi alas segitiga: ");
    fflush(stdin);
    rangeVldFloat(&t_alas, 0,"\n\t Masukkan tinggi alas segitiga: ");
    fflush(stdin);
    rangeVldFloat(&t_prisma, 0,"\n\t Masukkan tinggi prisma: ");
    fflush(stdin);
    hasil= (alas*t_alas/2)*t_prisma;
    printf("\n\t Volume: %.2f cm\n", hasil);
    
    pilihan_keluar(8,4);
}

void menu_kerucut(){
	int pilihan;
    
    system("cls");
	dis_headerbox();
	gotoxy(17,2);
	printf("PROGRAM MENGHITUNG VOLUME DAN LUAS PERMUKAAN BANGUN RUANG");
	gotoxy(36,3);
	printf("KERUCUT");
	dis_mainbox();
	
	gotoxy(18,11);
	printf("MENU :");
	gotoxy(18,14);
	printf("1.	Hitung Luas Permukaan");
	gotoxy(18,17);
	printf("2.	Hitung Volume");
	gotoxy(18,20);
	printf("3.	Kembali");
	gotoxy(18,23);
	printf("4.	Keluar");
	gotoxy(18,30);
	printf("Masukan Pilihan Anda :");
    scanf("%d", &pilihan);
    fflush(stdin);
    system("cls");
    
    if (pilihan==1){
        luas_permukaan_kerucut();
	}else if (pilihan==2){
        volume_kerucut();
	}else if (pilihan==3){
        menu_utama();
	}else if (pilihan==4){
		keluar();
	}else{
		int i;
		
		gotoxy(20,2);
		printf("Input Yang Anda Masukan Salah");
		gotoxy(17,3);
		printf("Masukan Sesuai Input Yang Disediakan");
		
		for(i=1;i<79;i++){
			gotoxy(0+i,1);
			printf("%c",205);
		}

		for(i=1;i<79;i++){
			gotoxy(0+i,4);
			printf("%c",205);
		}
		getch();
		menu_kerucut();
	}
    
}

void luas_permukaan_kerucut(){
    system("cls");
    float r, t, garis, hasil;
    char mengulang;

	dis_headerbox();
	gotoxy(25,2);
	printf("MENGHITUNG LUAS PERMUKAAN KERUCUT");

	gotoxy(0,7);
    printf("\n\tRumus : (PHI*r*r) + (PHI*r*garis)");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    
    rangeVldFloat(&r, 0,"\n\t Masukkan jari-jari: ");
    fflush(stdin);
    rangeVldFloat(&garis, 0,"\n\t Masukkan garis pelukis: ");
    fflush(stdin);
    hasil= (PHI*r*r) + (PHI*r*garis);
    printf("\n\t Volume: %.2f\n", hasil);
    
    pilihan_keluar(9,5);
}

void volume_kerucut(){
    system("cls");
    float r, t, garis, hasil ;
    char mengulang;

	dis_headerbox();
	gotoxy(26,2);
	printf("MENGHITUNG VOLUME KERUCUT");

	gotoxy(0,7);
    printf("\n\tRumus : PHI*r*r*t/3");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    
    rangeVldFloat(&r, 0,"\n\t Masukkan jari-jari: ");
    fflush(stdin);
    rangeVldFloat(&t, 0,"\n\t\ Masukkan tinggi kerucut: ");
    fflush(stdin);
    hasil= PHI*r*r*t/3;
    printf("\n\t Volume: %.2f\n", hasil);
    
    pilihan_keluar(10,5);
}

void keluar(){
	system("cls");
	int i;
	for(i=1;i<79;i++){
		gotoxy(0+i,1);
		printf("%c",205);
	}
	gotoxy(20,2);
	printf("Terima Kasih Sudah Menggunakan Program Ini");
	for(i=1;i<79;i++){
		gotoxy(0+i,3);
		printf("%c",205);
	}
}

void menu_utama(){
	int pilihan;
	
	system("cls");
	dis_headerbox();
	gotoxy(17,2);
	printf("PROGRAM MENGHITUNG VOLUME DAN LUAS BANGUN RUANG");
	gotoxy(25,3);
	printf("KELOMPOK 9 ALGORITMA PEMOGRAMAN");
	dis_mainbox();
	
	gotoxy(18,11);
	printf("1.	Tabung");
	gotoxy(18,14);
	printf("2.	Bola");
	gotoxy(18,17);
	printf("3.	Limas Segiempat");
	gotoxy(18,20);
	printf("4.	Prisma Segitiga");
	gotoxy(18,23);
	printf("5.	Kerucut");
	gotoxy(18,26);
	printf("6.	Keluar");
	gotoxy(18,30);
	printf("Masukan Pilihan Anda :");
    scanf("%d", &pilihan);
    fflush(stdin);
    system("cls");
    
    if (pilihan==1){
        menu_tabung();
	}else if (pilihan==2){
        menu_bola();
	}else if (pilihan==3){
        menu_limas_segiempat();
	}else if (pilihan==4){
        menu_prisma_segitiga();
	}else if (pilihan==5){
        menu_kerucut();
	}else if (pilihan==6){
		keluar();
	}else{
		int i;
		
		gotoxy(20,2);
		printf("Input Yang Anda Masukan Salah");
		gotoxy(17,3);
		printf("Masukan Sesuai Input Yang Disediakan");
		
		for(i=1;i<79;i++){
			gotoxy(0+i,1);
			printf("%c",205);
		}

		for(i=1;i<79;i++){
			gotoxy(0+i,4);
			printf("%c",205);
		}
		getch();
		menu_utama();
	}

}


int main(){
    menu_utama();

    return 0;
}
