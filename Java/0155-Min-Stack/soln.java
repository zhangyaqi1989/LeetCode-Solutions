class MinStack {
    
    private Stack<Integer> nums;
    private Stack<Integer> mins;

    /** initialize your data structure here. */
    public MinStack() {
        nums = new Stack<>();
        mins = new Stack<>();
    }
    
    public void push(int x) {
        nums.push(x);
        if (mins.isEmpty()) mins.push(x);
        else mins.push(Math.min(x, mins.peek()));
    }
    
    public void pop() {
        nums.pop();
        mins.pop();
    }
    
    public int top() {
        return nums.peek();
    }
    
    public int getMin() {
        return mins.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
