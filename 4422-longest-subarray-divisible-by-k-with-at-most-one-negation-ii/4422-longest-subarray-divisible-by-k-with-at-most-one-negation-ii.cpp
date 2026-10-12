class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        
        vector<int> first(k, -1);
        vector<int> last(k, -1);
        
        first[0] = 0;
        last[0] = 0;
        
        for (int i = 0; i < n; ++i) {
            int rem = nums[i] % k;
            if (rem < 0) rem += k;
            
            pref[i + 1] = (pref[i] + rem) % k;
            
            if (first[pref[i + 1]] == -1) {
                first[pref[i + 1]] = i + 1;
            }
            last[pref[i + 1]] = i + 1;
        }
        
        int ans = 0;
        for (int x = 0; x < k; ++x) {
            if (first[x] != -1) {
                ans = max(ans, last[x] - first[x]);
            }
        }
        
        vector<int> earliest(k, 1e9);
        
        for (int i = n - 1; i >= 0; --i) {
            int rem = nums[i] % k;
            if (rem < 0) rem += k;
            int d = (2 * rem) % k;
            
            earliest[d] = i;
            
            int x = pref[i];
            if (i == first[x]) {
                for (int cd = 0; cd < k; ++cd) {
                    if (earliest[cd] != 1e9) {
                        int y = (x + cd) % k;
                        if (last[y] != -1 && earliest[cd] < last[y]) {
                            ans = max(ans, last[y] - i);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};