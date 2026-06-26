class Solution {
private:
    int rob_count(const std::vector<int>& nums, int left, int right) {
        int prev1 = 0, prev2 = 0, current = 0;

        for (int i = left; i < right; ++i) {
            current = std::max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = current;
        }

        return current;
    }
public:
    int rob(vector<int>& nums) {
        int size = static_cast<int>(nums.size());

        if (size == 1) {
            return nums[0];
        }

        return std::max (
            rob_count(nums, 0, size - 1),
            rob_count(nums, 1, size)
        );
    }
};
