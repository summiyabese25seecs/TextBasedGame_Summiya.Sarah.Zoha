#include <iostream>
#include <cstdlib> // For rand(), srand()
#include <ctime>   // For time()

using namespace std;
//initializing the global variables.
int key;
int key2;
int life = 8; // Start with 8 lives 

// Function Prototyping
void start();
int password_room1();
void keys1();
void library();
void keys2();
int password_room2();
void kitchen();
void keys3();
int password_room3();

int main() {

    srand(time(0));

    //print the welcome message without any function.
    cout << "========================================================\n";
    cout << "|         WELCOME TO THE ESCAPE MYSTERY GAME!          |\n";
    cout << "========================================================\n";
    cout << "\t========================================\n";
    cout << "\t             HAUNTED HOUSE              \n";
    cout << "\t========================================\n";
    cout << "\t                [ATTIC]                 \n";
    cout << "\t               __________               \n";
    cout << "\t              |          |              \n";
    cout << "\t              |   ATTIC  |              \n";
    cout << "\t              |          |   \n";
    cout << "\t                    ||                  \n";
    cout << "\t                    || (Door)           \n";
    cout << "\t                    \\/                  \n";
    cout << "\t              ________________          \n";
    cout << "\t             |                |         \n";
    cout << "\t             |    LIBRARY     |         \n";
    cout << "\t             |                | \n";
    cout << "\t              ||            ||          \n";
    cout << "\t    (Locked)  ||            ||  (Locked)\n";
    cout << "\t              \\/            \\/          \n";
    cout << "\t           __________    __________     \n";
    cout << "\t          |          |  |          |    \n";
    cout << "\t          | KITCHEN  |  |  EXIT    |    \n";
    cout << "\t          |     ||   |\n";
    cout << "\t                ||                       \n";
    cout << "\t                \\/                       \n";
    cout << "\t             ESCAPE HERE!                \n";
    cout << "\t========================================\n";


    //only call the two main functions inside main.
    //Users choices influence which functions are called, therefore all functions must be called inside other functions.
    start();
    keys1();

    return 0;
}

// START FUNCTION which introduces the player to the game instructions.
void start() {
    cout << "--------------------------------------------------------------------------------\n";
    cout << "You have " << life << " LIVES.\n";
    cout << "You just woke up in a room, unconscious. The criminals have locked you up in a haunted house.\n";
    cout << "Your only escape is the clues left behind by one of the criminals. You need to find the right KEYS and advance through all THREE LEVELS to win.\n\n";

    cout << "There are three main rooms in the house:\n";
    cout << "1) ATTIC\t (Your first step to escape)\n";
    cout << "2) LIBRARY\t (Your place for clues)\n";
    cout << "3) KITCHEN\t (Your destiny to escape or death)\n\n";
    cout << "--------------------------------------- LEVEL 1 -----------------------------------------\n";
    cout << "YOU ARE IN THE ATTIC.\n";
}

// ATTIC 
void keys1() {
    cout << "On your left you see two keys:\n ||| KEY 1 \t KEY 2. |||\n";
    cout << "CHOOSE A KEY: One will cost a life, the other will lead you to the LIBRARY.\n";
    cout << "CHOOSE WISELY!\n";
    cout << "----------------------------------------------------------------------------------\n";
    cout << "Which key (1 or 2): ";
    cin >> key;

    //switch statements are used because the players decisions control what happens next.
    switch (key) {
    case 1:

        cout << "\n OOPS! YOU LOST A LIFE. The key was a distraction.\n";
        life--;
        cout << "You have " << life << " LIVES remaining.\n";

        if (life > 0) {

            cout << "You still get a chance to try the other key.\n";
            cout << "\n--------------------------------------------------------------------------------\n";
            cout << "KEY 2: THE LOCKED DOOR NEEDS A PASSWORD...\n";
            cout << "Every time you guess a wrong password, a life goes away.\n";
            //for level 1, you get another chance after choosing the wrong key.
            password_room1();
        }
        else {
            //loosing all your lives directly exits the game.
            cout << "\n!!! GAME OVER !!! You ran out of lives.\n";
            cout << "\t =========MISSION FAILED ========\n\n";
        }
        break;

    case 2:
        cout << "\n GOOD CHOICE! Key 2 unlocks the way for your escape.\n";
        cout << "A secret door appears directing you to the next place.\n";

        cout << "\nKEY 2: THE LOCKED DOOR NEEDS A PASSWORD...\n";
        cout << "Every time you guess a wrong password, a life goes away.\n";
        password_room1();
        break;

    default:
        cout << "\nEntered wrong key!\n";
    }
}

