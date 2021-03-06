#pragma once

#pragma warning(disable:4369)

#include <Windows.h>

#include <vector>
#include <math.h>

#ifdef GetGlyphIndices
#undef GetGlyphIndices
#endif

#include <d2d1.h>
#include <d2d1helper.h>
#include <d2d1_1.h>
#include <d2d1_1helper.h>
#include <d2d1_2.h>
#include <d2d1_2helper.h>
#include <d2d1_3.h>
#include <d2d1_3helper.h>
#include <d2d1effects.h>
#include <d2d1effects_1.h>
#include <d2d1effects_2.h>
#include <d2d1effectauthor.h>
#include <d2d1effectauthor_1.h>
#include <d2d1effecthelpers.h>
#include <d2d1svg.h>
#include <dwrite.h>
#include <dwrite_1.h>
#include <dwrite_2.h>
#include <dwrite_3.h>
#include <wincodec.h>

#ifndef GetGlyphIndices
#define GetGlyphIndices GetGlyphIndicesW
#endif