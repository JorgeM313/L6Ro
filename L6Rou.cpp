// Jorge Martinez
//CPSC 121 Lab 6
//11/07/2018

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Calculator // Creating the struct provided
{
  long long LHValue;
  long long * RHValue;
  char lastOperator;
};
void processInput(Calculator * calc, string userInput) // Function that calculates the expression
{
  calc->LHValue
}

int main()
{
  Calculator problem = {0, 0, +};

  problem.LHValue = 0;
  problem.RHValue = new long long;
  *(problem.RHValue) = 0;
  problem.lastOperator = '+';

  string userInput = 0;
  cout << "Welcome to the Calculator program.\n";
  cout << "Enter your expression:\n";
  cin.ignore();
  getline(cin, userInput);
  processInput(&problem, userInput);

return 0;
}


// Note to self: Don't be afraid of the red letters. They are supposed to be like that
