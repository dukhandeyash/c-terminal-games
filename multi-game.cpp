#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <cstring>
#include<bits/stdc++.h>
using namespace std;

//yash
void board();// function to draw the board
int check_progress();// function to check game progress
int roll_dice();// function to roll dice
int roll; //holds the rolled value for the player
int computer_roll; //holds the rolled value for computer
int input; //variable to hold the users input, any number to roll dice and 0 to quit game, entering a not a number value ends  the game as well
int progress; //holds the value for the progress
int player = 0;
int computer = 0;
//both player and computer's initial starting point is 0
int squares[99]; // for the 100 squares

void snakenladders(){
  srand( time(NULL) ); //for randomn numbers

    string alert = ""; //to alert you for your W's and L's
    string computer_alert = ""; // to alert you for computer's W's and L's

    cout << "Welcome to snakes and ladders, enter any number to roll dice, press 0 to quit\n\n";
    cout << "SNAKES\tLADDERS\n99-5\t4-36\n93-25\t8-28\n77-9\t20-41\n52-6\t35-67\n30-2\t45-66\n\n";

    for ( int i = 1; i <= 100; i++) // to give square values
        {
            squares[i] = i;
        }

    do 
    {
        cout << "enter: ";
        cin >> input;

        roll = roll_dice();//player rolls dice

        if( (roll + player) > 100)
        {
            player = player; //player has rolled a number that exceeds the end point player remains where they are
        }
        else
        {
            squares[player] = player;//overwrite the current position
            player = player + roll;//move player to a new position
        }

        computer_roll = roll_dice();//computer rolls dice

        if( (computer_roll + computer) > 100)
        {
            computer = computer; //computer has rolled a number that exceeds the end point, computer remains where it is
        }
        else
        {
            squares[computer] = computer;//overwrite the current position
            computer = computer + computer_roll;//move computer to a new position
        }

        switch(player) // numbers represent the snakes and ladders
        {
            case 99:
            player = 5;
            alert = "OOPS... You ran into a SNAKE!";
            break;

            case 93:
            player = 25;
            alert = "OOPS... You ran into a SNAKE!";
            break;

            case 77:
            player = 9;
            alert = "OOPS... You ran into a SNAKE!";
            break;

            case 52:
            player = 6;
            alert = "OOPS... You ran into a SNAKE!";
            break;

            case 30:
            player = 2;
            alert = "OOPS... You ran into a SNAKE!";
            break;

            case 45:
            player = 66;
            alert = "YAY! you climbed a ladder!!!";
            break;

            case 35:
            player = 67;
            alert = "YAY! you climbed a ladder!!!";
            break;

            case 20:
            player = 41;
            alert = "YAY! you climbed a ladder!!!";
            break;

            case 8:
            player = 28;
            alert = "YAY! you climbed a ladder!!!";
            break;

            case 4:
            player = 36;
            alert = "YAY! you climbed a ladder!!!";
            break;

            default:
            alert = "";

        }

        switch(computer)
        {
            case 99:
            computer = 5;
            computer_alert = "OOPS... Computer ran into a SNAKE!";
            break;

            case 93:
            computer = 25;
            computer_alert = "OOPS... Computer ran into a SNAKE!";
            break;

            case 77:
            computer = 9;
            computer_alert = "OOPS... Computer ran into a SNAKE!";
            break;

            case 52:
            computer = 6;
            computer_alert = "OOPS... Computer ran into a SNAKE!";
            break;

            case 30:
            computer = 2;
            computer_alert = "OOPS... Computer ran into a SNAKE!";
            break;

            case 45:
            computer = 66;
            computer_alert = "HAHA! computer climbed a ladder!!!";
            break;

            case 35:
            computer = 67;
            computer_alert = "HAHA! computer climbed a ladder!!!";
            break;

            case 20:
            computer = 41;
            computer_alert = "HAHA! computer climbed a ladder!!!";
            break;

            case 8:
            computer = 28;
            computer_alert = "HAHA! computer climbed a ladder!!!";
            break;

            case 4:
            computer = 36;
            computer_alert = "HAHA! computer climbed a ladder!!!";
            break;

            default:
            computer_alert = "";
        }

        squares[player] = 999; //player's position shall be represented by the integer 999
        squares[computer] = 111; //computer's position shall be represented by the integer 111

        if ( input != 0)
        {
            cout<<"You rolled "<<roll<<" Computer rolled "<<computer_roll<<endl;
            cout<<"Your Position: "<<player<<" Computer's Position: "<<computer<<endl;
            cout <<alert<<endl;
            cout <<computer_alert<<endl;

            board();
            cout << "SNAKES\tLADDERS\n99-5\t4-36\n93-25\t8-28\n77-9\t20-41\n52-6\t35-67\n30-2\t45-66\n\n"; //so the player knows which is a snake and that which is ladder
        }

        progress = check_progress();

    }
    while ( progress == 0 && input != 0 );

    if ( squares[100] == 200)
    {
        cout << "||You Win!||"<<endl;
    }
    else if ( squares[100] == 300)
    {
        cout << "||Game Over Computer Wins!"<<endl;
    }
    else
    {
        cout << "You Quit!";
    }

    cin.get();
    cin.ignore();
}

