class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> row_masks;
        
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            
            if (col >= 2 && col <= 9) {
                row_masks[row] |= (1 << col);
            }
        }
        
        int max_families = (n - row_masks.size()) * 2;
        
        int left   = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5); 
        int middle = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7); 
        int right  = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9); 
        
        for (const auto& [row, mask] : row_masks) {
            if ((mask & left) == 0 && (mask & right) == 0) {
                max_families += 2;
            } 
            else if ((mask & left) == 0 || (mask & right) == 0 || (mask & middle) == 0) {
                max_families += 1;
            }
        }
        
        return max_families;
    }
};