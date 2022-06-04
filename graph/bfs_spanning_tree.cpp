#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;

class Graph
{
	int n=0;
	deque<int> queue;
	vector<list<int>> adj_list;
	vector<list<int>> span_tree;
	vector<bool> visited;

	public:
	Graph(int val)
	{
		n=val;
		adj_list.resize(n);
		span_tree.resize(n);
		for(int i=0;i<n;i++)
		{
			adj_list[i].push_back(i);
			span_tree[i].push_back(i);
		}
		visited.resize(n,false);
	}
	
	void add_edges(int src,int dest)
	{
        	int src, dest;
        	cout << "Enter source vertex(Enter -1 to end): ";
        	cin >> src;
        	while (src != -1 && src < n)
        	{
            		cout << "Enter all destinations of vertex " << src << " (Enter -1 to finish): ";
            		cin >> dest;
            		while (dest != -1 && dest < n)
            		{
                		adj_list[src].push_back(dest);
               			cin >> dest;
            		}
            		cout << "Enter source vertex(Enter -1 to end): ";
           		cin >> src;
        	}
    	}

	void spanning_tree(int vertex)
	{
		bfs(vertex);
		for(auto it:span_tree)
		{
			for(auto it2:it)
				if(it.front()==it2)
					cout<<it2<<"->";
				else
					cout<<it2<<" ";
			cout<<endl;
		}
	}

	void bfs(int vertex)
	{
		for(auto it:adj_list[vertex])
		{
			if(!visited[it])
			{
				span_tree[vertex].push_back(it);
				queue.push_back(it);
				visited[it]=true;
			}
		}
		while(!queue.empty())
		{
			int temp=queue.front();
			queue.pop_front();
			bfs(temp);
		}

	}

	void show_adj()
	{
		cout<<"The adjacency list for given graph: "<<endl;
		for(int i=0;i<n;i++)
		{
			for(auto it:adj_list[i])
				if(it==adj_list[i].front())
					cout<<it<<"->";
				else 
					cout<<it<<" ";
			cout<<endl;
		}
	}

};
int main()
{
	int n,src=0,dest=0,temp=0;
	cout<<"Enter the number of vertices: ";
	cin>>n;

	Graph graph(n);

	cout<<"Enter edges:\n";
	graph.add_edges();

	graph.show_adj();
	
	cout<<"Enter the starting vertex for Spanning Tree: ";
	cin>>temp;

	cout<<"Adjacency list for a Spanning tree using BFS starting from vertex "<<temp<<":"<<endl;
	graph.spanning_tree(vertex);
	return 0;
}
