set(classes 
	mempool.h
)
set_source_files_properties(${classes} PROPERTIES LANGUAGE CXX)
add_library(mempool ${classes})
set_target_properties(Source PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})