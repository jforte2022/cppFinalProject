
#include <iostream>
#include <string>
#include"C:/Users/andre/cppSchool/CPlusPlusExamples/CPlusPlusHowToProgram10e-master/examples/ch10/fig10_06_08/Date.h"
#include"C:/Users/andre/HeaderFilesForCpp/Game.h"
#include"C:/Users/andre/HeaderFilesForCpp/GameRecord.h"
using namespace std;

/// The main routine starts by prototyping the global functions and then shows the user a menu with options they can choose.
string name();
string dev();
string genre();
Date lastPlayedDate();
double highScore();
int timesPlayed();
double hoursPlayed();
int enemiesDefeated();
void showGameRecord(GameRecord);
int menu();
int numberOfGames();
Date releaseDate();

int main() {

    // Below, I create an array of objects that contains numberOfGames() elements. I use a pointer and the new command to make this work properly.

    GameRecord* gameInfoArray;
    int arraySize = numberOfGames();
    gameInfoArray = new GameRecord[arraySize];

    int choice;
    int gamesStored = 0;
    bool menuQuit = false;

    do {
        choice = menu();
        switch (choice) {
        case 1:
            if (gamesStored == arraySize) {
                cout << "\nYou have entered the maximum allowed number of games!" << endl;
            }
            else {

                string gameName = name();
                string gameDev = dev();
                string gameGenre = genre();
                Date release = releaseDate();

                gameInfoArray[gamesStored].setGameInfo(Game(gameName, gameDev, gameGenre, release));
                gameInfoArray[gamesStored].setLastPlayedDate(lastPlayedDate());
                gameInfoArray[gamesStored].setHighScore(highScore());
                gameInfoArray[gamesStored].setTimesPlayed(timesPlayed());
                gameInfoArray[gamesStored].setHoursPlayed(hoursPlayed());
                gameInfoArray[gamesStored].setEnemiesDefeated(enemiesDefeated());

                gamesStored += 1;
            }
            break;
        case 2:
            if (gamesStored == 0) {
                cout << "You have not entered any games yet." << endl;
            }
            else {
                cout << "\nHere is a list of all of the games you have entered: \n" << endl;
                for (int gameElement = gamesStored - 1; gameElement >= 0; gameElement--) {
                    string gameName = gameInfoArray[gameElement].getGameInfo().getGameName();
                    cout << gameName << endl;
                }
                string gameName;
                cout << "\nPlease enter the name of the game you wish to modify: ";
                cin.ignore();
                getline(cin, gameName);

                for (int gameElement = gamesStored - 1; gameElement >= 0; gameElement--) {
                    if (gameInfoArray[gameElement].getGameInfo().getGameName() != gameName) {
                        if (gameElement == 0) {
                            cout << "\nYou have not entered a valid game!" << endl;
                        }
                    }
                    else {
                        bool subMenuQuit = false;
                        int choice2;
                        do {
                            cout << "\nWhich parameter do you wish to modify?" << endl;
                            cout << "1. High Score\n2. Times Played\n3. Hours Played\n4. Enemies Defeated\n5. None" << endl;
                            cin >> choice2;

                            switch (choice2) {
                            case 1:
                                gameInfoArray[gameElement].setHighScore(highScore());
                                break;
                            case 2:
                                gameInfoArray[gameElement].setTimesPlayed(timesPlayed());
                                break;
                            case 3:
                                gameInfoArray[gameElement].setHoursPlayed(hoursPlayed());
                                break;
                            case 4:
                                gameInfoArray[gameElement].setEnemiesDefeated(enemiesDefeated());
                                break;
                            case 5:
                                subMenuQuit = true;
                                break;
                            default:
                                cout << "You have entered an invalid choice." << endl;
                                break;
                            }
                        } while (subMenuQuit == false);
                        break;
                    }
                }
            }
            break;
        case 3:
            for (int gameElement = gamesStored - 1; gameElement >= 0; gameElement--) {
                showGameRecord(gameInfoArray[gameElement]);
            }
            break;
        case 4:
            gamesStored = 0;
            menuQuit = true;
            break;
        default:
            break;
        }
    } while (menuQuit == false);
}

//Below is the menu subroutine
int menu() {
    string choice;
    int retchoice = 0;
    do {
        cout << "\n1. Enter New Game\n";
        cout << "2. Update Game Statistics\n";
        cout << "3. Display all Game Statistics\n";
        cout << "4. Quit\n";
        cout << "\nPlease Select an Option: ";
        cin >> choice;

        switch (choice[0]) {
        case '1':
            retchoice = 1;
            break;
        case '2':
            retchoice = 2;
            break;
        case '3':
            retchoice = 3;
            break;
        case '4':
            retchoice = 4;
            break;
        default:
            cout << "\nYou have entered an invalid choice.";
            retchoice = 0;
            break;
        }
    } while (retchoice == 0);
    return retchoice;
}

