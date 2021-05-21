#include "Proga lll.hpp"
#include <cmath>
#include <utility> //make_pair

void Work_with_data(Dungeon master)
{
	std::wcout << L"The longest route is: " << longest_route(master.Multimap_of_transport) << std::endl;
	std::pair<std::wstring, long double> result_coordinates = longest_route_coordinates(master.Multimap_of_transport);
	std::wcout << L"The longest route with coordinates is: " << result_coordinates.first << L", lenght = " << result_coordinates.second << std::endl;
	std::pair<std::wstring, unsigned int> result_quantity = the_biggest_street(master.Map_of_streets);
	std::wcout << L"Street with the biggest quantity of stopings is: " << result_quantity.first << L", quantity = " << result_quantity.second << std::endl;
}

std::wstring longest_route(const Mmp_tran& MMP)
{
	unsigned int Max_quantityOf_stopings = 0;
	std::wstring result_route;
	for (auto MMP_element : MMP)
	{
		if (MMP_element.second.route.size() > Max_quantityOf_stopings)
		{
			Max_quantityOf_stopings = MMP_element.second.route.size();
			result_route = MMP_element.first;
		}
	}
	return result_route;
}

std::pair<std::wstring, long double> longest_route_coordinates(const Mmp_tran& MMP)
{ //была идея использовать Алгоритм Флойда — Уоршелла для нахождения кратчайших путей между всеми остановками до всех, но это бесполезно
	std::pair<std::wstring, long double> result;
	
	for (auto MMP_element : MMP)
	{
		long double Lenght = 0;
		for (unsigned int i = 0; i < MMP_element.second.route.size() - 1; ++i)
		{
			Lenght += sqrt(
				((MMP_element.second.route[i + 1].coordinates.first - MMP_element.second.route[i].coordinates.first) *
					(MMP_element.second.route[i + 1].coordinates.first - MMP_element.second.route[i].coordinates.first))
				+
				((MMP_element.second.route[i + 1].coordinates.second - MMP_element.second.route[i].coordinates.second) *
					(MMP_element.second.route[i + 1].coordinates.second - MMP_element.second.route[i].coordinates.second))
			);
		}
		if (Lenght > result.second)
		{
			result = std::make_pair(MMP_element.first, Lenght);
		}
	}
	return result;
}

std::pair<std::wstring, unsigned int>
	the_biggest_street(const Mp_streets& MAP)
{
	unsigned int Max_quantityOf_stopings = 0;
	std::pair<std::wstring, unsigned int> answer;
	for (auto Street : MAP)
	{
		if (Street.second.size() > Max_quantityOf_stopings)
		{
			answer = std::make_pair(Street.first, Street.second.size());
		}
	}
	return answer;
}