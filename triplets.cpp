#include<iostream>
#include<algorithm>

using namespace std;

#define DEBUG_MODE

int main() {
  int n, count;
  cin>>n;
  int *arr = new int[n];
  for(int i=0; i<n; i++)
    cin>>arr[i];

  struct Distinct_Map {
    int i, j,k;
  }dm;

  count =0;

  for (int i=0;i<n;i++) {
    for (int j=i+1; j<n;j++) {
      if(arr[j]>arr[i]) {
   for(int k=j+1; k<n; k++)
	   if (arr[k]>arr[j]) {
	       count++;
	   }
      }
    } 
  }
  cout<<count;

}// end of main
