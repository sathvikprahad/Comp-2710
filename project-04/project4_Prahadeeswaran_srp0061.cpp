/*
Sathvik Prahadeeswaran
srp0061
project4_Prahadeeswaran_srp0061.cpp

compile using g++ -o test project4_Prahadeeswaran_srp0061.cpp
Run using: ./test

REFERENCES
* I looked up how to properly use the get line function on geeksforgeeks.com https://www.geeksforgeeks.org/getline-string-c/
* I looked at Dr. Li's slides and watched his lectures. 
* W3 schools helped me implement my pointer variables. https://www.w3schools.com/cpp/cpp_pointers.asp#:~:text=Create%20a%20pointer%20variable%20with,variable%20you're%20working%20with.
* I also watched youtube videos on unit testing in C++ to better understand the objective in this project.
*/
#include <iostream>
#include <assert.h>
#include <cstring>
#include <cstdlib>
using namespace std; 


//creates trivia node structure
   struct TriviaNode {
      string question;
      string answer;
      int value;
      TriviaNode* nextVal;
   };
   
   //makes the linked list for Trivia 
   typedef TriviaNode *nod;
   
   //makes the hard coded questions
   void triviaInitializer(nod& triviaQuestions) {
      nod ptr = new TriviaNode;
      
      ptr -> question = "How long was the shortest war on record?";
      ptr -> answer = "38";
      ptr -> value = 100;
      ptr -> nextVal = new TriviaNode;
      nod nodeOne = ptr;
      ptr = ptr -> nextVal;
      
      ptr -> question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
      ptr -> answer = "Bank of Italy";
      ptr -> value = 50;
      ptr -> nextVal = new TriviaNode;
      ptr = ptr -> nextVal;

      ptr -> question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)?";
      ptr -> answer = "Wii Sports";
      ptr -> value = 20;
      ptr = nodeOne;
      triviaQuestions = ptr;
   }
   
   //loads the question into every node
   void addQuestion(nod& triviaQuestions) {
      nod ptr = new TriviaNode;
      int pts;       
      nod nodeOne = triviaQuestions;
      
      while (triviaQuestions -> nextVal != NULL) {
         triviaQuestions = triviaQuestions -> nextVal;
      }  
      
      cout << "Enter a new question: ";
      getline(cin, ptr -> question);
      
      cout << "Enter an answer: ";
      getline(cin, ptr -> answer);
      
      cout << "Enter award points: ";
      cin >> pts;
      ptr -> value = pts;
       
      
      triviaQuestions -> nextVal = ptr;
      
      while (triviaQuestions != NULL) {
         triviaQuestions = triviaQuestions -> nextVal;
      } 
      triviaQuestions = nodeOne;
   }
   
   // the question method
   int askQuestion(nod& triviaQuestions, int nQuestions) {
      int qNum = 0;
      int total = 0;
      nod ptr = triviaQuestions;
      string a;
      while (ptr != NULL) {
         ptr = ptr -> nextVal;
         qNum++;
      }
      ptr = triviaQuestions;
      
      if (ptr == NULL || triviaQuestions == NULL) {
         return 0;
      }
      
      else if (nQuestions < 1) {
         cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
         return 1;
      }
      
      else if (qNum < nQuestions) {
         cout << "Warning - There is only " << qNum << " trivia in the list.";
         return 1;
      }
      
      else {
         for (int i = 0; i < nQuestions; i++) {
            cout << "Question: " << ptr -> question << "\n";
            cout << "Answer: ";
            getline(cin, a);
            
            if((ptr -> answer).compare(a) == 0) {
               cout << "Your answer is correct! You receive " << ptr -> value << " points.\n";
               total = total + ptr -> value;
               cout << "Your total points: " << total << "\n";
               ptr = ptr -> nextVal;
            }
            else {
               cout << "Your answer is wrong. The correct answer is: " << ptr -> answer << "\n";
               cout << "Your total points: " << total << "\n";
               ptr = ptr -> nextVal;
            }
            
         }
         return 0;
      }
   }
   
   #define UNITTESTING
   //#define quiz
   
   
   // unit testing  
   void UnitTesting() {
      cout << "***This is a debugging version ***\n";
      nod nodes = new TriviaNode;
      triviaInitializer(nodes);
      
      cout << "Unit Test Case 1: Ask no question. The program should give a warning message.\n";
      int answerOne = askQuestion(nodes, 0);
      assert(answerOne == 1);
      cout << "\nCase 1 Passed\n\n";
      
      cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer.\n";
      int answerTwo = askQuestion(nodes, 1);
      assert(answerTwo == 0);
      cout << "\nCase 2.1 Passed\n\n";
      
      cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer.\n";
      int answerThree = askQuestion(nodes, 1);
      assert(answerThree == 0);
      cout << "\nCase 2.2 Passed\n\n";
      
      cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list.\n";
      int answerFour = askQuestion(nodes, 3);
      assert(answerFour == 0);
      cout << "\nCase 3 Passed\n\n";
      
      cout << "Unit Test Case 4: Ask 5 questions in the linked list.\n";
      int answerFive = askQuestion(nodes, 5);
      assert(answerFive == 1);
      cout << "\nCase 4 Passed\n\n";
      
      cout << "*** End of the Debugging Version ***";
   }
   
   //main method
   int main() {
   //implements unit testing
      #ifdef UNITTESTING
      UnitTesting();
      return 0;
   #endif
   
   //implements trivia quiz
   #ifdef quiz
      nod nodes = new TriviaNode;
      triviaInitializer(nodes);
      cout << "*** Welcome to Sathvik's trivia quiz game ***\n";
      int qNumber = 3;
      while (cin.good()) {
         addQuestion(nodes);
         qNumber++;
         string continue;
         cout << "Continue? (Yes/No): ";
         cin >> continue;
         cin.clear();
         cin.ignore(10000, '\n');
         cout << "\n";
         if(continue.compare("No") == 0) {
            break;
         }
      }
      askQuestion(nodes, qNumber);
      cout << "\n***Thank you for playing the trivia quiz game. Goodbye! ***\n\n";
      return 0;
   #endif
   }  