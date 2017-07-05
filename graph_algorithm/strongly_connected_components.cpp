#include <iostream>
#include <cstring>
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

void STRONGLY_CONNECTED_COMPONENTS(Node* graph[], int nodeNum);
void DFS_VISIT( Node* graph[], int nodeNum, int recNode, bool* visited, int &time, int* finishedTime, bool shown);
void DELETE_GRAPH(Node* graph[], int nodeNum);
void DELETE_LIST(Node* node);

int main(){
	// Construct a graph with 8 nodes just like the graph in 
	// http://blog.csdn.net/Jingle_cjy/article/details/72566269
	 Node* nodes[8]; 
	// Allocate memory
	nodes[0] = new Node(0, new Node(1)); // NODE a
	nodes[1] = new Node(1, new Node(2, new Node(4, new Node(5)))); // NODE b
	nodes[2] = new Node(2, new Node(3, new Node(6))); // NODE c
	nodes[3] = new Node(3, new Node(2, new Node(7))); // NODE d
	nodes[4] = new Node(4, new Node(0, new Node(5))); // NODE e
	nodes[5] = new Node(5, new Node(6)); // NODE f
	nodes[6] = new Node(6, new Node(5, new Node(7))); // NODE g
	nodes[7] = new Node(7, new Node(7)); // NODE h 
	
	STRONGLY_CONNECTED_COMPONENTS(nodes, 8);
	
	DELETE_GRAPH(nodes, 8);
	
	return 0;
}

void STRONGLY_CONNECTED_COMPONENTS( Node* graph[], int nodeNum){
	if(graph==NULL || nodeNum<=0) return;
	
	// The first DFS 
	bool visited[nodeNum];
	int finishedTime[nodeNum];
	int time=0;
	memset(visited, false, sizeof(visited));
	for(int i=0; i<nodeNum; i++){
		if(!visited[i]) DFS_VISIT(graph, nodeNum, i, visited, time, finishedTime, false);
	}
	
	// Construct the G^T
	 Node* graphT[nodeNum]; 
	 Node* tempNode1 = NULL;
	Node* tempNode2 = NULL;
	for(int i=0; i<nodeNum; i++){
		graphT[i] = new Node(i);
	}
	for(int i=0; i<nodeNum; i++){
		tempNode1 = graph[i]->neighbors;
		while(tempNode1 != NULL){
			tempNode2 = graphT[tempNode1->NO];
			while(tempNode2->neighbors != NULL) tempNode2 = tempNode2->neighbors;
			tempNode2->neighbors = new Node(i);
			tempNode1 = tempNode1->neighbors;
		}
	}
	
	// The second DFS
	memset(visited, false, sizeof(visited));
	time = 0;
	int finishedTime2[nodeNum];
	int shownNum=0, maxTime, maxIndex, componentsNum=1;
	while(shownNum<nodeNum){
		maxTime = 0;
		for(int i=0; i<nodeNum; i++){
			if(!visited[i] && finishedTime[i]>maxTime){
				maxTime = finishedTime[i];
				maxIndex = i;
			}
		}
		cout << "The " << componentsNum << " component: ";
		DFS_VISIT(graphT, nodeNum, maxIndex, visited, time, finishedTime2, true);
		cout << endl;
		componentsNum++;
		shownNum = nodeNum;
		for(int i=0; i<nodeNum; i++){
			if(!visited[i]) shownNum--;
		}
	}
	
	DELETE_GRAPH(graphT, nodeNum);
} 

void DFS_VISIT( Node* graph[], int nodeNum, int recNode, bool* visited, int &time, int* finishedTime, bool shown){
	if(graph==NULL || nodeNum<=0 || recNode>=nodeNum) return;
	if(visited[recNode]) return;
	time = time+1;
	if(shown) cout << recNode << " ";
	visited[recNode] = true;
	Node* neighborsList = graph[recNode]->neighbors;
	while(neighborsList != NULL){
		if(!visited[neighborsList->NO])
			DFS_VISIT(graph, nodeNum, neighborsList->NO, visited,  time, finishedTime, shown);
		neighborsList = neighborsList->neighbors;
	}
	finishedTime[recNode] = time;
}

void DELETE_GRAPH(Node* graph[], int nodeNum){
	for(int i=0; i<nodeNum; i++){
		DELETE_LIST(graph[i]);
	}
} 

void DELETE_LIST(Node* node){
	if(node->neighbors != NULL){
		DELETE_LIST(node->neighbors);
	}
	delete node;
}
