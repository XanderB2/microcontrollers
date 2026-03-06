#include <stdio.h>
#include "myADC.h"
#include "esp_adc/adc_oneshot.h"
#include "esp_adc/adc_cali.h"

#define ADC_calibration 1

adc_cali_handle_t adc2_cali_handle;

adc_cali_line_fitting_config_t cali_config = {
    .unit_id = ADC_UNIT_2,
    .atten = ADC_ATTEN_DB_12,
    .bitwidth = ADC_BITWIDTH_DEFAULT,
};


adc_oneshot_unit_handle_t adc2_handle;
adc_oneshot_unit_init_cfg_t init_config2 = {
    .unit_id = ADC_UNIT_2,
    .ulp_mode = ADC_ULP_MODE_DISABLE,
};

adc_oneshot_chan_cfg_t config = {
    .bitwidth = ADC_BITWIDTH_DEFAULT,
    .atten = ADC_ATTEN_DB_12,
};





void myADC_setup(int channel)
    {
        adc_oneshot_new_unit(&init_config2, &adc2_handle);
        adc_oneshot_config_channel(adc2_handle,channel,&config);

        #if ADC_calibration
            adc_cali_create_scheme_line_fitting(&cali_config, &adc2_cali_handle);
        #endif
    }



int     myADC_inlezen(int channel)
    {
        int getal;
        adc_oneshot_read(adc2_handle, channel, &getal);
        return getal;
    }
    
    
    

