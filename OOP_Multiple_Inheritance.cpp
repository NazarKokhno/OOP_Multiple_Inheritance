#include <iostream>
#include <string>

using namespace std;


// Task 1
class Address
{
protected:
    string streetName;
    int houseNumber;
    string cityName;
public:
    Address(string streetName = "NoInfo",int houseNumber = 0,string cityName = "NoInfo") 
        : streetName(streetName),houseNumber(houseNumber),cityName(cityName) {}

    void Show() const
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

class Parrot : public Pet
{
private:
    string type;
    bool canSpeak;
public:
    Parrot(string name = "NoInfo", int age = 0, string type = "NoInfo", bool canSpeak = false)
        : Pet(name, age), type(type), canSpeak(canSpeak)
    {
    }

    void Sound() const override
    {
        cout << (canSpeak ? "Hello!" : "Squawk!") << endl;
    }
    void Show() const override
    {
        Pet::Show();
        cout << "Can speak: " << (canSpeak ? "Yes" : "No") << endl;
    }
    void Type() const override
    {
        cout << "Type: " << type << endl;
    }
};

class Hamster : public Pet
{
private:
    string type;
    bool activeAtNight;
public:
    Hamster(string name = "NoInfo", int age = 0, string type = "NoInfo", bool activeAtNight = false)
        : Pet(name, age), type(type), activeAtNight(activeAtNight)
    {
    }

    void Sound() const override
    {
        cout << "Squeak!" << endl;
    }
    void Show() const override
    {
        Pet::Show();
        cout << "Active at night: " << (activeAtNight ? "Yes" : "No") << endl;
    }
    void Type() const override
    {
        cout << "Type: " << type << endl;
    }
};


class Zoo : public Dog, public Cat, public Parrot, public Hamster
{
private:
    Address address;
    string name;
public:
    Zoo(
        string streetName, int houseNumber, string cityName,
        string zooName,

        string dogName, int dogAge, string dogBreed,

        string catName, int catAge, string catBreed, bool isIndoor,

        string parrotName, int parrotAge, string parrotType, bool canSpeak,

        string hamsterName, int hamsterAge, string hamsterType, bool activeAtNight
    )
        : Dog(dogName, dogAge, dogBreed),
        Cat(catName, catAge, catBreed, isIndoor),
        Parrot(parrotName, parrotAge, parrotType, canSpeak),
        Hamster(hamsterName, hamsterAge, hamsterType, activeAtNight),
        address(streetName, houseNumber, cityName),
        name(zooName) {}

    void Show() const
    {
        cout << "Zoo name: " << name << endl;
        address.Show();
    }

};

int main()
{
    Zoo zoo(
        "Shevchenka", 15, "Kyiv", "Happy Zoo",

        "Rex", 5, "German Shepherd",

        "Barsik", 3, "British Shorthair", true,

        "Kesha", 2, "Macaw", true,

        "Homa", 1, "Syrian", true
    );

    cout << "===== ZOO =====" << endl;
    zoo.Show();

    cout << "\n===== DOG =====" << endl;
    zoo.Dog::Show();
    zoo.Dog::Type();
    zoo.Dog::Sound();

    cout << "\n===== CAT =====" << endl;
    zoo.Cat::Show();
    zoo.Cat::Type();
    zoo.Cat::Sound();

    cout << "\n===== PARROT =====" << endl;
    zoo.Parrot::Show();
    zoo.Parrot::Type();
    zoo.Parrot::Sound();

    cout << "\n===== HAMSTER =====" << endl;
    zoo.Hamster::Show();
    zoo.Hamster::Type();
    zoo.Hamster::Sound();

    return 0;
}
