#include "pugixml.hpp"

#include <string.h>
#include <iostream>

int main()
{
    pugi::xml_document doc;
    if (!doc.load_file("tekst.xml")) return -1;

    //pugi::xml_node tools = doc.child("chunkList").child("chunk");

    // tag::basic[]
    for (pugi::xml_node chunkList = doc.first_child(); chunkList; chunkList = chunkList.next_sibling())
      for (pugi::xml_node chunk = chunkList.first_child(); chunk; chunk = chunk.next_sibling())
        for (pugi::xml_node sentence = chunk.first_child(); sentence; sentence = sentence.next_sibling())
          for (pugi::xml_node tok = sentence.first_child(); tok; tok = tok.next_sibling())
            for(pugi::xml_node lex = tok.first_child(); lex; lex = lex.next_sibling())
            {
                //std::cout << tok.first_child().name() << " " << tok.first_child().text().get();
                for (pugi::xml_attribute attr = lex.first_attribute(); attr; attr = attr.next_attribute())
                {
                  //std::cout << *(attr.value()) << std::endl;
                //  if(attr.name() == "disamb")
                  std::string napis = "disamb";
                  std::string nazwa = attr.name();
                  if(napis == nazwa)
                    for(pugi::xml_node element = lex.first_child(); element; element = element.next_sibling())
                      std::cout << element.text().get() << " ";
                      //std::cout << " " << attr.name() << "=" << *attr.value() << " " << tok.text()
                    std::cout << std::endl;
                }

                //std::cout << std::endl;
            }
            // end::basic[]

    std::cout << std::endl;
/*
    // tag::data[]
    for (pugi::xml_node tool = tools.child("Tool"); tool; tool = tool.next_sibling("Tool"))
    {
        std::cout << "Tool " << tool.attribute("Filename").value();
        std::cout << ": AllowRemote " << tool.attribute("AllowRemote").as_bool();
        std::cout << ", Timeout " << tool.attribute("Timeout").as_int();
        std::cout << ", Description '" << tool.child_value("Description") << "'\n";
    }
    // end::data[]

    std::cout << std::endl;

    // tag::contents[]
    std::cout << "Tool for *.dae generation: " << tools.find_child_by_attribute("Tool", "OutputFileMasks", "*.dae").attribute("Filename").value() << "\n";

    for (pugi::xml_node tool = tools.child("Tool"); tool; tool = tool.next_sibling("Tool"))
    {
        std::cout << "Tool " << tool.attribute("Filename").value() << "\n";
    }
    // end::contents[]
*/
}

// vim:et
