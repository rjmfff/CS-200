// ADVENTURE

#include <iostream>
#include <string>
using namespace std;

#include "Room.hpp"
#include "Special.hpp"

void SetNeighbors( Room rooms[25], int room, int neighbor, Direction dir );
void LoadCoreRooms( Room rooms[25] );
void LoadStudentRooms( Room rooms[25] );

int main()
{
    bool done = false;

    string directions[4];
    directions[0] = "NORTH";
    directions[1] = "SOUTH";
    directions[2] = "EAST";
    directions[3] = "WEST";

    bool canMove[4] = { false, false, false, false };
    string commands[4] = { "N. North", "S. South", "E. East  ", "W. West  " };

    Room rooms[25];
    LoadCoreRooms( rooms );
    LoadStudentRooms( rooms );
    int currentRoom = 0;

    string lastMessage = "";

    while ( !done )
    {
        ClearScreen();

        rooms[ currentRoom ].Display();
        for ( int i = 0; i < 4; i++ )
        {
            int neighborIndex = rooms[ currentRoom ].GetNeighbor( Direction( i ) );
            if ( neighborIndex != -1 )
            {
                canMove[i] = true;
                cout << "To the " << directions[i] << " is " << rooms[ neighborIndex ].GetName() << endl;
            }
            else
            {
                canMove[i] = false;
            }
        }

        cout << endl;
        cout << "MOVE" << endl;
        for ( int i = 0; i < 4; i++ )
        {
            if ( canMove[i] )
            {
                cout << commands[i] << "\t";
            }
        }
        cout << endl;
        char choice;
        cout << endl << "What will you do? ";
        cin >> choice;
        choice = tolower( choice );

        while ( choice != 'n' && choice != 'e' && choice != 's' && choice != 'w' )
        {
            cout << "Invalid option. Try again." << endl;
            cout << endl << "What will you do? ";
            cin >> choice;
        }

        int dir;
        if      ( choice == 'n' ) { dir = 0; }  // north
        else if ( choice == 's' ) { dir = 1; }  // south
        else if ( choice == 'e' ) { dir = 2; }  // east
        else if ( choice == 'w' ) { dir = 3; }  // west

        int neighborIndex = rooms[ currentRoom ].GetNeighbor( Direction( dir ) );
        if ( neighborIndex != -1 )
        {
            currentRoom = neighborIndex;
        }
    }
}

/*
    0   1
2   3   4   5
    6   7
*/

void LoadCoreRooms( Room rooms[25] )
{
    // Create Rooms
    rooms[0].Setup( "Forest West",      "This part of the forest is dense and dark." );
    rooms[1].Setup( "Forest East",      "Flecks of light spot the ground, which is mostly shaded by the leaves of the trees." );
    rooms[2].Setup( "Cave Entrance",    "A large, foreboding cave opens up ahead of you." );
    rooms[3].Setup( "Grassy Clearing",  "There are small animals foraging around in this grassland." );
    rooms[4].Setup( "Pond",             "A small pond sits here." );
    rooms[5].Setup( "Cottage",          "An old cottage sits next to the pond." );
    rooms[6].Setup( "Dirt Road",        "A dirt road begins at this point and stretches toward town." );
    rooms[7].Setup( "Old Well",         "The old well has seen better days." );

    // Set neighbors (does forward and backward)
    SetNeighbors( rooms, 0, 1, EAST );
    SetNeighbors( rooms, 0, 3, SOUTH );
    SetNeighbors( rooms, 1, 4, SOUTH );
    SetNeighbors( rooms, 3, 6, SOUTH );
    SetNeighbors( rooms, 4, 7, SOUTH );
    SetNeighbors( rooms, 2, 3, EAST );
    SetNeighbors( rooms, 4, 5, EAST );
    SetNeighbors( rooms, 3, 4, EAST );
}

void LoadStudentRooms( Room rooms[25] )
{
    // 1 Room 8, NORTH of Room 0

    // 2 Room 9, NORTH of Room 1

    // 3 Room 10, WEST of Room 2

    // 4 Room 11, EAST of Room 5

    // 5 Room 12, SOUTH of Room 6

    // 6 Room 13, SOUTH of Room 7

    // 7 Room 15, WEST of Room 0

    // 8 Room 16, EAST of Room 1

    // 9 Room 17, NORTH of Room 2

    // 10 Room 18, NORTH of Room 5

    // 11 Room 19, SOUTH of Room 2

    // 12 Room 20, SOUTH of Room 5

    // 13 Room 21, WEST of Room 6

    // 14 Room 22, EAST of Room 7
}

void SetNeighbors( Room rooms[18], int room, int neighbor, Direction dir )
{
    Direction opp;
    if ( dir == NORTH ) { opp = SOUTH; }
    else if ( dir == SOUTH ) { opp = NORTH; }
    else if ( dir == WEST ) { opp = EAST; }
    else if ( dir == EAST ) { opp = WEST; }

    rooms[room].SetNeighbor( dir, neighbor );
    rooms[neighbor].SetNeighbor( opp, room );
}

// =^o.o^=

