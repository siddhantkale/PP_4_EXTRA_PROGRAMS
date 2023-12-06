#include <iostream>
#include <iomanip>

class WeatherReport {
private:
    int day_of_month;
    int high_temp;
    int low_temp;
    float amount_rain;
    float amount_snow;

public:
    WeatherReport() : day_of_month(99), high_temp(999), low_temp(-999), amount_rain(0), amount_snow(0) {}

    void enterData() {
        std::cout << "Enter day of month: ";
        std::cin >> day_of_month;

        std::cout << "Enter high temperature: ";
        std::cin >> high_temp;

        std::cout << "Enter low temperature: ";
        std::cin >> low_temp;

        std::cout << "Enter amount of rain: ";
        std::cin >> amount_rain;

        std::cout << "Enter amount of snow: ";
        std::cin >> amount_snow;
    }

    void displayReport() const {
        std::cout << "Day of Month: " << day_of_month << std::endl;
        std::cout << "High Temperature: " << high_temp << std::endl;
        std::cout << "Low Temperature: " << low_temp << std::endl;
        std::cout << "Amount of Rain: " << amount_rain << std::endl;
        std::cout << "Amount of Snow: " << amount_snow << std::endl;
    }
};

int main() {
    WeatherReport monthlyReport[30];  // Assuming a month has 30 days for simplicity

    int choice;
    do {
        std::cout << "\nMenu:\n1. Enter Data\n2. Display Report\n3. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int day;
                std::cout << "Enter day of month (1-30): ";
                std::cin >> day;

                if (day >= 1 && day <= 30) {
                    monthlyReport[day - 1].enterData();
                } else {
                    std::cout << "Invalid day. Please enter a day between 1 and 30." << std::endl;
                }
                break;

            case 2:
                std::cout << "\nMonthly Weather Report:\n";
                for (int i = 0; i < 30; ++i) {
                    std::cout << "\nDay " << (i + 1) << ":\n";
                    monthlyReport[i].displayReport();
                }
                break;

            case 3:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 3);

    return 0;
}
