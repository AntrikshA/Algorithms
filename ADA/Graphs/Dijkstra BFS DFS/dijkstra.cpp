#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <unistd.h>

using namespace std;

#define None 1000000
#define Name "dijkstraData.txt"
#define TestName "test.txt"
#define SIZE 201

int dist[SIZE], X[SIZE], graph[SIZE][SIZE];
int list[] = {7,37,59,82,99,115,133,165,188,197};

int minDistance(int dist[], bool sptSet[]){   
	
	int min = None, min_index;
 
	for (int v = 0; v < SIZE; v++)
		if (sptSet[v] == false && dist[v] <= min)
		    min = dist[v], min_index = v;

	return min_index;
}

void dijkstra(int graph[SIZE][SIZE], int s){

	bool sptSet[SIZE]; 

	for (int i = 0; i < SIZE; i++)
	dist[i] = None, sptSet[i] = false;

	dist[s] = 0;


	for (int count = 0; count < SIZE-1; count++)
	{
	int u = minDistance(dist, sptSet);

	sptSet[u] = true;

	for (int v = 0; v < SIZE; v++)
		if (!sptSet[v] && graph[u][v] && dist[u] != None && dist[u]+graph[u][v] < dist[v])
			dist[v] = dist[u] + graph[u][v];
	}
}

int main(){

	for(int i=0;i<SIZE;i++){
		dist[i] = None;
		X[i] = None;
	}

	ifstream file(Name);
	string read;

	while(getline(file,read)){

		istringstream read_line(read);
		string node;
		int x,y,z;

		while(getline(read_line,node,'\t')){
			x = atoi(node.c_str());

			istringstream read_node(node);
			string value1, value2;

			getline(read_node,value1,',');
			getline(read_node,value2,',');
			y = atoi(value1.c_str());
			z = atoi(value2.c_str());
			
			graph[x][y] = z;
		}
		cout << endl;
	}

	for(int i=1;i<SIZE;i++){
		for (int j=1;j<SIZE;j++){
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

}