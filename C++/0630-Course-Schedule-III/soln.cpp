class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // [100, 200], [200, 1300], [1000, 1250] ...
        sort(courses.begin(), courses.end(), [](const vector<int> & a, const vector<int> & b) 
             {return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];});
        int cur = 0;
        priority_queue<int> pq;
        for(const auto & course : courses) {
            int e = course[1];
            cur += course[0];
            pq.push(course[0]);
            while (cur > e) {
                cur -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
