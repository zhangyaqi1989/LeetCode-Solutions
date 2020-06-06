
class Solution {
public:
  int lastStoneWeightII(vector<int>& stones) {
      unordered_set<int> dp;
      dp.insert(0);
      for(int stone : stones) {
          unordered_set<int> temp;
          for(int item : dp) {
              temp.insert(stone + item);
              temp.insert(stone - item);
          }
          swap(temp, dp);
      }
      int ans = INT_MAX;
      for(int item : dp) ans = min(ans, abs(item));
      return ans;
  }
};
