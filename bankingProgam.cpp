#include<iostream>
#include<string>


int main()
{
	std::string firstName; // string variable for the users first name
	std::string lastName; // string variable for the users last name
	float balance; // float variable for the users account balance
	float transAmount;  // float variable for the users transaction amounts
	std::string usrCommand;
	bool keepPrinting = true;
 
	// Creates a header for the program
	std::cout << "################################################" << std::endl;
	std::cout << "##### Welcome to the CS141 Banking Program #####" << std::endl;
	std::cout << "################################################" << std::endl;
	
	// Asks user for first and last name and an account number and saves them to their respective varaibles
	std::cout << "Please type your first name" << std::endl;
	std::cin >> firstName;
	std::cout << "Please type your last name" << std::endl;
	std::cin >> lastName;

	// Says hello to user and asks for a strting account balance
	std::cout << "Hello " << firstName << " " << lastName <<std::endl;
	std::cout << "Please enter your strating balance: $"; 
	
	// stores the account balance
	std::cin >> balance;
	std::cout << "" << std::endl;
	
	// Loops while keepPrinting is true
	while(keepPrinting)
	{
		// Creates a menu for the user to select and action from
		std::cout << "Press D or d to make a deposit" << std::endl;
		std::cout << "Press W or w to make a withrawl" << std::endl;
		std::cout << "Press S or s to show current balance" << std::endl;
		std::cout << "Press Q or q to quit" << std::endl;
		std::cin >> usrCommand;
	
		// if the user pressed d or D ask for a deposit amount, add it to old balance
		// and display the new balance
		if (usrCommand == "D" || usrCommand == "d" )
		{
			std::cout << "" << std::endl;
			std::cout << "Please enter the amount you want to deposit: $";
			std::cin >> transAmount;
			std::cout << "" << std::endl << std::endl;
			balance = balance + transAmount;
			std::cout << "You new balance is: $" << balance << std::endl;
		}
	
		// if the user pressed w or W, ask fro a withdrawl amount, add it to the old
		// balance and display the new balance
		if (usrCommand == "W" || usrCommand == "w")
		{
			std::cout << "" << std::endl;
			std::cout << "Please enter the amount you want to withdraw: $" << std::endl; 
			std::cin >> transAmount;
			std::cout << "" << std::endl;
			balance = balance - transAmount;
			std::cout << "Your new balance is: $" << balance << std::endl;
		}
	
		// if the user pressed s or S, show there current balance
		if (usrCommand == "S" || usrCommand == "s")
		{	
			std::cout << "" << std::endl;
			std::cout << "Your current balance is: $" << balance << std::endl;
		}
	
		// if the user pressed q or Q, quit program and display goodbye message
		if (usrCommand == "Q" || usrCommand == "q")
		{	
			std::cout << "" << std::endl;
			std::cout << "Thank you and good bye" << std::endl;
			keepPrinting = false;
		}
	 	 
	}
	return 0;
}
