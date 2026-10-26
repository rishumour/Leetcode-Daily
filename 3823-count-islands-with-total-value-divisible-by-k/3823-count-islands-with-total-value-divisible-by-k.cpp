class Solution {
    long long dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] <= 0) {
            return 0;
        }
        
        long long val = grid[r][c];
        grid[r][c] = 0;
        
        val += dfs(grid, r + 1, c);
        val += dfs(grid, r - 1, c);
        val += dfs(grid, r, c + 1);
        val += dfs(grid, r, c - 1);
        
        return val;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] > 0) {
                    if (dfs(grid, r, c) % k == 0) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};