int password_room1() {

    //generates a random number between 1 and 10 which needs to be guessed by the user in Level 1.
    int target = 1 + rand() % 10;
    int guess;
    int attempt = 1;
    bool won = false;
    const int max_Attempts = 3;

    cout << "\n--- PASSWORD CHALLENGE ---\n";
    cout << " You have " << max_Attempts << " chances to guess the number (1 - 10).\n";

    do {
        cout << "\nLife count: " << life << " | Attempt " << attempt << " of " << max_Attempts << ".\n";
        cout << "Enter the guess number: ";
        cin >> guess;

        if (guess == target) {
            cout << "\n[!!! SUCCESS !!!] The lock clicks open!\n";
            cout << "The password was " << target << ". YOU PASSED THIS LEVEL!. Directing you to the LIBRARY now.\n";
            won = true;
            break;
        }
        else {
            if (guess < target) {
                life--;
                cout << " !!!WRONG CHOICE !!!Your guess is too low. You lost 1 life. Remaining lives : " << life << endl;
            }
            else if (guess > target) {
                life--;
                cout << "!!! WRONG CHOICE !!! Your guess is too high. You lost 1 life. Remaining lives: " << life << endl;
            }
            else if (life <= 0) {
                cout << "\n!!! GAME OVER !!! You ran out of lives during the challenge.\n";
                cout << "\t=========MISSION FAILED========\n\n";
                break;
            }

            attempt++;
        }
    } while (attempt <= max_Attempts);

    //As soon as the winning flag(bool) is raised, you move to the next level.
    if (won) {
        cout << "\n--- MOVING ON ---\n";
        cout << "You successfully entered the LIBRARY. More clues await...\n";
        library();
    }
    else if (life < 0 || attempt > max_Attempts) {
        cout << "\n OUT OF TRIES. You failed the password challenge.\n";
        cout << "The correct number was: " << target << ".\n";
        cout << "!!YOU REMAIN TRAPPED!! \n";
        cout << "\t=========MISSION FAILED========\n\n";
    }
    return won;
}

//LIBRARY 
void library() {
    cout << "\n------------------------------------ LEVEL 2 --------------------------------------------\n";
    cout << "YOU ARE IN THE LIBRARY.\n";
    keys2();

}

void keys2() {
    cout << "On your right you see two keys:\n ||| KEY 1 \t KEY 2 |||\n";
    cout << "CHOOSE A KEY: One will get you CAUGHT, the other will LEAD you to the KITCHEN.\n";
    cout << "CHOOSE WISELY!\n";
    cout << "----------------------------------------------------------------------------------\n";
    cout << "Which key (1 or 2): ";
    cin >> key;

    ////switch statements are used because the players decisions control what happens next.
    //hardcoding the keys here, only key 1 leads to the right way.
    switch (key) {
    case 2:

        cout << "\nBAD LUCK! THE KEY WAS A TRAP!\nYou got caught!\n!!!GAME OVER!!!\n";
        cout << "\t=========MISSION FAILED========\n";
        break;

    case 1:

        cout << "\nGOOD CHOICE! Key 1 unlocks the way for your escape.\n";
        cout << "A secret door opens leading you to the next place.\n";
        cout << "\nKEY 1: THE LOCKED DOOR NEEDS A PASSWORD...\n";
        cout << "Every time you guess a wrong password, a life goes away.\n";
        password_room2();
        break;

    default:
        cout << "\nEntered wrong key!";
    }
}

//function to proceed to level 3.
int password_room2() {

    //the password should be guessed, which is a random number between 1 and 15.
    int target = 1 + rand() % 15;
    int guess;
    int attempt = 1;
    bool won = false;
    const int max_Attempts = 4;

    cout << "\n--- PASSWORD CHALLENGE ---\n";
    cout << "You have " << max_Attempts << " chances to guess the number (1 - 15).\n";

    do {
        cout << "\nLife count: " << life << " | Attempt " << attempt << " of " << max_Attempts << ".\n";
        cout << "Enter the guess number: ";
        cin >> guess;

        if (guess == target) {
            cout << "\n[!!! SUCCESS !!!] The lock clicks open!\n";
            cout << "The password was " << target << ". YOU PASSED THIS LEVEL!. Directing you to the KITCHEN now.\n";
            won = true;
            break;
        }
        else {
            if (guess < target) {
                life--;
                cout << "!!!WRONG CHOICE !!!Your guess is low. You lost 1 life. Remaining lives : " << life << endl;
            }
            else if (guess > target) {
                life--;
                cout << "!!! WRONG CHOICE !!! Your guess is high. You lost 1 life. Remaining lives: " << life << endl;
            }
            else if (life <= 0) {
                //going out of lives directly exits the game.
                cout << "\n!!! GAME OVER !!! You ran out of lives during the challenge.\n";
                cout << "\t=========MISSION FAILED========\n\n";
                break;
            }

            attempt++;
        }
    } while (attempt <= max_Attempts);


    if (won) {
        cout << "\n--- MOVING ON ---\n";
        cout << "You successfully entered the KITCHEN. More clues await...\n";
        kitchen();
    }
    else if (life < 0 || attempt > max_Attempts) {
        cout << "\n OUT OF TRIES. You failed the password challenge.\n";
        cout << "The correct number was: " << target << ".\n";
        cout << "!!YOU REMAIN TRAPPED!! \n";
        cout << "\t=========MISSION FAILED========\n\n";
    }
    return won;
}

