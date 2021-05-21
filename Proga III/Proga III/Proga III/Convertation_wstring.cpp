#include "Proga lll.hpp"
#include <sstream> 


std::vector <std::wstring> S_in_vs(std::wstring String, wchar_t type)
{
    std::wstring div = L",";
    std::wstring div2 = L".";
    std::vector <std::wstring> result;
    size_t position = 0;
    std::wstring Sub_str;

    if (type == 'n')
    {
        while (((position = String.find(div)) != std::string::npos) || ((position = String.find(div2)) != std::string::npos))
        {
            Sub_str = String.substr(0, position);
            String.erase(0, position + div.length());
            result.push_back(Sub_str);
        }
        result.push_back(String);
        return result;
    }
    else if (type == 'l')
    {
        while ((position = String.find(div)) != std::string::npos)
        {
            Sub_str = String.substr(0, position);
            String.erase(0, position + div.length());
            result.push_back(Sub_str);
        }
        result.push_back(String);
        return result;
    }
    else
        throw std::exception("ERROR: s_in_vs, wrong type of string.");
}

std::pair <double, double> S_in_pd(std::wstring String)
{
    size_t position = String.find(',');
    String[position] = ' ';
    std::wstringstream ss;
    ss << String;
    std::pair <double, double> result;
    ss >> result.first >> result.second;
    return result;
}