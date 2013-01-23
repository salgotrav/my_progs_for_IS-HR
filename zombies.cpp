#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include<time.h>

//#define DEBUG_MODE

using namespace std;

int calculate_random_index(int);
void refresh_zombies_count(int);

int main() 
{
  /***************input data*******************/
  unsigned int num_test, num_nodes,num_roads, num_timesteps;
  cin>>num_test>>num_nodes>>num_roads>>num_timesteps;
  cout<<num_test<<num_nodes<<num_roads<<num_timesteps<<"\n";

 class Edgelist {
    public:
     vector<int> neighbour;
     int num_zombies;
     int num_neighbours;
     int zombies_moved;
  };

  Edgelist *el = new Edgelist[num_nodes];

  while(num_test--) {
  int node, neighbour;

  for (int i=0; i<num_roads; i++) {
    cin>>node>>neighbour;
    el[node].neighbour.push_back(neighbour);
    el[neighbour].neighbour.push_back(node);
    }
#ifdef DEBUG_MODE
  cout<<"\nEDGE LIST\n";
#endif
  for (int i=0; i<num_nodes; i++) {
    sort(el[i].neighbour.begin(), el[i].neighbour.end());
    el[i].neighbour.erase( unique(el[i].neighbour.begin(), el[i].neighbour.end()), el[i].neighbour.end() );
    el[i].num_neighbours = el[i].neighbour.size();
#ifdef DEBUG_MODE
    cout<<"\n\n"<<i<<"\t-->";
    for (int j=0; j < el[i].neighbour.size(); j++) {
        cout<<"\t"<<el[i].neighbour[j];
    }
    cout<<"\nNumber of Neighbours = "<<el[i].num_neighbours;
#endif
    }
  
  for(int i=0; i<num_nodes; i++) {
    cin>>el[i].num_zombies;
    el[i].zombies_moved = 0;
  }

#ifdef DEBUG_MODE
  cout<<"\n\nNumber of Zombies";
  for(int i=0; i<num_nodes; i++) 
    cout<<"\n"<<i<<" = "<<el[i].num_zombies;
#endif
  /*********INPUT END*************************/
 

  /*********OUTPUT DATA***********************/
  while(num_timesteps--) {
#ifdef DEBUG_MODE
    cout<<endl<<"TEST CASE: "<<num_timesteps+1<<endl;
#endif
    int random_index=0;
    for(int i=0;i<num_nodes;i++) {
      random_index = calculate_random_index(el[i].num_neighbours);
      el[i].zombies_moved--; //1 zombie moved away
      el[el[i].neighbour[random_index]].zombies_moved++; //1 zombie came
#ifdef DEBUG_MODE
      cout<<"Random Index for node "<<i<<" = "<<random_index<<endl;
#endif
    }
    //refresh_zombies_count(num_nodes);
    for (int i=0; i<num_nodes; i++) {
      el[i].num_zombies += el[i].zombies_moved;
      el[i].zombies_moved = 0;
    }
#ifdef DEBUG_MODE
  cout<<"\nNumber of Zombies";
  for(int i=0; i<num_nodes; i++) 
    cout<<"\n"<<i<<" = "<<el[i].num_zombies;
#endif
      
  }//end of while


    vector<int> zombies;
    for (int i=0;i<num_nodes;i++) {
       zombies.push_back(el[i].num_zombies);
#ifdef DEBUG_MODE
    cout<<endl<<"Testcase unsorted zombies returned as: "<<el[i].num_zombies;
#endif
    }
    sort(zombies.begin(),zombies.end());
    reverse(zombies.begin(),zombies.end());
    for(int i=0; i<5; i++) {
      cout<<zombies[i]<<"\t";
      }
    cout<<endl;
  }//while test
  /*********OUTPUT END************************/
  delete[] el;
  return 0;
}//end of main

int calculate_random_index(int num) 
{
  srand(time(NULL));
  int index = rand() % num +1;
  return index;
  /*
  default_random_engine dre;
  uniform_int_distribution<int> di(1,num);
  return dre(di);*/
}//end 

/*void refresh_zombies_count(int num_nodes)
{
  for (int i=0; i<num_nodes; i++) {
    el[i].num_zombies += el[i].zombies_moved;
    el[i].zombies_moved = 0;
  }
}//end
*/
