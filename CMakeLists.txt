# CMakeList.txt : CMake project for Gravity Simulation, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


# version info ------------------------------------------------------------------------------------
project ("gravitySimulation")
set (VERSION_MAJOR 0)
set (VERSION_MINOR 0)
set (VERSION_PATCH 0)
set (VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
message ("Version: ${VERSION}")


# Configure Source and Binary Directories ---------------------------------------------------------
set (PROJECT_ROOT			"${PROJECT_SOURCE_DIR}")
set (PROJECT_EXTERNAL_DIR	"${PROJECT_SOURCE_DIR}/3rdparty")
set (PROJECT_RESOURCE_DIR	"${PROJECT_SOURCE_DIR}/res")
set (PROJECT_SOURCE			"${PROJECT_SOURCE_DIR}/src")
set (PROJECT_BINARY_DIR		"${PROJECT_BINARY_DIR}/bin")
message ("Root Dir:		${PROJECT_ROOT}")
message ("External Dir:	${PROJECT_EXTERNAL_DIR}")
message ("Resource Dir:	${PROJECT_RESOURCE_DIR}")
message ("Source Dir:	${PROJECT_SOURCE}")
message ("Binary Dir:	${PROJECT_BINARY_DIR}")


include_directories("inc" "3rdparty")


add_executable (gravitySimulation src/gravitySimulation_unity.cpp)


# fetch -------------------------------------------------------------------------------------------

include(FetchContent)

# glfw
FetchContent_Declare(
	glfw
	GIT_REPOSITORY	https://github.com/glfw/glfw.git
	GIT_TAG			7b6aead9fb88b3623e3b3725ebb42670cbe4c579
)

FetchContent_MakeAvailable(glfw)

target_link_libraries(gravitySimulation PRIVATE glfw)


