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

namespace example1
{

namespace details
{
namespace unicode = boost::spirit::unicode;
namespace qi = boost::spirit::qi;
namespace repo = boost::spirit::repository;
namespace phx = boost::phoenix;


inline void append( std::vector<double> & vec, const std::string & x )
{ vec.push_back( boost::lexical_cast<double>( x ) ); }

/**
 *@brief construct a grammar for parsing expressions
 */
template <typename Iterator>
struct Grammar : qi::grammar<Iterator, std::string()>
{
    Grammar()
    : Grammar::base_type(entry)
    {
        using qi::lit;
        using qi::_val;
        using qi::_1;
        using qi::_2;
        using qi::_a;
        using qi::_b;
        using qi::lexeme;
        using qi::no_skip;
        using qi::space;
        using qi::omit;
        using qi::int_;
        using unicode::char_;
        using qi::double_;
        using phx::bind;

        // An unquoted string 
        num = (+char_);
        // a product is something of this kind: a * b
        product = ( num[_a = _1] >> lit('*') >> num[_b = _1] )/*[_val = _a * _b]*/;
        // a division is something of this kind: a / b
        division = ( num[_a = _1] >> lit('/') >> num[_b = _1] )/*[_val = _a / _b]*/;
        // an expression is something of this kind: a + b * b - c
        expression = ( product | division );

        entry = *( expression/*[ phx::bind( &append, _val, _1 ) ]*/ );
    }

    qi::rule<Iterator, std::string()> entry;
    qi::rule<Iterator, std::string()> expression;
    qi::rule<Iterator, std::string(), qi::locals<std::string, std::string> > division;
    qi::rule<Iterator, std::string(), qi::locals<std::string, std::string> > product;
    qi::rule<Iterator, std::string()> num;
};
}

std::vector<double> parse( const std::string & input );

}

#endif
