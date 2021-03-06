#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

struct Studentai{
	string vardas;
	string pavarde;
	int homeworkNum;
	vector <int> grades;
	int exam;
};

bool check(){
	while(true){
		char ats;
		cin >> ats;
		if(ats == 'y' or ats == 'Y') return true;
		else if(ats == 'n' or ats == 'N') return false;
		else cout <<"Wrong input. Try again." << endl;
	}				// Y/N checkup	
}

char choiceCheck(char &rt){
	while(true){
		cin >> rt;
		if(rt == '1' or rt == '2' or rt == '3')
			return rt; 
		else{
			cout << "Wrong input. Try again. " << endl;
		}
	}
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
		stud.grades.resize(stud.homeworkNum);

		cout << endl << "Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): ";
		generateGrades = check();

		if(generateGrades){							// random number generation
			gradeNum = stud.homeworkNum;
			stud.grades.resize(gradeNum);
			cout << endl << "Sugeneruoti studento pazymiai: ";
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.grades[i] = rand() % 10 + 1;
				cout << stud.grades[i] << " ";
			}
			stud.exam = rand() % 10 + 1;
			cout << endl << "Egzamino rezultatas: " << stud.exam;
		}

		else {
			cout << endl << "Iveskite atliktu namu darbu pazymius: " << endl;
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
			stud.grades.resize(gradeNum);
			cout << endl << "Sugeneruoti studento pazymiai: ";
			for(int i = 0; i < stud.homeworkNum; i++){
				stud.grades[i] = rand() % 10 + 1;
				cout << stud.grades[i] << " ";
			}
			stud.exam = rand() % 10 + 1;
			cout << endl << "Egzamino rezultatas: " << stud.exam;
		}

		else {
			cout << endl << "Iveskite atliktu namu darbu pazymius: " << endl;
			stud.grades.resize(stud.homeworkNum);
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

void fileInput(Studentai &stud, Studentai *&studentai, int &studNum){			//working
	ifstream file;
	file.open("kursiokai.txt");

	string line;
	getline(file, line);
	while (getline(file, line)){
		Studentai stud;

		istringstream iss(line);
		iss >> stud.vardas >> stud.pavarde;
		int g;
		while (iss >> g){
			stud.grades.push_back(g);
		}

		stud.grades.pop_back();
		stud.exam = g;
		processStud(stud, studentai, studNum);
	}
	file.close();
}

void output(Studentai *studentai, char rt, int studNum){

	cout << "\n\n\n\n\n";
	cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(18);
	if(rt == '2') cout << "Galutinis (vid.)" << endl;
	else if (rt == '1') cout << "Galutinis (med.)" << endl;
	else cout << "Galutinis (vid.)" << setw(18) << "Galutinis (med.)" << endl;
	if (rt == '3') cout << "----------------------------------------------------------------" << endl;
	else cout << "-------------------------------------------" << endl;

	for(int i = 0; i < studNum; i++){
		double galutinisVid = 0;
		double galutinisMed = 0;

		
		double sum = 0;		//calc vid
		int size = studentai[i].grades.size();
		for(int j = 0; j < size; j++){
			sum = sum + studentai[i].grades[j];
		}
		double average = sum / size;
		galutinisVid = studentai[i].exam*0.6 + average*0.4;
		

		int vidI = (size/2)-1;			//calc med
		sort(studentai[i].grades.begin(), studentai[i].grades.end());
		if(size != 0) galutinisMed = studentai[i].grades[vidI]*0.4 + studentai[i].exam*0.6;
		else galutinisMed = ((studentai[i].grades[vidI] + studentai[i].grades[vidI+1])/2)*0.4 + studentai[i].exam*0.6;
		
		//galutinis outputui \/

		cout << left << setw(15) << studentai[i].vardas << setw(15) << studentai[i].pavarde << setw(18);
		
		// for(int j = 0; j < 15; j++){				//test
		// 	cout << studentai[i].grades[j] << " ";
		// }
		// cout << studentai[i].exam << endl;

		if(rt == '1')	cout << fixed << setprecision(2) << galutinisMed << endl;
		else if (rt == '2')	cout << fixed << setprecision(2) << galutinisVid << endl;
		else cout << fixed << setprecision(2) << galutinisVid << setw(18) << setprecision(2) << galutinisMed << endl;
	}
}

bool FileExist(){		// Failo patikrinimas
	ifstream file;
	file.open("kursiokai.txt");
	if(!file) return 0;
	else {cout << "File 'kursiokai.txt' detected." << endl << endl;
		return 1;}
}

// void fileOutput(Studentai *studentai, int rt, int studNum){		// to do
// }

bool studComp(Studentai a, Studentai b){
	if(a.vardas < b.vardas) return true;
	else return false;
}

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

// 	cout << endl << "Ar norite duomenis isvesti i .txt faila(y), ar i ekrana(n)? ";
// 	if(check())	fileOutput(studentai, rt, studNum);
// 	else output(studentai, rt, studNum);
}