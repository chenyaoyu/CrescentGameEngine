
#ifndef EDITOR_APP_CONST_H
#define EDITOR_APP_CONST_H

#include "Common/CommonHeader.h"
#include <vector>

namespace EditorAppConst
{
	/// <summary>
	/// 编辑器app 名称
	/// </summary>
	const char* EDITOR_APP_NAME = "CresentGameEngineEditor";
	const int WIDTH = 800;
	const int HEIGHT = 600;

	// 是否开启验证层
#ifdef NDEBUG
	const bool ENABLE_VALIDATION_LAYERS = false;
#else
	const bool ENABLE_VALIDATION_LAYERS = true;
#endif

	// 指定需要支持哪些拓展
	const std::vector<const char*> deviceExtensions = {
		VK_KHR_SWAPCHAIN_EXTENSION_NAME
	};
};

#endif
