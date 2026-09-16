#pragma once

enum class CartType
{
    NO_MBC,
    MBC1,
    MBC2,
    MBC3,
    MBC5,
    MBC6,
    MBC7,
    MMM01,
    POCKET_CAMERA,
    BANDAI_TAMA5,
    HUC3,
    HUC1,
    UNUSED
};

struct CartTypeInfo
{
    CartType type;
    bool has_ram;
    bool has_battery;
    bool has_timer;
    bool has_rumble;
    bool has_accelerometer;
    const char* name;
};

const CartTypeInfo cart_type_info[256] = {
    {CartType::NO_MBC, false, false, false, false, false, "ROM ONLY"},               // 0x00
    {CartType::MBC1, true, true, false, false, false, "MBC1"},                       // 0x01
    {CartType::MBC1, true, true, false, false, false, "MBC1+RAM"},                   // 0x02
    {CartType::MBC1, true, true, false, false, false, "MBC1+RAM+BATTERY"},           // 0x03
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x04
    {CartType::MBC2, true, true, false, false, false, "MBC2"},                       // 0x05
    {CartType::MBC2, true, true, false, false, false, "MBC2+BATTERY"},               // 0x06
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x07
    {CartType::NO_MBC, true, true, false, false, false, "ROM+RAM"},                  // 0x08
    {CartType::NO_MBC, true, true, false, false, false, "ROM+RAM+BATTERY"},          // 0x09
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x0A
    {CartType::MMM01,false,false,false,false,false,"MMM01"},                         // 0x0B
    {CartType::MMM01,true,false,false,false,false,"MMM01+RAM"},                      // 0x0C
    {CartType::MMM01,true,true,false,false,false,"MMM01+RAM+BATTERY"},               // 0x0D
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x0E
    {CartType::MBC3,true,true,true,false,false,"MBC3+TIMER+BATTERY"},                // 0x0F
    {CartType::MBC3,true,true,false,false,false,"MBC3+TIMER+RAM+BATTERY"},           // 0x10
    {CartType::MBC3,true,true,false,false,false,"MBC3"},                             // 0x11
    {CartType::MBC3,true,true,false,false,false,"MBC3+RAM"},                         // 0x12
    {CartType::MBC3,true,true,false,false,false,"MBC3+RAM+BATTERY"},                 // 0x13
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x14
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x15
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x16
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x17
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x18
    {CartType::MBC5,true,false,false,false,false,"MBC5"},                            // 0x19
    {CartType::MBC5,true,true,false,false,false,"MBC5+RAM"},                         // 0x1A
    {CartType::MBC5,true,true,false,false,false,"MBC5+RAM+BATTERY"},                 // 0x1B
    {CartType::MBC5,true,false,false,false,false,"MBC5+RUMBLE"},                     // 0x1C
    {CartType::MBC5,true,true,false,false,false,"MBC5+RAM+RUMBLE"},                  // 0x1D
    {CartType::MBC5,true,true,false,false,false,"MBC5+RAM+BATTERY+RUMBLE"},          // 0x1E
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x1F
    {CartType::MBC6,true,false,false,false,false,"MBC6"},                            // 0x20
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x21
    {CartType::MBC7,true,true,false,true,true,"MBC7+SENSOR+RUMBLE+RAM+BATTERY"},     // 0x22
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x23
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x24
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x25
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x26
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x27
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x28
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x29
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x2A
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x2B
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x2C
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x2D
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x2E
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x2F
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x30
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x31
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x32
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x33
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x34
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x35
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x36
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x37
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x38
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x39
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x3A
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x3B
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x3C
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x3D
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x3E
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x3F
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x40
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x41
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x42
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x43
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x44
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x45
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x46
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x47
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x48
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x49
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x4A
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x4B
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x4C
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x4D
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x4E
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x4F
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x50
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x51
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x52
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x53
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x54
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x55
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x56
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x57
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x58
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x59
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x5A
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x5B
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x5C
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x5D
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x5E
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x5F
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x60
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x61
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x62
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x63
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x64
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x65
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x66
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x67
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x68
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x69
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x6A
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x6B
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x6C
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x6D
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x6E
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x6F
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x70
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x71
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x72
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x73
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x74
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x75
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x76
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x77
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x78
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x79
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x7A
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x7B
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x7C
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x7D
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x7E
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x7F
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x80
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x81
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x82
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x83
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x84
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x85
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x86
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x87
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x88
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x89
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x8A
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x8B
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x8C
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x8D
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x8E
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x8F
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x90
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x91
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x92
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x93
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x94
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x95
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x96
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x97
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x98
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x99
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x9A
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x9B
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x9C
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x9D
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x9E
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0x9F
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xA0
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xA1
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xA2
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xA3
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xA4
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xA5
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xA6
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xA7
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xA8
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xA9
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xAA
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xAB
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xAC
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xAD
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xAE
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xAF
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xB0
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xB1
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xB2
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xB3
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xB4
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xB5
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xB6
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xB7
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xB8
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xB9
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xBA
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xBB
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xBC
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xBD
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xBE
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xBF
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xC0
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xC1
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xC2
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xC3
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xC4
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xC5
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xC6
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xC7
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xC8
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xC9
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xCA
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xCB
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xCC
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xCD
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xCE
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xCF
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xD0
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xD1
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xD2
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xD3
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xD4
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xD5
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xD6
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xD7
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xD8
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xD9
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xDA
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xDB
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xDC
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xDD
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xDE
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xDF
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xE0
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xE1
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xE2
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xE3
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xE4
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xE5
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xE6
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xE7
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xE8
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xE9
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xEA
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xEB
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xEC
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xED
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xEE
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xEF
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xF0
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xF1
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xF2
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xF3
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xF4
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xF5
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xF6
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xF7
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xF8
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xF9
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xFA
    {CartType::UNUSED, false, false, false, false, false, "UNUSED"},                 // 0xFB
    {CartType::POCKET_CAMERA, false, false, false, false, false, "POCKET CAMERA"},   // 0xFC
    {CartType::BANDAI_TAMA5, false, false, false, false, false, "BANDAI TAMA5"},     // 0xFD
    {CartType::HUC3, false, false, false, false, false, "HuC3"},                     // 0xFE
    {CartType::HUC1, true, true, false, false, false, "HuC1+RAM+BATTERY"}            // 0xFF
};