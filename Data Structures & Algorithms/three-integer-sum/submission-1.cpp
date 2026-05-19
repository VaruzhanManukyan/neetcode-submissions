class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        if (nums[0] > 0) {
            return {};
        }

        std::vector<std::vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int start = i + 1;
            int end = nums.size() - 1;
            while(end > start) {
                int sum = nums[i] + nums[start] + nums[end];

                if (sum > 0) {
                    --end;
                } else if (sum < 0) {
                    ++start;
                } else {
                    result.push_back({
                        nums[i],
                        nums[start],
                        nums[end]
                    });

                    ++start;
                    --end;

                    while(end > start && nums[start] == nums[start - 1]) {
                        ++start;
                    }  
                    while(end > start && nums[end] == nums[end + 1]) {
                        --end;
                    }
                }
            }
        }

        return result;
    }
};
