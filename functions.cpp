#include "functions.hpp"
using namespace std;

Studentai::Studentai(std::string name,  std::string surname){
    this->vardas = name;
    this->pavarde = surname;
}

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
		else if(num <= 0 || cin.fail()) {
			cin.clear(); cin.ignore(999, '\n');
			cout << "Wrong input. Try again." << endl;
		}
		else return num;
	}
}

int gradeInput(){
	int grade = 0;
	while(true){
		cin >> grade;
		if(grade <= 10 && grade > 0) return grade;
		
		else {
			cin.clear(); cin.ignore(999, '\n');
			cout << "Wrong input. Try again." << endl;
		}
	}
}

void checkGrade(int &grade){			// grade checkup
	while(true){
		if(grade <= 10 && grade > 0) break;
		else cout << "Wrong input. Try again.";
		grade = numInput();
	}
}

void NewStud(vector <Studentai> &studentai, char rt){			// manual input - adding new student				//WORKING
	bool knownGradesNum, generateGrades;
	int gradeNum, g, f;
	string vardas, pavarde;
	Studentai stud;
	vector<int> nd;

	cout << "Iveskite studento varda: "; cin >> vardas; cout << endl;
	cout << "Iveskite studento pavarde: "; cin >> pavarde; cout << endl;

	stud.setVardas(vardas); stud.setPavarde(pavarde);

	cout << "Ar zinote atliktu namu darbu kieki? (Y/N): ";
	knownGradesNum = check();

	if(knownGradesNum){
		cout << endl << "Iveskite atliktu namu darbu kieki: ";
		stud.setHomeworkNum(numInput());

		cout << endl << "Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): ";
		generateGrades = check();

		if(generateGrades){							// random number generation
			gradeNum = stud.getHomeworkNum();

			cout << endl << "Sugeneruoti studento pazymiai: ";
			for(int i = 0; i < gradeNum; i++){
				g = rand() % 10 + 1;
				cout << g << " ";
				nd.push_back(g);
			}
			stud.setGrades(nd);
			stud.setExam(rand() % 10 + 1);
			cout << endl << "Egzamino rezultatas: " << stud.getExam();
		}

		else {
			cout << endl << "Iveskite atliktu namu darbu pazymius: " << endl;
			for(int i = 0; i < stud.getHomeworkNum(); i++){
				g = numInput();
				checkGrade(g);
				nd.push_back(g);
			}
			stud.setGrades(nd);
			cout << endl << "Iveskite egzamino pazymi: ";
			stud.setExam(gradeInput());
		}
	}

	else{
		stud.setHomeworkNum(rand() % 25 + 1);				// homework number range: 1-25

		cout << endl << "Sugeneruotas atliktu namu darbu kiekis: " << stud.getHomeworkNum() << endl;

		cout << endl << "Ar norite, kad studento pazymiai butu sugeneruojami automatiskai? (Y/N): ";
		generateGrades = check();

		if(generateGrades){								// random number
			gradeNum = stud.getHomeworkNum();

			cout << endl << "Sugeneruoti studento pazymiai: ";
			for(int i = 0; i < gradeNum; i++){
				g = rand() % 10 + 1;
				cout << g << " ";
				nd.push_back(g);
			}
			stud.setGrades(nd);
			stud.setExam(rand() % 10 + 1);
			cout << endl << "Egzamino rezultatas: " << stud.getExam();
		}

		else {
			cout << endl << "Iveskite atliktu namu darbu pazymius: " << endl;
			for(int i = 0; i < stud.getHomeworkNum(); i++){
				g = numInput();
				checkGrade(g);
				nd.push_back(g);
			}
			stud.setGrades(nd);

			cout << endl << "Iveskite egzamino pazymi: ";
			stud.setExam(gradeInput());
		}
	}
	
	f = calcFinal(stud.getGrades(), stud.getExam(), stud.getHomeworkNum(), rt);
	stud.setFinal(f);
	studentai.push_back(stud);
	nd.clear();
}

