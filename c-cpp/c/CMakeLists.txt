file(GLOB C_SRC *.c)

foreach(C_FILE ${C_SRC})
    strip_filename(${C_FILE} ".c" C_ROOT)
    set(C_EXE c_${C_ROOT})
    message(STATUS "C_EXE: ${C_EXE}")
    add_executable(${C_EXE} ${C_FILE})
endforeach()