#include "functions.hpp"
using namespace std;							// FIX SECONDS, FILE GENERATION, WHOLE FILE PROCESS TIME CALCULATION

int main(){
	srand(time(NULL));
	char rt = '0';		// rt naudojamas vidurkio isvedimui pasirinkti (resultType)
	bool vid, timeOut;

	cout << "Ar norite atlikti programos veikimo (greicio) analize? (Y/N): ";
	if(check())	benchmark();

	else{						// iprasta programos eiga \/
	
		vector <Studentai> studentai;
		vector <Studentai> winner;
		vector <Studentai> loser;

		if(FileExist()){
			cout << "Ar norite skaityti duomenis is failo ar duomenis ivesti rankiniu budu? (y - file / n - manually): ";

			if(check()){
				fileInput(studentai, "kursiokai.txt", rt, false);
			}

			else{
				do{
					NewStud(studentai);
					cout << endl << "Ar norite prideti dar viena studenta? (Y/N) ";
				} while(check());
			}
		}

		else {			// only manual input
			cout << "Failas nerastas. Duomenys privalo buti ivesti rankiniu budu." << endl << endl;
			do{
				NewStud(studentai);
				cout << endl << "Ar norite prideti dar viena studenta? (Y/N) ";
			} while(check());
		}

		sort(studentai.begin(), studentai.end(), studComp);
		cout << endl << "Ar norite apskaiciuoti mediana(1), vidurki(2), ar abu(3)? ";
		choiceCheck(rt);
		output(studentai, rt);
	}

	cout << endl;
	system("PAUSE");
}