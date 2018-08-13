#include "unmangler.h"

#include <cxxabi.h>

std::string unmangler::unmangle(std::string mangled)
{
	int status;
	char *demangled = abi::__cxa_demangle(mangled.c_str(), nullptr, nullptr, &status);
	if (status == 0)
	{
		std::string result {demangled};
		delete[] demangled;
		return std::move(result);
	}
	else
	{
		delete[] demangled;
		return std::move(mangled);
	}
	
}
