#pragma once
#include "UnityEngine/Color.hpp"
#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(ModConfig,

    CONFIG_VALUE(Rainbow, bool, "Rainbow Bar when full energy", true);
    CONFIG_VALUE(AlwaysRainbow, bool, "Always Rainbow Bar", false);
    CONFIG_VALUE(Fadeout, bool, "Fadeout", false);
    CONFIG_VALUE(FullFade, bool, "Use fade between 15% and 95% colors", false);
    CONFIG_VALUE(Alpha, float, "Alpha", 1.0);
    CONFIG_VALUE(Diehp, UnityEngine::Color, "under 15% energy", UnityEngine::Color(1.0f, 0.0f, 0.0f, 0.0f));
    CONFIG_VALUE(Lowhp, UnityEngine::Color, "under 50% energy", UnityEngine::Color(1.0f, 0.0f, 0.0f, 0.0f));
    CONFIG_VALUE(Midhp, UnityEngine::Color, "over 70% energy", UnityEngine::Color(0.0f, 1.0f, 0.0f, 0.0f));
    CONFIG_VALUE(Highhp, UnityEngine::Color, "over 95% energy", UnityEngine::Color(0.0f, 1.0f, 1.0f, 0.0f));
    CONFIG_VALUE(Defhp, UnityEngine::Color, "over 50% energy", UnityEngine::Color(1.0f, 1.0f, 1.0f, 0.0f));

    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(Rainbow);
        CONFIG_INIT_VALUE(AlwaysRainbow);
        CONFIG_INIT_VALUE(Fadeout);
        CONFIG_INIT_VALUE(FullFade);
        CONFIG_INIT_VALUE(Alpha);
        CONFIG_INIT_VALUE(Diehp);
        CONFIG_INIT_VALUE(Lowhp);
        CONFIG_INIT_VALUE(Midhp);
        CONFIG_INIT_VALUE(Highhp);
        CONFIG_INIT_VALUE(Defhp);
    )
)