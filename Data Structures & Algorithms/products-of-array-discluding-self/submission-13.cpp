class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long number = 1;
        int count = 0;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++count;
                continue;
            }
            number *= nums[i];
        }

        std::vector<int> result(nums.size(), 0);
        if (count > 1) {
            return result;
        }

        if (count == 1) {
            for (std::size_t i = 0; i < nums.size(); ++i) {
                if (nums[i] == 0) {
                    result[i] = number;
                }
            }
        } else {
            for (std::size_t i = 0; i < nums.size(); ++i) {
                result[i] = number / nums[i];
            } 
        }

        return result;
    }
};
