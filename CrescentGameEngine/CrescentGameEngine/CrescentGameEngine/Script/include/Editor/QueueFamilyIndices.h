#ifndef QUEUE_FAMILY_INDICES_H
#define QUEUE_FAMILY_INDICES_H
#include <optional>

struct QueueFamilyIndices {
public:
	/// <summary>
	/// 支持图形操作的队列簇索引
	/// </summary>
	std::optional<uint32_t> graphicsFamily;
	/// <summary>
	/// 支持通过向窗口表面（VkSurfaceKHR）提交呈现操作的队列簇索引
	/// </summary>
	std::optional<uint32_t> presentFamily;

	/// <summary>
	/// 是否初始化完毕
	/// </summary>
	/// <returns></returns>
	bool isComplete() {
		return graphicsFamily.has_value() && presentFamily.has_value();
	}
};

#endif
