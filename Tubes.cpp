#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<fstream>
using namespace std;
struct data{
	string nama;
	char JK;
	string tmpt_lahir;
	string tgl_lahir;
	char no_hp[13];
	string jurusan;
	int semester;
	int mtk[6], fisika[6], kimia[6], biologi[6];
	int geografi[6], ekonomi[6], sosiologi[6], sejarah[6];
	int bindo[6], bing[6];
	int sino_anto, logis_analis, aritmatik, analogi;
	int mb_poin[8];
	int rata;
}biodata;

struct pertanyaan{
	string soal;
	string kategori;
	string jawaban[4];
	string jBenar;
}text[200];

struct soal_{
	string soal;
	string kategori;
}question[80];

int mtk=0, fisika=0, kimia=0, biologi=0;
int geo=0, eko=0, sosio=0, sejarah=0;
int bindo=0, bing=0;

string kategori[7]={"Sinonim", "Logika", "Analitik", "Antonim", "Hitung", "Barisan dan deret", "Analogi"};
string kategori2[8]={"Linguistik", "Logis Matematis", "Visual Spasial", "Musikal", "Kinestetik", "Interpersonal", "Intrapersonal", "Naturalis"};
string kate[8]={"L","LM","VS","M","K","IA","IE","N"};
string ans[]={"Ya","Tidak"};

struct jurus{
	string kategori;
	string jrs;
	string bid[2];
	string kel;
}jur[100];

int tot=0;


char quest;

void minat_bakat();
void rekomendasi();

void hitung_akhir(){
	biodata.mb_poin[0]=(biodata.mb_poin[0]*10+biodata.sino_anto+bindo+bing)/4;
	biodata.mb_poin[1]=(biodata.mb_poin[1]*10+biodata.logis_analis+biodata.aritmatik+mtk+fisika+kimia)/6;
	biodata.mb_poin[2]=(biodata.mb_poin[2]*10+biodata.analogi+biologi+geo+sejarah)/5;
	biodata.mb_poin[3]=(biodata.mb_poin[3]*10+biodata.analogi+bindo+bing)/4;
	biodata.mb_poin[4]=(biodata.mb_poin[4]*10+biodata.analogi+sosio)/3;
	biodata.mb_poin[5]=(biodata.mb_poin[5]*10+biodata.analogi+biodata.sino_anto+sosio)/4;
	biodata.mb_poin[6]=(biodata.mb_poin[6]*10+biodata.logis_analis+biodata.analogi)/3;
	biodata.mb_poin[7]=(biodata.mb_poin[7]*10+biodata.analogi+biologi+kimia+fisika)/5;
}

void Biodata(){
	system("cls");
	cout<<"BIODATA:"<<endl;
	cout<<"===========\n";
	cout<<"Nama           :";cin>>biodata.nama;
	cout<<"Jenis Kelamin  :";cin>>biodata.JK;
	cout<<"Tempat Lahir   :";cin>>biodata.tmpt_lahir;
	cout<<"Tanggal Lahir  :";cin>>biodata.tgl_lahir;
	cout<<"No. Telp/HP    :";cin>>biodata.no_hp;
	cout<<"Apakah anda yakin data telah benar?(y/n)";cin>>quest;
}

void Nilai_rapor(){
	balik:
	system("cls");
	cout<<"INPUT NILAI RAPOR:\n";
	cout<<"====================\n";
	cout<<"PILIH JURUSAN(IPA/IPS):";cin>>biodata.jurusan;
	back:
	cout<<"SEMESTER YANG TELAH DITEMPUH: ";cin>>biodata.semester;
	if(biodata.semester<2 || biodata.semester>6){
		cout<<"Semester harus minimal 2 dan masksimal 6!"<<endl;system("pause");goto back;
	}
	switch(biodata.jurusan[2]){
		case 'A': for(int i=0;i<biodata.semester;i++){
				  cout<<"---------------"<<endl;
				  cout<<"|  SEMESTER "<<i+1<<" |"<<endl;
				  cout<<"---------------"<<endl;
				  cout<<"Matematika        :";cin>>biodata.mtk[i];
				  cout<<"Fisika            :";cin>>biodata.fisika[i];
				  cout<<"Kimia             :";cin>>biodata.kimia[i];
				  cout<<"Biologi      	   :";cin>>biodata.biologi[i];
				  cout<<"B. Indonesia      :";cin>>biodata.bindo[i];
				  cout<<"B. Inggris        :";cin>>biodata.bing[i];
				  cout<<endl<<endl;
				  }
				  break;
		case 'S': for(int i=0;i<biodata.semester;i++){
				  cout<<"SEMESTER "<<i+1<<endl;
				  cout<<"Geografi     	   :";cin>>biodata.geografi[i];
				  cout<<"Ekonomi      	   :";cin>>biodata.ekonomi[i];
				  cout<<"Sosiologi    	   :";cin>>biodata.sosiologi[i];
				  cout<<"Sejarah      	   :";cin>>biodata.sejarah[i];
				  cout<<"B. Indonesia      :";cin>>biodata.bindo[i];
				  cout<<"B. Inggris        :";cin>>biodata.bing[i];
				  cout<<endl<<endl;
				  }
				  break;
		default : cout<<"INPUT SALAH!!!"; goto balik;break;
	}
	cout<<" apakah yakin nilai yang diinput sudah benar ?(y/n) : ";cin>>quest;
}

void soal();

void saving(string jrsn[], int mx);

int rata_rapor(){
	mtk=0, fisika=0, kimia=0, biologi=0;
	geo=0, eko=0, sosio=0, sejarah=0;
	bindo=0, bing=0;
	switch(biodata.jurusan[2]){
		case 'A' : for(int i=0;i<biodata.semester;i++){
					mtk+=biodata.mtk[i];
					biologi+=biodata.biologi[i];
					fisika+=biodata.fisika[i];
					kimia+=biodata.kimia[i];
					bindo+=biodata.bindo[i];
					bing+=biodata.bing[i];
			}
			mtk/=biodata.semester;
			biologi/=biodata.semester;
			fisika/=biodata.semester;
			kimia/=biodata.semester;
			bindo/=biodata.semester;
			bing/=biodata.semester;
		return (mtk+kimia+biologi+fisika+bindo+bing)/(biodata.semester*6);
		break;
		case 'S' : for(int i=0;i<biodata.semester;i++){
					sejarah+=biodata.sejarah[i];
					geo+=biodata.geografi[i];
					sosio+=biodata.sosiologi[i];
					eko+=biodata.ekonomi[i];
					bindo+=biodata.bindo[i];
					bing+=biodata.bing[i];
			}
			sejarah/=biodata.semester;
			geo/=biodata.semester;
			sosio/=biodata.semester;
			eko/=biodata.semester;
			bindo/=biodata.semester;
			bing/=biodata.semester;
		return (eko+sosio+sejarah+geo+bindo+bing)/(biodata.semester*6);
		break;
	}
}

void psikotes(){
	char pil;
	int n[200]={0};
	int a=0;
	string abj="abcd";
	int jb, bts; 
	biodata.sino_anto=0, biodata.analogi=0, biodata.logis_analis=0, biodata.aritmatik=0;
	
	
	srand(time(NULL));
	system("cls");
	cout<<"TAHAP PSIKOTES\n";
	cout<<"====================\n";
	cout<<"PERHATIAN\nHal-hal yang harus diperhatikan sebelum memulai mengerjakan soal!"<<endl;
	cout<<"-Anda akan mengejarkan total 70 soal pilihan ganda\n";
	cout<<"-Isilah jawaban yang menurut anda benar\n";
	cout<<"-Pilih jawaban dengan huruf kecil\n";
	cout<<"-Kerjakan soal dengan jujur(jangan cari di google atau nanya temen)\n";
	cout<<"-Jangan terlalu serius ini bukan ujian\n";
	cout<<system("pause");
	
	for(int i=0;i<70;i++){
		if(i%10==0)bts=i*2;
		
		system("cls");
		x:
		n[i]=bts + rand()%20;
		for(int j=bts/2;j<i;j++){
			if(i!=j && n[j]==n[i])//simple sequential search
			goto x;
		}
		a=n[i];
		cout<<i+1<<"."<<text[a].soal<<"..."<<endl;
		for(int k=0;k<4;k++){
			if(text[a].kategori==kategori[1] || text[a].kategori==kategori[2]){
				cout<<"  "<<abj[k]<<"."<<text[a].jawaban[k]<<endl;
			}
			else
			{
				if(k%2==1)cout<<"\t\t";
				cout<<"   "<<abj[k]<<"."<<text[a].jawaban[k];
				if(k%2==1)cout<<endl;
			}

		}	
		cout<<"Pilih: ";cin>>pil;
		switch(pil){
			case 'a': jb=0; break;
			case 'b': jb=1; break;
			case 'c': jb=2; break;
			case 'd': jb=3; break; 
		}
		if(text[a].jawaban[jb]==text[a].jBenar){
			if(text[a].kategori==kategori[0] || text[a].kategori==kategori[3]){
				biodata.sino_anto++;
			}
			else
			if(text[a].kategori==kategori[1] || text[a].kategori==kategori[2]){
				biodata.logis_analis++;
			}
			else
			if(text[a].kategori==kategori[4] || text[a].kategori==kategori[5]){
				biodata.aritmatik++;
			}
			else
			if(text[a].kategori==kategori[6]){
				biodata.analogi++;
			}			
		}
		system("pause");
	}
}

