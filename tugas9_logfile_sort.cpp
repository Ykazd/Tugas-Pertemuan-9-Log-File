#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string sort(string filename, string str);

int main(){
    ofstream oFile;     //deklarasi output file
    string input = "event_log_windows_1000.txt", output, information = "Information", warning = "Warning", error = "error";      //deklarasi string
    
    oFile.open("event_log_windows_information.txt");        //open file baru "event_log_windows_information.txt" untuk menyimpan baris yang ada tulisan "Information"
    output = sort(input, information);
    oFile<<output;              //memasukkan variabel output yang berisi baris yang mengandung kata "Information"
    oFile.close();      //close file output

    oFile.open("event_log_windows_warning.txt");
    output = sort(input, warning);
    oFile<<output;
    oFile.close();

    oFile.open("event_log_windows_error.txt");
    output = sort(input, error);
    oFile<<output;
    oFile.close();

    return 0;
}

string sort(string filename, string str){
    ifstream iFile;     //deklarasi input file
    string temp, output;

    iFile.open(filename, ios::in);       //open file "event_log_windows_1000.txt" sebagai input file
    while(!iFile.eof()){        //saat input file  belum mencapai end of line:
        getline(iFile, temp);       //mendapatkan sebaris line dari input file dan menyimpan baris tersebut ke dalam variabel temp
        if(temp.find(str) != string::npos){     //iki aku rareti awkawkwakwk seng penteng nggo nemokke kata "Information"
            output.append("\n" + temp);     //memperbarui variabel temp jika menemukan kata "Information"
        }
        else{           //jika tidak menemukan kata "Information" maka akan skip baris
            continue;
        }
    }
    iFile.close();      //close file input
    return output;
}