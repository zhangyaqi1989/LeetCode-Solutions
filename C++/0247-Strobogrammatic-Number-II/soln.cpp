class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
          // '11' '88' '00' '69' '96'
          vector<string> ans;
          if (n % 2 == 1) {
            ans.push_back("1");
            ans.push_back("8");
            ans.push_back("0");
            --n;
          } else {
            ans.push_back("");
          }
          string valids[5] = {"00", "11", "88", "69", "96"};
          while (n >= 2) {
            vector<string> temp;
            if (n > 2) {
              for(int i = 0; i < 5; ++i) {
                string pair = valids[i];
                for(string item : ans) temp.push_back(pair.substr(0, 1) + item + pair.substr(1));
              }
            } else {
              for(int i = 1; i < 5; ++i) {
                string pair = valids[i];
                for(string item : ans) temp.push_back(pair.substr(0, 1) + item + pair.substr(1));
              }
            }
            swap(temp, ans);
            n -= 2;
          }
          return ans;
    }
};
