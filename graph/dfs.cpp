#include<iostream>
#include<vector>
#include<list>
using namespace std;

void add_edge(vector<list<int>> &,int,int);
void dfs(int,vector<list<int>> &);
void display(vector<list<int>> &);
int v;
vector<bool> visited;
int main()
{
	int src,dest,temp;
	cout<<"Enter no. of vertices: ";
	cin>>v;
	//vector<bool> visited(v,false);
	visited.resize(v,false);
	vector<list<int>> vertices(v);
	for(int i=0;i<v;i++)
		vertices[i].push_back(i);
	cout<<"Enter edges:(Press -1 to end)"<<endl;
	cout<<"Enter source vertex: ";
	cin>>src;
	while(src!=-1)
	{
		cout<<"Enter all destination of vertex "<<src<<" (Enter -1 to end):"<<endl;
		cin>>dest;
		while(dest!=-1)
		{
			add_edge(vertices,src,dest);
			cin>>dest;
		}
		cout<<"Enter source vertex:(Enter -1 to end)"<<endl;
		cin>>src;
	}
	cout<<"The adjacency list for given matrix:"<<endl;
	display(vertices);
	cout<<"Enter the starting vertex for dfs traversal: ";
	cin>>temp;
	dfs(temp,vertices);
	return 0;
}

void add_edge(vector<list<int>> &adj_list,int src,int dest)
{
	adj_list[src].push_back(dest);
	//adj_list[dest].push_back(src);
}

void dfs(int vertex,vector<list<int>> &graph)
{
	cout<<vertex<<" ";
	visited[vertex]=true;
	for(auto it:graph[vertex])
	{
		if(!visited[it])
			dfs(it,graph);
	}
}

void display(vector<list<int>> &list)
{
	for(int i=0;i<v;i++)
	{
		for(auto it:list[i])
			cout<<it<<" ";
		cout<<endl;
	}
}
