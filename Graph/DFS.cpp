#include<iostream>
#include<vector>
using namespace std;
void createAdjancencyList(vector<int> adj[],vector<pair<int,int>> &edges)
{
     for(int i=0;i<edges.size();i++){
         adj[edges[i].first].push_back(edges[i].second);
         adj[edges[i].second].push_back(edges[i].first);
     }
}

void DFS(vector<int> adj[],int visited[],int node,vector<int> &dfs){
    if(adj[node].size() == 0)
        return;
    dfs.push_back(node);
    for(int i=0;i<adj[node].size();i++){
        if(visited[adj[node][i]]!=1){
            visited[adj[node][i]] =1;
            DFS(adj,visited,adj[node][i],dfs);
        }
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
    int visited[vertex]={0};
    visited[0] = 1;
    vector<int> dfs;
    DFS(adj,visited,0,dfs);
    for(int i=0;i<dfs.size();i++){
        cout<<dfs[i]<<" ";
    }
    
}