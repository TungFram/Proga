#include "Proga lll.hpp"
#include <utility> //make_pair

struct Dungeon Parsing_xml(const pugi::xml_document& Document, struct Dungeon master)
{

    pugi::xml_node Stopings = Document.child(L"dataset");
    for (pugi::xml_node this_stop = Stopings.child(L"transport_station"); this_stop; this_stop = this_stop.next_sibling(L"transport_station"))
    {
        std::vector <std::wstring> numbers;
        std::wstring xml_route = this_stop.child(L"routes").child_value();
        std::wstring help_string;
        

        CStoping help_stop;
        help_stop.coordinates = S_in_pd(this_stop.child(L"coordinates").child_value());
        std::vector <std::wstring> location = S_in_vs(this_stop.child(L"location").child_value(), L'l');

        for (unsigned int i = 0; i < location.size(); ++i)
        {
            auto that_stop_on_Mp = master.Map_of_streets.find(location[i]);
            if (that_stop_on_Mp != master.Map_of_streets.end()) //если такая улица уже есть
            {
                for (int k = 0; k < that_stop_on_Mp->second.size(); ++k)
                {
                    if (help_stop.coordinates == that_stop_on_Mp->second.at(k).coordinates)//если эта остановка уже есть
                        throw std::exception("Unknown ERROR! [same coordinates]");
                    //надо удалять элементы, а потом создавать новые
                }
                auto help_insert = that_stop_on_Mp->second; //добавить в вектор остановок эту
                help_insert.push_back(help_stop);
                master.Map_of_streets.erase(location[i]);
                master.Map_of_streets.emplace(make_pair(location[i], help_insert));
            }
            else //если этой улицы еще нет
            {
                std::vector<CStoping> help_vector;
                help_vector.push_back(help_stop);
                master.Map_of_streets.emplace(make_pair(location[i], help_vector));
            }
        }


        numbers = S_in_vs(xml_route, L'n');
        for (unsigned int i = 0; i < numbers.size(); ++i) //для каждого транспорта-маршрута
        {
            CTransport this_transport;
            this_transport.number = numbers[i];
            this_transport.type = this_stop.child(L"type_of_vehicle").child_value();

            auto that_number_on_Mmp = master.Multimap_of_transport.find(numbers[i]);
            if (that_number_on_Mmp != master.Multimap_of_transport.end()) //если элемент c таким жe номером уже есть
            {
                if (that_number_on_Mmp->second.type == this_transport.type) //и они одного типа, то есть это тот же самый
                {
                    /*this_transport.route = that_number_on_Mmp->second.route;
                    this_transport.route.push_back(help_stop);
                    master.Multimap_of_transport.erase(that_number_on_Mmp);
                    master.Multimap_of_transport.emplace(make_pair(this_transport.number, this_transport));*/
                    replace_in_Mmp(master.Multimap_of_transport, that_number_on_Mmp, help_stop, this_transport);
                }
                else //но у них разные типы, то есть другой вид транспорта с тем же номером
                {
                    /*this_transport.route.push_back(help_stop);
                    master.Multimap_of_transport.emplace(make_pair(this_transport.number, this_transport));*/
                    insert_to_Mmp(master.Multimap_of_transport, help_stop, this_transport);
                }
            }
            else //если такого еще нет, - создаем новый
            {
                /*this_transport.route.push_back(help_stop);
                master.Multimap_of_transport.emplace(make_pair(this_transport.number, this_transport));*/
                insert_to_Mmp(master.Multimap_of_transport, help_stop, this_transport);
            }

        }

    }


    
    return master;
}