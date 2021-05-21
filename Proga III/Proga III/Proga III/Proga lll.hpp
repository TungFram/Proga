#ifndef DEBUG
#define DEBUG


#include <iostream>
#include <vector>
#include <map>
#include "pugixml.cpp" 
//#include <algorithm> //count
//#include <cstdlib> //strtod

class CStoping
{
private:

public:
    std::pair <double, double> coordinates;
};

class CTransport
{
private:

public:
    std::wstring number;
    std::wstring type;
    std::vector <CStoping> route;
};

typedef std::map <std::wstring, std::vector <CStoping>> Mp_streets;
typedef std::multimap <std::wstring, CTransport> Mmp_tran;

struct Dungeon
{
    Mmp_tran Multimap_of_transport;
    Mp_streets Map_of_streets;
};

struct Dungeon Parsing_xml(const pugi::xml_document&, struct Dungeon master);

void Work_with_data(Dungeon master);

std::vector <std::wstring> S_in_vs(std::wstring, wchar_t);
std::pair <double, double> S_in_pd(std::wstring);

void insert_to_Mmp
(
    Mmp_tran&,
    CStoping,
    CTransport
);

void replace_in_Mmp
(
    Mmp_tran&,
	Mmp_tran::iterator,
	CStoping,
	CTransport
);


void Work_with_data(Dungeon master);

std::wstring longest_route(const Mmp_tran&);
std::pair<std::wstring, long double> longest_route_coordinates(const Mmp_tran&);
std::pair<std::wstring, unsigned int> the_biggest_street(const Mp_streets&);


#endif