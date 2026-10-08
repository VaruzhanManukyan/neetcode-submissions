class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> set_;
        for (auto& num : nums) {
            if (!set_.contains(num)) {
                set_.insert(num);
                continue;
            }
            return true;
        }
        return false;
    }
};