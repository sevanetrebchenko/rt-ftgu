
set(CORE_SOURCE_FILES
    "${PROJECT_SOURCE_DIR}/src/main.cpp"

    # Project files.
    "${PROJECT_SOURCE_DIR}/src/rt/application.cpp"

    # BRDFs.
    "${PROJECT_SOURCE_DIR}/src/rt/brdf/brdf.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/brdf/lambertian.cpp"

    # Cameras.
    "${PROJECT_SOURCE_DIR}/src/rt/cameras/camera.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/cameras/pinhole.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/cameras/thin_lens.cpp"

    # Objects.
    "${PROJECT_SOURCE_DIR}/src/rt/objects/object.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/objects/primitives/plane.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/objects/primitives/sphere.cpp"

    # Samplers.
    "${PROJECT_SOURCE_DIR}/src/rt/samplers/sampler.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/samplers/stratified.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/samplers/random.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/samplers/n_rooks.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/samplers/multi_stratified.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/samplers/standard.cpp"

    # Utilities.
    "${PROJECT_SOURCE_DIR}/src/rt/utilities/ray.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/utilities/hit_record.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/utilities/writer.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/utilities/directory.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/utilities/random.cpp"
    "${PROJECT_SOURCE_DIR}/src/rt/utilities/onb.cpp"
)

add_executable(rt ${CORE_SOURCE_FILES})

target_include_directories(rt PUBLIC "${PROJECT_SOURCE_DIR}/include/")
target_precompile_headers(rt PRIVATE "${PROJECT_SOURCE_DIR}/include/pch.h")

# DEPENDENCIES
target_link_libraries(rt glm)
target_link_libraries(rt tinyobjloader)
target_link_libraries(rt stb)
