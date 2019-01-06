#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int no_of_stones, no_of_steps;
    cin >> no_of_stones >> no_of_steps;

    vector <int> height(no_of_stones + 1, 0);
    for(int i = 1; i <= no_of_stones; i++)
        cin >> height[i];

    const int oo = 1e9;
    vector <int> minimum_cost(no_of_stones + 1, oo);
    minimum_cost[1] = 0;

    for(int i = 2; i <= no_of_stones; i++)
    {
        for(int j = i - 1; j >= max(1, i - no_of_steps); j--)
        {
            minimum_cost[i] = min(minimum_cost[i], minimum_cost[j] + abs(height[i] - height[j]));
        }
    }

    cout << minimum_cost[no_of_stones];
    return 0;
}

