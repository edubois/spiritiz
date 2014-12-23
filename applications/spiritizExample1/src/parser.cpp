#include "parser.hpp"

namespace example1
{

std::vector<double> parse( const std::string & input )
{
    using namespace boost::spirit;

    std::vector<double> vec;
    typedef std::string::const_iterator iterator_t;
    details::Grammar<iterator_t> g;
    iterator_t itBegin = input.begin();
    iterator_t itEnd = input.end();
    std::string v;
    phrase_parse( itBegin, itEnd, g, +qi::space, vec );
    return vec;
}

}
