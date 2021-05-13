#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <chrono>
#include <numeric>
#include <string>

using namespace std;
using namespace std::chrono;

// struct Studentai{
// 	string vardas;
// 	string pavarde;
// 	int homeworkNum;
// 	vector <int> grades;
// 	int exam;
// 	double final;
// };

class basePerson{		//base class
protected:
	string vardas;
	string pavarde;
public:
	basePerson() { };
	// -------------------
	inline std::string getVardas() const { return vardas; }
	inline std::string getPavarde() const { return pavarde; }
	// -------------------
	inline void setVardas(std::string _vardas) { vardas = _vardas; }
	inline void setPavarde(std::string _pavarde) { pavarde = _pavarde; }

	~basePerson() {};
};


class Studentai : public basePerson {		
private:
	int homeworkNum;
	vector <int> grades;
	int exam;
	double final;
public:
	Studentai() : final(0) { } // def konstruktorius
	Studentai(std::string name, std::string surname);
	// -------------------- Getteriai ----------------------
	inline std::vector<int> getGrades() const { return grades; }
	inline int getExam() const { return exam; }
	inline int getHomeworkNum() const { return homeworkNum; }
	inline int getFinal() const { return final; }

	// -------------------- Setteriai -----------------------
	// inline void set1grade(int g) { grades.push_back(g); }
	inline void setGrades(std::vector<int> _nd) { Studentai::grades = _nd; }
	inline void setExam(int _exam) { Studentai::exam = _exam; }
	inline void setHomeworkNum(int _homeworkNum) { Studentai::homeworkNum = _homeworkNum; }
	inline void setFinal(double _final) { Studentai::final = _final; }



	Studentai(const Studentai& other) :			// copy constructor
		// vardas(other.vardas), pavarde(other.pavarde),
		grades(other.grades), exam(other.exam),
		homeworkNum(other.homeworkNum), final(other.final) 
		{
			vardas = other.getVardas();
			pavarde = other.getPavarde();
		}


	Studentai& operator = (const Studentai& other){			// copy assignment operator
		vardas = other.vardas;
		pavarde = other.pavarde;
		grades = other.grades;
		exam = other.exam;
		homeworkNum = other.homeworkNum;
		final = other.final;
		return *this;
	}

	~Studentai() {};			// destructor
};

bool check();
char choiceCheck(char&);
char choiceCheck2(char&);
int numInput();
int gradeInput();
void checkGrade(int&);

void NewStud(vector <Studentai>&, char);

template <class T>
void fileInput(T&, string, char, bool);

void printCon(vector <Studentai>, char);

template <class T>
void print(T, char, string);

bool FileExist();
bool studComp(Studentai, Studentai);
void generateStud(int, string);

double calcFinal(vector <int>, int, int, char);			// update this in normal function of program

//---- strats -----
template <class T>
void group_strat1(T, T&, T&, int);

template <class T>
void group_strat2(T&, T&, int);

template <class T>
void group_optimised_vector(T&, T&, int);

//------ benchmarking --------

template <class T>
void mainFunc(T, T, T, bool, char, char);

template <class T>
void mainFuncForList(T, T, T, bool, char, char);

void benchmarkingVector(bool, char, char);
void benchmarkingDeque(bool, char, char);
void benchmarkingList(bool, char, char);

void benchmark();


#endif