class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::size_t size = temperatures.size();
        std::stack<int> stack_;
        std::vector<int> result(size, 0);

        for(int i = 0; i < size; ++i) {
            while (!stack_.empty() && temperatures[i] > temperatures[stack_.top()]) {
                int previous = stack_.top();
                stack_.pop();
                result[previous] = i - previous;
            }
            stack_.push(i);
        }

        return result;
    }
};
