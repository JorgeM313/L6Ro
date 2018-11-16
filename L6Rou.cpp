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
	if(userInput != "=")
	{
		string tempLH, tempRH;
		for(int i = 0; i < userInput.size(); i++)
		{
			if(isspace(userInput[i])){

			}
			else if(isdigit(userInput[i])){
				tempLH = tempLH + userInput[i];
			}
			else if (userInput[i] == '*' || userInput[i] == '-' || userInput[i] == '\\' || userInput[i] == '+' || userInput[i] == '%')
			{
				calc->lastOperator = userInput[i];
				break;
			}
			else
			{
				cout << "Bad Input1\n";
				break;
			}
		}
		for (int j = 0;j< userInput.size(); j++)
		{
			if (userInput[j] == '*' || userInput[j] == '-' || userInput[j] == '\\' || userInput[j] == '+' || userInput[j] == '%')
			{
				for(int i = j+1; i <userInput.size();i++)
				{			
					if(isspace(userInput[i])){

					}
					else if(isdigit(userInput[i])){
						tempRH = tempRH + userInput[i];
					}
					else {
						cout << "Bad Input2\n";
					}
				}
				break;
			}
		}
		if (!tempLH.empty())
		{	
			calc->LHValue = stoll(tempLH,nullptr,10);
		}

		if (!tempRH.empty())
		{
			*calc->RHValue = stoll(tempRH,nullptr,10);
		}
		
	}
	if (calc->lastOperator == '%'){
		calc->LHValue = calc->LHValue % *calc->RHValue;
	}	
	if (calc->lastOperator == '+'){
		calc->LHValue = calc->LHValue + *calc->RHValue; 
	}
	if (calc->lastOperator == '-'){
		calc->LHValue = calc->LHValue - *calc->RHValue;
	}
	if (calc->lastOperator == '*'){
		calc->LHValue = calc->LHValue * *calc->RHValue;
	}
	if (calc->lastOperator == '/'){
		if (*calc->RHValue = 0)
		{
			cout << "Error. Cannot divide by 0.\n";
		} 
		else
		{
			calc->LHValue = calc->LHValue / *calc->RHValue;
		}
	}
	cout << " = "<< calc->LHValue<<endl; 



}

int main()
{
  Calculator *problem = new Calculator; 

  problem->LHValue = 0;
  problem->RHValue = new long long;
  *problem->RHValue = 0;
  problem->lastOperator = '+';

  string userInput ="";
do{
  cout << "Welcome to the Calculator program.\n";
  cout << "Enter your expression:\n";
  getline(cin, userInput);
	if(userInput != "q")
  	processInput(problem, userInput);
}while(userInput != "q");
return 0;
}


// Note to self: Don't be afraid of the red letters. They are supposed to be like that
