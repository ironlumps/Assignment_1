#include "dna.h"
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <random>
#include <math.h>

using namespace std;

// constructor
DNA::DNA()
{

}
//descructor
DNA::~DNA()
{

}
// The sum function iterates through the file and sums the
// charcter count of each line
int DNA::sum(string fileName)
{
  int sum = 0;
  string line;
  // Opens up the input file fstream
  ifstream readFile(fileName);
  // Checks to see if the file exists
  if(readFile.good())
  {
    // Iterates through each line of the file
    while(getline(readFile, line))
    {
      // Adds each line length to previously established sum
      sum += line.length();
    }
  }
  return sum;
}
// The mean function takes the sum of the characters and
// divides it by the total line count to get the average
// characters per line
double DNA::mean(string fileName)
{
  string line;
  double lineCount = 0;
  // Initializing sum with the previous sum method
  int sum = DNA::sum(fileName);
  // Opens the input file stream
  ifstream readFile(fileName);
  if(readFile.is_open())
  {
    // Iterates through each line of the file
    while(getline(readFile, line))
    {
      // Counts the amount of lines
      lineCount++;
    }
  }
  readFile.close();
  // Calculates and returns the mean while accounting
  // for whitespace and new lines
  return((sum - lineCount)/lineCount);
}
// The checkProbability method takes in a filename and a key
// in order to iterate through a file and determine the
// probability for the specified key string ("A" or "AA" for example)
double DNA::checkProbability(string fileName, string key)
{
  // Opens the input file sream for the specified file
  ifstream readFile(fileName);
  // Declares all of the variables that are used in the method
  string line;
  double charCount = 0;
  double bigramCount = 0;
  double aCount = 0;
  double cCount = 0;
  double tCount = 0;
  double Gcount = 0;
  double aaCount = 0;
  double acCount = 0;
  double atCount = 0;
  double agCount = 0;
  double caCount = 0;
  double ccCount = 0;
  double ctCount = 0;
  double cgCount = 0;
  double taCount = 0;
  double tcCount = 0;
  double ttCount = 0;
  double tgCount = 0;
  double gaCount = 0;
  double gcCount = 0;
  double gtCount = 0;
  double ggCount = 0;

  // Verifies if the file exists
  if(readFile.good())
  {
    // Iterates through each line of the file
      while(getline(readFile, line))
      {
        // This for loops iterates through the line
        // and makes all the characters upper case
        for(int i = 0; i < line.length(); i++)
        {
          line[i] = toupper(line[i]);
        }
        // Itreates through each character in the line
        for(int i = 0; i < line.length(); i++)
        {
          // Checks if the character is an "A"
          if(line[i] == 'A')
          {
            aCount++;
            charCount++;
          }
          // Checks if the character is a "T"
          if(line[i] == 'T')
          {
            tCount++;
            charCount++;
          }
          // Checks if the character is a "G"
          if(line[i] == 'G')
          {
            Gcount++;
            charCount++;
          }
          // Checks if the character is a "C"
          if(line[i] == 'C')
          {
            cCount++;
            charCount++;
          }
        }
        // Bigram Counter is similar to for loop, but
        // instead of iterating by 1, it iterates by 2
        // in order to not double count bigrams
        int j = 0;
        while(j < line.length())
        {
          // Combines the first and second letter to then
          // create the bigram
          string bigram = string() + line[j] + line[j+1];
          // Checks if the bigram is "AA"
          if(bigram == "AA")
          {
            aaCount++;
            bigramCount++;
          }
          // Checks if the bigram is "AC"
          if(bigram == "AC")
          {
            acCount++;
            bigramCount++;
          }
          // Checks if the bigram is "AT"
          if(bigram == "AT")
          {
            atCount++;
            bigramCount++;
          }
          // Checks if the bigram is "AG"
          if(bigram == "AG")
          {
            agCount++;
            bigramCount++;
          }
          // Checks if the bigram is "CA"
          if(bigram == "CA")
          {
            caCount++;
            bigramCount++;
          }
          // Checks if the bigram is "CC"
          if(bigram == "CC")
          {
            ccCount++;
            bigramCount++;
          }
          // Checks if the bigram is "CT"
          if(bigram == "CT")
          {
            ctCount++;
            bigramCount++;
          }
          // Checks if the bigram is "CG"
          if(bigram == "CG")
          {
            cgCount++;
            bigramCount++;
          }
          // Checks if the bigram is "TA"
          if(bigram == "TA")
          {
            taCount++;
            bigramCount++;
          }
          // Checks if the bigram is "TC"
          if(bigram == "TC")
          {
            tcCount++;
            bigramCount++;
          }
          // Checks if the bigram is "TT"
          if(bigram == "TT")
          {
            ttCount++;
            bigramCount++;
          }
          // Checks if the bigram is "TG"
          if(bigram == "TG")
          {
            tgCount++;
            bigramCount++;
          }
          // Checks if the bigram is "GA"
          if(bigram == "GA")
          {
            gaCount++;
            bigramCount++;
          }
          // Checks if the bigram is "GC"
          if(bigram == "GC")
          {
            gcCount++;
            bigramCount++;
          }
          // Checks if the bigram is "GT"
          if(bigram == "GT")
          {
            gtCount++;
            bigramCount++;
          }
          // Checks if the bigram is "GG"
          if(bigram == "GG")
          {
            ggCount++;
            bigramCount++;
          }

          j += 2;
        }
      }
  }
  else
  {
    cout << "Invalid File Name" << endl;
  }
  // These next if statements check the key, which is an argument
  // of this class and then returns the probability of the key
  if(key == "A")
  {
    // Returns the probability of "A"
    return ((aCount/charCount) * 100);
  }
  if(key == "T")
  {
    // Returns the probability of "T"
    return ((tCount/charCount) * 100);
  }
  if(key == "C")
  {
    // Returns the probability of "C"
    return ((cCount/charCount) * 100);
  }
  if(key == "G")
  {
    // Returns the probability of "G"
    return ((Gcount/charCount) * 100);
  }
  if(key == "AA")
  {
    // Returns the probability of "AA"
    return ((aaCount/bigramCount) * 100);
  }
  if(key == "AT")
  {
    // Returns the probability of "AT"
    return ((atCount/bigramCount) * 100);
  }
  if(key == "AC")
  {
    // Returns the probability of "AC"
    return ((acCount/bigramCount) * 100);
  }
  if(key == "AG")
  {
    // Returns the probability of "AG"
    return ((agCount/bigramCount) * 100);
  }
  if(key == "TA")
  {
    // Returns the probability of "TA"
    return ((taCount/bigramCount) * 100);
  }
  if(key == "TT")
  {
    // Returns the probability of "TT"
    return ((ttCount/bigramCount) * 100);
  }
  if(key == "TC")
  {
    // Returns the probability of "TC"
    return ((tcCount/bigramCount) * 100);
  }
  if(key == "TG")
  {
    // Returns the probability of "TG"
    return ((tgCount/bigramCount) * 100);
  }
  if(key == "CA")
  {
    // Returns the probability of "CA"
    return ((caCount/bigramCount) * 100);
  }
  if(key == "CT")
  {
    // Returns the probability of "CT"
    return ((ctCount/bigramCount) * 100);
  }
  if(key == "CC")
  {
    // Returns the probability of "CC"
    return ((ccCount/bigramCount) * 100);
  }
  if(key == "CG")
  {
    // Returns the probability of "CG"
    return ((cgCount/bigramCount) * 100);
  }
  if(key == "GA")
  {
    // Returns the probability of "GA"
    return ((gaCount/bigramCount) * 100);
  }
  if(key == "GT")
  {
    // Returns the probability of "GT"
    return ((gtCount/bigramCount) * 100);
  }
  if(key == "GC")
  {
    // Returns the probability of "GC"
    return ((gcCount/bigramCount) * 100);
  }
  if(key == "GG")
  {
    // Returns the probability of "GG"
    return ((ggCount/bigramCount) * 100);
  }
  else
  {
    cout << "No Valid Key Given" << endl;
  }
  readFile.close();

}

