class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int start_x = -1, start_y = -1;
        int litter_count = 0;
        vector<vector<int>> litter_id(m, vector<int>(n, -1));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    start_x = i;
                    start_y = j;
                } else if (classroom[i][j] == 'L') {
                    litter_id[i][j] = litter_count++;
                }
            }
        }
        
        if (litter_count == 0) return 0;
        
        int target_mask = (1 << litter_count) - 1;
        vector<vector<vector<char>>> visited(m, vector<vector<char>>(n, vector<char>(1 << litter_count, -1)));
        
        queue<tuple<int, int, int, int>> q;
        q.push({start_x, start_y, energy, 0});
        visited[start_x][start_y][0] = energy;
        
        int moves = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz-- > 0) {
                auto [x, y, e, mask] = q.front();
                q.pop();
                
                if (mask == target_mask) return moves;
                
                if (e == 0) continue;
                
                for (auto& d : dirs) {
                    int nx = x + d[0];
                    int ny = y + d[1];
                    
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (classroom[nx][ny] == 'X') continue;
                    
                    int nxt_e = e - 1;
                    int nxt_mask = mask;
                    
                    if (classroom[nx][ny] == 'R') {
                        nxt_e = energy;
                    } else if (classroom[nx][ny] == 'L') {
                        nxt_mask |= (1 << litter_id[nx][ny]);
                    }
                    
                    if (nxt_e > visited[nx][ny][nxt_mask]) {
                        visited[nx][ny][nxt_mask] = nxt_e;
                        q.push({nx, ny, nxt_e, nxt_mask});
                    }
                }
            }
            moves++;
        }
        
        return -1;
    }
};