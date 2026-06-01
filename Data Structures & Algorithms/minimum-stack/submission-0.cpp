class MinStack {
    std::stack<int> stack_;
    std::stack<int> min_stack_;
public:
    MinStack() {}

    void push(int val) {
        stack_.push(val);

        if (min_stack_.empty() || val <= min_stack_.top()) {
            min_stack_.push(val);
        }
    }
    
    void pop() {
        if (stack_.top() == min_stack_.top()) {
            min_stack_.pop();
        }

        stack_.pop();
    }
    
    int top() {
        return stack_.top();
    }
    
    int getMin() {
        return min_stack_.top();
    }
};
