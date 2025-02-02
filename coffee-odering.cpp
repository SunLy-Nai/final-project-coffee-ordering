#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void displayMenu () {
    cout << "\n----- COFFEE MENU ----\n";
    cout << "1. Expresso       $1.90\n";
    cout << "2. Ice Latte      $2.50\n";
    cout << "3. Green tea      $2.25\n";
    cout << "4. Mocha          $2.00\n";
    cout << "5. Americano      $2.35\n";
    cout << "6. Matcha         $2.15\n";
    cout << "7. Black coffee   $1.60\n";
}

int main () {
    string menu[] = {"Espresso","Ice Latte","Green Tea","Mocha","Americano","Matcha","Black coffee",""};
    double price[] = {1.90,2.50,2.25,2.00,2.35,2.15,1.60};

    string customName;
    cout << "Enter your name: ";
    getline(cin, customName);

    vector<string>orderItem;
    vector<double>orderPrice;
    char addMore;
    double totalPrice = 0.0;

    do
    {
        displayMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice < 1 || choice >7){
            cout << "Invalid choice! Please try again\n";
            continue;
        }
        orderItem.push_back(menu[choice -1]);
        double basePrice = price[choice - 1];
        double itemPrice = basePrice;

        char iceOrHot;
        cout << "Do you want ice or hot?\n";
        cout << "Ice(I) or Hot(H): ";
        cin >> iceOrHot;
        if (toupper(iceOrHot) == 'I'){
            int iceLevel;
            cout<< "1.Less ice\n";
            cout<< "2.Regular ice\n";
            cout<< "3.More ice\n";
            cout<< "Enter your ice level: ";
            cin >> iceLevel;
            switch (iceLevel){
                case 1:
                    orderItem.push_back("Less ice"); 
                    break;
                case 2:
                    orderItem.push_back("Regular ice"); 
                    break;
                case 3:
                    orderItem.push_back("More ice");
                    break;
                default:
                    cout << "Invalid input ice level => default is Regular\n";
                    orderItem.push_back("Regular ice");
                break;
            }
        } else if(toupper(iceOrHot) != 'I') {
            cout<< "Invalid input => set to default hot!\n";
        }
        
        int sizeItem;
        double costSize = 0.0;
        cout<< "1.small size (add 0.00$)\n";
        cout<< "2.medium size (add 0.50$)\n";
        cout<< "3.large size (add 1.00$\n";
        cout<< "Enter your size: ";
        cin>> sizeItem;
        switch (sizeItem) {
            case 1:
                orderItem.push_back("small size");
                costSize;
                break;
            case 2:
                orderItem.push_back("medium size");
                costSize += 0.50;
                break;
            case 3:
                orderItem.push_back("Larg size");
                costSize =+ 1.00;
                break;
            default :
                cout<< "Invalid input size => Default is small size";
                orderItem.push_back("small size");
                costSize;
                break;
        }
        itemPrice += costSize;
        orderPrice.push_back(itemPrice);


        int sweetLevel;
        cout<< "1.Less sweet\n";
        cout<< "2.Normal sweet\n";
        cout<< "3.More sweet\n";
        cout<< "Enter your sweet level: ";
        cin>> sweetLevel;
        switch (sweetLevel) {
            case 1: 
                orderItem.push_back("Less sweet");
                break;
            case 2:
                orderItem.push_back("Normal sweet");
                break;
            case 3:
                orderItem.push_back("More sweet");
                break;
            default:
                cout << "Invalid input sweet level => Default is normal sweet\n";
                orderItem.push_back("Normal sweet");
                break;
        }


        while (true)
        {
            cout << "Do you want to add more? (Y/N)\n";
            cout << "your answer is: ";
            cin >> addMore;
            if ( toupper(addMore) == 'Y' || toupper (addMore) == 'N' ){
                break;
            } else {
                cout << "Invalid input! Please enter 'Y' or 'N' ";
            }
        }   

    } while (toupper(addMore) == 'Y');
    
    for (double price : orderPrice){
        totalPrice += price;
    }
    cout << "\n----- YUOUR ORDER SUMMERY -----\n";
    cout << "Name customer: " << customName << endl;
    cout << "Item Ordered: \n";
    for(size_t i = 0; i < orderItem.size(); i++){
        cout << "- " << orderItem[i] << endl;
    }
    cout << "Total price: $" << fixed << setprecision(2) << totalPrice << endl;
    cout << "   ----Thank You----         ";
    return 0;
}