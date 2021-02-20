#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>

using namespace std;

struct Studentai{
	string vardas;
	string pavarde;
	int homeworkNum;
	int *grades;
	int exam;
};

bool check(){
	while(true){
		char ats;
		cin >> ats;
		if(ats == 'y' or ats == 'Y') return true;
		else if(ats == 'n' or ats == 'N') return false;
		else cout <<"Wrong input. Try again." << endl;
	}				// Y/N checkup			s
}

int numInput(){
	int num = 0;
	while(true){
		cin >> num;
		if(num == -1) return -1;		//WIP
		else if(num <= 0 or cin.fail()) {
			cin.clear(); cin.ignore(999, '\n');
			cout << "Wrong input. Try again." << endl;
		}
		else return num;
	}
}

void checkGrade(int &grade){
	while(true){
		if(grade <= 10 and grade > 0) break;
		else cout << "Wrong input. Try again.";
		grade = numInput();
	}
}

void NewStud(Studentai &stud){
	bool knownGradesNum, generateGrades;			//gg f false for testing
	int gradeNum;

	cout << "Iveskite studento varda: "; cin >> stud.vardas; cout << endl;
	cout << "Iveskite studento pavarde: "; cin >> stud.pavarde; cout << endl;

	cout << "Ar zinote atliktu namu darbu kieki? (Y/N): ";
	knownGradesNum = check();

	if(knownGradesNum){
		cout << endl << "Iveskite atliktu namu darbu kieki: ";
		stud.homeworkNum = numInput();

		cout << endl << "Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): ";
		generateGrades = check();

		if(generateGrades){							// random number generation
			gradeNum = stud.homeworkNum;
			stud.grades = new int[gradeNum];
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.grades[i] = rand() % 10 + 1;
			}
			stud.exam = rand() % 10 + 1;
		}

		else {
			cout << endl << "Iveskite atliktu namu darbu pazymius: " << endl;
			stud.grades = new int[stud.homeworkNum];
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.grades[i] = numInput();
				checkGrade(stud.grades[i]);
			}

			cout << endl << "Iveskite egzamino pazymi: ";
			stud.exam = numInput();
			checkGrade(stud.exam);
		}

	}

	else{

		stud.homeworkNum = rand() % 25 + 1;				// homework number range: 1-25

		cout << endl << "Sugeneruotas atliktu namu darbu kiekis: " << stud.homeworkNum << endl;

		cout << endl << "Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): ";
		generateGrades = check();

		if(generateGrades){								// random number
			gradeNum = stud.homeworkNum;
			stud.grades = new int[gradeNum];
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.grades[i] = rand() % 10 + 1;
			}
			stud.exam = rand() % 10 + 1;
		}

		else {
			cout << endl << "Iveskite atliktu namu darbu pazymius: " << endl;
			stud.grades = new int[stud.homeworkNum];
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.grades[i] = numInput();
				checkGrade(stud.grades[i]);
			}

			cout << endl << "Iveskite egzamino pazymi: ";
			stud.exam = numInput();
			checkGrade(stud.exam);
		}
	}
}

void processStud(Studentai stud, Studentai *&studentai, int &studNum){
	Studentai* arr = new Studentai[studNum+1];
	for(int i = 0; i < studNum; i++) arr[i] = studentai[i];

	delete[] studentai;
	studentai = arr;
	studNum = studNum + 1;
	studentai[studNum - 1] = stud;
}

void output(Studentai *studentai, bool vid, int studNum){

	cout << "\n\n\n\n\n";
	cout << left << setw(10) << "Vardas" << setw(15) << "Pavarde" << setw(13);
	if(vid) cout << "Galutinis (vid.)" << endl;
	else cout << "Galutinis (med.)" << endl;
	cout << "------------------------------------------------" << endl;

	for(int i = 0; i < studNum; i++){
		double galutinis = 0;

		if(vid){
			double sum = 0;
			int size = studentai[i].homeworkNum-1;
			for(int j = 0; j < size; j++){
				sum = sum + studentai[i].grades[j];
			}
			double average = sum / size;
			galutinis = studentai[i].exam*0.6 + average*0.4;
		}
		else{
			int vidI = (studentai[i].homeworkNum/2)-1;
			sort(studentai[i].grades, studentai[i].grades + studentai[i].homeworkNum);

			if(studentai[i].homeworkNum != 0) galutinis = studentai[i].grades[vidI]*0.4 + studentai[i].exam*0.6;

			else galutinis = ((studentai[i].grades[vidI] + studentai[i].grades[vidI+1])/2)*0.4 + studentai[i].exam*0.6;
		}

		cout << left << setw(10) << studentai[i].vardas << setw(15) << studentai[i].pavarde << setw(13) << fixed << setprecision(2) << galutinis << endl;
	}
}

int main(){
	srand(time(NULL));
	int studNum = 0;
	bool vid;
	Studentai* studentai = new Studentai[studNum];

	do{
		Studentai stud;
		NewStud(stud);
		processStud(stud, studentai, studNum);
		cout << endl << "Ar norite prideti dar viena studenta? (Y/N) ";

	} while(check());

	cout << endl << "Ar norite apskaiciuoti mediana? (Y - med / N - vid): ";
	if(check()) vid = false;
	else vid = true;

	output(studentai, vid, studNum);
}