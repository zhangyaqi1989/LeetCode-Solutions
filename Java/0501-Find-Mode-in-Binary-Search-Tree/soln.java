/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int[] findMode(TreeNode root) {
        TreeNode cur = root;
        Stack<TreeNode> stk = new Stack<>();
        List<Integer> modes = new ArrayList<>();
        int mx_cnt = 0;
        int cur_num = 0, cur_cnt = 0;
        while(cur != null || !stk.isEmpty()) {
            while(cur != null) {
                stk.push(cur);
                cur = cur.left;
            }
            cur = stk.pop();
            // System.out.println(cur.val);
            if (cur.val != cur_num) {
                if (cur_cnt > mx_cnt) {
                    mx_cnt = cur_cnt;
                    modes.clear();
                    modes.add(cur_num);
                } else if (mx_cnt != 0 && cur_cnt == mx_cnt) {
                    modes.add(cur_num);
                }
                cur_num = cur.val;
                cur_cnt = 1;
            } else {
                ++cur_cnt;
            }
            cur = cur.right;
        }
        if (cur_cnt > mx_cnt) {
            mx_cnt = cur_cnt;
            modes.clear();
            modes.add(cur_num);
        } else if (mx_cnt != 0 && cur_cnt == mx_cnt) {
            modes.add(cur_num);
        }
        int [] ans = new int [modes.size()];
        for(int i = 0; i < modes.size(); ++i) {
            ans[i] = modes.get(i);
        }
        return ans;
    }
}
