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
	vector<bool> visited;

	public:
	Graph(int val)
	{
		n=val;
		adj_list.resize(n);
		for(int i=0;i<n;i++)
			adj_list[i].push_back(i);
		visited.resize(n,false);
	}
	
	void add_edge(int src,int dest)
	{
		adj_list[src].push_back(dest);
//		adj_list[dest].push_back(src);
	}

	void bfs(int vertex)
	{
	//	if(!visited[vertex])
	//	{
	//		cout<<adj_list[vertex].front()<<" ";
	//		visited[vertex]=true;
	//	}

		for(auto it:adj_list[vertex])
		{
			if(!visited[it])
			{
				cout<<it<<" ";
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

	void display()
	{
		cout<<"The adjacency list for given graph: "<<endl;
		for(int i=0;i<n;i++)
		{
			for(auto it:adj_list[i])
				cout<<it<<" ";
			cout<<endl;
		}
	}

//	void display()
//	{
//		cout<<"The adjacency list for the graph given is : \n"<<endl;
//		for(auto it:adj_list)
//		{
//			for(auto it2:adj_list[it])
//				cout<<it2<<" ";
//			cout<<endl;
//		}
//
//	}


	
};
int main()
{
	int n,src=0,dest=0,temp=0;
	cout<<"Enter the number of vertices: ";
	cin>>n;

	Graph graph(n);

	cout<<"Enter edges:\n";
	cout<<"Enter source(Enter -1 to end): ";
	cin>>src;	
	while(src!=-1)
	{
		cout<<"Enter all destinations of vertex "<<src<<":(Enter -1 to end)\n";
		cin>>dest;
		while(dest!=-1)
		{
			graph.add_edge(src,dest);
			cin>>dest;
		}

		cout<<"Enter Source: ";
		cin>>src;
	}
	graph.display();
	cout<<"Enter the starting vertex: ";
	cin>>temp;
	graph.bfs(temp);
	return 0;
}
