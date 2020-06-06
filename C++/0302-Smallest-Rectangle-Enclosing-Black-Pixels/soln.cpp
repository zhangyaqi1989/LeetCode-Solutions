class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        // the black pixel is connected
        // determine left, right, top, bottom
        // last empty col
        int left = binarySearch(0, y, image, colContainsOne);
        int right = binarySearch(y, image[0].size(), image, colContainsNoOne);
        int top = binarySearch(0, x, image, rowContainsOne);
        int bottom = binarySearch(x, image.size(), image, rowContainsNoOne);
        return (right - left) * (bottom - top);
        
    }
    
private:
    static bool colContainsOne(vector<vector<char>> & image, int col) {
        int m = image.size(), n = image[0].size();
        for(int i = 0; i < m; ++i) 
            if (image[i][col] == '1') return true;
        return false;
    }
    
    static bool colContainsNoOne(vector<vector<char>> & image, int col) {
        int m = image.size(), n = image[0].size();
        for(int i = 0; i < m; ++i) 
            if (image[i][col] == '1') return false;
        return true;
    }
    
    
    static bool rowContainsOne(vector<vector<char>> & image, int row) {
        int m = image.size(), n = image[0].size();
        for(int j = 0; j < n; ++j) 
            if (image[row][j] == '1') return true;
        return false;
    }
    
    static bool rowContainsNoOne(vector<vector<char>> & image, int row) {
        int m = image.size(), n = image[0].size();
        for(int j = 0; j < n; ++j) 
            if (image[row][j] == '1') return false;
        return true;
    }
    
    int binarySearch(int lo, int hi, vector<vector<char>> & image,  bool (* valid) (vector<vector<char>> &, int)) {
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            // cout << mid << " " << valid(image, mid) << endl;
            if (valid(image, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};
