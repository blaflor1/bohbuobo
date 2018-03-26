#include <vector>
#include <list>
#include <string> 
#include <deque>
#include <sstream>
#include <iostream>
#include <utility>
#include <fstream>
#include <time.h>

using namespace std;

class LCSTable {
public:
	deque<pair<char, int>> xTable;
	deque<pair<char, int>> yTable;
	string ** directionalTable;
	int ** matrix;
	string xString;
	string yString;
	int xLength;
	int yLength;
	string lcs_string;
	void generateTable();
	int bottomUp();
	//~LCSTable() {
	//	delete directionalTable;
	//	delete matrix;

	//}

};


void LCSTable::generateTable() {
	for(int i = 0; i < xLength; i++) {
		directionalTable[i][0] = "N";
	}
	for(int i = 0; i < yLength; i++) {
		directionalTable[0][i] = "N";
	}
	for(int i = 1; i1 = 0; i< yLength; ++i, ++i1) {
		for(j = 1; j1 = 0; j < xLength; ++j, ++j1) {
			if(xString[i1] == yString[j1]) {
				matrix[i][j] = 1 + matrix[i-1][j-1];
				directionalTable[i][j] = "\\";
			}
			else if(matrix[i][j-1] <= matrix[i-1][j]) {
				matrix[i][j] = matrix[i-1][j];
				directionalTable[i][j] = "|";

			}
			else {
				matrix[i][j] = matrix[i][j-1];
				directionalTable[i][j] = "<";
			}
		}
	}
}

void LCSTable::writeToFile() {
	ofstream myfile;
	myfile.open("output.txt");
	if(xLength > 10 && yLength > 10) {
		myfile << "Length of sequence: " << lcs_string.length() << "\n";
	}
	else {
		int i = 0;
		while(i < xLength - 1) {
			myfile << " " << xString[i];
			i++;
		}
		for (int j = 0; j < yLength; ++j) 
		{
			if(j > 0 ) {
				myfile << yString[j-1] << " ";
			}
			else {
				myfile << " ";
			}
			for (int i = 0; i < xLength; ++i)
			{
				
			}
		}
	}
}

void LCSTable::bottomUp() {
	//string lcs_string;
	string larger;
	//bool sizeDiffX = false;
	//bool sizeDiffY = false;
	int i, j, ind;
	i = xLength -1;
	j = yLength - 1;
	if(xLength > yLength) {
		larger = xString
		ind = i -1;

	}
	else {
		larger = yString;
		ind = j -1;
	}
	while(j > 0 && i > 0) {
		if(directionalTable[i][j] == "<") {
			j--;
			if(xLength > yLength) ind--;
		}else if(direction[i][j] == "\\") {
			lcs_string.append(larger[ind]);
			i--;
			j--;
			index--;
		}
		else if(directionalTable[i][j] == "|") {
			i--;
			if(larger == yString) {
				ind--;
			}
		}
	}
}

