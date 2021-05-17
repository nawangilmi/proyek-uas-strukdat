/* 
Kelompok 3 :

 Aulia Rahmanita 140810200004
 Nawang Ilmi Adzani 140810200014
 Pujo Prayogo 1408102000038
*/

#include <iostream>
#include <stdlib.h>

struct masuk{
    int uangmasuk;
    masuk* nextMasuk;
};

struct keluar{
    int uangkeluar;
    keluar* nextKeluar;
};

struct tanggal{
    char tgl[15];
    masuk* firstMasuk;
    keluar* firstKeluar;
    tanggal* nextTgl; 
};


typedef masuk* pMasuk;
typedef keluar* pKeluar;
typedef tanggal* pTanggal;
typedef pTanggal listTanggal;

void createListTgl(listTanggal& First){
    First = nullptr;
}

void createElementTgl(pTanggal& pBaru){
    pBaru = new tanggal;
    std::cout<<"Masukkan Tanggal (DD/MM/YY) : " ; std::cin>>pBaru->tgl;
    pBaru->nextTgl = nullptr;
    pBaru-> firstMasuk = nullptr;
    pBaru-> firstKeluar = nullptr;
}

void InputPemasukkan(pMasuk& pBaru){
    pBaru = new masuk;
    std::cout<<"Masukkan Uang yang masuk: " ; std::cin>>pBaru->uangmasuk;
    pBaru->nextMasuk = nullptr;
}

void insertFirstPeg(listTanggal& First,pTanggal pBaru){
if (First== nullptr) {
		First=pBaru; 
        } else { 
		pBaru-> nextTgl=First;
		First=pBaru;
	}
}

void InputPengeluaran(pKeluar pBaru){
pBaru = new keluar;
    std::cout<<"Masukkan Uang yang masuk: " ; std::cin>>pBaru->uangkeluar;
    pBaru->nextKeluar = nullptr;
}

void linearSearch(listTanggal First, std::string& key, pTanggal& pCari){
    pCari = First;
    int ketemu;
    ketemu = 0;

    while (pCari != nullptr && ketemu == 0){
        if (pCari->tgl == key){
            ketemu = 1;
        } else{
            pCari = pCari->nextTgl;
        }
    }
    if (ketemu == 1){
        std::cout << "";
    } else {
        std::cout << "";
    }
}

void insertFirstMasuk(listTanggal& First, std::string key,pMasuk pBaru){
    // I.S List First mungkin kosong dan pBaru sudah terdefinisi
    // F.S Elemen anak bertambah satu elemen di depan
    pTanggal pOrtu, pCari;
    int ketemu,id;

    std::cout << "masukan Tanggal : ";
    std::cin >> key; 
    linearSearch(First, key, pCari);
    pOrtu = First;
    ketemu = 0;
    while (pOrtu != nullptr && ketemu==0) { //!ketemu
        if (pOrtu->tgl==key){
            ketemu=1;
        }
        else{
            pOrtu=pOrtu->nextTgl;
        }
    }
    
    if (ketemu){ // (ketemu==1)
        if (pOrtu-> firstMasuk == nullptr){
            pOrtu-> firstMasuk = pBaru;
        }
        else {
            pBaru->nextMasuk = pOrtu->firstMasuk;
            pOrtu->firstMasuk = pBaru;
        }
    }
}

void insertFirstKeluar(listTanggal& First, std::string key,pKeluar pBaru){
    // I.S List First mungkin kosong dan pBaru sudah terdefinisi
    // F.S Elemen anak bertambah satu elemen di depan
    pTanggal pOrtu, pCari;
    int ketemu,id;

    std::cout << "Masukan Tanggal : ";
    std::cin >> key; 
    linearSearch(First, key, pCari);
    pOrtu = First;
    ketemu = 0;
    while (pOrtu != nullptr && ketemu==0) { //!ketemu
        if (pOrtu->tgl==key){
            ketemu=1;
        }
        else{
            pOrtu=pOrtu->nextTgl;
        }
    }
    
    if (ketemu){ // (ketemu==1)
        if (pOrtu-> firstKeluar == nullptr){
            pOrtu-> firstKeluar = pBaru;
        }
        else {
            pBaru->nextKeluar = pOrtu->firstKeluar;
            pOrtu->firstKeluar = pBaru;
        }
    }
}


