class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> map;
        std::size_t size = nums.size();

        for (std::size_t i = 0; i < size; ++i) {
            if (map.find(nums[i]) != map.end()) {
                return true;
            }
            map.emplace(nums[i], nums[i]);
        }
        
        return false;
    }
};