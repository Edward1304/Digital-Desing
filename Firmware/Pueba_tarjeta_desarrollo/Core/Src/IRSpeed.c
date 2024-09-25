#include "IRSpeed.h"

void IRSPEED_Init(void) {
    // Initialize the Analog Output (AO) pin
    GPIO_InitTypeDef GPIO_InitStruct = {0};
    GPIO_InitStruct.Pin = IRSPEED_AO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(IRSPEED_AO_PORT, &GPIO_InitStruct);

    // Initialize the Digital Output (DO) pin
    GPIO_InitStruct.Pin = IRSPEED_DO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(IRSPEED_DO_PORT, &GPIO_InitStruct);
}

uint16_t IRSPEED_ReadAnalog(void) {
    // Configure ADC to read from the AO pin
    ADC_ChannelConfTypeDef sConfig = {0};
    sConfig.Channel = ADC_CHANNEL_3; // Corresponding to PA3
    sConfig.Rank = ADC_RANK_CHANNEL_NUMBER;
    sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
    HAL_ADC_ConfigChannel(&hadc, &sConfig);

    // Start the ADC conversion
    HAL_ADC_Start(&hadc);
    HAL_ADC_PollForConversion(&hadc, HAL_MAX_DELAY);
    uint16_t analogValue = HAL_ADC_GetValue(&hadc);
    HAL_ADC_Stop(&hadc);

    return analogValue;
}

uint8_t IRSPEED_ReadDigital(void) {
    // Read the digital value from the DO pin
    return HAL_GPIO_ReadPin(IRSPEED_DO_PORT, IRSPEED_DO_PIN);
}