cmake_minimum_required(VERSION 3.16)
project(c_cord C)

# find depends
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)
#find_package(CURL QUIET COMPONENTS libcurl CONFIG)
find_package(jansson CONFIG REQUIRED)
find_package(Libwebsockets CONFIG REQUIRED)
add_subdirectory(thirdparty/curl)

# link lib
file(GLOB_RECURSE source_list src/*.c)
add_library(c_cord STATIC ${source_list})
target_include_directories(c_cord PUBLIC include PRIVATE include/c_cord)

# link depends
target_link_libraries(c_cord PRIVATE CURL::libcurl)
target_link_libraries(c_cord PRIVATE jansson::jansson)
target_link_libraries(c_cord PRIVATE websockets_shared)

set(CMAKE_C_STANDARD 11)
