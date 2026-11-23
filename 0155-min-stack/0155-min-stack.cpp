class MinStack {
public:
    std::vector<std::pair<int, int>> stack;
    
    MinStack() {
        stack.reserve(30000);
    }
    
    void push(int value) {
        int curMin = stack.empty() ? value : std::min(stack.back().second, value);
        stack.push_back({value, curMin});
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        return stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */