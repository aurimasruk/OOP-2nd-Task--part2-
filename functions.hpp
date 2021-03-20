#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Studentai{
	string vardas;
	string pavarde;
	int homeworkNum;
	vector <int> grades;
	int exam;
	double final;
};

bool check();
char choiceCheck(char&);
int numInput();
void checkGrade(int&);
void NewStud(vector <Studentai>&);
void fileInput(vector <Studentai>&, string);
void output(vector <Studentai>, char);
void fileOutput(vector <Studentai>, vector<Studentai>, char, string);
bool FileExist();
bool studComp(Studentai, Studentai);
void generateStud(int, string);
void calcFinal(vector <Studentai>&, char);
void group(vector <Studentai>, vector <Studentai>&, vector <Studentai>&);

#endif