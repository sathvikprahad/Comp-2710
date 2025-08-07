/*
Sathvik Prahadeeswaran
srp0061
project2_Prahadeeswaran_srp0061.cpp

compile using g++ project2_Prahadeeswaran_srp0061.cpp
Run using: ./test

*References*
1) I watched Dr. Li's lectures and it helped me follow a template to complete some of my methods. 
2) I looked at the websites stack overflow and geeksforgeeks in order to understand the assert function in the testing methods.
3) I watched a youtube video about using test methods in C++.
4) I talked with my friend Roshan about how to plan the testing methods out in pseudocode. 
*/


#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;


bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);

void Aaron_shoots(bool& B_alive, bool& C_alive);

void Bob_shoots(bool& A_alive, bool& C_alive);

void Charlie_shoots(bool& A_alive, bool& B_alive);

void Aaron_shoots2(bool& B_alive, bool& C_alive);

void Press_any_key(void);

//Testing Prototypes
void test_at_least_two_alive(void);

void test_Aaron_shoots(void);

void test_Bob_shoots(void);

void test_Charlie_shoots(void);

void test_Aaron_shoots2(void);


// Probability Constants of them hitting their shots
const float aaronAcc = ((1.0 / 3.0) * 100);
const float bobAcc = ((1.0 / 2.0) * 100);
const float charlieAcc = ((1.0) * 100);

int main() {
//Random Number Generator
    srand(time(0));

    //First Line
    cout << "*** Welcome to Sathvik's Duel Simulator ***\n";
    
    //Call Testing Functions
    test_at_least_two_alive();
    test_Aaron_shoots();
    test_Bob_shoots();
    test_Charlie_shoots();
    test_Aaron_shoots2();

    //Strategy 1

    cout << "Ready to test strategy 1 (run 10000 times):\n";
    Press_any_key();

    bool aaronAlive, bobAlive, charlieAlive;

    //Variables to track wins, Set to 0
    int aWins, bWins, cWins;
    aWins = bWins = cWins = 0;
    //Runs 10,000 trials
    for (int i = 0; i < 10000; i++)
    {
        //Sets all puzzele-solvers to alive
        aaronAlive = bobAlive = charlieAlive = true;

        //Runs the contest until only one puzzle-solver is left standing
        while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            if (aaronAlive) {
                Aaron_shoots(bobAlive, charlieAlive);
            }
            if (bobAlive) {
                Bob_shoots(aaronAlive, charlieAlive);
            }
            if (charlieAlive) {
                Charlie_shoots(aaronAlive, bobAlive);
            }
        }
        //Check the winner of the contest and add to the winner's win total
        if (aaronAlive) {
            aWins++;
        }
        if (bobAlive) {
            bWins++;
        }
        if (charlieAlive) {
            cWins++;
        }
    }

    //Results from strategy 1
    cout << "Aaron won " << aWins << "/10000 duels or " << static_cast<double>(aWins) / 10000 * 100 << "%\n";
    cout << "Bob won " << bWins << "/10000 duels or " << static_cast<double>(bWins) / 10000 * 100 << "%\n";
    cout << "Charlie won " << cWins << "/10000 duels or " << static_cast<double>(cWins) / 10000 * 100 << "%\n\n";

    //Strategy 2
    cout << "Ready to test Strategy 2 (run 10000 times):\n";
    Press_any_key();

    //Variables used to track the number of wins for strategy 2 and initialized to 0 
    int aWins2, bWins2, cWins2;
    aWins2 = bWins2 = cWins2 = 0;

    //Runs 10,000 trials
    for (int i = 0; i < 10000; i++) {
        aaronAlive = bobAlive = charlieAlive = true;

        //Runs the contest until only one puzzle-solver is left standing
        while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            if (aaronAlive) {
                Aaron_shoots2(bobAlive, charlieAlive);
            }
            if (bobAlive) {
                Bob_shoots(aaronAlive, charlieAlive);
            }
            if (charlieAlive) {
                Charlie_shoots(aaronAlive, bobAlive);
            }
        }