void init_jurusan(){
	ifstream file("Jurusan.txt");
	while(file.good()){
		getline(file, jur[tot].jrs, ',');
		getline(file, jur[tot].bid[0], ',');
		getline(file, jur[tot].bid[1], '.');
		getline(file, jur[tot].kategori, '-');
		getline(file, jur[tot].kel, '\n');
		
		tot++;
	}
	
}

void tampilkan(){
	system("cls");
	cout<<"==========\nHASIL TES\n==========\n";
	cout<<"Tes telah selesai. Berikut Nilai Tes yang telah anda lakukan:\n";
	cout<<"\n====================\n\nNilai Rata-Rata Rapor:\n";
	if(mtk!=0){
		cout<<"MTK	  :"<<mtk<<endl;
		cout<<"Biologi:"<<biologi<<endl;
		cout<<"Fisika :"<<fisika<<endl;
		cout<<"Kimia  :"<<kimia<<endl;
	}
	else
	{
		cout<<"Sosiologi:"<<sosio<<endl;
		cout<<"Ekonomi  :"<<eko<<endl;
		cout<<"Geografi :"<<geo<<endl;
		cout<<"Sejarah  :"<<sejarah<<endl;
	}
	cout<<"B. Indonesia :"<<bindo<<endl;
	cout<<"B. Inggris   :"<<bing<<endl;
	
	cout<<"\n====================\n\nNilai Psikotes:\n";
	cout<<"Verbal:"<<biodata.sino_anto+biodata.analogi/3<<endl;
	cout<<"Analisa/Logika:"<<biodata.logis_analis/2<<endl;
	cout<<"Aritmatika:"<<biodata.aritmatik/2<<endl;
	
	hitung_akhir();
	
	cout<<"\n====================\n\nMinat & Bakat:\n";
	for(int i=0;i<8;i++){
		cout<<kategori2[i]<<":"<<biodata.mb_poin[i]<<endl;
	}
	cout<<endl;
	system("pause");
}

int main(){
	system("title Program Rekomendasi Jurusan");
	
	soal();
	init_jurusan();
	
	while(quest!='y' && quest!='Y'){
		Biodata();
	}
	quest='n';
	while(quest!='y' && quest!='Y'){
		Nilai_rapor();	
	}
	biodata.rata=rata_rapor();
	
	psikotes();
	
	minat_bakat();
	
	tampilkan();
	
	rekomendasi();
	
	return 0;
}


