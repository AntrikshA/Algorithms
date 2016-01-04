// Minimum Cut Problem

#include "iostream"
#include "fstream"
#include "sstream"
#include "cstring"
#include "cstdlib"

using namespace std;

#define INPUT_FILE "kargerMinCut.txt"

class node{
private:
	int value;
	node* ptr;
public:
	node(){}
	
	int setData(int val){
		value=val;
	}
	int setNext(node* nextptr){
		ptr = nextptr;
	}
	int Data(){
		return value;
	}
	node* pointer(){
		return ptr;
	}

};

class list{

public:
	node *head;
	list(){}

	void append(int val){

		node* newNode = new node();
	    newNode->setData(val);
	    newNode->setNext(NULL);

		node* tmp=head;

		if(tmp!=NULL){
			while(tmp->pointer()!=NULL){
				tmp = tmp->pointer();
			}
			tmp->setNext(newNode);
		}
		else{
			head = newNode;
		}

	}

	void Delete(int val){
		
		node* tmp=head;

		if(tmp==NULL)
			return;
		else if(tmp->pointer()==NULL){
			delete tmp;
		}
		else{
			node *prev;
			do{
				if(tmp->Data()==val){
					prev = tmp;
					tmp = tmp->pointer();
				}
			}while(tmp->pointer()!=NULL);
			
			prev->setNext(tmp->pointer());
			delete tmp;	
		}
	}

	void Print() {
		node *tmp = head;

	    if ( tmp == NULL ) {
		    cout << "EMPTY" << endl;
		    return;
	    }

	    if ( tmp->pointer() == NULL ) {
		    cout << tmp->Data();
		    cout << " --> ";
		    cout << "NULL" << endl;
	    }
	    else {
		    do {
		        cout << tmp->Data();
		        cout << " --> ";
		        tmp = tmp->pointer();
		    }while ( tmp != NULL );

	    	cout << "NULL" << endl;
	    }
	}

};


class graph{
private:
	list *array;
	int SIZE;
public:
	graph(){}

	void createGraph(int V)
	{
	    // graph *first = (graph*) malloc(sizeof(graph*));
	    this->SIZE = V;
	 
	    this->array = (list*) malloc(V * sizeof(list));
	 
	    int i;
	    for (i = 0; i <= V; ++i)
	        this->array[i].head = NULL;
	 
	}
	 
	void addEdge(int src, int dest)
	{
	    node* newNode = new node();
	    newNode->setData(dest);
	    newNode->setNext(this->array[src].head);
	    this->array[src].head = newNode;
		/*
	    node* newNode = new node();
	    newNode->setData(src);
	    newNode->setNext(this->array[dest].head);
	    this->array[dest].head = newNode;*/
	}
	 
	void printGraph()
	{
	    int v;
	    for (v = 0; v <= this->SIZE; ++v)
	    {
	        node* pCrawl = this->array[v].head;
	        cout << v << " --> ";
	        while (pCrawl)
	        {
	            cout << pCrawl->Data() << " --> ";
	            pCrawl = pCrawl->pointer();
	        }
	        cout << "NULL" <<  endl;
	    }
	    // cout << "NULL";
	}

};

int main(){
	ifstream file(INPUT_FILE);

	string line;

	graph first;
	first.createGraph(200);

	while(getline(file,line)){
		
		string cell;
		istringstream line_stream(line);
		int i=0;
		while(getline(line_stream,cell,'\t')){
			int values[200];
			values[i++] = atoi(cell.c_str());
			first.addEdge(values[0],values[i-1]);
		}
	}

	first.printGraph();


}
