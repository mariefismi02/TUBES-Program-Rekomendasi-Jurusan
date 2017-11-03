#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;

struct data{
	string nama,no_hp,tpt_lahir, tgl_lahir;
	string jk;
	string mb_poin[8];
	string rekomend;
}hasil[500];
int bts=0;

string kategori[8]={"Linguistik", "Logis Matematis", "Visual Spasial", "Musikal", "Kinestetik", "Interpersonal", "Intrapersonal", "Naturalis"};

void menu1(){
	system("tubes.exe");
}

void menu2(){
	system("cls");
	ifstream file("doc.txt");
	bts=0;
	while(file.good()){
		getline(file, hasil[bts].nama,',');
		getline(file, hasil[bts].jk,',');
		getline(file, hasil[bts].no_hp,',');
		getline(file, hasil[bts].tpt_lahir,',');
		getline(file, hasil[bts].tgl_lahir,'.');
		for(int i=0;i<8;i++){
			if(i<7)
			getline(file, hasil[bts].mb_poin[i], '_');
			else
			getline(file, hasil[bts].mb_poin[i], ';'); 
		}
		getline(file, hasil[bts].rekomend,'.');
		bts++;
	}
	cout<<"==============="<<endl;
	cout<<"===HASIL TES==="<<endl;
	cout<<"==============="<<endl;
	for(int i=0;i<bts-1;i++){
		cout<<"\n======================"<<endl;
		cout<<"TES "<<i+1<<":"<<endl;
		cout<<"======================"<<endl;
		cout<<"Nama	           :"<<hasil[i].nama<<endl;
		cout<<"Jenis Kelamin      :"<<hasil[i].jk<<endl;
		cout<<"No. HP             :"<<hasil[i].no_hp<<endl;
		cout<<"Tempat Lahir	   :"<<hasil[i].tpt_lahir<<endl;
		cout<<"Tanggal Lahir      :"<<hasil[i].tgl_lahir<<endl;
		cout<<"----------------------"<<endl;
		cout<<"Nilai:"<<endl;
		cout<<"----------------------"<<endl;
		for(int j=0;j<8;j++){
			cout<<kategori[j]<<"\t:"<<hasil[i].mb_poin[j]<<endl;
		}
		cout<<"----------------------"<<endl;
		cout<<"Rekomendasi Jurusan:"<<endl<<hasil[i].rekomend;
	}
}

int main(){
	system("title Program Rekomendasi Jurusan");
	int pilih;
	while(pilih!=3){
	system("cls");
	cout<<" MENU\n";
	cout<<" 1. Jalankan tes\n";
	cout<<" 2. Lihat hasil\n";
	cout<<" 3. Keluar\n";
	cout<<" Pilih : ";cin>>pilih;
	
	switch(pilih){
		case 1 : menu1(); break;
		case 2 : menu2(); break;
		case 3 : return 0; break;
		default: cout<<"Input Salah!!!"<<endl;break;
	}
	 system("pause");
	}
	return 0;
}


