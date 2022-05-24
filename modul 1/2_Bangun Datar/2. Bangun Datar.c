/*  Modul 1 Praktikum Algoritna Pemograman                  									*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>															
#include <windows.h>

#define PHI 3.14


void pilihan_keluar(int ulang,int kembali);
void menu_segitiga_sembarang();
void luas_segitiga_sembarang();
void keliling_segitiga_sembarang();
void menu_belah_ketupat();
void luas_belah_ketupat();
void keliling_belah_ketupat();
void menu_jajar_genjang();
void luas_jajar_genjang();
void keliling_jajar_genjang();
void menu_trapesium();
void luas_trapesium();
void keliling_trapesium();
void menu_lingkaran();
void luas_lingkaran();
void keliling_lingkaran();
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

float input(){
     int i = 0;
    int cntd = 0;
    int cnt = 0;
    float val;
    char nama[100];


    scanf("%s", &nama);


    while(nama[i] != '\0'){
        if(nama[0] == '.'){
            cnt = 1;
            nama[0] = '\0';
        }else if(nama[i]>='0' && nama[i]<='9' || nama[i] == '.' || nama[0] == '-'){
            if(nama[i] == '.'){
            cntd = cntd + 1;
                if(cntd > 1 || nama[i+1] == '\0'){
                    cnt = 1;
                    nama[i] = '\0';
                }
            }
            i++;
        }else{
            cnt = 1;
            nama[i] = '\0';
        }
    }

    val = atof(nama);

    if(cnt == 1){
        printf("\n\tMasukkan salah! Masukkan nilai yang benar : ");
        return input();
    }else if(val <= 0){
        printf("\n\tMasukkan Tidak boleh kurang dari sama dengan 0! Masukkan nilai yang benar : ");
        return input();
    }else{
        return val;
    }
}

void pilihan_keluar(int ulang,int kembali){
    char mengulang;

    printf("\n\tLakukan lagi? ya/kembali/keluar(y/t/k) : ");
    fflush(stdin);
    scanf("%c", &mengulang);
    if(mengulang != 'y' && mengulang != 't' && mengulang != 'k'){
        printf("Masukan anda salah!");
        getch();
        pilihan_keluar(ulang,kembali);
    }else if(mengulang == 't' || mengulang == 'T'){
        system("cls");
        switch(kembali){
            case 1:
                menu_segitiga_sembarang();
                break;
            case 2:
                menu_belah_ketupat();
                break;
            case 3:
                menu_jajar_genjang();
                break;
            case 4:
                menu_trapesium();
                break;
            case 5:
                menu_lingkaran();
                break;
        }
    }else if(mengulang == 'y'|| mengulang == 'Y'){
        system("cls");
        switch(ulang){
            case 1:
                luas_segitiga_sembarang();
                break;
            case 2:
                keliling_segitiga_sembarang();
                break;
            case 3:
                luas_belah_ketupat();
                break;
            case 4:
                keliling_belah_ketupat();
                break;
            case 5:
                luas_jajar_genjang();
                break;
            case 6:
                keliling_jajar_genjang();
                break;
            case 7:
                luas_trapesium();
                break;
            case 8:
                keliling_trapesium();
                break;
            case 9:
                luas_lingkaran();
                break;
            case 10:
                keliling_lingkaran();
                break;
        }
    }else{
        keluar();
    }
}

void menu_segitiga_sembarang(){
	int pilihan;
    
    system("cls");
	dis_headerbox();
	gotoxy(17,2);
	printf("PROGRAM MENGHITUNG KELILING DAN LUAS BANGUN DATAR");
	gotoxy(31,3);
	printf("SEGITIGA SEMBARANG");
	dis_mainbox();
	
	gotoxy(18,11);
	printf("MENU :");
	gotoxy(18,14);
	printf("1.	Hitung Luas");
	gotoxy(18,17);
	printf("2.	Hitung Keliling");
	gotoxy(18,20);
	printf("3.	Kembali");
	gotoxy(18,23);
	printf("4.	Keluar");
	gotoxy(18,30);
	printf("Masukan Pilihan Anda :");

	gotoxy(18,11);
	printf("MENU :");
	gotoxy(18,14);
	printf("1.	Hitung Luas");
	gotoxy(18,17);
	printf("2.	Hitung Keliling");
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
        luas_segitiga_sembarang();
	}else if (pilihan==2){
        keliling_segitiga_sembarang();
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
		menu_segitiga_sembarang();
	}
}

void luas_segitiga_sembarang(){
    system("cls");

    float sisi1, sisi2, sisi3, pilihan;
    float keliling,s,luas;
    char mengulang;
    
    dis_headerbox();
	gotoxy(25,2);
	printf("MENGHITUNG LUAS SEGITIGA SEMBARANG");

	gotoxy(0,7);
    printf("\tRumus : akar(s*( s - sisi1 )*( s - sisi2 )*( s - sisi3 ))");
    printf("\n\tTolong Masukkan Nilai Yang Dibutuhkan");
    printf("\n\tMasukkan nilai sisi1 : ");
	sisi1 = input();	
    printf("\n\tMasukkan nilai sisi2 : ");
    sisi2 = input();
    printf("\n\tMasukkan nilai sisi3 : ");
    sisi3 = input();

    if(sisi1 == sisi2 || sisi1 == sisi3 || sisi2 == sisi3){
        printf("\n\tPanjang sisi tidak boleh sama");
        getch();
        system("cls");
        luas_segitiga_sembarang();
    }else{
        keliling = sisi1+sisi2+sisi3;
        s = keliling/2;

        if(sisi1>s || sisi2>s || sisi3>s){
            printf("\tPanjang sisi tidak sesuai");
            getch();
            system("cls");
            luas_segitiga_sembarang();
        }else{
            luas = sqrt(s*(s-sisi1)*(s-sisi2)*(s-sisi3));
            if(luas<=0){
                printf("\n\tPanjang sisi kurang mencukupi");
                getch();
                system("cls");
                luas_segitiga_sembarang();
            }else{
                printf("\n\tLuas segitiga sembarang adalah %.2f", luas);
                pilihan_keluar(1,1);
            }
        }
    }
}


void keliling_segitiga_sembarang(){
    system("cls");

    float sisi1,sisi2,sisi3,pilihan;
    float keliling,s,luas;
    char mengulang;
    
	dis_headerbox();
	gotoxy(24,2);
	printf("MENGHITUNG KELILING SEGITIGA SEMBARANG");

	gotoxy(0,7);
    printf("\n\tRumus : sisi1+sisi2+sisi3");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    printf("\n\tMasukkan nilai sisi1 : ");
    sisi1 = input();
    printf("\n\tMasukkan nilai sisi2 : ");
    sisi2 = input();
    printf("\n\tMasukkan nilai sisi3 : ");
    sisi3 = input();

    if(sisi1 == sisi2 || sisi1 == sisi3 || sisi2 == sisi3){
        printf("\n\tPanjang sisi tidak boleh sama");
        getch();
        system("cls");
        keliling_segitiga_sembarang();
    }else{
        keliling = sisi1+sisi2+sisi3;
        s = keliling/2;

        if(sisi1>s || sisi2>s || sisi3>s){
            printf("\n\tPanjang sisi tidak sesuai");
            getch();
            system("cls");
            luas_segitiga_sembarang();
        }else{

            printf("\n\tLuas segitiga sembarang adalah %.2f", keliling);
            pilihan_keluar(2,1);
        }
    }
}

void menu_belah_ketupat(){
    int pilihan;
    
    system("cls");
	dis_headerbox();
	gotoxy(17,2);
	printf("PROGRAM MENGHITUNG KELILING DAN LUAS BANGUN DATAR");
	gotoxy(36,3);
	printf("BELAH KETUPAT");
	dis_mainbox();
	
	gotoxy(18,11);
	printf("MENU :");
	gotoxy(18,14);
	printf("1.	Hitung Luas");
	gotoxy(18,17);
	printf("2.	Hitung Keliling");
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
        luas_belah_ketupat();
	}else if (pilihan==2){
        keliling_belah_ketupat();
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
		menu_belah_ketupat();
	}
    
}
  
void luas_belah_ketupat(){
    system("cls");
    float diagonal1,diagonal2,luas,pilihan;
    char mengulang;

	dis_headerbox();
	gotoxy(25,2);
	printf("MENGHITUNG LUAS BELAH KETUPAT");
	
	gotoxy(0,7);
    printf("\n\tRumus : 1/2*diagonal1*diagonal2");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    printf("\n\tMasukkan nilai diagonal 1 : ");
    diagonal1= input();
    printf("\n\tMasukkan nilai diagonal 2 : ");
    diagonal2 = input();

    luas = diagonal1*diagonal2/2;

    printf("\n\tLuas belah ketupat adalah %.2f", luas);
    pilihan_keluar(3,2);
}

void keliling_belah_ketupat(){
    system("cls");
    float sisi,keliling,pilihan;
    char mengulang;

	dis_headerbox();
	gotoxy(24,2);
	printf("MENGHITUNG KELILING BELAH KETUPAT");
	
	gotoxy(0,7);
    printf("\n\tRumus : 4*sisi");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    printf("\n\tMasukkan sisi belah ketupat : ");
    sisi = input();

    keliling = sisi*4;

    printf("\n\tKeliling belah ketupat adalah %.2f", keliling);
    pilihan_keluar(4,2);
}
void menu_jajar_genjang (){
	int pilihan;
    
    system("cls");
	dis_headerbox();
	gotoxy(17,2);
	printf("PROGRAM MENGHITUNG KELILING DAN LUAS BANGUN DATAR");
	gotoxy(33,3);
	printf("JAJARGENJANG");
	dis_mainbox();
	
	gotoxy(18,11);
	printf("MENU :");
	gotoxy(18,14);
	printf("1.	Hitung Luas");
	gotoxy(18,17);
	printf("2.	Hitung Keliling");
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
        luas_jajar_genjang();
	}else if (pilihan==2){
        keliling_jajar_genjang();
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
		menu_jajar_genjang();
	}
    
}


void luas_jajar_genjang(){
    system("cls");
    float alas,tinggi,luas,pilihan;
    char mengulang;

	dis_headerbox();
	gotoxy(25,2);
	printf("MENGHITUNG LUAS JAJARGENJANG");

	gotoxy(0,7);
    printf("\n\tRumus : a*t");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    printf("\n\tMasukkan nilai alas : ");
    alas = input();
    printf("\n\tMasukkan nilai tinggi : ");
    tinggi = input();

    luas = alas*tinggi;

    printf("\n\tLuas jajar genjang adalah %.2f", luas);
    pilihan_keluar(5,3);
}

void keliling_jajar_genjang(){
    system("cls");
    float sisi1,sisi2,keliling,pilihan;
    char mengulang;

	dis_headerbox();
	gotoxy(23,2);
	printf("MENGHITUNG KELILING JAJARGENJANG");

	gotoxy(0,7);
    printf("\n\tRumus : 2*(sisi1+sisi2)");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    printf("\n\tMasukkan sisi1 jajar genjang : ");
    sisi1 = input();
    printf("\n\tMasukkan sisi2 jajar genjang : ");
    sisi2 = input();

    keliling = 2*(sisi1+sisi2);

    printf("\n\tKeliling jajar genjang adalah %.2f", keliling);
    pilihan_keluar(6,3);
}

void menu_trapesium(){
   	int pilihan;
    
    system("cls");
	dis_headerbox();
	gotoxy(17,2);
	printf("PROGRAM MENGHITUNG KELILING DAN LUAS BANGUN DATAR");
	gotoxy(36,3);
	printf("TRAPESIUM");
	dis_mainbox();
	
	gotoxy(18,11);
	printf("MENU :");
	gotoxy(18,14);
	printf("1.	Hitung Luas");
	gotoxy(18,17);
	printf("2.	Hitung Keliling");
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
        luas_trapesium();
	}else if (pilihan==2){
        keliling_trapesium();
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
		menu_trapesium();
	}
    
}

void luas_trapesium(){
    system("cls");
    float sisia,sisib,tinggi,luas,pilihan;
    char mengulang;
    
    dis_headerbox();
	gotoxy(26,2);
	printf("MENGHITUNG LUAS TRAPESIUM");

	gotoxy(0,7);
    printf("\n\tRumus : (sisia+sisib)*t/2");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    printf("\n\tMasukkan nilai sisi a : ");
    sisia = input();
    printf("\n\tMasukkan nilai sisi b : ");
    sisib = input();
    printf("\n\tMasukkan nilai tinggi : ");
    tinggi = input();

    luas = (sisia+sisib)*tinggi/2;

    printf("\n\tLuas trapesium adalah %.2f", luas);
    pilihan_keluar(7,4);
}

void keliling_trapesium(){
    system("cls");
    float sisiab,sisicd,sisica,sisidb,keliling,pilihan;
    char mengulang;

	dis_headerbox();
	gotoxy(24,2);
	printf("MENGHITUNG KELILING TRAPESIUM");
	
	gotoxy(0,7);
    printf("\n\tRumus : sisiAB+sisiCD+sisiCA+sisiDB");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    printf("\n\tMasukkan sisi AB : ");
    sisiab = input();
    printf("\n\tMasukkan sisi CD : ");
    sisicd = input();
    printf("\n\tMasukkan sisi CA : ");
    sisica = input();
    printf("\n\tMasukkan sisi DB : ");
    sisidb = input();

    keliling = sisiab + sisicd + sisica + sisidb;

    printf("\n\tKeliling trapesium adalah %.2f", keliling);
    pilihan_keluar(8,4);
}

void menu_lingkaran(){
	int pilihan;
    
    system("cls");
	dis_headerbox();
	gotoxy(17,2);
	printf("PROGRAM MENGHITUNG KELILING DAN LUAS BANGUN DATAR");
	gotoxy(36,3);
	printf("LINGKARAN");
	dis_mainbox();
	
	gotoxy(18,11);
	printf("MENU :");
	gotoxy(18,14);
	printf("1.	Hitung Luas");
	gotoxy(18,17);
	printf("2.	Hitung Keliling");
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
        luas_lingkaran();
	}else if (pilihan==2){
        keliling_lingkaran();
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
		menu_lingkaran();
	}
    
}

void luas_lingkaran(){
    system("cls");
    float jari,luas,pilihan;
    char mengulang;

	dis_headerbox();
	gotoxy(25,2);
	printf("MENGHITUNG LUAS LINGKARAN");

	gotoxy(0,7);
    printf("\n\tRumus : PHI*r^2");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    printf("\n\tMasukkan nilai jari-jari: ");
	jari = input();

    luas = PHI*jari*jari;

    printf("\n\tLuas lingkaran adalah %.2f", luas);
    pilihan_keluar(9,5);
}

void keliling_lingkaran(){
    system("cls");
    float jari,keliling,pilihan;
    char mengulang;

	dis_headerbox();
	gotoxy(25,2);
	printf("MENGHITUNG KELILING LINGKARAN");

    printf("\n\tRumus : PHI*(r*2)");
    printf("\n\tTolong masukkan nilai yang dibutuhkan");
    printf("\n\tMasukkan nilai jari-jari: ");
	jari = input();

    keliling = jari*2*PHI;

    printf("\n\tKeliling lingkaran adalah %.2f", keliling);
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
	printf("PROGRAM MENGHITUNG KELILING DAN LUAS BANGUN DATAR");
	gotoxy(25,3);
	printf("KELOMPOK 9 ALGORITMA PEMOGRAMAN");
	dis_mainbox();
	
	gotoxy(18,11);
	printf("1.	Segitiga Sembarang");
	gotoxy(18,14);
	printf("2.	Belah Ketupat");
	gotoxy(18,17);
	printf("3.	Jajargenjang");
	gotoxy(18,20);
	printf("4.	Trapesium");
	gotoxy(18,23);
	printf("5.	Lingkaran");
	gotoxy(18,26);
	printf("6.	Keluar");
	gotoxy(18,30);
	printf("Masukan Pilihan Anda :");
    scanf("%d", &pilihan);
    fflush(stdin);
    system("cls");
    
    if (pilihan==1){
        menu_segitiga_sembarang();
	}else if (pilihan==2){
        menu_belah_ketupat();
	}else if (pilihan==3){
        menu_jajar_genjang();
	}else if (pilihan==4){
        menu_trapesium ();
	}else if (pilihan==5){
        menu_lingkaran ();
	}else if (pilihan==6){
		keluar();
	}else{
		int i;
		
		gotoxy(20,2);
		printf("Input yang anda masukan salah");
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

