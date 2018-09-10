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
  ClickButton(byte pin, int active, T *createContext)
  {
    _pin = pin;
    _context = createContext;

    _debounceTicks = 50; // number of millisec that have to pass by before a click is assumed as safe.
    _clickTicks = 600;   // number of millisec that have to pass by before a click is detected.
    _pressTicks = 1000;  // number of millisec that have to pass by before a long button press is detected.

    _state = 0;             // starting with state 0: waiting for button to be pressed
    _isLongPressed = false; // Keep track of long press state

    if (active)
    {
      // the button connects the input pin to GND when pressed.
      _buttonReleased = HIGH; // notPressed
      _buttonPressed = LOW;

      // use the given pin as input and activate internal PULLUP resistor.
      pinMode(pin, INPUT_PULLUP);
    }
    else
    {
      // the button connects the input pin to VCC when pressed.
      _buttonReleased = LOW;
      _buttonPressed = HIGH;

      // use the given pin as input
      pinMode(pin, INPUT);
    } // if

    // no functions attached yet: clear all function pointers.
    _clickFunc = NULL;
    _doubleClickFunc = NULL;
    _pressFunc = NULL;
    _longPressStartFunc = NULL;
    _longPressStopFunc = NULL;
    _duringLongPressFunc = NULL;
  };
  ~ClickButton(){};

  // ----- Set runtime parameters -----

  // set # millisec after safe click is assumed.
  void setDebounceTicks(int ticks)
  {
    _debounceTicks = ticks;
  };

  // set # millisec after single click is assumed.
  void setClickTicks(int ticks)
  {
    _clickTicks = ticks;
  };

  // set # millisec after press is assumed.
  void setPressTicks(int ticks)
  {
    _pressTicks = ticks;
  };

  // attach functions that will be called when button was pressed in the specified way.
  void attachClick(callbackFunction newFunction)
  {
    _clickFunc = newFunction;
  };
  void attachDoubleClick(callbackFunction newFunction)
  {
    _doubleClickFunc = newFunction;
  };
  void attachPress(callbackFunction newFunction)
  {
    _pressFunc = newFunction;
  }; // DEPRECATED, replaced by longPressStart, longPressStop and duringLongPress
  void attachLongPressStart(callbackFunction newFunction)
  {
    _longPressStartFunc = newFunction;
  };
  void attachLongPressStop(callbackFunction newFunction)
  {
    _longPressStopFunc = newFunction;
  };
  void attachDuringLongPress(callbackFunction newFunction)
  {
    _duringLongPressFunc = newFunction;
  };

  // ----- State machine functions -----

  // call this function every some milliseconds for handling button events.
  void process(void)
  {
    // Detect the input information
    int buttonLevel = digitalRead(_pin); // current button signal.
    unsigned long now = millis();        // current (relative) time in msecs.

    // Implementation of the state machine
    if (_state == 0)
    { // waiting for menu pin being pressed.
      if (buttonLevel == _buttonPressed)
      {
        _state = 1;       // step to state 1
        _startTime = now; // remember starting time
      }                   // if
    }
    else if (_state == 1)
    { // waiting for menu pin being released.

      if ((buttonLevel == _buttonReleased) && ((unsigned long)(now - _startTime) < _debounceTicks))
      {
        // button was released to quickly so I assume some debouncing.
        // go back to state 0 without calling a function.
        _state = 0;
      }
      else if (buttonLevel == _buttonReleased)
      {
        _state = 2;      // step to state 2
        _stopTime = now; // remember stopping time
      }
      else if ((buttonLevel == _buttonPressed) && ((unsigned long)(now - _startTime) > _pressTicks))
      {
        _isLongPressed = true; // Keep track of long press state
        if (_pressFunc)
          _pressFunc(_context);
        if (_longPressStartFunc)
          _longPressStartFunc(_context);
        if (_duringLongPressFunc)
          _duringLongPressFunc(_context);
        _state = 6;      // step to state 6
        _stopTime = now; // remember stopping time
      }
      else
      {
        // wait. Stay in this state.
      } // if
    }
    else if (_state == 2)
    { // waiting for menu pin being pressed the second time or timeout.
      if (_doubleClickFunc == NULL || (unsigned long)(now - _startTime) > _clickTicks)
      {
        // this was only a single short click
        if (_clickFunc)
          _clickFunc(_context);
        _state = 0; // restart.
      }
      else if ((buttonLevel == _buttonPressed) && ((unsigned long)(now - _stopTime) > _debounceTicks))
      {
        _state = 3;       // step to state 3
        _startTime = now; // remember starting time
      }                   // if
    }
    else if (_state == 3)
    { // waiting for menu pin being released finally.
      // Stay here for at least _debounceTicks because else we might end up in state 1 if the
      // button bounces for too long.
      if (buttonLevel == _buttonReleased && ((unsigned long)(now - _startTime) > _debounceTicks))
      {
        // this was a 2 click sequence.
        if (_doubleClickFunc)
          _doubleClickFunc(_context);
        _state = 0;      // restart.
        _stopTime = now; // remember stopping time

      } // if
    }
    else if (_state == 6)
    { // waiting for menu pin being release after long press.
      if (buttonLevel == _buttonReleased)
      {
        _isLongPressed = false; // Keep track of long press state
        if (_longPressStopFunc)
          _longPressStopFunc(_context);
        _state = 0;      // restart.
        _stopTime = now; // remember stopping time
      }
      else
      {
        // button is being long pressed
        _isLongPressed = true; // Keep track of long press state
        if (_duringLongPressFunc)
          _duringLongPressFunc(_context);
      } // if

    } // if
  };
  bool isLongPressed()
  {
    return _isLongPressed;
  };
  int getPressedTicks()
  {
    return _stopTime - _startTime;
  };
  void reset(void)
  {
    _state = 0; // restart.
    _startTime = 0;
    _stopTime = 0;
    _isLongPressed = false;
  };

private:
  byte _pin;          // hardware pin number.
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