//surya
void chess(){
  string chess[8][8] = {"WE1", "WKn1", "WB1", "WQ", "WK", "WB2", "Wkn2", "WE2",
                          "WP1", "WP2", "WP3", "WP4", "WP5", "WP6", "WP7", "WP8",
                          "0", "0", "0", "0", "0", "0", "0", "0",
                          "0", "0", "0", "0", "0", "0", "0", "0",
                          "0", "0", "0", "0", "0", "0", "0", "0",
                          "0", "0", "0", "0", "0", "0", "0", "0",
                          "BP1", "BP2", "BP3", "BP4", "BP5", "BP6", "BP7", "BP8",
                          "BE1", "BKn1", "BB1", "BQ", "BK", "BB2", "Bkn2", "BE2"};
    for(int i = 1; i<=8; i++)
    {
        cout << i << "     ";
    }
    cout << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (chess[i][j] != "0") {
                cout << chess[i][j] + "   ";
            } else {
                cout << chess[i][j] + "     ";
            }
        }
        cout << endl;
    }
    while (1) {
        for (int i = 1; i > 0; i++) {
            cout << "Black's turn!\n";
            cout << "Enter which piece you want to move: \n";
            string choice;
            cin >> choice;
            int a, b;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (chess[i][j] == choice) {
                        a = i;
                        b = j;
                    }
                }
            }
            cout << choice << endl;
            if (choice[0] == 'B' && choice[1] == 'P') {
                cout << "Enter the row you want to move to: \n";
                int p;
                cin >> p;
                cout << "Enter the column you want to move to: \n";
                int q;
                cin >> q;
                int x = p - 1;
                int y = q - 1;
                if ((x + 1 == a && y + 1 == b) || (x - 1 == a && y + 1 == b) || (x + 1 == a && y - 1 == b) || (x - 1 == a && y - 1 == b)){
                    if (chess[x][y][0] == 'W') {
                        cout << chess[x][y] << " is out!\n";
                        chess[x][y] = choice;
                        chess[a][b] = "0";
                    }
                    else  {
                        cout << "You can't move there!\n";
                        continue;
                    }
                }
                else if( ((x + 1 == a && y == b) || (x + 2 == a && y == b)))
                {
                    if (chess[x][y][0] == 'W') {
                        cout << "You can't remove the piece ahead of you!\n";
                        continue;
                    }
                    else if (chess[x][y][0] == 'B') {
                        cout << "You can't move there!\n";
                        continue;
                    } else {
                        chess[x][y] = choice;
                        chess[a][b] = "0";
                    }
                }
                else if ((x - 1 == a && y == b) || (x - 2 == a && y == b)) {

                    if (chess[x][y][0] == 'W') {
                        cout << "You can't remove the piece ahead of you!\n";
                    }
                    else if(chess[x][y][0] == 'B')
                    {
                        cout << "You can't move there!\n";
                        continue;
                    }
                    else {
                        chess[x][y] = choice;
                        chess[a][b] = "0";
                    }
                } else {
                    cout << "You can't move there!\n";
                    continue;
                }
            } else if (choice[0] == 'B' && choice[1] == 'E') {
                cout << "Enter whether you want to move in a row or a column(row|column)\n";
                string rc;
                cin >> rc;
                if (rc == "row") {
                    cout << "Enter the row you want to move to: \n";
                    int r;
                    cin >> r;
                    int qw = 0;
                    for (int o = a - 1; o > r - 1; o--) {
                        cout << chess[o][b] << endl;
                        if (chess[o][b][0] == 'B') {
                            qw++;
                        }
                    }
                    if (qw > 0) {
                        cout << "There is a piece of yours in the way!\n";
                        continue;
                    } else if (chess[r][b][0] == 'W') {
                        cout << chess[r][b] << " is out!\n";
                        chess[r - 1][b] = choice;
                        chess[a][b] = "0";
                    } else {
                        chess[r - 1][b] = choice;
                        chess[a][b] = "0";
                    }

                } else if (rc == "column") {
                    cout << "Enter the column you want to move to: \n";
                    int c;
                    cin >> c;
                    int qw1 = 0;
                    for (int o = b - 1; o > c - 1; o--) {
                        if (chess[a][o][0] == 'B') {
                            qw1++;
                        }
                    }
                    if (qw1 > 0) {
                        cout << "There is a piece of yours in the way!\n";
                        continue;
                    } else if (chess[a][c - 1][0] == 'W') {
                        cout << chess[a][c] << " is out!\n";
                        chess[a][c - 1] = choice;
                        chess[a][b] = "0";
                    } else {
                        chess[a][c - 1] = choice;
                        chess[a][b] = "0";
                    }

                }
            } else if (choice == "BKn1" || choice == "BKn2") {
                cout << "Enter the row you want to move to:\n";
                int rkn1, ckn1;
                cin >> rkn1;
                int rkn = rkn1 - 1;
                cout << "Enter the column you want to move to:\n";
                cin >> ckn1;
                int ckn = ckn1 - 1;
                int qw5 = 0;

                 if ((rkn + 2 == a && ckn - 1 == b) || (rkn - 2 == a && ckn + 1 == b)) {
                    if (chess[rkn][ckn][0] == 'W') {
                        cout << chess[rkn][ckn] << " is out!\n";
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice;
                    }
                    else if(chess[rkn][ckn][0] == 'B')
                    {
                        cout << "You can't move there!\n";
                    }else {
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice;
                    }
                } else if ((rkn + 1 == a && ckn - 2 == b) || (rkn - 1 == a && ckn + 2 == b)) {
                    if (chess[rkn][ckn][0] == 'W') {
                        cout << chess[rkn][ckn] << " is out!\n";
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice;
                    }
                    else if(chess[rkn][ckn][0] == 'B')
                    {
                        cout << "You can't move there!\n";
                    }else {
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice;
                    }
                } else {
                    cout << "You can't move there!\n";
                    continue;
                }
            } else if (choice == "BK") {
                cout << "Enter the row you want to move to: \n";
                int rk1, ck1;
                cin >> rk1;
                cout << "Enter the column you want to move to: \n";
                cin >> ck1;
                int rk = rk1 - 1;
                int ck = ck1 - 1;
                if (chess[rk][ck][0] == 'B') {
                    cout << "You can't move there!\n";
                    continue;
                } else if (chess[rk][ck][0] == 'W') {
                    cout << chess[rk][ck] << " is out!\n";
                    chess[rk][ck] = choice;
                    chess[a][b] = "0";
                } else {
                    if ((rk - 1 == a && ck == b) || (rk == a && ck - 1 == b) || (rk - 1 == a && ck - 1 == b) ||
                        (rk + 1 == a && ck == b) || (rk == a && ck + 1 == b) || (rk + 1 == a && ck + 1 == b)) {
                        chess[rk][ck] = choice;
                        chess[a][b] = "0";
                    }
                }
            } else if (choice == "BB1" || choice == "BB2") {
                int rb1, cb1;
                cout << "Enter the row you want to move to:\n";
                cin >> rb1;
                cout << "Enter the column you want to move to:\n";
                cin >> cb1;
                int rb = rb1 - 1;
                int cb = cb1 - 1;
                int cob = 0;
                int mb1 = cb;
                int mb2 = b;
                if (rb > a && cb > b) {
                    for (int i = a + 1; i > rb - 1; i--) {
                        if (chess[i][mb1][0] == 'B') {
                            cout << chess[i][mb1] << " 1" << endl;
                            cob++;
                        }
                        mb1--;
                        if (mb1 == b + 1) {
                            break;
                        }
                    }
                } else if (rb < a && cb > b) {
                    for (int i = a - 1; i > rb - 1; i--) {

                        if (chess[i][mb2+1][0] == 'B') {
                            cout << chess[i][mb2] << " 2" << endl;
                            cob++;
                        }
                        mb2++;
                        if (mb2 == cb - 1) {
                            break;
                        }
                    }
                } else if (rb > a && cb < b) {
                    for (int i = a + 1; i > rb - 1; i--) {
                        if (chess[i][mb1][0] == 'B') {
                            cout << chess[i][mb1] << " 3" << endl;
                            cob++;
                        }
                        mb1++;
                        if (mb1 == b + 1) {
                            break;
                        }
                    }
                } else {
                    for (int i = rb + 1; i < a - 1; i++) {
                        if (chess[i][mb2][0] == 'B') {
                            cout << chess[i][mb2] << " 4" << endl;
                            cob++;
                        }
                        mb2--;
                        if (mb2 == b - 1) {
                            break;
                        }
                    }
                }
                cout << cob << endl;
                if (cob > 0) {
                    cout << "You can't move there!\n";
                    continue;
                } else if ((rb - a == cb - b) || (a - rb == b - cb) || (rb - a == b - cb) || (a - rb == cb - b)) {
                    if (chess[rb][cb][0] == 'W') {
                        cout << chess[rb][cb] << " is out!\n";
                        chess[rb][cb] = choice;
                        chess[a][b] = "0";
                    } else {
                        chess[rb][cb] = choice;
                        chess[a][b] = "0";
                    }
                } else {
                    cout << "You can't move there!\n";
                    continue;
                }

            } else if (choice == "BQ") {
                int rq1, cq1;
                cout << "Enter the row you want to move to:\n";
                cin >> rq1;
                cout << "Enter the column you want to move to:\n";
                cin >> cq1;
                int rq = rq1 - 1;
                int cq = cq1 - 1;
                int cot = 0;
                for (int mq = a; mq > rq; mq--) {
                    for (int nq = b; nq > cq; nq--) {
                        if (chess[mq][nq][0] == 'B') {
                            cot++;
                        }
                    }
                }
                if (cot > 0) {
                    cout << "You can't move there!\n";
                    continue;
                } else if (chess[rq][cq][0] == 'W') {
                    cout << chess[rq][cq] << " is out!";
                    chess[rq][cq] = choice;
                    chess[a][b] = "0";
                } else {
                    chess[rq][cq] = choice;
                    chess[a][b] = "0";
                }
            } else {
                cout << "Wrong Input!\n";
                continue;
            }
            for(int i = 1; i<=8; i++)
            {
                cout << i << "     ";
            }
            cout << endl;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (chess[i][j] != "0") {
                        cout << chess[i][j] + "   ";
                    } else {
                        cout << chess[i][j] + "     ";
                    }
                }
                cout << endl;
            }
            break;
        }
        int cmb = 0;
        int cmw = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (chess[i][j] == "BK") {
                    cmb++;
                } else if (chess[i][j] == "WK") {
                    cmw++;
                }
            }
        }
        if (cmb == 0) {
            cout << "Game Over! White Wins!\n";
            break;
        } else if (cmw == 0) {
            cout << "Game Over! Black Wins!\n";
            break;
        } else {
        }
        for (int i = 1; i >= 1; i++) {
            cout << "White's turn!\n";
            cout << "Enter which piece you want to move: \n";
            string choice1;
            cin >> choice1;
            int a, b;
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                    if (chess[i][j] == choice1) {
                        a = i;
                        b = j;
                    }
                }
            }
            if (choice1[0] == 'W' && choice1[1] == 'P') {
                cout << "Enter the row you want to move to: \n";
                int p;
                cin >> p;
                cout << "Enter the column you want to move to: \n";
                int q;
                cin >> q;
                int x = p - 1;
                int y = q - 1;
                if ((x + 1 == a && y + 1 == b) || (x - 1 == a && y + 1 == b) || (x + 1 == a && y - 1 == b) || (x - 1 == a && y - 1 == b)){
                    if (chess[x][y][0] == 'B') {
                        cout << chess[x][y] << " is out!\n";
                        chess[x][y] = choice1;
                        chess[a][b] = "0";
                    }
                    else  {
                        cout << "You can't move there!\n";
                        continue;
                    }
                }
                else if( ((x + 1 == a && y == b) || (x + 2 == a && y == b)))
                {
                    if (chess[x][y][0] == 'B') {
                        cout << "You can't remove the piece ahead of you!\n";
                        continue;
                    }
                    else if (chess[x][y][0] == 'W') {
                        cout << "You can't move there!\n";
                        continue;
                    } else {
                        chess[x][y] = choice1;
                        chess[a][b] = "0";
                    }
                }
                else if ((x - 1 == a && y == b) || (x - 2 == a && y == b)) {

                    if (chess[x][y][0] == 'B') {
                        cout << "You can't remove the piece ahead of you!\n";
                    }
                    else if(chess[x][y][0] == 'W')
                    {
                        cout << "You can't move there!\n";
                        continue;
                    }
                    else {
                        chess[x][y] = choice1;
                        chess[a][b] = "0";
                    }
                } else {
                    cout << "You can't move there!\n";
                    continue;
                }
            } else if (choice1[0] == 'W' && choice1[1] == 'E') {
                cout << "Enter whether you want to move in a row or a column(row|column)\n";
                string rc;
                cin >> rc;
                if (rc == "row") {
                    cout << "Enter the row you want to move to: \n";
                    int r;
                    cin >> r;
                    int qw = 0;
                    for (int o = a - 1; o > r - 1; o--) {
                        cout << chess[o][b] << endl;
                        if (chess[o][b][0] == 'B') {
                            qw++;
                        }
                    }
                    if (qw > 0) {
                        cout << "There is a piece of yours in the way!\n";
                        continue;
                    } else if (chess[r][b][0] == 'W') {
                        cout << chess[r][b] << " is out!\n";
                        chess[r - 1][b] = choice1;
                        chess[a][b] = "0";
                    } else {
                        chess[r - 1][b] = choice1;
                        chess[a][b] = "0";
                    }

                } else if (rc == "column") {
                    cout << "Enter the column you want to move to: \n";
                    int c;
                    cin >> c;
                    int qw1 = 0;
                    for (int o = b - 1; o > c - 1; o--) {
                        if (chess[a][o][0] == 'B') {
                            qw1++;
                        }
                    }
                    if (qw1 > 0) {
                        cout << "There is a piece of yours in the way!\n";
                        continue;
                    } else if (chess[a][c - 1][0] == 'W') {
                        cout << chess[a][c] << " is out!\n";
                        chess[a][c - 1] = choice1;
                        chess[a][b] = "0";
                    } else {
                        chess[a][c - 1] = choice1;
                        chess[a][b] = "0";
                    }

                }
            } else if (choice1 == "WKn1" || choice1 == "WKn2") {
                cout << "Enter the row you want to move to:\n";
                int rkn1, ckn1;
                cin >> rkn1;
                int rkn = rkn1 - 1;
                cout << "Enter the column you want to move to:\n";
                cin >> ckn1;
                int ckn = ckn1 - 1;
                int qw5 = 0;
                for (int as = a - 1; as > rkn - 1; as--) {
                    for (int sa = b - 1; sa > ckn - 1; sa--) {
                        cout << chess[rkn][ckn] << endl;
                        if (chess[rkn][ckn][0] == 'B') {
                            qw5++;
                        }
                    }
                }
                if (qw5 > 0) {
                    cout << "There is a piece of yours in the way!\n";
                    continue;
                } else if ((rkn + 2 == a && ckn - 1 == b) || (rkn - 2 == a && ckn + 1 == b)) {
                    if (chess[rkn][ckn][0] == 'W') {
                        cout << chess[rkn][ckn] << " is out!\n";
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice1;
                    } else {
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice1;
                    }
                } else if ((rkn + 1 == a && ckn - 2 == b) || (rkn - 1 == a && ckn + 2 == b)) {
                    if (chess[rkn][ckn][0] == 'W') {
                        cout << chess[rkn][ckn] << " is out!\n";
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice1;
                    } else {
                        chess[a][b] = "0";
                        chess[rkn][ckn] = choice1;
                    }
                } else {
                    cout << "You can't move there!\n";
                    continue;
                }
            } else if (choice1 == "WK") {
                cout << "Enter the row you want to move to: \n";
                int rk1, ck1;
                cin >> rk1;
                cout << "Enter the column you want to move to: \n";
                cin >> ck1;
                int rk = rk1 - 1;
                int ck = ck1 - 1;
                if (chess[rk][ck][0] == 'B') {
                    cout << "You can't move there!\n";
                    continue;
                } else if (chess[rk][ck][0] == 'W') {
                    cout << chess[rk][ck] << " is out!\n";
                    chess[rk][ck] = choice1;
                    chess[a][b] = "0";
                } else {
                    if ((rk - 1 == a && ck == b) || (rk == a && ck - 1 == b) || (rk - 1 == a && ck - 1 == b) ||
                        (rk + 1 == a && ck == b) || (rk == a && ck + 1 == b) || (rk + 1 == a && ck + 1 == b)) {
                        chess[rk][ck] = choice1;
                        chess[a][b] = "0";
                    }
                    else
                    {
                        cout << "You cannot move there!\n";
                        continue;
                    }
                }
            } else if (choice1 == "WB1" || choice1 == "WB2") {
                int rb1, cb1;
                cout << "Enter the row you want to move to:\n";
                cin >> rb1;
                cout << "Enter the column you want to move to:\n";
                cin >> cb1;
                int rb = rb1 - 1;
                int cb = cb1 - 1;
                int cob = 0;
                int mb1 = cb;
                int mb2 = b;
                if (rb > a && cb > b) {
                    for (int i = a + 1; i > rb - 1; i--) {
                        if (chess[i][mb1][0] == 'B') {
                            cout << chess[i][mb1] << " 1" << endl;
                            cob++;
                        }
                        mb1--;
                        if (mb1 == b + 1) {
                            break;
                        }
                    }
                } else if (rb < a && cb > b) {
                    for (int i = a - 1; i > rb - 1; i--) {
                        cout << i << endl;
                        cout << mb2 << endl;
                        if (chess[i][mb2][0] == 'B') {
                            cout << chess[i][mb2] << " 2" << endl;
                            cob++;
                        }
                        mb2++;
                        if (mb2 == cb - 1) {
                            break;
                        }
                    }
                } else if (rb > a && cb < b) {
                    for (int i = a + 1; i > rb - 1; i--) {
                        if (chess[i][mb1][0] == 'B') {
                            cout << chess[i][mb1] << " 3" << endl;
                            cob++;
                        }
                        mb1++;
                        if (mb1 == b + 1) {
                            break;
                        }
                    }
                } else {
                    for (int i = rb + 1; i < a - 1; i++) {
                        if (chess[i][mb2][0] == 'B') {
                            cout << chess[i][mb2] << " 4" << endl;
                            cob++;
                        }
                        mb2--;
                        if (mb2 == b - 1) {
                            break;
                        }
                    }
                }
                cout << cob << endl;
                if (cob > 0) {
                    cout << "You can't move there!\n";
                    continue;
                } else if ((rb - a == cb - b) || (a - rb == b - cb) || (rb - a == b - cb) || (a - rb == cb - b)) {
                    if (chess[rb][cb][0] == 'W') {
                        cout << chess[rb][cb] << " is out!\n";
                        chess[rb][cb] = choice1;
                        chess[a][b] = "0";
                    } else {
                        chess[rb][cb] = choice1;
                        chess[a][b] = "0";
                    }
                } else {
                    cout << "You can't move there!\n";
                    continue;
                }

            } else if (choice1 == "WQ") {
                int rq1, cq1;
                cout << "Enter the row you want to move to:\n";
                cin >> rq1;
                cout << "Enter the column you want to move to:\n";
                cin >> cq1;
                int rq = rq1 - 1;
                int cq = cq1 - 1;
                int cot = 0;
                for (int mq = a; mq > rq; mq--) {
                    for (int nq = b; nq > cq; nq--) {
                        if (chess[mq][nq][0] == 'B') {
                            cot++;
                        }
                    }
                }
                if (cot > 0) {
                    cout << "You can't move there!\n";
                    continue;
                } else if (chess[rq][cq][0] == 'W') {
                    cout << chess[rq][cq] << " is out!";
                    chess[rq][cq] = choice1;
                    chess[a][b] = "0";
                } else {
                    chess[rq][cq] = choice1;
                    chess[a][b] = "0";
                }
            } else {
                cout << "Wrong Input!\n";
                continue;
            }
            break;
        }
        for(int i = 1; i<=8; i++)
        {
            cout << i << "     ";
        }
        cout << endl;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (chess[i][j] != "0") {
                    cout << chess[i][j] + "   ";
                } else {
                    cout << chess[i][j] + "     ";
                }
            }
            cout << endl;
        }
        int cmb1 = 0;
        int cmw1 = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (chess[i][j] == "BK") {
                    cmb1++;
                } else if (chess[i][j] == "WK") {
                    cmw1++;
                }
            }
        }
        if (cmb1 == 0) {
            cout << "Game Over! White Wins!\n";
            break;
        } else if (cmw1 == 0) {
            cout << "Game Over! Black Wins!\n";
            break;
        } else {
            continue;
        }
    }

}

