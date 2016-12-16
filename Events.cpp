/*
 * Events.cpp
 *
 *
 *     Author: DanielleTremblay
 */

#include <string>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "Events.h"

//Error: If file containing random events cannot be opened
FileException::FileException(const string& message) :message(message) {
}
string& FileException::what() {
	return message;
}

vector<string> positiveArray, negativeArray;
vector<int> positiveMoney, negativeMoney, positiveRating, negativeRating;
vector<float>  positivePopulation, negativePopulation;
Events::Events(){}

//Opens positive events file and saves contents in a vector
void Events::readPositive() {
	string line;
	//Text with all positive events
	ifstream myFile("positiveEvents.txt");
	srand(time(NULL));
	if (myFile.fail()) {
		//If the file cannot be read throw an exception
		throw FileException("ERROR: File with positive events cannot be read.");
		return;
	}
	if (myFile.is_open()) {
		//Separates lines into a vector
		while (getline(myFile, line)) {
			positiveArray.push_back(line);
		}
	}
	myFile.close();
	return;
}

//Opens negative events and saves contents in a vector
void Events::readNegative() {
	string line;
	//Text with all negative events
	ifstream myFile("negativeEvents.txt");
	srand(time(NULL));
	if (myFile.fail()) {
		//If the file cannot be read throw an exception
		throw FileException("ERROR: File with negative events cannot be read.");
		return;
	}
	if (myFile.is_open()) {
		//Separates lines into a vector
		while (getline(myFile, line)) {
			negativeArray.push_back(line);
		}
	}
	myFile.close();
	return;
}

//Opens positive money changes and saves contents in a vector
void Events::readPMoney() {
	int line;
	//Text with all changes
	ifstream myFile("PMoney.txt");
	srand(time(NULL));
	if (myFile.fail()) {
		//If the file cannot be read throw an exception
		throw FileException("ERROR: File with positive money changes cannot be read.");
		return;
	}
	if (myFile.is_open()) {
		//Separates lines into a vector
		while (myFile >> line) {
			positiveMoney.push_back(line);
		}
	}
	myFile.close();
	return;
}

//Opens negative money changes and saves contents in a vector
void Events::readNMoney() {
	int line;
	//Text with all changes
	ifstream myFile("NMoney.txt");
	srand(time(NULL));
	if (myFile.fail()) {
		//If the file cannot be read throw an exception
		throw FileException("ERROR: File with negative money changes cannot be read.");
		return;
	}
	if (myFile.is_open()) {
		//Separates lines into a vector
		while (myFile >> line) {
			negativeMoney.push_back(line);
		}
	}
	myFile.close();
	return;
}

//Opens positive population changes and saves contents in a vector
void Events::readPPopulation() {
	float line;
	//Text with all changes
	ifstream myFile("PPopulation.txt");
	srand(time(NULL));
	if (myFile.fail()) {
		//If the file cannot be read throw an exception
		throw FileException("ERROR: File with positive population changes cannot be read.");
		return;
	}
	if (myFile.is_open()) {
		//Separates lines into a vector
		while (myFile >> line) {
			positivePopulation.push_back(line);
		}
	}
	myFile.close();
	return;
}

//Opens negative population changes and saves contents in a vector
void Events::readNPopulation() {
	float line;
	//Text with all changes
	ifstream myFile("NPopulation.txt");
	srand(time(NULL));
	if (myFile.fail()) {
		//If the file cannot be read throw an exception
		throw FileException("ERROR: File with negative population changes cannot be read.");
		return;
	}
	if (myFile.is_open()) {
		//Separates lines into a vector
		while (myFile >> line) {
			negativePopulation.push_back(line);
		}
	}
	myFile.close();
	return;
}

//Opens positive rating changes and saves contents in a vector
void Events::readPRating() {
	int line;
	//Text with all changes
	ifstream myFile("PRating.txt");
	srand(time(NULL));
	if (myFile.fail()) {
		//If the file cannot be read throw an exception
		throw FileException("ERROR: File with positive rating changes cannot be read.");
		return;
	}
	if (myFile.is_open()) {
		//Separates lines into a vector
		while (myFile >> line) {
			positiveRating.push_back(line);
		}
	}
	myFile.close();
	return;
}

//Opens negative Rating changes and saves contents in a vector
void Events::readNRating() {
	int line;
	//Text with all changes
	ifstream myFile("NRating.txt");
	srand(time(NULL));
	if (myFile.fail()) {
		//If the file cannot be read throw an exception
		throw FileException("ERROR: File with negative rating changes cannot be read.");
		return;
	}
	if (myFile.is_open()) {
		//Separates lines into a vector
		while (myFile >> line) {
			negativeRating.push_back(line);
		}
	}
	myFile.close();
	return;
}

//Vectors containing all used numbers
vector<int> usedPositive, usedNegative;

//Generates random number with no duplicate for positive events
int Events::randomNumberPositiveEvent() {
	int random;
	//Limits range to number of events
	random = rand() % positiveArray.size();
	for (unsigned int i = 0; i < usedPositive.size(); i++) {
		//If that number has already been used
		if (random == usedPositive[i]) {
			random = 0;
			//Repeat the function
			randomNumberPositiveEvent();
		}
	}
	//Add number to used numbers
	usedPositive.push_back(random);
	return random;
}

//Generates random number with no duplicate for negative events
int Events::randomNumberNegativeEvent() {
	int random;
	//Limits range to number of events
	random = rand() % negativeArray.size();
	for (unsigned int i = 0; i < usedNegative.size(); i++) {
		//If that number has already been used
		if (random == usedNegative[i]) {
			random = 0;
			//Repeat the function
			randomNumberNegativeEvent();
		}
	}
	//Add number to used numbers
	usedNegative.push_back(random);
	return random;
}

int money;
float population;
int rating;
//Generate and return positive or negative event to display to the screen
string Events::getEvent() {
	string eventString;
	srand(time(NULL));
	int random = rand() % 2;
	//Generate positive event
	if (random == 0) {
		readPositive();
		readPMoney();
		readPPopulation();
		readPRating();
		int randNum = randomNumberPositiveEvent();
		eventString = positiveArray[randNum];
		money = positiveMoney[randNum];
		population = positivePopulation[randNum];
		rating = positiveRating[randNum];

	}

	//Generate negative event
	if (random == 1) {
		readNegative();
		readNMoney();
		readNPopulation();
		readNRating();
		int randNum = randomNumberNegativeEvent();
		eventString = negativeArray[randNum];
		money = negativeMoney[randNum];
		population = negativePopulation[randNum];
		rating = negativeRating[randNum];
	}
	return eventString;
}

//Gets change in money
int Events::getMoney() {
	return money;
}

//Gets change in population
float Events::getPopulation() {
	return population;
}

//Gets change in Rating
int Events::getRating() {
	return rating;
}
