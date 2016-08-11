#include <iostream>
#include <windows.h>
#include <math.h>
#include <string>
#include <fstream>

using namespace std;


/********************
Function: positionToFreq(int position)
Converts the position of a note on a standard piano into its frequency

Returns: frequency in Hertz
*********************/
int convertToFreq(int position) {
	int freq = pow(2,((position-49)/12)) * 440;
	return freq;
}

/********************
Function: nameToPosition(string name)
Converts the name of a note into its corresponding position

Returns: position of a note on a piano
*********************/
int convertToPosition(string name) {
	return 0;
}

/********************
Function: noteToDuration(string note, int BPM)
Using the type of note (quarter, half, whole..) and BPM, converts to the duration

Returns: duration of the note in milliseconds
*********************/
double noteToDuration(char note, int BPM) {
	
	//default case, for whole note in seconds
	double duration = 1 / (double)(BPM / 60);
	
	//checks for whole, half, quarter, and eighth notes and converts from seconds to milliseconds
	switch (note)
	{
		case'w':
			return duration * 1000;
			break;
		case'h':
			return (duration / 2) * 1000;
			break;
		case'q':
			return (duration / 2) * 1000;
			break;
		case'e':
			return (duration / 2) * 1000;
			break;
		default:
			cout << "incorrect note";
			break;
	}
}



int main(void) {
	string line, input;

	cout << "Please enter a scientific name: ";
	cin >> input;

	ifstream myfile("C:\Users\Matt\Documents\Visual Studio 2015\Projects\piano.txt");
	if (myfile)
	{
		while (getline(myfile, line))
		{
			if (line == input)
			{
				getline(myfile, line);
				cout << "The Key number for " << input;
				cout << " is " << line;
			}
		}
		myfile.close();
	}
	else
	{
		cout << "Unable to open file";
	}
}