//Check the winner of the contest and add to the winner's win total
        if (aaronAlive) {
            aWins2++;
        }
        if (bobAlive) {
            bWins2++;
        }
        if (charlieAlive) {
            cWins2++;
        }
    }

    //Results from strategy 2
    cout << "Aaron won " << aWins2 << "/10000 duels or " << static_cast<double>(aWins2) / 10000 * 100 << "%\n";
    cout << "Bob won " << bWins2 << "/10000 duels or " << static_cast<double>(bWins2) / 10000 * 100 << "%\n";
    cout << "Charlie won " << cWins2 << "/10000 duels or " << static_cast<double>(cWins2) / 10000 * 100 << "%\n\n";

    //Comparing strategies 1 and 2 to determine which is better
    if (aWins2>aWins) {
        cout << "Strategy 2 is better than Strategy 1.\n"; //Should be the correct result
    }
    else {
        cout << "Strategy 1 is better than Strategy 2.\n";
    }
}


//Implementing all of the different types of duel methods
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
    if((A_alive && B_alive) || (B_alive && C_alive) || (A_alive && C_alive)) {
        return true;
    }
    else {
        return false; 
    }
}

//Aaron's shooting method in strategy one 
void Aaron_shoots(bool& B_alive, bool& C_alive) {
    int shotLanded = rand()%100;
    if (C_alive == true && (shotLanded <= aaronAcc)) {
        C_alive = false;
    }
    else if (B_alive == true && (shotLanded <= aaronAcc)) {
        B_alive = false;
    }
}

//Aaron's shooting method in strategy two
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
    int shotLanded = rand()%100;
    if (B_alive == true && C_alive == true) {
        return;
    }
    else {
        if (C_alive == true && (shotLanded < aaronAcc)) {
            C_alive = false;
        }
        else if (B_alive == true && (shotLanded < aaronAcc)) {
            B_alive = false;
        }
    }
}

//Bob's shooting method
void Bob_shoots(bool& A_alive, bool& C_alive) {
    int shotLanded= rand()%100;
    if (C_alive == true && (shotLanded < bobAcc)) {
        C_alive = false;
    }
    else if (A_alive == true && (shotLanded < bobAcc)) {
        A_alive = false;
    }
}

//Charlie's shooting method
void Charlie_shoots(bool& A_alive, bool& B_alive) {
    int shotLanded = rand()%100;
    if (B_alive == true && (shotLanded < charlieAcc)) {
        B_alive = false;
    }
    else if (A_alive == true && (shotLanded < charlieAcc)) {
        A_alive = false;
    }
}


// Pause the program
void Press_any_key(void) {
    cout << "Press any key to continue...";
    cin.ignore().get();
}

// Testing methods
void test_at_least_two_alive(void) {
    cout << "Unit Testing 1: Function - at_least_two_alive()\n";

    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "\tCase passed ...\n";

    cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(false, true, true));
    cout << "\tCase passed ...\n";

    cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
    assert(true == at_least_two_alive(true, false, true));
    cout << "\tCase passed ...\n";

    cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
    assert(true == at_least_two_alive(true, true, false));
    cout << "\tCase passed ...\n";

    cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
    assert(false == at_least_two_alive(false, false, true));
    cout << "\tCase passed ...\n";

    cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
    assert(false == at_least_two_alive(false, true, false));
    cout << "\tCase passed ...\n";

    cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(true, false, false));
    cout << "\tCase passed ...\n";

    cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
    assert(false == at_least_two_alive(false, false, false));
    cout << "\tCase passed ...\n";

    Press_any_key();
}


