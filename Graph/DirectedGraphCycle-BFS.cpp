// detect cycle in directed graph using BFS
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool hasCycle(vector<int> adj[],int vertex,int starting_vertex){
    int visited[vertex] = {0};
    queue<int> nodes;
    nodes.push(starting_vertex);
    visited[starting_vertex] = 1;
    while(!nodes.empty()){
        int v= nodes.front();
        nodes.pop();
        for(int i=0;i<adj[v].size();i++){
            if(visited[adj[v][i]]==1)
                return true;
            visited[adj[v][i]] = 1;
            nodes.push(adj[v][i]);
        }
    }
    for(int i=0;i<vertex;i++){
        if(visited[i]!=1){
            if(hasCycle(adj,vertex,i))
                return true;
            hasCycle(adj,vertex,i);
        }
    }
    return false;
}

void createAdjancencyList(vector<int> adj[],vector<pair<int,int>> &edges)
{
     for(int i=0;i<edges.size();i++){
         adj[edges[i].first].push_back(edges[i].second);
     }
}
int main()
{
    cout<<"enter no of vertex and edges"<<endl;
    int vertex,e;
    cin>>vertex>>e;
    vector<int> adj[vertex];
    vector<pair<int,int>> edges;
    pair<int,int> edge;
    cout<<"enter edges"<<endl;
    for(int i=0;i<e;i++)
    {
        cin>>edge.first>>edge.second;
        edges.push_back(edge);
    }
    createAdjancencyList(adj,edges);
    cout<<"has cycle?: "<<hasCycle(adj,vertex,0);
}