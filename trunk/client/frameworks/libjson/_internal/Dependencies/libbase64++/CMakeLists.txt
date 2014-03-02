set(classes 
	libbase64++.h
)
set_source_files_properties(${classes} PROPERTIES LANGUAGE CXX)
add_library(libbase64 ${classes})
set_target_properties(Source PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})