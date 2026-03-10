


//main things to fix
//it can break if you try putting in fractions of pennies
//table isn't built properly





#include <iostream>
#include <iomanip>
//we're not sure if this proprocessor directive is allowed or not, may have to change it later
//found it, this Limits part is the thing we use for
//those long input buffer
#include <limits>

//random notes to self
//the std:: namespace stuff applies even to the iomanip stuff


//yup, these aren't variables, they're Functions
//also called 'Function Prototypes'; we may rename these later too so it's intuitive
double getLoanAmount();
double getInterestRate();
double getMonthlyPayment(double remainingBalance);

//attempting to use the void we practiced
int main() {

//collecting the inital loan information
double loanAmount = getLoanAmount();
double annualRate = getInterestRate();
double monthlyRate = annualRate / 100 / 12;

double remainingBalance = loanAmount;
double totalInterest = 0;
double totalPaid = 0;

//attempting to draw a table using iomanip
//don't forget these std:: markers for these things because we're not using std::namespace in the preprocessor section (it may not
//even be called a preprocessor directive, it's different like strings
std::cout << std::fixed << std::setprecision(2);
//below is a string format i'm not sure we've covered in class or not, double check for proper formatting
std::cout << "\n" << std::string(80, '=') << std::endl;
std::cout << std::setw(20) << "Month";
std::cout << std::setw(20) << "Payment";  
std::cout << std::setw(20) << "Interest";
std::cout << std::setw(20) << "Principal";
std::cout << std::setw(20) << "Balance" << std::endl;
std::cout << std::string(80, '=') << std::endl;

//beginning actual calculations area:
//double check this counter loop thing is the same we used in class
//add comments to each section after thoroughly reviewing them
for(int month = 1; month <= 12; month++) {
double monthlyInterest = remainingBalance * monthlyRate;
totalInterest += monthlyInterest;

double payment = getMonthlyPayment(remainingBalance + monthlyInterest);

if(payment > remainingBalance + monthlyInterest) {
    payment = remainingBalance + monthlyInterest;
}

double principal = payment - monthlyInterest;

remainingBalance -= principal;
totalPaid += payment;

std::cout << std::setw(20) << month;
std::cout << std::setw(20) << payment;
std::cout << std::setw(20) << monthlyInterest;
std::cout << std::setw(20) << principal;
std::cout << std::setw(20) << remainingBalance << std::endl;

//skipping an experimental part about
//checking to see if the loan is paid
//off early

}


std::cout << std::string(80, '-') << std::endl;
std::cout << "\nSummary of Loan:" << std::endl;
std::cout << "Initial Loan Amount: $" << loanAmount << std::endl;
std::cout << "Total Amount Paid: $" << totalPaid << std::endl;
std::cout << "Total Interest Paid: $" << totalInterest << std::endl;
std::cout << "Remaining Balance: $" << remainingBalance << std::endl;

//placeholder for int at the end of our
//main block
return 0;
}

//this is where the Functions are no longer
//Prototypes, they're Implemented and 
//Defined

double getLoanAmount() {
int amount;
std::cout << "Enter a loan amount from 1-1000 with no decimals: ";


//the (std::cin >> amount) part may be overkill, not sure we've covered it
//it checks to see if 'extraction failed'
while (!(std::cin >> amount) || amount < 1 || amount > 1000) {
    std::cin.clear();
    //double check these input buffer clear things are the right way to do it
    //also note the std prefixes again since we're not allowed to use namespace
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input. Try a whole number from 1-1000: ";
}

//also don't remember using return
//in class, double check the notes
return static_cast<double>(amount);
}


//i don't remember if this is supposed to be from
//0-100 or 1-100
double getInterestRate() {
    double rate;
    std::cout << "Enter the annual interest rate from 1-100 (using decimals this time if needed): ";

    while(!(std::cin >> rate) || rate < 1 || rate > 100) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Try entering a number from 1-100: ";
    }

    return rate;

}

double getMonthlyPayment(double maxAllowed) {
    double payment;
    std::cout << "Enter payment amount (max payable is $" << maxAllowed << "): ";


    //don't forget that '\n' is something we can use in place of std::endl;
    //it's treated as a char literal instead of a string literal
    while(!(std::cin >> payment) || payment <= 0 || payment > maxAllowed) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid payment amount. Try entering an amount between $0.01 and $" << maxAllowed << ": ";

    }
return payment;
}

//this is a placeholder to ensure that the configuration files (i forget what they're called right now)
//are created properly using Visual Studio
//now we can edit this thing using any tool we want.