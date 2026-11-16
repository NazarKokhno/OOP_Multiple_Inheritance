#include <iostream>
#include <string>

using namespace std;

class Address
{
protected:
    string streetName;
    int houseNumber;
    string cityName;
public:
    Address(string streetName = "NoInfo",int houseNumber = 0,string cityName = "NoInfo") 
        : streetName(streetName),houseNumber(houseNumber),cityName(cityName) {}

    void Show()
    {
        cout << "Street: " << streetName
            << "\nHouse: " << houseNumber
            << "\nCity: " << cityName << endl;
    }

};

    

int main()
{

    
}

