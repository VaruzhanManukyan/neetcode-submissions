class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> map;

        for (int num : nums) {
            if (!map.insert(num).second) {
                return true;
            }
        }
        
        return false;
    }
};