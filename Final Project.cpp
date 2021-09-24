#include <bits/stdc++.h>  
using namespace std;

#define max 1000	

struct data{
	string nama, nip;
} Data[max];

int jumlahData=max, jumlahFile=0;
ofstream fout; //write file
ifstream fin; //reads file

void menu(){
	cout << "======================" << endl;
	cout << "1. View Data" << endl;
	cout << "2. Insert Data" << endl;
	cout << "3. Hapus Data" << endl;
	cout << "4. Ubah Data" << endl;
	cout << "5. Exit" << endl;
	cout << "======================" << endl;
}

/*fungsi untuk buka file dan simpan di struct*/
void readFile(){
	fin.open("nip.txt");
	jumlahFile = 0;
	for (int i=0; i<jumlahData; i++){
		getline(fin, Data[i].nama);
		getline(fin, Data[i].nip);
		jumlahFile++;
		if (fin.eof()) break;
	}
    jumlahData = jumlahFile;
    fin.close();
}

/* fungsi untuk view data*/
void sortNama(){
	for(int i=0; i<jumlahData-1; i++){
		for(int j=i+1; j<jumlahData; j++){
			if(Data[i].nama > Data[j].nama){
				swap(Data[i].nama, Data[j].nama);
				swap(Data[i].nip, Data[j].nip);
			}
		}
	}
	for(int i=0; i<jumlahData; i++){
		cout << Data[i].nama << "\t\t"; 
		cout << Data[i].nip << endl;
	}
}
void sortnip(){
	for(int i=0; i<jumlahData-1; i++){
		for(int j=i+1; j<jumlahData; j++){
			if(Data[i].nip > Data[j].nip){
				swap(Data[i].nama, Data[j].nama);
				swap(Data[i].nip, Data[j].nip);
			}
		}
	}
	for(int i=0; i<jumlahData; i++){
		cout << Data[i].nama << "\t\t"; 
		cout << Data[i].nip << endl;
	}
}
void viewData(){
	if(jumlahData < 1){
		cout << "Data kosong!";
	}
	else{
		bool view = true;
		do{
			cout << "===========================" << endl;
			cout << "1. Urutkan Berdasarkan Nama" << endl;
			cout << "2. Urutkan Berdasarkan nip" << endl;
			cout << "3. Kembali ke Menu" << endl; 
			cout << "===========================" << endl;
			int choice;
			cin >> choice;
			switch(choice){
				case 1 :
					sortNama();
					break;
				case 2 :
					sortnip(); 
					break;
				case 3 :
					view = false;
				default:
					break;
			}
		}while(view);
	}
}

/*fungsi untuk insert Data*/
void writeStruct(string name, string N){		
	Data[jumlahData].nama = name;
	Data[jumlahData].nip = N;
}
void writeFile(){
	fout.open("nip.txt", ofstream::out | ofstream::app);
	fout << endl;
	fout << Data[jumlahData].nama << endl;
	fout << Data[jumlahData].nip;
	fout.close();
}
void inputData(){
	string temp_nama, temp_nip;
	cout << "Nama : "; 
	getline(cin >> ws, temp_nama);
	cout << "nip : "; 
	getline(cin >> ws, temp_nip);
	
	int count = 0;
	for(int i=0; i<jumlahData; i++){
		if(temp_nip == Data[i].nip){
			cout << "Data nip sudah ada" << endl;
			count++;
			break;
		}
	}
	if (count==0){
		writeStruct(temp_nama, temp_nip);
		writeFile();
		jumlahData++;
		cout << "Data berhasil tersimpan" << endl;	
	}
}

/*fungsi untuk delete file*/
void deleteFile(string search){
	fout.open("nip.txt");
	int deleted = 0;
	for (int i=0; i<jumlahData; i++){
		if (Data[i].nama == search || deleted == 1){
			Data[i].nama = Data[i+1].nama;
			Data[i].nip = Data[i+1].nip;
			deleted = 1;

			fout << Data[i].nama << endl;
			fout << Data[i].nip << endl;
		}
		else{
			fout << Data[i].nama << endl;
			fout << Data[i].nip << endl;
		}
	}
	fout.close();
}
void deleteData(){
	string search;
	int ada = 0;
	cout << "===================" << endl;
	cout << "Nama yang dihapus : "; 
	getline(cin >> ws, search);
	cout << "===================" << endl;
	int deleted = 0;
	for (int i=0; i<jumlahData; i++){
		if (Data[i].nama == search || deleted == 1){
			if (Data[i].nama == search || deleted == 1){
				ada++;
			}
		}
	}
	if(ada==0){
		cout << "Data tidak ditemukan" << endl;
	}
	else{
		jumlahData--;
		deleteFile(search);
	}
}

/*fungsi untuk edit file*/
void ubahFile(string tmp_nama, string ubah_nama, string ubah_nip){
	fout.open("nip.txt");
	for (int i=0; i<jumlahData; i++){
		if (Data[i].nama == tmp_nama){
			Data[i].nama = ubah_nama;
			Data[i].nip = ubah_nip;
			
			fout << Data[i].nama << endl;
			fout << Data[i].nip << endl;
		}
		else{
			fout << Data[i].nama << endl;
			fout << Data[i].nip << endl;
		}
	}
	fout.close();
}
void ubahData(){
	string tmp_nama, ubah_nama, ubah_nip;
	cout << "========================" << endl;
	cout << "    Data yang diubah    " << endl;
	cout << "Nama : ";
	getline(cin >> ws, tmp_nama);
	cout << "===================" << endl;
	cout << "     Data Baru     " << endl; 
	cout << "Nama : ";
	getline(cin >> ws, ubah_nama);
	cout << "nip : ";
	getline(cin >> ws, ubah_nip);
	cout << "===================" << endl;

	int ubah = 0;
	for (int i=0; i<jumlahData; i++){
		if (Data[i].nama == tmp_nama){
			ubah++;
		}
	}
	if (ubah == 0){
		cout << "Data tidak ditemukan" << endl;
	}
	else{
		ubahFile(tmp_nama, ubah_nama, ubah_nip);
	}
}

/*driver code*/
int main(){
	while(1){
		menu(); 
		int choice;
		cin >> choice;
		 
		switch(choice){
			case 1 :
				readFile();
				viewData(); 
			    break;
			case 2 :
				readFile();
				inputData(); 
			    break;
			case 3 :
				readFile();
				deleteData();
				break;
			case 4 :
				readFile();
				ubahData();
				break;
			case 5 :
				exit(0);
			default:
			    break;
		}
	}
}