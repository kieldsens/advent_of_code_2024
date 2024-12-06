#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(){
  string filename = "Input.txt";
  ifstream inputFile(filename);

  string line;
  vector<int> level;
  bool inc, dcr;
  int safe = 0;

  while(getline(inputFile, line)){
    istringstream iss(line);
    int num;
    level.clear();
    inc = false;
    dcr = false;
    while(iss >> num){
      level.push_back(num);
    }
    int length = level.size();
    bool valid = true;
    for (int i = 0; i < length - 1; i++){
      if (abs(level[i] - level[i + 1]) > 3 || level[i] == level[i + 1]){
       valid = false;
        break;
      }
      else{
        if(level[i] > level[i + 1]){
          dcr = true;
        }
        else{
          inc = true;
        }
      }
      if(inc && dcr){
        valid = false;
        break;
      }
    }
    if(valid){
      safe++;
    }
  }
  cout << safe;
}
