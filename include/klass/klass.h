#define KLASS_API_IMPORT __declspec(dllimport)

#include <string>

namespace kl
{
	KLASS_API_IMPORT void print(std::string out);
}