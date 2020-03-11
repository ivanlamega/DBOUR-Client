#pragma once
#include "VersionLog.h"
#define STRINGIZE2(s) #s
#define STRINGIZE(s) STRINGIZE2(s)

#define VER_FILE_VERSION_STR        STRINGIZE(_VERSION_MAJOR_)        \
                                    "." STRINGIZE(_VERSION_MINOR_)    \
                                    "." STRINGIZE(_VERSION_REVISION_) \
                                    "." STRINGIZE(_VERSION_BUILD_)
