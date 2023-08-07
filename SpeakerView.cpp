#include "SpeakerView.h"
#include "MonoStack.h"
#include <iostream>
#include <string>
#include <fstream>

// All header files needed are included above

SpeakerView::SpeakerView(std::string inputFile){
    outfile = inputFile;
}

// default constructor
SpeakerView::~SpeakerView(){
}

//defualt destructor

double** SpeakerView::createMyStack(){ // creates set of stacks needed based on text file
    std::cout << std::endl;
    std::cout << "Original Textfile:" << std::endl;
    std::cout << std::endl;
    std::ifstream MyFile;
    std::string IntVal = "";
    std::string FloatVal = "";
    double DoubleReference = 0;
    double **FinalStack;
    int row_location = 0;
    int column_location = 0;
    // initialization of all values to 0

    //rows signify the size of the stack
    //columns signify the number of stacks
   
    MyFile.open(outfile);
    while (getline(MyFile, IntVal)){ // getline helps iterate through each column in the text file
        for (int i = 0; i < IntVal.length(); i++){ // size of each row essentially
            if (row_location >= 1){
                break;
            }
            if (IntVal[i] == ' '){
                column_location++;
                // accounts for all spaces
            }
            else if (i == IntVal.length() - 1){
                column_location++;
                // starst new stack
            }
        }
        row_location++;
        // moves onto the next row
    }
    MyFile.close();
    // retrieving file contents in order to create the stack

    FinalStack = new double *[row_location];
    for (int i = 0; i < row_location; i++){
        FinalStack[i] = new double[column_location];
    }

    for (int i = 0; i < row_location; i++){ // nested for loop prints out all rows and columns of the text file
        for (int j = 0; j < column_location; j++){
            FinalStack[i][j] = 0;
        }
    }
    myRow = row_location;
    myColumn = column_location;
    row_location = 0;
    column_location = 0;

    MyFile.open(outfile);
    while (getline(MyFile, IntVal)){
        for (int i = 0; i < IntVal.length(); i++){
            if (IntVal[i] == ' '){ // checks open spaces in the text file
                DoubleReference = stod(FloatVal); // stod method converts string to doubles
                FinalStack[row_location][column_location] = DoubleReference;
                FloatVal = "";
                column_location++; // iterates through each column
            }
            else if (i == IntVal.length() - 1){
                FloatVal += IntVal.at(i);
                DoubleReference = stod(FloatVal); // stod method converts string to doubles
                FinalStack[row_location][column_location] = DoubleReference;
                FloatVal = "";
                column_location = 0;
                // begins new stack
            }
            else{
                FloatVal += IntVal[i];
            }
        }
        row_location++;
    }
    MyFile.close();
    return FinalStack;
    // returns a full completed text file
}

// this method checks the view of people that see the speaker in front of the room
void SpeakerView::StackView(double **FinalStack){ // creates output of all stacks
    for (int a = 0; a < myRow; a++){
        for (int b = 0; b < myColumn; b++){
            std::cout << FinalStack[a][b];
            std::cout << ' '; // accounts for all spaces between values in text file
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    MonoStack<float> myStack(1, 'd');
    // decreasing method that uses the MonoStack class
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Output Statements: " << std::endl;
    std::cout << std::endl;
    int j = 0;
    int column_locationCount = 0;
    for (int i = myRow - 1; i > -1; i--){ // used as a preincrementing method form the header file
        myStack.push(FinalStack[i][j]); // uses push method from MonoStack
        if (i == 0){
            column_locationCount++;
            std::cout << "In column location " << column_locationCount;
            std::cout << ", there are "<< myStack.size() << " that can see. ";
            std::cout << "Their heights are: ";
            // stack.size() accounts for how many are pushed in the stack
            while (!myStack.isEmpty()){
                std::cout << myStack.pop();
                std::cout << ", ";
            }
            std::cout << "inches.";
            std::cout << std::endl;
            if (j == myColumn - 1){
                break;
            }
            j++;
            i = myRow;
            std::cout << std::endl;   
        }
    }
    std::cout << std::endl;
    delete[] FinalStack;
    // deallocation of array
}

