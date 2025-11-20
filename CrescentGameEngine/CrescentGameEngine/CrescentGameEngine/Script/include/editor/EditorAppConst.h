
#ifndef EDITOR_APP_CONST_H
#define EDITOR_APP_CONST_H

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
};

#endif
