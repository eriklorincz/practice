#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

struct person
{
    string name;
    double weight;
    double height;
    double bmi;
    person *next;

};

class linked_list
{
private:
    person *head;

public:
    linked_list()
    {
        head = new person;
        head->next = nullptr;
    }

    void add_ordered(string nname, double nweight, double nheight, double nbmi)
    {
        person *temp = new person;
        person *correct = new person;
        temp = head;
        correct = temp;


        //searching for the correct place to insert the next
        while ((temp != nullptr) && (temp->name < nname))
        {
            correct = temp;
            temp = temp->next;
        }

        person *tmp = new person;

        tmp->name = nname;
        tmp->weight = nweight;
        tmp->height = nheight;
        tmp->bmi = nbmi;
        tmp->next = nullptr;


        tmp->next = correct->next;
        correct->next = tmp;

    }

    //print the full list on the screen
    void write_list()
    {
        person *tmp = new person;
        tmp = head->next;

        system("cls");

        while (tmp != nullptr)
        {
            cout << tmp->name << " " << tmp->weight << " kg " << tmp->height << " m  bmi: "<< tmp->bmi << endl;
            tmp = tmp->next;
        }
    }

    person* gethead()
    {
        return head;
    }


    //find the highest-bmi person and print the data on screen
    void maxbmi()
    {
        system("cls");

        person *tmp = head->next;
        person *maxim = tmp;

        while(tmp != NULL)
        {
            if (maxim->bmi < tmp->bmi)
            {
                maxim = tmp;
            }
            tmp = tmp->next;
        }

        cout << "And the winner is:\n" << maxim->name << " " << maxim->weight << " kg " << maxim->height << " m  bmi: " << maxim->bmi;

    }

};

int main()
{
    string aname = " ";
    double aweight = -1;
    double aheight = -1;
    double abmi;

    linked_list a;

    while((aname != "0") && (aweight != 0) && (aheight != 0))
    {
        cout << "Name: ";
        cin >> aname;

        if (aname == "0") break;

        cout << "Weight: ";
        cin >> aweight;

        if(aweight == 0) break;

        cout << "Height: ";
        cin >> aheight;

        if (aheight == 0) break;

        abmi = aweight / (aheight * aheight);

        a.add_ordered(aname, aweight, aheight, abmi);
        a.write_list();

    }

    if (a.gethead() != nullptr)
    {
        a.maxbmi();

        person *i = a.gethead();
        person *j = i;
        while(i != NULL)
        {
            j = i;
            i = i->next;
            free(j);
        }
    }

    return 0;
}
