#ifndef UNMANGLER_H
#define UNMANGLER_H

#include <ngrest/common/Service.h>

class unmangler: public ngrest::Service
{
public:
	// *method: GET
	std::string unmangle(std::string mangled);
};


#endif // UNMANGLER_H
