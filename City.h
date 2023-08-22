#ifndef AA 
#define AA 
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;
class City {
    public:
    City () {
        this->index = -1;
        this->name = "USA";
        this->tempDist = 1000;
        this->totDist = 0;
    }
    ~City() {
        delete[] distances;
    }
    void setSize(int n) {
        this->distances = new int[n];
    }
    void setIndex(int i) {
        this->index = i;
    }
    void setName(string s) {
        this->name = s;
    }
    void addConnection(City& c, int d) {
        pair <City&, int> p (c,d);
        connected.push_back(p);
    }
    void setTempDist(int n) {
        this->tempDist = n;
    }
    int getTempDist() {
        return this->tempDist;
    }
    void switchDists() {
        this->totDist+=this->tempDist;
        this->tempDist = 1000;
    }
    int getTotDist() {
        return this->totDist;
    }
    string getName() {
        return this->name;
    }
    int getIndex() {
        return this->index;
    }
    vector<pair<City&, int>> connected;
    //the order was initially geographic but turned out to be alphabetical
    private:
    int* distances;
    int index;
    string name;
    int tempDist;
    int totDist;
};
    void find(City& c) {
        for (pair<City&, int> p : c.connected) {
            if (p.first.getTempDist() > p.second+c.getTempDist()) {
                p.first.setTempDist(p.second+c.getTempDist());
                find(p.first);
            }
        }
        return;
    }
#endif