//neel
void DrawMan(int tries){
	cout<<endl<<endl;
	cout<<"  -----"<<endl;
	cout<<"  |   |"<<endl;
	cout<<"  |"; if(tries>=1) cout<<"   O    "; cout<<endl;
	cout<<"  |"; if(tries>=3) cout<<"  /|\\   "; cout<<endl;
	cout<<"  |"; if(tries>=5) cout<<"  / \\    "; cout<<endl;
	cout<<"  |"<<endl;
	cout<<"_|_"<<endl;
}


void hangman(){
    srand (time(NULL));
	string wordList[5] = {"programming","namespace","iostream","identifier","string"};
	string word;
	string guessed;

	word = wordList[rand()%5];

	int wordLength = word.length();
	string dispWord (wordLength, '_');

	int found = 0;
	char guess = ' ';
	int tries = 5; //No of wrong tries
	int flagFound = 0;

	while(tries>=0){
		system("cls");
		cout<<"Guess the term: "<<endl<<endl;

		for(int i=0; i<wordLength; i++)
			cout<<" "<<dispWord[i]<<" ";
		cout<<endl<<endl<<endl;

		cout<<"Wrong Attempts: "<<tries<<" / "<<WRONGTRIES<<endl;
		cout<<"Guessed Letters: "<<guessed<<endl;

		DrawMan(tries);

		if( found == wordLength ){
			cout<<endl;
			cout<<"*******"<<endl;
			cout<<"*    You Win    *"<<endl;
			cout<<"*******"<<endl;
			break;
		}

		if( tries == 0) break;

		cout<<"Pick a Letter:";
		guess = getche();

		guessed = guessed + " " + guess;

		if( dispWord.find(guess)!=string::npos ) tries++;

		flagFound = 0;
		for(int i=0; i<wordLength; i++){
			if( word[i]==guess && dispWord[i]=='_' ){
				dispWord[i] = guess;
				found++;
				flagFound = 1;
			}
		}

		if( !flagFound )
			tries--;
	}
	if( found != wordLength ){
		cout<<endl;
		cout<<"******"<<endl;
		cout<<"*    You Lose    *"<<endl;
		cout<<"******"<<endl;
	}

	getch();
}