void TampilkanPemasukan(listTanggal& First){
    pTanggal pBantuTgl;
    pMasuk pBantuMsk;
    std::cout<<"\nSeluruh Transaksi Uang Masuk"<<std::endl<<std::endl;
	std::cout<<"----------------------------------"<<std::endl;
    pBantuTgl=First;
    while (pBantuTgl != nullptr){ //loop ortu
        std::cout<< pBantuTgl->tgl <<std::endl;
        pBantuMsk=pBantuTgl->firstMasuk;
        while (pBantuMsk!= nullptr) { //loop anak
            std::cout<<" "<<pBantuMsk->uangmasuk<<std::endl;
            pBantuMsk=pBantuMsk->nextMasuk;
        }
        pBantuTgl=pBantuTgl->nextTgl;
    }
}

void TampilkanPengeluaran(listTanggal& First){
    pTanggal pBantuTgl;
    pKeluar pBantuKeluar;
    std::cout<<"\nSeluruh Transaksi Uang Keluar"<<std::endl<<std::endl;
	std::cout<<"----------------------------------"<<std::endl;
    pBantuTgl=First;
    while (pBantuTgl != nullptr){ //loop ortu
        std::cout<< pBantuTgl->tgl <<std::endl;
        pBantuKeluar=pBantuTgl->firstKeluar;
        while (pBantuKeluar!= nullptr) { //loop anak
            std::cout<<" "<<pBantuKeluar->uangkeluar<<std::endl;
            pBantuKeluar=pBantuKeluar->nextKeluar;
        }
        pBantuTgl=pBantuTgl->nextTgl;
    }
}

void Total (){

}
void RatarataPemasukan(){}

void RatarataPengeluaran(){}

void MaxMasuk(){}

void MaxKeluar(){}


void DataKeuangan(){
    int pilih;
    std::cout << "=== Data Keuangan ===" << "\n";
    std::cout << "1. Rata-rata Pemasukkan\n";
    std::cout << "2. Rata-rata Pengeluaran\n";
    std::cout << "3. Pemasukkan Terbesar\n";
    std::cout << "4. Pengeluaran Terbesar\n";
    std::cout << "5. Back \n"; // ini harus ada atau ga tapi gimana 
    std::cout << "Masukkan Pilihan :";
    std::cin >> pilih;

    switch(pilih){
        case 1 :
            RatarataPemasukan();
            break;
        case 2 :
            RatarataPengeluaran();
            break;
        case 3 :
            MaxMasuk();
            break;
        case 4 :
            MaxKeluar();
            break;
        case 5:
            break;
        case 6:
            break;
        
    }

}

int main(){
    int total = 0;
    int pilih;
    char pilih1;
    listTanggal head;
    pMasuk masuk;
    pTanggal tgl;
    pKeluar keluar;
    std::string data;

    createListTgl(head);
    do{
    system("cls");
    std::cout << "==================================\n";
    std::cout << "           BUDGETIN AJA           \n";
    std::cout << "==================================\n";
    std::cout << "1. Tanggal Hari ini               \n";
    std::cout << "2. Isi Pemasukkan                 \n";
    std::cout << "3. Isi Pengeluaran                \n";
    std::cout << "4. Tampilkan Pemasukan            \n";
    std::cout << "5. Tampilkan Pengeluaran          \n";
    std::cout << "6. Total Uang                     \n";
    std::cout << "7. Data - data Keuangan           \n";
    std::cout << "Masukkan Pilihan :";
    std::cin >> pilih;

    switch (pilih)
    {
    case 1:
        createElementTgl(tgl);
        insertFirstPeg(head,tgl);
        break;
    case 3:
        InputPengeluaran(keluar);
        insertFirstKeluar(head,data,keluar);
        break;
    case 2:
        InputPemasukkan(masuk);
        insertFirstMasuk(head,data,masuk);
        break;
    case 4:
        TampilkanPemasukan(head);
        break;
    case 5:
        TampilkanPengeluaran(head);
        break;
    case 6:
        ;
        break;
     case 7:
        DataKeuangan();
        break;
    default : 
        std::cout << "Pilihan tidak tersedia!";
        break;  
    }
    std::cout <<"Kembali ke menu awal (y/n)?";
    std::cin >> pilih1;
		system("pause");
    } while (pilih1=='Y' || pilih1=='y');
    return 0;
}