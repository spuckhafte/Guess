#include <iostream>
#include <string> /* to_string() */
#include <stdlib.h> /* rand(), srand() */
#include <time.h> /* time() */
#include <cmath> /* mathematics */

using namespace std;

/* output text to user */
void println(string output, string vara = "", string varb = "", string varc = "") {
    cout << output << vara << varb << varc << endl;
}

/* take input with label */
string input(string label="", string vara = "", string varb = "", string varc = "") {
    string inp;
    cout << label << vara << varb << varc;
    getline(cin, inp);
    return inp;
}

/* convert string to int */
int parseInt(string num) {
    int _num = std::stoi(num);
    return _num;
}

/* initializing the Game */
class Game {
public:
    int _min = 0; /* Minimum value to guess */
    int _max = 30; /* Maximum value to guess */
    int _chances = 5; /* Total "Try Again" for user */
};

/* How wrong the user guess is?*/
string status(int randm, int guess) {
    Game Guess;

    int distance = guess - randm;
    int factor = Guess._max/5 < 1 ? 1 : round(Guess._max/5);
    string _status;
    if (abs(distance) < factor) {
        _status = distance < 0 ? "Lower" : "Higher";
    } else {
        _status = distance < 0 ? "Much Lower" : "Much Higher";
    }

    return _status;
}


int main() {
    Game Guess;
    println("Welcome to the Guess Game");
    println("Choose a number between: ", to_string(Guess._min), "-", to_string(Guess._max));
    println(to_string(Guess._chances), " chances are available\n");

    int _chance = 1;
    srand(time(NULL));
    int random = rand() % Guess._max + Guess._min;

    /* Game Loop */
    while (_chance <= Guess._chances) {
        int guess = parseInt(input("Chance ", to_string(_chance), ": "));
        if (guess == random) {
            println("\nYou Won!");
            break;
        } else {
            string how_wrong = status(random, guess);
            println("Wrong Guess!, ", how_wrong);
            if (_chance == Guess._chances) println("\nYou Lost!\nActual no: ", to_string(random));
        }
        _chance++;

    }
    return 0;
}
