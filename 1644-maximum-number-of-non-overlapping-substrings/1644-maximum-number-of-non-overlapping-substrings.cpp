class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> L(26, -1), R(26, -1);
        
        for (int i = 0; i < n; ++i) {
            if (L[s[i] - 'a'] == -1) L[s[i] - 'a'] = i;
            R[s[i] - 'a'] = i;
        }
        
        auto getRight = [&](int i) -> int {
            int right = R[s[i] - 'a'];
            for (int j = i; j <= right; ++j) {
                if (L[s[j] - 'a'] < i) return -1;
                right = max(right, R[s[j] - 'a']);
            }
            return right;
        };
        
        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; ++i) {
            if (L[i] != -1) {
                int right = getRight(L[i]);
                if (right != -1) {
                    intervals.push_back({L[i], right});
                }
            }
        }
        
        sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.second != b.second) return a.second < b.second;
            return (a.second - a.first) < (b.second - b.first);
        });
        
        vector<string> res;
        int last_end = -1;
        for (auto& interval : intervals) {
            if (interval.first > last_end) {
                res.push_back(s.substr(interval.first, interval.second - interval.first + 1));
                last_end = interval.second;
            }
        }
        
        return res;
    }
};