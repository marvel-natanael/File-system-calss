#include <iostream>
#include <string>
#include <sstream>
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

int getLastLine(std::ifstream& in)
{
    std::string line,temp;
    int x;
    while (in >> std::ws && std::getline(in, line)){
		if(line.find("\t") != std::string::npos){
	            temp =line.substr(0, line.find("\t")); //gets number from last line
	        }
	stringstream u(temp); //convert string to integer
	u>>x;			
	}
    return x;
    in.close();
}

void continueLastNumber(string s, string t, int o){
	string a,b,c,d,final[27],ccc[27];
	int e,f,x=0,h=2,i,j,q=0;;
	int k, l[27], z[27];

	ifstream daftarCSV(s);
	ifstream daftarNama(t);
	ifstream temp(t);

    std::ofstream newCSV;
	while (getline (daftarCSV, a)){
		size_t pos = a.find(",");
		a.erase(0, pos); //delete old number

		ccc[q] = a;
		q++;
	}	
	k = getLastLine(temp); //get last number

    while (getline (daftarNama, c)){
	   	if(x==h){
		   	if(c.find("\t") != std::string::npos)
	        {
	            d =c.substr(0, c.find("\t"));
	        }
		    stringstream q(d);
		    q>>f;
		    l[j]= f; //gets number
		    j++;
	   		h++;
		}
		   x++;
	}

	for(int r=0;r<o;r++){
		stringstream ss;
		z[r] = k + l[r];
		ss<<z[r];
		string zz;
		ss>>zz;
		final[r] = zz+ccc[r]; // final string
	}
	newCSV.open("copy.csv", std::ofstream::out | std::ofstream::trunc);
		for(int i=0;i<o;i++){ //skips header
			newCSV << final[i] <<endl; //write to file
		}
	temp.close();
	daftarCSV.close();
	daftarNama.close();	
}

void reverse(string r, int sz){
	string arrCopy [sz];
	int i = sz;
	ifstream CSVtemp(r);
    std::ofstream daftarCSV;
		while (getline (CSVtemp, myText)) {
			arrCopy[i-1] = myText; //store data in array
			std::replace(arrCopy[i-1].begin(), arrCopy[i-1].end(), '\t', ','); //replace tab with comma
			i--;
		}
	daftarCSV.open(r, std::ofstream::out | std::ofstream::trunc);
		for(int i=0;i<sz-2;i++){ //skips header
			daftarCSV << arrCopy[i]<<endl; //write to file
		}
	CSVtemp.close();
}

int main(){
	copy("daftar-nama.txt", "copy.csv"); //copies data
	reverse("copy.csv", getCount("copy.csv")); //reverse data
	continueLastNumber("copy.csv", "daftar-nama.txt",getCount("copy.csv"));//continue form last number
	read("copy.csv"); // shows data
}
//ref : http://www.cplusplus.com/forum/general/108679/
//https://www.javatpoint.com/cpp-int-to-string
