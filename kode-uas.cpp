/* 
Kelompok 3 :

 Aulia Rahmanita 140810200004
 Nawang Ilmi Adzani 140810200014
 Pujo Prayogo 1408102000038
*/

#include <iostream>

struct pemasukkan{
    int uangmasuk;
    char tanggal[15];
};
struct pengeluaran{
    int uangkeluar;
    char tanggal[15];
};

typedef pemasukkan* pMasuk;
typedef pengeluaran* pKeluar;

void InputPemasukkan(){

}

void InputPengeluaran(){

}
void Total (){}
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
    std::cout << "5. \n";
    std::cout << "6. \n";
    std::cout << "7. Back \n"; // ini harus ada atau ga tapi gimana 
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
    int pilih;
    do{
    system("cls");
    std::cout << "==================================\n";
    std::cout << "           BUDGETIN AJA           \n";
    std::cout << "==================================\n";
    std::cout << "1. Isi Pemasukkan                 \n";
    std::cout << "2. Isi Pengeluaran                \n";
    std::cout << "3. Total Uang                     \n";
    std::cout << "4. Data - data Keuangan           \n";
    std::cout << "Masukkan Pilihan :";
    std::cin >> pilih;

    switch (pilih)
    {
    case 1:
        InputPemasukkan();
        break;
    case 2:
        InputPengeluaran();
        break;
    case 3:
        Total();
        break;
    case 4:
        DataKeuangan();
        break;

    default:
        break;
    }
    std::cout<<std::endl;
		system("pause");
    } while (pilih!=5);
}