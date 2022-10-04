#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;
void game();
int main()
{
	//start screen
	char start;
	cout << "Welcome to Hangman\n"
		<< "__________________\n"
		<< "|          |      \n"
		<< "|          O      \n"
		<< "|          |      \n"
		<< "|        / | \\   \n"
		<< "|       /  |  \\  \n"
		<< "|         / \\    \n"
		<< "|        /   \\   \n"
		<< "|                 \n"
		<< "|_________________\n"
		<< "\ns: start\n"
		<< "e: exit\n";

	//Menu options 
	cin >> start;
	switch (start) {
	case 's':
		game();
		break;
	case 'e': 
		exit(0);
		break; 
	default :
		cout << "Enter a valid letter" << endl;
	}
}

	void game() {
		//Variables
		int tries {6}; //number of attempts
		char guess; //letter that user inputs to guess the word
		bool Correct = false; 
		string Word;
		string WordList[75]; //wordlist comes from file which can be edited
		srand((unsigned int)time(NULL)); //crates random number from time and pulls a random word

		/*This part has a variable created that depends on a text file, 
		without this text file, this game wont work	*/
		ifstream RandomWord; 
		RandomWord.open("WordList.txt");

		
		char PrevGuesses[7]; //array is created to store guesses
		
		for (int x = 0; x < 7; x++) {
			PrevGuesses[x] = '-';
		}
		PrevGuesses[6] = '\0';
		for (int x = 0; x < 75; x++) { //This for loop uses the file and inputs the word list into the array
			RandomWord >> WordList[x];

			//cout << wordlist[x] << endl; // DEBUG: prints wordlist
		}
		//generates random number between 1-75 and chooses a word on that number
		int RandomNumber = rand() % 75;
		Word = WordList[RandomNumber];
		//cout << Word;		//DEBUG: This shows the word that was chosen from the list 
		RandomWord.close(); //File is closed as there is nothing else needed

		//Hidden Word
		string HiddenWord(Word.length(), '*'); //replaces word with asterisks

		//Game runs on while loop and uses switch statements for: Picture of hangman, Tries left, and information about the word to guess.
		while (tries >= 0) {
			//reset bool flag
			Correct = false;

			//Displays information for the word
			cout << "\nThe word you have is: \n" << HiddenWord << endl; //Displays mystery word in asterisk
			cout << "There are " << HiddenWord.length() << " letters for this word\n"; //shows number of letters in the word
			cout << "You have " << tries << " guesses left\n"; //number of tries left
			cout << "You have already guessed: " << PrevGuesses << endl; //displays letters attempted
			
			//get player guess
			cout << "Guess a letter: ";
			cin >> guess;

			//Check for correct letter
			for (int x = 0; x < signed(HiddenWord.length()); x++) //For loops the length of the word
			{
				if (Word[x] == guess) //If a letter is found it replaces the asterisks to repeated occurences of the letter
				{
					HiddenWord[x] = guess;
					cout << "You got one of the letters!\n";
					Correct = true; //set bool to true if a correct guess is made, flag is reset with another bool to prevent infinite guesses
				}
				
			}
			//Once the entire word is found, the game ends and shows the word it was
			if (Word == HiddenWord) {
				cout << "Good job, the word was '" << HiddenWord << "'" << endl;
				break;
			}
			if (Correct == false) {
				tries--;
			}
			
			//Switch statement uses variable 'tries' as number of guesses left, after 6 failed guesses the game ends and shows the answer
			switch (tries) {
			case 6:
				cout << "__________________\n"
					<< "|          |      \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|_________________\n";

				break;
			case 5:
				cout << "__________________\n"
					<< "|          |      \n"
					<< "|          O      \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|_________________\n";
				if (Correct == false) {
					PrevGuesses[0] = guess;
				}
				break;
			case 4:
				cout << "__________________\n"
					<< "|          |      \n"
					<< "|          O      \n"
					<< "|          |      \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|_________________\n";
				if (Correct == false) {
					PrevGuesses[1] = guess;
				}
				break;
			case 3:
				cout << "__________________\n"
					<< "|          |      \n"
					<< "|          O      \n"
					<< "|          |      \n"
					<< "|        / |      \n"
					<< "|       /  |      \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|_________________\n";
				if (Correct == false) {
					PrevGuesses[2] = guess;
				}
				break;
			case 2:
				cout << "__________________\n"
					<< "|          |      \n"
					<< "|          O      \n"
					<< "|          |      \n"
					<< "|        / | \\   \n"
					<< "|       /  |  \\  \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|                 \n"
					<< "|_________________\n";
				if (Correct == false) {
					PrevGuesses[3] = guess;
				}
				break;
			case 1:
				cout << "__________________\n"
					<< "|          |      \n"
					<< "|          O      \n"
					<< "|          |      \n"
					<< "|        / | \\   \n"
					<< "|       /  |  \\  \n"
					<< "|         /       \n"
					<< "|        /        \n"
					<< "|                 \n"
					<< "|_________________\n";
				if (Correct == false) {
					PrevGuesses[4] = guess;
				}
				break;
			case 0:
				cout << "__________________\n"
					<< "|          |      \n"
					<< "|          O      \n"
					<< "|          |      \n"
					<< "|        / | \\   \n"
					<< "|       /  |  \\  \n"
					<< "|         / \\    \n"
					<< "|        /   \\   \n"
					<< "|                 \n"
					<< "|_________________\n";
				cout << "Game Over!\nThe word we were looking for was " << Word << endl;
				tries = -1;
				break;
			default:
				cout << "Well an error occured here\n";
				break;
			}
		}

	}

