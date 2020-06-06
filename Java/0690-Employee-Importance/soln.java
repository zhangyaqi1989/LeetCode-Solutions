/*
// Employee info
class Employee {
    // It's the unique id of each node;
    // unique id of this employee
    public int id;
    // the importance value of this employee
    public int importance;
    // the id of direct subordinates
    public List<Integer> subordinates;
};
*/
class Solution {
    public int score = 0;
    public int getImportance(List<Employee> employees, int id) {
        score = 0;
        Map<Integer, Employee> people = new HashMap<>();
        for(Employee employee : employees) people.put(employee.id, employee);
        dfs(people, id);
        return score;
    }
    
    public void dfs(Map<Integer, Employee> people, int id) {
        score += people.get(id).importance;
        for(int subid : people.get(id).subordinates) dfs(people, subid);
    }
}
