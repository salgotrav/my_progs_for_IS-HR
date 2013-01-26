#include<iostream>
#include<map>
#include<set>
#include<algorithm>

using namespace std;

#define DEBUG_MODE

int main() {
  int n, count;
  cin>>n;
  int *arr = new int[n];
  for(int i=0; i<n; i++)
    cin>>arr[i];
  count = 0;

  //here onwards we assume i,j and k as the last, 2nd and 1st digits of a triplet.
  //  multimap<int,int> ij_map; //map<i,j>
  set<int> i_map;
  set<int> j_map;
  set<int> k_map;

  for(int i=n-1;i>=0;i--) { //outer for start
    if(i_map.find(arr[i]) == i_map.end())
      i_map.insert(arr[i]);
    else
      continue;
    k_map.erase(k_map.begin(),k_map.end());
    j_map.erase(j_map.begin(),j_map.end());
    for(int j=i-1; j>=0; j--) {//middle for start
      if( arr[j]<arr[i] ) {
  if( j_map.find(arr[j]) == j_map.end() )
	  j_map.insert(arr[j]);
      }
      else 
	continue;
      for(int k=j-1;k>=0; k--) {
	if(k_map.find(arr[k])==k_map.end()) {
	  k_map.insert(arr[k]);
	}
	else 
	  continue;
	count++;
      }//inner for end
    }// middle for end
  }// outer for end


  cout<<count;
}// end of main
