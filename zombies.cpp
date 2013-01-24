#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#define DEBUG_MODE

using namespace std;

class Edgelist {
  public:
		vector<int> neighbour;
		 double num_zombies;
		 int num_neighbours;
};

int calculate_random_index(int);
//void refresh_zombies_count(int);

int main() 
{
  /***************input data*******************/
	unsigned int num_test, num_nodes,num_roads, num_timesteps;
	
	while(num_test--) {
		cin>>num_test>>num_nodes>>num_roads>>num_timesteps;
		Edgelist *el = new Edgelist[num_nodes];
		int node, neighbour;
		for (int i=0; i<num_roads; i++) {
			cin>>node>>neighbour;
			el[node].neighbour.push_back(neighbour);
			el[neighbour].neighbour.push_back(node);
		}
#ifdef DEBUG_MODE
		cout<<endl<<"Test Case: "<<num_test<<endl;
		cout<<num_test<<"\t"<<num_nodes<<"\t"<<num_roads<<"\t"<<num_timesteps<<"\n";
		cout<<"**************************************\n";
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
			//el[i].zombies_moved = 0;
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
			//cout<<endl<<"Time Step: "<<num_timesteps+1<<endl;
#endif
			for(int i=0;i<num_nodes;i++) {
				if(el[i].num_zombies >= 1) {
					el[i].num_zombies--;
#ifdef DEBUG_MODE
					//cout<<endl<<"Zombies at node "<<i<<" --> "<<el[i].num_zombies;
#endif
					for (int j=0; j < el[i].neighbour.size(); j++){
						el[el[i].neighbour[j]].num_zombies += 1.0/el[i].num_neighbours;
#ifdef DEBUG_MODE
						//cout<<endl<<"Zombies at node "<<el[i].neighbour[j]<<" --> "<<el[el[i].neighbour[j]].num_zombies;
#endif
					}
				}
			}
//			int random_index=0;
//			for(int i=0;i<num_nodes;i++) {
//				random_index = calculate_random_index(el[i].num_neighbours);
//				el[i].zombies_moved--; //1 zombie moved away
//				el[el[i].neighbour[random_index]].zombies_moved++; //1 zombie came
//#ifdef DEBUG_MODE
//				cout<<"Random Index for node "<<i<<" = "<<random_index<<endl;
//#endif
//			}
//			//refresh_zombies_count(num_nodes);
//			for (int i=0; i<num_nodes; i++) {
//				el[i].num_zombies += el[i].zombies_moved;
//				el[i].zombies_moved = 0;
//			}
//#ifdef DEBUG_MODE
//			cout<<"\nNumber of Zombies";
//			for(int i=0; i<num_nodes; i++) 
//				cout<<"\n"<<i<<" = "<<el[i].num_zombies;
//#endif

		}//end of while num_timesteps

		//store final number of zombies in a vector 
		vector<int> zombies;
		for (int i=0;i<num_nodes;i++) {
			zombies.push_back( floor(el[i].num_zombies + 0.5) );
#ifdef DEBUG_MODE
			cout<<endl<<"Number of zombies at "<<i<<" --> "<<el[i].num_zombies;
#endif
		}
		sort(zombies.begin(),zombies.end());
		reverse(zombies.begin(),zombies.end());
		cout<<endl;
		for(int i=0; i<5; i++) {
			cout<<zombies[i]<<"\t";
		}
		cout<<endl;
		delete[] el;
	}//while test
  /*********OUTPUT END************************/
	
	return 0;
}//end of main

//int calculate_random_index(int num) 
//{
//	srand(time(NULL));
//	int index = rand() % num +1;
//	return index;
//	/*
//	default_random_engine dre;
//	uniform_int_distribution<int> di(1,num);
//	return dre(di);*/
//}//end 

/*void refresh_zombies_count(int num_nodes)
{
  for (int i=0; i<num_nodes; i++) {
    el[i].num_zombies += el[i].zombies_moved;
    el[i].zombies_moved = 0;
  }
}//end
*/

