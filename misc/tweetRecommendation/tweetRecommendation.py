# Complete the function below.
# followGraph_edges is a list of tuples (userId, userId)
# likeGraph_edges is also a list of tuples (userId, tweetId)
from collections import defaultdict

def getRecommendedTweets(followGraph_edges, likeGraph_edges, targetUser, minLikeThreshold):
    targetUserFollows = {t[1] for t in followGraph_edges if t[0] is targetUser}
    recommendedTweets = defaultdict(lambda:0)
    for like in likeGraph_edges:
        if like[0] in targetUserFollows:
            recommendedTweets[like[1]] += 1
    return [tweet for tweet in recommendedTweets if recommendedTweets[tweet] >= minLikeThreshold]
