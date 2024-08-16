#include <iostream>
#include <string>
#include <sstream>
#include <string>

/*
 * From stack overflow question:
 * https://stackoverflow.com/questions/12975341/to-string-is-not-a-member-of-std-says-g-mingw
 *
 * Included here to allow students to more easily convert numbers to strings.
 *
 * Usage:
 *
 * patch::to_string(<value to convert>)
*/

namespace patch
{
    template < typename T >
    std::string to_string(const T& n)
    {
        std::ostringstream stm;
        stm << n;
        return stm.str();
    }
}