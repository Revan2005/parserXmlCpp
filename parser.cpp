#include "pugixml.hpp"
#include <iostream>

int main(int argc, char const *argv[]) {
  /* code */
  pugi::xml_document doc;

  pugi::xml_parse_result result = doc.load_file("00103610.xml");

  std::cout << "Load result: " << result.description() << ", mesh name: " <<
      doc.child("mesh").attribute("name").value() << std::endl;
  return 0;
}
