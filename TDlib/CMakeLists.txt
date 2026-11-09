
cmake_minimum_required(VERSION 3.24)

project(TelegramClient LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

set(TD_ENABLE_JNI OFF CACHE BOOL "" FORCE)
set(TD_ENABLE_DOTNET OFF CACHE BOOL "" FORCE)
set(TD_ENABLE_TDWEB OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
        tdlib
        GIT_REPOSITORY https://github.com/tdlib/td.git
        GIT_TAG master
        GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(tdlib)

add_executable(${PROJECT_NAME}
        src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
        PRIVATE Td::TdStatic
)
