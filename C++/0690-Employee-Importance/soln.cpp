/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee *> m;
        for(auto employee_ptr : employees) {
            m[employee_ptr->id] = employee_ptr;
        }
        int ans = 0;
        stack<int> s;
        s.push(id);
        while (s.size()) {
            id = s.top();
            s.pop();
            ans += m[id]->importance;
            for(auto nei : m[id]->subordinates)
                s.push(nei);
        }
        return ans;
    }
};