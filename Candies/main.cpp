#include <iostream>
#include <vector>

using namespace std;


long candies(int n, vector<int> arr)
{
    int num = 0;

    vector<int> candnum(n);
    for (int i = 0; i < n; i++)
    {
        candnum[i] = 1;
    }

    int i = 1;

    while (i < n)
    {
        if ((arr[i] > arr[i-1]) && (candnum[i] <= candnum[i-1]))
        {
            candnum[i] = candnum[i-1] + 1;
            i++;
        }
        else if ((arr[i] < arr[i-1]) && (candnum[i] >= candnum[i-1]))
        {
            candnum[i-1]++;
            i--;
        }
        else
        {
            i++;
        }
    }



    for (int i = 0; i < n; i++)
    {
        num = num + candnum[i];
    }

    return num;
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;

        arr[i] = arr_item;
    }

    long result = candies(n, arr);
    cout << result;


    return 0;
}
