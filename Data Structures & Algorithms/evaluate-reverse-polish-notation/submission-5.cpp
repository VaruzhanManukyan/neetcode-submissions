class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack_;

        for (const std::string& token : tokens) {
            if (token == "+") {
                int right = stack_.top();
                stack_.pop();
                int left = stack_.top();
                stack_.pop();
                
                stack_.push(left + right);
            } else if (token == "-") {
                int right = stack_.top();
                stack_.pop();
                int left = stack_.top();
                stack_.pop();
                
                stack_.push(left - right);
            } else if (token == "*") {
                int right = stack_.top();
                stack_.pop();
                int left = stack_.top();
                stack_.pop();
                
                stack_.push(left * right);
            } else if (token == "/") {
                int right = stack_.top();
                stack_.pop();
                int left = stack_.top();
                stack_.pop();
                
                stack_.push(left / right);
            } else {
                stack_.push(std::stoi(token));
            }
        }

        return stack_.top();
    }
};
