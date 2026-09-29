class Solution {
int m, n;
    vector<vector<vector<int>>> memo;

    bool dfs(int r, int c, int bal, const vector<vector<char>>& grid) {
        bal += (grid[r][c] == '(' ? 1 : -1);
        
        if (bal < 0 || bal > (m + n - 1) / 2) {
            return false;
        }
        
        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }
        
        if (memo[r][c][bal] != -1) {
            return memo[r][c][bal];
        }
        
        bool res = false;
        if (r + 1 < m) {
            res = res || dfs(r + 1, c, bal, grid);
        }
        if (!res && c + 1 < n) {
            res = res || dfs(r, c + 1, bal, grid);
        }
        
        return memo[r][c][bal] = res;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        if ((m + n - 1) % 2 != 0) {
            return false;
        }
        
        memo.assign(m, vector<vector<int>>(n, vector<int>((m + n) / 2 + 1, -1)));
        
        return dfs(0, 0, 0, grid);   
    }
};