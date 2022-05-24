#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>														
#include <math.h>															
#include <windows.h>
#define MAX 100

char kata [100], temp;
int opsi, geser, i;

void end();
void menu();
void deskripsi();
int validInt(int *var);
void spam();

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



//menu program
int validInt(int *var){
    char buff[1024];
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
        fflush(stdin);
        if(validInt(var))
            break;
        printf("\n\t\tInput salah! Silahkan coba lagi.\n");
    }
}

void rangeVldInt(int *var, int range1, int range2, char *prompt){
    while(1){
        reVldInt(var, prompt);
        fflush(stdin);
        if(*var >= range1  && *var <= range2)
            break;
        printf("\n\t\tInput salah! Silahkan coba lagi.\n");
    }
}

// Input validation of Encription
int validasi_enkripsi(){
    int key;
    int input, bil;
	char huruf;

    input=scanf("%d%c", &bil, &huruf);
    if(input!=2 || huruf!='\n'){
        spam();
        printf("\t\t!!! Masukan nilai salah, Silahkan masukan angka bukan huruf !!!.\n\n");
        system("pause");
        system("cls");
        enkripsi();
    }
    else{
		return bil;
    }
}

// Input validation of decription
int validasi_dekripsi(){
    int key;
    int input, bil;
	char huruf;

    input=scanf("%d%c", &bil, &huruf);
    if(input!=2 || huruf!='\n'){
        spam();
        printf("\t\t!!! Masukan nilai salah, Silahkan masukan angka bukan huruf !!!.\n\n");
        system("pause");
        system("cls");
        dekripsi();
    }
    else{
        return bil;
    }
}

void spam(void){
    char spam;
    while ((spam = getchar()) != '\n' && spam != EOF) ;
}

char * inputStringNotNull(char * pesan, char keterangan[]){
    do{
        printf("%s", keterangan);
        fflush(stdin);
        scanf("%[^\n]", pesan);
    }while(strcmp(pesan, "") == 0);
    return pesan;
}

// Function Encription
int enkripsi(){
	char pesan[100], ch;
	int i, key, angkaVal;

	system("cls");
	dis_headerbox();
	gotoxy(32,2);
	printf(" PROGRAM ENKRIPSI");
	gotoxy(25,3);
	printf("KELOMPOK 9 ALGORITMA PEMOGRAMAN");

	gotoxy(0,7);
    inputStringNotNull(pesan, "\n\tMasukan Plaintext : ");
	printf("\n\tMasukan jumlah pergeseran : ");
	key=validasi_enkripsi();

	for(i = 0; pesan[i] != '\0'; ++i){
		ch = pesan[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key;

			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}

			pesan[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;

			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}

			pesan[i] = ch;
		}
	}
	printf("\n\n\tHasil Enkripsi : %s", pesan);

	return 0;
}

// Function Decription
int dekripsi()
{
	char pesan[100], ch;
	int i, key;

	system("cls");
	dis_headerbox();
	gotoxy(32,2);
	printf(" PROGRAM DESKRIPSI");
	gotoxy(25,3);
	printf("KELOMPOK 9 ALGORITMA PEMOGRAMAN");
	
	gotoxy(0,7);
	inputStringNotNull(pesan,"\n\tMasukan Chiphertext: ");
	printf("\n\tMasukan Jumlah Pergeseran : ");
	key=validasi_dekripsi();

	for(i = 0; pesan[i] != '\0'; ++i){
		ch = pesan[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;

			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}

			pesan[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;

			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}

			pesan[i] = ch;
		}
	}

	printf("\n\n\tHasil Dekripsi : %s", pesan);
	return 0;
}

void sub_menu(int menu){
    if(menu == 1){
    	enkripsi();	
	}else if(menu == 2){
		dekripsi();	
	} 

    int ulang,kembali;

    printf("\n=================================================================================");
    rangeVldInt(&ulang,0,1,"\n\n\tIngin Mengulang Kembali \t [ 0(tidak) / 1(Ya) ] : ");
    if (ulang == 1) sub_menu(menu);
    else{
        rangeVldInt(&kembali,0,1,"\n\n\tKembali ke Menu Utama [ 0(tidak) / 1(Ya) ] : ");
        if (kembali == 1){
        	main();	
		}else{
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

        }
    }
}

// Function Main Menu
 int main(void){
    int menu;
    fflush(stdin);
    system("cls");
	dis_headerbox();
	gotoxy(25,2);
	printf(" PROGRAM ENKRIPSI DAN DESKRIPSI");
	gotoxy(25,3);
	printf("KELOMPOK 9 ALGORITMA PEMOGRAMAN");
	
	gotoxy(16,11);
	printf("Menu :");
	gotoxy(16,14);
	printf("[1] Enkripsi");
	gotoxy(16,17);
	printf("[2] Dekripsi");
	gotoxy(16,20);
	printf("[3] Keluar");
	rangeVldInt(&menu,1,3,"\n\n\t\tMenu yang dipilih : ");

	 switch (menu) {
        case 1:
        case 2:
            sub_menu(menu);
            break;
        case 3:
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
            break;
    }

    return(0);
}
