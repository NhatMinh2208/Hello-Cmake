cmake_minimum_required(VERSION "3.16.3")

project("HelloWorld")


set(CMAKE_BINARY_DIR, "${CMAKE_CURRENT_SOURCE_DIR}/../build2")

add_executable(
    "${PROJECT_NAME}" src/main.cpp   #the second+ para is the src code require for build the exe
)

add_subdirectory(src/Adder)  #build libary, you see this cmake file is lay on the roof of cmake tree
        #there are like a subfolder and inside that also have a cmake file
#target_include_directories(${PROJECT_NAME} PUBLIC Adder)
target_link_libraries(${PROJECT_NAME} add1) #link the lib to the exe
#install(TARGETS  "${PROJECT_NAME}" DESTINATION bin) #DESTINATION is relative to ${CMAKE_INSTALL_PREFIX}/bin
                                                    #${CMAKE_INSTALL_PREFIX} is ProgramFilesx86 in WINDOW and usr/local in linux
                                                    #build project INSTALL on the .sln file, you will see
#install(FILES "main.cpp" DESTINATION src)        

#include(CTest)  #insert 5 more test project in sln file.

#add_test("test1" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}") #build RUN_TESTS, if return 0 mean test pass
                    #para1 is the name of test, para2 is the exe you want test run on
 #CMAKE_CURRENT_BINARY_DIR is the path to the binary directory currently being processed, denote that maybe there are more than 1 bin dir
#include(CPack)  #add vsxproj PACKAGE to sln file, build it to build the package HelloWorld
            #CPack depend on INSTALL code, which just gerenate a location, put stuff in there and compress



