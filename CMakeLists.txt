cmake_minimum_required(VERSION 3.15)

#============================================================================================>
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/output")
#============================================================================================>
option(USE_ATMEL "USE ATML" OFF)


if (USE_ATMEL)
	set(CMAKE_FIND_ROOT_PATH "C:/Program Files/Microchip/xc8/v2.36")
else(USE_ATMEL)
#	set(CMAKE_FIND_ROOT_PATH "F:/AVR/WinAVR")
	set(CMAKE_FIND_ROOT_PATH "F:/AVR/avr-gcc-12.1.0-x64-windows")
endif ()

set(AVR_MCU atmega32)
set(MCU_SPEED "16000000UL")

#============================================================================================>
if (USE_ATMEL)
	set(AVR_CC          ${CMAKE_FIND_ROOT_PATH}/bin/xc8-cc.exe)
	set(AVR_CXX     	${CMAKE_FIND_ROOT_PATH}/bin/xc8-cc.exe)

else(USE_ATMEL)
	set(AVR_CC          ${CMAKE_FIND_ROOT_PATH}/bin/avr-gcc.exe)
	set(AVR_CXX     	${CMAKE_FIND_ROOT_PATH}/bin/avr-g++.exe)
endif ()

set(AVR_OBJCOPY     ${CMAKE_FIND_ROOT_PATH}/bin/avr-objcopy.exe)
set(AVR_OBJDUMP     ${CMAKE_FIND_ROOT_PATH}/bin/avr-objdump.exe)

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_CXX_COMPILER ${AVR_CXX} CACHE STRING "c++ compiler" FORCE)
set(CMAKE_C_COMPILER ${AVR_CC} CACHE STRING "c compiler" FORCE)
set(CMAKE_OBJCOPY ${AVR_OBJCOPY} CACHE STRING "AVR OBJCOPY" FORCE)

set (CMAKE_CXX_FLAGS "-std=c++11 -mmcu=${AVR_MCU} -O1 -DF_CPU=${MCU_SPEED} ${CMAKE_CXX_FLAGS}")

#============================================================================================>
PROJECT(DIO-CPP CXX)
#============================================================================================>
if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)
#============================================================================================>
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_SYSTEM_INCLUDE_PATH "${CMAKE_FIND_ROOT_PATH}/avr/avr/include")
set(CMAKE_SYSTEM_LIBRARY_PATH "${CMAKE_FIND_ROOT_PATH}/avr/avr/lib")
#============================================================================================>

#============================================================================================>
#add_definitions("-DF_CPU=${MCU_SPEED}")
#add_definitions("-fpack-struct")
#add_definitions("-fshort-enums")
#add_definitions("-Wall")
#add_definitions("-Werror")
#add_definitions("-pedantic")
#add_definitions("-pedantic-errors")
#add_definitions("-funsigned-char")
#add_definitions("-funsigned-bitfields")
#add_definitions("-ffunction-sections")
#add_definitions("-c")
#============================================================================================>
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/mcal)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/hal)
#============================================================================================>
add_subdirectory(src)
#============================================================================================>
set(APP_SOURCES ${APP_SOURCES})
#============================================================================================>
set(elf_file ${PROJECT_NAME}.elf)
set(hex_file ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${PROJECT_NAME}.hex)
#============================================================================================>
#add_avr_executable(${PROJECT_NAME} ${APP_SOURCES})
add_executable(${elf_file} ${APP_SOURCES})
#============================================================================================>
add_custom_target(
		OUTPUT ALL
		DEPENDS ${elf_file}
		COMMAND ${AVR_OBJCOPY} -j .text -j .data -O ihex ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${elf_file} ${hex_file}
)
#============================================================================================>


