# User function Template for python3

class Solution:

    def DFS(self, V, adj, visited, dfs, current_node):
        visited[current_node] = 1
        dfs.append(current_node)
        for ele in adj[current_node]:
            if visited[ele] == 0:
                self.DFS(V, adj, visited, dfs, ele)

    # Function to return a list containing the DFS traversal of the graph.
    def dfsOfGraph(self, V, adj):
        # code here
        visited = [0] * V
        dfs = list()
        self.DFS(V, adj, visited, dfs, 0)
        return dfs


# {
# Driver Code Starts

if __name__ == '__main__':
    T = int(input())
    while T > 0:
        V, E = map(int, input().split())
        adj = [[] for i in range(V + 1)]
        for i in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
            adj[v].append(u)
        ob = Solution()
        ans = ob.dfsOfGraph(V, adj)
        for i in range(len(ans)):
            print(ans[i], end=" ")
        print()
        T -= 1
# } Driver Code Ends