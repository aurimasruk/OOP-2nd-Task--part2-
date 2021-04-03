#include "functions.hpp"
using namespace std;

bool check(){							// Y/N checkup
	while(true){
		char ats;
		cin >> ats;
		if(ats == 'y' || ats == 'Y') return true;
		else if(ats == 'n' || ats == 'N') return false;
		else cout <<"Wrong input. Try again." << endl;
	}
}

char choiceCheck(char &rt){				// 1/2/3 checkup
	while(true){
		cin >> rt;
		if(rt == '1' || rt == '2' || rt == '3')
			return rt; 
		else{
			cout << "Wrong input. Try again. " << endl;
		}
	}
}

char choiceCheck2(char &rt){
	while(true){
		cin >> rt;
		if(rt == '1' || rt == '2')
			return rt; 
		else{
			cout << "Wrong input. Try again. " << endl;
		}
	}
}

int numInput(){							// number checkup
	int num = 0;
	while(true){
		cin >> num;
		if(num == -1) return -1;
		else if(num <= 0 or cin.fail()) {
			cin.clear(); cin.ignore(999, '\n');
			cout << "Wrong input. Try again." << endl;
		}
		else return num;
	}
}

void checkGrade(int &grade){			// grade checkup
	while(true){
		if(grade <= 10 and grade > 0) break;
		else cout << "Wrong input. Try again.";
		grade = numInput();
	}
}

void NewStud(vector <Studentai> &studentai){			// manual input - adding new student				//WORKING
	bool knownGradesNum, generateGrades;
	int gradeNum;
	Studentai stud;

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
	studentai.push_back(stud);
	stud.grades.clear();
}

template <class T>
void fileInput(T &studentai, string fileName, char rt, bool timeOut){			// input from file
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	ifstream file;

	try{
		file.open(fileName);
		if (!file) throw 1;

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
			if (stud.grades.size() == 0) throw 2;
	
			stud.grades.pop_back();
			stud.exam = g;
			stud.homeworkNum = stud.grades.size();
			stud.final = calcFinal(stud.grades, stud.exam, stud.homeworkNum, rt);
			studentai.push_back(stud);
		}
	}
	catch (int e){
		switch (e) {
		case 1:
			cout << "Failas nerastas." << endl << endl << "Baigiamas programos veikimas." << endl;
			break;
		case 2:
			cout << "Failas nuskaitytas netinkamai." << endl;
			break;
		}
		exit(1);
	}

	file.close();

	if(timeOut == true)
	cout << "Duomenu nuskaitymas is failo uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
}

void output(vector <Studentai> studentai, char rt){						// output to console			// WORKING

	cout << "\n\n\n\n\n";
	cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(18);
	if(rt == '2') cout << "Galutinis (vid.)" << endl;
	else if (rt == '1') cout << "Galutinis (med.)" << endl;
	else cout << "Galutinis (vid.)" << setw(18) << "Galutinis (med.)" << endl;
	if (rt == '3') cout << "----------------------------------------------------------------" << endl;
	else cout << "-----------------------------------------------" << endl;

	for(int i = 0; i < studentai.size(); i++){
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

		if(rt == '1')	cout << fixed << setprecision(2) << galutinisMed << endl;
		else if (rt == '2')	cout << fixed << setprecision(2) << galutinisVid << endl;
		else cout << fixed << setprecision(2) << galutinisVid << setw(18) << setprecision(2) << galutinisMed << endl;
	}
}

