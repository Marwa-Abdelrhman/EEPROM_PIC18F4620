/* 
 * File:   application.c
 * Author: Marwa Abdelrahman
 *
 * Created on August 1, 2024, 12:53 AM
 */


#include"application.h"
#include"MCAL_Layer/EEPROM/hal_eeprom.h"
#include"MCAL_Layer/Interrupt/mcal_external_interrupt.h"



Std_RetrunType ret=E_NOK;
uint8 eeprom_data;
volatile uint8 prog_selected=0;
void ISR_INT0_App(void);

void program_1(void);
void program_2(void);
void program_3(void);

led_t led_1={.port_name=PORTC_INDEX,.pin=GPIO_PIN0,.led_state=GPIO_STATE_LOW};
led_t led_2={.port_name=PORTC_INDEX,.pin=GPIO_PIN1,.led_state=GPIO_STATE_LOW};

interrupt_INTx_t int0_obj={ .src=INTERRUPT_INT0,
                            .edge=INTERRUPT_RISING_EDGE,
                            .priority=INTERRUPT_HIGH_PRIORITY,
                            .external_interrupt_handler=ISR_INT0_App,
                            .intx_pin.direction=GPIO_DIRECTION_INPUT,
                            .intx_pin.port=PORTB_INDEX,
                            .intx_pin.pin=GPIO_PIN0
                            };

int main() {
    app_init();
    ret=eeprom_read_data(0x000,&prog_selected);
   
        
    while(1){                  
        
        if(prog_selected ==1){
            program_1();
        }               
        else if(prog_selected ==2)
        {
            program_2();
        }
        else{program_3();}

    }
        return (EXIT_SUCCESS);
}

void app_init(void){
 
     
    //ecu_layer_initialize();
    ret=interrupt_INTx_Init(&int0_obj);
    led_init(&led_1);
    led_init(&led_2);
     
}
void ISR_INT0_App(void)
{
   prog_selected++;
   if(prog_selected==3)
   {
       prog_selected=0;
   }else{}
    ret=eeprom_write_data(0x000,prog_selected);
}

void program_1(void)
{
    led_toggle(&led_1);
    __delay_ms(200);
    
}
void program_2(void){
    
     led_toggle(&led_2);
    __delay_ms(200);
    
}
void program_3(void){
     led_off(&led_1);
     led_off(&led_2);
    
    
}