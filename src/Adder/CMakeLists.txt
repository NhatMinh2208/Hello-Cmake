add_library(adder add.cpp add.h)  

install(TARGETS adder DESTINATION lib)
#install library libadder.a in usr/local/bin (for linux)
install(FILES add.h DESTINATION include)
#install file add.h in usr/local/include (for linux)