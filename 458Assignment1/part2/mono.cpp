#include <string>
#include <vector>
#include <fstream>
#include <queue>
#include <deque>
#include <iostream>
#include <sstream>

using namespace std;

int findLocation(char letter) {
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	int loc = -1;
	for (int i = 0; i < alphabet.length(); i++)
	{
		if(letter == alphabet[i]) { 
			loc = i;
		}
	}
	return loc;
}

char getCypheLetter(int location, int seedNum) {
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	cout << "seedNum =  " << seedNum <<  "\n";
	int cyphIndex = location + seedNum;
	cout << "cyphIndex = " << cyphIndex <<  "\n";
	int count = 0;
	char retChar;
	if (cyphIndex > alphabet.length()-1)  {
		cout << "shouldnt be in here yet" << "\n";
		int realIndex = cyphIndex - (alphabet.length());
		cyphIndex = realIndex;
		retChar = alphabet[cyphIndex];
	}
	else {
		retChar = alphabet[cyphIndex];
	}
	return retChar;
}

char getPlainLetter(int location, int seedNum) {
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	int plainIndex = location - seedNum;
	int count = 0;
	char retChar;
	if (plainIndex < 0)  {
		int realIndex = plainIndex + (alphabet.length());
		plainIndex = realIndex;
		retChar = alphabet[plainIndex];
	}
	else {
		retChar = alphabet[plainIndex];
	}
	return retChar;
}

string monoCypher(string plainText, int encrypt, int seedNum) {
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	string retString = "";
	//cout << "In Mono Cypher Func \n";
	if (encrypt == 1)
	{
	  //cout << "In Encrypt If statement \n";
	  for (int i = 0; i < plainText.length(); i++)
		{

		  cout << "Printing plainText letter: " << plainText[i] << "\n"<< "\n";
		  int location = findLocation(plainText[i]);
		  cout << "Printing location num: " << location << "\n"<< "\n";
		  char ciphLetter = getCypheLetter(location, seedNum);
		  cout << "Printing encrypted letter: " << ciphLetter << "\n" << "\n";
		  retString += ciphLetter;
		  retString += ", ";
		}
	}
	else if(encrypt == 0) {

		for (int i = 0; i < plainText.length(); i++)
		{
		  cout << "Printing cyphText letter: " << plainText[i] << "\n"<< "\n";	
		  int location = findLocation(plainText[i]);
		  cout << "Printing location num: " << location << "\n"<< "\n";
		  char plainLetter = getPlainLetter(location, seedNum);
		  cout << "Printing decrypted letter: " << plainLetter << "\n" << "\n";
		  retString += plainLetter;
		  retString += ", ";
		}

	}
	
	return retString;
}




int main(int argc, char *argv[]) {

	string inputFileName;
	string outputFileName;
	string fullText;
	string outputText;
	int seed;
	int type;
	bool encrypt;
	if (argc == 4) {
		inputFileName = argv[1]; // Get input file
		outputFileName = argv[2]; // Get output file
		seed = 0; // Set seed default

		string temp = argv[3]; // Get encryption/decryption value
		stringstream encryptVal(temp);
		encryptVal >> type;
		//type = stoi(temp); // Convert to int
		ifstream inputFile;
	    inputFile.open(argv[1]);
	    ofstream outputFile;
	    outputFile.open(argv[2]);
	    if(!inputFile.is_open()) {
		  return -1;
		}
		if (type != 0 && type != 1) { // Check encryption/decryption variable is 0 or 1
			cout << "Last argument must be '0' or '1'" << endl;
			return -1;
		}
		else { 
		  if(type == 0) encrypt = false;
		  else if (type == 1)
			{
				encrypt == true;
			}
		  getline(inputFile, fullText);
		  outputText = monoCypher(fullText, encrypt, seed);
		  outputFile << outputText;
		}
	} else if (argc == 5) {
		inputFileName = argv[1];
		outputFileName = argv[2];

		string temp = argv[3]; // seed num
		string temp2 = argv[4]; // encrypt/decrypt val
		stringstream seedVal(temp);
		seedVal >> seed;
		stringstream encryptVal(temp2);
		encryptVal >> type;
		//seed = stoi(temp);
		//type = stoi(temp2);
		ifstream inputFile;
	    inputFile.open(argv[1]);
	    ofstream outputFile;
	    outputFile.open(argv[2]);
		if(!inputFile.is_open()) {
		  return -1;
		}

		if (type != 0 && type != 1) { // Check encryption/decryption variable is 0 or 1
			cout << "Last argument must be '0' or '1'" << endl;
			return -1;
		}
		else { 
			cout << "Checking what type ==" << " " << type << "\n";
			/*if(type == 0) { 
				encrypt = false;
			}
			else if (type == 1)
			{
				encrypt == true;
			}*/
			getline(inputFile, fullText);
			cout << "Printing full text: " << fullText << "\n";
			outputText = monoCypher(fullText, type, seed);
			cout << "Printing output text: " << outputText << "\n";
			outputFile << outputText;
		}
	} else { // unexpected number of args
		cout << "Expected either 3 or 4 arguments.\nUsage: ./mono <input.txt> <output.txt> <seed> 0/1" << endl;
		return -1;
	}

	
	return 0;	
}