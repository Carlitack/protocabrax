// scenes/protopirate_scene_protocol_help.c
// In-app protocol documentation by brand + quick usage guide
#include "../protopirate_app_i.h"

#define TAG "ProtoPirateProtoHelp"

// Each help page is a chunk of text displayed in a widget
static const char* help_pages[] = {
    // Page 0: Quick Start Guide
    "=== QUICK START ===\n"
    "\n"
    "1. RECEIVE\n"
    "  Go to Receive, pick freq,\n"
    "  point Flipper at keyfob.\n"
    "  Press OK to lock signal.\n"
    "\n"
    "2. SAVED\n"
    "  View captured signals,\n"
    "  check decode details.\n"
    "\n"
    "3. SUB DECODE\n"
    "  Load .sub files from SD.\n"
    "\n"
    "4. CONFIG\n"
    "  Freq, hopping, TX power,\n"
    "  auto-save, emulate.\n"
    "\n"
    "5. TIMING TUNER\n"
    "  Compare fob timing vs\n"
    "  protocol definition.\n",

    // Page 1: Ford
    "=== FORD ===\n"
    "\n"
    "Ford V0 [AM 315/433]\n"
    "  Manchester, Rolling Code\n"
    "  CRC matrix GF(2)\n"
    "  Decode: yes  Encode: yes\n"
    "\n"
    "Ford V1 [FM 315/433]\n"
    "  Manchester, Rolling Code\n"
    "  CRC16\n"
    "\n"
    "Ford V2 [FM 434]\n"
    "  Manchester, Simple replay\n"
    "\n"
    "Ford V3 [AM/FM 434]\n"
    "  Manchester, Rolling Code\n",

    // Page 2: Kia
    "=== KIA ===\n"
    "\n"
    "Kia V0 [FM 315/433]\n"
    "  PWM, Rolling Code + CRC8\n"
    "\n"
    "Kia V1 [AM 315/433]\n"
    "  Manchester, Rolling Code\n"
    "  CRC4\n"
    "\n"
    "Kia V2 [FM 315/433]\n"
    "  Manchester, Rolling Code\n"
    "  CRC4\n"
    "\n"
    "Kia V3/V4 [FM 315/433]\n"
    "  PWM, KeeLoq + CRC4\n"
    "\n"
    "Kia V5 [FM 315/433]\n"
    "  PWM, Rolling Code\n"
    "\n"
    "Kia V6 [FM 315/433]\n"
    "  Manchester, AES-128\n"
    "  CRC8\n"
    "\n"
    "Kia V7 [FM 315/433]\n"
    "  Manchester, Rolling Code\n"
    "  CRC8\n",

    // Page 3: VAG (VW/Audi/Seat/Skoda)
    "=== VAG ===\n"
    "(VW/Audi/Seat/Skoda)\n"
    "\n"
    "Protocol: VAG\n"
    "  [AM 434.42]\n"
    "  Manchester\n"
    "  Crypto: AUT64 + XTEA\n"
    "  Decode: yes  Encode: yes\n"
    "\n"
    "AUT64 = 12 rounds,\n"
    "8-byte block cipher.\n"
    "Used by most VW group\n"
    "vehicles since ~2005.\n",

    // Page 4: PSA (Peugeot/Citroen)
    "=== PSA ===\n"
    "(Peugeot/Citroen)\n"
    "\n"
    "Protocol: PSA\n"
    "  [AM + FM 315/433]\n"
    "  Manchester\n"
    "  Crypto: XTEA + XOR\n"
    "  CRC8\n"
    "  Decode: yes  Encode: yes\n"
    "\n"
    "PSA Bruteforce plugin\n"
    "available for XTEA key\n"
    "recovery.\n",

    // Page 5: Fiat
    "=== FIAT ===\n"
    "\n"
    "Fiat V0 [AM 315/433]\n"
    "  Manchester, Rolling Code\n"
    "  (static emulate only)\n"
    "\n"
    "Fiat V1 [AM 315/433]\n"
    "  Manchester, HITAG2\n"
    "  XOR8 checksum\n"
    "  Needs HITAG2 key prompt\n"
    "\n"
    "Fiat V2 [AM 315/433]\n"
    "  Manchester, Rolling Code\n"
    "  No encoder\n",

    // Page 6: Honda
    "=== HONDA ===\n"
    "\n"
    "Honda Static [FM 315/433]\n"
    "  PWM, Static code\n"
    "  Checksum\n"
    "\n"
    "Honda V1 [AM 315/433]\n"
    "  Manchester, Rolling Code\n"
    "  CRC4\n"
    "\n"
    "Honda V2 [FM 315/433]\n"
    "  PWM, Rolling Code\n"
    "  Check + Tail\n",

    // Page 7: Other Brands
    "=== OTHER ===\n"
    "\n"
    "Chrysler V0 [AM 315/433]\n"
    "  PWM, Rolling Code\n"
    "\n"
    "Mazda V0 [AM+FM 315/433]\n"
    "  Manchester, Rolling Code\n"
    "  Checksum\n"
    "\n"
    "Mitsubishi V0 [FM 315/433]\n"
    "  PWM, Rolling Code\n"
    "\n"
    "Porsche Touareg [AM 315]\n"
    "  PWM, Rolling Code\n"
    "\n"
    "Renault V0 [AM 315/433]\n"
    "  Manchester, Rolling/Replay\n"
    "\n"
    "Subaru [AM 315/433]\n"
    "  PPM, Rolling Code\n"
    "\n"
    "Scher-Khan [FM]\n"
    "  PWM, Magic Code\n"
    "\n"
    "StarLine [AM 315/433]\n"
    "  PWM, KeeLoq\n",
};

