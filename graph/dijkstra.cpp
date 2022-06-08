#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Node
{
    int key = 0;
    int wt = 0;
};

class Graph
{

    vector<list<Node *>> adj_list;
    vector<bool> visited;
    vector<int> weight;
    vector<int> parent;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    void add_edge(int, int, int);
    void show_path(int);
    Node *relax(int vertex = -1);
    int n;

public:
    Graph(int);
    void add_properties();
    void show_adj();
    void shortest_path(int, int);
    void dijkstra(int, int);
};

Graph::Graph(int n)
{
    this->n = n;
    adj_list.resize(n);
    parent.resize(n, 0);
    visited.resize(n, false);
    weight.resize(n, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node();
        temp->key = i;
        adj_list[i].push_back(temp);
    }
}

void Graph::add_properties()
{
    int src, dest, wt;
    cout << "Enter Source(Enter -1 to end): ";
    cin >> src;
    while (src != -1)
    {
        cout << "Enter all destinations and weight from vertex " << src << "(Enter -1 to finish): ";
        cin >> dest;
        while (dest != -1)
        {
            cin >> wt;
            add_edge(src, dest, wt);
            cin >> dest;
        }
        cout << "Enter Source(Enter -1 to end): ";
        cin >> src;
    }
}

void Graph::add_edge(int src, int dest, int wt)
{
    Node *temp = new Node();
    temp->key = dest;
    temp->wt = wt;
    adj_list[src].push_back(temp);

    Node *temp2 = new Node();
    temp2->key = src;
    temp2->wt = wt;
    adj_list[dest].push_back(temp2);
}

void Graph::show_adj()
{
    for (auto it : adj_list)
    {
        for (auto it2 : it)
            if (it.front() == it2)
                cout << it2->key << "->"
                     << " ";
            else
                cout << it2->key << "[" << it2->wt << "]"
                     << " ";
        cout << endl;
    }
}

void Graph::shortest_path(int u, int v)
{
    if (u >= 0 && u < n)
    {
        if (v >= 0 && v <= n)
        {
            parent[u] = -1;
            visited[u] = true;
            weight[u] = 0;
            dijkstra(u, v);
        }
        else
        {
            cout << "Destination vertex out of boundary." << endl;
            return;
        }
    }
    else
    {
        cout << "Source vertex out of boundary." << endl;
        return;
    }

    show_path(v);
    cout << "\nCost- " << weight[v] << endl;

    cout << "Costs of shortest path between all the vertices from vertex " << u << ": " << endl;
    for (int i = 0; i < n; i++)
        cout << i << "--" << weight[i] << endl;
}

void Graph::show_path(int v)
{
    if (parent[v] == -1)
    {
        cout << v;
        return;
    }

    show_path(parent[v]);
    cout << "->" << v;
}

void Graph::dijkstra(int u, int v)
{
    //    if (u != v)
    //    {
    int N = n - 1;
    while (N > 0)
    {
        Node *next = relax(u);
        while (visited[next->key])
            next = relax();
        visited[next->key] = true;
        //    dijkstra(next->key, v);
        u = next->key;
        N--;
    }
}

Node *Graph::relax(int vertex)
{
    if (vertex != -1)
    {
        for (auto it : adj_list[vertex])
        {
            int tmp_wt = weight[vertex] + it->wt;
            if (!visited[it->key] && tmp_wt < weight[it->key])
            {
                parent[it->key] = vertex;
                weight[it->key] = tmp_wt;
                pq.push({weight[it->key], it->key});
            }
        }
    }

    Node *temp = new Node();
    temp->wt = pq.top().first;
    temp->key = pq.top().second;
    pq.pop();
    return temp;
}

int main()
{
    int n, src, dest;
    cout << "Enter the number of vertices: ";
    cin >> n;

    Graph graph(n);

    graph.add_properties();
    system("clear");

    cout << "Adjacency list for the given graph with weights: " << endl;
    graph.show_adj();

    cout << "\nEnter the source and destination vertex to find the shortest path: ";
    cin >> src >> dest;

    cout << "\nShortest Path between " << src << " and " << dest << "-" << endl;
    graph.shortest_path(src, dest);

    return 0;
}
