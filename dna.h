#include <iostream>
#include <fstream>

using namespace std;

class DNA
{
  public:
    DNA();
    ~DNA();
    int sum(string fileName);
    double mean(string fileName);
    double variance(string fileName);
    double stdDeviation(string fileName);
    double checkProbability(string fileName, string key);
    void writeStats(string fileName);
    void execute(string fileName);
    double generateRandomDouble();
    int generateRandomInt();
    void appendRandom(string fileName);
};
