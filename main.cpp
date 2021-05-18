
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

void insertFirstTgl(listTanggal& First,pTanggal pBaru){
if (First== nullptr) {
		First=pBaru; 
        } else { 
		pBaru-> nextTgl=First;
		First=pBaru;
	}
}

void InputPemasukkan(pMasuk& pBaru){
    pBaru = new masuk;
    std::cout<<"Masukkan Uang yang masuk : " ; std::cin>>pBaru->uangmasuk;
    pBaru->nextMasuk = nullptr;
}


void InputPengeluaran(pKeluar& pBaru){
pBaru = new keluar;
    std::cout<<"Masukkan Uang yang keluar : " ; std::cin>>pBaru->uangkeluar;
    pBaru->nextKeluar = nullptr;
}

void linearSearch(listTanggal First, std::string& tanggal, pTanggal& pCari){
    pCari = First;
    int ketemu;
    ketemu = 0;

    while (pCari != nullptr && ketemu == 0){
        if (pCari->tgl == tanggal){
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

void insertFirstMasuk(listTanggal& First, std::string tanggal,pMasuk pBaru){
    // I.S List First mungkin kosong dan pBaru sudah terdefinisi
    // F.S Elemen anak bertambah satu elemen di depan
    pTanggal pMasuk, pCari;
    int ketemu,id;

    std::cout << "masukan Tanggal : ";
    std::cin >> tanggal; 
    linearSearch(First, tanggal, pCari);
    pMasuk = First;
    ketemu = 0;
    while (pMasuk != nullptr && ketemu==0) { //!ketemu
        if (pMasuk->tgl==tanggal){
            ketemu=1;
        }
        else{
            pMasuk=pMasuk->nextTgl;
        }
    }
    
    if (ketemu){ // (ketemu==1)
        if (pMasuk-> firstMasuk == nullptr){
            pMasuk-> firstMasuk = pBaru;
        }
        else {
            pBaru->nextMasuk = pMasuk->firstMasuk;
            pMasuk->firstMasuk = pBaru;
        }
    }
}

void insertFirstKeluar(listTanggal& First, std::string tanggal,pKeluar pBaru){
    // I.S List First mungkin kosong dan pBaru sudah terdefinisi
    // F.S Elemen anak bertambah satu elemen di depan
    pTanggal pKeluar, pCari;
    int ketemu,id;

    std::cout << "Masukan Tanggal : ";
    std::cin >> tanggal; 
    linearSearch(First, tanggal, pCari);
    pKeluar = First;
    ketemu = 0;
    while (pKeluar != nullptr && ketemu==0) { //!ketemu
        if (pKeluar->tgl==tanggal){
            ketemu=1;
        }
        else{
            pKeluar=pKeluar->nextTgl;
        }
    }
    
    if (ketemu){ // (ketemu==1)
        if (pKeluar-> firstKeluar == nullptr){
            pKeluar-> firstKeluar = pBaru;
        }
        else {
            pBaru->nextKeluar = pKeluar->firstKeluar;
            pKeluar->firstKeluar = pBaru;
        }
    }
}


void TampilkanPemasukan(listTanggal& First){
    pTanggal pBantuTgl;
    pMasuk pBantuMsk;
    std::cout<<"----------------------------------\n";
    std::cout<<"   Seluruh Transaksi Uang Masuk   \n";
	std::cout<<"----------------------------------\n";
    pBantuTgl=First;
    while (pBantuTgl != nullptr){ 
        std::cout<< pBantuTgl->tgl <<std::endl;
        pBantuMsk=pBantuTgl->firstMasuk;
        while (pBantuMsk!= nullptr) { 
            std::cout<<" "<<pBantuMsk->uangmasuk<<std::endl;
            pBantuMsk=pBantuMsk->nextMasuk;
        }
        pBantuTgl=pBantuTgl->nextTgl;
    }
}

void TampilkanPengeluaran(listTanggal& First){
    pTanggal pBantuTgl;
    pKeluar pBantuKeluar;
    std::cout<<"----------------------------------\n";
    std::cout<<"   Seluruh Transaksi Uang Keluar  \n";
	std::cout<<"----------------------------------\n";
    pBantuTgl=First;
    while (pBantuTgl != nullptr){ 
        std::cout<< pBantuTgl->tgl <<std::endl;
        pBantuKeluar=pBantuTgl->firstKeluar;
        while (pBantuKeluar!= nullptr) { 
            std::cout<<" "<<pBantuKeluar->uangkeluar<<std::endl;
            pBantuKeluar=pBantuKeluar->nextKeluar;
        }
        pBantuTgl=pBantuTgl->nextTgl;
    }
}


void RatarataPemasukan(listTanggal& First){
    int countmsk = 0;
    int summsk = 0;
    float meanmsk;
    pMasuk curr;
     pTanggal pBantuTgl;
    pMasuk pBantuMsk;
    std::cout<<"----------------------------------\n";
    std::cout<<"   rata rata Uang Masuk  \n";
	std::cout<<"----------------------------------\n";
    pBantuTgl=First;
    while (pBantuTgl != nullptr){ 
        std::cout<< pBantuTgl->tgl <<std::endl;
        pBantuMsk=pBantuTgl->firstMasuk;
        if (First == NULL){
        std::cout << -1;} 
    while (pBantuMsk != NULL){
        countmsk++; 
        summsk += pBantuMsk->uangmasuk; 
        pBantuMsk = pBantuMsk->nextMasuk;
        }
    } 
    meanmsk = (double)summsk / countmsk; //menghitung rata-rata
    std::cout << "Rata - Rata : "<< meanmsk; //mengoutputkan nilai ratarata
    pBantuTgl=pBantuTgl->nextTgl;
    
}

void RatarataPengeluaran(listTanggal& First){
    int countklr = 0;
    int sumklr = 0;
    float meanklr;
    pKeluar curr;
     pTanggal pBantuTgl;
    pKeluar pBantuKeluar;
    std::cout<<"----------------------------------\n";
    std::cout<<"      rata rata Uang Keluar       \n";
	std::cout<<"----------------------------------\n";
    pBantuTgl=First;
    while (pBantuTgl != nullptr){ 
        std::cout<< pBantuTgl->tgl <<std::endl;
        pBantuKeluar=pBantuTgl->firstKeluar;
        if (First == NULL){
        std::cout << -1;} 
    while (pBantuKeluar != NULL){
        countklr++; 
        sumklr += pBantuKeluar->uangkeluar; 
        pBantuKeluar = pBantuKeluar->nextKeluar;
        }   
    } 
    meanklr = (double)sumklr / countklr; //menghitung rata-rata
    std::cout << "Rata - Rata : "<< meanklr; //mengoutputkan nilai ratarata
    pBantuTgl=pBantuTgl->nextTgl;
    
}

void MaxMasuk(listTanggal& First){
    int maxmsk = 0;
    pMasuk pBaru ;
    pTanggal pBantuTgl;
    pMasuk pBantuMsk;
    std::cout<<"----------------------------------\n";
    std::cout<<"       Uang Masuk Terbesar        \n";
	std::cout<<"----------------------------------\n";
    pBantuTgl=First;
    while (pBantuTgl != nullptr){ 
        std::cout<< pBantuTgl->tgl <<std::endl;
        pBantuMsk=pBantuTgl->firstMasuk;
        while (pBaru != NULL) {
        if (pBaru->uangmasuk > maxmsk) 
            maxmsk = pBaru->uangmasuk; 
    }  pBaru = pBaru->nextMasuk;
    
        }
        std::cout << "Pemasukkan Terbesar : " << maxmsk; 
        pBantuTgl=pBantuTgl->nextTgl;
    }
        


void MaxKeluar(listTanggal& First){
    int maxklr = 0;
    pKeluar pBaru ;
    pTanggal pBantuTgl;
    pKeluar pBantuKeluar;
    std::cout<<"----------------------------------\n";
    std::cout<<"       Uang Keluar Terbesar       \n";
	std::cout<<"----------------------------------\n";
    pBantuTgl=First;
    while (pBantuTgl != nullptr){ //loop ortu
        std::cout<< pBantuTgl->tgl <<std::endl;
        pBantuKeluar=pBantuTgl->firstKeluar;
        while (pBaru != NULL) {
        if (pBaru->uangkeluar > maxklr) 
            maxklr = pBaru->uangkeluar; 
    }  pBaru = pBaru->nextKeluar;
    
        }
        std::cout << "Pengeluaran Terbesar : " << maxklr; 
        pBantuTgl=pBantuTgl->nextTgl;
}


void DataKeuangan(){
    int pilih;
    listTanggal head;
    system("cls");
    std::cout << "==================================\n";
    std::cout << "        Data-data Keuangan        \n";
    std::cout << "==================================\n";
    std::cout << "1. Rata-rata Pemasukkan\n";
    std::cout << "2. Rata-rata Pengeluaran\n";
    std::cout << "3. Pemasukkan Terbesar\n";
    std::cout << "4. Pengeluaran Terbesar\n";
    std::cout << "5. Back \n"; 
    std::cout << "Masukkan Pilihan : ";
    std::cin >> pilih;

    switch(pilih){
        case 1 :
            RatarataPemasukan(head);
            break;
        case 2 :
            RatarataPengeluaran(head);
            break;
        case 3 :
            MaxMasuk(head);
            break;
        case 4 :
            MaxKeluar(head);
            break;
        case 5:
            break;
        default : 
            std::cout << "Pilihan tidak tersedia!\n";
            break; 
        
    }

}

int main(){
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
    std::cout << "6. Data - data Keuangan           \n";
    std::cout << "Masukkan Pilihan : ";
    std::cin >> pilih;

    switch (pilih)
    {
    case 1:
        createElementTgl(tgl);
        insertFirstTgl(head,tgl);
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
        system("cls");
        TampilkanPemasukan(head);
        break;
    case 5:
        system("cls");
        TampilkanPengeluaran(head);
        break;
    case 6:
        system("cls");
        DataKeuangan();
        break;
    default : 
        std::cout << "Pilihan tidak tersedia!\n";
        break;  
    }
    std::cout <<"Kembali ke menu awal (y/n)?";
    std::cin >> pilih1;
		system("pause");
    } while (pilih1=='Y' || pilih1=='y');
    return 0;
}
