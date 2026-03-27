/*
Lab2: Loan Payments and Interest
Robert Pace
COSC-1436-21005; Spring 2026
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

// Function prototypes
double getLoanAmount();
double getInterestRate();
double getMonthlyPayment();

int main() {
    std::cout << "Lab2: Loan Payments and Interest\n";
    std::cout << "Robert Pace\n";
    std::cout << "COSC-1436-21005; Spring 2026\n\n";

    double loanAmount = getLoanAmount();
    double annualRate = getInterestRate();
    double monthlyRate = annualRate / 100 / 12;
    double monthlyPayment = getMonthlyPayment();

    double remainingBalance = loanAmount;
    double totalInterest = 0;
    double totalPaid = 0;
    int month = 0;

    std::cout << std::fixed << std::setprecision(2);

    // Table header
    std::cout << "\n" << std::string(80, '=') << std::endl;
    std::cout << std::setw(10) << "Month" 
              << std::setw(15) << "Payment" 
              << std::setw(15) << "Interest" 
              << std::setw(15) << "Principal" 
              << std::setw(15) << "Balance" << std::endl;
    std::cout << std::string(80, '-') << std::endl;

    // Loop until loan is paid off
    while (remainingBalance > 0) {
        month++;

        double monthlyInterest = remainingBalance * monthlyRate;
        double payment = monthlyPayment;

        // Final payment adjustment (prevents overpaying)
        if (payment > remainingBalance + monthlyInterest) {
            payment = remainingBalance + monthlyInterest;
        }

        double principal = payment - monthlyInterest;
        
        remainingBalance -= principal;
        totalInterest += monthlyInterest;
        totalPaid += payment;

        // Table row with proper fill this time for alignment
        std::cout << std::setw(10) << month
                  << std::setw(15) << payment
                  << std::setw(15) << monthlyInterest
                  << std::setw(15) << principal
                  << std::setw(15) << (remainingBalance < 0 ? 0 : remainingBalance) << std::endl;

        // 30 year safety break
        if (month > 360) break;
    }

    // Summary Table
    std::cout << std::string(80, '=') << std::endl;
    std::cout << "\nSummary of Loan:" << std::endl;
    std::cout << "Initial Loan Amount: $" << loanAmount << std::endl;
    std::cout << "Monthly Payment: $" << monthlyPayment << std::endl;
    std::cout << "Total Amount Paid: $" << totalPaid << std::endl;
    std::cout << "Total Interest Paid: $" << totalInterest << std::endl;
    std::cout << "Number of Months: " << month << std::endl;

    return 0;
}

double getLoanAmount() {
    double amount;
    std::cout << "Enter loan amount (1-100; decimals allowed): ";
    
    while (!(std::cin >> amount) || amount < 1 || amount > 1000) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Entry. Try entering an amount between 1 and 1000: ";
    }
    return amount;
}

double getInterestRate() {
    double rate;
    std::cout << "Enter annual interest rate (1-100; decimals allowed): ";
    
    while(!(std::cin >> rate) || rate < 1 || rate > 100) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Entry. Try entering a rate between 1 and 100: ";
    }
    return rate;
}

double getMonthlyPayment() {
    double payment;
    std::cout << "Enter fixed monthly payment amount: ";
    
    while(!(std::cin >> payment) || payment <= 0) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Entry. Try entering a positive payment amount: ";
    }
    return payment;
}