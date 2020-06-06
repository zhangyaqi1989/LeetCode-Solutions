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
        int ans = 0;
        unordered_map<int, Employee *> people;
        for(auto & employee : employees) people[employee->id] = employee;
        dfs(people, ans, id);
        
        return ans;
    }
    
    void dfs(unordered_map<int, Employee *> & people, int & ans, int id) {
        ans += people[id]->importance;
        for(auto subordinate : people[id]->subordinates) dfs(people, ans, subordinate);
    }
};
