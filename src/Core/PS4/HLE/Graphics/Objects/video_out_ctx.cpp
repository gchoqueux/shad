#include "video_out_ctx.h"

namespace HLE::Graphics::Objects {

void VideoOutCtx::Init(u32 width, u32 height) {
    m_video_out_ctx.m_resolution.fullWidth = width;
    m_video_out_ctx.m_resolution.fullHeight = height;
    m_video_out_ctx.m_resolution.paneWidth = width;
    m_video_out_ctx.m_resolution.paneHeight = height;
}
int VideoOutCtx::Open() {
    Lib::LockMutexGuard lock(m_mutex);

    int handle = -1;

    if (!m_video_out_ctx.isOpened) {
        handle = 1;//positive return , should be more than 1 ?
    }

    m_video_out_ctx.isOpened = true;
    m_video_out_ctx.m_flip_status = SceVideoOutFlipStatus();
    m_video_out_ctx.m_flip_status.flipArg = -1;
    m_video_out_ctx.m_flip_status.currentBuffer = -1;
    m_video_out_ctx.m_flip_status.count = 0;
    m_video_out_ctx.m_vblank_status = SceVideoOutVblankStatus();

    return handle;
}
};  // namespace HLE::Graphics::Objects