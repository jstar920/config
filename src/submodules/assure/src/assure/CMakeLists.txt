file (GLOB ASSURE_HEADERS "*.h")
file (GLOB ASSURE_SOURCES "*.cpp")

message(STATUS "header files:" ${ASSURE_HEADERS})
message(STATUS "source files:" ${ASSURE_SOURCES})

source_group("headers" FILES ${ASSURE_HEADERS})
source_group("sources" FILES ${ASSURE_SOURCES})

include_directories (.)

add_library(assure SHARED ${ASSURE_HEADERS} ${ASSURE_SOURCES})
add_library(assure_static STATIC ${ASSURE_HEADERS} ${ASSURE_SOURCES})

set_property(TARGET assure PROPERTY FOLDER ${PRJECT_LIBRARIES_DIR})
set_property(TARGET assure_static PROPERTY FOLDER ${PRJECT_LIBRARIES_DIR})
target_include_directories(assure_static PUBLIC ".")

#set_target_properties(assure PROPERTIES RUNTIME_OUTPUT_DIRECTORY %{PROJECT_BINARY_DIR}/bin)

install (TARGETS assure
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install
         LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/_install
)
