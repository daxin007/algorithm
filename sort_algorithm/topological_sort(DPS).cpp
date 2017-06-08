#include <iostream>
#include <cstring>
#include <list>
#include <queue>
using namespace std;

/**
 * graph: adjacency matrix represented DAG
 * nodeNum: the number of nodes of graph
**/
void topological_sort(list<int>* previousNodes, queue<int>& res, int nodeNum);
void DFS(list<int>* previousNodes, queue<int>& q, bool* visited, int node);

int main(){
	int nodesNum = 9;
	list<int> previousNodes[nodesNum];
	previousNodes[2].push_back(4); // 4->2
	previousNodes[2].push_back(8); // 8->2
	previousNodes[3].push_back(4); // 4->3
	previousNodes[6].push_back(1); // 1->6
	previousNodes[6].push_back(5); // 5->6
	previousNodes[6].push_back(8); // 8->6
	previousNodes[7].push_back(2); // 2->7
	previousNodes[7].push_back(3); // 3->7
	previousNodes[8].push_back(1); // 1->8
	queue<int> result;
	topological_sort(previousNodes, result, nodesNum);
	while(!result.empty()){
		cout << result.front() << " ";
		result.pop();
	}
	cout << endl; 
	
	return 0;
}

void topological_sort(list<int>* previousNodes, queue<int>& res, int nodeNum){
	if(previousNodes==NULL || nodeNum<=0) return;
	bool visited[nodeNum];
	memset(visited, false, sizeof(visited));
	for(int i=0; i<nodeNum; i++)
		DFS(previousNodes, res, visited, i);
}

void DFS(list<int>* previousNodes, queue<int>& q, bool* visited, int node){
	if(previousNodes==NULL || visited==NULL || node<=0 || visited[node]) return;
	visited[node] = true;
	list<int>::iterator iter;
	for(iter=previousNodes[node].begin(); iter!=previousNodes[node].end(); iter++){
		if(!visited[*iter])
			DFS(previousNodes, q, visited, *iter);
	}
	q.push(node);
}
