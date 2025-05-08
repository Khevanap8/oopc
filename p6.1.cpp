#include<iostream>

using namespace std;

struct abc
{
    int a, b;
    abc *n;

    void InsertData()
    {
        cout<<"Enter the value of A and B : ";
        cin >> a >> b;
        n = NULL;
        cout<<endl;
    }

    void DisplayData()
    {
        cout<<endl<<"--- Display Data ---"<<endl;
        cout << a << " " << b << endl<<endl;
    }
};

int main()
{
    abc *B = NULL, *t;
    int ch;

    next:

    cout<<"Enter your choice : ";
    cin >> ch;
    switch(ch)
    {
    case 1:
        {
        abc *p = new abc;
        p->InsertData();
        if (B == NULL)
        {
            B = p;
        } else
        {
            t = B;
            while (t->n != NULL)
            {
                t = t->n;
            }
            t->n = p;
        }
        goto next;
    }
    case 2:
        {
        if (B == NULL)
        {
            cout << "no data" << endl;
        } else
        {
            t = B;
            do
            {
                t->DisplayData();
                t = t->n;
            } while (t != NULL);
        }
        goto next;
    }
    default:
        break;
    }

    return 0;
}
