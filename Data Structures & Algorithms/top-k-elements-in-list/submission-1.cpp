class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> maps;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            maps[nums[i]]++;
        }

        std::priority_queue<std::pair<int, int>> pq;
        for (const auto& item : maps) {
            pq.push({item.second, item.first});
        }

        std::vector<int> result;
        for(std::size_t i = 0; i < k; ++i) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};
