#include <iostream>
using namespace std;

float get_tax_rate() {
    float tax_rate;
    cout << "Please enter tax rate from 0-100: ";
    cin >> tax_rate;
    if (tax_rate < 0 || tax_rate > 100) {
        cout << "Value must be 0-100 " << endl;
        return(get_tax_rate());
    }
    return (tax_rate);
}

float get_insurance_cost() {
    float insurance_cost;
    cout << "Please enter insurance cost: ";
    cin >> insurance_cost;
    if (insurance_cost < 0) {
        cout << "Please enter a positive value ";
        return (get_insurance_cost());
    }
    return (insurance_cost);
}

float get_initial_cost() {
    float initial_cost;
    cout << "Please enter initial cost: ";
    cin >> initial_cost;
    if (initial_cost < 0) {
        cout << "Please enter a positive value ";
        return get_initial_cost();
    }
    return (initial_cost);
}

float get_property_tax(float initial_cost, float tax_rate ) {
    return (initial_cost * tax_rate / 100);
}

float get_total_cost(float initial_cost, float property_tax, float insurance_cost) {
    return (initial_cost + property_tax + insurance_cost);
}

void main_program() {
    char decision;
    float initial_cost;

    // Get user inputs
    initial_cost = get_initial_cost();
    float tax_rate = get_tax_rate();
    float insurance_cost = get_insurance_cost();
    
    // Calculate values
    float tax_amount = get_property_tax(initial_cost, tax_rate);
    float total_cost = get_total_cost(initial_cost, tax_amount, insurance_cost);

    cout << "Annual property tax: $" << tax_amount << endl;
    cout << "Annual After-Tax Cost: $" << total_cost << endl;

    cout << "Enter y if you would like to run the program again ";
    cin >> decision;
    if (decision == 'y' || decision == 'Y') {
        main_program();
    }
    else {
        cout << "Program finished ";
    }
}

int main() {
    main_program();
    return 0;
}