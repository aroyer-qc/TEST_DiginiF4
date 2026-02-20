set(CMAKE_SYSTEM_NAME               Generic)
set(CMAKE_SYSTEM_PROCESSOR          arm)

set(COMPILER_WANTED_VERSION "$ENV{COMPILER_WANTED_VERSION}" CACHE STRING "Compiler version for build" FORCE)

set(COMPILERS_FOLDER "${CMAKE_CURRENT_LIST_DIR}/../../Compiler")

set(PACKAGE_CONTAINS_SUBFOLDER FALSE)
set(PACKAGE_EXTRACTED_FOLDER "")
if(COMPILER_WANTED_VERSION STREQUAL "8.2.1")
	if(CMAKE_HOST_APPLE)
		SET(COMPILER_PACKAGE_NAME "gcc-arm-none-eabi-8-2018-q4-major-mac.tar.bz2")
		SET(COMPILER_MD5 1EC5BED45D78788723036F22C4E83BA8)
		SET(COMPILER_DOWNLOAD_URL "https://developer.arm.com/-/media/Files/downloads/gnu-rm/8-2018q4/gcc-arm-none-eabi-8-2018-q4-major-mac.tar.bz2")
		SET(MY_COMPILER_PATH "${COMPILERS_FOLDER}/gcc-arm-none-eabi-8-2018-q4-major-mac")
	elseif(CMAKE_HOST_WIN32)
		SET(COMPILER_PACKAGE_NAME "gcc-arm-none-eabi-8-2018-q4-major-win32.zip")
		SET(COMPILER_MD5 9b1cfb7539af11b0badfaa960679ea6f)
		SET(COMPILER_DOWNLOAD_URL "https://developer.arm.com/-/media/Files/downloads/gnu-rm/8-2018q4/gcc-arm-none-eabi-8-2018-q4-major-win32.zip")
		SET(MY_COMPILER_PATH "${COMPILERS_FOLDER}/gcc-arm-none-eabi-8-2018-q4-major-win32")
	elseif(CMAKE_HOST_UNIX)
		SET(COMPILER_PACKAGE_NAME "gcc-arm-none-eabi-8-2018-q4-major-linux.tar.bz2")
		SET(COMPILER_MD5 f55f90d483ddb3bcf4dae5882c2094cd)
		SET(COMPILER_DOWNLOAD_URL "https://developer.arm.com/-/media/Files/downloads/gnu-rm/8-2018q4/gcc-arm-none-eabi-8-2018-q4-major-linux.tar.bz2")
		SET(MY_COMPILER_PATH "${COMPILERS_FOLDER}/gcc-arm-none-eabi-8-2018-q4-major-linux")
	endif()
elseif(COMPILER_WANTED_VERSION STREQUAL "13.2.1")
  if(CMAKE_HOST_APPLE)
		SET(COMPILER_PACKAGE_NAME "xpack-arm-none-eabi-gcc-13.2.1-1.1-darwin-x64.tar.gz")
		SET(COMPILER_MD5 d49e809701b8f381185d45572f416637)
		SET(COMPILER_DOWNLOAD_URL "https://github.com/xpack-dev-tools/arm-none-eabi-gcc-xpack/releases/download/v13.2.1-1.1/xpack-arm-none-eabi-gcc-13.2.1-1.1-darwin-x64.tar.gz")
		SET(MY_COMPILER_PATH "${COMPILERS_FOLDER}/xpack-arm-none-eabi-gcc-13.2.1-1.1-darwin-x64")
	elseif(CMAKE_HOST_WIN32)
		SET(COMPILER_PACKAGE_NAME "xpack-arm-none-eabi-gcc-13.2.1-1.1-win32-x64.zip")
		SET(COMPILER_MD5 cfbd5476cc796ae332318061439e4019)
		SET(COMPILER_DOWNLOAD_URL "https://github.com/xpack-dev-tools/arm-none-eabi-gcc-xpack/releases/download/v13.2.1-1.1/xpack-arm-none-eabi-gcc-13.2.1-1.1-win32-x64.zip")
		SET(MY_COMPILER_PATH "${COMPILERS_FOLDER}/xpack-arm-none-eabi-gcc-13.2.1-1.1-win32-x64")
	elseif(CMAKE_HOST_UNIX)
		SET(COMPILER_PACKAGE_NAME "xpack-arm-none-eabi-gcc-13.2.1-1.1-linux-x64.tar.gz")
		SET(COMPILER_MD5 6ead98defe950a0225530c900e3f7791)
		SET(COMPILER_DOWNLOAD_URL "https://github.com/xpack-dev-tools/arm-none-eabi-gcc-xpack/releases/download/v13.2.1-1.1/xpack-arm-none-eabi-gcc-13.2.1-1.1-linux-x64.tar.gz")
		SET(MY_COMPILER_PATH "${COMPILERS_FOLDER}/xpack-arm-none-eabi-gcc-13.2.1-1.1-linux-x64")
	endif()
