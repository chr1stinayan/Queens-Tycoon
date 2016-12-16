#ifndef MYCAMPUS_H
#define MYCAMPUS_H

#pragma once
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>;

// class attributes of num of each type of building
using namespace std;

class MyCampus {
public:
  MyCampus(float p, float m, float r)
	float getRating();
  void setRating(float n);
  void setRating(int n);
	float getMoney();
  void setMoney(float n);
  void addBuilding(Building b);
  void removeBuilding(Building b);
  vector<int> getBuildingNums();
  vector<Building> getBuildingList();
	int getPop();
  void setRating(float n);
  vector<float> currentStats();
  vector<float> changeStats(float p, float m, float r);
  void setPop(int lab, int lib, int lec, int res);
  void passBuildings(Map m, AllegroDisplay ad);

protected:
	float rating; // this will represent the student satisfaction levels, or "happiness ratings"
	float money; // math models will likely output float values, rather than integers
	int population;
  vector<Building> buildingList;
  int labs;
  int libs;
  int lecs;
  int res;

friend ostream& operator<<(ostream& out, const MyCampus& value);  // Output stream overload for MyCampus, prints basic attributes of campus

};

#endif
