project(utilities)
set(UTILITIES ${PROJECT_NAME} CACHE INTERNAL "UTILITIES")

set(UTIL_PRIVATE
    # LOGGER
    ${CMAKE_CURRENT_SOURCE_DIR}/logger/private/logger_service.cpp
)
set(UTIL_PUBLIC
    # PLATFORM
    ${CMAKE_CURRENT_SOURCE_DIR}/platform/public/platform.h

    # LOGGER
    ${CMAKE_CURRENT_SOURCE_DIR}/logger/public/logger_helpers.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/logger/public/logger_service.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/logger/public/asio_logger.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/logger/public/logger.hpp
)
set(UTIL_COLLECTIVE
    ${UTIL_PRIVATE}
    ${UTIL_PUBLIC}
)

add_library(${UTILITIES} SHARED
    ${UTIL_COLLECTIVE}
) 

add_source_group(${UTIL_COLLECTIVE})

generate_export_header(${UTILITIES})

# Defines the headers for this library,
# and will be added to build paths.
target_include_directories(${UTILITIES} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/logger/public>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/platform/public>
    $<INSTALL_INTERFACE:public>
    PRIVATE src)

# "make install" to the correct locations (GNUInstallDirs).
install(TARGETS ${UTILITIES} EXPORT ${PROJECT_NAME}LibraryConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows.
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Importable from the install directory.
# Config file per-project dir or into "cmake".
install(EXPORT ${PROJECT_NAME}LibraryConfig DESTINATION share/${PROJECT_NAME}Library/cmake)

# Importable from build directory.
export(TARGETS ${UTILITIES} FILE ${PROJECT_NAME}LibraryConfig.cmake)
