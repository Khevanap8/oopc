#include<iostream>
using namespace std;

class PlotData
{
    int l,w,area,perimeter;
    public:
        void AddPlotData()
        {
            cout<<"_____ADD PLOT DATA_____"<<endl<<endl;
            cout<<"Enter length of the plot : ";
            cin>>l;
            cout<<"Enter width of the plot : ";
            cin>>w;
            cout<<endl<<endl;
            area=l*w;
            perimeter=2*(l+w);
        }

        void UpdatePlotData()
        {
            cout<<"_____UPDATE PLOT DATA_____"<<endl<<endl;
            cout<<"Enter length of the plot : ";
            cin>>l;
            cout<<"Enter width of the plot : ";
            cin>>w;
            cout<<endl<<endl;
            area=l*w;
            perimeter=2*(l+w);
        }

        void DisplayPlotData()
        {
            cout<<"_____DISPLAY PLOT DATA_____"<<endl<<endl;
            cout<<"Length is "<<l<<endl<<"Width is "<<w<<endl;
            cout << "-----------------------------------"<<endl;
            cout<<"Area is "<<area<<endl<<"Perimeter is "<<perimeter<<endl;
            cout << "-----------------------------------"<<endl<<endl;
        }


};

int main()
{
    PlotData P[10];

        int choice,c=0,PN,i,X,E,A;
        X:
        cout<<"Enter 1 for Add data"<<endl<<"Enter 2 for Update data"<<endl<<"Enter 3 for Display data"<<endl<<"else Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        cout<<endl<<endl;
        switch(choice)
        {
            case 1:
            {
                P[c].AddPlotData();
                c++;
                break;

            }
            case 2:
                {
                    A:
                    cout<<"Enter plot number for update the data : ";
                    cin>>PN;
                    if(PN<=c)
                    {
                        P[PN-1].UpdatePlotData();
                        break;

                    }
                    else
                    {
                        cout<<"your plot number is more than "<<c<<" so enter correct plot number";
                        goto A;
                    }
                }
            case 3:
                {
                    cout<<"Enter plot number for display the data : ";
                    cin>>PN;
                    if(PN<=c)
                    {
                        for(i=0;i<c;i++)
                        {
                            P[PN-1].DisplayPlotData();
                        }
                    }
                    else
                    {
                        cout<<"Enter valid plot number";

                    }

                        break;

                }
            default:
                {
                    cout<<"Exit from the program...";
                    goto E;
                }
        }
        goto X;

    E:return 0;
}
