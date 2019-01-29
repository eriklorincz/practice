#include <iostream>
#include <vector>

using namespace std;

vector<int> bonetrousle(int k, int b, int n)
{
    vector<int> boxToBuy;
    int boxes;

    int shopspag = 0;

    for (int i = 1; i <= k; i++)
    {
        shopspag = shopspag + i;
    }

    if ((shopspag < n) || (b == 1 && n > k) || (b > k))
    {
        boxToBuy.push_back(-1);
    }
    else
    {
        int i = k;
        int cart = 0;

        while(i >= 1)// && ((cart != n) || (boxToBuy.size() != b)))
        {
            cout << i << endl << endl;

            if (i + cart > n)
            {
                i--;
                cout << ">\n";
            }

            else if(i == 1/* && i + cart <= n*/ && boxToBuy.size() < b-1 && boxToBuy.size() > 0)
            {
                i = boxToBuy.back()-1;
                cout << boxToBuy.back();
                cart = cart - boxToBuy.back();
                boxToBuy.pop_back();
               // boxToBuy.push_back(i);
                //cart = cart + i;
                cout<<"egy" << i;
            }

            else if ((i + cart == n) && (boxToBuy.size() < b-1))
            {
                i--;
                cout << "equal n\n";
            }

            else if ((i + cart < n) && (boxToBuy.size() == b-1))
            {
                i = boxToBuy.back()-1;
                cart = cart - boxToBuy.back();
                boxToBuy.pop_back();

            }
            else if (i + cart <= n)
            {
                boxToBuy.push_back(i);
                cart = cart + i;
                i--;
            }


            for (int j = 0; j < boxToBuy.size(); j++)
            {
                cout <<"inbox:" <<boxToBuy[j] << endl;
            }

            cout<<"boxsize:" << boxToBuy.size() << endl;
            //cout << i << endl << endl;

            if (i < 1 && boxToBuy.size() <= 1 && b != 1)
            {
                boxToBuy.clear();
                boxToBuy.push_back(-1);
            }
        }
    }

    return boxToBuy;
}

int main()
{
    int b, n, k;
    vector<int> result;

    cout << "Boxes in store: ";
    cin>>k;
    cout << "Boxes to buy: ";
    cin>>b;
    cout << "Sticks to buy: ";
    cin>>n;

    result = bonetrousle(k, b, n);

    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
