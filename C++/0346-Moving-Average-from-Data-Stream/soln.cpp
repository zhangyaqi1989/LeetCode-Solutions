class MovingAverage {
    double sum;
    queue<int> window;
    int size;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size): size(size){
        sum = 0.0;
    }
    
    double next(int val) {
        sum += val;
        window.push(val);
        if (window.size() > size) {
            sum -= window.front();
            window.pop();
        }
        return sum / window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
