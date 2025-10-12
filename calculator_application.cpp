#include <iostream>
#include <vector>
#include <string>

//cout is pronounced "see-out". Used for output, and uses the insertion operator (<<)
//cin is pronounced "see-in". Used for input, and uses the extraction operator (>>)

using namespace std;

class calculator {
    public :
        virtual double calculate(double a, double b) = 0;
        virtual string getName() = 0;
};
class Add : public calculator{
    public : 
        double calculate(double a, double b) override {
            return a + b;
        }
        string getName() override { return "Addition";}
};
class Subtract : public calculator {
    public :
        double calculate(double a, double b) override {
            return a - b;
        }
        string getName() override {return "Subtraction";}
};
class Multiple : public calculator{
    public :
        double calculate(double a, double b) override{
            return a * b;
        }
        string getName() override { return "Multiplication";}
};
class Divide : public calculator{
    public :
        double calculate(double a, double b) override {
            if (b == 0) {
                return 0; 
        }
        return a / b;
    }
    string getName() override { return "Division"; }
};


void Menu() {
    cout << "Welcome to the calculator application!" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Substraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Fraction to decimal conversion" << endl;
    cout << "6. Exit" << endl;
    cout << "Please select an operation (1-6): ";


}


int main() {
    int choice;
    double number1, number2;

    while (true) {
        Menu();
        cin >> choice;

        if (choice == 6) {
            cout << "Exiting the application. See you next time!" << endl;
            break;
        }
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
            }

            char again;
            cout << "Do you want to perform another operation? (y/n): ";
            cin >> again;

            if (again == 'n' || again == 'N') {
                cout << "Exiting the application. See you next time!" << endl;
                break;
        }
        continue;
            
        }
    
    
        cout << "Enter the first number: ";
        cin >> number1;
        cout << "Enter the second number: ";
        cin >> number2;

        calculator* calculator = nullptr;

        switch(choice) {
            case 1: calculator = new Add(); break;
            case 2: calculator = new Subtract(); break;
            case 3: calculator = new Multiple(); break;
            case 4: calculator = new Divide(); break;
            default: 
                cout << "Invalid choice. Please try again.\n" ; 
                continue;
        }

        double result = calculator -> calculate(number1, number2);
        cout << "Result of " << calculator -> getName() << ": " << result << endl;

        char again;
        cout << "Do you want to perform another operation? (y/n): ";
        cin >> again;

        if (again == 'n' || again == 'N') {
            cout << "Exiting the application. See you next time!" << endl;
            break;
        }
    }
}