template <class T>
void fileInput(T &studentai, string fileName, char rt, bool timeOut){			// input from file
	// high_resolution_clock::time_point t1 = high_resolution_clock::now();

	ifstream file;

	try{
		file.open(fileName);
		if (!file) throw 1;

		string line;
		getline(file, line);
		while (getline(file, line)){
			Studentai stud;
			int f;
			string vardas, pavarde;

			istringstream iss(line);
			iss >> vardas >> pavarde;
			stud.setVardas(vardas); stud.setPavarde(pavarde);
		
			vector<int> nd;
			int g;
			while (iss >> g){
				nd.push_back(g);
			}
			if (nd.size() == 0) throw 2;

			nd.pop_back();
			stud.setExam(g);
			stud.setGrades(nd);
			stud.setHomeworkNum(stud.getGrades().size());
			f = calcFinal(stud.getGrades(), stud.getExam(), stud.getHomeworkNum(), rt);
			stud.setFinal(f);
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

	// if(timeOut == true)
	// cout << "Duomenu nuskaitymas is failo uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
}

void printCon(vector <Studentai> studentai, char rt){			// output to console
	string galutinis;

	if(rt == '1') galutinis = "Galutinis (med.)";
	else if (rt == '2') galutinis = "Galutinis (vid.)";

	cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(18) << galutinis << endl
	<< "----------------------------------------------------------------------" << endl;
	for(auto stud : studentai){
		cout << left << setw(20) << stud.getVardas() << 
		setw(20) << stud.getPavarde() << 
		setw(18) << fixed << setprecision(2) << stud.getFinal() << endl;
	}
}

template <class T>
void print(T studentai, char rt, string outFileName){
	string galutinis;

	if(rt == '1') galutinis = "Galutinis (med.)";
	else if (rt == '2') galutinis = "Galutinis (vid.)";

	ofstream out(outFileName);

	out << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(18) << galutinis << endl
	<< "----------------------------------------------------------------------" << endl;
	for(auto stud : studentai){
		out << left << setw(20) << stud.getVardas() << 
		setw(20) << stud.getPavarde() << 
		setw(18) << fixed << setprecision(2) << stud.getFinal() << endl;
	}
}

bool FileExist(){		// Failo patikrinimas
	ifstream file;
	file.open("kursiokai.txt");
	if(!file) return 0;
	else {cout << "File 'kursiokai.txt' detected." << endl << endl;
		return 1;}
}

bool studComp(Studentai a, Studentai b){			// rusiavimas
	if(a.getVardas() < b.getVardas()) return true;
	else return false;
}

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
	Studentai stud;

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

	final = round(final);
	return final;
}

// --------------------------------------------------------------------------------
// GRUPAVIMAS

template <class T>
void group_strat1(T studentai, T &winner, T &loser, int studNum){						// 2 new containers
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	copy_if(studentai.begin(), studentai.end(), back_inserter(winner), [](Studentai const& stud) {return stud.getFinal() >= 5; });
	copy_if(studentai.begin(), studentai.end(), back_inserter(loser), [](Studentai const& stud) {return stud.getFinal() < 5; });  

	cout << "Studentu rusiavimas i dvi grupes uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
}

						// working
template <class T>
void group_strat2(T &studentai, T &loser, int studNum){									// 1 new and 1 existing containers
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	
	auto it = stable_partition(studentai.begin(), studentai.end(), [](Studentai const& stud) {return stud.getFinal() >= 5;});
	loser.assign(it, studentai.end());
	studentai.erase(it, studentai.end());

	cout << "Studentu rusiavimas i dvi grupes uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
}

template <class T>
void group_optimised_vector(T &studentai, T &loser, int studNum){
	high_resolution_clock::time_point t1 = high_resolution_clock::now();

	copy_if(studentai.begin(), studentai.end(), back_inserter(loser), [](Studentai const& stud) {return stud.getFinal() < 5; });
	studentai.erase(remove_if(studentai.begin(), studentai.end(), [](Studentai const& stud) {return stud.getFinal() < 5; }), studentai.end());

	cout << "Studentu rusiavimas i dvi grupes uztruko: " << chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
}

// ----------------------------------------------- \/ GREICIO ANALIZE \/ ------------------------------------------

template <class T>
void mainFunc(T studentai, T winner, T loser, bool genStud, char rt, char strat){

	int a = 5;			// size dydis
	int size[5] = {1000, 10000, 100000, 1000000, 10000000};

	if(strat == '1'){
		for(int i = 0; i < a; i++){

			string kursiokai = "kursiokai" + to_string(size[i]) + ".txt";

			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			cout << endl << "Failas " << kursiokai << endl;
			if (genStud == 1)
			generateStud(size[i], kursiokai);
			fileInput(studentai, kursiokai, rt, true);
			sort(studentai.begin(), studentai.end(), studComp);
			group_strat1(studentai, winner, loser, size[i]);
			print(winner, rt, "Winner_" + kursiokai);
			print(loser, rt, "Loser_" + kursiokai);
			cout << "Bendras failo " << kursiokai << " testavimo laikas: " << 
			chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
		}
	}

	else if(strat == '2'){
		for(int i = 0; i < a; i++){

			string kursiokai = "kursiokai" + to_string(size[i]) + ".txt";

			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			cout << endl << "Failas " << kursiokai << endl;
			if (genStud == 1)
			generateStud(size[i], kursiokai);
			fileInput(studentai, kursiokai, rt, true);
			sort(studentai.begin(), studentai.end(), studComp);
			group_strat2(studentai, loser, size[i]);
			print(studentai, rt, "Winner_" + kursiokai);
			print(loser, rt, "Loser_" + kursiokai);
			cout << "Bendras failo " << kursiokai << " testavimo laikas: " << 
			chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
		}
	}

	else if(strat == '3'){
		for(int i = 0; i < a; i++){

			string kursiokai = "kursiokai" + to_string(size[i]) + ".txt";

			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			cout << endl << "Failas " << kursiokai << endl;
			if (genStud == 1)
			generateStud(size[i], kursiokai);
			fileInput(studentai, kursiokai, rt, true);
			sort(studentai.begin(), studentai.end(), studComp);
			group_optimised_vector(studentai, loser, size[i]);
			print(studentai, rt, "Winner_" + kursiokai);
			print(loser, rt, "Loser_" + kursiokai);
			cout << "Bendras failo " << kursiokai << " testavimo laikas: " << 
			chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
		}
	}
}

template <class T>
void mainFuncForList(T studentai, T winner, T loser, bool genStud, char rt, char strat){

	int a = 3;

	int size[5] = {1000, 10000, 100000, 1000000, 10000000};

	if(strat == '1'){
		for(int i = 0; i < a; i++){

			string kursiokai = "kursiokai" + to_string(size[i]) + ".txt";

			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			cout << endl << "Failas " << kursiokai << endl;
			if (genStud == 1)
			generateStud(size[i], kursiokai);
			fileInput(studentai, kursiokai, rt, true);
			studentai.sort(studComp);
			group_strat1(studentai, winner, loser, size[i]);
			print(winner, rt, "Winner_" + kursiokai);
			print(loser, rt, "Loser_" + kursiokai);
			cout << "Bendras failo " << kursiokai << " testavimo laikas: " << 
			chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
		}
	}
	
	if(strat == '2'){
		for(int i = 0; i < a; i++){

			string kursiokai = "kursiokai" + to_string(size[i]) + ".txt";

			high_resolution_clock::time_point t1 = high_resolution_clock::now();
			cout << endl << "Failas " << kursiokai << endl;
			if (genStud == 1)
			generateStud(size[i], kursiokai);
			fileInput(studentai, kursiokai, rt, true);
			studentai.sort(studComp);
			group_strat2(studentai, loser, size[i]);
			print(studentai, rt, "Winner_" + kursiokai);
			print(loser, rt, "Loser_" + kursiokai);
			cout << "Bendras failo " << kursiokai << " testavimo laikas: " << 
			chrono:: duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - t1).count() / 1000. << "s." << endl;
		}
	}
}

