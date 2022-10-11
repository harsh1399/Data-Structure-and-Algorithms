// Topological sort for directed acyclic sort using BFS

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<int> topoSort(vector<int> adj[],int vertex){
    vector<int> toposorted;
    int indegree[vertex]={0};
    queue<int> nodes; 
    for(int i=0;i<vertex;i++){
        for(int j=0;j<adj[i].size();j++){
            indegree[adj[i][j]]++;
        }
    }
    for(int i=0;i<vertex;i++){
        if(indegree[i] == 0)
            nodes.push(i);
    }
    while(!nodes.empty()){
        int val = nodes.front();
        nodes.pop();
        toposorted.push_back(val);
        for(auto it: adj[val]){
            indegree[it]--;
            if(indegree[it]==0)
                nodes.push(it);
        }
    }
    return toposorted;
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
    cout<<"topo sort: ";
    vector<int> sorted = topoSort(adj,vertex);
    for(int i=0;i<vertex;i++){
        cout<<sorted[i]<<" ";
    }
    
}