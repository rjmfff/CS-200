// ADVENTURE

#include "Room.hpp"

#include <iostream>
using namespace std;

Room::Room()
{
    for ( int i = 0; i < 4; i++ )
    {
        m_neighborRooms[i] = -1;
    }
}

void Room::Setup( const string& name, const string& description )
{
    m_name = name;
    m_description = description;
}

void Room::SetNeighbor( Direction dir, int index )
{
    m_neighborRooms[ dir ] = index;
}

int Room::GetNeighbor( Direction dir )
{
    return m_neighborRooms[ dir ];
}

void Room::Display()
{
    cout << m_name << endl << m_description << endl;
}

string Room::GetName()
{
    return m_name;
}
