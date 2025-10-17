#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

//cout is pronounced "see-out". Used for output, and uses the insertion operator (<<)
//cin is pronounced "see-in". Used for input, and uses the extraction operator (>>)

using namespace std;

// base abstract class
// This class defines the interface for all all types of calculators operations
class calculator {
    public :
        virtual double calculate(double a, double b) = 0; // Pure virtual function
        virtual string getName() = 0; // Operation name
        virtual ~calculator() {} // Virtual destructor
};
// derived class for addition
class Add : public calculator{
    public : 
        double calculate(double a, double b) override {
            return a + b;
        }
        string getName() override { return "Addition";}
};
// derived class for substractiion
class Subtraction : public calculator {
    public :
        double calculate(double a, double b) override {
            return a - b;
        }
        string getName() override {return "Subtraction";}
};
// derived class for multiplication
class Multiple : public calculator{
    public :
        double calculate(double a, double b) override{
            return a * b;
        }
        string getName() override { return "Multiplication";}
};
// derived class for division
class Divide : public calculator{
    public :
        double calculate(double a, double b) override {
            if (b == 0) {
                cout << "Error! Please enter a non-zero denominator." << endl;
                return 0; 
        }
        return a / b;
    }
    string getName() override { return "Division"; }
};

// Function to format numbers with one decimal place
string format(double number) {
    ostringstream out;
    out << fixed << setprecision(1) << number;
    return out.str();
}
//display menu
void Menu() {
    cout << "------------------------------------------------------" << endl;
    cout << "Welcome to the calculator application!" << endl;
    cout << "======================================================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Fraction to decimal conversion" << endl;
    cout << "6. Exit" << endl;
    cout << "Please select an operation (1-6): ";


}

//main function
int main() {
    int choice;
    double number1, number2;
    vector<string> history; // to store history of calculations


    while (true) {
        Menu(); //show menu
        cin >> choice;

        //exit option
        if (choice == 6) {
            break;
        }
        // fraction to decimal conversion option
        if (choice == 5) {
            double numerator, denominator;
            cout << "Enter the numerator: ";
            cin >> numerator;
            cout << "Enter the denominator: ";
            cin >> denominator;

            if (denominator == 0) {
                cout << "Error! Please enter a non-zero denominator." << endl;
            }
            else {
                double result = numerator / denominator;
                cout << "The decimal value is: " << result << endl;
                history.push_back(format(numerator) + '/' + format(denominator) + " = " + format(result));
            }

            char again;
            cout << "Do you want to perform another operation? (y/n): ";
            cin >> again;

            if (again == 'n' || again == 'N') 
            break;continue;
        
        
            
        }
    
        // Regular calculator operations
        cout << "Enter the first number: ";
        cin >> number1;
        cout << "Enter the second number: ";
        cin >> number2;

        calculator* cal = nullptr;
        string symbol;

        switch (choice) {
            case 1: cal = new Add(); symbol = "+" ; break;
            case 2: cal = new Subtraction(); symbol = "-"; break;
            case 3: cal = new Multiple(); symbol = "*"; break;
            case 4: cal = new Divide(); symbol = "/"; break;
            default: 
                cout << "Invalid choice. Please try again.\n" ; 
                continue;
        }

        // show result
        double result = cal -> calculate(number1, number2);
        cout << "Result of " << cal -> getName() << ": " << result << endl;
        history.push_back(format(number1) + "" + symbol + format(number2) + " = " + format(result));

        delete cal; // free memory
        // ask user if they want to perform another operation
        char again;
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> again;

        if (again == 'n' || again == 'N') break;
    
    }
    // I used ChatGPT to help me understand how to use the C++ Standard Template Library (STL), specifically how to implement a std::vector to store and display the calculation history in my program.
    // The AI provided example code and explanations about how to:
                // Declare and initialize a vector to hold past results
                // Add new results using the push_back() method
                // Iterate through the vector with a for loop to print all stored calculations
    if (!history.empty()) {
        cout << "\nCalculation History:\n" ;
        for (size_t i = 0; i < history.size(); ++i) {
                cout << i + 1 << ": " << history[i] << endl;
            }
          
    }

    cout << "Exiting the application. See you next time!" << endl;
    return 0;
}