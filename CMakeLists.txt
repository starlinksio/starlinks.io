cmake_minimum_required(VERSION 3.0)
project(SPACELINKS_IO_OFFICIAL_API VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



include_directories(
    /usr/local/include
    /usr/local/include/bsoncxx/v_noabi
    /usr/local/include/mongocxx/v_noabi
)

link_directories(
    /usr/local/lib
)


add_executable(api
    api.cpp
    starlinks-lib/Starlinks.cpp
    starlinks-lib/entities/Token.cpp
    starlinks-lib/entities/Link.cpp
    starlinks-lib/entities/Shortcut.cpp
    starlinks-lib/entities/Click.cpp
    starlinks-lib/entities/Domain.cpp
    starlinks-lib/network/Requests.cpp
    starlinks-lib/network/netToken.cpp
    starlinks-lib/network/netDomain.cpp
)

target_link_libraries(api
    curl
)