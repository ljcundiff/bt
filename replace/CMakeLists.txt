cmake_minimum_required( VERSION 3.3 )
project( replace )

set( REPLACE_SOURCES
        main.cpp
)

set( REPLACE_HEADERS
)


add_executable( replace ${REPLACE_SOURCES} ${REPLACE_HEADERS} )


target_link_libraries( replace )