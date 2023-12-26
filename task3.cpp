#include<iostream>
#include<string>

using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string player1, player2;
int choice;
int row, col;
char turn = 'X';
bool draw = false;

void display() {
    cout << player1 << " (X) vs " << player2 << " (O)\n\n";
    cout << " " << space[0][0] << " | " << space[0][1] << " | " << space[0][2] << "\n";
    cout << "-----------\n";
    cout << " " << space[1][0] << " | " << space[1][1] << " | " << space[1][2] << "\n";
    cout << "-----------\n";
    cout << " " << space[2][0] << " | " << space[2][1] << " | " << space[2][2] << "\n";
}

void switchPlayer() {
    turn = (turn == 'X') ? 'O' : 'X';
}

void getInput() {
    cout << "Player " << ((turn == 'X') ? player1 : player2) << ", enter your move (1-9): ";
    cin >> choice;
    if(choice <1 || choice>9){
        cout<<"invalid choice\n";
      
    }
}

bool isValidMove() {
    row = (choice - 1) / 3;
    col = (choice - 1) % 3;

    if (choice >= 1 && choice <= 9 && space[row][col] != 'X' && space[row][col] != 'O')
        return true;

    return false;

    
    
    
}

void makeMove() {
    space[row][col] = turn;
}

bool checkWin() {
   
    for (int i = 0; i < 3; ++i) {
        if (space[i][0] == turn && space[i][1] == turn && space[i][2] == turn)
            return true;
        if (space[0][i] == turn && space[1][i] == turn && space[2][i] == turn)
            return true;
    }

    if (space[0][0] == turn && space[1][1] == turn && space[2][2] == turn)
        return true;
    if (space[0][2] == turn && space[1][1] == turn && space[2][0] == turn)
        return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (space[i][j] != 'X' && space[i][j] != 'O')
                return false;

    return true;
}

bool askReplay() {
    char response;
    cout << "Do you want to play again? (y/n): ";
    cin >> response;
    return (response == 'y' || response == 'Y');
}

void resetGame() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            space[i][j] = (i * 3 + j + 1) + '0';

    draw = false;
    turn = 'X';
}

int main() {
    cout << "Enter the name of Player 1 (X): ";
    cin >> player1;
    cout << "Enter the name of Player 2 (O): ";
    cin >> player2;

    do {
        display();

        do {
            getInput();
        } while (!isValidMove());

        makeMove();

        if (checkWin()) {
            display();
            cout << "Player " << ((turn == 'X') ? player1 : player2) << " wins!\n";
        } else if (checkDraw()) {
            display();
            cout << "The game is a draw!\n";
        } else {
            switchPlayer();
            continue;
        }

        if (askReplay()) {
            resetGame();
        } else {
            break;
        }

    } while (true);

    return 0;
}