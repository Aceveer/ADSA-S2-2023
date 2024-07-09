#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int CountryConnections;
    char CostForBuilding;
    char CostForDestroying;

    Node(int CountryConnections, char BuildCost, char DestroyCost) : CountryConnections(CountryConnections), CostForBuilding(BuildCost), CostForDestroying(DestroyCost) {}
};

struct GraphFunctions {
    vector<int> Parent, Number;

    GraphFunctions(int n) : Parent(n), Number(n, 1) {
        for (int i = 0; i < n; ++i) {
            Parent[i] = i;
        }
    }

    int Find(int key) {
        return Parent[key] == key ? key : Parent[key] = Find(Parent[key]);
    }

    void Union(int A, int B) {
        int A_N = Find(A);
        int B_N = Find(B);

        if (A_N != B_N) {
            if (Number[A_N] < Number[B_N]) {
                Parent[A_N] = B_N;
            } else {
                Parent[B_N] = A_N;
                Number[A_N]++;
            }
        }
    }
};

struct Graph {
    int rows, columns;
    vector<vector<Node>> graph;

    Graph(int rows, int columns) : rows(rows), columns(columns), graph(rows, vector<Node>(columns, {-1, '0', '0'})) {}

    int kruskalMST(Graph& g);
};


int Graph::kruskalMST(Graph& g) {
    int Cost = 0;
    GraphFunctions mf(g.rows * g.columns);

    vector<vector<int>> Build, Destroy;

    for (int i = 0; i < g.rows; ++i) {
        for (int j = 0; j < g.columns; ++j) {
            if (g.graph[i][j].CountryConnections == 0) {
                Build.push_back({i, j, getCost(g.graph[i][j].CostForBuilding)});
            } else {
                Destroy.push_back({i, j, getCost(g.graph[i][j].CostForDestroying)});
            }
        }
    }

    sort(Build.begin(), Build.end(), [](const auto& a, const auto& b) { return get<2>(a) < get<2>(b); });
    sort(Destroy.begin(), Destroy.end(), [](const auto& a, const auto& b) { return get<2>(a) > get<2>(b); });


    for (auto& i : Destroy) {
        if (mf.Find(i.at(0)) != mf.Find(i.at(1))) {
            mf.Union(i.at(0), i.at(1));
        } else {
            Cost += i.at(2);
        }
    }

    for (auto& i : Build) {
        if (mf.Find(i.at(0)) != mf.Find(i.at(1))) {
            mf.Union(i.at(0), i.at(1));
            Cost += i.at(2);
        }
    }

    return Cost;
}

int getCost(char c) {
    return (isupper(c) != 0) ? (c - 'A') : (c - 'a' + 26);
}

int main() {
    string Country, BuildCost, DestroyCost;
    cin >> Country >> BuildCost >> DestroyCost;

    char CommaSeparator = ',';

    int rows = 0, columns = 0;

    rows = count(Country.begin(), Country.end(), CommaSeparator) + 1;

    if (Country.find(CommaSeparator) != string::npos)
        columns = Country.substr(0, Country.find(CommaSeparator)).size();

    Graph g(rows, columns);

    int i = 0;
    string CountryMatrix, CostMatrix, DestoryMatrix;
    while (Country.find(CommaSeparator) != string::npos) {
        CountryMatrix = Country.substr(0, Country.find(CommaSeparator));
        CostMatrix = BuildCost.substr(0, BuildCost.find(CommaSeparator));
        DestoryMatrix = DestroyCost.substr(0, DestroyCost.find(CommaSeparator));

        for (int j = 0; j < columns; ++j)
            g.graph[i][j] = Node(int(CountryMatrix.at(j) - '0'), CostMatrix.at(j), DestoryMatrix.at(j));

        Country.erase(0, Country.find(CommaSeparator) + 1);
        BuildCost.erase(0, BuildCost.find(CommaSeparator) + 1);
        DestroyCost.erase(0, DestroyCost.find(CommaSeparator) + 1);
        ++i;
    }

    for (int j = 0; j < columns; ++j)
        g.graph[i][j] = Node(int(Country.at(j) - '0'), BuildCost.at(j), DestroyCost.at(j));

    cout << g.kruskalMST(g) << endl;

    return 0;
}