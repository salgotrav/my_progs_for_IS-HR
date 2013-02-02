#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

//#define DEBUG_MODE

int main()
{
  int num_test, count, str_len;
  cin>>num_test;

  string str;
  //string::iterator iter;

  while(num_test--) {
    int i=0;
    count=0;
    cin>>str;

    sort(str.begin(), str.end());
#ifdef DEBUG_MODE
    cout<<str<<endl;
#endif
    str_len=str.length();

    while(i<str_len){
      int diff=str.find_last_of(str[i]) - i;
      i=i+diff+1;
      if(diff>0){ //multiple occurences
	//if(diff%2==0)//odd
	  count += diff/2+1;
	//else 
	//count += diff/2;
      }
      else//single occurrence
	count++;
    }//end of inner while loop
    cout<<count<<endl;
    count=0;
  }//end of while
  return 0;
}//end of main
