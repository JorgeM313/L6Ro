// Jorge Martinez
//CPSC 121 Lab 6
//11/07/2018

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Calculator // Creating the struct provided in the lab
{
  long long LHValue;
  long long * RHValue;
  char lastOperator;
};
void processInput(Calculator * calc, string userInput) // Function that calculates the expression
{
	if(userInput != "=") //if the user's input is not an equals sign, all of the following happens
	{
		string tempLH, tempRH;
		for(int i = 0; i < userInput.size(); i++)
		{
			if(isspace(userInput[i])){ //If there is whitespace, the program does nothing with it. Simply ignores it

			}
			else if(isdigit(userInput[i])){ //If the input contains digits, keep going. This is where our temporary value for LH is stored
				tempLH = tempLH + userInput[i];
			}//Next, check to see when the operator appears
			else if (userInput[i] == '*' || userInput[i] == '-' || userInput[i] == '\\' || userInput[i] == '+' || userInput[i] == '%')
			{// This next line is where the last operator is stored
				calc->lastOperator = userInput[i];
				break;
			}
			else // If any other symbols are entered, error message is displayed
			{
				cout << "Bad Input1\n";
				break;
			}
		}
		for (int j = 0;j< userInput.size(); j++)
		{
			if (userInput[j] == '*' || userInput[j] == '-' || userInput[j] == '\\' || userInput[j] == '+' || userInput[j] == '%')
			{ 
				for(int i = j+1; i <userInput.size();i++) // This is where the temporary value for RH is stored
				{			
					if(isspace(userInput[i])){

					}
					else if(isdigit(userInput[i])){
						tempRH = tempRH + userInput[i];
					}
					else { // If anu other symbol is entered, error message is displayed
						cout << "Bad Input2\n";
					}
				}
				break;
			}
		}
		if (!tempLH.empty())
		{	
			calc->LHValue = stoll(tempLH,nullptr,10); // Converting to a long long int
		}

		if (!tempRH.empty())
		{
			*calc->RHValue = stoll(tempRH,nullptr,10); // Converting to a long long int
		}
		
	} // Now, the different scenarios are set up for each operation
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
			cout << "Error. Cannot divide by 0.\n"; // Special case. Check to make sure you can't divide by 0
		} 
		else
		{
			calc->LHValue = calc->LHValue / *calc->RHValue;
		}
	}
	cout << " = "<< calc->LHValue<<endl; //Display the result of the input



}

int main()
{ // Declaring each object and variable
  Calculator *problem = new Calculator; 

  problem->LHValue = 0;
  problem->RHValue = new long long;
  *problem->RHValue = 0;
  problem->lastOperator = '+';

  string userInput ="";
do{ // Putting the whole program into a loop until the input is q
  cout << "Welcome to the Calculator program.\n"; //
  cout << "Enter your expression:\n";
  getline(cin, userInput);
	if(userInput != "q")
  	processInput(problem, userInput); // Calling the function and providing parameters
}while(userInput != "q"); // Providing the exit from the program
return 0;
}


// Note to self: Don't be afraid of the red letters. They are supposed to be like that
