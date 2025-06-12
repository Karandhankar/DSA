class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
    for (int i = 0; i < relations.size(); i++) {
        adj[relations[i][0] - 1].push_back(relations[i][1] - 1);
    }

    // Kahn's algorithm: compute in-degrees
    vector<int> InDeg(n, 0);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < adj[i].size(); j++)
            InDeg[adj[i][j]]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (!InDeg[i])
            q.push(i);

    // Maximum time to complete previous course
    vector<int> CourseTime(n, 0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int j = 0; j < adj[node].size(); j++) {
            int next = adj[node][j];

            InDeg[next]--;
            if (!InDeg[next])
                q.push(next);

            // Correct max logic:
            CourseTime[next] = max(CourseTime[next], CourseTime[node] + time[node]);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, CourseTime[i] + time[i]);
    }

    return ans;
        
    }
};