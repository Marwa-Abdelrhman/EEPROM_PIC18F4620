/* 
 * File:   application.c
 * Author: Marwa Abdelrahman
 *
 * Created on August 1, 2024, 12:53 AM
 */


#include"application.h"
#include"MCAL_Layer/EEPROM/hal_eeprom.h"



Std_RetrunType ret=E_NOK;
uint8 eeprom_count=0,eeprom_data;
led_t led_1={.port_name=PORTC_INDEX,.pin=GPIO_PIN0,.led_state=GPIO_STATE_LOW};


int main() {
    app_init();
    ret=eeprom_write_data(0x0FF,22);
    ret=eeprom_write_data(0x3FF,65);
        
    while(1){
        
    ret=eeprom_write_data(0x3FF,eeprom_count++);
    if(eeprom_count %2 ==0)
    {
        led_toggle(&led_1);
        
    }
    __delay_ms(1000);    
         


    }
        return (EXIT_SUCCESS);
}

void app_init(void){
 
     
    //ecu_layer_initialize();
    led_init(&led_1);
     
}

