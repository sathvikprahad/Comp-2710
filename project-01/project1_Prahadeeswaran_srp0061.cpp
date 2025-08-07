
/* 
* Sathvik Prahadeeswaran
* srp0061
* project1_Prahadeeswaran_srp0061.cpp
* compile using g++ -o test project1_Prahadeeswaran_srp0061.cpp
* run using: ./test

*References* 
1) I used the W3 schools website to learn more about prompting the user input and how to run that portion of my program.
2) I used W3 schools to learn C++ syntax that I did not know such as boolean statements.
3) I watched a youtube video on the basics of C++

*/

#include <iostream>
using namespace std;
int main() {
// VARIABLE INITIALIZATION
float loan = 0; // initial loan amount
float interestRate = 0; // interest rate per year
float paymentPerMonth = 0; // money being paid per month 
float balance; // the remaining balance which should be declining
int currentMonth = 0; // counts the months till interest is paid off
float interest = 0; // interest paid per payment
float accruedInterest = 0; // counts total interest paid
float moneyLeft = 0; // money paid towards the balance after the interest is paid initially

// CURRENCY FORMATTING
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

// USER INPUT which obtains the loan amount
cout << "\nLoan Amount: ";
cin >> loan;
while (loan <= 0) {
     cout << "Invalid Loan Amount! Loan must be higher than $0.00. \n";
    cin >> loan;
}

// get and set the interest rate 
bool workingInterestRate = false; 
while (workingInterestRate == false) {
    cout << "Interest Rate (% per year): ";
    if (cin >> interestRate) {
        if (interestRate < 0) {
            workingInterestRate = false; 
            cout << " Invalid Interest Rate! Interest cannot be negative. \n";
        }
        else {
            workingInterestRate = true;
        }
        }
    }
    balance = loan;

// GET PROPER INTEREST RATES FOR CALCULATIONS
interestRate /= 12; // monthly interest rate
interestRate /= 100; // decimal interest rate
double minimum = (loan * interestRate) + 0.01; // The monthly payments need to be bigger than the actual minimum sum of money from interest so the loan gets paid eventually 

// get and set the monthly payment 
cout << "Monthly Payments: ";
cin >> paymentPerMonth;
while (paymentPerMonth <= minimum) { // payment needs to be higher than minimum 
    cout << " Insufficient Payment! Payment must be at least " << minimum << "\n";
}

// AMORTIZATION TABLE
cout << "*****************************************************************\n"
     << "\tAmortization Table\n"
     << "*****************************************************************\n"
     << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

// LOOP TO FILL TABLE

while (balance > 0) {
if (currentMonth == 0) {
    cout << currentMonth << "\t$" << loan;
    cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
}
interest = balance * interestRate;
accruedInterest = accruedInterest + interest; 
currentMonth++; 

if (paymentPerMonth > (balance + interest)) {
    moneyLeft = balance + interest;
}

moneyLeft = paymentPerMonth - interest; 
balance = balance - moneyLeft; 

if (balance < 0) {
balance = 0;
}

if (balance < 1000) { // This if loop helps fix a formatting issue when the remaining loan amount reaches $1000
       cout << currentMonth << "\t$" << balance << "\t\t$" << paymentPerMonth << "\t" << interestRate * 100 << "\t$" << interest << "\t\t$" << moneyLeft << endl;

     }
     else {
       cout << currentMonth << "\t$" << balance << "\t$" << paymentPerMonth << "\t" << interestRate * 100 << "\t$" << interest << "\t\t$" << moneyLeft << endl;
   }
}

// Summary 

cout << "****************************************************************\n";
if (currentMonth == 1) {
    cout << "\nIt takes " << currentMonth << " months to pay off the loan.\n";
}
else {
    cout << "\nIt takes " << currentMonth << " months to pay off the loan.\n";
}
    cout << "Total interest paid is: $" << accruedInterest; cout << endl << endl; 
    return 0;
}