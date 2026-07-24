// scenes/protopirate_scene_export_csv.c
// Export decoded signal data as CSV text for PC analysis
#include "../protopirate_app_i.h"
#include "../helpers/protopirate_storage.h"

#define TAG "ProtoPirateExportCSV"

void protopirate_scene_export_csv_on_enter(void* context) {
    furi_check(context);
    ProtoPirateApp* app = context;

    FuriString* csv = furi_string_alloc();
    FuriString* text = furi_string_alloc();
    uint32_t temp_u32 = 0;

    furi_string_printf(csv, "Field,Value\n");

    // Read loaded file directly
    if(app->loaded_file_path && !furi_string_empty(app->loaded_file_path)) {
        Storage* storage = furi_record_open(RECORD_STORAGE);
        FlipperFormat* ff = flipper_format_file_alloc(storage);

        if(flipper_format_file_open_existing(ff, furi_string_get_cstr(app->loaded_file_path))) {
            flipper_format_rewind(ff);

            // Read standard fields
            if(flipper_format_read_string(ff, "Protocol", text))
                furi_string_cat_printf(csv, "Protocol,%s\n", furi_string_get_cstr(text));

            flipper_format_rewind(ff);
            if(flipper_format_read_uint32(ff, "Bit", &temp_u32, 1))
                furi_string_cat_printf(csv, "Bit,%lu\n", (unsigned long)temp_u32);

            flipper_format_rewind(ff);
            if(flipper_format_read_uint32(ff, "Key", &temp_u32, 1))
                furi_string_cat_printf(csv, "Key,0x%08lX\n", (unsigned long)temp_u32);

            flipper_format_rewind(ff);
            if(flipper_format_read_uint32(ff, "TE", &temp_u32, 1))
                furi_string_cat_printf(csv, "TE,%lu\n", (unsigned long)temp_u32);

            flipper_format_rewind(ff);
            if(flipper_format_read_uint32(ff, "Sn", &temp_u32, 1))
                furi_string_cat_printf(csv, "Serial,0x%08lX\n", (unsigned long)temp_u32);

            flipper_format_rewind(ff);
            if(flipper_format_read_uint32(ff, "Btn", &temp_u32, 1))
                furi_string_cat_printf(csv, "Button,%lu\n", (unsigned long)temp_u32);

            flipper_format_rewind(ff);
            if(flipper_format_read_uint32(ff, "Cnt", &temp_u32, 1))
                furi_string_cat_printf(csv, "Counter,%lu\n", (unsigned long)temp_u32);

            flipper_format_rewind(ff);
            if(flipper_format_read_uint32(ff, "Manufacture", &temp_u32, 1))
                furi_string_cat_printf(csv, "Manufacture,%lu\n", (unsigned long)temp_u32);

            flipper_format_rewind(ff);
            if(flipper_format_read_uint32(ff, "Type", &temp_u32, 1))
                furi_string_cat_printf(csv, "Type,%lu\n", (unsigned long)temp_u32);
        } else {
            furi_string_set_str(csv, "\nCould not open file.");
        }

        flipper_format_free(ff);
        furi_record_close(RECORD_STORAGE);
    } else {
        furi_string_set_str(csv, "\nNo file loaded.\nSave a capture first,\nthen view details\nto export CSV.");
    }

    widget_reset(app->widget);
    widget_add_text_scroll_element(app->widget, 0, 0, 128, 64, furi_string_get_cstr(csv));
    view_dispatcher_switch_to_view(app->view_dispatcher, ProtoPirateViewWidget);

    furi_string_free(text);
    furi_string_free(csv);
}

bool protopirate_scene_export_csv_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);
    return false;
}

void protopirate_scene_export_csv_on_exit(void* context) {
    furi_check(context);
    ProtoPirateApp* app = context;
    widget_reset(app->widget);
}
