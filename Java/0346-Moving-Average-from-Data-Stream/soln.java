class MovingAverage {
    Queue<Integer> window;
    int size;
    double sum;

    /** Initialize your data structure here. */
    public MovingAverage(int size) {
        sum = 0.0;
        this.size = size;
        window = new LinkedList<>();
    }
    
    public double next(int val) {
        sum += val;
        window.add(val);
        if (window.size() > size) {
            sum -= window.poll();
        }
        return sum / window.size();
    }
}

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
