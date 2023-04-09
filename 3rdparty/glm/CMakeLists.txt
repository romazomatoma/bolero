include(FetchContent)

FetchContent_Populate(
	glm
	GIT_REPOSITORY https://github.com/g-truc/glm
	GIT_TAG 0.9.9.8
)

set(GLM_SOURCE_DIR ${glm_SOURCE_DIR} CACHE PATH description)