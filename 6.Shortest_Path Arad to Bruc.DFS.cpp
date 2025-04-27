#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

// Graph representation: Adjacency list
unordered_map<string, vector<pair<string, int>>> romaniaMap = {
    {"Arad", {{"Zerind", 75}, {"Sibiu", 140}, {"Timisoara", 118}}},
    {"Zerind", {{"Arad", 75}, {"Oradea", 71}}},
    {"Oradea", {{"Zerind", 71}, {"Sibiu", 151}}},
    {"Sibiu", {{"Arad", 140}, {"Oradea", 151}, {"Fagaras", 99}, {"Rimnicu Vilcea", 80}}},
    {"Timisoara", {{"Arad", 118}, {"Lugoj", 111}}},
    {"Lugoj", {{"Timisoara", 111}, {"Mehadia", 70}}},
    {"Mehadia", {{"Lugoj", 70}, {"Drobeta", 75}}},
    {"Drobeta", {{"Mehadia", 75}, {"Craiova", 120}}},
    {"Craiova", {{"Drobeta", 120}, {"Rimnicu Vilcea", 146}, {"Pitesti", 138}}},
    {"Rimnicu Vilcea", {{"Sibiu", 80}, {"Craiova", 146}, {"Pitesti", 97}}},
    {"Fagaras", {{"Sibiu", 99}, {"Bucharest", 211}}},
    {"Pitesti", {{"Rimnicu Vilcea", 97}, {"Craiova", 138}, {"Bucharest", 101}}},
    {"Bucharest", {{"Fagaras", 211}, {"Pitesti", 101}, {"Giurgiu", 90}, {"Urziceni", 85}}},
    {"Giurgiu", {{"Bucharest", 90}}},
    {"Urziceni", {{"Bucharest", 85}, {"Hirsova", 98}, {"Vaslui", 142}}},
    {"Hirsova", {{"Urziceni", 98}, {"Eforie", 86}}},
    {"Eforie", {{"Hirsova", 86}}},
    {"Vaslui", {{"Urziceni", 142}, {"Iasi", 92}}},
    {"Iasi", {{"Vaslui", 92}, {"Neamt", 87}}},
    {"Neamt", {{"Iasi", 87}}}
};

// Stores the best (shortest) path
vector<string> bestPath;
int minCost = INF;

// DFS function to find the shortest path
void dfs(string currentCity, string destination, set<string> &visited, vector<string> &path, int cost) {
    // If we reach the destination, check if it's the shortest path
    if (currentCity == destination) {
        if (cost < minCost) {
            minCost = cost;
            bestPath = path;
        }
        return;
    }

    // Mark current city as visited
    visited.insert(currentCity);

    // Explore neighbors (cities connected to the current city)
    for (auto neighbor : romaniaMap[currentCity]) {
        string nextCity = neighbor.first;
        int distance = neighbor.second;

        if (visited.find(nextCity) == visited.end()) {
            path.push_back(nextCity);
            dfs(nextCity, destination, visited, path, cost + distance);
            path.pop_back();
        }
    }

    // Unmark the city after backtracking
    visited.erase(currentCity);
}

int main() {
    string start = "Arad", destination = "Bucharest";

    set<string> visited;
    vector<string> path = {start};

    cout << "Searching for the shortest path from " << start << " to " << destination << " using DFS...\n";
    
    dfs(start, destination, visited, path, 0);

    // Print the shortest path found
    if (minCost == INF) {
        cout << "No path found!\n";
    } else {
        cout << "\nShortest Path: ";
        for (const auto &city : bestPath) {
            cout << city << " -> ";
        }
        cout << "Bucharest\n";
        cout << "Total Distance: " << minCost << " miles\n";
    }

    return 0;
}

