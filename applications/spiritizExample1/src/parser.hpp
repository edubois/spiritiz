#ifndef _SPIRITIZ_EXAMPLE1_PARSER_HPP_
#define	_SPIRITIZ_EXAMPLE1_PARSER_HPP_

#include <boost/function.hpp>
#include <boost/bind.hpp>

#define BOOST_SPIRIT_UNICODE // We'll use unicode (UTF8) all throughout
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/spirit/repository/include/qi_subrule.hpp>
#include <boost/lexical_cast.hpp>

#include <vector>
#include <string>
#include <cassert>

namespace example1
{

namespace details
{
namespace unicode = boost::spirit::unicode;
namespace qi = boost::spirit::qi;
namespace phx = boost::phoenix;

inline double operation( double & x, const double y, const char op )
{
    switch( op )
    {
        case '*':
            return x *= y;
        case '/':
            return x /= y;
        case '+':
            return x += y;
        case '-':
            return x -= y;
        default:
            assert( 0 && "Invalid operation!" );
            return 0.0;
    }
}

/**
 *@brief construct a grammar for parsing expressions
 */
template <typename Iterator>
struct Grammar : qi::grammar<Iterator, std::vector<double>()>
{
    Grammar()
    : Grammar::base_type(entry)
    {
        using qi::lit;
        using qi::_val;
        using qi::_1;
        using qi::_a;
        using qi::_b;
        using unicode::char_;
        using qi::double_;
        using phx::bind;
        using phx::push_back;

        // An double value
        num = double_;
        factor = qi::skip(qi::blank)[ ( num[_val = _1] >> +( ( char_('*') | char_('/') )[_a = _1] >> num[_b = _1] )[phx::bind( &operation, _val, _b, _a )] ) ];
        expression = qi::skip(qi::blank)[ ( (factor|num)[_val = _1] >> *( ( char_('+') | char_('-') )[_a = _1] >> (factor|num)[_b = _1] )[phx::bind(&operation, _val, _b, _a )] ) ];
        entry = +( expression[ phx::push_back( _val, _1 ) ] >> *qi::eol );
    }

    // Create a starting rule with _val as a vector<double>
    qi::rule<Iterator, std::vector<double>()> entry;
    qi::rule<Iterator, double(), qi::locals<char, double> > expression;
    qi::rule<Iterator, double(), qi::locals<char, double> > factor;
    qi::rule<Iterator, double()> num;
};
}

std::vector<double> parse( const std::string & input );

}

#endif
