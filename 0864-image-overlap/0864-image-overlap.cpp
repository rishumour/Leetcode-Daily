class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> points1, points2;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) points1.push_back({i, j});
                if (img2[i][j] == 1) points2.push_back({i, j});
            }
        }
        
        vector<vector<int>> count(2 * n + 1, vector<int>(2 * n + 1, 0));
        int max_overlap = 0;
        
        for (auto& p1 : points1) {
            for (auto& p2 : points2) {
                int dx = p1.first - p2.first + n;
                int dy = p1.second - p2.second + n;
                count[dx][dy]++;
                max_overlap = max(max_overlap, count[dx][dy]);
            }
        }
        
        return max_overlap;
    }
};