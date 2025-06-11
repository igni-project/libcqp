cmake_minimum_required(VERSION 3.15...4.0)

project(
	cqp
	VERSION 0.1
	LANGUAGES C
)

add_library(
	cqp
	src/cqp.c
)

install(TARGETS cqp)
include(CPack)

