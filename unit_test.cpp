#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.hpp"

TEST_CASE( "Pradedami unit testai. Tikrinama Student klase. ") {
    Studentai stud;
	vector<int> grades = {7, 8, 9, 9, 10, 6, 3, 7};			// studento pazymiai


	SECTION("Studentu vardo ir pavardes patikrinimas pries nuskaityma. "){
		REQUIRE(stud.getVardas().size() == 0);
		REQUIRE(stud.getPavarde().size() == 0);
	}

	SECTION("Studento vardo ir pavardes nuskaitymas. "){
		stud.setVardas("Jonas");
		stud.setPavarde("Jonauskas");
		REQUIRE(stud.getVardas() == "Jonas");
		REQUIRE(stud.getPavarde() == "Jonauskas");
	}

	SECTION("Studento pazymiu nuskaitymas. "){
		stud.setGrades(grades);
		REQUIRE(stud.getGrades() == grades);
	}

	SECTION("Studento egzamino nuskaitymas. "){
		stud.setExam(9);
		REQUIRE(stud.getExam() == 9);
	}

	SECTION("Studento galutinio pazymio nuskaitymas. "){
		stud.setFinal(7);
		REQUIRE(stud.getFinal() == 7);
	}
}