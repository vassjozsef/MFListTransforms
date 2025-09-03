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
| NVIDIA AV1 Encoder MFT | HW | {80B80715-8C5A-420D-B346-1A9DC40A5880} |
| NVIDIA HEVC Encoder MFT | HW | {966F107C-8EA2-425D-B822-E4A71BEF01D7} |

DELL XPS 15 9500,  Intel UHD and NVIDIA GeForce GTX 1650 Ti
| Codec | Flags | GUID |
|--|--|--|
| H264 Encoder MFT | SW | {6CA50344-051A-4DED-9779-A43305165E35} |
| Intel« Quick Sync Video H.264 Encoder MFT | HW | {4BE8D3C0-0515-4A37-AD55-E4BAE19AF471} |
| NVIDIA H.264 Encoder MFT | HW | {60F44560-5A20-4857-BFEF-D29773CB8040} |
| NVIDIA HEVC Encoder MFT | HW | {966F107C-8EA2-425D-B822-E4A71BEF01D7} |
| Intel« Hardware H265 Encoder MFT | HW | {BC10864D-2B34-408F-912A-102B1B867B6C} |
