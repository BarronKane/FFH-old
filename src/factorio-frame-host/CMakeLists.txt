project(factorio-frame-host)

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

add_library(${CMAKE_PROJECT_NAME}
    ${FFH_PRIVATE}
    ${FFH_PUBLIC}
)

if(WIN32)
    target_compile_definitions(${CMAKE_PROJECT_NAME}
        PRIVATE -D _WIN32_WINNT=0x0601
    )
endif(WIN32)

target_link_libraries(${CMAKE_PROJECT_NAME}
    ${CONAN_LIBS}
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
export(TARGETS ${CMAKE_PROJECT_NAME} FILE FFHLibraryConfig.cmake)

add_executable (test
    ${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp
)

target_link_libraries(test
    ${CMAKE_PROJECT_NAME}
)

#add_test()
