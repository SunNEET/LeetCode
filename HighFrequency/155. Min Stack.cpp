class MinStack {
private:
    stack<int> s1; // 正常出入 stack
    stack<int> s2; // 用來存目前當作最小值的val, 當該val從s1被pop時就跟著pop掉
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s2.empty()||x<=getMin())
            s2.push(x);
    }
    
    void pop() {
        int cur = top();
        s1.pop();
        if(cur == getMin()) 
            s2.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top(); 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */