class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxiProfit = 0;
        
        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxiProfit = max(maxiProfit, price - minPrice);
        }
        
        return maxiProfit;
    }
};