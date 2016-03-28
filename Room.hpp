// ADVENTURE

#ifndef _ROOM
#define _ROOM

#include <string>
using namespace std;

enum Direction { NORTH, SOUTH, EAST, WEST };

class Room
{
    public:
    Room();
    void Setup( const string& name, const string& description );
    void SetNeighbor( Direction dir, int index );
    int GetNeighbor( Direction dir );
    string GetName();
    void Display();

    private:
    string m_name;
    string m_description;
    int m_neighborRooms[4]; // index of room, direction
};

#endif