//level 3: KITCHEN
void kitchen() {
    cout << "\n------------------------------------- LEVEL 3 -------------------------------------------\n";
    cout << "YOU ARE IN THE KITCHEN.\n";
    keys3();
}

void keys3() {
    //level 3 has three keys and the cirrect key is only number 3.
    cout << "In front of you, you see three keys:\n ||| KEY 1 \t KEY 2 \t KEY 3 |||\n";
    cout << "CHOOSE A KEY: One will COST a life, one will get you CAUGHT the one will let you ESCAPE from the back door.\n";
    cout << "CHOOSE WISELY!\n";
    cout << "----------------------------------------------------------------------------------\n";
    cout << "Which key (1 or 2 or 3): ";
    cin >> key;


    switch (key) {
    case 1:
        cout << "\nBAD LUCK! THE KEY WAS A TRAP!\nYou got caught!\n\t!!!GAME OVER!!!\n";
        cout << "\t=========MISSION FAILED========\n\n";
        break;

    case 3:

        cout << "\nGOOD CHOICE! Key 3 unlocks the way for your escape.\n";
        cout << "A secret door appears for your escape.\n";
        cout << "\nKEY 3: THE LOCKED DOOR NEEDS A PASSWORD...\n";
        cout << "Every time you guess a wrong password, a life goes away.\n";
        password_room3();
        break;

    case 2:
        cout << "\n OOPS! YOU LOST A LIFE. The key was a distraction.\n";
        life--;
        cout << "You have " << life << " LIVES remaining.\n";

        //you only get a chance to choose again IF you still have lives yet. Otherwise you lose.
        if (life > 0) {
            cout << "You still get a chance to try the other key.\n";
            cout << "Which key (key 1 or 3): ";
            cin >> key2;

            switch (key2) {
            case 1:

                cout << "\nBAD LUCK! THE KEY WAS A TRAP!\nYou got caught!\n\t!!!GAME OVER!!!\n";
                break;

            case 3:
                cout << "\n GOOD CHOICE! Key 3 unlocks the way for your escape.\n";
                cout << "KEY 3: THE LOCKED DOOR NEEDS A PASSWORD...\n";
                cout << "Every time you guess a wrong password, a life goes away.\n";
                password_room3();
            }
        }
        else {
            cout << "\n!!! GAME OVER !!! You ran out of lives.\n";
            cout << "\t=========MISSION FAILED========\n\n";
        }
        break;

    default:
        cout << "\nEntered wrong key!";
    }
}

//function for the password of level 3.
int password_room3() {

    //the probability of choosing the right number decreases as the levels proceed.
    //the password is a random number between 1 and 20.
    int target = 1 + rand() % 20;
    int guess;
    int attempt = 1;
    bool won = false;
    const int max_Attempts = 4;

    cout << "\n--- PASSWORD CHALLENGE ---\n";
    cout << " You have " << max_Attempts << " chances to guess the number (1 - 20).\n";

    do {
        cout << "\nLife count: " << life << " | Attempt " << attempt << " of " << max_Attempts << ".\n";
        cout << "Enter the guess number: ";
        cin >> guess;

        //you only win if you escape through all three doors by guessing all 3 passwords right AND all before running out of lives.
        if (guess == target) {
            cout << "\n[!!! SUCCESS !!!] The lock clicks open!\n";
            cout << "The password was " << target << ". YOU WON this challenge!.\n\t\t!!!YOU ARE NOW FREE!!!\n";
            cout << "\n==============ESCAPE MISSION SUCCESSFUL=====================\n\n";
            won = true;
            break;
        }
        else {
            if (guess < target) {
                life--;
                cout << " !!! WRONG CHOICE !!!Your guess is low. You lost 1 life. Remaining lives : " << life << endl;
            }
            else if (guess > target) {
                life--;
                cout << "!!! WRONG CHOICE !!! Your guess is high. You lost 1 life. Remaining lives: " << life << endl;
            }
            else if (life <= 0) {
                cout << "\n!!! GAME OVER !!! You ran out of lives during the challenge.\n";
                cout << "\t=========MISSION FAILED========\n\n";
                break;
            }

            attempt++;
        }
    } while (attempt <= max_Attempts);

    if (life < 0 || attempt > max_Attempts) {
        cout << "\n OUT OF TRIES. You failed the password challenge.\n";
        cout << "The correct number was: " << target << ".\n";
        cout << "!!YOU REMAIN TRAPPED!! \n";
        cout << "\t=========MISSION FAILED========\n\n";
    }
    return won;
}