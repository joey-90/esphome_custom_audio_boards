#include "esp_korvo_volume.h"
#include "esphome/core/log.h"
#include "../esp32_s3_korvo1/board.h" // Adjust this include as necessary

namespace esphome
{
  namespace esp_korvo_volume
  {

    static const char *const TAG = "esp_box_volume";

    void ESPKorvoVolume::set_volume(float volume)
    {
      int vol = static_cast<int>(volume * 100.0);
      ESP_LOGD(TAG, "Setting volume to: %d", vol);
      audio_board_handle_t board_handle = audio_board_get_handle();
      if (!board_handle)
      {
        ESP_LOGE(TAG, "Invalid board handle, cannot set volume");
        return;
      }
      esp_err_t result = audio_board_set_volume(board_handle, vol);
      if (result != ESP_OK)
      {
        ESP_LOGE(TAG, "Failed to set volume, error: %d", result);
      }
    }

  } // namespace esp_box_volume
} // namespace esphome
