# Lists of hearders and sources
set(calcli-headers
	calcli.hpp
)

set(calcli-sources
	calcli.cpp
	main.cpp
)

# Executable compilation
set(exe_name calcli)
add_executable(${exe_name} ${calci-hearders} ${calcli-sources})

target_include_directories(${exe_name} PRIVATE ${CMAKE_SOURCE_DIR})

target_compile_features(${exe_name} PRIVATE cxx_std_17)

target_compile_options(${exe_name} PRIVATE 
	"-Wall"
	"-Wextra"
	"-pedantic"
)

include(${CMAKE_SOURCE_DIR}/cmake/OutputDirectories.cmake)
make_bin_directory(bin_directory)

set_target_properties(${exe_name} PROPERTIES 
	LINKER_LANGUAGE CXX
	CXX_EXTENSIONS OFF
	RUNTIME_OUTPUT_DIRECTORY ${bin_directory}
)
