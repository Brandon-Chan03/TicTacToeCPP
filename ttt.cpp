#include <iostream>
#include <stdlib.h>

#include "helper.hpp"

using namespace std;

int main() {

    string name1;
    string name2;

    cout << "Please enter Player 1's name: ";
    cin >> name1;
    cout << "\n";

    cout << "Please enter Player 2's name: ";
    cin >> name2;
    cout << "\n";

    while(gameover()) {
        displayBoard(name1, name2);
        playerTurn(name1, name2);
        gameover();
    }

    displayBoard(name1, name2);

}

