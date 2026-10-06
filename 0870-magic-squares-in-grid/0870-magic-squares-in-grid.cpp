class Solution {
bool isMagic(const vector<vector<int>>& grid, int r, int c) {
        if (grid[r + 1][c + 1] != 5) {
            return false;
        }
        
        int mask = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int val = grid[r + i][c + j];
                if (val < 1 || val > 9) return false;
                mask |= (1 << val);
            }
        }
        
        if (mask != 0x3FE) {
            return false;
        }
        
        if (grid[r][c] + grid[r][c + 1] + grid[r][c + 2] != 15) return false;
        if (grid[r + 2][c] + grid[r + 2][c + 1] + grid[r + 2][c + 2] != 15) return false;
        if (grid[r][c] + grid[r + 1][c] + grid[r + 2][c] != 15) return false;
        if (grid[r][c + 2] + grid[r + 1][c + 2] + grid[r + 2][c + 2] != 15) return false;
        
        if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != 15) return false;
        if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != 15) return false;
        
        return true;
    }
    
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m < 3) return 0;
        int n = grid[0].size();
        if (n < 3) return 0;
        
        int count = 0;
        for (int r = 0; r <= m - 3; ++r) {
            for (int c = 0; c <= n - 3; ++c) {
                if (isMagic(grid, r, c)) {
                    count++;
                }
            }
        }
        
        return count;
    }
};