#include <iostream>

using namespace std;

int main()
{
    int n;
    int i, j;
    int steps = 0;

    cout << "The starting number: ";
    cin >> n;
    i = n;


    while (i > 1)
    {
        j = 1;
        while (2 * j <= i)
        {
            j = 2 * j;
        }

        if (j == i)
        {
            i = i / 2;
        }
        else
        {
            i = i - j;
        }

        steps++;
    }

    if (steps % 2 == 0)
    {
        cout << "Richard";
    }
    else
    {
        cout << "Louise";
    }


    return 0;
}
