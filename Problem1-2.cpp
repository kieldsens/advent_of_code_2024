#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
  vector<int> list1;
  vector<int> list2;
  for(int i = 0; i < 1000; i++){
    int x,y;
    cin >> x >> y;
    list1.push_back(x);
    list2.push_back(y);
  }
  sort(list1.begin(),list1.end());
  sort(list2.begin(),list2.end());
  int score = 0;
  int num = -1;
  int c;
  for(int j = 0; j < 1000; j++){
    c = 0;
    if(num == list1[j]){
      continue;
    }
    else{
      num = list1[j];
      for(int k = 0; k < 1000; k++){
        if(list2[k] == num){
          c++;
        }
      }
      c *= num;
    }
    score += c;
  }
  cout << score;
}
