class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int result = 0;

        for (std::size_t i = 1; i < prices.size(); ++i) {
            result = std::max(result, prices[i] - min);
            min = std::min(min, prices[i]);
        }

        return result;
    }
};
