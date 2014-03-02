set(classes 
	GNU_C.h
	Strings_Defs.h
	Unknown_C.h
	Visual_C.h
)
set_source_files_properties(${classes} PROPERTIES LANGUAGE CXX)
add_library(JSONDefs ${classes})
set_target_properties(JSONDefs PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})