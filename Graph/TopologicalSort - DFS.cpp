// topological sort using DFS
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void topologicalSort(vector<int> adj[],int node,stack<int> &s,int visited[]){
    visited[node] = 1;
    for(auto it: adj[node]){
        if(visited[it]!=1){
            topologicalSort(adj,it,s,visited);
        }
    }
    s.push(node);
}
void DFS(vector<int> adj[],int vertex){
    int visited[vertex] = {0};
    stack<int> s;
    for(int i=0;i<vertex;i++){
        if(visited[i]!=1){
            topologicalSort(adj,i,s,visited);
        }
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
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
    DFS(adj,vertex);

}
   