set(classes 
	libjson.h
	JSONOptions.h
)
set_source_files_properties(${classes} PROPERTIES LANGUAGE CXX)
add_library(Source ${classes})
set_target_properties(Source PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

add_subdirectory(JSONDefs)