project(frame-host)
set(FACTORIO_FRAME_HOST ${PROJECT_NAME} CACHE INTERNAL "FACTORIO_FRAME_HOST")

set(FFH_PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/private/factorio-frame-host.cpp

    #SUBPROCESS
    ${CMAKE_CURRENT_SOURCE_DIR}/private/subprocess/factorio_process.cpp
)
set(FFH_PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/public/factorio-frame-host.h

    #SUBPROCESS
    ${CMAKE_CURRENT_SOURCE_DIR}/public/subprocess/factorio_process.h
)
set(FFH_COLLECTIVE
    ${FFH_PRIVATE}
    ${FFH_PUBLIC}
)

add_library(${FACTORIO_FRAME_HOST}
    ${FFH_COLLECTIVE}
)

add_source_group(${FFH_COLLECTIVE})

target_link_libraries(${FACTORIO_FRAME_HOST}
    ${CONAN_LIBS}
)

# Defines the headers for this library,
# and will be added to build paths.
target_include_directories(${FACTORIO_FRAME_HOST} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public/subprocess>
    $<INSTALL_INTERFACE:public>
    PRIVATE src)

# "make install" to the correct locations (GNUInstallDirs).
install(TARGETS ${FACTORIO_FRAME_HOST} EXPORT FFHLibraryConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows.
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Importable from the install directory.
# Config file per-project dir or into "cmake".
install(EXPORT FFHLibraryConfig DESTINATION share/FFHLibrary/cmake)

# Importable from build directory.
export(TARGETS ${FACTORIO_FRAME_HOST} FILE FFHLibraryConfig.cmake)

add_executable (test
    ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp
)

target_link_libraries(test
    ${FACTORIO_FRAME_HOST}
)

#add_test()
