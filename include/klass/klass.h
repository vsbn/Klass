#define KLASS_API_IMPORT __declspec(dllimport)

#include <string>
#include <Windows.h>

#ifdef NO_GPU_SELECT // Disables the auto selection of any AMD or NVIDIA GPU. Uses integrated graphics by defualt if available.
#define NvOptimusEnablement PLACE_HOLDER_NVIDIA
#define AmdPowerXpressRequestHighPerformance PLACE_HOLDER_AMD
#endif

#ifdef ONLY_AMD_GPU_SELECT // Selects AMD GPU for rendering if available.
#define NvOptimusEnablement PLACE_HOLDER_NVIDIA
#endif

#ifdef ONLY_NVIDIA_GPU_SELECT // Selects NVIDIA GPU for rendering if available.
#define AmdPowerXpressRequestHighPerformance PLACE_HOLDER_AMD
#endif

#define AUTO_GPU_SELECT // Enabled by defualt. Selects any AMD or NVIDIA GPUs for rendering if available. Nvidia is prioritised above AMD.

extern "C" 
{
    __declspec(dllexport) DWORD NvOptimusEnablement = 1;
    __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
}


namespace kl
{
	KLASS_API_IMPORT void print(std::string out);
}