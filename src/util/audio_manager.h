#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <string>
#include "src/lib/miniaudio.h"

namespace game
{
    class AudioManager
    {
    public:
        explicit AudioManager(const std::string &file_path);

        ~AudioManager();

        void play();

        void stop();

        double get_audio_length_in_seconds() const;

        bool is_playback_complete() const;

    private:
        ma_decoder m_decoder;
        ma_device m_device;
        bool m_is_initialized = false;
        bool m_playback_complete = false;

        static void data_callback(ma_device *device, void *output, const void *input, ma_uint32 frame_count);
    };
}

#endif // AUDIO_MANAGER_H
