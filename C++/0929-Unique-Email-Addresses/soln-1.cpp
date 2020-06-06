class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> uniques;
        for(string & email : emails) {
            int i = email.find('@');
            string local = email.substr(0, i), rest = email.substr(i);
            string temp = "";
            for(char ch : local) {
                if (ch == '.') continue;
                else if (ch == '+') break;
                else temp += ch;
            }
            uniques.insert(temp + rest);
        }
        return uniques.size();
    }
};
