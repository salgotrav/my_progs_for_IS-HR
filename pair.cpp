#include<iostream>
#include<algorithm>

using namespace std;

#define DEBUG_MODE

int main()
{
  unsigned int n, k, result, temp;
  int num;

  cin>>n>>k;

  int *num_map = new int[n];

  for (int i=0;i<n;i++) {
    cin>>num;
    num_map[i]=num;
  }//end of for loop for input

  sort(num_map, num_map+n);

  result=0;

  for(unsigned int i=0; i<n;i++) {
    temp = num_map[i]+k;
    if( binary_search(&num_map[i],num_map+n, temp) )
      result++;
  }
      
    cout<<result;  
}//end of main
