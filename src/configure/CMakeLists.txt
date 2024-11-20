
file (GLOB CONFIGURE_HEADERS "*.h")
file (GLOB CONFIGURE_SOURCES "*.cpp")

message(STATUS "header files:" ${CONFIGURE_HEADERS})
message(STATUS "source files:" ${CONFIGURE_SOURCES})

source_group("headers" FILES ${CONFIGURE_HEADERS})
source_group("sources" FILES ${CONFIGURE_SOURCES})

include_directories (.)

add_library(configure SHARED ${CONFIGURE_HEADERS} ${CONFIGURE_SOURCES})
add_library(configure_static STATIC ${CONFIGURE_HEADERS} ${CONFIGURE_SOURCES})

set_property(TARGET configure PROPERTY FOLDER ${PRJECT_LIBRARIES_DIR})
set_property(TARGET configure_static PROPERTY FOLDER ${PRJECT_LIBRARIES_DIR})
target_include_directories(configure_static PUBLIC ".")
target_link_libraries(configure_static PUBLIC configure_common_static platform_static)
target_link_libraries(configure PUBLIC configure_common_static platform_static)

install (TARGETS configure
         RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/_install
         LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/_install
)

