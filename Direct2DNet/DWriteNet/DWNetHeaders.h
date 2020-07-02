#pragma once

#include <Windows.h>

#include <vector>

#ifdef GetGlyphIndices
#undef GetGlyphIndices
#endif

#include <dwrite.h>
#include <dwrite_1.h>
#include <dwrite_2.h>
#include <dwrite_3.h>

#ifndef GetGlyphIndices
#define GetGlyphIndices GetGlyphIndicesW
#endif