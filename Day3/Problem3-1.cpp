#include<stdio.h>
#include<iostream>
#include<regex>
#include<ctime>
#include<thread>

using namespace std;

int main(){
  string in;
  int sum = 0;
  for(int i = 0; i < 6; i++){
  getline(cin, in);

  regex reg (R"(mul\(([0-9]+),([0-9]+)\))",regex_constants::icase);
  auto begin = sregex_iterator(in.begin(), in.end(), reg);
  auto end = sregex_iterator();

  for(auto it = begin; it != end; ++it){
    smatch match =  *it;
    int num1 = stoi(match[1]);
    int num2 = stoi(match[2]);
    sum += num1 * num2;
  }
  }
  cout << sum;
  return 0;
}
