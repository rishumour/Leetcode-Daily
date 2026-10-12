class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
       long long sum_source = 0;
        long long sum_target = 0;
        
        for (int x : source) {
            sum_source += x;
        }
        
        for (int x : target) {
            sum_target += x;
        }
        
        return sum_source == sum_target;
    }
};