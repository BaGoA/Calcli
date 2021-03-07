# Add calcli libraries
add_subdirectory(calcli-core)
add_subdirectory(calcli-processing)

# Lists of hearders and sources
set(calcli-headers
	calcli-application/application.hpp
)

set(calcli-sources
	calcli-application/application.cpp
	main.cpp
)

# Executable compilation
set(exe_name calcli)
add_executable(${exe_name} ${calci-hearders} ${calcli-sources})

target_include_directories(${exe_name} PRIVATE ${CMAKE_SOURCE_DIR}/src)

target_compile_features(${exe_name} PRIVATE cxx_std_20)

target_compile_options(${exe_name} PRIVATE 
	"-Wall"
	"-Wextra"
	"-pedantic"
)

include(${CMAKE_SOURCE_DIR}/tools/cmake/OutputDirectories.cmake)
make_lib_directory(lib_directory)
make_bin_directory(bin_directory)

target_link_libraries(${exe_name}
	${lib_directory}/libcalcli-processing.a
	${lib_directory}/libcalcli-core.a
)

set_target_properties(${exe_name} PROPERTIES 
	LINKER_LANGUAGE CXX
	CXX_EXTENSIONS OFF
	RUNTIME_OUTPUT_DIRECTORY ${bin_directory}
)
