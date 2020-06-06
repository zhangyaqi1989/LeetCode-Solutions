# """
# This is HtmlParser's API interface.
# You should not implement it, or speculate about its implementation
# """
#class HtmlParser(object):
#    def getUrls(self, url):
#        """
#        :type url: str
#        :rtype List[str]
#        """

class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        def get_host(url):
            tokens = url.split('.')[:2]
            return '.'.join(tokens).lower()
        visited = {startUrl}
        stack = [startUrl]
        host = get_host(startUrl)
        ans = []
        while stack:
            url = stack.pop()
            ans.append(url)
            for nei in htmlParser.getUrls(url):
                if get_host(nei) == host and nei not in visited:
                    visited.add(nei)
                    stack.append(nei)
        return sorted(ans)
