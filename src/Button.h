#ifndef Button_h
#define Button_h

#include "Arduino.h"

namespace simpleButton {
    class Button {
        public:
            uint32_t updateInterval      = 5;
            uint32_t defaultMinPushTime  = 40;
            uint32_t defaultTimeSpan     = 650;
            uint32_t defaultHoldInterval = 250;

            Button();
            Button(uint8_t pin);
            Button(uint8_t pin, bool inverted);
            ~Button();

            virtual void enable();
            virtual void disable();
            virtual void reset();

            virtual void push();
            virtual void release();

            virtual void click();
            virtual void click(uint32_t time);

            virtual bool read();
            virtual void update();
            virtual void update(bool state);

            virtual bool isInverted();
            virtual bool isEnabled();
            virtual bool isSetup();

            virtual bool getState();
            virtual int getClicks();
            virtual int getPushTime();

            virtual bool pushed();
            virtual bool released();
            virtual bool clicked();
            virtual bool clicked(uint32_t minPushTime);
            virtual bool doubleClicked();
            virtual bool doubleClicked(uint32_t minPushTime);
            virtual bool doubleClicked(uint32_t minPushTime, uint32_t timeSpan);
            virtual bool holded();
            virtual bool holded(uint32_t interval);

        protected:
            bool button_inverted = false;
            bool button_setup    = false;
            bool button_enabled  = false;
            bool state           = false;
            bool pushedFlag      = false;
            bool releasedFlag    = false;
            bool holdFlag        = false;

            uint8_t button_pin = 255;

            uint16_t clicks = 0;

            uint32_t prevPushTime    = 0;
            uint32_t prevReleaseTime = 0;
            uint32_t pushTime        = 0;
            uint32_t holdTime        = 0;
            uint32_t updateTime      = 0;
    };
}

#endif // ifndef Button_h