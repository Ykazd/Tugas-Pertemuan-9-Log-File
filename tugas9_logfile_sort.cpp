#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream iFile;     //deklarasi input file
    ofstream oFile;     //deklarasi output file
    string temp, output, info = "Information";      //deklarasi string

    
    iFile.open("event_log_windows_1000.txt", ios::in);      //open file "event_log_windows_1000.txt" sebagai input file
    while(!iFile.eof()){        //saat input file  belum mencapai end of line:
        getline(iFile, temp);       //mendapatkan sebaris line dari input file dan menyimpan baris tersebut ke dalam variabel temp
        if(temp.find(info) != string::npos){        //iki aku rareti awkawkwakwk seng penteng nggo nemokke kata "Information"
            output.append("\n" + temp);         //memperbarui variabel temp jika menemukan kata "Information"
        }
        else{
            continue;           //jika tidak menemukan kata "Information" maka akan skip baris
        }
    }
    
    oFile.open("event_log_windows_information.txt");        //open file baru "event_log_windows_information.txt" untuk menyimpan baris yang ada tulisan "Information"
    oFile<<output;              //memasukkan variabel output yang berisi baris yang mengandung kata "Information"

    iFile.close();      //close file input
    oFile.close();      //close file output

    return 0;
}