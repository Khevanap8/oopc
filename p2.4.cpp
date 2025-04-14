#include<iostream>
#include<string.h>
using namespace std;

class Items
{
    int Id;
    string Name;
    double Price;
    int StockQuantity;

public:

    void AddItems()
    {
        cout<<"Enter the id of product : "<<endl;
        cin>>Id;
        cout<<"Enter the name of product : "<<endl;
        cin>>Name;
        cout<<"Enter the price of product : "<<endl;
        cin>>Price;
        cout<<"Enter the quantity of product : "<<endl;
        cin>>StockQuantity;

    }
    void DisplayItems(int id)
    {
        if(id==Id)
        {
            cout<<"___DISPLAY THE DETAIL OF GIVEN ID___"<<endl;
            cout<<"id : "<<Id<<endl;
            cout<<"name : "<<Name<<endl;
            cout<<"price : "<<Price<<endl;
            cout<<"available stock : "<<StockQuantity<<endl;
        }
    }
    void SearchItems(int id1)
    {
        if(id1==Id)
        {
            cout<<"___THIS ID IS AVAILABEL___"<<endl;
            cout<<"id : "<<Id<<endl;
            cout<<"name : "<<Name<<endl;
            cout<<"price : "<<Price<<endl;
            cout<<"available stock : "<<StockQuantity<<endl;
        }
    }

    void AddStocks(int id2)
    {
        int addstock;
        if(id2==Id)
        {
            cout<<"___ENTER THE QUANTITY OF STOCK WHICH YOU ADDED___"<<endl;
            cin>>addstock;
            StockQuantity+=addstock;
            cout<<"After add stock : "<<endl;
            cout<<StockQuantity<<endl;
        }

    }
    void DeleteStock(int id3)
    {
        int deletestock;
        if(id3==Id)
        {
            cout<<"___ENTER THE QUANTITY OF STOCK WHICH YOU NEED TO DELETE___"<<endl;
            cin>>deletestock;
            if(deletestock>StockQuantity)
            {
                cout<<"ERROR";
            }
            else
            {
               StockQuantity-=deletestock;
               cout<<"After add stock : ";
               cout<<StockQuantity<<endl;
            }

        }

    }

};

int main()
{
    Items a[2];
    int id1,id2,id3;
    int id;
    int c=0;
    while(true)
{
    cout<<"SELECT THE NUMBER"<<endl<<"1.Add Items"<<endl<<"2.Display Items"<<endl<<"3.Search Items"<<endl<<"4.Add Stock"<<endl<<"5.Delete Stock"<<endl<<"6.exit"<<endl;
    int i;

    cin>>i;
    switch(i)
    {
    case 1:
        {
            if(c<2)
            {
                a[c].AddItems();
                c++;
            }
            else
            {
                cout<<"Maximum limit reached!";
            }
        }
          break;
    case 2:
        {
                cout<<"Enter the id : "<<endl;
                cin>>id;
                for(int i=0;i<c;i++)
                {
                  a[i].DisplayItems(id);
                }
        }
          break;
    case 3:
        {
            cout<<"Enter the id : "<<endl;
            cin>>id1;
            for(int i=0;i<c;i++)
            {
               a[i].SearchItems(id1);
            }
        }
          break;
    case 4:
        {
            cout<<"Enter the id : "<<endl;
            cin>>id2;
            for(int i=0;i<c;i++)
            {
            a[i].AddStocks(id2);

            }
        }
          break;
    case 5:
        {
            cout<<"Enter the id : "<<endl;
            cin>>id3;
            for(int i=0;i<c;i++)
           {
              a[i].DeleteStock(id3);

           }
        }
          break;
     case 6:
                cout << "EXITING PROGRAM..." << endl;
                return 0;

    default:

            cout<<"EXIT"<<endl;

    }
}

}

