cmake_minimum_required(VERSION 3.15...4.0)

project(
	cqp
	VERSION 0.1.1
	LANGUAGES C
)

add_library(
	cqp
	src/cqp.c
)

target_sources(
	cqp
	PUBLIC
	$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
	$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/libcqp>
)

get_target_property(CQP_PUBLIC_HEADERS cqp INTERFACE_SOURCES)

set_target_properties(cqp PROPERTIES PUBLIC_HEADER "${CQP_PUBLIC_HEADERS}")

target_include_directories(
	cqp
	INTERFACE include/libcqp
)

include(CPack)
include(GNUInstallDirs)

install(TARGETS cqp)