// The writeStats method uses the methods above and then
// prints the statiscs (i.e. probability, sum etc.) to a
// designated write file
void DNA::writeStats(string fileName)
{
  string outputFile = "ryanKassab.out";
  ofstream writeFile(outputFile, ios::app);

  writeFile << "The Sum of All the Characters: " << DNA::sum(fileName) << endl;
  writeFile << "The Mean of the Characters : " << DNA::mean(fileName) << endl;
  writeFile << "The Variance Between the Lines: " << DNA::variance(fileName) << endl;
  writeFile << "The Standard Deviaton for the Lines: " << DNA::stdDeviation(fileName) << endl;
  writeFile << "The Probability of A: %" << DNA::checkProbability(fileName, "A") << endl;
  writeFile << "The Probability of T: %" << DNA::checkProbability(fileName, "T") << endl;
  writeFile << "The Probability of C: %" << DNA::checkProbability(fileName, "C") << endl;
  writeFile << "The Probability of G: %" << DNA::checkProbability(fileName, "G") << endl;
  writeFile << "The Probability of AA: %" << DNA::checkProbability(fileName, "AA") << endl;
  writeFile << "The Probability of AT: %" << DNA::checkProbability(fileName, "AT") << endl;
  writeFile << "The Probability of AC: %" << DNA::checkProbability(fileName, "AC") << endl;
  writeFile << "The Probability of AG: %" << DNA::checkProbability(fileName, "AG") << endl;
  writeFile << "The Probability of TA: %" << DNA::checkProbability(fileName, "TA") << endl;
  writeFile << "The Probability of TT: %" << DNA::checkProbability(fileName, "TT") << endl;
  writeFile << "The Probability of TC: %" << DNA::checkProbability(fileName, "TC") << endl;
  writeFile << "The Probability of TG: %" << DNA::checkProbability(fileName, "TG") << endl;
  writeFile << "The Probability of CA: %" << DNA::checkProbability(fileName, "CA") << endl;
  writeFile << "The Probability of CT: %" << DNA::checkProbability(fileName, "CT") << endl;
  writeFile << "The Probability of CC: %" << DNA::checkProbability(fileName, "CC") << endl;
  writeFile << "The Probability of CG: %" << DNA::checkProbability(fileName, "CG") << endl;
  writeFile << "The Probability of GA: %" << DNA::checkProbability(fileName, "GA") << endl;
  writeFile << "The Probability of GT: %" << DNA::checkProbability(fileName, "GT") << endl;
  writeFile << "The Probability of GC: %" << DNA::checkProbability(fileName, "GT") << endl;
  writeFile << "The Probability of GG: %" << DNA::checkProbability(fileName, "GG") << endl;

  writeFile.close();
}
// This method calulates the variance between strings
double DNA::variance(string fileName)
{
  // Opens the input filee stream
  ifstream readFile(fileName);
  string line;
  // Calls upon the mean function to get the mean
  double mean = DNA::mean(fileName);
  double variance = 0;

  // Checks if the file exists
  if(readFile.good())
  {
    // Iterates through each line of the file
    while(getline(readFile, line))
    {
      // Actually calculates the variance by subtracting the
      // mean from the line length
      double temp = mean - line.length();
      // THen squares it to get the variance
      variance += pow(temp, 2);
    }
  }

  readFile.close();

  return variance;
}
// The stdDeviation method calculates the standard deviation
// by using the variance
double DNA::stdDeviation(string fileName)
{
  // Obtains variance by calling the calulate variance function
  double variance = DNA::variance(fileName);
  // Square Roots the variacne to get the standard deviation
  return(sqrt(variance));
}

