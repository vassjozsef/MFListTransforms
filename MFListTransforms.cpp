// MFListTransforms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <mfapi.h>
#include <mferror.h>
#include <mftransform.h>

struct Codec {
    std::string name;
    GUID guid;
};

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

    Codec encoders[] = { Codec{"H.264", MFVideoFormat_H264}, Codec{"HEVC", MFVideoFormat_HEVC}, Codec{"AV1", MFVideoFormat_AV1} };

    for (auto encoder : encoders) {
        MFT_REGISTER_TYPE_INFO outputType = { MFMediaType_Video , encoder.guid };

        hr = MFTEnumEx(MFT_CATEGORY_VIDEO_ENCODER,
            //MFT_ENUM_FLAG_SYNCMFT | MFT_ENUM_FLAG_ASYNCMFT,
            MFT_ENUM_FLAG_HARDWARE,
            nullptr,
            &outputType,
            &ppActivate,
            &count);
        if (FAILED(hr)) {
            std::cout << "Media Foundation enumeration failed" << std::endl;
        }

        std::cout << "Transforms for " << encoder.name << ": " << count << std::endl;

        for (auto i = 0; i < count; i++) {
            GUID guidMFT = { 0 };
            auto hr = ppActivate[i]->GetGUID(MFT_TRANSFORM_CLSID_Attribute, &guidMFT);
            if (FAILED(hr)) {
              continue;
            }
            LPWSTR guid = nullptr;
            hr = StringFromIID(guidMFT, &guid);
            if (FAILED(hr)) {
                std::cerr << "Failed to get GUID string" << std::endl;
                continue;
            }

            LPWSTR friendlyName = nullptr;
            uint32_t length = 0;
            hr = ppActivate[i]->GetAllocatedString(MFT_FRIENDLY_NAME_Attribute, &friendlyName, &length);
            if FAILED(hr) {
                std::cout << "Failed to get friendly name" << std::endl;
                continue;
            }

            uint32_t flags = 0;
            ppActivate[i]->GetUINT32(MF_TRANSFORM_FLAGS_Attribute, &flags);
            if (FAILED(hr)) {
                std::cout << "Failed to get flags" << std::endl;
                continue;
            }

            std::wcout << friendlyName << ", GUID: " << guid << ", flags: " << flags << std::endl;

            CoTaskMemFree(friendlyName);
            CoTaskMemFree(guid);
        }

        for (auto i = 0; i < count; i++)
        {
            ppActivate[i]->Release();
        }
        CoTaskMemFree(ppActivate);
    }
}