else()
	message(FATAL_ERROR "Config not supported")
endif()

if(CMAKE_HOST_WIN32)
	set(UTIL_SEARCH_CMD where)
	set(COMPILER_EXECUTABLE_SUFFIX ".exe")
	message(STATUS "search command where")
elseif(CMAKE_HOST_UNIX)
	set(UTIL_SEARCH_CMD whereis)
	message(STATUS "search command whereis")
endif()

set(TOOLCHAIN_PREFIX arm-none-eabi-)

# use only the default compiler path if found
get_filename_component(DEFAULT_COMPILER_PATH "${MY_COMPILER_PATH}/bin/${TOOLCHAIN_PREFIX}gcc${COMPILER_EXECUTABLE_SUFFIX}" REALPATH)
IF(EXISTS "${DEFAULT_COMPILER_PATH}")
    SET(BIN_PATHS "${DEFAULT_COMPILER_PATH}")
ELSE()
	#Check if we can find it elsewhere
	execute_process(
		COMMAND ${UTIL_SEARCH_CMD} ${TOOLCHAIN_PREFIX}gcc
		OUTPUT_VARIABLE BINUTILS_PATH
		OUTPUT_STRIP_TRAILING_WHITESPACE
	)

	if(CMAKE_HOST_WIN32)
		STRING(REPLACE "\n" ";" BIN_PATHS ${BINUTILS_PATH} "")
	elseif(CMAKE_HOST_UNIX)
		STRING(REPLACE "${TOOLCHAIN_PREFIX}gcc: " "" BINUTILS_PATH ${BINUTILS_PATH} "")
		STRING(REPLACE " " ";" BIN_PATHS ${BINUTILS_PATH} "")
	endif()
ENDIF()

SET(COMPILER_PATH "")
IF(NOT BIN_PATHS STREQUAL "")
  FOREACH(X IN LISTS BIN_PATHS)
    MESSAGE(STATUS "Checking compiler: ${X}")
    execute_process(
	    COMMAND ${X} -dumpversion
	    OUTPUT_VARIABLE COMPILER_VERSION
	    OUTPUT_STRIP_TRAILING_WHITESPACE
    )
	  SET(MY_COMPILER_VERSION "${COMPILER_VERSION}")

    IF("${COMPILER_VERSION}" MATCHES "${COMPILER_WANTED_VERSION}")
	    SET(COMPILER_PATH ${X})
	    BREAK()
    ENDIF()
  ENDFOREACH()
ENDIF()

MESSAGE(STATUS "Wanted compiler version ${COMPILER_WANTED_VERSION} and found version = " ${MY_COMPILER_VERSION} " at path = " ${COMPILER_PATH})

