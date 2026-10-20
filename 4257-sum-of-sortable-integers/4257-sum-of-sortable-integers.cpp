class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefMax(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefMax[i + 1] = max(prefMax[i], nums[i]);
        }
        
        vector<int> suffMin(n + 1, 1e9);
        for (int i = n - 1; i >= 0; --i) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }
        
        vector<int> prefDrop(n, 0);
        for (int i = 1; i < n; ++i) {
            prefDrop[i] = prefDrop[i - 1] + (nums[i - 1] > nums[i] ? 1 : 0);
        }
        
        int ans = 0;
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;
            
            bool ok = true;
            for (int i = k; i < n; i += k) {
                if (prefMax[i] > suffMin[i]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;
            
            for (int i = 0; i < n; i += k) {
                int drops = prefDrop[i + k - 1] - prefDrop[i];
                int wrap = (nums[i + k - 1] > nums[i]) ? 1 : 0;
                if (drops + wrap > 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans += k;
            }
        }
        
        return ans;
    }
};