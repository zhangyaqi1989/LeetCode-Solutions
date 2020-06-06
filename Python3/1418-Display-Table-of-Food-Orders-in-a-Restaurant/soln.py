class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        food = set()
        record = {}
        for _, table, dish in orders:
            table = int(table)
            food.add(dish)
            if table not in record:
                record[table] = collections.Counter()
            record[table][dish] += 1
        food = sorted(food)
        ans = [['Table'] + food]
        for table in sorted(record):
            counter = record[table]
            row = [str(table)] + [str(counter[dish]) for dish in food]
            ans.append(row)
        return ans
