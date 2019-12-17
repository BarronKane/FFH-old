project(factorio-frame-host)

set(FFH_PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/private/factorio-frame-host.cpp
)
set(FFH_PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/public/factorio-frame-host.h
)

add_library(${CMAKE_PROJECT_NAME}
    ${FFH_PRIVATE}
    ${FFH_PUBLIC}
)

# Defines the headers for this library,
# and will be added to build paths.
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>
    $<INSTALL_INTERFACE:public>
    PRIVATE src)

# "make install" to the correct locations (GNUInstallDirs).
install(TARGETS ${CMAKE_PROJECT_NAME} EXPORT FFHLibraryConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows.
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Importable from the install directory.
# Config file per-project dir or into "cmake".
install(EXPORT FFHLibraryConfig DESTINATION share/FFHLibrary/cmake)

# Importable from build directory.
export(TARGETS ${CMAKE_PROJECT_NAME} FILE MyLibraryConfig.cmake)

add_executable (test
    ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp
)

target_link_libraries(test
    ${CMAKE_PROJECT_NAME}
)

#add_test()
