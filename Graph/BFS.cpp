#include<iostream>
#include<queue>
#include<vector>
#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
void createAdjancencyList(vector<int> adj[],vector<pair<int,int>> &edges)
{
     for(int i=0;i<edges.size();i++){
         adj[edges[i].first].push_back(edges[i].second);
         adj[edges[i].second].push_back(edges[i].first);
     }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> bfs;
    vector<int> adj[vertex];
    createAdjancencyList(adj,edges);
    queue<int> vertex_queue;
    int visited[vertex]={0};
    vertex_queue.push(0);
    visited[0] = 1;
    int v;
    while(!vertex_queue.empty()){
        v = vertex_queue.front();
        vertex_queue.pop();
        bfs.push_back(v);
        sort(adj[v].begin(),adj[v].end());
        for(int i=0;i<adj[v].size();i++)
        {
            if(visited[adj[v][i]]!=1){
                vertex_queue.push(adj[v][i]);
                visited[adj[v][i]] = 1;
            }   
                
        }
    }
    for(int i=0;i<vertex;i++)
    {
        if(visited[i]!=1){
            bfs.push_back(i);
            visited[i]=1;
        }     
    }
    return bfs;
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
    vector<int> bfs = BFS(v,edges);
    for(int i=0;i<bfs.size();i++)
    {
        cout<<bfs[i]<<' ';
    }
    return 0;
}