class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        graph = collections.defaultdict(dict)
        for value, (num, deno) in zip(values, equations):
            graph[num][num] = graph[deno][deno] = 1.
            graph[num][deno] = value
            graph[deno][num] = 1.0 / value
        # k i j not i j k
        for k, i, j in itertools.permutations(graph, 3):
            if k in graph[i] and j in graph[k]:
                graph[i][j] = graph[i][k] * graph[k][j]
        return [graph[num].get(deno, -1.0) for num, deno in queries]