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

// Log level: comment out levels you want to see.
// E=errors, W=warnings, I=info, D=debug, T=trace
// Production: keep E, W enabled. Development: enable I, D as needed.
#define PP_LOG_QUIET

#ifdef PP_LOG_QUIET
// Disable verbose logs (I, D, T) but keep errors and warnings
#undef FURI_LOG_I
#undef FURI_LOG_D
#undef FURI_LOG_T
#define FURI_LOG_I(tag, format, ...)
#define FURI_LOG_D(tag, format, ...)
#define FURI_LOG_T(tag, format, ...)
// FURI_LOG_E and FURI_LOG_W remain active
#endif // PP_LOG_QUIET
