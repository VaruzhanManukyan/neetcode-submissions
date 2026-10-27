class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = 0;
        std::size_t size = prices.size();
    
        for (int i = 0; i < size; ++i) {
            max_profit = std::max(max_profit, prices[i] - min_price);
            min_price = std::min(min_price, prices[i]);
        }

        return max_profit;
    }
};