// The appendRandom method appends the random strings onto the
// writefile that has been being used
void DNA::appendRandom(string fileName)
{
  string output = "ryanKassab.out";
  // Opens up the output file stream with above file name
  ofstream writeFile(output, ios::app);
  // Writes some introductory strings to file
  writeFile << endl;
  writeFile << "DNA Random Strings: " << endl;
  writeFile << endl;
  // Pulls mean from the mean method
  double mean = DNA::mean(fileName);
  // Pulls standard deviation from the standard deviation method
  double stdDeviation = DNA::stdDeviation(fileName);
  int counter = 0;
  // Iterates through this printing statement 1000 times
  // to print 1000 random strings
  while(counter < 1000)
  {
    // Calls the generateRandomDouble method to generate
    // two random numbers
    double random1 = DNA::generateRandomDouble();
    double random2 = DNA::generateRandomDouble();
    // Calculates the cosine part of the equation using a
    // a random number
    double cosTemp = cos(2 * M_PI * random2);
    // Calculates the logarithimic part of the equation
    // using a random number
    double logTemp = (-2) * log(random1);
    double squareTemp = sqrt(logTemp);
    // Finshes the equation by combining the two equations
    double c = squareTemp * cosTemp;
    // Combines the last equation with mean and standard
    // deviation to get the D equation
    int d = (stdDeviation * c) + mean;
    string line;
    if(d != 0)
    {
      for(int i = 0; i < d; i++)
      {
        //Generate random number between 1 and 4
        int randNum = DNA::generateRandomInt();
        // If the random number is 1, it returns "A"
        if(randNum == 1)
        {
          line += "A";
        }
        // If the random number is 2, it returns "T"
        if(randNum == 2)
        {
          line += "T";
        }
        // If the random number is 3, it returns "C"
        if(randNum == 3)
        {
          line += "C";
        }
        // If the random number is 4, it returns "G"
        if(randNum == 4)
        {
          line += "G";
        }
      }
      // Only prints the lines generated that aren't empty
      if(line != "")
      {
        writeFile << line << endl;
        counter++;
      }
    }
  }

  writeFile.close();
}

