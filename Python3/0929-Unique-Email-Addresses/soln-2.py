class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        def process(email):
            local, domain = email.split('@')
            return re.sub(r'\.|\+.*', '', local), domain
        return len(set(map(process, emails)))
