//Given an undirected Graph, check for a cycle using BFS (Breadth-First Search) Traversal.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool hasCycle(vector<int> adj[],int vertex,int starting_node){
    int visited[vertex]={0};
    visited[starting_node] = 1;
    queue<int> nodes;
    nodes.push(starting_node);
    while(!nodes.empty()){
        int v = nodes.front();
        nodes.pop();
        for(int i=0;i<adj[v].size();i++){
            if(adj[v][i] == nodes.back())
                return true;
            if(visited[adj[v][i]] != 1)
            {
                visited[adj[v][i]] = 1;
                nodes.push(adj[v][i]);
            }
        }
    }
    for(int i=0;i<vertex;i++){
        if(visited[i]!=1){
            return hasCycle(adj,vertex,i);
        }
    }
    return false;
}
void createAdjancencyList(vector<int> adj[],vector<pair<int,int>> &edges)
{
     for(int i=0;i<edges.size();i++){
         adj[edges[i].first].push_back(edges[i].second);
         adj[edges[i].second].push_back(edges[i].first);
     }
}
int main(){
    int v,e;
    cout<<"enter no of vertex and edges"<<endl;
    cin>>v>>e;
    vector<pair<int,int>> edges;
    pair<int,int> edge;
    cout<<"enter edges"<<endl;
    for(int i=0;i<e;i++)
    {
        cin>>edge.first>>edge.second;
        edges.push_back(edge);
    }
    vector<int> adj[v];
    createAdjancencyList(adj,edges);
    cout<<"Graph has cycle?: "<<hasCycle(adj,v,0);
}