#include "animation/AnimationExtractor.h"

using namespace WarframeExporter::Animation;

AnimationExtractor*
AnimationExtractor::getInstance()
{
	static AnimationExtractor* instance = new AnimationExtractor();
	return instance;
}

void
AnimationExtractor::extract(LotusLib::FileEntry& fileEntry, const LotusLib::PackageCollection& pkgs, const LotusLib::PackagesBin& pkgsBin, const std::filesystem::path& outputPath, const ExtractOptions options)
{
	AnimationHeaderExternal extHeader;
	AnimationBodyExternal extBody;

	AnimationReader* reader = g_enumMapAnimation.at(pkgs.getGame(), (int)fileEntry.commonHeader.type);
	reader->readHeader(&fileEntry.header, fileEntry.commonHeader, extHeader);
	reader->readBody(&fileEntry.body, extHeader, fileEntry.commonHeader, extBody);

	AnimationData combined;
	AnimationConverter::convertAnimation(extHeader, extBody, combined);

	gltfAnimation outAnimation;
	outAnimation.addAnimationData(combined);
	outAnimation.save(outputPath);
}
