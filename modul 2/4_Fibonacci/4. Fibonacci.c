#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>	
#include <windows.h>

void menu();
void iteratif();
void rekursif();
void invalid ();
void reset();
double input();

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

void invalid (){
    gotoxy(0,20);
    printf("\n\tData Invalid\n");

}
int main(){
	system("cls");
    menu();
    return 0;

}

void menu(){
    int pilih, size;

	dis_headerbox();
	gotoxy(31,2);
	printf("PROGRAM FIBONACCI ");
	gotoxy(25,3);
	printf("KELOMPOK 9 ALGORITMA PEMOGRAMAN");

	gotoxy(0,9);
	printf("\t[1] Fibonacci Iteratif");
	gotoxy(0,12);
	printf("\t[2] Fibonacci Rekursif");
	gotoxy(0,15);
	printf("\t[3] Keluar");
	gotoxy(0,18);
	printf("\t=>Pilihan Anda : ");
    pilih =input();
    if(pilih == 1 || pilih == 2){
        printf("\n\tMasukkan Panjang Deret Bilangan : ");
        size =input();
        if(size<=0){
            reset();
        }
        switch(pilih){
            case 1:
                iteratif(size);
                reset();
                break;

            case 2 :
                rekursif(size);
                reset();
                break;
                
        }

    }else if(pilih == 3){
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
        exit(0);
    }else{
    	system("cls");
        invalid();
        menu();
	}

}

double input(){
	double bilangan;
	char karakter;

	if (scanf("%lf%c", &bilangan, &karakter)!= 2 || bilangan<= 0 || karakter != '\n' || karakter == ','){
		fflush(stdin);
		printf ("\n\tInput tidak valid! Masukan data dengan benar :");
		return input();
	} else{
		return bilangan;
	}
}

int fibonacci(int size){
    if (size == 0){
        return 0;
    } else if (size == 1){
        return 1;
    } else {
       return fibonacci(size-2) + fibonacci(size-1);
    }
}

void iteratif(int size){
    int a[size];
    int i;
    printf("\n\tDeret Fibonacci Dengan Cara Iteratif : \n\t",size);
	for (i=1; i<=size ; i++){
        if(i == 1){
            a[i] = 1;
        } else if (i == 2){
            a[i] = 1;
        } else {
            a[i] = a[i-1] + a[i-2];
        }
        
        printf("%d ",a[i]);
    }
    printf("\n");

}

void rekursif(int size){
    int a[size];
    int i;
    printf("\n\tDeret Fibonacci Dengan Cara Rekursif : \n\t",size);
    for (i = 0;i <= size-1; i++){
        a[i] = fibonacci(i);
            printf("%d ",a[i]);
    }
    printf("\n");
}

void reset(){
	char opt[1];

	printf ("\n\tApakah anda ingin kembali melakukan operasi? [Y/N] ");
	gets(opt);

	if (!(strcmp(opt, "Y")) ||! (strcmp(opt, "y"))){
		system ("cls");
		menu();
	}
	else if (!(strcmp(opt, "N")) ||! (strcmp(opt, "n"))){
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
		return;
	}
	else {

		printf ("Input yang anda masukan tidak valid!\n\a");
		reset();
	}
}

