# Static analysis activation with clang-tidy
include(${CMAKE_SOURCE_DIR}/tools/cmake/StaticAnalyzers.cmake)

# Library compilation
set(lib_name pinky-api)

add_library(${lib_name} STATIC
	expression.hpp expression.cpp
)

target_compile_features(${lib_name} PRIVATE cxx_std_20)

include(${CMAKE_SOURCE_DIR}/tools/cmake/CompilerWarnings.cmake)
set_project_warnings(${lib_name})

include(${CMAKE_SOURCE_DIR}/tools/cmake/OutputDirectories.cmake)
make_lib_directory(lib_directory)

target_link_libraries(${lib_name}
	${lib_directory}/libpinky-core.a
)

set_target_properties(${lib_name} PROPERTIES 
	LINKER_LANGUAGE CXX
	CXX_EXTENSIONS OFF
	ARCHIVE_OUTPUT_DIRECTORY ${lib_directory}
)
