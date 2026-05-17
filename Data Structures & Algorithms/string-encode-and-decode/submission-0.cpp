class Solution {
public:
    string encode(vector<string>& strs) {
        std::string result = "";
        for (const auto& item : strs) {
            result += std::to_string(item.size()) + '-' + item;
        }
        return result;
    }

    vector<string> decode(string s) {
        std::vector<std::string> result;
        std::string size = "";

        for (std::size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '-') {
                ++i;
                result.push_back(s.substr(i, std::stoi(size)));
                i += std::stoi(size) - 1;
                size = "";
                continue;
            }
            size += s[i];
        }

        return result;
    }
};
