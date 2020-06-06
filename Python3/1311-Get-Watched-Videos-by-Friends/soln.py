class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], ID: int, level: int) -> List[str]:
        n = len(friends)
        # BFS
        frontier = [ID]
        levels = {ID : 0}
        nsteps = 0
        while frontier:
            if level == 0:
                break
            level -= 1
            next_level = []
            for u in frontier:
                for v in friends[u]:
                    if v not in levels:
                        levels[v] = nsteps + 1
                        next_level.append(v)
            frontier = next_level
            nsteps += 1
        counter = collections.Counter()
        for ID in frontier:
            for video in watchedVideos[ID]:
                counter[video] += 1
        return sorted(counter, key=lambda x : (counter[x], x))