// The generateRandomDouble method generates a random double
double DNA::generateRandomDouble()
{
  double randNum = ((double) rand() / (RAND_MAX));

  return randNum;
}
// The generateRandomInt method generates a random integer
int DNA::generateRandomInt()
{
  int randNum = (rand() % 4) + 1;

  return randNum;
}
// The execute method combines the other methods to just run the code
void DNA::execute(string fileName)
{
  string output = "ryanKassab.out";
  ofstream writeFile(output);
  // Prints the initial header to the file
  writeFile << "Ryan Kassab" << endl;
  writeFile << "2296707" << endl;
  writeFile << "rkassab@chapman.edu" << endl;
  writeFile << "CPSC 350-01" << endl;
  writeFile << endl;
  // Calls upon writeStats to write the stats of the file to the new file
  DNA::writeStats(fileName);
  writeFile << endl;
  // Calls upon appendRandom to just append the random strings to data file
  DNA::appendRandom(fileName);
  writeFile << endl;
  // Prompts user to enter another file
  cout << "Would you like to enter another file? ";
  string answer;
  cin >> answer;
  // Lowers the answer to lowercase
  for(int i = 0; i < answer.length(); i++)
  {
    answer[i] = tolower(answer[i]);
  }
// If answer is yes, basically re-runs program
  if(answer.compare("y") == 0 || answer.compare("yes") == 0)
  {
    while(answer.compare("y") == 0 || answer.compare("yes") == 0)
    {
      cout << "Please enter another file name: ";
      string newFile;
      cin >> newFile;

      DNA::writeStats(newFile);
      writeFile << endl;
      DNA::appendRandom(newFile);
      writeFile << endl;

      cout << "Would you like to enter another file? ";
      cin >> answer;
    }
  }
  // If answer is no, exits the program
  if(answer.compare("n") == 0 || answer.compare("no") == 0)
  {
    cout << "Program Exiting: Thank You" << endl;
  }
  // If netiher, asks the question again
  if(answer.compare("\n") == 0)
  {
    cout << "No Valid Answer Given" << endl;
    cout << "Would you like to enter another file? ";
    cin >> answer;
  }
  // If netiher, asks the question again
  else
  {
    cout << "No Valid Answer Given" << endl;
    cout << "Would you like to enter another file? ";
    cin >> answer;
    // Asks question again and then re runs program if yes
    if(answer.compare("y") || answer.compare("yes"))
    {
      cout << "Please enter another file name: " << endl;
      string nextFile;
      cin >> nextFile;

      DNA::writeStats(nextFile);
      writeFile << endl;
      DNA::appendRandom(nextFile);
      writeFile << endl;
    }
    // If anything else, exits the program
    else
    {
      cout << "Program Exiting: Thank You" << endl;
    }
  }

  writeFile.close();
}
