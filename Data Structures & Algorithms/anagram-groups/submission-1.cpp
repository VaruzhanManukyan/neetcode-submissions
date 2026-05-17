class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, std::vector<std::string>> maps;
        for(std::size_t i = 0; i < strs.size(); ++i) {
            std::string key = strs[i];
            std::sort(key.begin(), key.end());
            maps[key].push_back(strs[i]);
        }

        std::vector<std::vector<string>> result;
        for(const auto& item : maps) {
            result.push_back(item.second);
        }

        return result;
    }
};
