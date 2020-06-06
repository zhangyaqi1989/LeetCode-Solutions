class Solution:
    def numOfMinutes(self, n: int, headID: int, manager: List[int], informTime: List[int]) -> int:
        tree = collections.defaultdict(list)
        for idx, m_idx in enumerate(manager):
            if m_idx != -1:
                tree[m_idx].append(idx)
        frontier = [(headID, 0)]
        times = {headID : 0}
        while frontier:
            next_level = []
            for idx, _ in frontier:
                cur_time = times[idx]
                in_time = informTime[idx]
                for child in tree[idx]:
                    if child not in times or in_time + cur_time < times[child]:
                        next_level.append((child, in_time + cur_time))
                        times[child] = in_time + cur_time
            frontier = next_level
        return max(times.values())