//gagandeep

void add (char a[3][3], char inp, char ch)
{
	int num = inp-49, row,col;
	row=num/3, col=num%3;
	a[row][col] = ch;
}

void disp(char a[3][3])
{
	cout <<"Tic Tac Toe" << endl;
	int i,j;
	for(i=0;i<3;i++)
	{
		cout << "-------------\n";
		for(j=0;j<3;j++)
		{
			if(a[i][j]=='a') cout<<"|   ";
			else
				cout << "| "<<a[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << "-------------\n";
}

int check(char a[3][3],char inp)
{
	int num=inp-48,row,col;
	if(num<=0 || num>=10) return 0;
	num--;
	row=num/3;
	col=num%3;
	if(a[row][col]=='a') return 1;
	else return 0;
}

char gameover(char a[3][3])
{
	char winner='a';
	if(a[0][0]==a[0][1] && a[0][0]==a[0][2] && a[0][0]!='a') winner=a[0][0];
	if(a[1][0]==a[1][1] && a[1][0]==a[1][2] && a[1][0]!='a') winner=a[1][0];
	if(a[2][0]==a[2][1] && a[2][0]==a[2][2] && a[2][0]!='a') winner=a[2][0];
	if(a[0][0]==a[1][0] && a[0][0]==a[2][0] && a[0][0]!='a') winner=a[0][0];
	if(a[0][1]==a[1][1] && a[0][1]==a[2][1] && a[0][1]!='a') winner=a[0][1];
	if(a[0][2]==a[1][2] && a[0][2]==a[2][2] && a[0][2]!='a') winner=a[0][2];
	if(a[0][0]==a[1][1] && a[0][0]==a[2][2] && a[0][0]!='a') winner=a[0][0];
	if(a[0][2]==a[1][1] && a[0][2]==a[2][0] && a[0][2]!='a') winner=a[0][2];
	return winner;
}

int draw(char a[3][3])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(a[i][j]=='a')
				return 0;
	return 1;
}

void tictactoe(){
  cout << "Tic Tac Toe\nPress any key to continue";
	getch();
	char a[3][3],turn[2]={'X','O'},ch='X',inp,winner,res;
	do
	{
		a[0][0]=a[0][1]=a[0][2]=a[1][0]=a[1][1]=a[1][2]=a[2][0]=a[2][1]=a[2][2]='a';
		system("cls");
		disp(a);
		cout << ""<< ch <<"'s Turn\n";
		int count=0;
		while(1)
		{
			inp=getch();
			system("cls");
			if(inp<=48 || inp>=58 || !check(a,inp))
			{
				disp(a);
				cout << "" << ch << "'s Turn\n";
				cout << "Invalid Move!\n";
			}
			else
			{
				add(a,inp,ch);
				disp(a);
				winner=gameover(a);
				if(winner=='a')
				{
					if(draw(a))
					{
						cout << "Draw!\n";
						break;
					}
					ch = turn[(++count)%2];
					cout << ch <<"'s Turn\n";
				}
				else
				{
					cout << winner << "Won!\n";
					break;
				}
			}
		}
		getch();
		system("cls");
		cout << "Play Again? (Y/N): ";
		cin >> res;
	}while(res=='y' || res=='Y');
}

int main(){
  int answer;
  cout<< "What do you wanna play?:"<<endl;
  cout << "1. Snake and Ladders" << endl << "2. Chess" << endl << "3. Tic Tac Toe" << endl << "4. Hangman"<<endl<<"5. Quit" << endl;
  cin >> answer;
  while(answer>0 && answer<6){
    switch(answer){
      case 1:
      snakenladders();

      case 2:
      chess();

      case 3:
      tictactoe();

      case 4:
      hangman();

      case 5:
      cout << "Thank you for playing!!!";
      break;
    }
  cout<< "What do you wanna play?:"<<endl;
  cout << "1. Snake and Ladders" << endl << "2. Chess" << endl << "3. Tic Tac Toe" << endl << "4. Hangman"<<endl<<"5. Quit" << endl;
  }
}

void board()//define the board drawing mechanism
{
    cout << "----------------------------------------------------------------------------"<<endl<<endl;
         cout << squares[100]<<"\t"<<squares[99]<<"\t"<<squares[98]<<"\t"<<squares[97]<<"\t"<<squares[96]<<"\t"
         <<squares[95]<<"\t"<<squares[94]<<"\t"<<squares[93]<<"\t"<<squares[92]<<"\t"<<squares[91]<<endl<<endl;

         cout << squares[81]<<"\t"<<squares[82]<<"\t"<<squares[83]<<"\t"<<squares[84]<<"\t"<<squares[85]<<"\t"
         <<squares[86]<<"\t"<<squares[87]<<"\t"<<squares[88]<<"\t"<<squares[89]<<"\t"<<squares[90]<<endl<<endl;

         cout << squares[80]<<"\t"<<squares[79]<<"\t"<<squares[78]<<"\t"<<squares[77]<<"\t"<<squares[76]<<"\t"
         <<squares[75]<<"\t"<<squares[74]<<"\t"<<squares[73]<<"\t"<<squares[72]<<"\t"<<squares[71]<<endl<<endl;

         cout << squares[61]<<"\t"<<squares[62]<<"\t"<<squares[63]<<"\t"<<squares[64]<<"\t"<<squares[65]<<"\t"
         <<squares[66]<<"\t"<<squares[67]<<"\t"<<squares[68]<<"\t"<<squares[69]<<"\t"<<squares[70]<<endl<<endl;

         cout << squares[60]<<"\t"<<squares[59]<<"\t"<<squares[58]<<"\t"<<squares[57]<<"\t"<<squares[56]<<"\t"
         <<squares[55]<<"\t"<<squares[54]<<"\t"<<squares[53]<<"\t"<<squares[52]<<"\t"<<squares[51]<<endl<<endl;

         cout << squares[41]<<"\t"<<squares[42]<<"\t"<<squares[43]<<"\t"<<squares[44]<<"\t"<<squares[45]<<"\t"
         <<squares[46]<<"\t"<<squares[47]<<"\t"<<squares[48]<<"\t"<<squares[49]<<"\t"<<squares[50]<<endl<<endl;

         cout << squares[40]<<"\t"<<squares[39]<<"\t"<<squares[38]<<"\t"<<squares[37]<<"\t"<<squares[36]<<"\t"
         <<squares[35]<<"\t"<<squares[34]<<"\t"<<squares[33]<<"\t"<<squares[32]<<"\t"<<squares[31]<<endl<<endl;

         cout << squares[21]<<"\t"<<squares[22]<<"\t"<<squares[23]<<"\t"<<squares[24]<<"\t"<<squares[25]<<"\t"
         <<squares[26]<<"\t"<<squares[27]<<"\t"<<squares[28]<<"\t"<<squares[29]<<"\t"<<squares[30]<<endl<<endl;

         cout << squares[20]<<"\t"<<squares[19]<<"\t"<<squares[18]<<"\t"<<squares[17]<<"\t"<<squares[16]<<"\t"
         <<squares[15]<<"\t"<<squares[14]<<"\t"<<squares[13]<<"\t"<<squares[12]<<"\t"<<squares[11]<<endl<<endl;

         cout << squares[1]<<"\t"<<squares[2]<<"\t"<<squares[3]<<"\t"<<squares[4]<<"\t"<<squares[5]<<"\t"
         <<squares[6]<<"\t"<<squares[7]<<"\t"<<squares[8]<<"\t"<<squares[9]<<"\t"<<squares[10]<<endl<<endl;
    cout << "----------------------------------------------------------------------------"<<endl;
}

int roll_dice()//define the dice rolling mechanism
{
    return rand() % (7-1) + 1;//can only roll 1 - 6
}

int check_progress()//define the progress checking mechanism
{
    if ( squares[100] == 200 || squares[100] == 300)
    {
        return 1;//game has ended... win! someone has
    }
    else
    {
        return 0;//game is still on, win no one has...
    }
}