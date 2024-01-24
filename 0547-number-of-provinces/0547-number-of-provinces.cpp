
class Solution {
private:
    void dfs(int node, vector<int> adjls[], int visited[]) {
        visited[node] = 1;
        for (auto it : adjls[node]) {
            if (!visited[it]) {
                dfs(it, adjls, visited);//recursion call for each node
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adjls[V];
// changing ajacency matrix to adjacency list
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (isConnected[i][j] && i != j) {
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }

        vector<int> visited(V, 0);
        int count = 0;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                count++;
                dfs(i, adjls, visited.data());  //calling dfs and pass the data() of the vector to get the underlying array
            }
        }

        return count;
    }
};