cmake_minimum_required( VERSION 3.3 )
project( refid )

set( REFID_SOURCES
        main.cpp
)

set( REFID_HEADERS
)


add_executable( refid ${REFID_SOURCES} ${REFID_HEADERS} )


target_link_libraries( refid )