/*int bottomUp(string s, string q, LCSTable L) {
	time_t timer = time(NULL);
	ofstream myfile;
	myfile.open("output.txt");
	for(int i = 0; i < s.length(); i++) {
		for( int j = 0; j < q.length(); j++) {
			if (s[i] == 'x' || q[i] == 'y') {
				L.matrix[i][j] = 0;
				L.directionalTable[i][j] = "";
			}
			else if(s[i] == q[j]) {
				L.matrix[i][j] = 1 + L.matrix[i - 1][j-1];
				L.directionalTable[i][j] = "\\";

			}
			else {
				L.matrix[i][j] = max(L.matrix[i - 1][j], L.matrix[i][j-1]);
				if(L.matrix[i][j] == L.matrix[i-1][j]) {
					L.directionalTable[i][j] = "<-";
				}
				else if (L.matrix[i][j] == L.matrix[i][j-1]) {
					L.directionalTable[i][j] = "|";
				}
			}
		}
		
	}
	if (s.length() > 10 || q.length() > 10)
	{
		myfile << L.matrix[s.length()-1][q.length()-1] << "\n";
		myfile << timer << "\n";
	}
	else {
		string lcs_string = "";
		int i = 0;
		int j = 0;
		/*while(i < s.length() && j < q.length()) {
			if(s[i] == q[j]) {
				lcs_string += s[i];
				i++;
				j++;
			}
			else if (L.matrix[i+1][j] >= L.matrix[i][j+1] && i+1 <= s.length() && j+1 <= q.length()) {
				i++;
			}
			else {
				j++;
			}

		}
		myfile << " ";
		//for loop to print X row of string
		for( i = 0; i < s.length(); i++) {
			cout << s[i] << " ";
		}
		myfile << "\n";

		for (j = 0; j < q.length() ; ++j)
		{	
			myfile << q[j] << " ";
			for(i = 0; i < s.length(); i++) {
				myfile << L.directionalTable[i][j] << L.matrix[i][j] << " ";
			}
			myfile << "\n";
			
		}
			myfile << "\n" << lcs_string << "\n" << timer << "\n";
	}
	myfile.close();

	return L.matrix[s.length() - 1][q.length()-1];
}  */
//int * matrix[][] = new int[][];

int main(int argc, char const *argv[])
{	
	LCSTable mainTable;
	//deque<LCSTable> matrix;
	char const * file1 = argv[1];
	char const * file2 = argv[2];
	stringstream ss;
	string s1, s2, line, line2; 
	// S1 is X string, s2 is Y STRING
	ifstream myfile;
	ifstream myfile2;
	//ofstream outputFile;
	myfile.open(file1);
	myfile2.open(file2);
	while(getline(myfile, line)) {
		stringstream ss(line);
		ss >> s1;
		//cout << s1 << "\n";
	}
	while(getline(myfile2, line2)) {
		stringstream ss(line2);
		ss >> s2;
		//cout << s2 << "\n";
	}
	myfile.close();
	myfile2.close();

	int i = 0;
	int j = 0;
	string x = "x";
	string y = "y";
	x = x + s1;
	y = y + s2;
	string ** dTable = new string[x.length()][y.length()];
	// S1 is X string, s2 is Y STRING
	//string ** dTable = new string*[y.length()];
	//for(int i = 0; i < y.length(); i++) {
	//	dTable[i] = new string[x.length()];
	//}
	int ** mTable = new int[x.length()][y.length()];
	//for(int i = 0; i < y.length(); i++) {
	//	mTable[i] = new int[x.length()];
	//}
	//string dTable[x.length()][y.length()];
	
	//int matrix1[x.length()][y.length()];
	cout << x << "\n";
	cout << y << "\n";
	//for(int i = 0; i < x.length(); i++) {
	//	for(int j = 0; j < y.length(); j++) {
	//		mTable[i][j] = 0;
	//	}
	//}
	//for(i = 0; i < x.length(); i++) {
	//	for(j = 0; j < y.length(); j++) {
	//		dTable[i][j] = "N";
	//	}
	//}
	mainTable.directionalTable = dTable;
	mainTable.matrix = mTable;
	//cout << "checking strings x: " << x << " y: " << y << "\n";
	//for( i = 0; i < x.length(); i++) {
	//		cout << x[i] << " ";
	//	}
	cout << "\n";

	//for (j = 0; j < y.length() ; ++j)
	//{	
	//	cout << y[j] << " ";
	//	for(i = 0; i < x.length(); i++) {
	//		cout << mainTable.directionalTable[i][j] << mainTable.matrix[i][j] << " ";
	//	}
	//	cout << "\n";
			
//	}
			//myfile << "\n" << lcs_string << "\n" << timer << "\n";
	mainTable.bottomUp(x, y, mainTable);
	

//	for(int i = 0; i < y.length(); i++) {
////		delete mainTable.matrix[i];
		//delete mainTable.directionalTable[i];
	//}
	//for(int j = 0; j <)
	delete [] mainTable.matrix;
	delete [] mainTable.directionalTable;
	//delete mTable;
	//delete dTable;
	return 0;
}

