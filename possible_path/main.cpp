#include <iostream>

using namespace std;

int main()
{
    long int a, b, x, y;
    short int i, j;
    cin>>a;
    cin>>b;
    cin>>x;
    cin>>y;

    if (b != 0)
    {
        if(abs(x - a) % b == 0)
        {
           i = 0;
        }
        else
        {
            i = 1;
        }
    }
    else if (a == x)
    {
        i = 0;
    }
    else
    {
        i = 1;
    }
    if (a != 0)
    {
        if (abs(y - b) % a == 0)
        {
            j = 0;
        }
        else
        {
            j = 1;
        }
    }
    else if (b == y)
    {
        j = 0;
    }
    else
    {
        j = 1;
    }

    if (i == 0 && j == 0)
    {
        cout << "Yes";
    }
    else
    {
        cout << "NO";
    }



    return 0;
}
