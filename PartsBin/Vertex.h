#pragma once

//Optional, forces memory alignment
//#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
#include <glm/glm.hpp>
#include <array>

//This is so comically bloated compared to the DX11 version
struct Vertex {
	glm::vec2 pos;
	glm::vec3 color;
	glm::vec2 texCoord;

	static VkVertexInputBindingDescription getBindingDescription() {
		VkVertexInputBindingDescription bindingDescription{};
		bindingDescription.binding = 0;
		bindingDescription.stride = sizeof(Vertex);
		bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX; //VK_VERTEX_INPUT_RATE_INSTANCE for instanced rendering

		return bindingDescription;
	}

	//Documentation recommended these values. Measured in bits not bytes. 32bi == 4by
	//Format options: SFLOAT, UINT, SINT
	//float: VK_FORMAT_R32_SFLOAT
	//vec2 : VK_FORMAT_R32G32_SFLOAT
	//vec3 : VK_FORMAT_R32G32B32_SFLOAT
	//vec4 : VK_FORMAT_R32G32B32A32_SFLOAT
	static std::array<VkVertexInputAttributeDescription, 3> getAttributeDescriptions() {
		std::array<VkVertexInputAttributeDescription, 3> attributeDescriptions{};
		attributeDescriptions[0].binding = 0;
		attributeDescriptions[0].location = 0;
		attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
		attributeDescriptions[0].offset = offsetof(Vertex, pos);

		attributeDescriptions[1].binding = 0;
		attributeDescriptions[1].location = 1;
		attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
		attributeDescriptions[1].offset = offsetof(Vertex, color);

		attributeDescriptions[2].binding = 0;
		attributeDescriptions[2].location = 2;
		attributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
		attributeDescriptions[2].offset = offsetof(Vertex, texCoord);

		return attributeDescriptions;
	}

};