class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> counts(k, 0);
        set<int> available;
        
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;
        
        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            long long t = arrival[i];
            long long l = load[i];
            
            while (!busy.empty() && busy.top().first <= t) {
                available.insert(busy.top().second);
                busy.pop();
            }
            
            if (available.empty()) {
                continue;
            }
            
            int target = i % k;
            auto it = available.lower_bound(target);
            
            if (it == available.end()) {
                it = available.begin();
            }
            
            int server = *it;
            available.erase(it);
            busy.emplace(t + l, server);
            counts[server]++;
        }
        
        int max_req = *max_element(counts.begin(), counts.end());
        vector<int> ans;
        
        for (int i = 0; i < k; ++i) {
            if (counts[i] == max_req) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};