#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum class enWinner { Player1, Computer, Draw };

void SetWinnerScreenColor(enWinner Winner) 
{
    switch (Winner) 
    {
        case enWinner::Player1:
            system("color 2F"); 
            break;
        case enWinner::Computer:
            system("color 4F"); 
            cout << "\a";       
        default:
            break;
    }
}

int random_number(int from, int to) 
{
    return (rand() % (to - from + 1) + from);
}

int computer_choice() 
{
    int choice = random_number(1, 3); 
    switch (choice) 
    {
        case 1: cout << "Computer choice: Stone\n";    break;
        case 2: cout << "Computer choice: Paper\n";    break;
        case 3: cout << "Computer choice: Scissors\n"; break;
    }
    return choice;
}

void read_player_choice(int &player_choice) 
{
    do {
        cout << "Your choice: [1]: Stone, [2]: Paper, [3]: Scissors? ";
        cin >> player_choice;
       } while (player_choice < 1 || player_choice > 3);
}

void display_player_choice(int player_choice) 
{
    switch (player_choice) 
    {
        case 1: cout << "Player choice: Stone\n";    break;
        case 2: cout << "Player choice: Paper\n";    break;
        case 3: cout << "Player choice: Scissors\n"; break;
    }
}

void determine_winner(int player, int computer, int &player_wins, int &computer_wins, int &draws)
 {
    enWinner winner;
    if (player == computer) 
    {
        cout << "Result: It's a tie!\n";
        draws++;
        winner = enWinner::Draw;
    }
    else if ((player == 1 && computer == 3) ||
             (player == 2 && computer == 1) ||
             (player == 3 && computer == 2)) 
             {
               cout << "Result: You win!\n";
               player_wins++;
               winner = enWinner::Player1;
             }
    else 
    {
        cout << "Result: Computer wins!\n";
        computer_wins++;
        winner = enWinner::Computer;
    }
    SetWinnerScreenColor(winner);
}

void start_rounds(int num_rounds, int &player_wins, int &computer_wins, int &draws)
 {
    for (int i = 1; i <= num_rounds; i++) 
    {
        int player_choice;
        cout << "\nRound [" << i << "] begins\n\n";
        read_player_choice(player_choice);
        display_player_choice(player_choice);
        int comp_choice = computer_choice();
        determine_winner(player_choice, comp_choice, player_wins, computer_wins, draws);
    }
}

void show_game_results(int num_rounds, int player_wins, int computer_wins, int draws) 
{
    cout << "---------------------------------------------------\n";
    cout << "             +++ Game Over +++\n";
    cout << "---------------------------------------------------\n";
    cout << "---------------- [Game Results] -------------------\n";
    cout << "Game Rounds      : " << num_rounds << endl;
    cout << "Player Wins      : " << player_wins << endl;
    cout << "Computer Wins    : " << computer_wins << endl;
    cout << "Draws            : " << draws << endl;
    
    if (player_wins > computer_wins)
        cout << "Final Winner     : Player\n";
    else if (player_wins < computer_wins)
        cout << "Final Winner     : Computer\n";
    else
        cout << "Final Winner     : It's a tie\n";
    
    cout << "---------------------------------------------------\n";
}

int main() 
{
    srand(time(0));
    char play_again;
    
    do {
        system("cls");
        
        int player_wins = 0, computer_wins = 0, draws = 0;
        int num_rounds;
        cout << "How many rounds (1 to 10)? ";
        cin >> num_rounds;
        
        start_rounds(num_rounds, player_wins, computer_wins, draws);
        show_game_results(num_rounds, player_wins, computer_wins, draws);
        
        cout << "\nDo you want to play again? (y/n): ";
        cin >> play_again;
        
      } while (play_again == 'y' || play_again == 'Y');
    
    cout << "\nThanks for playing! Goodbye.\n";
    return 0;
}