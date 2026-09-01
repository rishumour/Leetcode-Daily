class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> visited(n, false);
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int v_count = 0;
                int degree_sum = 0;
                vector<int> q;
                q.push_back(i);
                visited[i] = true;
                
                int head = 0;
                while (head < q.size()) {
                    int u = q[head++];
                    v_count++;
                    degree_sum += adj[u].size();
                    
                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push_back(v);
                        }
                    }
                }
                
                if (degree_sum == v_count * (v_count - 1)) {
                    ans++;
                }
            }
        }
        
        return ans;
    }
};