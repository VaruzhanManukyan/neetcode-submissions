class Solution {
public:
    int rob(vector<int>& nums) {
        std::size_t size = nums.size();

        if (size == 0) {
            return 0;
        }
        if (size == 1) {
            return nums[0];
        }

        std::vector<int> dp(size + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];
        
        for (std::size_t i = 2; i <= size; ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }

        return dp[size];
    }
};
