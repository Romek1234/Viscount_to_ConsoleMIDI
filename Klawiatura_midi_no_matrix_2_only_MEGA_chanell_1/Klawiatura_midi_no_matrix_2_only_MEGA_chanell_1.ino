/**
 * for ATmega1284p or Arduino mega
 * @brief   This example demonstrates the use of push buttons that send note 
 *          events.
 * 
 * ### Connections
 * 
 *  - 2:  momentary push button (to ground)
 *  - 3:  momentary push button (to ground)
 * 
 * The internal pull-up resistors for the buttons will be enabled automatically.
 * 
 * ### Behavior
 * 
 * Pressing the first button will send note on/off events on middle C.
 * Pressing the second button will send note on/off events for middle C sharp.
 * 
 * Written by PieterP, 28-01-2019  
 * https://github.com/tttapa/Control-Surface
 */

// Include the Control Surface library
#include <Control_Surface.h>

// Instantiate a MIDI over USB interface.
//USBDebugMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi;
//HardwareSerialMIDI_Interface midi = Serial;
HardwareSerialMIDI_Interface midiser = Serial;
//HairlessMIDI_Interface midi;

MIDI_PipeFactory<1> pipes;

using namespace MIDI_Notes;

// Instantiate the momentary push buttons that send out MIDI Note events.
NoteButton buttons[] = {
    //{2, note(C, 4)}, // digital input pin, note number
    //{3, note(Db, 4)},
    
    // If you want to set the channel specifically, you can use:
    // for UNO , nano
    {2, {note(C, 2), CHANNEL_1}},
    {3, {note(Db, 2), CHANNEL_1}},
    {4, {note(D, 2), CHANNEL_1}},
    {5, {note(Eb, 2), CHANNEL_1}},
    {6, {note(E, 2), CHANNEL_1}},
    {7, {note(F_, 2), CHANNEL_1}},
    {8, {note(Gb, 2), CHANNEL_1}},
    {9, {note(G, 2), CHANNEL_1}},
    {10, {note(Ab, 2), CHANNEL_1}},
    {11, {note(A, 2), CHANNEL_1}},
    {12, {note(Bb, 2), CHANNEL_1}},
    {A15, {note(B, 2), CHANNEL_1}},
    {14, {note(C, 3), CHANNEL_1}},
    {15, {note(Db, 3), CHANNEL_1}},
    {16, {note(D, 3), CHANNEL_1}},
    {17, {note(Eb, 3), CHANNEL_1}},
    {18, {note(E, 3), CHANNEL_1}},
    {19, {note(F_, 3), CHANNEL_1}},
    {20, {note(Gb, 3), CHANNEL_1}},
    {21, {note(G, 3), CHANNEL_1}},
    {22, {note(Ab, 3), CHANNEL_1}},
    {23, {note(A, 3), CHANNEL_1}},
    {24, {note(Bb, 3), CHANNEL_1}},
    {25, {note(B, 3), CHANNEL_1}},
    {26, {note(C, 4), CHANNEL_1}},
    {27, {note(Db, 4), CHANNEL_1}},
    {28, {note(D, 4), CHANNEL_1}},
    {29, {note(Eb, 4), CHANNEL_1}},
    {30, {note(E, 4), CHANNEL_1}},
    {31, {note(F_, 4), CHANNEL_1}},
    {32, {note(Gb, 4), CHANNEL_1}},
    {33, {note(G, 4), CHANNEL_1}},
    {34, {note(Ab, 4), CHANNEL_1}},
    {35, {note(A, 4), CHANNEL_1}},
    {36, {note(Bb, 4), CHANNEL_1}},
    {37, {note(B, 4), CHANNEL_1}},
    {38, {note(C, 5), CHANNEL_1}},
    {39, {note(Db, 5), CHANNEL_1}},
    {40, {note(D, 5), CHANNEL_1}},
    {41, {note(Eb, 5), CHANNEL_1}},
    {42, {note(E, 5), CHANNEL_1}},
    {43, {note(F_, 5), CHANNEL_1}},
    {44, {note(Gb, 5), CHANNEL_1}},
    {45, {note(G, 5), CHANNEL_1}},
    {46, {note(Ab, 5), CHANNEL_1}},
    {47, {note(A, 5), CHANNEL_1}},
    {48, {note(Bb, 5), CHANNEL_1}},
    {49, {note(B, 5), CHANNEL_1}},
    {50, {note(C, 6), CHANNEL_1}},
    {51, {note(Db, 6), CHANNEL_1}},
    {52, {note(D, 6), CHANNEL_1}},
    {53, {note(Eb, 6), CHANNEL_1}},
    {A0, {note(E, 6), CHANNEL_1}},
    {A1, {note(F_, 6), CHANNEL_1}},
    {A2, {note(Gb, 6), CHANNEL_1}},
    {A3, {note(G, 6), CHANNEL_1}},
    {A4, {note(Ab, 6), CHANNEL_1}},
    {A5, {note(A, 6), CHANNEL_1}},
    {A6, {note(Bb, 6), CHANNEL_1}},
    {A7, {note(B, 6), CHANNEL_1}},
    {A8, {note(C, 7), CHANNEL_1}},
    {A9, {note(Db, 7), CHANNEL_1}},
    {A10, {note(D, 7), CHANNEL_1}},
    {A11, {note(Eb, 7), CHANNEL_1}},
    {A12, {note(E, 7), CHANNEL_1}},
    {A13, {note(F_, 7), CHANNEL_1}},
    {A14, {note(Gb, 7), CHANNEL_1}},
    
    
  
    
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
