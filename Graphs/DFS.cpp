#include <iostream>
#include <stack>
using namespace std;

#define MAX 10

void DFS(int graph[MAX][MAX], int start, int noNodes) {
    bool visited[MAX] = {false};
    visited[start] = true;
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        cout << node << ", ";

        for (int i = 1; i <= noNodes; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                st.push(i);
            }
        }
    }
}

int main() {
    int numNodes = 9;
    int graph[MAX][MAX] = {0};

    graph[1][2] = 1;
    graph[1][4] = 1;
    graph[1][5] = 1;
    graph[2][3] = 1;
    graph[3][6] = 1;
    graph[4][5] = 1;
    graph[5][6] = 1;
    graph[5][8] = 1;
    graph[6][9] = 1;
    graph[7][4] = 1;
    graph[8][6] = 1;
    graph[8][7] = 1;
    graph[9][8] = 1;

    int start = 1;
    cout << "DFS traversal starting from node " << start << ": ";
    DFS(graph, start, numNodes);

    return 0;
}
