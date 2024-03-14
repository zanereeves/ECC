cmake_minimum_required(VERSION 3.10)
project(ellipse)
add_executable(ellipseScal src/main.c)
add_executable(ellipsePed src/pedersenTest.c)
add_executable(ellipseVerify src/sigTest.c)
enable_testing()
add_test(test_0 ellipseScal)
add_test(test_1 ellipsePed)
add_test(test_2 ellipseVerify)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBSODIUM libsodium)
pkg_check_modules(LIBGMP gmp)

add_library(ELLIPSE_LIB SHARED
            header/arithmetic.h
            src/arithmetic.c)

if(STATIC_LIBSODIUM)
  if(BUILD_STATIC_EXECUTABLES)
    set_target_properties(ellipse PROPERTIES LINK_SEARCH_START_STATIC 1)
    set_target_properties(ellipse PROPERTIES LINK_SEARCH_END_STATIC 1)
  endif()
  set(CMAKE_FIND_LIBRARY_SUFFIXES .lib .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
endif()

if(STATIC_LIBGMP)
  if(BUILD_STATIC_EXECUTABLES)
    set_target_properties(ellipse PROPERTIES LINK_SEARCH_START_STATIC 1)
    set_target_properties(ellipse PROPERTIES LINK_SEARCH_END_STATIC 1)
  endif()
  set(CMAKE_FIND_LIBRARY_SUFFIXES .lib .a ${CMAKE_FIND_LIBRARY_SUFFIXES})
endif()

find_path(SODIUM_INCLUDE_DIR sodium.h HINTS ${LIBSODIUM_INCLUDE_DIRS} /usr/local/include /opt/local/include /opt/include)
find_library(SODIUM_LIBRARY NAMES sodium HINTS ${LIBSODIUM_LIBRARY_DIRS} /usr/local/lib /opt/local/lib /opt/lib)

find_path(GMP_INCLUDE_DIR gmp.h HINTS ${LIBGMP_INCLUDE_DIRS} /usr/local/include /opt/local/include /opt/include)
find_library(GMP_LIBRARY NAMES gmp HINTS ${LIBGMP_LIBRARY_DIRS} /usr/local/lib /opt/local/lib /opt/lib)


if(STATIC_LIBSODIUM)
  set(LIBSODIUM_CFLAGS_OTHER ${LIBSODIUM_STATIC_CFLAGS_OTHER})
  set(LIBSODIUM_LDFLAGS_OTHER ${LIBSODIUM_STATIC_LDFLAGS_OTHER})
endif()

if(STATIC_LIBGMP)
  set(LIBGMP_CFLAGS_OTHER ${LIBGMP_STATIC_CFLAGS_OTHER})
  set(LIBGMP_LDFLAGS_OTHER ${LIBGMP_STATIC_LDFLAGS_OTHER})
endif()


target_include_directories(ELLIPSE_LIB PUBLIC ${SODIUM_INCLUDE_DIR} ${LIBGMP_INCLUDE_DIRS})
target_compile_options(ELLIPSE_LIB PUBLIC ${LIBSODIUM_CFLAGS} ${LIBSODIUM_CFLAGS_OTHER} ${LIBGMP_CFLAGS} ${LIBGMP_CFLAGS_OTHER})
target_link_libraries(ELLIPSE_LIB ${SODIUM_LIBRARY} ${LIBSODIUM_LDFLAGS_OTHER} ${GMP_LIBRARY} ${LIBGMP_LDFLAGS_OTHER})

target_link_libraries(ellipseScal ELLIPSE_LIB)
target_link_libraries(ellipsePed ELLIPSE_LIB)
target_link_libraries(ellipseVerify ELLIPSE_LIB)
