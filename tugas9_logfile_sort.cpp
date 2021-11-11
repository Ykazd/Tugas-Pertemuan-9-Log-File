#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string sort(string filename, string str);       //prototipe fungsi sort

int main(){
    ofstream oFile;     //deklarasi output file
    string output;        //deklarasi string    
    
    oFile.open("information.txt");        //open file baru "information.txt" untuk menyimpan baris yang ada tulisan "Information"
    output = sort("event_log_windows_1000.txt", "Information");      //memanggil fungsi sort mencari kata "Information" pada file "event_log_windows_1000.txt"
    oFile<<output;              //memasukkan variabel output yang berisi baris yang mengandung kata "Information"
    oFile.close();      //close file output

    oFile.open("warning.txt");        //open file baru "warning.txt" untuk menyimpan baris yang ada tulisan "Warning"
    output = sort("event_log_windows_1000.txt", "Warning");          //memanggil fungsi sort mencari kata "Warning" pada file "event_log_windows_1000.txt"
    oFile<<output;              //memasukkan variabel output yang berisi baris yang mengandung kata "Warning"
    oFile.close();      //close file output

    oFile.open("error.txt");      //open file baru "error.txt" untuk menyimpan baris yang ada tulisan "Error"
    output = sort("event_log_windows_1000.txt", "Error");            //memanggil fungsi sort mencari kata "Error" pada file "event_log_windows_1000.txt"
    oFile<<output;              //memasukkan variabel output yang berisi baris yang mengandung kata "Error"
    oFile.close();      //close file output

    return 0;
}

string sort(string filename, string keyword){       //fungsi sort dengan parameter string filename dan keyword
    ifstream iFile;     //deklarasi input file
    string temp, output;

    iFile.open(filename, ios::in);       //open file "event_log_windows_1000.txt" sebagai input file
    while(!iFile.eof()){        //saat input file belum mencapai end of line (eof):
        getline(iFile, temp);       //mendapatkan sebaris line dari input file dan menyimpan baris tersebut ke dalam variabel temp
        if(temp.find(keyword) == 0){         //jika ditemukan kata "Information/Warning/Error" di index 0:
            output.append(temp + "\n");     //memperbarui variabel temp jika menemukan kata "Information/Warning/Error"
        }
        else{           //jika tidak menemukan kata "Information/Warning/Error" maka akan skip baris
            continue;
        }
    }
    iFile.close();      //close file input
    return output;      //return isi dari output
}