
file (GLOB CONFIGURE_COMMON_HEADERS "*.h")
file (GLOB CONFIGURE_COMMON_SOURCES "*.cpp")

message(STATUS "header files:" ${CONFIGURE_COMMON_HEADERS})
message(STATUS "source files:" ${CONFIGURE_COMMON_SOURCES})

source_group("headers" FILES ${CONFIGURE_COMMON_HEADERS})
source_group("sources" FILES ${CONFIGURE_COMMON_SOURCES})

include_directories (.)

add_library(configure_common SHARED ${CONFIGURE_COMMON_HEADERS} ${CONFIGURE_COMMON_SOURCES})
add_library(configure_common_static STATIC ${CONFIGURE_COMMON_HEADERS} ${CONFIGURE_COMMON_SOURCES})

set_property(TARGET configure_common PROPERTY FOLDER ${PRJECT_LIBRARIES_DIR})
set_property(TARGET configure_common_static PROPERTY FOLDER ${PRJECT_LIBRARIES_DIR})
target_include_directories(configure_common_static PUBLIC ".")
target_link_libraries(configure_common_static PUBLIC timeutils_static)
target_link_libraries(configure_common PUBLIC timeutils_static)

install (TARGETS configure_common
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install
         LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/_install
)

