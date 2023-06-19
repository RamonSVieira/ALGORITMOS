#include <iostream>
#include <vector>

using namespace std;

bool validateBattleshipPositioning(int n, vector<vector<int>> &ships)
{
    vector<vector<int>> board(11, vector<int>(11, 0)); // Criação de um tabuleiro 11x11 inicializado com zeros

    for (int i = 0; i < n; i++)
    {
        int d, l, r, c;
        cin >> d >> l >> r >> c;

        if (d == 0)
        { // Navio está alinhado horizontalmente
            for (int j = 0; j < l; j++)
            {
                if (board[r][c + j] == 1)
                { // Verifica se a posição já está ocupada por outro navio
                    return false;
                }
                board[r][c + j] = 1;
            }
        }
        else
        { // Navio está alinhado verticalmente
            for (int j = 0; j < l; j++)
            {
                if (board[r + j][c] == 1)
                { // Verifica se a posição já está ocupada por outro navio
                    return false;
                }
                board[r + j][c] = 1;
            }
        }
    }

    return true;
}

int main()
{
    int n;
    cin >> n; // Número de navios

    vector<vector<int>> ships(n, vector<int>(4));
    for (int i = 0; i < n; i++)
    {
        cin >> ships[i][0] >> ships[i][1] >> ships[i][2] >> ships[i][3];
    }

    bool result = validateBattleshipPositioning(n, ships);
    if (result)
    {
        cout << "Y" << endl;
    }
    else
    {
        cout << "N" << endl;
    }

    return 0;
}
