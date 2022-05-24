/*  Modul 1 Praktikum Algoritna Pemograman                 	*/

#include <stdio.h>														
#include <stdlib.h>
#include <conio.h>														
#include <math.h>															
#include <windows.h>												


typedef struct{
    float hasil,bilangan1,bilangan2;
}perhitungan;

float input();
void mengulang();
void menu_utama();
perhitungan operasi_kalkulator();
void penjumlahan();
void pengurangan();
void perkalian();
void pembagian();
void mod();
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

//Program
float input(){
    float num;
    char chara;
    if (scanf("%f%c",&num,&chara)!= 2  || chara != '\n' || chara == ','){
        fflush(stdin);
        printf("\n\tMasukan Salah! Masukkan inputan yang benar : ");
        return input();
    }else{
        return num;
    }
}

perhitungan operasi_kalkulator(int pilihan){
    perhitungan masukan;
	
    printf("\n\tMasukkan Bilangan Pertama : ");
    masukan.bilangan1 = input();
    printf("\n\tMasukkan Bilangan Kedua : ");
    masukan.bilangan2 = input();
    if((pilihan == 4 || pilihan == 5) && masukan.bilangan2 == 0){
        printf("\n\tMaaf penyebut tidak bisa dibagi 0! Masukkan nilai yang benar ");
        printf("\n ==============================================================================");
        return operasi_kalkulator(pilihan);
    }else{
        switch(pilihan){
            case 1:
                masukan.hasil = masukan.bilangan1 + masukan.bilangan2;
                break;
            case 2:
                masukan.hasil = masukan.bilangan1 - masukan.bilangan2;
                break;
            case 3:
                masukan.hasil = masukan.bilangan1 * masukan.bilangan2;
                break;
            case 4:
                masukan.hasil = masukan.bilangan1 / masukan.bilangan2;
                break;
            case 5:
                masukan.hasil = 0;
        }
    }
    return masukan;
}

void mengulang(int ulang){
    char pilihan;

    printf("\n\n\tLakukan lagi? Ya/Tidak/Keluar Dari Program (Y/T/K) : ");
    fflush(stdin);
    scanf("%c", &pilihan);
    
    if(pilihan == 'y'||pilihan == 'Y'){
        system("cls");
        switch(ulang) {
            case 1:
                penjumlahan();
                break;
            case 2:
                pengurangan();
                break;
            case 3:
                perkalian();
                break;
            case 4:
                pembagian();
                break;
            case 5:
                mod();
                break;
            default :
                printf("gagal");
                break;
        }
    }else if (pilihan == 'T' || pilihan == 't'){
        system("cls");
        menu_utama();
    }
    else if(pilihan == 'k' || pilihan == 'K'){
        keluar();
    }
    else{
        printf("\tMASUKAN DENGAN BENAR");
        mengulang(ulang);
    }
}

void penjumlahan(){
    perhitungan masukan;
    
    system("cls");
    
	dis_headerbox();
	gotoxy(30,2);
	printf("KALKULATOR PENJUMLAHAN");
	
	gotoxy(0,7);
    masukan = operasi_kalkulator(1);
    printf("\n\tHasil penjumlahan dari %.1f dengan %.1f adalah %.1f", masukan.bilangan1,masukan.bilangan2,masukan.hasil);
    mengulang(1);
}

void pengurangan(){
    perhitungan masukan;
    
    system("cls");
    
	dis_headerbox();
	gotoxy(30,2);
	printf("KALKULATOR PENGURANGAN");
	
	gotoxy(0,7);
    masukan = operasi_kalkulator(2);
    printf("\n\tHasil pengurangan dari %.1f dengan %.1f adalah %.1f", masukan.bilangan1,masukan.bilangan2,masukan.hasil);
    mengulang(2);
}

void perkalian(){
    perhitungan masukan;
    
    system("cls");
    
	dis_headerbox();
	gotoxy(30,2);
	printf("KALKULATOR PERKALIAN");

	gotoxy(0,7);	
    masukan = operasi_kalkulator(3);
    printf("\n\tHasil perkalian dari %.1f dengan %.1f adalah %.1f", masukan.bilangan1,masukan.bilangan2,masukan.hasil);
    mengulang(3);
}

void pembagian(){
    perhitungan masukan;

    system("cls");
    
	dis_headerbox();
	gotoxy(30,2);
	printf("KALKULATOR PEMBAGIAN");

	gotoxy(0,7);	
    masukan = operasi_kalkulator(4);
    printf("\n\tHasil pembagian dari %.1f dengan %.1f adalah %.1f", masukan.bilangan1,masukan.bilangan2,masukan.hasil);
    mengulang(4);
}

void mod(){
    perhitungan masukan;
    int pembulatan_bil1,pembulatan_bil2,hasil;


    system("cls");
    
	dis_headerbox();
	gotoxy(30,2);
	printf("KALKULATOR MODULUS");

	gotoxy(0,7);	
    masukan = operasi_kalkulator(5);
    pembulatan_bil1 = (masukan.bilangan1);
    pembulatan_bil2 = (masukan.bilangan2);
    hasil = pembulatan_bil1%pembulatan_bil2;
    printf("\n\tHasil modulus dari %d dengan %d adalah %d", pembulatan_bil1,pembulatan_bil2,hasil);
    mengulang(5);
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
	
	//deklarasi variabel
	int pilihan;
	
	system("cls");
	dis_headerbox();
	gotoxy(36,2);
	printf("KALKULATOR");
	gotoxy(25,3);
	printf("KELOMPOK 9 ALGORITMA PEMOGRAMAN");
	dis_mainbox();
	
	//mencetak pilihan dan meminta input user
	gotoxy(18,11);
	printf("1.	Penjumlahan");
	gotoxy(18,14);
	printf("2.	Pengurangan");
	gotoxy(18,17);
	printf("3.	Perkalian");
	gotoxy(18,20);
	printf("4.	Pembagian");
	gotoxy(18,23);
	printf("5.	Modulus");
	gotoxy(18,26);
	printf("6.	Keluar");
	gotoxy(18,30);
	printf("Masukan Pilihan Anda :");
    scanf("%d", &pilihan);
    fflush(stdin);
    system("cls");
    
    if (pilihan==1){
		penjumlahan();
	}else if (pilihan==2){
		pengurangan();
	}else if (pilihan==3){
		perkalian();
	}else if (pilihan==4){
		pembagian();
	}else if (pilihan==5){
		mod();
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
