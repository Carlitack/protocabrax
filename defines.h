#pragma once

#define ENABLE_TIMING_TUNER_SCENE
#define ENABLE_SUB_DECODE_SCENE
#define ENABLE_EMULATE_FEATURE

#if defined(ENABLE_EMULATE_FEATURE) && !defined(PROTOPIRATE_PROTOCOL_RX_ONLY)
#define PROTOPIRATE_WITH_ENCODER 1
#else
#define PROTOPIRATE_WITH_ENCODER 0
#endif

#ifndef PROTOPIRATE_PROTOCOL_TX_ONLY
#define PROTOPIRATE_WITH_DECODER 1
#else
#define PROTOPIRATE_WITH_DECODER 0
#endif

// Keep REMOVE_LOGS defined so #ifndef REMOVE_LOGS blocks remain disabled
#define REMOVE_LOGS

#ifdef REMOVE_LOGS
// Undefine verbose macros only
#undef FURI_LOG_I
#undef FURI_LOG_D
#undef FURI_LOG_T
// Define empty verbose macros
#define FURI_LOG_I(tag, format, ...)
#define FURI_LOG_D(tag, format, ...)
#define FURI_LOG_T(tag, format, ...)
// FURI_LOG_E and FURI_LOG_W remain active for debugging
#endif // REMOVE_LOGS
