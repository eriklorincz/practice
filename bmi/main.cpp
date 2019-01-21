#include <iostream>
#include <cstdlib>
#include <ctime>

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
    person *head, *tail;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_end(string nname, double nweight, double nheight, double nbmi)
    {
        person *tmp = new person;
        tmp->name = nname;
        tmp->weight = nweight;
        tmp->height = nheight;
        tmp->bmi = nbmi;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }

    void add_first(string nname, double nweight, double nheight, double nbmi)
    {
        person *tmp = new person;
        tmp->name = nname;
        tmp->weight = nweight;
        tmp->height = nheight;
        tmp->bmi = nbmi;

        tmp->next = head;
        head = tmp;
    }

    void add_between(string nname, double nweight, double nheight, double nbmi, person *previous)
    {
        person *tmp = new person;
        tmp->name = nname;
        tmp->weight = nweight;
        tmp->height = nheight;
        tmp->bmi = nbmi;

        tmp->next = previous->next;
        previous->next = tmp;

    }

    void write_list()
    {
        person *tmp = head;

        system("cls");

        while (tmp != NULL)
        {
            cout << tmp->name << " " << tmp->weight << " kg " << tmp->height << " m  bmi: "<< tmp->bmi << endl;
            tmp = tmp->next;
        }
    }

    person* gethead()
    {
        return head;
    }

    person* place(string sname)
    {
        person *tmp = head;
        person *correct = tmp;

        while ((tmp != NULL) && (tmp->name < sname))
        {
            correct = tmp;
            tmp = tmp->next;
        }

        cout << correct->name << endl;

        return correct;
    }

    void maxbmi()
    {
        system("cls");

        person *tmp = head;
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

        if (aname != "0")
        {
            cout << "Weight: ";
            cin >> aweight;

            if(aweight != 0)
            {
                cout << "Height: ";
                cin >> aheight;

                if (aheight != 0)
                {
                    abmi = aweight / (aheight * aheight);

                    if(a.gethead() == NULL)
                    {
                        a.add_end(aname, aweight, aheight, abmi);
                    }
                    else if ((a.place(aname) == a.gethead()) && (aname < a.gethead()->name))
                    {
                        a.add_first(aname, aweight, aheight, abmi);
                    }
                    else if (a.place(aname)->next == NULL)
                    {
                        a.add_end(aname, aweight, aheight, abmi);
                    }
                    else
                    {
                        a.add_between(aname, aweight, aheight, abmi, a.place(aname));
                    }

                    a.write_list();

                }
            }
        }
    }

    a.maxbmi();

    person *i = a.gethead();
    person *j = i;
    while(i != NULL)
    {
        i = i->next;
        free(j);
    }

    return 0;
}
