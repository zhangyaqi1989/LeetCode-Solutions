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
import concurrent.futures
class Solution:
    def crawl(self, startUrl: str, htmlParser: 'HtmlParser') -> List[str]:
        def extract_hostname(url):
            idx = url.find('/', 7)
            return url[:url.find('/', 7)] if idx != -1 else url
        def func(url):
            ans.append(url)
            res = []
            for nei in htmlParser.getUrls(url):
                if nei not in visited and extract_hostname(nei) == hostname:
                    visited.add(nei)
                    res.append(nei)
            return res
        hostname = extract_hostname(startUrl)
        frontier = [startUrl]
        visited = {startUrl}
        ans = []
        while frontier:
            with concurrent.futures.ThreadPoolExecutor(max_workers=6) as executor:
                frontier = [url for lst in executor.map(func, frontier) for url in lst]
        return ans
        
