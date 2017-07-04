#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Node{
	int NO;
	Node* neighbors;
	Node(){
		NO = -1;
		neighbors = NULL;
	}
	Node(int no, Node* next=NULL){
		NO = no;
		neighbors = next;
	}
};

void BFS(const Node* graph[], int nodeNum){
	if(graph==NULL || nodeNum<=0) return;
	bool visited[nodeNum];
	memset(visited, false, sizeof(visited));
	queue<int> q;
	q.push(0); // Start BFS in node 0
	visited[0] = true;
	while(!q.empty()){
		int recNO = q.front();
		q.pop();
		cout << recNO << " ";
		// Search all neighbors of recNO
		Node* neighborsList = graph[recNO]->neighbors;
		while(neighborsList != NULL){
			if(!visited[neighborsList->NO]){
				q.push(neighborsList->NO);
				visited[neighborsList->NO] = true;
			}			
			neighborsList = neighborsList->neighbors;
		}
	}
	cout << endl;
}

int main(){
	// Construct a graph with 8 nodes just like the graph in 
	// http://blog.csdn.net/Jingle_cjy/article/details/72566269
	const Node* nodes[8]; 
	// Allocate memory
	nodes[0] = new Node(0, new Node(1)); // NODE a
	nodes[1] = new Node(1, new Node(2, new Node(4, new Node(5)))); // NODE b
	nodes[2] = new Node(2, new Node(3, new Node(6))); // NODE c
	nodes[3] = new Node(3, new Node(2, new Node(7))); // NODE d
	nodes[4] = new Node(4, new Node(0, new Node(5))); // NODE e
	nodes[5] = new Node(5, new Node(6)); // NODE f
	nodes[6] = new Node(6, new Node(5, new Node(7))); // NODE g
	nodes[7] = new Node(7, new Node(7)); // NODE h 
	BFS(nodes, 8);
	
	return 0;
} 