IF(("${COMPILER_PATH}" STREQUAL "") OR NOT ("${MY_COMPILER_VERSION}" MATCHES "${COMPILER_WANTED_VERSION}"))
	message(STATUS "Compiler not found. Downloading the correct version")

	file(DOWNLOAD "${COMPILER_DOWNLOAD_URL}"
		"${COMPILERS_FOLDER}/${COMPILER_PACKAGE_NAME}"
		EXPECTED_MD5;${COMPILER_MD5}
		SHOW_PROGRESS
		STATUS status)

	message(STATUS "Creating folders and cleanup...")
	file(REMOVE_RECURSE "${MY_COMPILER_PATH}" "${MY_COMPILER_PATH}_temp")
	file(MAKE_DIRECTORY "${MY_COMPILER_PATH}_temp")
	
	message(STATUS "Extracting the compiler")
	execute_process(
		COMMAND ${CMAKE_COMMAND} -E tar xf ${COMPILERS_FOLDER}/${COMPILER_PACKAGE_NAME}
		WORKING_DIRECTORY "${MY_COMPILER_PATH}_temp"
	)

	if(EXISTS "${MY_COMPILER_PATH}_temp/bin")
		file(RENAME "${MY_COMPILER_PATH}_temp" ${MY_COMPILER_PATH})
	else()
		file(GLOB FOLDER_CONTENT RELATIVE "${MY_COMPILER_PATH}_temp" "${MY_COMPILER_PATH}_temp/*")
		message(DEBUG "glob is ${FOLDER_CONTENT}")
		if(EXISTS "${MY_COMPILER_PATH}_temp/${FOLDER_CONTENT}/bin")
			file(RENAME "${MY_COMPILER_PATH}_temp/${FOLDER_CONTENT}" "${MY_COMPILER_PATH}")
		else()
			message(FATAL_ERROR "Archive does not contain bin folder at expected location")
		endif()
	endif()

	file(REMOVE_RECURSE "${MY_COMPILER_PATH}_temp")

  	SET(COMPILER_PATH ${DEFAULT_COMPILER_PATH})
ELSE()
	message(STATUS "Compiler found with correct version. No need to install a new one")
ENDIF()

MESSAGE(STATUS "Compiler path: ${COMPILER_PATH}")

# Without that flag CMake is not able to pass test compilation check
set(CMAKE_EXE_LINKER_FLAGS_INIT "--specs=nosys.specs")
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

if(CMAKE_HOST_WIN32)
	set(APPLICATION_EXTENSION ".exe")
else()
	set(APPLICATION_EXTENSION "")
endif()

# Extract the directory component of the compiler path
get_filename_component(ARM_TOOLCHAIN_DIR ${COMPILER_PATH} DIRECTORY)

set(CMAKE_C_COMPILER                ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}gcc${APPLICATION_EXTENSION})
set(CMAKE_ASM_COMPILER              ${CMAKE_C_COMPILER})
set(CMAKE_CXX_COMPILER              ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}g++${APPLICATION_EXTENSION})
set(CMAKE_LINKER                    ${CMAKE_CXX_COMPILER})

set(CMAKE_OBJCOPY                   ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}objcopy CACHE INTERNAL "objcopy tool")
set(CMAKE_SIZE_UTIL                 ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}size    CACHE INTERNAL "size tool")
set(CMAKE_NM_UTIL                   ${ARM_TOOLCHAIN_DIR}/${TOOLCHAIN_PREFIX}nm      CACHE INTERNAL "nm tool")

set(CMAKE_FIND_ROOT_PATH ${ARM_TOOLCHAIN_DIR})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

get_filename_component(EXPECTED_TOOLCHAIN_DIR ${DEFAULT_COMPILER_PATH} DIRECTORY)
IF ((NOT ("${EXPECTED_TOOLCHAIN_DIR}" MATCHES "${ARM_TOOLCHAIN_DIR}")) AND (NOT ("$ENV{TOOLCHAIN_WARNING_VERSION}" MATCHES "$ENV{COMPILER_WANTED_VERSION}")))
# Set environment variable so warning is only generated once
SET(ENV{TOOLCHAIN_WARNING_VERSION} "$ENV{COMPILER_WANTED_VERSION}")
message(STATUS "Compiler not located in default location : ${EXPECTED_TOOLCHAIN_DIR}")
message(WARNING "Make sure the debug settings point to the correct toolchain path for OpenOCD to work:\n.vscode/settings.json\n.gdbinit_gccx.x.x files")
ENDIF()