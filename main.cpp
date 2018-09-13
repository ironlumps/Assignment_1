#include "dna.h"

using namespace std;

int main(int argc, char** argv)
{
  DNA dna;
  if(argc > 1)
  {
    string fileName = argv[1];
    ifstream checkFile(fileName);
    if(checkFile.good())
    {
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
