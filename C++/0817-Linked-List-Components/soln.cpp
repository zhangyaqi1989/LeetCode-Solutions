/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
const int N = 10000;

int parents[10000] = {0};

int find(int x) {
    return parents[x] == x ? x : parents[x] = find(parents[x]);
}

void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx != ry) parents[rx] = parents[ry];
}

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        for(int i = 0; i < N; ++i) parents[i] = i;
        set<int> Gs(G.begin(), G.end());
        while (head->next != nullptr) {
            int v1 = head->val, v2 = head->next->val;
            if (Gs.find(v1) != Gs.end() && Gs.find(v2) != Gs.end())
                unite(v1, v2);
            head = head->next;
        }
        set<int> ans;
        for(int num : G) {
            ans.insert(find(num));
        }
        return ans.size();
        
    }
};
