# Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
#
#
# OJ's undirected graph serialization:
# Nodes are labeled uniquely.
#
# We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
# As an example, consider the serialized graph {0,1,2#1,2#2,2}.
#
# The graph has a total of three nodes, and therefore contains three parts as separated by #.
#
# First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
# Second node is labeled as 1. Connect node 1 to node 2.
# Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
# Visually, the graph looks like the following:
#
#        1
#       / \
#      /   \
#     0 --- 2
#          / \
#          \_/
from collections import defaultdict
import pprint

# Definition for a undirected graph node
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []

# Graph structure compatible with Leetcode definition
#
# code inspired by: https://stackoverflow.com/questions/19472530/representing-graphs-data-structure-in-python
# Sophisticated Graph implementation from "NetworkX" may be worth looking further:
# https://networkx.github.io/documentation/latest/_modules/networkx/classes/graph.html#Graph
class UndirectedGraph:
    def __init__(self, connections, directed=False):
        # definition on convention: https://leetcode.com/problems/clone-graph/description/
        """ Graph data structure, undirected by default. """
        self._graph = set()
        self._directed = directed
        self.add_connections(connections)

    def add_connections(self, connections):
        """ Add connections (list of tuple pairs) to graph """
        adjacency_lists = connections.split("#")
        for adjacency_list_string in adjacency_lists:
            adjacency_list = adjacency_list_string.split(',')
            node1 = UndirectedGraphNode(adjacency_list[0])
            neighbors = adjacency_list[1:]
            for label in neighbors:
                node2 = UndirectedGraphNode(label)
                node1.neighbors.append(node2)
            self._graph.add(node1)

    def __str__(self):
        l = ['{']
        for element in self._graph:
            neighbor_list = []
            for node in element.neighbors:
                neighbor_list.append(str(node.label))
            neighbor_list_string = ','.join(neighbor_list)
            l.append("'" + str(element.label) + "': {" + neighbor_list_string + "}")
        l.append('}')
        return '\n'.join(l)

    def get_a_node(self):
        return next(iter(self._graph))

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if not node:
            return None
        visited = {}
        copy = UndirectedGraphNode(node.label)
        visited[node] = copy
        queue = []
        queue.insert(0, node)
        while queue:
            curr = queue.pop()
            for neighbor in curr.neighbors:
                if neighbor not in visited:
                    neighbor_copy = UndirectedGraphNode(neighbor.label)
                    visited[neighbor] = neighbor_copy
                    queue.insert(0, neighbor)
                visited[curr].neighbors.append(visited[neighbor])
        return copy

if __name__ == "__main__":
    connections = "0,1,2#1,2#2,2"
    g = UndirectedGraph(connections)
    print(g)

    node = g.get_a_node()
    sol = Solution()
    g_node = sol.cloneGraph(node)


