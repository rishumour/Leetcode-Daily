class Solution {
    int getDigitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);
        
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }
        
        sort(arr.begin(), arr.end(), [this](const pair<int, int>& a, const pair<int, int>& b) {
            int sumA = getDigitSum(a.first);
            int sumB = getDigitSum(b.first);
            if (sumA == sumB) {
                return a.first < b.first;
            }
            return sumA < sumB;
        });
        
        vector<bool> visited(n, false);
        int swaps = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] || arr[i].second == i) {
                continue;
            }
            
            int cycle_size = 0;
            int j = i;
            
            while (!visited[j]) {
                visited[j] = true;
                j = arr[j].second;
                cycle_size++;
            }
            
            if (cycle_size > 1) {
                swaps += (cycle_size - 1);
            }
        }
        
        return swaps;
    }
};