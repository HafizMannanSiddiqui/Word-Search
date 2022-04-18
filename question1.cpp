#include <string>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <cstring>
#include <string>
using namespace std;


int largeString(string arr[]) { //function to find longest string
	int occurence, newmax;
	for (int i = 0; i < 6; i++) {
		occurence = arr[0].length();
		if (arr[i].length() < arr[i + 1].length()) {
			newmax = arr[i + 1].length();
		}
		if (newmax > occurence) {
			occurence = newmax;
		}
	}
	return occurence;
}


void filereader(string A[]) 
{ //file reader function
	ifstream fin;
	fin.open("demo.txt");
	string line;
	int i = 0;
	while (!fin.eof()) {
		getline(fin, line, '\n');
		A[i] = line;
		fin >> A[i];
		i++;
	}
	fin.close();
	cout << "Words given are:" << endl;
	for (int j = 0; j < i; j++) {
		cout << A[j] << endl;
	}
}

void MAIN(int len, string arr[]) {
	char grid[30][30];
	int r;
	char c;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			r = rand() % 26;//generates random number between 0 and 26
			c = 'a' + r;//add the random number generated above 'r' into the ASCII value of 'a'
			grid[i][j] = c;//grid initializer
		}
	}
	int n = 0;
	int m = 0;
	for (int index = 0; index < 7; index++) {

		if (arr[index].length() == len || n == 0) {
			// put word diagonally
			int row = 0;
			int col = 0;
			for (int i = 0; arr[index][i] != '\0'; i++, row++, col++) {
				grid[row][col] = arr[index][i];
			}
			n++;
		}
		else if (arr[index].length() % 2 == 0) {
			// put word horizontally
			int row = rand() % len;
			int col = (rand() % 3) + 4;
			if (n == 1)
				row--;
			else if (n == 2)
				row++;
			for (int i = 0; arr[index][i] != '\0'; i++, col++) {
				grid[row][col] = arr[index][i];
			}
			n++;
		}
		else {
			int row = (rand() % 4) + 1;
			int col = rand() % 5;
			if (m == 0)
				col++;
			for (int i = 0, j = index; arr[index][i] != '\0'; i++, row++) {
				grid[row][col] = arr[index][i];
			}
			m++;
		}
	}
	ofstream fout("output.txt");//putting the grid in an output.txt file
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			fout << grid[i][j] << " ";
		}
		fout << endl;
	}
	fout.close();
}
int main() {
	int len = 0;
	string arr[7];
	filereader(arr);//to read the input file given by the user
	len = largeString(arr);//to check if any word is longer than the standard size of the matrix
	if (len < 10) {
		len = 10;
	}
	MAIN(len, arr);//function called for initializing the word puzzle
	cout << "The words are stored in file output.txt" << endl;
	system("pause");
	return 0;
}
