// MiniGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    string list[] = { "water", "air", "computer", "python", "violin" };
    string word;
    string userGuess = "";

    char userInput;
    bool isDone = false;

    srand(time(0));

    cout << "Welcome to a HangMan Game where you have to guess a random word\n";

    //first loop for repeated gameplay
    do {
        srand(time(0));
        bool doneGuess = false;
        
        word = list[(rand() % list->length())];
        
        //second loop for guessing correct word
        do {

            cout << "Current game status: word not correctly guessed yet\n\n";

            //third loop for guessing correct characters
            do {
                cout << "Please type a letter: ";

                cin >> userInput;
                cout << endl;

                //if correct character is inputed
                if (word.find(userInput) != string::npos) {
                    cout << "Good guess! The letter is in the word :)\n";
                    cout << "It is located: \n";

                    //shows the location of the inputed character 
                    //(without giving away the word)
                    for (int i = 0; i < word.length(); i++) {
                        if (word.at(i) == userInput) {
                            cout << userInput << " ";
                        }
                        else {
                            cout << "_ ";
                        }
                    }

                    cout << endl;
                }

                //if incorrect character is inputed
                else {
                    cout << "Oops! The letter is not in the word :(\n";
                }

                //checks to see if user is ready to guess the word
                cout << "Do you want to guess the word yet? (y for yes and n for no) ";
                cin >> userInput;
                cout << endl;

                if (userInput == 'y') {
                    cout << "Okay\n";
                    doneGuess = true;
                }
                else if (userInput == 'n') {
                    cout << "Okay, let's keep going\n\n";
                }

            } while (!doneGuess);

            //gets user input for word guess
            cout << "Please enter a word: ";
            cin >> userGuess;

        } while (userGuess != word); 

        //announces completion of game and asks if user wants to play again
        cout << "\nCongratulations! You correctly guessed the word " << word << "!\n\n";
        cout << "Do you want to play again? (y for yes and n for no) ";
        cin >> userInput;

        if (userInput == 'y') {
            cout << "\nOkay. Let's play again!\n\n";
        }
        else if (userInput == 'n') {
            cout << "\nOkay. Thanks for playing!\n\n";
            isDone = true;
        }

    } while (!isDone);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
