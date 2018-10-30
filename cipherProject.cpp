/* This program will read the contents of a file, in this case message1_encoded. 
   Then, it will change all letters to lowercase and remove anything that is not a letter
   Then, it will output the new letters to another file, in this case output.txt
   You need to change the file  names to the files you wish to look at. 
   Lines 20, 21 and 86 need to be changed to the files you wish to read in and output to.
*/

#include<iostream>
#include<fstream>
#include<string>

int main()
{

	// A method to read the encrypted message from a file
	std::ofstream outputFile; // Saves outputFile as a ofstream
	std::ifstream inputFile; // Saves inputFile as an ifstream
	
	//need to change to correct names. file 1 should print to output.txt and the rest print to output#.txt where # is the number of the encoded message
	outputFile.open("output.txt"); // opens a new file output.txt
	inputFile.open("message1_encoded.txt"); // reads the meesage1_encoded.txt file

	char letterInFile; // creates a string variable for each letter in the file
	int letters[26] = { 0 }; // creates an array called letter that has  a length of 26 and is all 0s
	int orderedLetters[26];
	char freqLetters[26];
	char freqTableLetters;
	std::string decodedMessage;
	int letterCountMax = 0;
	int count = 0;
	
	letterInFile = inputFile.get(); 

	std::string fullFile = ""; // Creates an empty string fullFIle
	
	// Loops while the  eof of the file has not been reached
	while(!inputFile.eof())
	{
		// Checks if the char in the file is a letter	
		if(isalpha(letterInFile))
		{
			// if it is a letter then they it change the letter to lowercase and then adds it to fullFile
			letterInFile = tolower(letterInFile);
			fullFile += letterInFile;
			
			// adds 1 to the position that matches each letter in the array letters
			int position = letterInFile - 97;
			letters[position]++;	
		}
		
		// Sets letterInFile to the next char in the string
		letterInFile = inputFile.get();		
	}	
	
	inputFile.close();
	std::ifstream inData;
	inData.open("freqTable.txt");
	inData >> freqTableLetters;

	// Prints fullFile
	//std::cout << "The full string is : " << fullFile << std::endl;
	
	for(int i = 0; i < 26; i++)
	{
		// Prints the array contents
		for(int interval = 0; interval < 26; interval++)
		{
			// Finds the letter with the highest frequency
			if(letters[interval] > letterCountMax)
			{
				letterCountMax = letters[interval];
				count = interval;
			}
		}
		// Create a second array based off of the freq table
		orderedLetters[i] = count + 'a';	
		freqLetters[i] = freqTableLetters;
		inData >> freqTableLetters;	
		letters[count] = -1;
		letterCountMax = -1;
		count = 0;
	}
	
	inData.close();
	std::ifstream inputData;
	inputData.open("message1_encoded.txt");
	letterInFile = inputData.get();

	while(!inputData.eof())
	{
		for(int i = 0; i < 26; i++)
		{
			// Checks if the char in the file is a letter	
			if(isalpha(letterInFile))
			{
				// if it is a letter then they it change the letter to lowercase and then adds it to fullFile
				if(letterInFile == char(orderedLetters[i]))
				{	
					letterInFile = freqLetters[i];
					i = 26;
				}
				else if(letterInFile == toupper(char(orderedLetters[i])))
				{	
					letterInFile = toupper(freqLetters[i]);
					i = 26;				
				}	
				
			}
		}
		decodedMessage += letterInFile;
		
		//Sets letterInFile to the next char in the string
		letterInFile = inputData.get();
	}	


	// Stores fullFile in output.txt
	outputFile << decodedMessage;
	
	std::cout << decodedMessage << std::endl;
	 
	// Closes the input and output files
	inputData.close();
	outputFile.close();
	return 0;
}
 
