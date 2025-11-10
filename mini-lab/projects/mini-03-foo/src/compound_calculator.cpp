#include <iostream>
#include <cmath>

double compound (double principal, double rate, int years) {
    return principal * pow(1 + rate, years);
}

double loan (double principal, double rate, int years) {
    return principal * (1 + rate * years);
}

double percent_gain(double ending, double initial){
    double gain = (ending - initial);
    double percent_gain = (gain / initial) * 100.0;
    return percent_gain;
}

int main(){
    double principal, rate;
    int years;

    std::cout << "Enter principal: " << std::endl;
    std::cin >> principal;

    std::cout << "Enter a rate: " << std::endl;
    std::cin >> rate;

    std::cout << "Enter number of years: " << std::endl;
    std::cin >> years;

    loan(principal, rate, years);
    std::cout << "The total: " << std::endl;

    rate /= 100;

    double compound_amt, loan_amt;
    compound_amt = compound(principal, rate, years);
    loan_amt = loan(principal, rate, years);
   
    std::cout << "\nCompound Interest Total: $" << compound_amt << std::endl;
    std::cout << "Total gain: " << percent_gain(compound_amt, principal) << "%" << std::endl;
    std::cout << "Simple Loan total: $" << loan_amt << std::endl;
    std::cout << "Total gain: " << percent_gain(loan_amt, principal) <<" %" << std::endl;

        return 0;
}