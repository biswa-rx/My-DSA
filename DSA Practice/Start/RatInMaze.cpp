#include <iostream>
using namespace std;
#define N 6
int maze[N][N] = {{1, 1, 1, 1, 0, 1}, {1, 1, 0, 1, 0, 1}, {1, 0, 0, 1, 1, 1}, {1, 1, 1, 1, 0, 1}, {1, 0, 1, 1, 0, 1}, {1, 1, 0, 0, 1, 1}};
int sol[N][N] = {0};
int n = N;

bool is_safe(int r, int c, int n)
{
    if (r >= n && c >= n)
    {
        return false;
    }
    if (maze[r][c] == 0)
    {
        return false;
    }
    return true;
}
bool rabbti_maze(int r, int c, int n)
{
    if (r == n - 1 && c == n - 1)
    {
        sol[r][c] = 1;
        return true;
    }
    if (is_safe(r, c, n))
    {
        sol[r][c] = 1;

        if (rabbti_maze(r + 1, c, n))
        {
            return true;
        }
        if (rabbti_maze(r, c + 1, n))
        {
            return true;
        }
        sol[r][c] = 0;
        return false;
    }
    return false;
}

int main()
{

    if (rabbti_maze(0, 0, n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}