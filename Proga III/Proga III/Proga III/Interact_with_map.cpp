#include "Proga lll.hpp"
#include <utility> //make_pair

void insert_to_Mmp
(
	Mmp_tran& MAP,
	CStoping stop,
	CTransport transport
)
{
	transport.route.push_back(stop);
	MAP.emplace(make_pair(transport.number, transport));

}




void replace_in_Mmp
(
	Mmp_tran& MAP,
	Mmp_tran::iterator SearchTransportIterator,
	CStoping stop,
	CTransport transport
)
{
	transport.route = SearchTransportIterator->second.route;
	transport.route.push_back(stop);
	MAP.erase(SearchTransportIterator);
	MAP.emplace(make_pair(transport.number, transport));
}
