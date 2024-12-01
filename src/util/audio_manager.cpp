#define MINIAUDIO_IMPLEMENTATION
#include "src/util/audio_manager.h"

#include <cstring>
#include <iostream>
#include "src/lib/miniaudio.h"

namespace game
{
    AudioManager::AudioManager(const std::string &file_path)
    {
        if (ma_decoder_init_file(file_path.c_str(), nullptr, &m_decoder) != MA_SUCCESS)
        {
            std::cerr << "Failed to initialize decoder." << std::endl;
            return;
        }

        ma_device_config device_config = ma_device_config_init(ma_device_type_playback);
        device_config.playback.format = m_decoder.outputFormat;
        device_config.playback.channels = m_decoder.outputChannels;
        device_config.sampleRate = m_decoder.outputSampleRate;
        device_config.dataCallback = data_callback;
        device_config.pUserData = this;

        if (ma_device_init(nullptr, &device_config, &m_device) != MA_SUCCESS)
        {
            std::cerr << "Failed to initialize playback device." << std::endl;
            ma_decoder_uninit(&m_decoder);
            return;
        }

        m_is_initialized = true;
    }

    AudioManager::~AudioManager()
    {
        if (m_is_initialized)
        {
            ma_device_uninit(&m_device);
            ma_decoder_uninit(&m_decoder);
        }
    }

    void AudioManager::play()
    {
        if (m_is_initialized)
        {
            if (ma_device_start(&m_device) != MA_SUCCESS)
            {
                std::cerr << "Failed to start playback." << std::endl;
            }
        }
    }

    void AudioManager::stop()
    {
        if (m_is_initialized)
        {
            ma_device_stop(&m_device);
        }
    }

    double AudioManager::get_audio_length_in_seconds() const
    {
        if (!m_is_initialized)
        {
            std::cerr << "AudioManager is not properly initialized." << std::endl;
            return 0.0;
        }

        ma_uint64 total_frames = 0;
        if (ma_decoder_get_length_in_pcm_frames(const_cast<ma_decoder *>(&m_decoder), &total_frames) != MA_SUCCESS)
        {
            std::cerr << "Failed to get the total number of PCM frames." << std::endl;
            return 0.0;
        }

        return static_cast<double>(total_frames) / m_decoder.outputSampleRate;
    }

    bool AudioManager::is_playback_complete() const
    {
        return m_playback_complete;
    }

    void AudioManager::data_callback(ma_device *device, void *output, const void *input, ma_uint32 frame_count)
    {
        AudioManager *manager = reinterpret_cast<AudioManager *>(device->pUserData);

        ma_uint64 frames_read = 0;
        ma_result result = ma_decoder_read_pcm_frames(&manager->m_decoder, output, frame_count, &frames_read);

        if (result != MA_SUCCESS || frames_read < frame_count)
        {
            manager->m_playback_complete = true;

            memset(static_cast<unsigned char *>(output) + (frames_read * ma_get_bytes_per_frame(
                                                               device->playback.format, device->playback.channels)),
                   0,
                   (frame_count - frames_read) * ma_get_bytes_per_frame(
                       device->playback.format, device->playback.channels));
        }

        (void) input; // Suppress unused parameter warning.
    }
}
