#pragma once

#ifdef SP_PLATFORM_WINDOWS
	#ifdef SP_BUILD_DLL
		#define SPOT_API __declspec(dllexport)
	#else
		#define SPOT_API __declspec(dllimport)
	#endif
#else
	#error Sport Engine only supports Windows Systems!
#endif