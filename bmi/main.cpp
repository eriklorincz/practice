#include <iostream>
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

class Linked_list
{
private:
    person *head;

public:
    Linked_list()
    {
        head = new person;
        head->next = nullptr;
    }

    void add_ordered(person *tmp)
    {
        person *temp = head;
        person *correct = temp;


        //searching for the correct place to insert the next
        while (temp  && (temp->name < tmp->name))
        {
            correct = temp;
            temp = temp->next;
        }

        tmp->next = correct->next;
        correct->next = tmp;

    }

    //print the full list on the screen
    void write_list()
    {
        person *tmp = head->next;

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

        while(tmp != nullptr)
        {
            if (maxim->bmi < tmp->bmi)
            {
                maxim = tmp;
            }
            tmp = tmp->next;
        }

        cout << "And the winner is:\n" << maxim->name << " " << maxim->weight << " kg " << maxim->height << " m  bmi: " << maxim->bmi;

    }

    ~Linked_list()
    {
        person *i = head;
        person *j = i;
        while(i)
        {
            j = i;
            i = i->next;
            delete j;
        }
    }

};

int main()
{
    string aname = " ";
    double aweight = -1;
    double aheight = -1;
    double abmi;

    Linked_list a;

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

        person* nperson = new person;

        nperson->name = aname;
        nperson->weight = aweight;
        nperson->height = aheight;
        nperson->bmi = abmi;
        nperson->next = nullptr;

        a.add_ordered(nperson);
        a.write_list();

    }

    if (a.gethead()->next)
    {
        a.maxbmi();
    }

    return 0;
}
