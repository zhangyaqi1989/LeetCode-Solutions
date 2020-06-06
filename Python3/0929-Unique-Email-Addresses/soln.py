class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        s = set()
        for email in emails:
            local, domain = email.split('@')
            local = local.replace('.', '')
            if '+' in local:
                local = local[:local.index('+')]
            s.add(local + '@' + domain)
        return len(s)