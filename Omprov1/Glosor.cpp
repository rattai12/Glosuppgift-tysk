#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <ctime>

using namespace std;
vector<string>svensk;
vector<string>tysk;

void setWesternEuropeanCodePage() {
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
}

void readFile() {
	string Mytext;

	ifstream MyreadFile("glosor.txt");
	
	while (getline(MyreadFile, Mytext)) {
		int firstcomma = Mytext.find(",");
		svensk.push_back(Mytext.substr(0, firstcomma));
		int secondcomma = Mytext.find(",", firstcomma + 1);
		tysk.push_back(Mytext.substr(firstcomma + 1, (secondcomma - firstcomma) - 1));
		
	}
	MyreadFile.close();
	
}
int slumpaTal() {
	int randtal;
	srand(time(0));
	randtal = (rand() % 35);
	return randtal;

}
void slumpaOrd(int tal) {
	int talord = 0;
	
	for (int i = 0; i < tal; i++) {
		talord++;
		cout << svensk[i] << endl;
	}


}



int main() {
	setWesternEuropeanCodePage();
	readFile();
	int correctanswer = 0;
	int antalglosor;
	cout << "Välkommen till glosförhöret!!! " << endl;
	cout << "------------------------------------" << endl;
	cout << "Totalt antal glosor inlästa är: " << svensk.size() << endl;
	cout << "Ange hur många glosor du vill träna på? ";
	cin >> antalglosor;
	cout << "Du vill träna på " << antalglosor << "glosor" << endl;
	//slumpaOrd(antalglosor);

	for (int i = 0; i < antalglosor; i++) {
		int slumptal = slumpaTal();
		cout << svensk[slumptal] << endl;
		cout << "Tysk översättning: ";
		string tyskord;
		cin >> tyskord;
		if (tysk[slumptal] == tyskord) {
			cout << "Bra rätt svar!" << endl;
			correctanswer++;
		}
	
		else {
			cout << "Tyvärr det var fel.." << endl;
		}

	}

	cout << "Du fick " << correctanswer<< " rätt";
	



	
	


}