static void protopirate_scene_protocol_help_dialog_callback(DialogExResult result, void* context) {
    furi_check(context);
    ProtoPirateApp* app = context;
    if(result == DialogExResultLeft) {
        view_dispatcher_send_custom_event(app->view_dispatcher, 0); // prev
    } else if(result == DialogExResultRight) {
        view_dispatcher_send_custom_event(app->view_dispatcher, 1); // next
    } else if(result == DialogExResultCenter) {
        view_dispatcher_send_custom_event(app->view_dispatcher, 2); // exit
    }
}

void protopirate_scene_protocol_help_on_enter(void* context) {
    furi_check(context);
    ProtoPirateApp* app = context;

    widget_reset(app->widget);
    widget_add_text_scroll_element(
        app->widget, 0, 0, 128, 64, help_pages[0]);

    view_dispatcher_switch_to_view(app->view_dispatcher, ProtoPirateViewWidget);
}

bool protopirate_scene_protocol_help_on_event(void* context, SceneManagerEvent event) {
    furi_check(context);
    ProtoPirateApp* app = context;
    bool consumed = false;

    if(event.type == SceneManagerEventTypeCustom) {
        uint32_t page = scene_manager_get_scene_state(app->scene_manager, ProtoPirateSceneProtocolHelp);
        uint32_t num_pages = sizeof(help_pages) / sizeof(help_pages[0]);

        if(event.event == 0 && page > 0) {
            page--;
            consumed = true;
        } else if(event.event == 1 && page < num_pages - 1) {
            page++;
            consumed = true;
        } else if(event.event == 2) {
            scene_manager_previous_scene(app->scene_manager);
            return true;
        }

        if(consumed) {
            scene_manager_set_scene_state(app->scene_manager, ProtoPirateSceneProtocolHelp, page);
            widget_reset(app->widget);
            widget_add_text_scroll_element(
                app->widget, 0, 0, 128, 64, help_pages[page]);
            widget_add_frame_element(app->widget, 0, 0, 128, 64, 0);
        }
    }

    return consumed;
}

void protopirate_scene_protocol_help_on_exit(void* context) {
    furi_check(context);
    ProtoPirateApp* app = context;
    widget_reset(app->widget);
}
