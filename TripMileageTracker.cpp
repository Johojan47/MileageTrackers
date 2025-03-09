#include <iostream>
#include <fstream>
#include <stdexcept>

// Step 5: Custom Exception Class
class InvalidMileageException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Please try again. The starting mileage cannot be greater than destination mileage.";
    }
};

// Step 6: Function to calculate mileage
double calculateMileage(double startMileage, double destMileage) {
    if (startMileage < 0 || destMileage < 0) {
        throw std::invalid_argument("Mileage cannot be negative.");
    }
    if (startMileage > destMileage) {
        throw InvalidMileageException();
    }
    return destMileage - startMileage;
}

int main() {
    double startMileage, destMileage;

    while (true) {
        try {
            // Step 1: User Input Handling
            std::cout << "Enter starting mileage: ";
            std::cin >> startMileage;
            std::cout << "Enter destination mileage: ";
            std::cin >> destMileage;

            // Step 2: Calculate Miles Traveled
            double milesTraveled = calculateMileage(startMileage, destMileage);
            std::cout << "Miles traveled: " << milesTraveled << std::endl;
            break; // Exit loop if input is valid
        }
        catch (const InvalidMileageException& e) {
            // Step 3: Handle invalid mileage
            std::cerr << "Error: " << e.what() << std::endl;
        }
        catch (const std::invalid_argument& e) {
            // Step 4: Handle negative inputs
            std::cerr << "Error: " << e.what() << std::endl;
        }
        catch (...) {
            // Step 7: Handle other exceptions
            std::cerr << "Error occurred. Please try again." << std::endl;
        }
    }

    // Step 7: Log errors to a file (example)
    std::ofstream logFile("error_log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << "Program executed successfully.\n";
        logFile.close();
    }

    return 0;
}