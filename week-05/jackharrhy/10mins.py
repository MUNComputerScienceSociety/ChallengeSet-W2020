import json
from decimal import Decimal
from sys import stdin

class Node:
    def __init__(self, label):
        self.label = label


class Edge:
    def __init__(self, to_node, length):
        self.to_node = to_node
        self.length = length


class Graph:
    def __init__(self):
        self.nodes = set()
        self.edges = dict()

    def add_node(self, node):
        self.nodes.add(node)

    def add_edge(self, from_node, to_node, length):
        edge = Edge(to_node, length)
        if from_node.label in self.edges:
            from_node_edges = self.edges[from_node.label]
        else:
            self.edges[from_node.label] = dict()
            from_node_edges = self.edges[from_node.label]
        from_node_edges[to_node.label] = edge


def min_dist(q, dist):
    min_node = None
    for node in q:
        if min_node == None:
            min_node = node
        elif dist[node] < dist[min_node]:
            min_node = node

    return min_node


INFINITY = Decimal("Infinity")


def dijkstra(graph, source):
    q = set()
    dist = {}
    prev = {}

    for v in graph.nodes:
        dist[v] = INFINITY
        prev[v] = INFINITY
        q.add(v)

    dist[source] = 0

    while q:
        u = min_dist(q, dist)

        q.remove(u)

        if u.label in graph.edges:
            for _, v in graph.edges[u.label].items():
                alt = dist[u] + v.length
                if alt < dist[v.to_node]:
                    dist[v.to_node] = alt
                    prev[v.to_node] = u

    return dist, prev


def to_array(prev, from_node):
    previous_node = prev[from_node]
    route = [from_node.label]
    while previous_node != INFINITY:
        route.append(previous_node.label)
        temp = previous_node
        previous_node = prev[temp]

    route.reverse()
    return route


nodes = {}
graph = Graph()

with open("../../problems/10mins/10mins.json") as json_file:
    data = json.load(json_file)
    for node in data.keys():
        nodes[node] = Node(node)
        graph.add_node(nodes[node])

    for node in data:
        cur_node = nodes[node]
        for edge in data[node]:
            linked_node = nodes[edge[0]]
            graph.add_edge(cur_node, linked_node, edge[1])
            graph.add_edge(linked_node, cur_node, edge[1])

node_from = nodes[stdin.readline().strip()]
node_to = nodes[stdin.readline().strip()]

dist, prev = dijkstra(graph, node_from)
path = " -> ".join(to_array(prev, node_to))

print(path)

num = dist[node_to]

if num <= 5:
    print("Short!")
elif num <= 15:
    print("Okay")
else:
    print("Long :(")
