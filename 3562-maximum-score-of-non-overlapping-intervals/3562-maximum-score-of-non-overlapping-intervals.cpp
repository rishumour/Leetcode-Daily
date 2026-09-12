class Solution {
    struct State {
        long long weight = -1;
        vector<int> selected;
    };

    struct Interval {
        int l, r, w, id;
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals_input) {
        int n = intervals_input.size();
        vector<Interval> intervals(n);
        
        for (int i = 0; i < n; ++i) {
            intervals[i] = {intervals_input[i][0], intervals_input[i][1], intervals_input[i][2], i};
        }
        
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            if (a.l != b.l) return a.l < b.l;
            return a.r < b.r;
        });
        
        vector<vector<State>> memo(n, vector<State>(5));
        
        auto dp = [&](auto& self, int i, int k) -> State {
            if (k == 0 || i == n) {
                return {0, {}};
            }
            if (memo[i][k].weight != -1) {
                return memo[i][k];
            }
            
            State skip = self(self, i + 1, k);
            
            int left = i + 1, right = n;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (intervals[mid].l > intervals[i].r) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            
            State pick = self(self, left, k - 1);
            pick.weight += intervals[i].w;
            pick.selected.push_back(intervals[i].id);
            
            sort(pick.selected.begin(), pick.selected.end());
            
            if (pick.weight > skip.weight) {
                return memo[i][k] = pick;
            } else if (pick.weight == skip.weight) {
                if (pick.selected < skip.selected) {
                    return memo[i][k] = pick;
                } else {
                    return memo[i][k] = skip;
                }
            } else {
                return memo[i][k] = skip;
            }
        };
        
        State result = dp(dp, 0, 4);
        return result.selected;
    }
};