template <class T>
void fileOutput(T winner, T loser, char rt, string outFileName){								// WORKING
	
	// high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	string wfile = "Winner_" + outFileName;
	string lfile = "Loser_" + outFileName;

	ofstream wout(wfile);
	ofstream lout(lfile);

	wout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(18);
	if(rt == '2') wout << "Galutinis (vid.)" << endl;
	else if (rt == '1') wout << "Galutinis (med.)" << endl;
	else wout << "Galutinis (vid.)" << setw(18) << "Galutinis (med.)" << endl;
	if (rt == '3') wout << "-----------------------------------------------------------------------------------------------------" << endl;
	else wout << "-------------------------------------------------------------------" << endl;

	lout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(18);
	if(rt == '2') lout << "Galutinis (vid.)" << endl;
	else if (rt == '1') lout << "Galutinis (med.)" << endl;
	else lout << "Galutinis (vid.)" << setw(18) << "Galutinis (med.)" << endl;
	if (rt == '3') lout << "-----------------------------------------------------------------------------------------------------" << endl;
	else lout << "-------------------------------------------------------------------" << endl;

	while(loser.size() > 0){
		lout << left << setw(20) << loser.front().vardas << setw(20) << loser.front().pavarde << setw(18);
		lout << fixed << setprecision(2) << round(loser.front().final) << endl;
		loser.erase(loser.begin());
	}		
	lout.close();

	while(winner.size() > 0){			
		wout << left << setw(20) << winner.front().vardas << setw(20) << winner.front().pavarde << setw(18);
		wout << fixed << setprecision(2) << round(winner.front().final) << endl;
		winner.erase(winner.begin());
	}
	wout.close();

	// cout << "Surusiuotu studentu isvedimas i du naujus failus uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
}

bool FileExist(){		// Failo patikrinimas
	ifstream file;
	file.open("kursiokai.txt");
	if(!file) return 0;
	else {cout << "File 'kursiokai.txt' detected." << endl << endl;
		return 1;}
}

bool studComp(Studentai a, Studentai b){			// rusiavimas
	if(a.vardas < b.vardas) return true;
	else return false;
}

// template <class T>
// void sorting(){

// }

void generateStud(int fStudSize, string fileName){						// failo kurimas
	int a = 10;

	// high_resolution_clock::time_point t1 = high_resolution_clock::now();

	ofstream out(fileName);
	out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
	for(int i = 0; i < a; i++) out << setw(8) << "ND" + to_string(i+1);
	out << setw(8) << "Egz." << endl;

	for(int i = 0; i < fStudSize; i++){
		out << left << setw(20) << "Vardenis" + to_string(i+1) << setw(20) << "Pavardenis" + to_string(i+1);
		for(int j = 0; j <= a; j++) {
			out << setw(8) << rand() % 10 + 1;
		}
		out << endl;
	}
	out.close();

	// cout << "Failo kurimas uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
}

double calcFinal(vector <int> grades, int exam, int homeworkNum, char rt){
	double final;

	if(rt == '2'){
					//calc vid
		int sum;
		sum = accumulate(grades.begin(), grades.end(), 0);
		final = (sum * 1.0 / homeworkNum) * 0.4 + exam * 0.6;
	}

	else if(rt == '1'){
		int vidI = (homeworkNum /2)-1;			//calc med
		sort(grades.begin(), grades.end());
		if(homeworkNum != 0) final = grades[vidI]*0.4 + exam*0.6;
		else final = ((grades[vidI] + grades[vidI+1])/2)*0.4 + exam*0.6;
	}
	return final;
}

template <class T>
void group(T studentai, T &winner, T &loser, int studNum){
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	for (int i = 0; i < studNum; i++){
		if (studentai.front().final < 5){ loser.push_back(studentai.front());
			studentai.erase(studentai.begin());
		}
		else {winner.push_back(studentai.front());
			studentai.erase(studentai.begin());
		}
	}
	studentai.clear();

	cout << "Studentu rusiavimas i dvi grupes uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
}

// template <class T>			// IN PROGRESS
// void groupVector(T studentai, T &winner, T &loser){
// 	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
// 	for (int i = 0; i < studentai.size(); i++){
// 		if (studentai[i].final < 5) loser.push_back(studentai[i]);
// 		else winner.push_back(studentai[i]);
// 	}
// 	studentai.clear();

// 	cout << "Studentu rusiavimas i dvi grupes uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() << "ms." << endl;
// }

// template <class T>
// void group(T studentai, T &winner, T &loser, int studNum){
// 	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
// 	for (int i = 0; i < studNum; i++){
// 		if (studentai.front() < 5){ loser.push_back(studentai.front());
// 			studentai.erase(studentai.begin());
// 		}
// 		else {winner.push_back(studentai.front());
// 			studentai.erase(studentai.begin());
// 		}
// 	}
// 	studentai.clear();

// 	cout << "Studentu rusiavimas i dvi grupes uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
// }

