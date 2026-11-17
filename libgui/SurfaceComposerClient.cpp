/*
 * Copyright (C) 2022-2025 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <gui/SurfaceComposerClient.h>
#include <utils/Errors.h>

using android::IBinder;
using android::sp;
using android::String8;
using android::SurfaceComposerClient;
using android::status_t;

extern "C" status_t _ZN7android21SurfaceComposerClient11Transaction5applyEbb(void* thisptr,
                                                                             bool synchronous,
                                                                             bool oneWay);

extern "C" status_t _ZN7android21SurfaceComposerClient11Transaction5applyEb(void* thisptr,
                                                                            bool synchronous) {
    return _ZN7android21SurfaceComposerClient11Transaction5applyEbb(thisptr, synchronous, false);
}

sp<IBinder> legacyCreateDisplay(const String8& displayName, bool isSecure,
                               float requestedRefreshRate)
        __asm__("_ZN7android21SurfaceComposerClient13createDisplayERKNS_7String8Ebf");

sp<IBinder> legacyCreateDisplay(const String8& displayName, bool isSecure,
                               float requestedRefreshRate) {
    return SurfaceComposerClient::createVirtualDisplay(
            std::string(displayName.c_str()), isSecure, true, SurfaceComposerClient::kEmpty,
            android::gui::Uid::INVALID.val(), requestedRefreshRate);
}

void legacyDestroyDisplay(const sp<IBinder>& displayToken)
        __asm__("_ZN7android21SurfaceComposerClient14destroyDisplayERKNS_2spINS_7IBinderEEE");

void legacyDestroyDisplay(const sp<IBinder>& displayToken) {
    SurfaceComposerClient::destroyVirtualDisplay(displayToken);
}

sp<IBinder> legacyCreateVirtualDisplay(const std::string& displayName, bool isSecure,
                                      const std::string& uniqueId, float requestedRefreshRate)
        __asm__("_ZN7android21SurfaceComposerClient20createVirtualDisplayERKNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEbS9_f");

sp<IBinder> legacyCreateVirtualDisplay(const std::string& displayName, bool isSecure,
                                      const std::string& uniqueId, float requestedRefreshRate) {
    return SurfaceComposerClient::createVirtualDisplay(
            displayName, isSecure, true, uniqueId, android::gui::Uid::INVALID.val(),
            requestedRefreshRate);
}

sp<IBinder> legacyCreateVirtualDisplayWithPolicy(const std::string& displayName, bool isSecure,
                                                bool optimizeForPower,
                                                const std::string& uniqueId,
                                                float requestedRefreshRate)
        __asm__("_ZN7android21SurfaceComposerClient20createVirtualDisplayERKNSt3__112basic_stringIcNS1_11char_traitsIcEENS1_9allocatorIcEEEEbbS9_f");

sp<IBinder> legacyCreateVirtualDisplayWithPolicy(const std::string& displayName, bool isSecure,
                                                bool optimizeForPower,
                                                const std::string& uniqueId,
                                                float requestedRefreshRate) {
    return SurfaceComposerClient::createVirtualDisplay(
            displayName, isSecure, optimizeForPower, uniqueId, android::gui::Uid::INVALID.val(),
            requestedRefreshRate);
}

extern "C" void* _ZTVN7android21SurfaceComposerClient11TransactionE = nullptr;
