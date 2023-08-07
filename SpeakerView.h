#ifndef SPEAKERVIEW_H
#define SPEAKERVIEW_H

#include <iostream>
#include <fstream>
#include <string>

// All header files needed are included above

class SpeakerView{
    public:
        SpeakerView(std::string inputFile);
        //defualt constructor
        ~SpeakerView();
        //defualt destructor
        double** createMyStack();
        void StackView(double **myStack); // 2D array made sense to me about having a
        // read values from the input file 

        // functions above are "getters" for each of the private variables below
    private:
        std::string outfile;
        int myRow;
        int myColumn;
        // these integers are set to the values read from the input file
};
#endif