class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> maps;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (maps.find(nums[i]) == maps.end()) {
                maps.insert({target - nums[i], i});
                continue;
            } 
            return {maps[nums[i]], static_cast<int>(i)};
        }
        return {-1, -1};
    }
};
