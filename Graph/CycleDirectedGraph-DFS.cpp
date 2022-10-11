// detect cycle in directed graph
#include<iostream>
#include<vector>
using namespace std;

bool hasCycle(vector<int> adj[],int visited[],int node,int parent,int vertex){
    if(visited[node] == 1)
        return true;
    visited[node] = 1;
    for(int i=0;i<adj[node].size();i++){
        if(hasCycle(adj,visited,adj[node][i],node,vertex))
            return true;
        hasCycle(adj,visited,adj[node][i],node,vertex);
    }
    return false;
}

bool DFSCycle(vector<int> adj[],int vertex){
    int visited[vertex] = {0};
    if(hasCycle(adj,visited,0,0,vertex))
        return true;
    for(int i=0;i<vertex;i++){
        if(visited[i]!=1)
            if(hasCycle(adj,visited,i,i,vertex))
                return true;
            hasCycle(adj,visited,i,i,vertex);
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
    int visited[vertex] = {0};
    cout<<"has cycle?: "<<DFSCycle(adj,vertex);
}