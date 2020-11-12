# Function to get binaries output directory according to built type
function(make_bin_directory bin_directory)
	set(bin_base_directory ${CMAKE_SOURCE_DIR}/bin)

	string(COMPARE EQUAL ${CMAKE_BUILD_TYPE} Debug is_debug_mode)
	string(COMPARE EQUAL ${CMAKE_BUILD_TYPE} Release is_release_mode)

	if(is_debug_mode)
		string(CONCAT bin_directory_tmp ${bin_base_directory} "/debug")
	elseif(is_release_mode)
		string(CONCAT bin_directory_tmp ${bin_base_directory} "/release")
	else()
		string(CONCAT bin_directory_tmp ${bin_base_directory} "/any")
	endif()

	set(${bin_directory} ${bin_directory_tmp} PARENT_SCOPE)
endfunction()
