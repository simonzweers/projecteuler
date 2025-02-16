file(GLOB CPP_SRC *.cpp)

foreach(CPP_FILE ${CPP_SRC})
    strip_filename(${CPP_FILE} CPP_EXE)
    message(STATUS "CPP_EXE: ${CPP_EXE}")
    add_executable(${CPP_EXE} ${CPP_FILE})
endforeach()


