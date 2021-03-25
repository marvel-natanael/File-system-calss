#include <iostream>
#include <fstream> //file handling
#include <algorithm> //replace
using namespace std;

string myText;

void copy(string read, string copy){
    std::ofstream daftarCSV;
	ifstream daftarNama(read);
	daftarCSV.open(copy, std::ofstream::out | std::ofstream::trunc); //create new csv file
		while (getline (daftarNama, myText)) {
	  		daftarCSV << myText<<endl; //write data to file
		}
	daftarNama.close();
}

void read(string read){
	ifstream daftarNama(read);
		while (getline (daftarNama, myText)) {
	  		cout << myText<<endl;
		}
	daftarNama.close();
}

int getCount(string c){ //count how many line in file
	int count = 0;
	ifstream daftarNama(c);
		while (getline (daftarNama, myText)) {
			count++;
		}
		return count;
	daftarNama.close();
}

void reverse(string r, int sz){
	string arrCopy [sz];
	int i = sz;
	ifstream daftarNama(r);
    std::ofstream daftarCSV;
		while (getline (daftarNama, myText)) {
			arrCopy[i-1] = myText; //store data in array
			std::replace(arrCopy[i-1].begin(), arrCopy[i-1].end(), '\t', ','); //replace tab with comma
			i--;
		}
	daftarCSV.open(r, std::ofstream::out | std::ofstream::trunc);
		for(int i=0;i<sz-2;i++){ //skips header
			daftarCSV << arrCopy[i]<<endl; //write to file
		}
	daftarNama.close();
}

int main(){
	copy("daftar-nama.txt", "copy.csv"); //copies data
	read("copy.csv"); // shows data
	reverse("copy.csv", getCount("copy.csv")); //reverse data
	read("copy.csv"); // shows data
}