//More test methods
void test_Aaron_shoots(void) {
    cout << "Unit Testing 2: Function Aaron_shoots(Bob_alive, Charlie_alive)\n";
    bool bobAlive, charlieAlive;

    cout << "\tCase 1: Bob alive, Charlie alive\n";
        bobAlive = charlieAlive = true;
        cout << "\t\tAaron is shooting at Charlie\n";
        Aaron_shoots(bobAlive, charlieAlive);
        assert(true == bobAlive); 

        cout << "\tCase 2: Bob dead, Charlie alive\n";
        bobAlive = false;
        charlieAlive = true;
        cout << "\t\tAaron is shooting at Charlie\n";
        Aaron_shoots(bobAlive, charlieAlive);
        assert(false == bobAlive);

    cout << "\tCase 3: Bob alive, Charlie dead\n";
        bobAlive = true;
        charlieAlive = false;
        cout << "\t\tAaron is shooting at Bob\n";
        Aaron_shoots(bobAlive, charlieAlive);
        assert(false == charlieAlive);

    Press_any_key();
}

void test_Aaron_shoots2(void) {
    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
    bool bobAlive, charlieAlive;

    cout << "\tCase 1: Bob alive, Charlie alive\n";
        bobAlive = charlieAlive = true;
        cout << "\t\tAaron intentionally misses his first shot\n";
        cout << "\t\tBoth Bob and Charlie are alive.\n";
        Aaron_shoots(bobAlive, charlieAlive);
        assert(true == bobAlive);

        cout << "\tCase 2: Bob dead, Charlie alive\n";
        bobAlive = false;
        charlieAlive = true;
        cout << "\t\tAaron is shooting at Charlie\n";
        Aaron_shoots(bobAlive, charlieAlive);
        assert(false == bobAlive);

        cout << "\tCase 3: Bob alive, Charlie dead\n";
        bobAlive = true;
        charlieAlive = false;
        cout << "\t\tAaron is shooting at Bob\n";
        Aaron_shoots(bobAlive, charlieAlive);
        assert(false == charlieAlive);

        Press_any_key();
}

void test_Bob_shoots(void) {
    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
    bool aaronAlive, charlieAlive;

    cout << "\tCase 1: Aaron alive, Charlie alive\n";
        aaronAlive = charlieAlive = true;
        cout << "\t\tBob is shooting at Charlie\n";
        Bob_shoots(aaronAlive, charlieAlive);
        assert(true == aaronAlive);

        cout << "\tCase 2: Aaron dead, Charlie alive\n";
        aaronAlive = false; 
        charlieAlive = true;
        cout << "\t\tBob is shooting at Charlie\n";
        Bob_shoots(aaronAlive, charlieAlive);
        assert(false == aaronAlive);

    cout << "\tCase 3: Aaron alive, Charlie dead\n";
        aaronAlive = true; 
        charlieAlive = false;
        cout << "\t\tBob is shooting at Aaron\n";
        Bob_shoots(aaronAlive, charlieAlive);
        assert(false == charlieAlive);

    Press_any_key();
}

void test_Charlie_shoots(void) {
    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
    bool aaronAlive, bobAlive;

    cout << "\tCase 1: Aaron alive, Bob alive\n";
        aaronAlive = bobAlive = true;
        cout << "\t\tCharlie is shooting at Bob\n";
        Bob_shoots(aaronAlive, bobAlive);
        assert(true == aaronAlive);

        cout << "\tCase 2: Aaron dead, Bob alive\n";
        aaronAlive = false;
        bobAlive = true;
        cout << "\t\tCharlie is shooting at Bob\n";
        Bob_shoots(aaronAlive, bobAlive);
        assert(false == aaronAlive);

    cout << "\tCase 3: Aaron alive, Bob dead\n";
        aaronAlive = true;
        bobAlive = false;
        cout << "\t\tCharlie is shooting at Aaron\n";
        Bob_shoots(aaronAlive, bobAlive);
        assert(false == bobAlive);

    Press_any_key();
}


