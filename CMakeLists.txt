cmake_minimum_required(VERSION 3.10)

project(University-database) 

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(FILES Student.cpp UniversityDb.cpp myTests.cpp)
set(FLAGS PRIVATE -Wall -Wextra  -pedantic -Wconversion -Werror -O0) #-Werror

add_library(${PROJECT_NAME}-lib STATIC ${FILES})
target_compile_options(${PROJECT_NAME}-lib ${FLAGS})
set_target_properties(${PROJECT_NAME}-lib PROPERTIES
                        CXX_STANDARD 17
                        CXX_STANDARD_REQUIRED ON)


add_executable(${PROJECT_NAME} main.cpp)
target_compile_options(${PROJECT_NAME} ${FLAGS})
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-lib)
set_target_properties(${PROJECT_NAME} PROPERTIES
                      CXX_STANDARD 17
                      CXX_STANDARD_REQUIRED ON)


# add_executable(${PROJECT_NAME}-ut myTests.cpp)
# target_compile_options(${PROJECT_NAME}-ut ${FLAGS})
# target_link_libraries(${PROJECT_NAME}-ut ${PROJECT_NAME}-lib)
# set_target_properties(${PROJECT_NAME}-ut PROPERTIES
#                         CXX_STANDARD 17
#                         CXX_STANDARD_REQUIRED ON)

# enable_testing()
# add_test(NAME myTests COMMAND ${PROJECT_NAME}-ut)


