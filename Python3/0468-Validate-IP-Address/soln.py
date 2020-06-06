# this solution is ugly
class Solution:
    def validIPAddress(self, IP):
        """
        :type IP: str
        :rtype: str
        """
        if '.' in IP:
            tokens = IP.split('.')
            if len(tokens) == 4:
                for token in tokens:
                    if len(token) > 1 and token[0] == '0':
                        break
                    else:
                        try:
                            if not token.isdigit():
                                return 'Neither'
                            val = int(token, 10)
                            if val < 0 or val > 255:
                                return 'Neither'
                        except:
                            break
                else:
                    return 'IPv4'
                return 'Neither'
            else:
                return 'Neither'
        elif ':' in IP:
            tokens = IP.split(':')
            if len(tokens) == 8:
                for token in tokens:
                    if len(token) > 4 or not all(ch in string.hexdigits for ch in token):
                        return 'Neither'
                    else:
                        try:
                            val = int(token, 16)
                        except:
                            break
                else:
                    return 'IPv6'
            else:
                return 'Neither'
            return 'Neither'
        else:
            return 'Neither'
