
#include "City.h"

using namespace std;
//authored by Anthony B. Duan on April Fools' Day 2023
//if anyone copies this code I will be furious
//one day, I may generalize this code should any of us transfer

int main() {
    vector<City> cities; //please see attached excel spreadsheet for which city corresponds to which int
    string f10; string f20; string f30;
    cout << "input the file name for the cities with their respective node numbers:" << endl;
    cin >> f10; //type cities.txt into the console
    fstream f1 (f10, std::fstream::in);
    int index;
    string s;
    int n = 0;
    while (f1 >> index >> s) {
        City cc;
        cc.setIndex(index);
        cc.setName(s);
        cities.push_back(cc);
        n++;
    }
    for (City& c : cities) {
        c.setSize(n);
    }
    cout <<  "input the file name for the connections between cities:" << endl;
    cin >> f20; //type distances.txt into the console
    fstream f2 (f20, std::fstream::in);
    int cityA; int cityB; int dist;
    while (f2 >> cityA >> cityB >> dist) {
        cities[cityA].addConnection(cities[cityB], dist);
        cities[cityB].addConnection(cities[cityA], dist);
    }
    cout << "input the file name for the cities someone is at:" << endl;
    cin >> f30; //type list.txt into the console
    fstream f3 (f30, std::fstream::in);
    int x;
    while (f3 >> x) {
        cities[x].setTempDist(0);
        find(cities[x]);
        for (City& c : cities) {
            c.switchDists();
        }
    }
    int minCity = 0;
    int minDist = cities[0].getTotDist();
    for (int count = 1; count < cities.size(); count++) {
        int k = cities[count].getTotDist();
        if (minDist > k){
            minDist = k;
            minCity = count;
        }
    }
    cout << "the city is: " << cities[minCity].getName() << endl;
    cout << "the total distance is: " << minDist << endl;
    return 0;
}