void soal(){	
	//Soal Sinonim
	text[0].soal="ABSOLUT  == ";text[0].kategori=kategori[0];
	text[0].jawaban[0]="Positif";text[0].jawaban[1]="Abnormal";text[0].jawaban[2]="Keras";text[0].jawaban[3]="Mutlak";text[0].jBenar=text[0].jawaban[3];
	
	text[1].soal="ADAPTASI == ";text[1].kategori=kategori[0];
	text[1].jawaban[0]="Kesepakatan";text[1].jawaban[1]="Keadaan";text[1].jawaban[2]="Penggabungan";text[1].jawaban[3]="Penyesuaian";text[1].jBenar=text[1].jawaban[3];
	
	text[2].soal="ANGGARAN == ";text[2].kategori=kategori[0];
	text[2].jawaban[0]="Keuangan";text[2].jawaban[1]="Laporan";text[2].jawaban[2]="Aturan";text[2].jawaban[3]="Pembelian";text[2].jBenar=text[2].jawaban[2];
	
	text[3].soal="TRANSKRIP == ";text[3].kategori=kategori[0];
	text[3].jawaban[0]="Penilaian";text[3].jawaban[1]="Akademik";text[3].jawaban[2]="Salinan";text[3].jawaban[3]="Ijazah";text[3].jBenar=text[3].jawaban[2];
	
	text[4].soal="AKSELERASI == ";text[4].kategori=kategori[0];
	text[4].jawaban[0]="Percepatan";text[4].jawaban[1]="Kecepatan";text[4].jawaban[2]="Keindahan";text[4].jawaban[3]="Perpaduan";text[4].jBenar=text[4].jawaban[0];
	
	text[5].soal="DEFISIT == ";text[5].kategori=kategori[0];
	text[5].jawaban[0]="Kelebihan";text[5].jawaban[1]="Perimbangan";text[5].jawaban[2]="Kekurangan";text[5].jawaban[3]="Pertemuan";text[5].jBenar=text[5].jawaban[2];
	
	text[6].soal="DONOR == ";text[6].kategori=kategori[0];
	text[6].jawaban[0]="Penderma";text[6].jawaban[1]="Penerima";text[6].jawaban[2]="Darah";text[6].jawaban[3]="Pemberian";text[6].jBenar=text[6].jawaban[0];
	
	text[7].soal="EFISIEN == ";text[7].kategori=kategori[0];
	text[7].jawaban[0]="Berhemat";text[7].jawaban[1]="Menyederhanakan";text[7].jawaban[2]="Tepat guna";text[7].jawaban[3]="Pemborosan";text[7].jBenar=text[7].jawaban[2];
	
	text[8].soal="KONSTRUKTIF == ";text[8].kategori=kategori[0];
	text[8].jawaban[0]="Menyatukan";text[8].jawaban[1]="Memperbaiki";text[8].jawaban[2]="Memisahkan";text[8].jawaban[3]="Hancur";text[8].jBenar=text[8].jawaban[1];
	
	text[9].soal="IDENTIK == ";text[9].kategori=kategori[0];
	text[9].jawaban[0]="Sejenis";text[9].jawaban[1]="Meniru";text[9].jawaban[2]="Palsu";text[9].jawaban[3]="Sama";text[9].jBenar=text[9].jawaban[3];
	
	text[10].soal="KOLEKTIF == ";text[10].kategori=kategori[0];
	text[10].jawaban[0]="Pendaftaran";text[10].jawaban[1]="Titipan";text[10].jawaban[2]="Individual";text[10].jawaban[3]="Bersama";text[10].jBenar=text[10].jawaban[3];
	
	text[11].soal="KONSOLDASI == ";text[11].kategori=kategori[0];
	text[11].jawaban[0]="Pemurnian";text[11].jawaban[1]="Penggabungan";text[11].jawaban[2]="Pemisahan";text[11].jawaban[3]="Kepartaian";text[11].jBenar=text[11].jawaban[1];
	
	text[12].soal="KONSPIRASI == ";text[12].kategori=kategori[0];
	text[12].jawaban[0]="Persekongkolan";text[12].jawaban[1]="Persaingan";text[12].jawaban[2]="Politik";text[12].jawaban[3]="Perdamaian";text[12].jBenar=text[12].jawaban[0];
		
	text[13].soal="KONSIDERASI == ";text[13].kategori=kategori[0];
	text[13].jawaban[0]="Peraturan";text[13].jawaban[1]="Pertimbangan";text[13].jawaban[2]="Perhubungan";text[13].jawaban[3]="Permusuhan";text[13].jBenar=text[13].jawaban[1];
		
	text[14].soal="KONSERVATIF == ";text[14].kategori=kategori[0];
	text[14].jawaban[0]="Moderat";text[14].jawaban[1]="Ekstrem";text[14].jawaban[2]="Kolot";text[14].jawaban[3]="Sosialis";text[14].jBenar=text[14].jawaban[2];
		
	text[15].soal="KONTAMINASI == ";text[15].kategori=kategori[0];
	text[15].jawaban[0]="Perbaikan";text[15].jawaban[1]="Lingkungan";text[15].jawaban[2]="Terpisah";text[15].jawaban[3]="Tercemar";text[15].jBenar=text[15].jawaban[3];
		
	text[16].soal="KONTRIBUSI == ";text[16].kategori=kategori[0];
	text[16].jawaban[0]="Dukungan";text[16].jawaban[1]="Sumbangan";text[16].jawaban[2]="Masukan";text[16].jawaban[3]="Partisi";text[16].jBenar=text[16].jawaban[1];
		
	text[17].soal="KREASI == ";text[17].kategori=kategori[0];
	text[17].jawaban[0]="Rencana";text[17].jawaban[1]="Pemikiran";text[17].jawaban[2]="Ciptaan";text[17].jawaban[3]="Bersama";text[17].jBenar=text[17].jawaban[2];
		
	text[18].soal="KONSTRUKTIF == ";text[18].kategori=kategori[0];
	text[18].jawaban[0]="Memperbaiki";text[18].jawaban[1]="Menyatukan";text[18].jawaban[2]="Memisahkan";text[18].jawaban[3]="Hancur";text[18].jBenar=text[18].jawaban[0];
		
	text[19].soal="KREDIBILITAS == ";text[19].kategori=kategori[0];
	text[19].jawaban[0]="Ternama";text[19].jawaban[1]="Dapat dipercaya";text[19].jawaban[2]="Mandiri";text[19].jawaban[3]="Kualifikasi";text[19].jBenar=text[19].jawaban[1];
	
	//Soal Antonim
	text[20].soal="TUNAI >< ";text[20].kategori=kategori[3];
	text[20].jawaban[0]="Bayar";text[20].jawaban[1]="Lunas";text[20].jawaban[2]="Hutang";text[20].jawaban[3]="Kontan";text[20].jBenar=text[20].jawaban[1];
	
	text[21].soal="TESIS >< ";text[21].kategori=kategori[3];
	text[21].jawaban[0]="Hipotesis";text[21].jawaban[1]="Sistensis";text[21].jawaban[2]="Antitesis";text[21].jawaban[3]="Skripsi";text[21].jBenar=text[21].jawaban[2];
	
	text[22].soal="NEKAT >< ";text[22].kategori=kategori[3];
	text[22].jawaban[0]="Takut";text[22].jawaban[1]="Berani";text[22].jawaban[2]="Sabar";text[22].jawaban[3]="Jagoan";text[22].jBenar=text[22].jawaban[0];
	
	text[23].soal="PASCA >< ";text[23].kategori=kategori[3];
	text[23].jawaban[0]="Pra";text[23].jawaban[1]="Setelah";text[23].jawaban[2]="Melewati";text[23].jawaban[3]="Akhir";text[23].jBenar=text[23].jawaban[0];
	
	text[24].soal="ASLI >< ";text[24].kategori=kategori[3];
	text[24].jawaban[0]="Tiruan";text[24].jawaban[1]="Orisinil";text[24].jawaban[2]="Autentik";text[24].jawaban[3]="Murni";text[24].jBenar=text[24].jawaban[0];
	
	text[25].soal="KONSTAN >< ";text[25].kategori=kategori[3];
	text[25].jawaban[0]="Stabil";text[25].jawaban[1]="Berbeda-beda";text[25].jawaban[2]="Bertentangan";text[25].jawaban[3]="Berubah-ubah";text[25].jBenar=text[25].jawaban[3];
	
	text[26].soal="NISBI >< ";text[26].kategori=kategori[3];
	text[26].jawaban[0]="Mutlak";text[26].jawaban[1]="Maya";text[26].jawaban[2]="Stabil";text[26].jawaban[3]="Abstrak";text[26].jBenar=text[26].jawaban[0];
	
	text[27].soal="KUALITAS >< ";text[27].kategori=kategori[3];
	text[27].jawaban[0]="Jumlah";text[27].jawaban[1]="Kapasitas";text[27].jawaban[2]="Kuantitas";text[27].jawaban[3]="Abstrak";text[27].jBenar=text[27].jawaban[2];
	
	text[28].soal="PROGRESIF >< ";text[28].kategori=kategori[3];
	text[28].jawaban[0]="Stabil";text[28].jawaban[1]="Stagnan";text[28].jawaban[2]="Aktif";text[28].jawaban[3]="Pasif";text[28].jBenar=text[28].jawaban[1];
	
	text[29].soal="PELUANG >< ";text[29].kategori=kategori[3];
	text[29].jawaban[0]="Kesempatan";text[29].jawaban[1]="Ancaman";text[29].jawaban[2]="Kemungkinan";text[29].jawaban[3]="Lowongan";text[29].jBenar=text[29].jawaban[1];
	
	text[30].soal="PLURAL >< ";text[30].kategori=kategori[3];
	text[30].jawaban[0]="Banyak";text[30].jawaban[1]="Sedikit";text[30].jawaban[2]="Ganda";text[30].jawaban[3]="Tunggal";text[30].jBenar=text[30].jawaban[3];
	
	text[31].soal="MITRA >< ";text[31].kategori=kategori[3];
	text[31].jawaban[0]="Saingan";text[31].jawaban[1]="Sekutu";text[31].jawaban[2]="Teman";text[31].jawaban[3]="Kongsi";text[31].jBenar=text[31].jawaban[0];
	
	text[32].soal="HIRAU >< ";text[32].kategori=kategori[3];
	text[32].jawaban[0]="Lupa";text[32].jawaban[1]="Ingat";text[32].jawaban[2]="Lalai";text[32].jawaban[3]="Acuh";text[32].jBenar=text[32].jawaban[3];

	text[33].soal="KASAR >< ";text[33].kategori=kategori[3];
	text[33].jawaban[0]="Gradasi";text[33].jawaban[1]="Kasap";text[33].jawaban[2]="Lembut";text[33].jawaban[3]="Halus";text[33].jBenar=text[33].jawaban[3];

	text[34].soal="ULTIMA >< ";text[34].kategori=kategori[3];
	text[34].jawaban[0]="Akhir";text[34].jawaban[1]="Awal";text[34].jawaban[2]="Tengah";text[34].jawaban[3]="Biasa";text[34].jBenar=text[34].jawaban[1];
	
	text[35].soal="GUGUR >< ";text[35].kategori=kategori[3];
	text[35].jawaban[0]="Tumbuh";text[35].jawaban[1]="Rontok";text[35].jawaban[2]="Salju";text[35].jawaban[3]="Tunas";text[35].jBenar=text[35].jawaban[0];
	
	text[36].soal="TIMPANG >< ";text[36].kategori=kategori[3];
	text[36].jawaban[0]="Seimbang";text[36].jawaban[1]="Pincang";text[36].jawaban[2]="Sama";text[36].jawaban[3]="Benar";text[36].jBenar=text[36].jawaban[0];
	
	text[37].soal="GENTAR >< ";text[37].kategori=kategori[3];
	text[37].jawaban[0]="Berani";text[37].jawaban[1]="Takut";text[37].jawaban[2]="Ragu";text[37].jawaban[3]="Tantang";text[37].jBenar=text[37].jawaban[1];
	
	text[38].soal="KAPABEL >< ";text[38].kategori=kategori[3];
	text[38].jawaban[0]="Pandai";text[38].jawaban[1]="Piawai";text[38].jawaban[2]="Bodoh";text[38].jawaban[3]="Mampu";text[38].jBenar=text[38].jawaban[3];
	
	text[39].soal="NAAS >< ";text[39].kategori=kategori[3];
	text[39].jawaban[0]="Rugi";text[39].jawaban[1]="Untung";text[39].jawaban[2]="Sial";text[39].jawaban[3]="Baik";text[39].jBenar=text[39].jawaban[1];

	//soal kategori deret angka	
	text[40].soal=" 1,3,5,7,... ";text[40].kategori=kategori[5];
	text[40].jawaban[0]="8";text[40].jawaban[1]="9";text[40].jawaban[2]="10";text[40].jawaban[3]="11";text[40].jBenar=text[40].jawaban[1];
	
	text[41].soal=" A,C,E,G,...  ";text[41].kategori=kategori[5];
	text[41].jawaban[0]="I";text[41].jawaban[1]="J";text[41].jawaban[2]="K";text[41].jawaban[3]="L";text[41].jBenar=text[41].jawaban[0];	
	
	text[42].soal=" 3,5,8,12,...  ";text[42].kategori=kategori[5];
	text[42].jawaban[0]="15";text[42].jawaban[1]="16";text[42].jawaban[2]="17";text[42].jawaban[3]="18";text[42].jBenar=text[42].jawaban[2];
	
	text[43].soal=" A,D,H,M,...  ";text[43].kategori=kategori[5];
	text[43].jawaban[0]="S";text[43].jawaban[1]="T";text[43].jawaban[2]="O";text[43].jawaban[3]="U";text[43].jBenar=text[43].jawaban[0];
	
	text[44].soal=" B,G,K,N,...  ";text[44].kategori=kategori[5];
	text[44].jawaban[0]="S";text[44].jawaban[1]="R";text[44].jawaban[2]="Q";text[44].jawaban[3]="P";text[44].jBenar=text[44].jawaban[3];
	
	text[45].soal=" 4,9,16,25,36,...  ";text[45].kategori=kategori[5];
	text[45].jawaban[0]="64";text[45].jawaban[1]="81";text[45].jawaban[2]="49";text[45].jawaban[3]="100";text[45].jBenar=text[45].jawaban[2];
	
	text[46].soal=" 1,2,4,8,16,32,...  ";text[46].kategori=kategori[5];
	text[46].jawaban[0]="36";text[46].jawaban[1]="46";text[46].jawaban[2]="48";text[46].jawaban[3]="64";text[46].jBenar=text[46].jawaban[3];
	
	text[47].soal=" 18,20,24,32,48,...  ";text[47].kategori=kategori[5];
	text[47].jawaban[0]="80";text[47].jawaban[1]="81";text[47].jawaban[2]="79";text[47].jawaban[3]="78";text[47].jBenar=text[47].jawaban[0];
	
	text[48].soal=" 15,15,14,12,9,5,...  ";text[48].kategori=kategori[5];
	text[48].jawaban[0]="0";text[48].jawaban[1]="1";text[48].jawaban[2]="2";text[48].jawaban[3]="3";text[48].jBenar=text[48].jawaban[0];
	
	text[49].soal=" 8,9,12,17,24,... ";text[49].kategori=kategori[5];
	text[49].jawaban[0]="30";text[49].jawaban[1]="31";text[49].jawaban[2]="32";text[49].jawaban[3]="33";text[49].jBenar=text[49].jawaban[3];
	
	text[50].soal=" 12,23,9,20,6,17,...  ";text[50].kategori=kategori[5];
	text[50].jawaban[0]="3,14";text[50].jawaban[1]="3,15";text[50].jawaban[2]="4,14";text[50].jawaban[3]="4,15";text[50].jBenar=text[50].jawaban[0];
	
	text[51].soal=" 60,62,50,52,40,42,... ";text[51].kategori=kategori[5];
	text[51].jawaban[0]="31,32";text[51].jawaban[1]="21,22";text[51].jawaban[2]="30,32";text[51].jawaban[3]="20,22";text[51].jBenar=text[51].jawaban[2];
	
	text[52].soal=" 16,35,14,30,12,25,...  ";text[52].kategori=kategori[6];
	text[52].jawaban[0]="8,15";text[52].jawaban[1]="8,20";text[52].jawaban[2]="10,15";text[52].jawaban[3]="10,20";text[52].jBenar=text[52].jawaban[3];
	
	text[53].soal=" 100,12,70,24,40,36,...  ";text[53].kategori=kategori[5];
	text[53].jawaban[0]="10,48";text[53].jawaban[1]="10,46";text[53].jawaban[2]="20,46";text[53].jawaban[3]="10,48";text[53].jBenar=text[53].jawaban[3];
	
	text[54].soal=" 5,7,10,12,15,17,20,...  ";text[54].kategori=kategori[5];
	text[54].jawaban[0]="24,25";text[54].jawaban[1]="22,25";text[54].jawaban[2]="22,26";text[54].jawaban[3]="23,26";text[54].jBenar=text[54].jawaban[1];
	
	text[55].soal=" 1,2,9,3,4,9,5,6,9,...  ";text[55].kategori=kategori[5];
	text[55].jawaban[0]="8,9";text[55].jawaban[1]="7,8";text[55].jawaban[2]="7,10";text[55].jawaban[3]="8,10";text[55].jBenar=text[55].jawaban[1];
	
	text[56].soal=" 6,8,10,14,18,26,34,50,...  ";text[56].kategori=kategori[5];
	text[56].jawaban[0]="66,82";text[56].jawaban[1]="66,98";text[56].jawaban[2]="74,102";text[56].jawaban[3]="74,88";text[56].jBenar=text[56].jawaban[1];
	
	text[57].soal=" 2,2,4,3,3,5,4,4,6,... ";text[57].kategori=kategori[5];
	text[57].jawaban[0]="4,4,7";text[57].jawaban[1]="5,5,7";text[57].jawaban[2]="4,4,8";text[57].jawaban[3]="5,5,8";text[57].jBenar=text[57].jawaban[1];

	text[58].soal=" 3,8,13,18,23,... ";text[57].kategori=kategori[5];
	text[58].jawaban[0]="28,34";text[58].jawaban[1]="28,38";text[58].jawaban[2]="33,38";text[58].jawaban[3]="28,33";text[58].jBenar=text[58].jawaban[3];	
		
	text[59].soal=" 8,4,8,6,4,6,4,4,4,... ";text[59].kategori=kategori[5];
	text[59].jawaban[0]="3,4,3";text[59].jawaban[1]="2,4,2";text[59].jawaban[2]="4,2,4";text[59].jawaban[3]="1,4,1";text[59].jBenar=text[59].jawaban[1];
	
	//soal kategori analogi
	text[60].soal=" Mobil - Bensin = Pelari - .... ";text[60].kategori=kategori[6];
	text[60].jawaban[0]="makanan";text[60].jawaban[1]="sepatu";text[60].jawaban[2]="kaos";text[60].jawaban[3]="lintasan";text[60].jBenar=text[60].jawaban[0];
	
	text[61].soal=" Dingin - Selimut = Hujan - .... ";text[61].kategori=kategori[6];
	text[61].jawaban[0]="air";text[61].jawaban[1]="payung";text[61].jawaban[2]="dingin";text[61].jawaban[3]="basah";text[61].jBenar=text[61].jawaban[1];
	
	text[62].soal=" Semir - Sepatu = Sikat - .... ";text[62].kategori=kategori[6];
	text[62].jawaban[0]="kuku";text[62].jawaban[1]="rambut";text[62].jawaban[2]="telivisi";text[62].jawaban[3]="gigi";text[62].jBenar=text[62].jawaban[3];
	
	text[63].soal=" Kayu - Pohon = Emas - .... ";text[63].kategori=kategori[6];
	text[63].jawaban[0]="tambang";text[63].jawaban[1]="perhiasan";text[63].jawaban[2]="mahar";text[63].jawaban[3]="logam";text[63].jBenar=text[63].jawaban[0];
	
	text[64].soal=" Kumis - Kucing = Belalai - .... ";text[64].kategori=kategori[6];
	text[64].jawaban[0]="ular";text[64].jawaban[1]="harimau";text[64].jawaban[2]="gajah";text[64].jawaban[3]="hidung";text[64].jBenar=text[64].jawaban[2];
	
	text[65].soal=" Reguler - Senin = Karyawan - ....  ";text[65].kategori=kategori[6];
	text[65].jawaban[0]="selasa";text[65].jawaban[1]="rabu";text[65].jawaban[2]="minggu";text[65].jawaban[3]="jumat";text[65].jBenar=text[65].jawaban[2];
	
	text[66].soal=" Busur - Panah = Senapan - .... ";text[66].kategori=kategori[6];
	text[66].jawaban[0]="peluru";text[66].jawaban[1]="senjata";text[66].jawaban[2]="berbahaya";text[66].jawaban[3]="tembakan";text[66].jBenar=text[66].jawaban[0];
	
	text[67].soal=" Ayah - Anak = Pohon - .... ";text[67].kategori=kategori[6];
	text[67].jawaban[0]="daun";text[67].jawaban[1]="tunas";text[67].jawaban[2]="ranting";text[67].jawaban[3]="akar";text[67].jBenar=text[67].jawaban[1];
	
	text[68].soal=" Terbang - Burung = Jalan - .... ";text[68].kategori=kategori[6];
	text[68].jawaban[0]="jauh";text[68].jawaban[1]="singa";text[68].jawaban[2]="lebah";text[68].jawaban[3]="kupu-kupu";text[68].jBenar=text[68].jawaban[1];
	
	text[69].soal=" Mobil - Roda = Rumah - .... ";text[69].kategori=kategori[6];
	text[69].jawaban[0]="pondasi";text[69].jawaban[1]="tanah";text[69].jawaban[2]="jendela";text[69].jawaban[3]="atap";text[69].jBenar=text[69].jawaban[0];
	
	text[70].soal=" Bulan - Bumi = Yupiter - ... ";text[70].kategori=kategori[6];
	text[70].jawaban[0]="venus";text[70].jawaban[1]="orbit";text[70].jawaban[2]="matahari";text[70].jawaban[3]="bulan";text[70].jBenar=text[70].jawaban[2];
	
	text[71].soal=" Bulan - Bumi = Yupiter - ... ";text[71].kategori=kategori[6];
	text[71].jawaban[0]="venus";text[71].jawaban[1]="orbit";text[71].jawaban[2]="matahari";text[71].jawaban[3]="bulan";text[71].jBenar=text[71].jawaban[2];
	
	text[72].soal=" Februari - April = Mei - .... ";text[72].kategori=kategori[6];
	text[72].jawaban[0]="juli";text[72].jawaban[1]="agustus";text[72].jawaban[2]="september";text[72].jawaban[3]="oktober";text[72].jBenar=text[72].jawaban[0];
	
	text[73].soal=" Ekspor - Pergi = Impor - ....  ";text[73].kategori=kategori[6];
	text[73].jawaban[0]="luar";text[73].jawaban[1]="dagang";text[73].jawaban[2]="masuk";text[73].jawaban[3]="asing";text[73].jBenar=text[73].jawaban[2];
	
	text[74].soal=" Mobil - Bensin = Perahu - .... ";text[74].kategori=kategori[6];
	text[74].jawaban[0]="laut";text[74].jawaban[1]="angin";text[74].jawaban[2]="ombak";text[74].jawaban[3]="kayu";text[74].jBenar=text[74].jawaban[1];
	
	text[75].soal=" Jam - Menit = Menit - ... ";text[75].kategori=kategori[6];
	text[75].jawaban[0]="waktu";text[75].jawaban[1]="jam";text[75].jawaban[2]="detik";text[75].jawaban[3]="hari";text[75].jBenar=text[75].jawaban[2];
	
	text[76].soal=" Obat - Apotik = Pakaian - ....  ";text[76].kategori=kategori[6];
	text[76].jawaban[0]="butik";text[76].jawaban[1]="binatu";text[76].jawaban[2]="baju";text[76].jawaban[3]="celana";text[76].jBenar=text[76].jawaban[0];
	
	text[77].soal=" Sendok - Makan = Silet - ....  ";text[77].kategori=kategori[6];
	text[77].jawaban[0]="tajam";text[77].jawaban[1]="potong";text[77].jawaban[2]="bahaya";text[77].jawaban[3]="hitam";text[77].jBenar=text[77].jawaban[1];
	
	text[78].soal=" Data - Disket = Uang - .... ";text[78].kategori=kategori[6];
	text[78].jawaban[0]="Bayar";text[78].jawaban[1]="Dompet";text[78].jawaban[2]="Orang";text[78].jawaban[3]="Mahal";text[78].jBenar=text[78].jawaban[1];
	
	text[79].soal=" Siang - Matahari = Malam - .... ";text[79].kategori=kategori[6];
	text[79].jawaban[0]="bintang";text[79].jawaban[1]="gelap";text[79].jawaban[2]="bulan";text[79].jawaban[3]="awan";text[79].jBenar=text[79].jawaban[2];

	//soal logika
	text[80].soal="Kebanyakan burung dapat terbang. Burung unta adalah juga seekor burung. Jadi :\n ";
	text[80].kategori=kategori[1];
	text[80].jawaban[0]="Burung unta dapat terbang";
	text[80].jawaban[1]="Burung unta memang tidak dapat terbang ";
	text[80].jawaban[2]="Burung unta belum tentu dapat terbang";
	text[80].jawaban[3]="Jawaban a,b, dan c ketiga-tiganya salah";
	text[80].jBenar=text[80].jawaban[2];

	text[81].soal="Semua Mahasiswa ISTN lulus tepat pada waktunya. Sebagian Mahasiswa ISTN adalah Mahasiswa Program Perkuliahan Karyawan (P2K). Jadi : \n ";
	text[81].kategori=kategori[1];
	text[81].jawaban[0]="Semua Mahasiswa Program Perkuliahan Karyawan (P2K) ISTN lulus tepat pada waktunya";
	text[81].jawaban[1]="Sebagian Mahasiswa ISTN lulus tidak tepat pada waktunya";
	text[81].jawaban[2]="Mahasiswa ISTN yang lulus tepat pada waktunya pasti Mahasiswa Program Perkuliahan Karyawan (P2K).";
	text[81].jawaban[3]="Sebagian Mahasiswa ISTN adalah Mahasiswa Program Perkuliahan Karyawan (P2K)";
	text[81].jBenar=text[81].jawaban[0];
	
	text[82].soal="Semua donor harus berbadan sehat. Sebagian donor darah memiliki golongan darah O. Jadi:\n ";
	text[82].kategori=kategori[1];
	text[82].jawaban[0]="Sebagian orang yang bergolongan darah O dan menjadi donor darah berbadan sehat";
	text[82].jawaban[1]="Semua donor harus memiliki golongan darah O dan berbadan sehat.";
	text[82].jawaban[2]="Semua donor darah yang memiliki golongan darah O harus berbadan sehat.";
	text[82].jawaban[3]="Yang berbadan sehat adalah yang memiliki golongan darah O dan menjadi donor darah";
	text[82].jBenar=text[82].jawaban[2];
	
	text[83].soal="Jika A = B maka A tidak sama dengan C. Bila P = A, maka....\n ";
	text[83].kategori=kategori[1];
	text[83].jawaban[0]="Bila P = C maka P= B";
	text[83].jawaban[1]="Bila P = C maka P tidak sama dengan A";
	text[83].jawaban[2]="Bila P = C maka tidak P tidak sama dengan B";
	text[83].jawaban[3]="Bila P = C maka P = A = B";
	text[83].jBenar=text[83].jawaban[2];
	
	text[84].soal="Bila kendaraan lewat jalan tol harus membayar, Sebagian kendaraan tak punya uang, jadi;\n ";
	text[84].kategori=kategori[1];
	text[84].jawaban[0]="Semua kendaraan tidak lewat jalan tol";
	text[84].jawaban[1]="Semua kendaraan lewat jalan tol";
	text[84].jawaban[2]="Sebagian kendaraan tak punya uang";
	text[84].jawaban[3]="Sebagian kendaraan tidak lewat jalan tol.";
	text[84].jBenar=text[84].jawaban[3];
	
	text[85].soal="Bila S lewat P harus tambah H. Sebagian S tak punya H. Jadi :\n ";
	text[85].kategori=kategori[1];
	text[85].jawaban[0]="Semua S tidak lewat P";
	text[85].jawaban[1]="Sebagian S tidak lewat P";
	text[85].jawaban[2]="Sebagian S tak punya H";
	text[85].jawaban[3]="Semua S tidak lewat P dan tak lewat H";
	text[85].jBenar=text[85].jawaban[1];
	
	text[86].soal="Beberapa benda yang memuai adalah logam. Semua logam adalah benda padat. Jadi :\n ";
	text[86].kategori=kategori[1];
	text[86].jawaban[0]="Hanya logam yang memuai merupakan benda padat.";
	text[86].jawaban[1]="Benda yang bukan logam tidak memuai.";
	text[86].jawaban[2]="Beberapa benda padat dapat memuai.";
	text[86].jawaban[3]="Benda padat dapat memuai";
	text[86].jBenar=text[85].jawaban[2];
	
	text[87].soal="Semua U bukan B. Sebagian U adalah C. Jadi : \n ";
	text[87].kategori=kategori[1];
	text[87].jawaban[0]="Sebagian U adalah C bukan B.";
	text[87].jawaban[1]="Semua U bukan B dan C.";
	text[87].jawaban[2]="Sebagian U bukan C adalah B.";
	text[87].jawaban[3]="Semua U adalah C";
	text[87].jBenar=text[87].jawaban[0];
	
	text[88].soal="Semua mahasiswa yang berdasi. Sebagian mahasiswa berjas. Jadi: \n ";
	text[88].kategori=kategori[1];
	text[88].jawaban[0]="Sebagian mahasiswa bersepatu.";
	text[88].jawaban[1]="Sebagian mahasiswa berjas dan bersepatu";
	text[88].jawaban[2]="Sebagian mahasiswa berdasi dan berjas";
	text[88].jawaban[3]="Sebagian mahasiswa bersepatu tapi tak berjas";
	text[88].jBenar=text[88].jawaban[2];
	
	text[89].soal="Semua Y adalah P. Sebagian Y adalah R. Jadi: \n ";
	text[89].kategori=kategori[1];
	text[89].jawaban[0]="Semua Y yang bukan P adalah R";
	text[89].jawaban[1]="Semua Y yang bukan R adalah P";
	text[89].jawaban[2]="Semua R yang bukan Y adalah P";
	text[89].jawaban[3]="Sebagian Y yang bukan R adalah P";
	text[89].jBenar=text[89].jawaban[1];
	
	text[90].soal="Semua kertas gambar sangat berguna. Sebagian kertas yang sangat berguna harganya murah. Jadi : \n ";
	text[90].kategori=kategori[1];
	text[90].jawaban[0]="Semua kertas gambar harganya murah";
	text[90].jawaban[1]="Semua kertas yang harganya murah adalah kertas gambar";
	text[90].jawaban[2]="Sebagian kertas harganya murah";
	text[90].jawaban[3]="Kertas yang murah sangat berguna";
	text[90].jBenar=text[90].jawaban[2];
	
	text[91].soal="Dalam sebuah kelas, sebagian besar murid pandai berenang, sebagian besar juga pandai mendayung. Jadi :\n ";
	text[91].kategori=kategori[1];
	text[91].jawaban[0]="Sebagian besar murid tidak pandai berenang dan tidak pandai mendayung";
	text[91].jawaban[1]="Sebagian besar murid pandai berenang saja";
	text[91].jawaban[2]="Sebagian tertentu dari murid-murid itu pandai berenang dan pandai mendayung";
	text[91].jawaban[3]="Jawaban a, b, dan c ketiga-tiganya salah";
	text[91].jBenar=text[91].jawaban[2];
	
	text[92].soal="Pengurus koperasi seharusnya berjiwa sosial. Sebagian ketua rukun tetangga pernah menjadi pengurus koperasi. Jadi:\n ";
	text[92].kategori=kategori[1];
	text[92].jawaban[0]="Ketua rukun tetangga itu selalu berjiwa sosial";
	text[92].jawaban[1]="Semua orang yang pernah menjadi ketua rukun tetangga itu pengurus koperasi";
	text[92].jawaban[2]="Sebagian ketua rukun tetangga seluruhnya berjiwa sosial";
	text[92].jawaban[3]="Semua pengurus koperasi berjiwa sosial";
	text[92].jBenar=text[92].jawaban[2];
	
	text[93].soal="Tidak ada dua gaun rancangan desainer X yang memiliki model yang sama. Gaun A dan B adalah rancangan desainer X. Jadi : \n ";
	text[93].kategori=kategori[1];
	text[93].jawaban[0]="Sebagian gaun rancangan desainer X.";
	text[93].jawaban[1]="Semua desainer merancang gaun dengan mode seperti gaun A dan B.";
	text[93].jawaban[2]="Gaun A dan B tidak memiliki mode yang sama.";
	text[93].jawaban[3]="Gaun yang modenya tidak sama berasal dari desainer X saja.";
	text[93].jBenar=text[93].jawaban[2];
	
	text[94].soal="Semua murid yang mengikuti ujian tidak menggunakan kalkulator. Sebagian murid yang ujian mengenakan jam tangan. Jadi :\n ";
	text[94].kategori=kategori[1];
	text[94].jawaban[0]="Semua murid yang ujian mengenakan jam tangan";
	text[94].jawaban[1]="Sementara murid yang ujian tidak mengenakan jam tangan.";
	text[94].jawaban[2]="Semua murid yang ujian tidak menggunakan kalkulator dan tidak mengenakan jam tangan.";
	text[94].jawaban[3]="Sebagian murid yang ujian mengenakan jam tangan dan tidak menggunakan kalkulator.";
	text[94].jBenar=text[94].jawaban[3];
	
	text[95].soal="Akhmad adalah pekerja. Akhmad menjadi buruh di sebuah pabrik. Banyak di antara buruh-buruhnya yang malas bekerja. Badrun adalah teman Akhmad. Jadi:";
	text[95].kategori=kategori[1];
	text[95].jawaban[0]="Akhmad itu malas.";
	text[95].jawaban[1]="Badrun itu malas.";
	text[95].jawaban[2]="Badrun mungkin teman sekerja Akhmad.";
	text[95].jawaban[3]="Teman-teman Badrun semuanya rajin.";
	text[95].jBenar=text[95].jawaban[2];
	
	text[96].soal="Semua dosen adalah pegawai negeri. Sebagian dosen adalah seniman. Yang tidak cocok dengan pernyataan tersebut adalah....";
	text[96].kategori=kategori[1];
	text[96].jawaban[0]="Sebagian seniman adalah pegawai negeri";
	text[96].jawaban[1]="Sebagian pegawai negeri adalah dosen";
	text[96].jawaban[2]="Sebagian seniman adalah dosen";
	text[96].jawaban[3]="Semua seniman adalah pegawai negeri";
	text[96].jBenar=text[96].jawaban[3];
	
	text[97].soal="Sebagian P adalah B. B bukan T. Sebagian P bukan M adalah T. Semua B, M, dan T adalah P. Jadi : ";
	text[97].kategori=kategori[1];
	text[97].jawaban[0]="Semua T adalah T bukan M";
	text[97].jawaban[1]="Semua P adalah B bukan T";
	text[97].jawaban[2]="Semua P bukan B bukan M";
	text[97].jawaban[3]="Sebagian P bukan T, bukan M, bukan B";
	text[97].jBenar=text[97].jawaban[3];
	
	text[98].soal="Semua ban terbuat dari karet. Semua karet bersifat elastis. Jadi : Sebagian karet berwarna hitam.";
	text[98].kategori=kategori[1];
	text[98].jawaban[0]="Semua ban elastis dan terbuat dari karet.";
	text[98].jawaban[1]="Semua ban berwarna hitam.";
	text[98].jawaban[2]="Semua ban elastis berwarna hitam.";
	text[98].jawaban[3]="Sebagian ban berwarna hitam terbuat dari karet.";
	text[98].jBenar=text[98].jawaban[0];
	
	text[99].soal="Semua ikan hidup di air. Beberapa ikan hidup di air tawar. Jadi : ";
	text[99].kategori=kategori[1];
	text[99].jawaban[0]="Semua ikan dapat hidup di air tawar dan air laut.";
	text[99].jawaban[1]="Beberapa ikan yang hidup di air tawar tidak dapat hidup di air laut.";
	text[99].jawaban[2]="Sebagian ikan tidak hidup di air tawar.";
	text[99].jawaban[3]="Tidak ada ikan yang hidup di air laut.";
	text[99].jBenar=text[99].jawaban[2];
	
	//SOAL ANALITIK MASIH KURANG 10 SOAL LAGI
	text[100].soal="A adalah seorang anak dari pasangan suami isteri B dengan C. E adalah anak dari pasangan D dengan B. Hubungan antara A dengan E disebut:";
	text[100].kategori=kategori[2];
	text[100].jawaban[0]="Saudara sepupu";
	text[100].jawaban[1]="Saudara misan";
	text[100].jawaban[2]="Saudara ipar";
	text[100].jawaban[3]="a, b, c, salah";
	text[100].jBenar=text[100].jawaban[0];
	
	text[101].soal="Dari kata-kata yang dicetak miring di bawah ini, manakah yang tidak bermakna abstrak?";
	text[101].kategori=kategori[2];
	text[101].jawaban[0]="Malaiha merasa terbelenggu akibat keputusan yang tidak jelas itu";
	text[101].jawaban[1]="Orang yang tidak berusaha sesungguhnya telah kalah sebelum berjuang";
	text[101].jawaban[2]="Ketajaman analisis intelijen Detasemen 88 Antiteror sungguh mengagumkan.";
	text[101].jawaban[3]="Kecantikan Dian Gitaya sangat mempesona forum.";
	text[101].jBenar=text[101].jawaban[3];
	
	text[102].soal="Albert dan Irene mendengarkan musik. Gloria dan Albert hobi membaca. Siapa yang sedang membaca sambil mendengarkan musik?";
	text[102].kategori=kategori[2];
	text[102].jawaban[0]="Gloria";
	text[102].jawaban[1]="Albert";
	text[102].jawaban[2]="Irene";
	text[102].jawaban[3]="Gloria dan Albert";
	text[102].jBenar=text[102].jawaban[1];
	
	text[103].soal="Hanya orang kaya bisa membeli mobil. Agustina adalah orang yang membeli mobil. Orang ini tidak kaya. Jadi:";
	text[103].kategori=kategori[2];
	text[103].jawaban[0]="Orang ini adalah Agustina ";
	text[103].jawaban[1]="Orang ini bukan Agustina";
	text[103].jawaban[2]="Agustina tidak kaya";
	text[103].jawaban[3]=" a, b,c bukan jawaban yang benar";
	text[103].jBenar=text[103].jawaban[1];
	
	text[104].soal="Gus Dur adalah putra kandung K.H. Wahid Hasyim. Kalimat manakah yang tidak berhubungan langsung dengan kalimat di atas?";
	text[104].kategori=kategori[2];
	text[104].jawaban[0]="Gus Dur adalah pernah menjadi Presiden Republik Indonesia.";
	text[104].jawaban[1]="Pada diri Gus Dur mengalir darah K.H Wahid Hasyim.";
	text[104].jawaban[2]="K.H. Wahid Hasyim adalah ayah Gus Dur.";
	text[104].jawaban[3]="Gus Dur adalah keturunan K.H. Wahid Hasyim. ";
	text[104].jBenar=text[104].jawaban[0];
	
	text[105].soal="Helen menyukai David. Siapa yang menyukai David dan menyukai Tom. Helen menyukai hanya laki-laki tampan. Jadi ";
	text[105].kategori=kategori[2];
	text[105].jawaban[0]="Tom adalah bukan laki-laki tampan";
	text[105].jawaban[1]="Tom adalah laki-laki tampan";
	text[105].jawaban[2]="Tom dan David menyukai Helen";
	text[105].jawaban[3]="Helen tidak menyukai David";
	text[105].jBenar=text[105].jawaban[0];
	
	text[106].soal="Produk Bontang lebih mahal daripada produk Medan. Produk Makasar lebih murah daripada produk Bontang. Jadi ... ";
	text[106].kategori=kategori[2];
	text[106].jawaban[0]="Produk Makasar lebih mahal daripada produk Medan.";
	text[106].jawaban[1]="Produk Medan lebih murah daripada produk Makasar.";
	text[106].jawaban[2]="Produk Medan dan produk Makasar sama mahalnya.";
	text[106].jawaban[3]="Produk Medan dan Produk Makasar lebih murah daripada produk Bontang. ";
	text[106].jBenar=text[106].jawaban[3];
	
	text[107].soal="Pada tes masuk perguruan tinggi, nilai jawaban benar adalah 3, jawaban salah adalah -1, dan tidak dijawab adalah 0 (nol). \nRirin menjawab dengan benar 65 soal dan tidak menjawab 8 soal dari 100 soal. Total skor Ririn?";
	text[107].kategori=kategori[2];
	text[107].jawaban[0]="130";
	text[107].jawaban[1]="168";
	text[107].jawaban[2]="125";
	text[107].jawaban[3]="155";
	text[107].jBenar=text[107].jawaban[1];
	
	text[108].soal="X lebih tua dari N, E lebih muda dari A, T lebih muda dari N;X lebih muda dari E, N lebih tua dari T maka yang termuda adalah ... ";
	text[108].kategori=kategori[2];
	text[108].jawaban[0]="N";
	text[108].jawaban[1]="E";
	text[108].jawaban[2]="X";
	text[108].jawaban[3]="T";
	text[108].jBenar=text[108].jawaban[3];
	
	text[109].soal="Steven, Richard, dan Anton menyukai bola basket. Joni dan Richard memakai arloji. \nSiapakah yang jatuh arlojinya ketika bermain basket?";
	text[109].kategori=kategori[2];
	text[109].jawaban[0]="Steven";
	text[109].jawaban[1]="Richard";
	text[109].jawaban[2]="Anton";
	text[109].jawaban[3]="Joni";
	text[109].jBenar=text[107].jawaban[1];
	
	text[110].soal="Berapa umur nenek 10 tahun ke depan, apabila 3 tahun yang lalu umurnya 60 tahun?";
	text[110].kategori=kategori[2];
	text[110].jawaban[0]="73";
	text[110].jawaban[1]="72";
	text[110].jawaban[2]="70";
	text[110].jawaban[3]="67";
	text[110].jBenar=text[110].jawaban[0];
	
	text[111].soal="Sebuah bejana berbentuk silinder berisi air 1/3 ya. \nJika kemudian ditambah air sebanyak 3 liter lagi, bejana ini akan berisi kira-kira ½ nya. \nBerapa literkah kapasitas bejana itu?";
	text[111].kategori=kategori[2];
	text[111].jawaban[0]="18 L";
	text[111].jawaban[1]="15 L";
	text[111].jawaban[2]="24 L";
	text[111].jawaban[3]="27 L";
	text[111].jBenar=text[111].jawaban[0];
	
	text[112].soal="Hasil kali 2 bilangan cacah adalah 2.254, salah satu bilangan itu adalah 49, dan bilangan yang lain adalah";
	text[112].kategori=kategori[2];
	text[112].jawaban[0]="46";
	text[112].jawaban[1]="49";
	text[112].jawaban[2]="47";
	text[112].jawaban[3]="45";
	text[112].jBenar=text[112].jawaban[0];
	
	text[113].soal="Angka 8 pada bilangan 789.654 mempunyai nilai ...?";
	text[113].kategori=kategori[2];
	text[113].jawaban[0]="menempati puluh ribuan";
	text[113].jawaban[1]="menempati puluhan ";
	text[113].jawaban[2]="menempati ratus ribuan";
	text[113].jawaban[3]="menempati ratusan";
	text[113].jBenar=text[113].jawaban[0];
	
	text[114].soal="Himpunan Q = { x I 5 = x = 14, x ? bilangan genap } dapat dinyatakan dengan mendaftar anggota – anggotanya menjadi …?";
	text[114].kategori=kategori[2];
	text[114].jawaban[0]=" { 5,6,7,8,9,10,11,12,13 }";
	text[114].jawaban[1]="{ 6,8,10,12 }";
	text[114].jawaban[2]="{ 6,8,10,12,14 }";
	text[114].jawaban[3]=" { 4,6,8,10,12 }";
	text[114].jBenar=text[114].jawaban[1];
	
	text[115].soal="Untuk mengerjakan 1 unit rumah dibutuhkan waktu 36 hari dengan 12 tenaga kerja. Berapa waktu akan dihabiskan bila menggunakan 24 orang tenaga kerja?";
	text[115].kategori=kategori[2];
	text[115].jawaban[0]="14 Hari";
	text[115].jawaban[1]="15 Hari";
	text[115].jawaban[2]="17 Hari";
	text[115].jawaban[3]="18 Hari";
	text[115].jBenar=text[115].jawaban[3];
	
	text[116].soal="Sebuah pesawat terbang berangkat dari kota Kupang menuju kota Jakarta pukul 7 pagi dan perjalanan ke Jakarta selama 4 jam. Transit di Denpasar selama 30 menit. Pada pukul berapa pesawat tersebut tiba di Jakarta?";
	text[116].kategori=kategori[2];
	text[116].jawaban[0]="11.30 ";
	text[116].jawaban[1]="11.15";
	text[116].jawaban[2]="11.00";
	text[116].jawaban[3]="11.45";
	text[116].jBenar=text[116].jawaban[0];
	
	text[117].soal="Angga mempunyai uang Rp. 4.500.000 dan ia berniat membeli sebuah handycam seharga Rp. 2.500.000 sebelum diskon. Harga diskon handycam tersebut adalah 20%. Selain itu, Angga juga membelanjakan uangnya untuk keperluan lain sebesar Rp. 1.500.000. Berapa sisa uang Angga saat ini?";
	text[117].kategori=kategori[2];
	text[117].jawaban[0]="1.300.000";
	text[117].jawaban[1]="Rp. 1.000.000";
	text[117].jawaban[2]="1.400.000";
	text[117].jawaban[3]=" 1.500.000";
	text[117].jBenar=text[117].jawaban[1];
	
	text[118].soal="Putri membeli boneka seharga Rp. 50.000. Kemudian, boneka dijual lagi dengan harga Rp. 80.000. Berapa persen keuntungan Putri?";
	text[118].kategori=kategori[2];
	text[118].jawaban[0]="30 %";
	text[118].jawaban[1]="70 %";
	text[118].jawaban[2]="40 %";
	text[118].jawaban[3]="60 %";
	text[118].jBenar=text[118].jawaban[3];
	
	text[119].soal="Defan menabung di Bank Rp. 150.000. Bunga 1 tahunnya adalah 12,5 %. Maka jumlah tabungan Defan setelah 1 tahun adalah...?";
	text[119].kategori=kategori[2];
	text[119].jawaban[0]="Rp. 158.750";
	text[119].jawaban[1]="Rp. 168.750";
	text[119].jawaban[2]="Rp. 178.750";
	text[119].jawaban[3]=" Rp. 198.750";
	text[119].jBenar=text[119].jawaban[1];
	//SOAL Aritmatika lanjutin untuk pilihan jawaban kita buat sendiri aja
	text[120].soal="Steven, Richard, dan Anton menyukai bola basket. Joni dan Richard memakai arloji. Siapakah yang jatuh arlojinya ketika bermain basket?";
	text[120].kategori=kategori[1];
	text[120].jawaban[0]="11";
	text[120].jawaban[1]="12";
	text[120].jawaban[2]="13";
	text[120].jawaban[3]="14";
	text[120].jBenar=text[120].jawaban[3];
	
	text[121].soal=" 1 - 1 x 1 - 1 = ...";
	text[121].kategori=kategori[1];
	text[121].jawaban[0]="1";
	text[121].jawaban[1]="-1";
	text[121].jawaban[2]="0";
	text[121].jawaban[3]="-4";
	text[121].jBenar=text[121].jawaban[1];
	
	text[122].soal=" 4 x 5 : 1 - 3 = ...";
	text[122].kategori=kategori[1];
	text[122].jawaban[0]="10";
	text[122].jawaban[1]="17";
	text[122].jawaban[2]="-10";
	text[122].jawaban[3]="-17";
	text[122].jBenar=text[122].jawaban[1];
	
	text[123].soal="12 adalah 150% dari";
	text[123].kategori=kategori[1];
	text[123].jawaban[0]="4";
	text[123].jawaban[1]="8";
	text[123].jawaban[2]="16";
	text[123].jawaban[3]="20";
	text[123].jBenar=text[123].jawaban[1];
	
	text[124].soal="Jika x + y = 100 dan x/y = 1/4, maka nilai y-x";
	text[124].kategori=kategori[1];
	text[124].jawaban[0]="30";
	text[124].jawaban[1]="50";
	text[124].jawaban[2]="60";
	text[124].jawaban[3]="40";
	text[124].jBenar=text[124].jawaban[2];
	
	text[125].soal="Nilai yang paling dekat dengan  v61(akar) adalah";
	text[125].kategori=kategori[1];
	text[125].jawaban[0]="2,5";
	text[125].jawaban[1]="7,3";
	text[125].jawaban[2]="7,8";
	text[125].jawaban[3]="9,2";
	text[125].jBenar=text[125].jawaban[2];
	
	text[126].soal="1 + 2 + 3 + 4 + 5 + ..........+ 29 =";
	text[126].kategori=kategori[1];
	text[126].jawaban[0]="435";
	text[126].jawaban[1]="280";
	text[126].jawaban[2]="465";
	text[126].jawaban[3]="300";
	text[126].jBenar=text[126].jawaban[0];
	
	text[127].soal="Dari data 6,8, 5, 10, 6, 9, 3, 11, 9, 6 maka";
	text[127].kategori=kategori[1];
	text[127].jawaban[0]="Median = 6, rata-rata = 5¼";
	text[127].jawaban[1]="Rata-rata = 8, modus = 7";
	text[127].jawaban[2]="Modus = 6, median = 6 ";
	text[127].jawaban[3]="Modus = 7, jangkauan = 8";
	text[127].jBenar=text[127].jawaban[2];
	
	text[128].soal="(15 + 40)^2 = ";
	text[128].kategori=kategori[2];
	text[128].jawaban[0]="3052";
	text[128].jawaban[1]="3025";
	text[128].jawaban[2]="3005";
	text[128].jawaban[3]="3225";
	text[128].jBenar=text[128].jawaban[1];
	
	text[129].soal="9 adalah berapa persennya dari 380? ";
	text[129].kategori=kategori[2];
	text[129].jawaban[0]="0,5%";
	text[129].jawaban[1]="0,05%";
	text[129].jawaban[2]="0,15%";
	text[129].jawaban[3]="5%";
	text[129].jBenar=text[129].jawaban[3];
	
	text[130].soal="32/9 x 0,75 =  ";
	text[130].kategori=kategori[2];
	text[130].jawaban[0]="6/16";
	text[130].jawaban[1]="3";
	text[130].jawaban[2]="3,5";
	text[130].jawaban[3]="16/6";
	text[130].jBenar=text[130].jawaban[3];
	
	text[131].soal="(0,31)^2 =  ";
	text[131].kategori=kategori[2];
	text[131].jawaban[0]=" 0,0991";
	text[131].jawaban[1]="0,0661";
	text[131].jawaban[2]="0,0961";
	text[131].jawaban[3]="0,0971";
	text[131].jBenar=text[131].jawaban[2];
	
	text[132].soal="Jika a = 6, b = 5, c = (2a – b)/ (ab). Berapakah abc ?  ";
	text[132].kategori=kategori[2];
	text[132].jawaban[0]="7 ";
	text[132].jawaban[1]="15";
	text[132].jawaban[2]="6";
	text[132].jawaban[3]="5";
	text[132].jBenar=text[132].jawaban[0];
	
	text[133].soal="2^18/2^6 = ";
	text[133].kategori=kategori[2];
	text[133].jawaban[0]="2^3";
	text[133].jawaban[1]="2^12";
	text[133].jawaban[2]="2^-3";
	text[133].jawaban[3]="2^24";
	text[133].jBenar=text[133].jawaban[1];
	
	text[134].soal="3/8 dari 40% adalah ?";
	text[134].kategori=kategori[2];
	text[134].jawaban[0]="16 %";
	text[134].jawaban[1]="0,11";
	text[134].jawaban[2]="0,15";
	text[134].jawaban[3]="15,5%";
	text[134].jBenar=text[134].jawaban[2];
	
	text[135].soal="(3 x 9/4) – (1/3)^2 =";
	text[135].kategori=kategori[2];
	text[135].jawaban[0]="6 23/36";
	text[135].jawaban[1]="6 20/26";
	text[135].jawaban[2]="7 9/36";
	text[135].jawaban[3]="6 39/36";
	text[135].jBenar=text[135].jawaban[0];
	
	text[136].soal="2,00486 x 0,5 =";
	text[136].kategori=kategori[2];
	text[136].jawaban[0]="1,000243";
	text[136].jawaban[1]="1,0243";
	text[136].jawaban[2]="1,00243";
	text[136].jawaban[3]="1,00253";
	text[136].jBenar=text[136].jawaban[2];
	
	text[137].soal="216 x 0,875 =";
	text[137].kategori=kategori[2];
	text[137].jawaban[0]="189";
	text[137].jawaban[1]="209";
	text[137].jawaban[2]="198";
	text[137].jawaban[3]="188";
	text[137].jBenar=text[137].jawaban[0];
	
	text[138].soal="Berapakah nilai dari 27,5% dari 200?";
	text[138].kategori=kategori[2];
	text[138].jawaban[0]="90";
	text[138].jawaban[1]="550";
	text[138].jawaban[2]="198";
	text[138].jawaban[3]="54,5";
	text[138].jBenar=text[138].jawaban[3];
	
	text[139].soal="Hasil dari 7,95 : 3 adalah =";
	text[139].kategori=kategori[2];
	text[139].jawaban[0]="2,56";
	text[139].jawaban[1]="2,65";
	text[139].jawaban[2]="1,65";
	text[139].jawaban[3]="2,66";
	text[139].jBenar=text[139].jawaban[1];
}

