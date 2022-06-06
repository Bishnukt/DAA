// Prim's Algorithm to find Minimum weighted spanning tree from a undirected weighted connected graph.

#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node
{
	int key = 0;
	int weight = 0;
};

class Graph
{

	vector<list<Node*>> adj_list;
	vector<list<Node*>> span_tree;
	vector<bool> visited;
	vector<int> weights;
	vector<int> parent;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	int n;

public:
	Graph(int n)
	{
		this->n = n;
		adj_list.resize(n);
		span_tree.resize(n);
		parent.resize(n,0);
		visited.resize(n, false);
		weights.resize(n,INT_MAX);
		for (int i = 0; i < n; i++)
		{
			Node *temp = new Node();
			temp->key = i;
			adj_list[i].push_back(temp);
			span_tree[i].push_back(temp);
		}
	}

	void add_edge(int src, int dest, int weight)
	{
		Node *temp = new Node();
		temp->key = dest;
		temp->weight = weight;
		adj_list[src].push_back(temp);

		Node *temp2 = new Node();
		temp2->key = src;
		temp2->weight = weight;
		adj_list[dest].push_back(temp2);
	}

	void add_properties();

	void show_adj()
	{
		for (auto it : adj_list)
		{
			for (auto it2 : it)
				if (it.front() == it2)
					cout << it2->key << "->"
						 << " ";
				else
					cout << it2->key << "[" << it2->weight << "]"
						 << " ";
			cout << endl;
		}
	}

	void disp_span_tree(int vertex)
	{
		weights[vertex]=0;
		parent[vertex]=-1;
		visited[vertex] = true;
		prims_algo(vertex);
		for (auto it : span_tree)
		{
			for (auto it2 : it)
				if (it2 == it.front())
					cout << it2->key << "->"
						 << " ";
				else
					cout << it2->key << "[" << it2->weight << "]"
						 << " ";
			cout << endl;
		}
	}

	void prims_algo(int vertex)
	{
		Node *next = find_next(vertex);
		int N=n-1;
		while(N>0)
		{
			if(!visited[next->key])
			{
				int par=parent[next->key];
				span_tree[par].push_back(next);
				visited[next->key]=true;
				next=find_next(next->key);
				N--;
			}
			else
				next=find_next();
		}

	}

	Node *find_next(int vertex=-1)
	{
		if(vertex!=-1)
		{
		for(auto it:adj_list[vertex])
		{
			if(!visited[it->key] && it->weight<weights[it->key])
			{
				pq.push({it->weight,it->key});
				weights[it->key]=it->weight;
				parent[it->key]=vertex;
			}
		}
		}
		Node *temp=new Node();
		temp->weight=pq.top().first;
		temp->key=pq.top().second;
		pq.pop();
		return temp;
	}
};

void Graph::add_properties()
{
	int src, dest, weight;
	cout << "Enter Source(Enter -1 to end): ";
	cin >> src;
	while (src != -1)
	{
		cout << "Enter all destinations and weights from vertex " << src << "(Enter -1 to finish): ";
		cin >> dest;
		while (dest != -1)
		{
			cin >> weight;
			add_edge(src, dest, weight);
			cin >> dest;
		}
		cout << "Enter Source(Enter -1 to end): ";
		cin >> src;
	}
}

int main()
{
	int n, start;
	cout << "Enter the number of vertices: ";
	cin >> n;

	Graph graph(n);
	cout << "Enter edges and weights-" << endl;
	graph.add_properties();

	cout << "\nAdjacency List for given graph: " << endl;
	graph.show_adj();

	cout << "\nEnter the starting vertex for Minimum weighted spanning tree: ";
	cin >> start;

	cout << "\nAdjacency List for minimum weighted spanning tree for the given graph using Prim's Algorithm:" << endl;
	graph.disp_span_tree(start);

	return 0;
}


/*
Output:

Enter the number of vertices: 7
Enter edges and weights-
Enter Source(Enter -1 to end): 0
Enter all destinations and weights from vertex 0(Enter -1 to finish): 2 2 1 5 -1
Enter Source(Enter -1 to end): 1
Enter all destinations and weights from vertex 1(Enter -1 to finish): 4 6 3 7 -1
Enter Source(Enter -1 to end): 2
Enter all destinations and weights from vertex 2(Enter -1 to finish): 6 3 5 4 -1
Enter Source(Enter -1 to end): 3
Enter all destinations and weights from vertex 3(Enter -1 to finish): 5 3 4 8 -1
Enter Source(Enter -1 to end): 5
Enter all destinations and weights from vertex 5(Enter -1 to finish): 6 11 -1
Enter Source(Enter -1 to end): -1

Adjacency List for given graph:
0-> 2[2] 1[5]
1-> 0[5] 4[6] 3[7]
2-> 0[2] 6[3] 5[4]
3-> 1[7] 5[3] 4[8]
4-> 1[6] 3[8]
5-> 2[4] 3[3] 6[11]
6-> 2[3] 5[11]

Enter the starting vertex for Minimum weighted spanning tree: 0

Adjacency List for minimum weighted spanning tree for the given graph using Prim's Algorithm:
0-> 2[2] 1[5]
1-> 4[6]
2-> 6[3] 5[4]
3->
4->
5-> 3[3]
6->

*/
