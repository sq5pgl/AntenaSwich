/* Sterownik przełącznika antenowego by Zbyszek SQ5PGL email: sq5pgl@gmail.com  
Jeśli poprawisz wsad lub dodasz coś fajnego to proszę daj mi znać.
Wersja: 4 pozycję
Antena 1, Antena 2, Antena 3, Antena 4
*/

#include "Nextion.h"
#include "NexDualStateButton.h" 

int R1 = 2, R2 = 3, R3 = 4, R4 = 5;

NexDSButton bt0 = NexDSButton(1, 1, "bt0");
NexDSButton bt1 = NexDSButton(1, 2, "bt1");
NexDSButton bt2 = NexDSButton(1, 3, "bt2");
NexDSButton bt3 = NexDSButton(1, 4, "bt3");
char buffer[100] = {0};

NexTouch *nex_listen_list[] = 
{
    &bt0, &bt1, &bt2, &bt3,
    NULL
};
void setup(void)
{    
    nexInit();
    bt0.attachPop(bt0PopCallback, &bt0);
    bt1.attachPop(bt0PopCallback, &bt1);
    bt2.attachPop(bt0PopCallback, &bt2);
    bt3.attachPop(bt0PopCallback, &bt3);
    dbSerialPrintln("setup done"); 
pinMode(2,OUTPUT);
pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
digitalWrite(R1, HIGH);
digitalWrite(R2, HIGH);
digitalWrite(R3, HIGH);
digitalWrite(R4, HIGH);
}

void loop(void)
{   
    nexLoop(nex_listen_list);
}

void bt0PopCallback(void *ptr)
{
    uint32_t dual_state;
    NexDSButton *btn = (NexDSButton *)ptr;
    
    dbSerialPrintln("Callback");
    dbSerialPrint("ptr=");
  
    dbSerialPrintln((uint32_t)ptr); 
    memset(buffer, 0, sizeof(buffer));

// przekaźnik 1
   bt0.getValue(&dual_state); 
   if(dual_state)
   {
   digitalWrite(R1, HIGH);
   }
   else
   {
   allRelaysOff(); 
   digitalWrite(R1, LOW);
   }

// przekaźnik 2
   bt1.getValue(&dual_state);
   if(dual_state)
   {
   digitalWrite(R2, HIGH);
   }
   else
   {
   allRelaysOff(); 
   digitalWrite(R2, LOW);
   }

// przekaźnik 3
   bt2.getValue(&dual_state);
   if(dual_state)
   {
   digitalWrite(R3, HIGH);
   }
   else
   {
   allRelaysOff(); 
   digitalWrite(R3, LOW);
   }
   
// przekaźnik 4
   bt3.getValue(&dual_state);
   if(dual_state)
   {
   digitalWrite(R4, HIGH);
   }
   else
   {
   allRelaysOff(); 
   digitalWrite(R4, LOW);
   }
}

void allRelaysOff()
{
   digitalWrite(R1, HIGH);
   digitalWrite(R2, HIGH);
   digitalWrite(R3, HIGH);
   digitalWrite(R4, HIGH);
}
