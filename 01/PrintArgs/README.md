<!-- doc.py -->
stdafx.cpp : source file that includes just the standard includes
PrintArgs.pch will be the pre-compiled header
stdafx.obj will contain the pre-compiled type information
TODO: reference any additional headers you need in STDAFX.H
and not in this file
[PrintArgs/stdafx.cpp](PrintArgs/stdafx.cpp)

stdafx.h : include file for standard system include files,
or project specific include files that are used frequently, but
are changed infrequently

TODO: reference additional headers your program requires here
[PrintArgs/stdafx.h](PrintArgs/stdafx.h)

Including SDKDDKVer.h defines the highest available Windows platform.
If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.
[PrintArgs/targetver.h](PrintArgs/targetver.h)

