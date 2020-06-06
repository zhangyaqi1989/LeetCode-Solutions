class ZigzagIterator {
    vector<int> v1, v2;
    int n1, n2;
    int i1, i2;
    int cnt;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        this->v1 = v1;
        this->v2 = v2;
        this->n1 = v1.size();
        this->n2 = v2.size();
        this->i1 = 0;
        this->i2 = 0;
        this->cnt = 0;
        
    }

    int next() {
        int val;
        if (this->cnt % 2 == 0) {
            if (this->i1 < this->n1) {
                val = this->v1[this->i1++];
            } else {
                val = this->v2[this->i2++];
            }
        } else {
            if (this->i2 < this->n2) {
                val = this->v2[this->i2++];
            } else {
                val = this->v1[this->i1++];
            }
        }
        ++this->cnt;
        return val;
    }

    bool hasNext() {
        return this->cnt < (this->n1 + this->n2);
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
