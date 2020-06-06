"""
# Employee info
class Employee:
    def __init__(self, id, importance, subordinates):
        # It's the unique id of each node.
        # unique id of this employee
        self.id = id
        # the importance value of this employee
        self.importance = importance
        # the id of direct subordinates
        self.subordinates = subordinates
"""
class Solution:
    def getImportance(self, employees, id):
        """
        :type employees: Employee
        :type id: int
        :rtype: int
        """
        d = {}
        for employee in employees:
            d[employee.id] = (employee.importance, employee.subordinates)
        stack = [id]
        ans = 0
        while stack:
            node = stack.pop()
            ans += d[node][0]
            for nei in d[node][1]:
                stack.append(nei)
        return ans