## Play Video Utility

### Overview

The `play_video` utility allows for video playback on an LCD screen by sequentially displaying image frames from a
specified folder. Each frame is expected to follow a naming convention where the base file name is appended with a
numerical suffix and ".png" file extension.

### Files

1. **play_video.cpp**: Implements the `play_video` function for video playback.
2. **play_video.h**: Declares the `play_video` function.

### Functionality

####
`void play_video(const std::filesystem::path &frames_folder_path, int number_of_frames, const std::string &base_file_name)`

- **frames_folder_path**: Specifies the path to the folder containing the frame images.
- **number_of_frames**: Total number of frames to display in the video.
- **base_file_name**: Base name of the frame files, excluding numeric suffix and file extension.

### Usage

1. Include `play_video.h` in your project.
2. Prepare a folder containing frames named in the format `<base_file_name><frame_number>.png`.
3. Call the `play_video` function with the folder path, frame count, and base file name.

### Example

```cpp
#include "src/util/play_video.h"

int main()
{
    std::filesystem::path frames_folder = "/path/to/frames";
    int total_frames = 100;
    std::string base_file_name = "frame_";

    play_video(frames_folder, total_frames, base_file_name);

    return 0;
}
```