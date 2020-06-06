class Twitter:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.timer = itertools.count(0, -1)
        self.tweets = collections.defaultdict(collections.deque) # map userId to tweets
        self.followees = collections.defaultdict(set) # map userId to its followees
        

    def postTweet(self, userId: 'int', tweetId: 'int') -> 'None':
        """
        Compose a new tweet.
        """
        self.tweets[userId].appendleft((next(self.timer), tweetId))
        
        

    def getNewsFeed(self, userId: 'int') -> 'List[int]':
        """
        Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
        """
        self.followees[userId].add(userId)
        feeds = heapq.merge(*[iter(self.tweets[idx]) for idx in self.followees[userId]])
        return [idx for _, idx in itertools.islice(feeds, 10)]
        

    def follow(self, followerId: 'int', followeeId: 'int') -> 'None':
        """
        Follower follows a followee. If the operation is invalid, it should be a no-op.
        """
        self.followees[followerId].add(followeeId)
        

    def unfollow(self, followerId: 'int', followeeId: 'int') -> 'None':
        """
        Follower unfollows a followee. If the operation is invalid, it should be a no-op.
        """
        self.followees[followerId].discard(followeeId)
        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
