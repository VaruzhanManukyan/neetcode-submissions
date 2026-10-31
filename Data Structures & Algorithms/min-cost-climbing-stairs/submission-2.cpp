class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        std::size_t size = cost.size();
        std::vector<int> dp(size + 1, 0);
        
        dp[0] = 0;
        dp[1] = 0; 

        for (std::size_t i = 2; i <= size; ++i) {
            dp[i] = std::min(
                dp[i - 1] + cost[i - 1], 
                dp[i - 2] + cost[i - 2]
            );
        }

        return dp[size];
    }
};
