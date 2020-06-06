typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef long long ll;
#define REP(i,a,b) for (int i = a; i < b; i++)
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowZero = false, colZero = false;
        int m = sz(matrix), n = sz(matrix[0]);
        REP(i,0,m) {
            if (matrix[i][0] == 0) colZero = true;
        }
        REP(j,0,n) {
            if (matrix[0][j] == 0) rowZero = true;
        }
        REP(i,1,m) {
            REP(j,1,n) {
                if(matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        
        REP(i,1,m) {
            REP(j,1,n) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }
        // cout << rowZero << " " << colZero << endl;
        if(rowZero) {
            REP(j,0,n) matrix[0][j] = 0;
        }
        if (colZero) {
            REP(i,0,m) matrix[i][0] = 0;
        }
    }
};
