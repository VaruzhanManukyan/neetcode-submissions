class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<std::string> stack_;

        for (const std::string& token : tokens) {
            if (token == "+") {
                int right = std::stoi(stack_.top());
                stack_.pop();
                int left = std::stoi(stack_.top());
                stack_.pop();
                
                stack_.push(std::to_string(left + right));
            } else if (token == "-") {
                int right = std::stoi(stack_.top());
                stack_.pop();
                int left = std::stoi(stack_.top());
                stack_.pop();
                
                stack_.push(std::to_string(left - right));
            } else if (token == "*") {
                int right = std::stoi(stack_.top());
                stack_.pop();
                int left = std::stoi(stack_.top());
                stack_.pop();
                
                stack_.push(std::to_string(left * right));
            } else if (token == "/") {
                int right = std::stoi(stack_.top());
                stack_.pop();
                int left = std::stoi(stack_.top());
                stack_.pop();
                
                stack_.push(std::to_string(left / right));
            } else {
                stack_.push(token);
            }
        }

        return std::stoi(stack_.top());
    }
};
