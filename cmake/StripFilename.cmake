
function(strip_filename ABSOLUTE_PATH OUTPUT_VAR)
    get_FILENAME_component(FILENAME ${ABSOLUTE_PATH} NAME)
    string(REGEX REPLACE "\.cpp$" "" STRIPPED ${FILENAME})
    set(${OUTPUT_VAR} ${STRIPPED} PARENT_SCOPE)
endfunction()