#include <iostream>
using namespace std;

class Bill
{
    int ProductId, ProductQuantity, ProductPrice;
    char ProductName[20];

public:
    void AddProductDetails();
    void DisplayProductDetails();
    void UpdateProductQuantity(int);
    int GetTotalBill();
};

void Bill::AddProductDetails()
{
    cout << "...ADD PRODUCT DETAILS..." << endl << endl;
    cout << "Enter product id: ";
    cin >> ProductId;
    cout << "Enter product name: ";
    cin>>ProductName;
    cout << "Enter the quantity of product: ";
    cin >> ProductQuantity;
    cout << "Enter the price of product: ";
    cin >> ProductPrice;
    cout << endl;
}

void Bill::UpdateProductQuantity(int id1)
 {
    if (ProductId == id1)
        {
            int quantity;
            cout << "...UPDATE PRODUCT QUANTITY..." << endl << endl;
            cout << "Enter the quantity that you want to add in stock: ";
            cin >> quantity;
            ProductQuantity += quantity;
            cout << "Stock updated successfully!" << endl << endl;
        }
}

int Bill::GetTotalBill()
{
    int Bill;
    Bill= ProductQuantity * ProductPrice;
}


void Bill::DisplayProductDetails()
{
    cout << "Product ID: " << ProductId << endl;
    cout << "Product Name: " << ProductName << endl;
    cout << "Quantity: " << ProductQuantity << endl;
    cout << "Price per unit: " << ProductPrice << endl;
    cout << "Total Bill for this product: " << GetTotalBill() << endl << endl;



}
int main()
 {
    int i, id, choice,a;
    Bill B[2];

    for (i = 0; i < 2; i++)
        {
            B[i].AddProductDetails();
        }

    a:
    cout << "Enter 1 to update stock quantity" << endl;
    cout << "Enter 2 to display product details and total bill" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
       {
           cout << "Enter product ID to add stock: ";
           cin >> id;
           for (i = 0; i < 2; i++)
            {
                B[i].UpdateProductQuantity(id);
            }
        break;
       }
    case 2:
       {
           int TotalBill=0;
           cout << "...PRODUCT DETAILS..." << endl << endl;
           for (i = 0; i < 2; i++)
           {
                B[i].DisplayProductDetails();
                TotalBill += B[i].GetTotalBill();
            }

            cout << "===================================" << endl;
            cout << "TOTAL BILL FOR ALL PRODUCTS: " << TotalBill << endl;
            cout << "===================================" << endl;

           goto e;
       }
    default:
       {
           cout << "Invalid choice. Exiting program..." << endl;
           break;
       }
    }
    goto a;

    e:return 0;
}

