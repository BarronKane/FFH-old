## This may become a library at some point.
## For now, this will act as a listen server to act on the factorio process.
project(frame-host-api)
set(FFH_API ${PROJECT_NAME} CACHE INTERNAL "FFH_API")

set(FFHA_PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/private/frame-host-api.cpp
)
set(FFHA_PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/public/frame-host-api.hpp
)

set(FFHA_COLLECTIVE
    ${FFHA_PRIVATE}
    ${FFHA_PUBLIC}
)

add_library(${FFH_API} SHARED
    ${FFHA_COLLECTIVE}
)

add_source_group(${FFHA_COLLECTIVE})


generate_export_header(${FFH_API})

# Defines the headers for this library,
# and will be added to build paths.
target_include_directories(${FFH_API} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/logger/public>
    $<INSTALL_INTERFACE:public>
    PRIVATE src)

# "make install" to the correct locations (GNUInstallDirs).
install(TARGETS ${FFH_API} EXPORT ${PROJECT_NAME}LibraryConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows.
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Importable from the install directory.
# Config file per-project dir or into "cmake".
install(EXPORT ${PROJECT_NAME}LibraryConfig DESTINATION share/${PROJECT_NAME}Library/cmake)

# Importable from build directory.
export(TARGETS ${FFH_API} FILE ${PROJECT_NAME}LibraryConfig.cmake)

target_link_libraries(${PROJECT_NAME}
    ${FACTORIO_FRAME_HOST}
    ${UTILITIES}
)
