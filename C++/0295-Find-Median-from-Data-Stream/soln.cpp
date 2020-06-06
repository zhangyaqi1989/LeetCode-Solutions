class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        upper_.push(num);
        int t = upper_.top();
        upper_.pop();
        lower_.push(t);
        if (lower_.size() > upper_.size() + 1) {
            t = lower_.top();
            lower_.pop();
            upper_.push(t);
        }
    }
    
    double findMedian() {
        if (lower_.size() > upper_.size()) {
            return lower_.top();
        } else {
            return 0.5 * (lower_.top() + upper_.top());
        }
    }
private:
    priority_queue<int> lower_;
    priority_queue<int, vector<int>, greater<int>> upper_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
