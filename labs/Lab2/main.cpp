
#include <iostream>
#include <iomanip>
//we're not sure if this proprocessor directive is allowed or not, may have to change it later
//#include <limits>

//these are the highest level variables declared outside of the main block, double check to make sure it's supposed to
//be this way
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













//placeholder again
return 0;
}





//this is a placeholder to ensure that the configuration files (i forget what they're called right now)
//are created properly using Visual Studio
//now we can edit this thing using any tool we want.