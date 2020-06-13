cmake_minimum_required(VERSION 3.16)
project(discord_c C)

# find depends
find_package(OpenSSL REQUIRED)
find_package(ZLIB REQUIRED)
find_package(CURL QUIET COMPONENTS libcurl CONFIG)

# link lib
file(GLOB_RECURSE source_list src/*.c)
add_library(discord_c STATIC ${source_list})
target_include_directories(discord_c PUBLIC include PRIVATE include/discord_c)

# link depends
target_link_libraries(discord_c PRIVATE CURL::libcurl)

set(CMAKE_C_STANDARD 11)
