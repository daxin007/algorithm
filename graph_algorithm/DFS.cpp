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

void DFS(const Node* graph[], int nodeNum);
void DFS_VISIT(const Node* graph[], int nodeNum, int recNode, bool* visited);

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
	
	DFS(nodes, 8);
	
	return 0;
}

void DFS(const Node* graph[], int nodeNum){
	if(graph==NULL || nodeNum<=0) return;
	bool visited[nodeNum];
	memset(visited, false, sizeof(visited));
	for(int i=0; i<nodeNum; i++){
		if(!visited[i]) DFS_VISIT(graph, nodeNum, i, visited);
	}
	 
	cout << endl;
}

void DFS_VISIT(const Node* graph[], int nodeNum, int recNode, bool* visited){
	if(graph==NULL || nodeNum<=0 || recNode>=nodeNum) return;
	if(visited[recNode]) return;
	cout << recNode << " ";
	visited[recNode] = true;
	Node* neighborsList = graph[recNode]->neighbors;
	while(neighborsList != NULL){
		if(!visited[neighborsList->NO])
			DFS_VISIT(graph, nodeNum, neighborsList->NO, visited);
		neighborsList = neighborsList->neighbors;
	}
} 
