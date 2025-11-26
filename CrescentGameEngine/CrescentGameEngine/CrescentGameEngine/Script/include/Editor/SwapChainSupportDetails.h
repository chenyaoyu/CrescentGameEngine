#ifndef SWAP_CHAIN_SUPPORT_DETAILS_H
#define SWAP_CHAIN_SUPPORT_DETAILS_H

#include "Common/CommonHeader.h"
#include <vector>

struct SwapChainSupportDetails {
	VkSurfaceCapabilitiesKHR capabilities;
	std::vector<VkSurfaceFormatKHR> formats;
	std::vector<VkPresentModeKHR> presentModes;
};

#endif
