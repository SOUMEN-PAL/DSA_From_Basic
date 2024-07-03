#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Structure to represent a city
struct City {
    int id;
    int distance;

    City(int _id, int _distance) : id(_id), distance(_distance) {}

    // Overload the > operator
    bool operator>(const City& other) const {
        return distance > other.distance;
    }
};

// Structure to represent a road
struct Road {
    int city1, city2, distance;
    
    // Default constructor
    Road() : city1(0), city2(0), distance(0) {}

    // Constructor with parameters
    Road(int _city1, int _city2, int _distance) : city1(_city1), city2(_city2), distance(_distance) {}
};

// Function to find the minimum distance for the pilgrimage
int findMinDistance(int n, int m, int k, vector<Road>& roads) {
    // Create a graph to represent the cities and roads
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int city1 = roads[i].city1;
        int city2 = roads[i].city2;
        int distance = roads[i].distance;
        graph[city1].push_back({city2, distance});
        graph[city2].push_back({city1, distance});
    }

    // Create a priority queue to store the cities based on their distance
    priority_queue<City, vector<City>, greater<City>> pq;

    // Create a vector to store the minimum distance for each city
    vector<int> minDistance(n + 1, INT_MAX);

    // Mark the shrines as visited and set their distance to 0
    for (int i = 1; i <= k; i++) {
        int shrine = i;
        minDistance[shrine] = 0;
        pq.push(City(shrine, 0));
    }

    // Dijkstra's algorithm to find the minimum distance
    while (!pq.empty()) {
        int currentCity = pq.top().id;
        int currentDistance = pq.top().distance;
        pq.pop();

        // If the current distance is greater than the minimum distance, skip
        if (currentDistance > minDistance[currentCity]) {
            continue;
        }

        // Traverse the neighboring cities
        for (auto neighbor : graph[currentCity]) {
            int neighborCity = neighbor.first;
            int neighborDistance = neighbor.second;

            // If the new distance is smaller, update the minimum distance
            if (currentDistance + neighborDistance < minDistance[neighborCity]) {
                minDistance[neighborCity] = currentDistance + neighborDistance;
                pq.push(City(neighborCity, minDistance[neighborCity]));
            }
        }
    }

    // Return the minimum distance for the pilgrimage
    return minDistance[1];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<Road> roads(m);
        for (int i = 0; i < m; i++) {
            int city1, city2, distance;
            cin >> city1 >> city2 >> distance;
            roads[i] = Road(city1, city2, distance);
        }

        int minDistance = findMinDistance(n, m, k, roads);
        cout << minDistance << endl;
    }

    return 0;
}