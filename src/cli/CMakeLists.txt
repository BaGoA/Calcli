# Static analysis activation with clang-tidy
include(${CMAKE_SOURCE_DIR}/tools/cmake/StaticAnalyzers.cmake)

# Executable compilation
set(exe_name pinky-cli)

add_executable(${exe_name}
	application.hpp application.cpp
	main.cpp
)

target_compile_features(${exe_name} PRIVATE cxx_std_20)

include(${CMAKE_SOURCE_DIR}/tools/cmake/CompilerWarnings.cmake)
set_project_warnings(${exe_name})

include(${CMAKE_SOURCE_DIR}/tools/cmake/OutputDirectories.cmake)
make_lib_directory(lib_directory)
make_bin_directory(bin_directory)

target_link_libraries(${exe_name}
	${lib_directory}/libpinky-api.a
	${lib_directory}/libpinky-core.a
)

set_target_properties(${exe_name} PROPERTIES 
	LINKER_LANGUAGE CXX
	CXX_EXTENSIONS OFF
	RUNTIME_OUTPUT_DIRECTORY ${bin_directory}
)
