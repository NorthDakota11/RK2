cmake_minimum_required(VERSION 3.16)

project(rk2_solid
    VERSION 1.0.0
    DESCRIPTION "RK2 CMake project based on SOLID examples"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(GNUInstallDirs)

add_library(solid_srp src/journal.cpp)
add_library(rk2::solid_srp ALIAS solid_srp)

target_include_directories(solid_srp
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_options(solid_srp PRIVATE -Wall -Wextra -Wpedantic)

add_executable(solid_demo app/main.cpp)
target_link_libraries(solid_demo PRIVATE rk2::solid_srp)

include(CTest)
if(BUILD_TESTING)
    add_executable(test_journal tests/test_journal.cpp)
    target_link_libraries(test_journal PRIVATE rk2::solid_srp)
    add_test(NAME journal_saves_entries COMMAND test_journal)
endif()

install(TARGETS solid_srp solid_demo
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "rk2-solid")
set(CPACK_PACKAGE_VENDOR "NorthDakota11")
set(CPACK_PACKAGE_CONTACT "NorthDakota11")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "RK2 package with a CMake build, CTest test, and SOLID SRP example")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "NorthDakota11")
set(CPACK_DEBIAN_FILE_NAME DEB-DEFAULT)
set(CPACK_PACKAGING_INSTALL_PREFIX "/usr")
include(CPack)
