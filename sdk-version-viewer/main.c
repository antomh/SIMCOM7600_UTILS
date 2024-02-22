#include <stdio.h>

// #include <stdint.h>
// #include <unistd.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <pthread.h>
// #include <signal.h>
// #include <ctype.h>
// #include "VoiceCall.h"
// #include "DataCall.h"
// #include "WDSControl.h"
// #include "NASControl.h"
// #include "WiFiControl.h"
// #include "SMSControl.h"
// #include "ATControl.h"
// #include "UIMControl.h"
// #include "DMSControl.h"
// #include "OTAUpgrade.h"
// #include "BTControl.h"
// #include "TTSControl.h"
// #ifdef _SIMCOM_WINDOWS_
// #include "app_timer.h"
// #else
// #include "LinuxTimer.h"
// #endif
// #include "ADC.h"
// #include "I2C.h"
// #include "GPSControl.h"
// #include "GpioControl.h"
// #include "EthControl.h"
// #include "simcom_demo_version.h"
// #include "simcom_test_main.h"
// #include "FTPControl.h"
// #include "ALSAControl.h"
// #include "DEVControl.h"
// #include "ftp_s.h"
// #include "http_s.h"
// #include "mqtt_s.h"
// #include "openssl.h"
// #include "simcom_lbs.h"


int main(void) {
    char *sdk_ver;
    sdk_ver = (char*)get_simcom_sdk_version();
    printf("SDK VERSION: %s\n", sdk_ver);
    return 0;
}

