cmake_minimum_required(VERSION 3.16)
project(LeetCode_Solutions)

set(CMAKE_CXX_STANDARD 17)


# List of directories to process
set(DIRECTORIES "1 -- 99" "100 -- 999" "1000 -- 9999" "other")

# Loop over each directory
foreach(DIR ${DIRECTORIES})
    # Use file(GLOB ...) to get all .cpp files in the current directory
    file(GLOB SOURCE_FILES "${DIR}/*.cpp")

    # Iterate over each source file and create an executable
    foreach(SOURCE_FILE ${SOURCE_FILES})
        # Extract the file name without extension to use as target name
        get_filename_component(TARGET_NAME ${SOURCE_FILE} NAME_WE)
        # Replace spaces and special characters in the target name if necessary
        string(REPLACE " " "_" TARGET_NAME ${TARGET_NAME})
        string(REPLACE "." "_" TARGET_NAME ${TARGET_NAME})

        # Add the executable
        add_executable(${TARGET_NAME} "${SOURCE_FILE}")
    endforeach()
endforeach()
