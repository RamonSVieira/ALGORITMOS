#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K;

    while (cin >> N >> K)
    {
        vector<int> notas(N);

        for (int i = 0; i < N; i++)
        {
            cin >> notas[i];
        }

        sort(notas.begin(), notas.end(), greater<int>());

        double soma = 0;

        for (int i = 0; i < K; i++)
        {
            soma += notas[i];
        }

        double media = soma / K;

        cout << fixed;
        cout.precision(1);
        cout << media << endl;
    }

    return 0;
}
