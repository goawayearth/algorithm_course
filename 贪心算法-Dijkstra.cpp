#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// 边的结构体，包含边的起点、终点和权值
struct Edge {
    int from, to, weight;
};

// 图的结构体，包含节点数、边数和边的列表
struct Graph {
    int num_nodes, num_edges;
    vector<Edge> edges;
};

// Dijkstra算法
void dijkstra(const Graph& graph, int start_node, vector<int>& distances) {
    // 初始化距离列表，将起点到所有节点的距离都设置为无穷大
    distances.assign(graph.num_nodes, INT_MAX);
    // 起点到自身的距离为0
    distances[start_node] = 0;
    // 建立堆来存储待处理的节点
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push(make_pair(0, start_node));

    while (!heap.empty()) {
        // 从堆中取出最小距离的节点
        int current_node = heap.top().second;
        int current_distance = heap.top().first;
        heap.pop();
        // 如果当前节点的距离已经被更新过，则直接跳过
        if (current_distance > distances[current_node]) {
            continue;
        }
        // 更新当前节点的邻居节点的距离
        for (int i = 0; i < graph.num_edges; i++) {
            Edge edge = graph.edges[i];
            if (edge.from == current_node) {
                int new_distance = distances[current_node] + edge.weight;
                if (new_distance < distances[edge.to]) {
                    distances[edge.to] = new_distance;
                    heap.push(make_pair(new_distance, edge.to));
                }
            }
        }
    }
}

// 测试函数
int main() {
    // 创建一个包含5个节点和7条边的图
    Graph graph;
    graph.num_nodes = 5;
    graph.num_edges = 7;
    graph.edges.push_back({ 0, 1, 2 });
    graph.edges.push_back({ 0, 2, 5 });
    graph.edges.push_back({ 1, 2, 1 });
    graph.edges.push_back({ 1, 3, 3 });
    graph.edges.push_back({ 2, 3, 2 });
    graph.edges.push_back({ 2, 4, 1 });
    graph.edges.push_back({ 3, 4, 1 });
    // 运行Dijkstra算法，找到起点到所有节点的最短路径
    vector<int> distances;
    dijkstra(graph, 0, distances);
    // 输出最短路径
    for (int i = 0; i < distances.size(); i++) {
        cout << "Distance from node 0 to node " << i << " is " << distances[i] << endl;
    }
    return 0;
}
