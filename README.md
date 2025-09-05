MFListTransform
===============

Based on https://github.com/sipsorcery/mediafoundationsamples/tree/master/MFListTransforms.

Built with VS 2022.

Results
-------

Desktop, RTX NVIDIA 4090
| Name | Flasg | GUID |
|--|--|--|
| H264 Encoder MFT | SW | {6CA50344-051A-4DED-9779-A43305165E35} |
| NVIDIA H.264 Encoder MFT | HW | {60F44560-5A20-4857-BFEF-D29773CB8040} |
| NVIDIA HEVC Encoder MFT | HW | {966F107C-8EA2-425D-B822-E4A71BEF01D7} |
| NVIDIA AV1 Encoder MFT | HW | {80B80715-8C5A-420D-B346-1A9DC40A5880} |

DELL XPS 15 9500,  Intel UHD and NVIDIA GeForce GTX 1650 Ti
| Codec | Flags | GUID |
|--|--|--|
| H264 Encoder MFT | SW | {6CA50344-051A-4DED-9779-A43305165E35} |
| Intel&reg; Quick Sync Video H.264 Encoder MFT | HW | {4BE8D3C0-0515-4A37-AD55-E4BAE19AF471} |
| NVIDIA H.264 Encoder MFT | HW | {60F44560-5A20-4857-BFEF-D29773CB8040} |
| NVIDIA HEVC Encoder MFT | HW | {966F107C-8EA2-425D-B822-E4A71BEF01D7} |
| Intel&reg; Hardware H265 Encoder MFT | HW | {BC10864D-2B34-408F-912A-102B1B867B6C} |

Desktop, AMD Radeon RX 7900 dev card.
| Codec | Flags | GUID |
|--|--|--|
| H264 Encoder MFT | SW | {6CA50344-051A-4DED-9779-A43305165E35} |
| NVIDIA H.264 Encoder MFT | HW | {60F44560-5A20-4857-BFEF-D29773CB8040} |
| AMDh264Encoder | HW | {ADC9BC80-0F41-46C6-AB75-D693D793597D} |
| NVIDIA HEVC Encoder MFT | HW | {362A74CD-E177-4916-A569-C3D4D99CE786} |
| NVIDIA HEVC Encoder MFT | HW | {966F107C-8EA2-425D-B822-E4A71BEF01D7} |
| AMDh265Encoder | HW | {5FD65104-A924-4835-AB71-09A223E3E37B} |
| NVIDIA AV1 Encoder MFT | HW | {80B80715-8C5A-420D-B346-1A9DC40A5880} |
| AMDav1Encoder | HW | {608872CF-6E75-4421-A568-EB9F187D9C88} |

Notes: I used to sawap graphics cards in this computer, so I assume that is the reason for the NVIDIA transforrms. Not sure what is the difference between the two NVIDIA HEVC transforms.  