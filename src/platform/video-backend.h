/* Copyright (c) 2013-2015 Jeffrey Pfau
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#ifndef VIDEO_BACKEND_H
#define VIDEO_BACKEND_H

#include <mgba-util/common.h>

CXX_GUARD_START

#include <mgba-util/geometry.h>

#ifdef _WIN32
#include <windows.h>
typedef HWND WHandle;
#else
typedef void* WHandle;
#endif

enum VideoLayer {
	VIDEO_LAYER_BACKGROUND = 0,
	VIDEO_LAYER_IMAGE,
	VIDEO_LAYER_OVERLAY,
	VIDEO_LAYER_MAX
};

struct VideoBackend {
	void (*init)(struct VideoBackend*, WHandle handle);
	void (*deinit)(struct VideoBackend*);
	void (*setLayerDimensions)(struct VideoBackend*, enum VideoLayer, const struct Rectangle*);
	void (*layerDimensions)(const struct VideoBackend*, enum VideoLayer, struct Rectangle*);
	void (*swap)(struct VideoBackend*);
	void (*clear)(struct VideoBackend*);
	void (*contextResized)(struct VideoBackend*, unsigned w, unsigned h);
	void (*setImage)(struct VideoBackend*, enum VideoLayer, const void* frame);
	void (*drawFrame)(struct VideoBackend*);

	void* user;

	bool filter;
	bool lockAspectRatio;
	bool lockIntegerScaling;
	bool interframeBlending;
	enum VideoLayer cropToLayer;
};

struct VideoShader {
	const char* name;
	const char* author;
	const char* description;
	void* preprocessShader;
	void* passes;
	size_t nPasses;
};

CXX_GUARD_END

#endif
