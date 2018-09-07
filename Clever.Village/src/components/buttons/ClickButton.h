#ifndef ClickButton_h
#define ClickButton_h

#include "Arduino.h"

// ----- Callback function types -----

template <class T>
class ClickButton
{
public:

  typedef void (*callbackFunction)(T *);
  // ----- Constructor -----
  ClickButton(int pin, int active, T *createContext);

  // ----- Set runtime parameters -----

  // set # millisec after safe click is assumed.
  void setDebounceTicks(int ticks);

  // set # millisec after single click is assumed.
  void setClickTicks(int ticks);

  // set # millisec after press is assumed.
  void setPressTicks(int ticks);

  // attach functions that will be called when button was pressed in the specified way.
  void attachClick(callbackFunction newFunction);
  void attachDoubleClick(callbackFunction newFunction);
  void attachPress(callbackFunction newFunction); // DEPRECATED, replaced by longPressStart, longPressStop and duringLongPress
  void attachLongPressStart(callbackFunction newFunction);
  void attachLongPressStop(callbackFunction newFunction);
  void attachDuringLongPress(callbackFunction newFunction);

  // ----- State machine functions -----

  // call this function every some milliseconds for handling button events.
  void process(void);
  bool isLongPressed();
  int getPressedTicks();
  void reset(void);

private:
  int _pin;           // hardware pin number.
  int _debounceTicks; // number of ticks for debounce times.
  int _clickTicks;    // number of ticks that have to pass by before a click is detected
  int _pressTicks;    // number of ticks that have to pass by before a long button press is detected

  int _buttonReleased;
  int _buttonPressed;

  bool _isLongPressed;

  // These variables will hold functions acting as event source.
  callbackFunction _clickFunc;
  callbackFunction _doubleClickFunc;
  callbackFunction _pressFunc;
  callbackFunction _longPressStartFunc;
  callbackFunction _longPressStopFunc;
  callbackFunction _duringLongPressFunc;

  // These variables that hold information across the upcoming tick calls.
  // They are initialized once on program start and are updated every time the tick function is called.
  int _state;
  unsigned long _startTime; // will be set in state 1
  unsigned long _stopTime;  // will be set in state 2

  T *_context;
};

#endif
