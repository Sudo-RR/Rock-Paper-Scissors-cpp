#include <iostream>
#include <random>
#include <string>
#include <array>
#include <stdexcept>
using namespace std;
	class computer {
	public: 
		array <string, 3> choice = {"Rock","Paper","Scissor"};
	string computerplay() {
		random_device generator;
		uniform_int_distribution<int> distribution(0, 2);
		int idx_choice =  distribution(generator);
		return choice[idx_choice];
	}
};
class player {
public:
	string player_choice;
	computer compobj;
	string getPlayerChoice() {
		while (true) {
			try {
				cin >> player_choice;

				if (ValidatePlayerChoice(player_choice, compobj.choice)) {
					break;
				}
				else {
					throw invalid_argument("This is an invalid choice, did you perhaps mean to choose 'Rock', 'Paper' or 'Scissor'");

				}
			}
				catch (const invalid_argument& excp) {
					cout << excp.what();
				}


			
		}
		return player_choice;
	}
	bool ValidatePlayerChoice(const string& x, array<string, 3> valid_choice) {
		for (int i = 0; i < 3; i++)
		{
			if (x == valid_choice[i])
			{
				return true;
			}
		}
		 return false;
			
		
	}
};
class Result {
public:
	string winnerIs(string& choice_of_player, string& choice_of_computer) {
		if (choice_of_player == choice_of_computer) {
			return "Tie!";
		}
		
		else
		{

			if (choice_of_player == "Rock") {
				if (choice_of_computer == "Scissor")
					return "You Win!";
				else
					return "You Lose!";
			}
			if (choice_of_player == "Scissor") {
				if (choice_of_computer == "Paper")
					return "You Win!";
				else
					return "You Lose!";
			}
			if (choice_of_player == "Paper") {
				if (choice_of_computer == "Rock")
					return "You Win!";
				else
					return "You Lose!";
			}
		}
	}
};
//Driver code
int main() {
	computer Cmptr;
	player Plyr;
	Result gameon;
	cout<<"Welcome to this Rock Paper Scissor Game!"<<endl;
	bool iftie = true;
	while (iftie) {
		cout << "Rock, Paper or Scissor?" << endl;
		string plyrChoice = Plyr.getPlayerChoice();
		cout << "Great Choice!" << endl;
		string cmptrChoice = Cmptr.computerplay();
		cout << "You Chose:" << plyrChoice << endl;
		cout << " " << endl;
		cout << "Computer Chose:" << cmptrChoice << endl;
		cout << " " << endl;
		string reslt = gameon.winnerIs(plyrChoice, cmptrChoice);
		cout << reslt << endl;
		cout << "Would you like to play again? (Yes/No)"<<endl;
		string ans;
		cin >> ans;
		if (ans == "Yes") {
				iftie = true;
		}
		else if (ans == "No") {
			iftie = false;
			cout << "Thank you! Goodbye!" << endl;
		}
		else {
			iftie = false;
		}
	} 
	
	
}
