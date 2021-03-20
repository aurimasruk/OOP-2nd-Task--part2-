#ifndef functions_h
#define functions_h

using namespace std;

struct Studentai{
	string vardas;
	string pavarde;
	int homeworkNum;
	vector <int> grades;
	int exam;
};

bool check();
char choiceCheck(char&);
int numInput();
void checkGrade(int&);
void NewStud(Studentai&);
void processStud(Studentai, Studentai*&, int&);
void fileInput(Studentai&, Studentai*&, int&);
void output(Studentai*, char, int);
bool FileExist();
bool studComp(Studentai, Studentai);

#endif