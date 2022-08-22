#include <iostream>
#include <functional>

using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int choice;
int row, column;

char turn = 'X';

int score[] = {0, 0};

bool draw = false;


void displayBoard(string name1, string name2) {

    std::cout << "Player One: " << name1 << "  Player Two: " << name2 << "\n\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[0][0] << "  |" << "  " << board[0][1] << "  |" << "  " << board[0][2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[1][0] << "  |" << "  " << board[1][1] << "  |" << "  " << board[1][2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << board[2][0] << "  |" << "  " << board[2][1] << "  |" << "  " << board[2][2] << "  \n";
    std::cout << "     |     |     \n\n";

    cout << "Player 1 Score: " << score[0] << "  Player 2 Score: " << score[1] << "\n\n";

}

void playerTurn(string name1, string name2) {

    if (turn == 'X') {
        cout << name1 << " please choose a square: ";
    } else {
        cout << name2 << " please choose a square: ";

    }

    cin >> choice;
    cout << "\n";

    switch(choice){
        case 1: row=0; column=0; break;
        case 2: row=0; column=1; break;
        case 3: row=0; column=2; break;
        case 4: row=1; column=0; break;
        case 5: row=1; column=1; break;
        case 6: row=1; column=2; break;
        case 7: row=2; column=0; break;
        case 8: row=2; column=1; break;
        case 9: row=2; column=2; break;
        default:
            cout << "Invalid Move";
    }

    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'X';
        turn = 'O';

    }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
        board[row][column] = 'O';
        turn = 'X';

    }else {
        cout<<"Invalid Square: Please choose another\n\n";
        playerTurn(name1, name2);
    }

}

bool gameover(){
    //checking the win for Simple Rows and Simple Column
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return false;
        }
    }
    

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return false;
    }

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] != 'X' && board[i][j] != 'O') {
                return true;
            }
        }
    }

    //Checking the if game already draw
    draw = true;
    return false;
}




