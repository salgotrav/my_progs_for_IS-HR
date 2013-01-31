#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define DEBUG_MODE

int main() 
{
  int n;
  cin>>n;

  char ch;
  float median;
  int num;

  num=0;
  median=0;

  vector<int> list;
  vector<int>::iterator iter;

  iter = list.begin();

  while(n--) {
    cin>>ch;
    cin>>num;

    int list_size = list.size();

    switch(ch) {
    case 'a':
      list.push_back(num);
      sort(list.begin(),list.end());
      //      iter = list.begin();
      if(list_size == 1) { //list was initially empty
	cout<<num; //median is same as num
	median = num;
	  }
      else {
	if( list_size%2 != 0) { // num of elements in set are odd
	   median = list[list_size/2];
	}
	else { //no. of elements are even
	  median = (float)(list[list_size/2] + list[list_size/2 +1]) /2;
	}
      }//end of outer if else
      break;
    case 'r':
      //      iter = binary_search( list.begin(), list.end(), num);
     list.erase(iter);
      if(list_size == 0) { //list is empty
	cout<<"Wrong!";
      }
      else {
	if( list_size%2 != 0) { // num of elements in set are odd
	   median = list[list_size/2];
	}
	else { //no. of elements are even
	  median = (float)(list[list_size/2] + list[list_size/2 +1]) /2;
	}
      }//end of outer if else
      break;
    default:
      cout<<"\nInvalid Input";
    }//end of switch

  }//end of while loop

#ifdef DEBUG_MODE
  //for(iter=list.begin(),iter!=list.end();iter++)
  //	     cout<<iter<<"\n";
#endif

}//end of main


