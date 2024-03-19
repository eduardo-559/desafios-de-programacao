#include <iostream>
#include <vector>
#include <algorithm>

bool can_produce(std::vector<int> &machines, long long time, int t)
{
    long long total = 0;
    for (int machine : machines)
    {
        total += time / machine;
        if (total >= t)
            return true;
    }
    return total >= t;
}

int main()
{
    int n, t;
    std::cin >> n >> t;

    std::vector<int> machines(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> machines[i];
    }

    long long left = 0;
    long long right = 1e18; // Um limite superior suficientemente grande
    long long answer = right;

    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (can_produce(machines, mid, t))
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << answer << std::endl;

    return 0;
}