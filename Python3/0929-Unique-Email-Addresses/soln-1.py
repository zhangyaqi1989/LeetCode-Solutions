class Solution:
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        receivers = set()
        for email in emails:
            local, domain = email.split('@')
            idx = local.find('+')
            if idx != -1:
                local = local[:idx]
            local = local.replace('.', '')
            receivers.add('{}@{}'.format(local, domain))
        return len(receivers)