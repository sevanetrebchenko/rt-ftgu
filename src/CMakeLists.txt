
set(CORE_SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/src/main.cpp"
        )

add_executable(rt ${CORE_SOURCE_FILES})

target_include_directories(rt PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_precompile_headers(rt PRIVATE "${PROJECT_SOURCE_DIR}/include/pch.h")

# DEPENDENCIES
target_link_libraries(rt glm)
target_link_libraries(rt tinyobjloader)
target_link_libraries(rt stb)
