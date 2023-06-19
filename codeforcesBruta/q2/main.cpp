#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int conta(int n)
{
    vector<int> fatoriais;  // armazena valores dos fatoriais
    fatoriais.push_back(1); // fatorial de 0 é 1
    int i = 1;

    // calcula os fatoriais e armazena no final do vetor
    while (fatoriais.back() <= n)
    {
        fatoriais.push_back(fatoriais.back() * i);
        i++;
    }

    vector<int> dp(n + 1, numeric_limits<int>::max());
    dp[0] = 0; // o 0 é representado por 0 fatoriais

    // calcula a menor quantidade de números fatoriais para representar cada número
    for (int j = 1; j <= n; j++)
    {
        for (int fatorial : fatoriais)
        {
            if (fatorial > j)
            {
                break;
            }
            dp[j] = min(dp[j], dp[j - fatorial] + 1);
        }
    }

    return dp[n];
}

int main()
{
    int n;
    // entrada
    cin >> n;

    int result = conta(n);

    cout << result << endl;

    return 0;
}
