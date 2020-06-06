auto desyncio = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ans;
        for(auto email : emails) ans.insert(encode(email));
        return ans.size();
    }
    
    string encode(string email) {
        int idx = email.find('@');
        string local = email.substr(0, idx);
        string domain = email.substr(idx);
        local.erase(remove(local.begin(), local.end(), '.'), local.end());
        idx = local.find('+');
        if(idx != string::npos) local = local.substr(0, idx);
        return local + domain;
    }
};
