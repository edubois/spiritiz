#include "parser.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    if ( argc <= 1 )
    {
        // This example needs a m3u file
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        std::cerr << "Example: " << argv[0] << " dummyPlaylist.m3u" << std::endl;
        return -1;
    }

    std::vector<m3uParser::PlaylistItem> playlist = m3uParser::parse( argv[1] );
    std::cout << "Playlist items: " << std::endl;
    for( const m3uParser::PlaylistItem & item: playlist )
    {
        std::cout << "---" << std::endl;
        std::cout << "Filename: " << item.filename << std::endl;
        std::cout << "Duration: " << item.duration << std::endl;
        std::cout << "Infos: " << item.infos << std::endl;
    }
}
