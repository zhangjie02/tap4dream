set(classes 
	internalJSONNode.cpp
	internalJSONNode.h
	JSONAllocator.cpp
	JSONAllocator.h
	JSONChildren.cpp
	JSONChildren.h
	JSONDebug.cpp
	JSONDebug.h
	JSONDefs.h
	JSONGlobals.h
	JSONIterators.cpp
	JSONMemory.cpp
	JSONMemory.h
	JSONMemoryPool.h
	JSONNode.cpp
	JSONNode.h
	JSONNode_Mutex.cpp
	JSONPreparse.cpp
	JSONPreparse.h
	JSONSharedString.h
	JSONSingleton.h
	JSONStats.h
	JSONStream.cpp
	JSONStream.h
	JSONValidator.cpp
	JSONValidator.h
	JSONWorker.cpp
	JSONWorker.h
	JSONWriter.cpp
	JSON_Base64.h
	libjson.cpp
	NumberToString.h
)
add_library(Source ${classes})
set_target_properties(Source PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})

add_subdirectory(JSONDefs)