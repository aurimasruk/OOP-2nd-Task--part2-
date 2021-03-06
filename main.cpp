#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include "functions.hpp"

using namespace std;

int main(){
	srand(time(NULL));
	int studNum = 0; char rt = '0';		// rt naudojamas vidurkio isvedimui pasirinkti (resultType)
	bool vid;
	Studentai* studentai = new Studentai[studNum];

	if(FileExist()){
		cout << "Ar norite skaityti duomenis is failo ar duomenis ivesti rankiniu budu? (y - file / n - manually): ";
	
		if(check()){
			Studentai stud;
			fileInput(stud, studentai, studNum);
		}
			
		else{
			do{
				Studentai stud;
				NewStud(stud);
				processStud(stud, studentai, studNum);
				cout << endl << "Ar norite prideti dar viena studenta? (Y/N) ";
			} while(check());
		}
	}

	else {			// only manual input
		cout << "Failas nerastas. Duomenys privalo buti ivesti rankiniu budu. " << endl << endl; 
		do{
			Studentai stud;
			NewStud(stud);
			processStud(stud, studentai, studNum);
			cout << endl << "Ar norite prideti dar viena studenta? (Y/N) ";
		} while(check());
	}

	sort(studentai, studentai + studNum, studComp);

	cout << endl << "Ar norite apskaiciuoti mediana(1), vidurki(2), ar abu(3)? ";
	choiceCheck(rt);

	output(studentai, rt, studNum);
}