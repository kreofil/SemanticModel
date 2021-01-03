//#include <iostream>
//#include <fstream>
//#include <sstream>

//using namespace std;

//#include "module.h"
//#include "creator.h"

#include "tests.h"

int main()
{
    /*
    //std::ifstream instream("in.txt");
    if(instream.fail()) {
        std::cout << "File did not open" << std::endl;
        return 1;
    }
    std::stringstream ss;
    ss << instream.rdbuf();
    std::string str(ss.str());
    //std::cout << str << std::endl;

    //InitParser(str.c_str());
   // StartParser();
*/
    ///testBaseScalarVar();
    testInstructions();
    ///testModule();

    return 0;
}
