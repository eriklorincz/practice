#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    long int n, i;
    double j;
    int steps = 0;

    cout << "The starting number: ";
    cin >> n;

    i = n;
    while (i != 1)
    {
        j = log2(i);
        if (j == floor(j))
        {
                steps = steps + long(j);
                i = 1;
        }
        else
        {
            i = i - pow(2, floor(j));
            steps++;
        }
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
