#include <iostream>

using namespace std;

int main()
{
    int a, b, x, y;
    int i, j;
    cin>>a;
    cin>>b;
    cin>>x;
    cin>>y;

    i = a;
    j = b;

    if (b != 0)
    {
        if(x > a)
        {
            while (i < x)
            {
                i = i + b;
            }
        }
        else
        {
            while (i > x)
            {
                i = i - b;

            }
        }
    }

    if (a != 0)
    {
        if (i == x)
        {
            if (y > b)
            {
                while(j < y)
                {
                    j = j + a;
                }
            }
            else
            {
                while (j > y)
                {
                    j = j - a;
                }
            }

        }
    }

    if ((i == x) && (j == y))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
