// Copyright 2017 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include "common/common_types.h"
#include "common/vector_math.h"
#include "video_core/regs_texturing.h"

namespace Pica {
namespace Texture {

/// Returns the byte size of a 8*8 tile of the specified texture format.
size_t CalculateTileSize(TexturingRegs::TextureFormat format);

struct TextureInfo {
    PAddr physical_address;
    unsigned int width;
    unsigned int height;
    ptrdiff_t stride;
    TexturingRegs::TextureFormat format;

    static TextureInfo FromPicaRegister(const TexturingRegs::TextureConfig& config,
                                        const TexturingRegs::TextureFormat& format);

    /// Calculates stride from format and width, assuming that the entire texture is contiguous.
    void SetDefaultStride() {
        stride = CalculateTileSize(format) * (width / 8);
    }
};

/**
 * Lookup texel located at the given coordinates and return an RGBA vector of its color.
 * @param source Source pointer to read data from
 * @param x,y Texture coordinates to read from
 * @param info TextureInfo object describing the texture setup
 * without providing a good way to visualize alpha by themselves. If true, this will return 255 for
 * the alpha component, and either drop the information entirely or store it in an "unused" color
 * channel.
 * @todo Eventually we should get rid of the disable_alpha parameter.
 */
Math::Vec4<u8> LookupTexture(const u8* source, unsigned int x, unsigned int y,
                             const TextureInfo& info);

/**
 * Looks up a texel from a single 8x8 texture tile.
 *
 * @param source Pointer to the beginning of the tile.
 * @param x, y In-tile coordinates to read from. Must be < 8.
 * @param info TextureInfo describing the texture format.
 */
Math::Vec4<u8> LookupTexelInTile(const u8* source, unsigned int x, unsigned int y,
                                 const TextureInfo& info);

} // namespace Texture
} // namespace Pica