void minat_bakat(){
	int jwb;
	ifstream file("mbs.txt");
	int x=0;
	while(file.good()){
		getline(file, question[x].soal,'.');
		getline(file, question[x].kategori, '\n');
		x++;
	}
	
	file.close();
	system("cls");
	cout<<"TAHAP MINAT & BAKAT\n=========="<<endl;
	cout<<"-Berisi Pertanyaan menyangkut minat dan bakat anda!"<<endl;
	cout<<"-Pilih 'Ya' jika anda merasa benar terhadap pertanyaan tersebut"<<endl;
	cout<<"-Pilih 'Tidak' jika anda merasa sebaliknya"<<endl;
	system("pause");
	for(int i=0;i<80;i++){
		system("cls");
		cout<<i+1<<"."<<question[i].soal<<endl<<endl;
		for(int j=0;j<2;j++){
			cout<<j+1<<") "<<ans[j]<<endl;
		}
		cout<<"Pilih Jawaban:";cin>>jwb;
		if(jwb==1){
			biodata.mb_poin[i/10]++;
		}
		system("pause");
	}
	system("pause");
}

struct tmp{
	int b;//isi
	int a;//asal
}poin[8];

void rekomendasi(){
	
	string kel;
	string jrsn[50];
	int mx=0;

	
	for(int i=0;i<8;i++){
	poin[i].b=biodata.mb_poin[i];
	poin[i].a=i;
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<7;j++){
			if(poin[j].b>poin[j+1].b){
				swap(poin[j],poin[j+1]);
			}
		}
	}
	

	if(mtk==0)kel="IPS";else kel="IPA";
	system("cls");
	cout<<"===============\nREKOMENDASI\n===============\n";
	cout<<"Berikut Jurusan yang direkomendasikan:\n";
	for(int i=0;i<tot;i++){
		if((jur[i].bid[0]==kate[poin[7].a] || jur[i].bid[1]==kate[poin[6].a] || jur[i].bid[0]==kate[poin[6].a] || jur[i].bid[1]==kate[poin[7].a]) && (jur[i].kel==biodata.jurusan || jur[i].kel=="IPC")){
			cout<<"-"<<jur[i].jrs<<endl;
			jrsn[mx]=jur[i].jrs;
			mx++;
		}
		else
		if(mx==0 && i==tot-1){
			jrsn[mx]="Belum ada jurusan di yang direkomendasikan didatabase!";
			cout<<jrsn[mx]<<endl;
			mx++;
		}
	}
	
	system("pause");
	saving(jrsn, mx);
}

void saving(string jrsn[50], int mx){
	ofstream ff;
	ff.open("doc.txt", ios::app);
	ff<<biodata.nama<<","<<biodata.JK<<","<<biodata.no_hp<<","<<biodata.tmpt_lahir<<","<<biodata.tgl_lahir<<".";
	for(int i=0;i<8;i++){
		ff<<biodata.mb_poin[i];
		if(i<7)
		ff<<"_";
		else
		ff<<";";
	}
	
	for(int i=0;i<mx;i++){
		ff<<"-"<<jrsn[i];
		if(i==mx-1)ff<<"\n";
		else
		ff<".\n";
	}
	ff<<endl<<".";
	ff.close();
	system("cls");
	cout<<"Data tersimpan!"<<endl;
	system("pause");
	system("menu.exe");
}
