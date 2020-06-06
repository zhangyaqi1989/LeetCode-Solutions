class Solution:
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        d = collections.defaultdict(int)
        def encode(cpdomain):
            num, domain = cpdomain.split(' ', 1)
            num, i = int(num), 0
            d[domain] += num
            while i < len(domain):
                j = domain.find('.', i)
                if j == -1:
                    break
                i = j + 1
                d[domain[i:]] += num
        for cpdomain in cpdomains:
            encode(cpdomain)
        return ["{} {}".format(value, key) for key, value in d.items()]