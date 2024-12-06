
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

bool checklevel (vector <int> a){ 
    int length = a.size();
    bool val = true;
    bool inc = false;
    bool dcr = false;
    for (int i = 0; i < length - 1; i++){
      if (abs(a[i] - a[i + 1]) > 3 || a[i] == a[i + 1]){
       val = false;
        break;
      }
      else{
        if(a[i] > a[i + 1]){
          dcr = true;
        }
        else{
          inc = true;
        }
      }
      if(inc && dcr){
        val = false;
        break;
      }
  }
    return val;
}

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
    bool valid = false;
    auto consider = [&](int i){
      vector<int> b = level;
      b.erase(b.begin()+ i);
      if(checklevel(b)){
        valid = true;
      }
    };
    consider(0);
    for (int i = 0; i < length - 1; i++){
      int diff = level[i + 1] - level[i];
      if (abs(diff) > 3 || abs(diff) == 0){
        consider(i);
        consider(i+1);
        break;
      }
      if(i + 2 < length){
        int diff2 = level[i+2] - level[i+1];
        if((diff > 0) != (diff2 > 0)){
          consider(i);
          consider(i + 1);
          consider(i + 2);
          break;
        }
      }
    }
    if(valid){
      safe++;
    }
  }
  cout << safe;
}
