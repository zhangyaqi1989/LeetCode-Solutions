class MaxStack {
    stack<int> s;
    stack<int> mxs;
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if (mxs.empty() || x > mxs.top()) mxs.push(x);
        else mxs.push(mxs.top());
    }
    
    int pop() {
        int val = s.top();
        s.pop();
        mxs.pop();
        return val;
    }
    
    int top() {
       return s.top(); 
    }
    
    int peekMax() {
        int val = mxs.top();
        return val;
    }
    
    int popMax() {
        vector<int> temp;
        int val = mxs.top();
        while (s.top() != val) {
            temp.push_back(s.top());
            s.pop();
            mxs.pop();
        }
        s.pop();
        mxs.pop();
        for(auto it = temp.rbegin(); it != temp.rend(); ++it) {
            push(*it);
        }
        return val;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
