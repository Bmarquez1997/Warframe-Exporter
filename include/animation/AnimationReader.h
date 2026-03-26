#pragma once

#include "BinaryReader/Buffered.h"
#include "LotusLib/CommonHeader.h"
#include "ExporterExceptions.h"
#include "AnimationStructs.hpp"
#include "glm/vec3.hpp"
#include "glm/mat4x4.hpp"
#include "glm/gtc/quaternion.hpp"
#include "glm/gtx/euler_angles.hpp"
#include "EnumMapGame.h"

#include <cassert>
#include <unordered_map>
#include <iostream>
#include <cmath>

namespace WarframeExporter::Animation
{
	enum class AnimationType
	{
		ANIMATION_132 = 132
	};
	
	class AnimationReader : public EnumMapGameValue
	{
	protected:
		AnimationReader() = default;
		
	public:
		virtual void readHeader(BinaryReader::Buffered* headerReader, const LotusLib::CommonHeader& header, AnimationHeaderExternal& outHeader) = 0;
		virtual void readBody(BinaryReader::Buffered* bodyReader, const AnimationHeaderExternal& extHeader, const LotusLib::CommonHeader& header, AnimationBodyExternal& outBody) = 0;
	};
}