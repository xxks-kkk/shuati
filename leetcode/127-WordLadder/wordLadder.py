# Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
#
# Only one letter can be changed at a time.
# Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
# For example,
#
# Given:
# beginWord = "hit"
# endWord = "cog"
# wordList = ["hot","dot","dog","lot","log","cog"]
# As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
# return its length 5.
#
# Note:
# Return 0 if there is no such transformation sequence.
# All words have the same length.
# All words contain only lowercase alphabetic characters.
# You may assume no duplicates in the word list.
# You may assume beginWord and endWord are non-empty and are not the same.
# UPDATE (2017/1/20):
# The wordList parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.

import collections

class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        dict = {}
        queue = []
        alphabets = 'abcdefghijklmnopqrstuvwxyz'
        dict[beginWord] = 1
        queue.insert(0, beginWord)
        while queue:
            word = queue.pop()
            for i in range(len(word)):
                for char in alphabets:
                    new_word = word[:i] + char + word[i+1:]
                    if new_word == endWord and new_word in wordList:
                        return dict[word] + 1
                    if new_word in wordList and not new_word in dict.keys():
                        queue.insert(0, new_word)
                        dict[new_word] = dict[word] + 1
        return 0

    def ladderLength1(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        def make_p2w(word_list, w_idxs):
            """Creates a map of all combinations of words with missing letters mapped
            to all words in the list that match that pattern.
            E.g. hot -> {'_ot': ['hot'], 'h_t': ['hot'], 'ho_': ['hot']}
            """
            p2w = collections.defaultdict(list)

            for word in word_list:
                for i, j in w_idxs:
                    p = word[:i] + "_" + word[j:]
                    p2w[p].append(word)
            return p2w

        def bfs_words(begin, end, w_idxs, p2w):
            queue = collections.deque([(begin, 1)])
            visited = set([begin])

            while queue:
                # Get the next node to explore from the top of the queue
                word, depth = queue.popleft()

                # Get the node's children
                # By recreating all possible patterns for that string
                for i, j in w_idxs:
                    p = word[:i] + "_" + word[j:]
                    neighbor_words = p2w[p]
                    # Iterate through children
                    for nw in neighbor_words:
                        if nw not in visited:
                            # Goal check (before adding to the queue)
                            if nw == end:
                                return depth + 1
                            # Add to visited
                            # These is no reason to wait to mark nodes as visited. Because this is
                            # a BFS, once a node has been seen that is the earliest it could have
                            # possibly been seen so any other path to that node would either be
                            # longer or the same length as what we've already observed.
                            visited.add(nw)
                            # Add to the end of the queue
                            queue.append((nw, depth + 1))
            return 0

        # Get word length and character indexes
        wl = len(beginWord)
        w_indexes = zip(range(wl), range(1, wl + 1))
        # Preprocess words into a map
        patterns2words = make_p2w(wordList, w_indexes)
        # Do the search
        return bfs_words(beginWord, endWord, w_indexes, patterns2words)


if __name__ == "__main__":
    sol = Solution()
    wordList = ["hot","dot","dog","lot","log","cog"]
    assert sol.ladderLength('hit', 'cog', wordList) == 5
    assert sol.ladderLength1('hit', 'cog', wordList) == 5

    wordList = ["hot","dot","dog","lot","log"]
    assert sol.ladderLength('hit', 'cog', wordList) == 0
    assert sol.ladderLength('hit', 'cog', wordList) == 0