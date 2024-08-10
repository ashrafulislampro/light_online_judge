#include <bits/stdc++.h>
using namespace std;

int main()
{
    int testCases, numberOfCities, numberOfRoads, sourceCity, destinationCity, roadCost, homeTown, maxCostFound;

    cin >> testCases;
    for (int i = 1; i <= testCases; i++)
    {
        cin >> numberOfCities >> numberOfRoads;

        vector<int> areaMap[numberOfCities];      // actual graph
        int distanceFromHomeTown[numberOfCities]; // distance output array
        int cost[numberOfCities][numberOfCities]; // road cost

        memset(cost, 0, sizeof(cost)); // initially setting the cost as not specified
        for (int i = 0; i <= numberOfCities; i++)
        {
            distanceFromHomeTown[i] = INT_MAX;
        }

        // Adding each given roads while checking if already a low cost road exist between them or not
        for (int j = 0; j < numberOfRoads; j++)
        {
            cin >> sourceCity >> destinationCity >> roadCost;

            if (cost[sourceCity][destinationCity]) // checking any previous road exists or not
            {
                cost[sourceCity][destinationCity] = cost[destinationCity][sourceCity] = min(cost[sourceCity][destinationCity], roadCost);
            }
            else
            {
                // adding new road
                areaMap[sourceCity].push_back(destinationCity);
                areaMap[destinationCity].push_back(sourceCity);
                cost[sourceCity][destinationCity] = cost[destinationCity][sourceCity] = roadCost;
            }
        }
        cin >> homeTown;
        queue<int> cityQueue;     // making a queue to traverse through each of the city
        cityQueue.push(homeTown); // pushing the home town as our start point or source node
        distanceFromHomeTown[homeTown] = 0;

        while (!cityQueue.empty())
        {
            int startingCity = cityQueue.front();
            cityQueue.pop(); // taking it out since it will be traversed now
            // checking the other cities that can be reached via startingCity

            for (int k = 0; k < areaMap[startingCity].size(); k++)
            {
                int currentCity = areaMap[startingCity][k];
                maxCostFound = max(distanceFromHomeTown[startingCity], cost[startingCity][currentCity]);

                if (distanceFromHomeTown[currentCity] > maxCostFound)
                {
                    distanceFromHomeTown[currentCity] = maxCostFound;
                    cityQueue.push(currentCity);
                }
            }
        }
        cout << "Case " << i << ":\n";
        for (int p = 0; p < numberOfCities; p++)
        {
            if (distanceFromHomeTown[p] == INT_MAX)
            {
                cout << "Impossible\n";
            }
            else
            {
                cout << distanceFromHomeTown[p] << "\n";
            }
        }
    }
    return 0;
}