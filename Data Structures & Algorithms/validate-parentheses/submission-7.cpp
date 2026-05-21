class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack_;

        for (const char& c : s) {
            if (c == '[') {
                stack_.push(']');
            } else if (c == '(') {
                stack_.push(')');
            } else if (c == '{') {
                stack_.push('}');
            } else {
                if (stack_.empty() || stack_.top() != c) {
                    return false;
                }
                stack_.pop();
            }
        }
        return stack_.empty();
    }
};
