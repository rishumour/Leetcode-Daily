class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        vector<vector<int>> groups;
        groups.push_back(nums);
        
        vector<int> power(15, 0);
        
        for (int i = 0; i < 15; ++i) {
            int bit = 14 - i;
            vector<vector<int>> new_groups;
            int power_val = 0;
            bool stopped = false;
            
            for (const auto& group : groups) {
                if (stopped) {
                    new_groups.push_back(group);
                } else {
                    vector<int> set_group;
                    vector<int> unset_group;
                    
                    for (int x : group) {
                        if ((x & (1 << bit)) != 0) {
                            set_group.push_back(x);
                        } else {
                            unset_group.push_back(x);
                        }
                    }
                    
                    if (unset_group.empty()) {
                        power_val += set_group.size();
                        new_groups.push_back(set_group);
                    } else if (set_group.empty()) {
                        stopped = true;
                        new_groups.push_back(unset_group);
                    } else {
                        power_val += set_group.size();
                        new_groups.push_back(set_group);
                        new_groups.push_back(unset_group);
                        stopped = true;
                    }
                }
            }
            
            power[i] = power_val;
            groups = move(new_groups);
        }
        
        return power;
    }
};