//Finding and printing all paths between two vertices in a connected graph.
//Using dfs

#include<iostream>
#include<vector>
#include<list>

using namespace std;

class Graph
{
	vector<list<int>> adj_list;
	vector<int> visited;
	vector<int> path;
	int n;

	public:
	
	Graph(int);
	void show_paths(int,int);
	void add_edges();
	void show_adj();
};

Graph::Graph(int n)
{
	this->n=n;
	adj_list.resize(n);
	visited.resize(n,false);
	for(int i=0;i<n;i++)
		adj_list[i].push_back(i);
}

void Graph::show_paths(int u,int v)
{
	visited[u]=true;
	path.push_back(u);
	if(u==v)
	{
		for(auto it:path)
		{
			if(it==u)
				cout<<it<<endl;
			else
				cout<<it<<"->";
		}
	}
	else
	{
		for(auto it:adj_list[u])
			if(!visited[it])
				show_paths(it,v);
	}

	path.pop_back();
	visited[u]=false;
}

void Graph::add_edges()
{
	int src,dest;
	cout<<"Enter source (-1 to end)- ";
       	cin>>src;
	while(src!=-1)
	{
		cout<<"Enter all destinations of vertex "<<src<<"(-1 to finish)- ";
		cin>>dest;
		while(dest!=-1)
		{
			adj_list[src].push_back(dest);
			adj_list[dest].push_back(src);
			cin>>dest;
		}
		cout<<"Enter source (-1 to end)- ";
		cin>>src;
	}
}

void Graph::show_adj()
{
	for(auto it:adj_list)
	{
		for(auto it2:it)
			if(it2==it.front())
				cout<<it2<<"->";
			else
				cout<<it2<<" ";
		cout<<endl;
	}
}


int main()
{
	int n,src,dest;
	cout<<"Enter the number of vertices: ";
	cin>>n;

	Graph graph(n);
	graph.add_edges();
	system("clear");

	cout<<"Adjacency list for the given graph: "<<endl;
	graph.show_adj();

	cout<<"\nEnter the source and destination vertices to show all paths: ";
	cin>>src>>dest;
	cout<<"\nAll paths between vertex "<<src<<" and "<<dest<<" are: "<<endl;
	graph.show_paths(src,dest);
	
	return 0;
}
