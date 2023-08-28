# User function Template for python3

from typing import List
from queue import Queue


class Solution:
    # Function to return Breadth First Traversal of given graph.
    def bfsOfGraph(self, V: int, adj: List[List[int]]) -> List[int]:
        # code here
        que = Queue()
        visited = [0] * V
        bfs = list()
        que.put(0)
        visited[0] = 1
        while not que.empty():
            element = que.get()
            bfs.append(element)
            for ele in adj[element]:
                if visited[ele] == 0:
                    que.put(ele)
                    visited[ele] = 1
        return bfs


# {
# Driver Code Starts


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        V, E = map(int, input().split())
        adj = [[] for i in range(V)]
        for _ in range(E):
            u, v = map(int, input().split())
            adj[u].append(v)
        ob = Solution()
        ans = ob.bfsOfGraph(V, adj)
        for i in range(len(ans)):
            print(ans[i], end=" ")
        print()

# } Driver Code Ends