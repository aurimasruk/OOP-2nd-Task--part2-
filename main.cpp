#include "functions.hpp"
using namespace std;

int main(){
	srand(time(NULL));
	char rt = '0';		// rt naudojamas vidurkio isvedimui pasirinkti (resultType)
	bool vid;

	vector <Studentai> studentai;
	vector <Studentai> winner;
	vector <Studentai> loser;

	cout << "Ar norite atlikti programos veikimo (greicio) analize? (Y/N): ";
	if(check()){

		cout << endl << "Ar norite apskaiciuoti mediana(1), vidurki(2)? ";
		choiceCheck(rt);

																								// 		GREICIO ANALIZE \/
		cout << endl << "Failas kursiokai1000.txt" << endl;
		generateStud(1000, "kursiokai1000.txt");
		fileInput(studentai, "kursiokai1000.txt");
		calcFinal(studentai, rt);
		group(studentai, winner, loser);
		sort(studentai.begin(), studentai.end(), studComp);
		fileOutput(winner, loser, rt, "kursiokai1000.txt");

		cout << endl << "Failas kursiokai10000.txt" << endl;
		generateStud(10000, "kursiokai10000.txt");
		fileInput(studentai, "kursiokai10000.txt");
		calcFinal(studentai, rt);
		group(studentai, winner, loser);
		sort(studentai.begin(), studentai.end(), studComp);
		fileOutput(winner, loser, rt, "kursiokai10000.txt");

		cout << endl << "Failas kursiokai100000.txt" << endl;
		generateStud(100000, "kursiokai100000.txt");
		fileInput(studentai, "kursiokai100000.txt");
		calcFinal(studentai, rt);
		group(studentai, winner, loser);
		sort(studentai.begin(), studentai.end(), studComp);
		fileOutput(winner, loser, rt, "kursiokai100000.txt");

		cout << endl << "Failas kursiokai1000000.txt" << endl;
		generateStud(1000000, "kursiokai1000000.txt");
		fileInput(studentai, "kursiokai1000000.txt");
		calcFinal(studentai, rt);
		group(studentai, winner, loser);
		sort(studentai.begin(), studentai.end(), studComp);
		fileOutput(winner, loser, rt, "kursiokai1000000.txt");

		cout << endl << "Failas kursiokai10000000.txt" << endl;
		generateStud(10000000, "kursiokai10000000.txt");
		fileInput(studentai, "kursiokai10000000.txt");
		calcFinal(studentai, rt);
		group(studentai, winner, loser);
		sort(studentai.begin(), studentai.end(), studComp);
		fileOutput(winner, loser, rt, "kursiokai10000000.txt");
	}	

	else{						// iprasta programos eiga \/
	
		if(FileExist()){
			cout << "Ar norite skaityti duomenis is failo ar duomenis ivesti rankiniu budu? (y - file / n - manually): ";

			if(check()){
				fileInput(studentai, "kursiokai.txt");
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

	system("PAUSE");
}