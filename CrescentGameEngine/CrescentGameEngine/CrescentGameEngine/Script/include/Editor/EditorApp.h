#ifndef EDITOR_APP_H
#define EDITOR_APP_H

#include "Common/CommonHeader.h"
#include "Editor/QueueFamilyIndices.h"
#include "Editor/SwapChainSupportDetails.h"

class EditorApp {
public:
	void run();

private:
	GLFWwindow* window;
	/// <summary>
	/// vulkan实例
	/// </summary>
	VkInstance instance;
	/// <summary>
	/// vulkan 物理设备
	/// </summary>
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
	/// <summary>
	/// vulkan 逻辑设备
	/// </summary>
	VkDevice device;
	/// <summary>
	/// 
	/// </summary>
	VkDebugUtilsMessengerEXT debugMessenger;
	/// <summary>
	/// vulkan surface实例
	/// </summary>
	VkSurfaceKHR surface;

	/// <summary>
	/// 初始化glfw窗口
	/// </summary>
	void initWindow();

	/// <summary>
	/// 初始化vulkan环境
	/// </summary>
	void initVulkan();

	/// <summary>
	/// 创建Vulkan实例
	/// </summary>
	void createInstance();

	/// <summary>
	/// 验证层日志输出
	/// </summary>
	/// <param name="messageSeverity"></param>
	/// <param name="messageType"></param>
	/// <param name="pCallbackData"></param>
	/// <param name="pUserData"></param>
	/// <returns></returns>
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);

	/// <summary>
	/// 创建验证层的createinfo
	/// </summary>
	/// <param name="createInfo"></param>
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

	VkResult CreateDebugUtilsMessengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);

	/// <summary>
	/// 启动验证层
	/// </summary>
	void setupDebugMessenger();

	/// <summary>
	/// 创建surface拓展实例
	/// </summary>
	void createSurface();

	// 选择物理设备（GPU）
	void pickPhysicalDevice();

	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

	// 检查设备是否适合
	bool isDeviceSuitable(VkPhysicalDevice device);

	// 创建逻辑设备
	void createLogicalDevice();

	void mainLoop();
	void cleanup();
	/// <summary>
	/// 筛选能支持指定拓展的物理设备
	/// </summary>
	/// <param name="device"></param>
	/// <returns></returns>
	bool checkDeviceExtensionSupport(VkPhysicalDevice device);
	/// <summary>
	/// 查询目标物理设备锁支持的surface格式和presentation模式信息
	/// </summary>
	/// <param name="device"></param>
	/// <returns></returns>
	SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

};

#endif
