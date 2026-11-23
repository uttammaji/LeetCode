class MinStack {
private:
    stack<long long> s;
    long long minVal;

public:
    MinStack() {}

    void push(int val) {
        long long v = val;
        if (s.empty()) {
            minVal = v;
            s.push(v);
        } else if (v < minVal) {
            // Store encoded value and update minVal
            s.push(2LL * v - minVal);
            minVal = v;
        } else {
            s.push(v);
        }
    }

    void pop() {
        if (s.top() < minVal) {
            // Decode and restore the previous minimum
            minVal = 2LL * minVal - s.top();
        }
        s.pop();
    }

    int top() {
        if (s.top() < minVal) {
            // Actual top value is the current minVal
            return (int)minVal;
        }
        return (int)s.top();
    }

    int getMin() {
        return (int)minVal;
    }
};
