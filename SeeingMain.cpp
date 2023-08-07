#include "SpeakerView.h"

//All header files needed are included above

int main(int argc, char** argv){ // use of command line arguments, directions for running are in README file
    SpeakerView view(argv[1]);
    view.StackView(view.createMyStack());
}