//Below is the subroutine code for formatting the output AND extracting the attribute values of the GameInformation objects.

void showGameRecord(GameRecord object) {
    if (object.getGameInfo().getGameName() == "Default") {
    }
    else {
        cout << "________________________________________________________________________\n\n"
            << object.getGameInfo().getGameName() << " is developed by " << object.getGameInfo().getGameDev()
            << "!\nIts genre is " << object.getGameInfo().getGameGenre() << " and was released on "
            << object.getGameInfo().getReleaseDate() << "!\nIt has been played " << object.getTimesPlayed()
            << " times for a High Score of " << object.getHighScore() << "!\nYou have " << object.getHoursPlayed() << " Hours Played and "
            << object.getEnemiesDefeated() << " Enemies Defeated!\nYou played this game as recently as " << object.getLastPlayedDate()
            << "!\n________________________________________________________________________" << endl;
    }
}

/// <summary>
/// Below are functions that are used to prompt the user for various data.
/// </summary>

int numberOfGames() {
    int games;
    cout << "How many games have you played that you wish to store? ";
    cin >> games;
    do {
        if (games < 0) {
            cout << "\nPlease enter a valid number of games played: ";
            cin >> games;
        }
    } while (games < 0);
    return games;
}
string name() {
    string title;
    cout << "Please enter the name of a video game you have played: ";
    cin.ignore();
    getline(cin, title);
    return title;
}
string dev() {
    string dev;
    cout << "Please enter the studio that developed this game: ";
    //cin.ignore();
    getline(cin, dev);
    return dev;
}
string genre() {
    string genre;
    cout << "Please enter the game's genre: ";
    //cin.ignore();
    getline(cin, genre);
    return genre;
}
Date releaseDate() {
    Date release;
    int yyyy = 0;
    int mm = 0;
    int dd = 0;
    do {
        cout << "Please enter the year in which the game was released: ";
        cin >> yyyy;
        if (yyyy < 1970 or yyyy > 2022) {
            cout << "Please enter a valid year!\n";
        }
    } while (yyyy < 1970 or yyyy > 2022);
    do {
        cout << "Please enter the month in the which the game was released: ";
        cin >> mm;
        if (mm < 1 or mm > 12) {
            cout << "\nPlease enter a valid month!";
        }
    } while (mm < 1 or mm > 12);
    do {
        cout << "Please enter the day in which the game was released: ";
        cin >> dd;
        if (dd < 1 or dd > 31) {
            cout << "\nPlease enter a valid day!";
        }
    } while (dd < 1 or dd > 31);
    release.setDate(mm, dd, yyyy);
    return release;
}

Date lastPlayedDate() {
    Date lastPlayed;
    int yyyy = 0;
    int mm = 0;
    int dd = 0;
    do {
        cout << "Please enter the year in which the game was last played: ";
        cin >> yyyy;
        if (yyyy < 1970 or yyyy > 2022) {
            cout << "\nPlease enter a valid year!";
        }
    } while (yyyy < 1970 or yyyy > 2022);
    do {
        cout << "Please enter the month in the which the game was last played: ";
        cin >> mm;
        if (mm < 1 or mm > 12) {
            cout << "Please enter a valid month!\n";
        }
    } while (mm < 1 or mm > 12);
    do {
        cout << "Please enter the day in which the game was last played: ";
        cin >> dd;
        if (dd < 1 or dd > 31) {
            cout << "Please enter a valid day!\n";
        }
    } while (dd < 1 or dd > 31);
    lastPlayed.setDate(mm, dd, yyyy);
    return lastPlayed;
}
double highScore() {
    double retval;
    cout << "Please enter your high score in this game: ";
    cin >> retval;
    do {
        if (retval < 0) {
            cout << "Please enter a valid High Score for the game: ";
            cin >> retval;
        }
    } while (retval < 0);
    return retval;
}
int timesPlayed() {
    int retval;
    cout << "Please enter the amount of times you have played this game: ";
    cin >> retval;
    do {
        if (retval < 0) {
            cout << "Please enter a valid number of times played for the game: ";
            cin >> retval;
        }
    } while (retval < 0);
    return retval;
}
double hoursPlayed() {
    double retval;
    cout << "Please enter the amount of hours you have played this game: ";
    cin >> retval;
    do {
        if (retval < 0) {
            cout << "Please enter a valid number of hours played for the game: ";
            cin >> retval;
        }
    } while (retval < 0);
    return retval;
}
int enemiesDefeated() {
    int enemies;
    cout << "Please enter the amount of enemies you have defeated in this game: ";
    cin >> enemies;
    do {
        if (enemies < 0) {
            cout << "Please enter a valid number of enemies defeated for the game: ";
            cin >> enemies;
        }
    } while (enemies < 0);
    return enemies;
}