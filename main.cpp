#include "dna.h"

using namespace std;

int main(int argc, char** argv)
{
  // Initialize class object
  DNA dna;
  // Checks to see if an argument is given
  if(argc > 1)
  {
    //Gets filename from command line argument
    string fileName = argv[1];
    // Opens input file stream reader
    ifstream checkFile(fileName);
    // Checks if the file exists
    if(checkFile.good())
    {
      // Calls upon the execute function to run the whole program
      dna.execute(fileName);
    }
    else
    {
      cout << "Invalid File Name: Please Enter a Valid File Name with the Extension(i.e.: .txt)" << endl;
    }
  }
  else
  {
    cout << "Invalid File Name: Please Enter a Valid File Name with the Extension(i.e.: .txt)" << endl;
  }
}
