#include<iostream>
#include<utility>
#include<vector>
#include<cstdio>

using namespace std;

//#define DEBUG_MODE

int main() 
{
  int num_points, queries;
  //cin>>num_points>>queries;
  scanf("%d%d",&num_points,&queries);

  pair<int, int> xy; //coordinates of point
  vector< pair<int,int> > array_points;

  for (int i=0; i<num_points; i++) {
    //cin>>xy.first>>xy.second;
    scanf("%d%d",&xy.first,&xy.second);
    array_points.push_back(xy);
  }//end of for loop 

#ifdef DEBUG_MODE
  for (vector< pair<int,int> >::iterator iter=array_points.begin(); iter!=array_points.end(); iter++) {
    xy=*iter;
    cout<<xy.first<<"\t"<<xy.second<<"\n";
   }
#endif

  int x,y,d, xd,yd, count; //xd is x+d
  
  while(queries--) {
    //cin>>x>>y>>d;
    scanf("%d%d%d",&x,&y,&d);
    xd=x+d;
    yd=y+d;
    count=0;

    for (vector< pair<int,int> >::iterator iter=array_points.begin(); iter!=array_points.end(); iter++) {
      xy=*iter;
      if(xy.first<x)
	continue;
      else if(xy.first>xd)
	continue;
      else if(xy.second<y)
	continue;
      else if(xy.second>yd)
	continue;
      else {
	if( (xy.second-y)*(-d)-(xy.first-x-d)*d >=0 )
	  count++;
	}//end of last else of ifelse ladder
    }//end of for loop
    //cout<<count<<endl;
    printf("%d\n",count);
  }//end of queries while loop
}//end of main
