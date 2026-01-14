#ifndef EDITOR_APP_H
#define EDITOR_APP_H

#include "Common/CommonHeader.h"
#include "Editor/QueueFamilyIndices.h"
#include "Editor/SwapChainSupportDetails.h"
#include <string>

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
	/// 渲染队列
	/// </summary>
	VkQueue graphicsQueue;
	/// <summary>
	/// 提交呈现命令队列
	/// </summary>
	VkQueue presentQueue;
	/// <summary>
	/// 交换链拓展的实例
	/// </summary>
	VkSwapchainKHR swapChain;
	/// <summary>
	/// 图形数据的对象列表
	/// VkImage：一个用于表示图形数据的对象，它是图像数据的底层表示，负责存储图像的元数据（如宽度、高度、格式等）但不直接存储像素数据
	/// </summary>
	std::vector<VkImage> swapChainImages;
	std::vector<VkFramebuffer> swapChainFramebuffers;
	/// <summary>
	/// 交换链图像格式
	/// </summary>
	VkFormat swapChainImageFormat;
	/// <summary>
	/// 交换链图像尺寸
	/// </summary>
	VkExtent2D swapChainExtent;
	/// <summary>
	/// 交换链图像视图
	/// </summary>
	std::vector<VkImageView> swapChainImageViews;

	VkRenderPass renderPass;

	VkPipelineLayout pipelineLayout;
	VkPipeline graphicsPipeline;

	VkCommandPool commandPool;
	VkCommandBuffer commandBuffer;

	VkSemaphore imageAvailableSemaphore;
	VkSemaphore renderFinishedSemaphore;
	VkFence inFlightFence;

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
	/// <summary>
	/// 创建交换链
	/// </summary>
	void createSwapChain(bool enableVsync);

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

	/// <summary>
	/// 根据物理设备的所有表面格式拓展列表formats中过滤出指定的像素格式和色彩空间的表面格式拓展。
	/// </summary>
	/// <param name="availableFormats"></param>
	/// <returns></returns>
	VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
	/// <summary>
	/// 根据物理设备的所有提交呈现命名模式拓展中过滤指定模式的提交呈现命名模式拓展。
	/// </summary>
	/// <param name="availablePresentModes"></param>
	/// <returns></returns>
	VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
	/// <summary>
	/// 根据物理设备的表面能力的画面尺寸，创建二维尺寸VkExtent2D。
	/// </summary>
	/// <param name="capabilities"></param>
	/// <returns></returns>
	VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
	/// <summary>
	/// 创建图像视图
	/// </summary>
	void createImageViews();
	/// <summary>
	/// 
	/// </summary>
	void createFramebuffers();
	/// <summary>
	/// 创建渲染管道
	/// </summary>
	void createRenderPass();
	/// <summary>
	/// 创建渲染管线
	/// </summary>
	void createGraphicsPipeline();
	/// <summary>
	/// 临时的读取文件
	/// </summary>
	static std::vector<char> readFile(const std::string& filename);
	/// <summary>
	/// 根据shader的二进制数据创建shadermode.
	/// </summary>
	/// <param name="code"></param>
	/// <returns></returns>
	VkShaderModule createShaderModule(const std::vector<char>& code);
	void drawFrame();
	void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
	void createCommandPool();
	void createCommandBuffer();
	void createSyncObjects();
};

#endif
