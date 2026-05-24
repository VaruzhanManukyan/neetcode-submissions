class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int> stack_;

        for (const std::string& token : tokens) {
            if (token == "+") {
                int right = stack_.back();
                stack_.pop_back();
                int left = stack_.back();
                stack_.pop_back();
                
                stack_.push_back(left + right);
            } else if (token == "-") {
                int right = stack_.back();
                stack_.pop_back();
                int left = stack_.back();
                stack_.pop_back();
                
                stack_.push_back(left - right);
            } else if (token == "*") {
                int right = stack_.back();
                stack_.pop_back();
                int left = stack_.back();
                stack_.pop_back();
                
                stack_.push_back(left * right);
            } else if (token == "/") {
                int right = stack_.back();
                stack_.pop_back();
                int left = stack_.back();
                stack_.pop_back();
                
                stack_.push_back(left / right);
            } else {
                stack_.push_back(std::stoi(token));
            }
        }

        return stack_.back();
    }
};
