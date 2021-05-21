#include "Proga lll.hpp"



int main()
{
    pugi::xml_document Document;
    pugi::xml_parse_result Parse_result = Document.load_file("Data.xml");

    if (Parse_result)
        std::wcout << "XML [" << "Data.xml" << "] parsed without errors" << std::endl << std::endl;
    else
    {
        std::wcout << "XML [" << "Data.xml" << "] parsed with errors\n";
        std::wcout << "Error description: " << Parse_result.description() << "\n";
        std::wcout << "Error offset: " << Parse_result.offset << std::endl << std::endl;
    }
    
    //we have only троллейбус, трамвай и автобус

    Dungeon master = Parsing_xml(Document, master);
    Work_with_data(master);
    
    return 0;
}

