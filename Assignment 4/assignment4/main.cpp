#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int CalculateCost(char ch);

/*
 * Structure for Edge
 */
struct Edge {
    int CountryConnections;
    char CostForBuilding;
    char CostForDestroying;

    Edge(int Road, char Build, char Destroy);
};

Edge::Edge(int Road, char Build, char Destroy) {
    this->CountryConnections = Road;
    this->CostForBuilding = Build;
    this->CostForDestroying = Destroy;
}

/*
 * Structure for Union Find Data Structure
 */
struct GraphFunctions {
    int *Parent, *Number;

    GraphFunctions(int n);
    int Find(int value);
    void merge(int x, int y);
};

GraphFunctions::GraphFunctions(int n) {
    Parent = new int[n];
    Number = new int[n];
    for (int i = 0; i < n; i++) {
        Parent[i] = i;
        Number[i] = 1;
    }
}

int GraphFunctions::Find(int value) {
    return Parent[value] == value ? value : Parent[value] = Find(Parent[value]);
}

void GraphFunctions::merge(int A, int B) {
    int SetA = Find(A);
    int SetB = Find(B);

    if (SetA != SetB) {
        if (Number[SetA] < Number[SetB])
            Parent[SetA] = SetB;
        else {
            Parent[SetB] = SetA;
            Number[SetA]++;
        }
    }
}

/*
 * Structure for Graph
 */
struct Graph {
    int rows = 0, cols = 0;
    Edge ***edges;

    Graph(int numRows, int numCols);
    ~Graph();
    int CalculateMST(Graph *g);
};

Graph::Graph(int numRows, int numCols) {
    this->rows = numRows;
    this->cols = numCols;
    edges = new Edge **[rows];
    for (int i = 0; i < rows; i++) {
        edges[i] = new Edge *[cols];
        for (int j = 0; j < cols; j++)
            edges[i][j] = new Edge(-1, '0', '0');
    }
}

Graph::~Graph() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            delete edges[i][j];
        delete edges[i];
    }
}

int Graph::CalculateMST(Graph *g) {
    int Cost = 0;

    GraphFunctions myGraph = GraphFunctions(rows * cols);

    vector<vector<int>> build, destroy;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < i; j++) {
            if (edges[i][j]->CountryConnections == 0)
                build.push_back({i, j, CalculateCost(edges[i][j]->CostForBuilding)});
            else
                destroy.push_back({i, j, CalculateCost(edges[i][j]->CostForDestroying)});
        }
    }

    sort(build.begin(), build.end(), [](vector<int> a, vector<int> b) { return a.at(2) < b.at(2); });

    sort(destroy.begin(), destroy.end(), [](vector<int> a, vector<int> b) { return a.at(2) > b.at(2); });

    for (auto i : destroy) {
        if (myGraph.Find(i.at(0)) != myGraph.Find(i.at(1)))
            myGraph.merge(i.at(0), i.at(1));
        else
            Cost += i.at(2);
    }

    for (auto i : build) {
        if (myGraph.Find(i.at(0)) != myGraph.Find(i.at(1))) {
            myGraph.merge(i.at(0), i.at(1));
            Cost += i.at(2);
        }
    }
    return Cost;
}

/*
 * Functions
 */
int CalculateCost(char ch) {
    return (isupper(ch) != 0) ? (ch - 'A') : (ch - 'a' + 26);
}

/*
 * Main Driver
 */
int main() {
    string country, build, destroy;
    cin >> country >> build >> destroy;

    char delimiter = ',';

    int numRows = 0, numCols = 0;

    numRows = count(country.begin(), country.end(), delimiter) + 1;

    if (country.find(delimiter) != string::npos)
        numCols = country.substr(0, country.find(delimiter)).size();

    Graph *g = new Graph(numRows, numCols);

    int i = 0;
    string temp1, temp2, temp3;
    while (country.find(delimiter) != string::npos) {
        temp1 = country.substr(0, country.find(delimiter));
        temp2 = build.substr(0, build.find(delimiter));
        temp3 = destroy.substr(0, destroy.find(delimiter));

        for (int j = 0; j < numCols; j++)
            g->edges[i][j] = new Edge(int(temp1.at(j) - '0'), temp2.at(j), temp3.at(j));

        country.erase(0, country.find(delimiter) + 1);
        build.erase(0, build.find(delimiter) + 1);
        destroy.erase(0, destroy.find(delimiter) + 1);
        i++;
    }

    for (int j = 0; j < numCols; j++)
        g->edges[i][j] = new Edge(int(country.at(j) - '0'), build.at(j), destroy.at(j));

    cout << g->CalculateMST(g) << endl;

    delete g;

    return 0;
}