// -------------------------------------------------- \/ BENCHMARKING \/ ----------------------------------

void benchmarkingVector(bool genStud, char rt, char strat){
	vector <Studentai> studentai;
	vector <Studentai> winner;
	vector <Studentai> loser;

	mainFunc(studentai, winner, loser, genStud, rt, strat);

	studentai.clear();
	winner.clear();
	loser.clear();
}

void benchmarkingDeque(bool genStud, char rt, char strat){
	deque <Studentai> studentai;
	deque <Studentai> winner;
	deque <Studentai> loser;

	mainFunc(studentai, winner, loser, genStud, rt, strat);
	
	studentai.clear();
	winner.clear();
	loser.clear();
}

void benchmarkingList(bool genStud, char rt, char strat){
	list <Studentai> studentai;
	list <Studentai> winner;
	list <Studentai> loser;

	mainFuncForList(studentai, winner, loser, genStud, rt, strat);

	studentai.clear();
	winner.clear();
	loser.clear();
}

void benchmark(){

	bool genStud;
	char conType = '0', rt = '0';
	char strat;

	cout << endl << "Pasirinkite testavimo strategija (1 / 2 / 3): " << endl
	<< "(1 - studentai yra skaidomi i du naujus konteinerius) " << endl
	<< "(2 - studentai yra skaidomi panaudojant tik viena nauja konteineri)" << endl
	<< "(3 - programos veikimo spartos palyginimas naudojant optimizuota ir paprasta vector konteineri (naudojantis 2 strategija))" << endl;

	choiceCheck(strat); 

	cout << endl << "Ar norite sugeneruoti studentu failus? (Y/N): ";
	if(check()) genStud = 1;
		else genStud = 0;

	cout << endl << "Ar norite apskaiciuoti mediana(1), vidurki(2)? ";
	choiceCheck2(rt);

	if(strat == '1') {
		
		cout << "NAUDOJAMA 1 STRATEGIJA. " << endl;

		cout << endl << "--------------------------- Pradedamas testavimas naudojant vector: -----------------------------------------------" << endl;
		benchmarkingVector(genStud, rt, strat);

		cout << endl << "-------------------------- Pradedamas testavimas naudojant deque: ------------------------------------------------" << endl;
		benchmarkingDeque(genStud, rt, strat);

		cout << endl << "----------------------------- Pradedamas testavimas naudojant list: ---------------------------------------------" << endl;
		benchmarkingList(genStud, rt, strat);
	}

	else if(strat == '2') {
		cout << "NAUDOJAMA 2 STRATEGIJA. " << endl;

		cout << endl << "--------------------------- Pradedamas testavimas naudojant vector: -----------------------------------------------" << endl;
		benchmarkingVector(genStud, rt, strat);

		cout << endl << "-------------------------- Pradedamas testavimas naudojant deque: ------------------------------------------------" << endl;
		benchmarkingDeque(genStud, rt, strat);

		cout << endl << "----------------------------- Pradedamas testavimas naudojant list: ---------------------------------------------" << endl;
		benchmarkingList(genStud, rt, strat);
	}

	else {
		cout << "VYKDOMAS VECTOR VEIKIMO SPARTOS PALYGINIMAS. " << endl
		<< "(Palyginimui naudojama antroji strategija) " << endl;

		// cout << endl << "--------------------------- Pradedamas testavimas naudojant vector: -----------------------------------------------" << endl;
		// benchmarkingVector(genStud, rt, '2');

		cout << endl << "--------------------------- Pradedamas testavimas naudojant optimizuota vector: -----------------------------------------------" << endl;
		benchmarkingVector(genStud, rt, '3');
	}
}