template <class T>
void mainFunc(T studentai, T winner, T loser, bool genStud, char rt, char conType){

																								// GREICIO ANALIZE \/
	
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	cout << endl << "Failas kursiokai1000.txt" << endl;
	if (genStud == 1)
	generateStud(1000, "kursiokai1000.txt");
	fileInput(studentai, "kursiokai1000.txt", rt, true);

	// sorting();		// not sure if needed
	// if(conType == '1' || conType == '2')
	// sort(studentai.begin(), studentai.end(), studComp);
	// else if(conType == '3'){
	// studentai.sort(studComp);	studentai.sort(studComp); }
	// if(rt == '2' || rt == '3') 
	group(studentai, winner, loser, 1000);
	// else groupVector(studentai, winner, loser);
	fileOutput(winner, loser, rt, "kursiokai1000.txt");
	cout << "Bendras failo kursiokai1000.txt testavimo laikas: " << 
	chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;

	

	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	cout << endl << "Failas kursiokai10000.txt" << endl;
	if (genStud == 1)
	generateStud(10000, "kursiokai10000.txt");
	fileInput(studentai, "kursiokai10000.txt", rt, true);
	group(studentai, winner, loser, 10000);
	fileOutput(winner, loser, rt, "kursiokai10000.txt");
	cout << "Bendras failo kursiokai10000.txt testavimo laikas: " << 
	chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t2).count() / 1000. << "s." << endl;

	high_resolution_clock::time_point t3 = high_resolution_clock::now();
	cout << endl << "Failas kursiokai100000.txt" << endl;
	if (genStud == 1)
	generateStud(100000, "kursiokai100000.txt");
	fileInput(studentai, "kursiokai100000.txt", rt, true);
	group(studentai, winner, loser, 100000);
	fileOutput(winner, loser, rt, "kursiokai100000.txt");
	cout << "Bendras failo kursiokai100000.txt testavimo laikas: " << 
	chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t3).count() / 1000. << "s." << endl;

	high_resolution_clock::time_point t4 = high_resolution_clock::now();
	cout << endl << "Failas kursiokai1000000.txt" << endl;
	if (genStud == 1)
	generateStud(1000000, "kursiokai1000000.txt");
	fileInput(studentai, "kursiokai1000000.txt", rt, true);
	group(studentai, winner, loser, 1000000);
	fileOutput(winner, loser, rt, "kursiokai1000000.txt");
	cout << "Bendras failo kursiokai1000000.txt testavimo laikas: " << 
	chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t4).count() / 1000. << "s." << endl;

	high_resolution_clock::time_point t5 = high_resolution_clock::now();
	cout << endl << "Failas kursiokai10000000.txt" << endl;
	if (genStud == 1)
	generateStud(10000000, "kursiokai10000000.txt");
	fileInput(studentai, "kursiokai10000000.txt", rt, true);
	group(studentai, winner, loser, 10000000);
	fileOutput(winner, loser, rt, "kursiokai10000000.txt");
	cout << "Bendras failo kursiokai10000000.txt testavimo laikas: " << 
	chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t5).count() / 1000. << "s." << endl;
}

void benchmark(){

	bool genStud;
	char conType = '0', rt = '0';

	cout << "Pasirinkite konteinerio tipa" << endl
		<< "(1) Vector / (2) Deque / (3) List : ";
	choiceCheck(conType); 

	cout << endl << "Ar norite sugeneruoti studentu failus? (Y/N): ";
	if(check()) genStud = 1;
		else genStud = 0;

	cout << endl << "Ar norite apskaiciuoti mediana(1), vidurki(2)? ";
	choiceCheck2(rt);

	if(conType == '1') {

		vector <Studentai> studentai;
		vector <Studentai> winner;
		vector <Studentai> loser;

		cout << endl << "Pradedamas testavimas naudojant vector: " << endl;
		mainFunc(studentai, winner, loser, genStud, rt, conType);
	}
	else if(conType == '2') {
		deque <Studentai> studentai;
		deque <Studentai> winner;
		deque <Studentai> loser;

		cout << endl << "Pradedamas testavimas naudojant deque: " << endl;
		mainFunc(studentai, winner, loser, genStud, rt, conType);
	}
	else if (conType == '3') {
		list <Studentai> studentai;
		list <Studentai> winner;
		list <Studentai> loser;

		cout << endl << "Pradedamas testavimas naudojant list: " << endl;
		mainFunc(studentai, winner, loser, genStud, rt, conType);
	}
}