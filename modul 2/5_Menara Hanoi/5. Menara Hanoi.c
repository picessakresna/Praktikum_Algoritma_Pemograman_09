#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>															
#include <windows.h>

void iteratif();
void rekursif();
void clean();

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

int total=0;
int main(){

	int jumlah, menu;
	char ulang;
	do {
		system("cls");
		dis_headerbox();
		gotoxy(31,2);
		printf("PROGRAM MENARA HANOI ");
		gotoxy(25,3);
		printf("KELOMPOK 9 ALGORITMA PEMOGRAMAN");
		
		gotoxy(0,11);
		printf("\t[1] Menara Hanoi Iteratif");
		gotoxy(0,14);
		printf("\t[2] Menara Hanoi Rekursif");
		gotoxy(0,17);
		printf("\t[3] Keluar");
		gotoxy(0,21);
		printf("\t=>Pilihan Anda : ");
		
        validasi(&menu, "menu", 3);
        if (menu == 3)
        {
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
            return 0;
        }
        clean();
        if(menu == 1){
                
                system("cls || clear");
				dis_headerbox();
				gotoxy(26,2);
				printf("PROGRAM MENARA HANOI ITERATIF ");
				gotoxy(25,3);
				printf("KELOMPOK 9 ALGORITMA PEMOGRAMAN");
				
				gotoxy(0,11);
				printf("\n\tInput Jumlah Kepingan: ");
                validasi(&jumlah, "jumlah ", 50);
                iteratif(jumlah);
                printf("\n\tTotal Langkah \t= %d\n",total);
        }

        else if(menu ==2){

                
                system("cls || clear");

				dis_headerbox();
				gotoxy(26,2);
				printf("PROGRAM MENARA HANOI REKURSIF ");
				gotoxy(25,3);
				printf("KELOMPOK 9 ALGORITMA PEMOGRAMAN");
				
				gotoxy(0,11);
                printf("\n\tInput Jumlah Kepingan: ");
                validasi(&jumlah, "jumlah ", 50);
                rekursif(jumlah, 1, 2, 3);
                printf("\n\tTotal Langkah \t= %d\n",total);
        }
        total = 0;
        clean();
        printf("\n\tProgram Selesai, Ingin Mengulangi ? : [y/n] ");
        scanf("%c", &ulang);
    }   while (ulang == 'y' || ulang == 'Y');
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

    return 0;
}

void iteratif(int n){
    int x;
    for(x=1;x<(1 << n);x++){
		printf("\tKepingan dipindahkan dari %d ke %d\n",(x-(x&-x))%3+1,(x+(x&-x))%3+1);
		total++;
	}
	printf("\n\n\tSeluruh kepingan telah dipindahkan!\n\n");
}

void rekursif(int piringan, int asal, int temp, int tujuan){
	if(piringan>0){
		total++;
		rekursif(piringan-1, asal, tujuan, temp);
		printf("\tkepingan %d dipindahkan dari %d ke %d\n",piringan, asal, tujuan);
		rekursif(piringan-1, temp, asal, tujuan);
	}
}

int validasi(int *var, char nama[100], int size)
{
    if (scanf("%d", var) != 1)
    {
        clean();
        printf("\tInput Hanya angka, mohon masukkan ulang %s! : ", nama);
        validasi(var, nama, size);
    } else if (*var > size)
    {
        clean();
        printf("\tAngkanya melebihi batas (%d)!, mohon masukkan ulang %s! : ", size, nama);
        validasi(var, nama, size);
    }
    return 1;
}


void clean()
{
    while (getchar() != '\n')
        ;
}

