/*
Ini program sorting dari input file txt menggunakan sort linear
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string sort(string filename, string str);       //prototipe fungsi sort

int main(){
    ofstream oFile;     //deklarasi output file
    string output, input = "event_log_windows_1000.txt";        //deklarasi string
    string information = "Information";
    string warning = "Warning";
    string error = "error";      
    
    oFile.open("event_log_windows_information.txt");        //open file baru "event_log_windows_information.txt" untuk menyimpan baris yang ada tulisan "Information"
    output = sort(input, information);      //memanggil fungsi sort mencari kata "Information"
    oFile<<output;              //memasukkan variabel output yang berisi baris yang mengandung kata "Information"
    oFile.close();      //close file output

    oFile.open("event_log_windows_warning.txt");        //open file baru "event_log_windows_warning.txt" untuk menyimpan baris yang ada tulisan "Warning"
    output = sort(input, warning);          //memanggil fungsi sort mencari kata "Warning"
    oFile<<output;              //memasukkan variabel output yang berisi baris yang mengandung kata "Warning"
    oFile.close();      //close file output

    oFile.open("event_log_windows_error.txt");      //open file baru "event_log_windows_information.txt" untuk menyimpan baris yang ada tulisan "Error"
    output = sort(input, error);            //memanggil fungsi sort mencari kata "Error"
    oFile<<output;              //memasukkan variabel output yang berisi baris yang mengandung kata "Error"
    oFile.close();      //close file output

    return 0;
}

string sort(string filename, string str){
    ifstream iFile;     //deklarasi input file
    string temp, output;

    iFile.open(filename, ios::in);       //open file "event_log_windows_1000.txt" sebagai input file
    while(!iFile.eof()){        //saat input file belum mencapai end of line:
        getline(iFile, temp);       //mendapatkan sebaris line dari input file dan menyimpan baris tersebut ke dalam variabel temp
        if(temp.find(str) != string::npos){     //iki aku rareti awkawkwakwk seng penteng nggo nemokke kata "Information/Warning/Error"
            output.append("\n" + temp);     //memperbarui variabel temp jika menemukan kata "Information/Warning/Error"
        }
        else{           //jika tidak menemukan kata "Information/Warning/Error" maka akan skip baris
            continue;
        }
    }
    iFile.close();      //close file input
    return output;      //return isi dari output
}