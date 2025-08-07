/*
*Sathvik Prahadeeswaran
*srp0061

compile using: g++ -o test project3_Prahadeeswaran_srp0061.cpp
run using: ./test

*References* 
1) I used the W3 schools website to learn more about reading files in for that portion of my program.
2) I watched a youtube video on the I/O stream in a C++ environment to better my understanding of the task.

*/

 
#include <fstream> 
#include <iostream>
#include <cstdlib>
using namespace std;

const int maxAmount = 250;

//Reads in the files given by the user
int readFile(int arrayIn[], ifstream& instream) {
    int a = 0;
    instream >> arrayIn[a];
    while (!instream.eof()) {
        a++;
        instream >> arrayIn[a];
    }
    return a;
}

//Writes the sorted array to the new file named by the user 
void writeFile(int arrayOut[], int aSize, string outputFile) {
    ofstream outstream;

    if (outstream.fail()) {
        cout << "Output file opening failed." << endl;
        exit(1);
    }

    outstream.open(outputFile.c_str());
    for (int a = 0; a < aSize; a++) {
        outstream << arrayOut[a] << "\n";
    }
    outstream.close();
}

/*
Sorting Method
*Params: arrayOut should hold values that have been added when the numbers are displayed to the user
*Params: aSize show how big the output array is
*/
void sort(int arrayOut[], int aSize) {
    int a, b, c;
    for (int a = 0; a < aSize; a++) {
        for (int b = a; b < aSize - 1; b++) {
            if (arrayOut[a] > arrayOut [b+1]) {
                c = arrayOut[a];
                arrayOut[a] = arrayOut[b+1];
                arrayOut[b+1] = c;
            }
        }
    }
}

int main() {
    // declaring variables
    string fileName1, fileName2, outputFile;
    int fileSize1, fileSize2, aSize;
    int array1[maxAmount];
    int array2[maxAmount];
    int arrayOut[maxAmount * 2];

    cout << "*** Welcome to Sathvik's sorting program ***\n";

//* File 1 
    //Prompt the user for the first file
    cout << "Enter the first input file name: ";
    cin >> fileName1;

    //Open the file
    ifstream file;
    file.open((char*)fileName1.c_str());

    //Checks to see if file was opened
    if (file.fail()) {
         cout << "Input file opening failed." << endl;
         exit(1);
     }

    //Read in the values of the file and then closes
    fileSize1 = readFile(array1, file);
    file.close();

    //Prints the list of numbers in the file
    cout << "The list of " << fileSize1 << " numbers in file " << fileName1 << " is: \n";
    for (int a = 0; a < fileSize1; a++) {
        cout << array1[a] << endl;
        arrayOut[a] = array1[a];
        aSize++;
    }

//* File 2 
    //Prompt the user for the second file
    cout << "\nEnter the second input file name: ";
    cin >> fileName2;

    //Open the second file
    file.open((char*)fileName2.c_str());

    //Check to see if the second file was opened
    if (file.fail()) {
         cout << "Input file opening failed." << endl;
         exit(1);
     }

    //Read in the values of the second file and then closes
    fileSize2 = readFile(array2, file);
    file.close();

    //Prints the list of the numbers in the file
    cout << "The list of " << fileSize2 << " numbers in file " << fileName2 << " is: \n";
    for (int a = 0; a < fileSize2; a++) {
        cout << array2[a] << endl;
        arrayOut[a+fileSize1] = array2[a];
        aSize++;
    }

//* Sorting
    //Calls the sorted array function
    sort(arrayOut, aSize);

    //Prints out the sorted array
    cout << "\nThe sorted list of " << aSize << " numbers is: ";
    for (int a = 0; a < aSize; a++) {
        cout << arrayOut[a] << " ";
    }

    //Writes the result to a new file called output.txt
    cout << "\nEnter the output file name: ";
    cin >> outputFile;
    writeFile(arrayOut, aSize, outputFile);
    cout << "*** Please check the new file - " << outputFile << " ***\n";
    cout << "*** Goodbye. ***";
}
