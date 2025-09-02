// MFListTransforms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <mfapi.h>
#include <mferror.h>
#include <mftransform.h>

int main()
{
    auto hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (FAILED(hr)) {
        std::cout << "COM initialisation failed" << std::endl;
        exit(-1);
    }

    hr = MFStartup(MF_VERSION);
    if (FAILED(hr)) {
        std::cout << "Media Foundation initialization failed" << std::endl;
    }
    
    IMFActivate** ppActivate = NULL;
    UINT32 count = 0;

    // hw: MFVideoFormat_NV12, sw: MFVideoFormat_IYUV
    MFT_REGISTER_TYPE_INFO inputType = { MFMediaType_Video, MFVideoFormat_NV12 };

    hr = MFTEnumEx(MFT_CATEGORY_VIDEO_ENCODER,
        MFT_ENUM_FLAG_SYNCMFT | MFT_ENUM_FLAG_ASYNCMFT,
        // MFT_ENUM_FLAG_HARDWARE,
        &inputType,
        nullptr,
        &ppActivate,
        &count);
    if (FAILED(hr)) {
        std::cout << "Media Foundation enumeration failed" << std::endl;
    }

    std::cout << "Transforms: " << count << std::endl;

    for (auto i = 0; i < count; i++) {
        GUID guidMFT = { 0 };
        auto hr = ppActivate[i]->GetGUID(MFT_TRANSFORM_CLSID_Attribute, &guidMFT);
        LPWSTR guid = nullptr;
        hr = StringFromIID(guidMFT, &guid);
        if (FAILED(hr)) {
            std::cerr << "Failed to get GUID string" <<  std::endl;
            break;
        }

        LPWSTR friendlyName = nullptr;
        uint32_t length = 0;
        hr = ppActivate[i]->GetAllocatedString(MFT_FRIENDLY_NAME_Attribute, &friendlyName, &length);
        if FAILED(hr) {
            std::cout << "Failed to get friendly name" << std::endl;
            break;
        }

        std::wcout << friendlyName << ", GUID: " << guid << std::endl;

        CoTaskMemFree(friendlyName);
        CoTaskMemFree(guid);
    }

    for (auto i = 0; i < count; i++)
    {
        ppActivate[i]->Release();
    }
    CoTaskMemFree(ppActivate);
}
