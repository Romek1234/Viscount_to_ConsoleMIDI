/*
 * I_man_ZAMBROW_NEW-ver_Midi_matrix_for_micro__7x8_keyboard_in_surfacecontroll
 * Author: R. Milewski
 * for nano and uno
 *
 * 
 *  Written by PieterP, 28-01-2019  
 * https://github.com/tttapa/Control-Surface
 */
#include <Control_Surface.h>
//Instantiate a MIDI over USB interface.
//USBDebugMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi = Serial;
HardwareSerialMIDI_Interface midiser = Serial;
//HairlessMIDI_Interface midiser;

MIDI_PipeFactory<1> pipes;
// Instantiate a CCPotentiometer object
//CCPotentiometer potentiometer {
//  A0,                                   // Analog pin connected to potentiometer
//  {MIDI_CC::Channel_Volume, Channel_1}, // Channel volume of channel 1
//};

//Potenciometrs
CCPotentiometer  potentiometer1(A2, {MIDI_CC::Channel_Volume, CHANNEL_9});
CCPotentiometer potentiometer2(A3,  {MIDI_CC::Channel_Volume, CHANNEL_11});
CCPotentiometer potentiometer3(A4, {MIDI_CC::Channel_Volume,  CHANNEL_12});
CCPotentiometer potentiometer4(A5, {MIDI_CC::Channel_Volume,  CHANNEL_13});
CCPotentiometer potentiometer5(A6, {MIDI_CC::Channel_Volume,  CHANNEL_14});
// The note numbers corresponding to the buttons in the matrix
// inny kirunek diód
const AddressMatrix<5, 8> addresses = {{
  {  36,  37,  38, 39, 40, 41, 42, 43 },
  {  44,  45,  46, 47, 48, 49, 50, 51 },
  {  52,  53,  54, 55, 56, 57, 58, 59 },
  {  60,  61,  62, 63, 64, 65, 66, 67 },
 // {  68,  69,  70, 71, 72, 73, 74, 75 },
  {  76,  77,  78, 79, 80, 81, 82, 83 },
  // {  84,  85,  86, 87, 88, 89, 90, 91 },
 // {  92,  93,  94, 95, 96, 97, 98, 99 },
  

}};

NoteButtonMatrix<5, 8> buttonmatrix = {
 
  {10, 11, 12, A0, A1},  // row pins
  {2, 3, 4, 5, 6, 7, 8, 9},// column pins
  
  addresses, // address matrix
  CHANNEL_6, // channel and cable number
};
void setup() {
  // Initialize everything
Control_Surface.begin();
 midiser >> pipes >> midiser; //all incoming midi from Serial is looped back
     midiser.begin();
}

void loop() {
  // Update the control surface
Control_Surface.loop();
 midiser.update();
}