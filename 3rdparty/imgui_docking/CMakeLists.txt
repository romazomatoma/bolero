include(FetchContent)

FetchContent_Populate(
	imgui
	GIT_REPOSITORY https://github.com/ocornut/imgui
	GIT_TAG 1668693bcfbc8669db60e775fd19f3a4ac26fe89
)

set(IMGUI_SOURCE_DIR ${imgui_SOURCE_DIR} CACHE PATH description)