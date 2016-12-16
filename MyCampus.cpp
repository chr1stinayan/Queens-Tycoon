/*
* MyCampus.cpp
* November 16th, 2016
* Christina Yan
*/
void MyCampus::MyCampus(float p, float m, float r): population(p), money(m), rating(r) {
	vector<Building> *buildingList = new vector<Building>();
  labs = 0;
  libs = 0;
  res = 0;
  lecs = 0;
}

float MyCampus::getRating(){
    return rating;
    }
void MyCampus::setRating(float n) {
    rating = n;
    }
void MyCampus::setRating(int n){
    float percent = n/100;
    rating *= percent;
}

float MyCampus::getMoney(){
    return money;
    }

void MyCampus::setMoney(int n) {
    money = n;
    }

void MyCampus::setMoney(int n) {
    float percent = n/100;
    money *= percent;
}

void MyCampus::addBuilding(Building b){
    buildingList.push_back(b);
    string buildType = b.getType();
    if (buildType == "Lab")
      labs++;
    elif (buildType == "Library")
      libs++;
    elif (buildType == "Residence")
      res++;
    elif (buildType == "Lecture")
      lecs++;
    }
void MyCampus::removeBuilding(Building b) {
    buildingList.erase(remove(buildingList.begin(), buildingList.end(), b), vec.erase(std::remove(vec.begin(), vec.end(), b), vec.end()).end());
    string buildType = b.getType();
    if (buildType == "Lab")
      labs--;
    elif (buildType == "Library")
      libs;
    elif (buildType == "Residence")
      res--;
    elif (buildType == "Lecture")
      lecs--;
    } //http://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position

vector<int> MyCampus::getBuildingNums {
    int numLabs = getLabs();
    int numLibs = getLibs();
    int numRes = getRes();
    int numLecs = getLecs();
    vector<int> counts[4] = {numLabs, numLibs, numRes, numLecs};
    return counts;
}

int MyCampus::getPop() {
    return population;
    }

void MyCampus::setPop(int n){
    population = n;
    }

// make sure this gets rounded to whole number int
void MyCampus::setPop(float percent){
    population *= percent;
}

//overload to update population based on how many of each type of building we have
void MyCampus::setPop(int lab, int lib, int lec, int res){
    int numStudents = 0;
    numStudents += lab * 20;
    numStudents += lib * 50;
    numStudents += lec * 100;
    numStudents ++ res * 350;
    population = newStudents;
}

vector<float> MyCampus::currentStats(){
    vector<float> stats = {population, money, rating};
    return stats;
    }

vector<float> MyCampus::changeStats(float p, float m, float r){
    setPop(p);
    setMoney(m);
    setRating(r);
    return vector<float> {population, money, rating}
}

void MyCampus::passBuildings(Map m, AllegroDisplay ad){
    m.drawMap(ad, buildingList);
}

vector<Building> MyCampus::getBuildingList() {
	return *buildingList;
}
