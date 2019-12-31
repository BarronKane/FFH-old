project(frame-host)
set(FFH_NAME ${PROJECT_NAME} CACHE INTERNAL "FFH_NAME")

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

add_library(${FFH_NAME}
    ${FFH_COLLECTIVE}
)

add_source_group(${FFH_COLLECTIVE})

target_link_libraries(${FFH_NAME}
    ${CONAN_LIBS}
)

# Defines the headers for this library,
# and will be added to build paths.
target_include_directories(${FFH_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/public>
    $<INSTALL_INTERFACE:public>
    PRIVATE src)

# "make install" to the correct locations (GNUInstallDirs).
install(TARGETS ${FFH_NAME} EXPORT FFHLibraryConfig
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR})  # This is for Windows.
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Importable from the install directory.
# Config file per-project dir or into "cmake".
install(EXPORT FFHLibraryConfig DESTINATION share/FFHLibrary/cmake)

# Importable from build directory.
export(TARGETS ${FFH_NAME} FILE FFHLibraryConfig.cmake)

add_executable (test
    ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp
)

target_link_libraries(test
    ${FFH_NAME}
)

#add_test()
