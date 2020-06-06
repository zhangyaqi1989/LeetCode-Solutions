class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = INT_MIN;
        stack<int> stack;
        for(auto num : preorder)
        {
            if(num <= low) return false;
            while (!stack.empty() && num > stack.top())
            {
                low = stack.top();
                stack.pop();
            }
            stack.push(num);
        }
        return true;
    }
};