class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> counts(3, 0);
        for (int stone : stones) {
            counts[stone % 3]++;
        }
        if (counts[0] % 2 == 0) {
            return counts[1] > 0 && counts[2] > 0;
        } 
        else {
            return abs(counts[1] - counts[2]) > 2;
        }
    }
};