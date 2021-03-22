#include "../../std_lib_facilities.h"

int main() {
	string sFormLetter = " ";
	string sName = " ";
	string sFriendName = " ";
	string sYourName = " ";
	char cFriendGender = '\0';
	cout << "What is your name?\n";
	cin >> sYourName;
	cout << "Please enter the name of your recipient\n";
	cin >> sName;
	cout << "What is your mutual friends name?\n";
	cin >> sFriendName;
	sFormLetter = "Dear " + sName + ",\n";
	sFormLetter += " How are you? I am fine, although I miss you.";
	sFormLetter += "\nHave you seen " + sFriendName + " recently?";
	cout << "What is your mutual friends gender? (m/f/n)\n";
	cin >> cFriendGender;
	switch (cFriendGender)
	{
		case 'm' : sFormLetter += " If you see him please ask him to call me.";
			break;
		case 'f' : sFormLetter += " If you see her please ask her to call me.";
			break;
		case 'n' : sFormLetter += " If you see them please ask them to call me.";
			break;
	}
	sFormLetter += "\n Sincerely,\n\t" + sYourName;
	cout << sFormLetter;
}