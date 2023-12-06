#include <iostream>
#include <cstring>

class Person {
private:
    char* name;
    char* dateOfBirth;
    char* bloodGroup;
    double height;
    double weight;
    long insurancePolicyNumber;
    char* contactAddress;
    long phoneNumber;
    long drivingLicenseNumber;

public:
    // Constructor to initialize data
    Person(const char* n, const char* dob, const char* bg, double h, double w,
           long insurance, const char* address, long phone, long license)
        : height(h), weight(w), insurancePolicyNumber(insurance), phoneNumber(phone), drivingLicenseNumber(license) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);

        dateOfBirth = new char[strlen(dob) + 1];
        strcpy(dateOfBirth, dob);

        bloodGroup = new char[strlen(bg) + 1];
        strcpy(bloodGroup, bg);

        contactAddress = new char[strlen(address) + 1];
        strcpy(contactAddress, address);
    }

    // Default constructor
    Person() : name(nullptr), dateOfBirth(nullptr), bloodGroup(nullptr),
               height(0), weight(0), insurancePolicyNumber(0),
               contactAddress(nullptr), phoneNumber(0), drivingLicenseNumber(0) {}

    // Copy constructor
    Person(const Person& other) {
        // Deep copy
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        dateOfBirth = new char[strlen(other.dateOfBirth) + 1];
        strcpy(dateOfBirth, other.dateOfBirth);

        bloodGroup = new char[strlen(other.bloodGroup) + 1];
        strcpy(bloodGroup, other.bloodGroup);

        height = other.height;
        weight = other.weight;
        insurancePolicyNumber = other.insurancePolicyNumber;

        contactAddress = new char[strlen(other.contactAddress) + 1];
        strcpy(contactAddress, other.contactAddress);

        phoneNumber = other.phoneNumber;
        drivingLicenseNumber = other.drivingLicenseNumber;
    }

    // Destructor to free dynamic memory
    ~Person() {
        delete[] name;
        delete[] dateOfBirth;
        delete[] bloodGroup;
        delete[] contactAddress;
    }

    // Static member function
    static void displayStaticInfo() {
        std::cout << "This is a static member function.\n";
    }

    // Friend class
    friend class FriendClass;

    // Getter for name
    const char* getName() const {
        return name;
    }

    // Dynamic memory allocation with new and delete operators
    void updateContactAddress(const char* newAddress) {
        delete[] contactAddress;
        contactAddress = new char[strlen(newAddress) + 1];
        strcpy(contactAddress, newAddress);
    }

    // Display information
    void displayInfo() const {
        std::cout << "\nName: " << name << "\nDate of Birth: " << dateOfBirth
                  << "\nBlood Group: " << bloodGroup << "\nHeight: " << height
                  << "\nWeight: " << weight << "\nInsurance Policy Number: " << insurancePolicyNumber
                  << "\nContact Address: " << contactAddress << "\nPhone Number: " << phoneNumber
                  << "\nDriving License Number: " << drivingLicenseNumber << "\n";
    }
};

// Friend class
class FriendClass {
public:
    static void displayFriendInfo(const Person& person) {
        std::cout << "Friend Class accessing private member - Name: " << person.name << std::endl;
    }
};

int main() {
    // Creating objects using constructors
    Person person1("John Doe", "01-01-1990", "A+", 175.5, 70.5, 123456789, "123 Main St", 9876543210, 987654);

    // Displaying information
    person1.displayInfo();

    // Using dynamic memory allocation and inline code
    person1.updateContactAddress("456 Side St");

    // Displaying updated information
    person1.displayInfo();

    // Using static member function
    Person::displayStaticInfo();

    // Using friend class
    FriendClass::displayFriendInfo(person1);

    return 0;
}
