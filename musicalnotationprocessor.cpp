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
Converts the name of a note into its corresponding position on a piano
This function uses an outside text file that includes each scientfic name and note position from the following:
https://en.wikipedia.org/wiki/Piano_key_frequencies

Returns: position of a note on a piano
*********************/
int convertToPosition(string input) {
	ifstream inFile;
	string line, target;
	int position;

	//Contains all the scientific words and note positions
	inFile.open("piano.txt");
	if (inFile)
	{
		while (!inFile.eof()) {
			/* ">>" reads until the next whitespace and skips any leading or trailing whitespace. 
			 Allowing the user to receive the name of the note(C7) and then grab the next word which would be the position(76) */

			inFile >> target >> position;
			if (target == input) {
				inFile.close();
				return position;
			}
		}
		inFile.close();
		cout << "you did not input a valid note.";
	}
	else
	{
		cout << "Unable to open file";
	}
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
	ifstream sheet;
	string music;

	string line;
	string pitch;
	char note;
	
	int position;
	int freq;
	int time;
	int BPM;

	cout << "Enter the name of a text file." << endl;
	cin >> music;

	cout << "Enter the BPM" << endl;
	cin >> BPM;

	sheet.open(music);
	if (sheet)
	{
		while (!sheet.eof()) {
			sheet >> pitch >> note;
			position = convertToPosition(pitch);
			freq = convertToFreq(position);
			time = noteToDuration(note, BPM);

			Beep(freq, time);
		}
	}
	else
	{
		cout << "Unable to open file";
	}
}