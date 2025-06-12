class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, int src, int dest, vector<bool>& visited)
    {
        visited[src] = true;

        if(src == dest)
        {
            return true;
        }

        bool isReachable = false;
        for(auto &adjNode : adj[src])
        {
            if(!visited[adjNode])
            {
                isReachable = isReachable || dfs(adj, adjNode, dest, visited);
            }
        }
        return isReachable;
    }

    void preProcess(int n, unordered_map<int, vector<int>>& adj, vector<vector<bool>>& grid)
    {
        for(int u=0; u<n; u++)
        {
            for(int v=0; v<n; v++)
            {
                if(u != v){
                    vector<bool> visited(n, false);
                    if(dfs(adj, u, v, visited) == true)
                    {
                        grid[u][v] = true;
                    }
                }
            }
        }
    }


    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;

        for(auto &edge : prerequisites)
        {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        //Preprocessing
        vector<vector<bool>> grid(numCourses, vector<bool>(numCourses, false));

        preProcess(numCourses, adj, grid);

        int Q = queries.size();
        vector<bool> result(Q);

        for(int i=0; i<Q; i++)
        {
            int u = queries[i][0]; //source
            int v = queries[i][1]; //dest

            result[i] = grid[u][v];
            
        }
        return result;
    }
};