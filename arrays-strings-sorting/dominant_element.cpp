#include <iostream>
#include <unordered_map>

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        int N;
        std::cin >> N;
        std::unordered_map<int, int> freq;
        int num;
        int maxFreq = 0;
        bool dominant = false;

        for (int i = 0; i < N; ++i)
        {
            std::cin >> num;
            freq[num]++;
            if (freq[num] > maxFreq)
            {
                maxFreq = freq[num];
            }
        }

        for (const auto &element : freq)
        {
            if (element.second == maxFreq && maxFreq > 1)
            {
                dominant = true;
                // Se encontrarmos mais de um elemento com a frequência máxima, não é dominante
                for (const auto &elem : freq)
                {
                    if (elem.first != element.first && elem.second == maxFreq)
                    {
                        dominant = false;
                        break;
                    }
                }
                if (dominant)
                {
                    break;
                }
            }
        }

        std::cout << (dominant ? "YES\n" : "NO\n");
    }

    return 0;
}