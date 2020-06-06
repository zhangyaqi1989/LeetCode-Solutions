class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        int direction = 2;
        for(int i = 0; i < n; ++i) {
            int j = (i + 1) % n;
            int k = (i + 2) % n;
            vector<int> A = points[i], B = points[j], C = points[k];
            int temp = ccw(A, B, C);
            if (direction == 2 && temp != 0) {
                direction = temp;
            } else {
                if (temp != 0 && direction != temp)
                    return false;
            }
        }
        return true;
    }
    
    int ccw(vector<int> & A, vector<int> & B, vector<int> & C) {
        int Ax = A[0], Ay = A[1], Bx = B[0], By = B[1], Cx = C[0], Cy = C[1];
        int ABx = Bx - Ax, ABy = By - Ay;
        int ACx = Cx - Ax, ACy = Cy - Ay;
        int cross = ABx * ACy - ABy * ACx;
        if (cross > 0) return 1;
        else if (cross < 0) return -1;
        else return 0;
    }
};
