class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int size = nums.size();
        std::vector<int> ans;
        ans.resize(size + size);

        for (int i = 0; i < size; ++i) {
            ans[i] = nums[i];
            ans[i + nums.size()] = nums[i];
        }

        return ans;
    }
};