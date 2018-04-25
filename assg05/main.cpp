#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

// Read the winning configurations
//* Read winning configurations from the file to the 1D-array
void ReadWinningConfig(char *WinningConfig)
{
    ifstream inData;
    inData.open("winningPatterns.txt");
    int i=0;
    //** Create a string to store the current string in the file
    string temp;
    while (inData)
    {
        inData>>temp;
        //** If the string is valid, then transfer its data to the array
        if ((temp!="***********") && (temp!="rows") && (temp!="diagonals") && (temp!="columns") && (temp!="top") && (temp!="to") && (temp!="bottom") && (temp!=""))
        {
            for (int j=0;j<3;j++)
            {
                WinningConfig[i+j]=temp[j];
            }
            i+=3;
        }
    }
    inData.close();
}

// Print the board
void PrintBoard(const char board[3][3][3])
{
    cout<<"  012\t  012\t  012"<<endl;
    for (int i=0;i<3;i++)
    {
        cout<<i<<'|'<<board[0][i][0]<<board[0][i][1]<<board[0][i][2]<<'\t'<<i<<'|'<<board[1][i][0]<<board[1][i][1]<<board[1][i][2]<<'\t'<<i<<'|'<<board[2][i][0]<<board[2][i][1]<<board[2][i][2]<<endl;
    }
    cout<<"   0\t   1\t   2"<<endl;
}

// Implement the 3D-board
void ImplementBoard(char board[3][3][3])
{
    //* Initiate a 3D-array for the board
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            for (int k=0;k<3;k++)
            {
                board[i][j][k]='.';
            }
        }
    }

    //* Print the board
    PrintBoard(board);
}

// Change the player
char ChangePlayer(char player)
{
    if (player=='o') return 'x';
    if (player=='x') return 'o';
}

// Check if the player has won by WinningConfig#i
bool CheckWin(const char board[3][3][3], const char *WinningConfig, const char player, const int i)
{
    for (int j=0;j<3;j++)
    {
        for (int k=0;k<3;k++)
        {
            for (int l=0;l<3;l++)
            {
                if (WinningConfig[i*27+k*9+j*3+l]=='o')
                {
                    if (board[j][k][l]!=player) return false;
                }
            }
        }
    }
    return true;
}

// Check if the player has won
bool CheckWin(const char board[3][3][3], const char *WinningConfig, const char player)
{
    for (int i=0;i<33;i++)
    {
        if (CheckWin(board, WinningConfig, player, i)) return true;
    }
    return false;
}

// Check if the board is full
bool CheckFull(const char board[3][3][3])
{
    for (int i=0;i<3;i++)
    {
        for (int j=0;j<3;j++)
        {
            for (int k=0;k<3;k++)
            {
                if (board[i][j][k]=='.') return false;
            }
        }
    }
    return true;
}

// Let 2 players play the game until the game is over
void GamePlay(char board[3][3][3], const char *WinningConfig)
{
    char player='o';
    bool InvalidEnter;
    int marker[3];
    string garbage;

    //* Do
    do
    {
        //* Request the player to place his/her markers
        //** Do
        do
        {
            InvalidEnter=false;
            //** Ask the player to input
            cout<<player<<" Player, enter layer,row,column, E.g: 0 1 2: ";
            cin>>marker[0]>>marker[1]>>marker[2];
            if ((!cin) || (abs(marker[0]-1)>1) || (abs(marker[1]-1)>1) || (abs(marker[2]-1)>1) || (board[marker[0]][marker[1]][marker[2]]!='.'))
            {
                cout<<"Invalid input!"<<endl;
                cin.clear();
                getline(cin, garbage);
                InvalidEnter=true;
            }
        }
        //** While the input is invalid
        while (InvalidEnter);

        //* Set the board with the user input after validation
        board[marker[0]][marker[1]][marker[2]]=player;
        //* Print the board
        PrintBoard(board);

        //* Check if the game is over
        //** Check if the player has won
        if (CheckWin(board, WinningConfig, player))
        //*** If the player has won, then{
        //*** Announce win
        //*** End the game}
        {
            cout<<"Player "<<player<<" wins!"<<endl;
            return;
        }
        //** Check if the board is full
        if (CheckFull(board))
        //*** If the board is full, then{
        //*** Announce to restart
        //*** Implement the 3D-board
        //*** Set to player2}
        {
            cout<<"The board is full, now restart.\n"<<endl;
            ImplementBoard(board);
            player='x';
        }
        //* Change the player
        player=ChangePlayer(player);
    }
    //* While the game is not over
    while (true);
}

int main()
{
    // Read the winning configurations
    //* Create a 1D-array to store the winning configurations
    char *WinningConfig;
    WinningConfig=new char[33*3*3*3];
    //* Read winning configurations from the file to the 1D-array
    ReadWinningConfig(WinningConfig);

    // Implement the 3D-board
    char board[3][3][3];
    ImplementBoard(board);

    // Let 2 players play the game until the game is over
    GamePlay(board, WinningConfig);

    delete []WinningConfig;
    WinningConfig=0;
    return 0;
}
