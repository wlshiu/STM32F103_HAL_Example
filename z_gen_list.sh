#!/bin/bash


search_path=$*

find ./FATFS ./SYSTEM ./UCOSII ./Drivers ${search_path} -type f -name '*.c' -o -name '*.h' > cscope.files

# 001_USART_TRANSMIT
# 002_USART_RECEIVE
# 003_UART_RX_TX_INTERRUP
# 005_HC-05
# 006_RCC_HSE_CONFIG
# 007_SYSTICK_CONFIG
# 008_PLL_HSI_CONFIG
# 009_PLL_HSE_CONFIG
# 011_TIME_BASE_GENERATOR
# 011_TIME_BASE_GENERATOR_IT
# 013_TIMER_INPUT_CAPTURE
# 014_TIM_OC_IT
# 015_TIM_PWM_1
# 016_TIM_PWM_LED
# 017_SPI_MASTER
# 018_SPI_SLAVE
# 019_I2C_TEST_mpu6050
# 020_I2C_HMC5883L
# Experiment_01_HorseRaceLamp
# Experiment_02_Buzzer
# Experiment_03_KeyInput
# Experiment_04_SerialPort
# Experiment_05_ExternalInterrupt
# Experiment_06_IndependentWatchdog
# Experiment_07_WindowDog
# Experiment_08_TimerInterrupts
# Experiment_09_PWMOutput
# Experiment_10_InputCapture
# Experiment_11_TouchKey
# Experiment_12_OLEDDisplay
# Experiment_13_TFTLCDDisplay
# Experiment_14_DebugTool_USMART
# Experiment_15_RTC
# Experiment_16_PowerUpInStandby
# Experiment_17_ADC
# Experiment_18_InternalTemperatureSensor
# Experiment_19_LightSensor
# Experiment_20_DAC
# Experiment_21_DAC_SinusoidalOutputVoltage
# Experiment_22_DMA_DirectMemoryAccess
# Experiment_23_IIC_InterIntegratedCircuit
# Experiment_24_SPI_SerialPeripheralInterface
# Experiment_25_RS485
# Experiment_26_CAN_ControllerAreaNetwork
# Experiment_27_TouchScreen
# Experiment_28_InfraredRemoteControl
# Experiment_29_GameControllers
# Experiment_30_18B20DigitalTemperatureSensor
# Experiment_31_DHT11DigitalTemperatureSensor
# Experiment_32_MPU6050InertialMeasurementSensor
# Experiment_33_NRF24L01WirelessModule
# Experiment_34_FLASH_ReplaceEEPROM
# Experiment_35_CameraLenses
# Experiment_36_ExternalSRAM
# Experiment_37_MemoryManagement
# Experiment_38_SD_CardSDIO
# Experiment_39_FATFS
# Experiment_40_ChineseCharactersDisplay
# Experiment_41_PictureDisplay
# Experiment_42_Camera
# Experiment_43_MusicPlayer
# Experiment_44_RecordingMachine
# Experiment_45_HandwritingRecognition
# Experiment_46_T9PinyinInputMethod
# Experiment_47_Serial_IAP
# Experiment_48_USB_VirtualSerialPort
# Experiment_49_USB_CardReader
# Experiment_50_EthernetMAC_Controller
# key_control_led
# key_control_led_by_interrupt
# timer_base
# timer_encoder
# timer_input_capture
# timer_pwm
# uart_receive_and_transmit
# uart_receive_interrupt
# UCOSII_1_1_TaskScheduling
# UCOSII_1_2_TaskCreate_Delete_Suspend_Resume
# UCOSII_2_Semaphore_Mailbox
# UCOSII_3_MessageQueue_Semaphore_SoftwareTimer

