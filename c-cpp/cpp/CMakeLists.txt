file(GLOB CPP_SRC *.cpp)

foreach(CPP_FILE ${CPP_SRC})
    strip_filename(${CPP_FILE} ".cpp" CPP_ROOT)
    set(CPP_EXE cpp_${CPP_ROOT})
    message(STATUS "CPP_EXE: ${CPP_EXE}")
    add_executable(${CPP_EXE} ${CPP_FILE})
endforeach()

target_link_libraries(cpp_099 PRIVATE ctrack)

