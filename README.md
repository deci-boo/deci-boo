# Deci-Boo! 👾🔊

**Monsters, Inc. / Monsters University Scare Games–inspired Smart Sound & Noise Arcade** built with `STM32F411RE` (`NUCLEO-F411RE`) and `ESP32-S3`.

## Overview

- **`KY-037` (Microphone Sensor):** Samples ambient sound / scream level via Analog (`PA0` / `ADC1_IN0` peak-to-peak) and Digital threshold (`PA1`).
- **`KY-040` (Rotary Encoder + Switch):** Adjusts noise/scare threshold in real time (`TIM3` Encoder Mode on `PA6`/`PA7`) and resets/switches mode via push button (`PA8`).
- **`KY-009` (RGB SMD LED):** Displays 3-tier Green → Yellow → Blinking Red indicator via `TIM4` Hardware PWM (`PB6`, `PB8`, `PB9` with 220–330 Ω resistors).
- **`ESP32-S3` Wi-Fi Bridge:** Bidirectional UART (`USART1` ↔ `Serial1`) hosting a real-time Web Dashboard & threshold control over Wi-Fi.

## Pin Mapping (`NUCLEO-F411RE` ↔ Modules)

| Module | Pin | STM32F411RE / ESP32-S3 | Function |
|---|---|---|---|
| `KY-037` | `A0` / `D0` | `PA0` (`ADC1_IN0`) / `PA1` (`GPIO_Input`) | Sound amplitude & digital comparator |
| `KY-040` | `CLK` / `DT` / `SW` | `PA6` (`TIM3_CH1`) / `PA7` (`TIM3_CH2`) / `PA8` (`Pull-up`) | Threshold dial & button |
| `KY-009` | `R` / `G` / `B` | `PB6` (`TIM4_CH1`) / `PB8` (`TIM4_CH3`) / `PB9` (`TIM4_CH4`) | PWM RGB indicator (via 220–330 Ω R) |
| UART Bridge | `TX` / `RX` | `PA9` (`USART1_TX`) → `GPIO 18`, `PA10` (`USART1_RX`) ← `GPIO 17` | Bidirectional STM32 ↔ ESP32-S3 link |

## Team (Group `:)` — Embedded System Lab)

- `6731315721` Natthakorn Yiengyongphan
- `6731332321` Poonnawit Supawasuwat
- `6731362121` Sukrit Kankrasang
- `6731365021` Aut Suttitanamongkol

## Firmware Structure

- **STM32CubeIDE (`NUCLEO-F411RE`):** [`firmware/stm32/test_ky`](firmware/stm32/test_ky)
- **ESP32-S3 (`Arduino IDE`):** [`firmware/esp32/deci_boo_bridge/deci_boo_bridge.ino`](firmware/esp32/deci_boo_bridge/deci_boo_bridge.ino)
  - Copy `firmware/esp32/deci_boo_bridge/secrets.example.h` → `secrets.h` and fill in your 2.4 GHz Wi-Fi credentials before uploading.

## Roar Games (Web Game)

Open `http://<ESP32-IP>/` (the old dashboard moved to `/dash`).

1. Each player picks a monster → set threshold (web slider or rotate `KY-040`).
2. Press **Start turn** (or push `KY-040`): yellow light fades over 3 s → **ROAR!** window (2–4 s).
3. STM32 measures peak + time above threshold → green (pass) / red (fail) on the web and on `KY-009`.
4. Score = `th/10` + `(peak−th)/20` + `time-above-threshold ratio × 100`. Pass needs peak ≥ th and ≥ 0.2 s above it. Higher center bar wins.

- Source: [`web/game.html`](web/game.html) → after editing run `python3 tools/embed_html.py` to regenerate `game_html.h` for the ESP32.
- Without a board (open the file directly) it runs in simulation mode: hold `SPACE` to roar, `Enter` = KY-040 button.

UART protocol additions (`\n`-terminated):

| Direction | Message | Meaning |
|---|---|---|
| Web → STM32 | `GAME,1` / `GAME,0` | Enter / leave game mode (KY-009 controlled by web) |
| Web → STM32 | `LED,Y` / `LED,F` / `LED,G` / `LED,R` / `LED,OFF` | Yellow / yellow fade 3 s / green / red blink / off |
| Web → STM32 | `ROAR,<th>,<ms>` | Start a roar window |
| STM32 → Web | `RES,<peak>,<hold_ms>,<pass>` | Roar result |
| STM32 → Web | `BTN` | `KY-040` pushed in game mode |

## Docs

- [Week 1 Progress & Hardware Verification](docs/progress_update_2026-11-12.md)
