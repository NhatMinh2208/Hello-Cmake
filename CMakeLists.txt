cmake_minimum_required(VERSION "3.16.3")

project("HelloWorld")


add_executable(
    "${PROJECT_NAME}" src/main.cpp   #the second+ para is the src code require for build the exe
)

configure_file(file_config.h.in configure.h) #Copies an <input> file to an <output> file  
            #and substitutes variable values referenced as @VAR@ or ${VAR} in the input file content.
option(USE_ADDER "A simple library for adding 2 floats." OFF) #IF we want to actually specified ON/OFF you
                    #must set the D flags on the command or in the cache, modify this file may make no difference


if(USE_ADDER)
    add_subdirectory(src/Adder)  #build libary, you see this cmake file is lay on the roof of cmake tree
        #there are like a subfolder and inside that also have a cmake file
    list(APPEND INCLUDE_DIRS "src/Adder")
    list(APPEND LINK_DIRS "src/Adder")
    list(APPEND LIBS adder)

endif()
add_subdirectory(thirdparty/glfw) 

find_library(myglewlib glew NAMES glew2 GLEW GLEW2 DOC "cache doc about glewlib") # para1 is just var name, you can name it as what you want
                        # param2 is the library name you want to find 
                        # NAMES specify one or more possible names for the library.
                        # HINTS, PATHS specify directories to search in addition to the default locations
                        # in version 3.21, NO_CACHE, the result of the search will be stored in a normal variable rather than a cache entry.
                        
if (${myglewlib} STREQUAL myglewlib-NOTFOUND)
    message("huhu can't find the glew library, try: sudo apt-get install libglew-dev")
else()
    message("found glew library! hureyyy")
endif()
#When it found the glew library, it will save it on the cache, so it you run the cmake file again with different configure, its always "found"
#use NO_CACHE in ver 3.21 but note that it can affect you time to find again and again a lib

#------------------------------------------------------------------------------------------
#DOWNLOAD ALL THE SUBMODULES
#find_package(Git QUIET) #The QUIET option disables messages if the package cannot be found
#if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
 #   option(GIT_SUBMODULE "Check submodules during build" ON)
 #   if(GIT_SUBMODULE)
  #      message(STATUS "Submodule update")
   #     execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
    #                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    #                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
     #   if(NOT GIT_SUBMOD_RESULT EQUAL "0")
    #        message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
    #    endif()
    #endif()
#endif()
 #CHECK THE SUBMODULES
#if(NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/repo/CMakeLists.txt")
    #message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
#endif()
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIRS} thirdparty/glfw/include)
target_link_directories(${PROJECT_NAME} PUBLIC ${LINK_DIRS} thirdparty/glfw/src)
#target_include_directories(${PROJECT_NAME} PUBLIC Adder)
target_link_libraries(${PROJECT_NAME} glfw ${LIBS} ${myglewlib}) #link the lib to the exe
#why glfw but not glfw3, in the thirdparty/glfw/src/CMakeLists.txt define target in add_librarry is glfw and we work with the target

install(TARGETS  "${PROJECT_NAME}" DESTINATION bin) #DESTINATION is relative to ${CMAKE_INSTALL_PREFIX}/bin
                                                    #${CMAKE_INSTALL_PREFIX} is ProgramFilesx86 in WINDOW and usr/local in linux
                                                    #build project INSTALL on the .sln file, you will see (Window)
                                                    #cmake install (for Linux)
#install HelloWorld.exe in C:/ProgramFilesx86/HelloWorld/bin for Win10 (or in user/local/bin  for Linux)

install(FILES "main.cpp" DESTINATION include)        
    

#include(CTest)  #insert 5 more test project in sln file.

#add_test("test1" "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}") #build RUN_TESTS, if return 0 mean test pass
                    #para1 is the name of test, para2 is the exe you want test run on
 #CMAKE_CURRENT_BINARY_DIR is the path to the binary directory currently being processed, denote that maybe there are more than 1 bin dir

#include(CPack)  #add vsxproj PACKAGE to sln file, build it to build the package HelloWorld
            #CPack depend on INSTALL code, which just gerenate a location, put stuff in there and compress
            #use CPACK when we want to give non-techinical user a simple installer, where there is a promp and they keep press "next" 
            #and then it install and they also have uninstall option



