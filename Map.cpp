/*
CISC 320 Team Turing Map Implementation Class
Author: Mike Kennelly
*/

#include "map.h"
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

//Exception Class declaration
MapLoadException::MapLoadException(const string& message) : message(message) {}
string MapLoadException::what() const {return message;}

//Map Class Declaration
Map::Map(ALLEGRO_DISPLAY* disp) {
    display = disp;
    gameMap = new int*[NUMROWS];
    for (int rows=0;rows<NUMROWS;rows++)
        gameMap[rows] = new int[NUMCOLS];
    loadMap("basicmap.txt");
    drawMap();
}
//Copy Constructor also not necessary but included because big three
Map::Map(const Map&){

}
Map::~Map(){
    for(int i=0;i<NUMROWS;i++){
        delete[] gameMap[i];
    }
    delete[] gameMap;
    gameMap = nullptr;
}

//Assignment Overload, not really necessary but big three so here it is.
Map& Map::operator=(const Map&){

}


void Map::loadMap(const string& filename){
    enum LoadState {TileSet, Map};
    int state = NULL;
    int loadCounterRow = 0, loadCounterCol = 0;
    ifstream openFile(filename);
    if(openFile.is_open()){
        string line;
        getline(openFile, line);
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
        openFile.seekg(0, ios::beg);
        while(!openFile.eof()){
            if (line.find("[TileSet]") != string::npos){
                state = TileSet;
                continue;
            }
            else if (line.find("[Map]") != string::npos){
                state = Map;
                continue;
            }

            switch(state){
            case TileSet:
                if (line.length() > 0)
                    tileSet = al_load_bitmap(line.c_str());
                break;
            case Map:
                openFile >> gameMap[loadCounterRow][loadCounterCol];
                loadCounterCol++;

                if (loadCounterCol >= NUMCOLS){
                    loadCounterCol = 0;
                    loadCounterRow++;
                }

                break;
            }
        }
    } else {
        throw MapLoadException("Could Not Load Map File!");
    }
}

//DO NOT FLIP THE SCREEN
void Map::drawMap(){
    for (int row = 0; row<NUMROWS; row++){
        for(int col = 0; col<NUMCOLS; col++){
            al_draw_bitmap_region(tileSet, gameMap[row][col]* BLOCKSIZE, 0, BLOCKSIZE, BLOCKSIZE, col*BLOCKSIZE+PADDING, row*BLOCKSIZE+PADDING, NULL);
        }
    }
}

int** Map::getMap(){
    return gameMap;
}


void Map::updateMap(vector<Building*> b){
    //First loop through all of the tiles to check if they need updating
    for (int row = 0; row<NUMROWS; row++){
        for(int col = 0; col<NUMCOLS; col++){
            //Now loop through building list to see if the tile needs to be changed.
            for (int building=0; building<b.size(); building++){
                Building* build = b.at(building);
                string buildType = build->getType();
                int buildPercent = build->getConstruct();
                int buildX = build->getX();
                int buildY = build->getY();
                int buildImg = getBuildImg(buildType, buildPercent);
                if (gameMap[row][col] != buildImg){
                    al_draw_bitmap_region(tileSet, buildImg*BLOCKSIZE, 0, BLOCKSIZE, BLOCKSIZE, col*BLOCKSIZE+PADDING, row*BLOCKSIZE+PADDING, NULL);
                }
                else {
                    al_draw_bitmap_region(tileSet, gameMap[row][col]* BLOCKSIZE, 0, BLOCKSIZE, BLOCKSIZE, col*BLOCKSIZE+PADDING, row*BLOCKSIZE+PADDING, NULL);
                }
            }
        }
    }
}

int buildImg(const string& type, int percent){
    if (type="Lecture"){
        int[3] pc = [34, 68, 100];
        int index = 0;
        while (index < pc.length()){
            if (percent == pc[index]){
                return
            }
            index++;
        }
    }
    else if (type =="Library"){
        int[4] pc = [25, 50, 75, 100];
    }
    else if (type =="Lab"){
        int[5] pc = [20, 40, 60, 80, 100];
    }
    else { //type == "Residence
        int[10] pc = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];
    }
}
