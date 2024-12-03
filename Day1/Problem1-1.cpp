#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
  vector<int> list1;
  vector<int> list2;
  for(int i = 0; i < 1000; i++){
    int a,b;
    cin >> a >> b;
    list1.push_back(a);
    list2.push_back(b);
  }
  sort(list1.begin(), list1.end());
  sort(list2.begin(), list2.end());
  long long sum = 0;
  for(int i = 0; i < 1000; i++){
    sum +=  abs(list1[i]- list2[i]);
  }
  cout << sum << "\n";
}


