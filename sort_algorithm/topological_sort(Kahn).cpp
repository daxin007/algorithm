#include <iostream>
#include <cstring>
#include <list>
#include <vector>
#include <queue>
using namespace std;

/**
 * graph: adjacency matrix represented DAG
 * nodeNum: the number of nodes of graph
**/
vector<int> topological_sort(list<int>* graph, int nodeNum){
	vector<int> res;
	if(graph==NULL || nodeNum<=0) return res;
	
	// 0. Get in-degree of every node
	list<int>::iterator iter;
	int inDegree[nodeNum];
	memset(inDegree, 0, sizeof(inDegree));
	for(int node=0; node<nodeNum; node++)
		for(iter=graph[node].begin(); iter!=graph[node].end(); iter++)
			inDegree[*iter]++;
	
	// 1. Collect vertices which in-degree is 0
	queue<int> q;
	for(int u=0; u<nodeNum; u++)
		if(inDegree[u] == 0) q.push(u);

	// 2. Choose node V from q
	//    Delete node V and the corresponding edges 
	int count = 0; // The number of vertices in sorted set
	while(!q.empty()){
		int v = q.front();
		res.push_back(v);
		q.pop();
		count++;
		for(iter=graph[v].begin(); iter!=graph[v].end(); iter++){
			if(--inDegree[*iter]==0)
				q.push(*iter);
		}
	}
	if(count != nodeNum){
		cout << "NOT DAG!!" << endl; 
	}
	return res;
}

int main(){
	int nodesNum = 9;
	list<int> graph[nodesNum];
	graph[1].push_back(6);
	graph[1].push_back(8);
	graph[2].push_back(7);
	graph[3].push_back(7);
	graph[4].push_back(2);
	graph[4].push_back(3);
	graph[5].push_back(6);
	graph[8].push_back(2);
	graph[8].push_back(6);
	vector<int> result = topological_sort(graph, nodesNum);
	for(int i=0; i<result.size(); i++) cout << result[i] << " ";
	cout << endl; 
	
	return 0;
}
