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

class Pet
{
protected:
    string name;
    int age;
public:
    Pet(string name = "NoInfo",int age = 0)
        : name(name), age(age)
    {
        if (age < 0 || age > 100)
        {
            cout << "Error! Non-existent Age" << endl;
            this->age = 0;
        }

    }

    virtual void Sound() const = 0;
    virtual void Show() const
    {
        cout << "Name: " << name
            << "\nAge: " << age << endl;
    }
    virtual void Type() const = 0;
};

class Dog : public Pet
{
private:
    string breed;
public:
    Dog(string name = "NoInfo", int age = 0, string breed = "NoInfo") : Pet(name, age), breed(breed)
    {
     
    }

    void Sound() const override
    {
        cout << "Woof! Woof!" << endl;
    }
    void Show() const override
    {
        Pet::Show();
    }
    void Type() const override
    {
        cout << "Breed: " << breed << endl;
    }

};

class Cat : public Pet
{
private:
    string breed;
    bool isIndoor;
public:
    Cat(string name = "NoInfo", int age = 0, string breed = "NoInfo",bool isIndoor = false) 
        : Pet(name, age), breed(breed),isIndoor(isIndoor)
    {

    }

    void Sound() const override
    {
        cout << "Meow!" << endl;
    }
    void Show() const override
    {
        Pet::Show();
        cout << "Indoor cat: " << (isIndoor ? "Yes" : "No") << endl;
    }
    void Type() const override
    {
        cout << "Breed: " << breed << endl;
    }

};


int main()
{
    Dog dog("Rex", 5, "German Shepherd");

    dog.Sound();
    dog.Show();
    dog.Type();

    cout << endl;

    Cat cat("Barsik", 3, "British Shorthair");
    cat.Sound();
    cat.Show();
    cat.Type();

    return 0;
}

